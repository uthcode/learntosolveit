/***********************************************************
Copyright 1991 by Stichting Mathematisch Centrum, Amsterdam, The
Netherlands.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the names of Stichting Mathematisch
Centrum or CWI not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior permission.

STICHTING MATHEMATISCH CENTRUM DISCLAIMS ALL WARRANTIES WITH REGARD TO
THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS, IN NO EVENT SHALL STICHTING MATHEMATISCH CENTRUM BE LIABLE
FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

******************************************************************/

/* Asynchronous audio module for Silicon Graphics 4D/20 under IRIX 3.3
   Copyright 1990 Stichting Mathematisch Centrum, Amsterdam
   Author: Guido van Rossum, <gu...@cwi.nl>
   Last modified: gu...@cwi.nl, Oct 14, 1990

   Callers should #include "asa.h".

   This code is strongly IRIX 3.3 dependent.  (Or are sproc() and
   friends standard SYSV now?)

   Caution: if you put printf's in the slave for debugging, use "-lmpc"
   to get the semaphore version of stdio!


   This file contains two library layers and a test program:


   The lower layer implements a simple asynchronous execution facility,
   built directly on the system calls sproc() and [un]blockproc().

   A slave thread sits in an infinite loop waiting for work assigned to
   it by the master thread.  Work is represented by a function pointer
   and an argument of type void*.  The function returns a void* pointer
   which is transferred back to the master when it submits the next bit
   of work.  Submitting a NULL function pointer can be used by the
   master to wait for completion of the previous work.  This lower
   layer could be generally useful, but is currently implemented by
   static functions, for exclusive by the asynchronous audio layer.


   The higher layer implements an asynchronous interface to the
   /dev/audio device on the Silicon Graphics 4D/20.  It defines the
   following functions:

   int asa_init()
       Required initialization function.  The other functions will call
       abort() when they are called before asa_init().  It creates the
       slave process and returns a file descriptor for the audio
       device which can be used to set the sampling rate and output
       gain, etc.  It prints a message to stderr and returns -1 if the
       initialization failed.  Calling this function more than onece is
       harmless.

   void asa_start_read(char *buf, int len)
       Starts an asynchronous read call on the audio device.  This
       waits for completion of the previous request, if any.

   void asa_start_write(char *buf, int len)
       Starts an asynchronous write call on the audio device.  This
       waits for completion of the previous request, if any.

   int asa_poll()
       Polls whether the last asynchronous read or write request is
       finished.  Returns -1 if no request was queued, 0 if the request
       is not yet finished, and 1 if it is finished.

   int asa_wait()
       Waits for completion if the last asynchronous read or write
       request.  It returns the result of the read or write request,
       and sets the error code to the error code set by the request if
       the result is -1.  If no request was queued, this also returns
       -1 but leaves the error code unchanged.  Note: to get the error
       code, don't inspect the global variable errno but call the
       function oserror().

   int asa_cancel()
       Cancels the last asynchronous read or write request (by sending
       the slave thread a signal for which it has a handler) then
       returns its result and error code as asa_wait().

   void asa_done()
       Kills the slave process and closes the audio device.  After
       this, if further use of the module is required, asa_init()
       should be called again.  Calling this function when asa_init()
       has not been called is harmless.


   Finally, this file contains a simple test program that is compiled if
   MAIN is defined (e.g., compile with cc -DMAIN).  It makes a recording
   and plays it back.  The user must indicate begin and end of recording
   and play-back by pressing the Return key.
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/prctl.h>

#include "asa.h"


/* Asynchronous execution facility (lower layer) */


/* Signal used to cancel requests in progress */
#define MYSIG SIGUSR1

/* Respective process IDs */
static pid_t master_pid = -1;
static pid_t slave_pid = -1;

/* Work and result "queue" (1 element) */
static void * (*work_func)();
static void *work_arg;
static void *work_result;

/* Signal handler for MYSIG -- interrupts read or write system call */

/*ARGSUSED*/
static void
handler(sig)
       int sig;
{
       /* Reinstate the handler (non-BSD signal semantics) */
       signal(sig, handler);
}

/* Subroutine to fiddle signals */

static void
dosig(sig)
       int sig;
{
       if (signal(sig, SIG_IGN) != SIG_IGN)
               signal(sig, SIG_DFL);
}

/* Slave control flow */

/*ARGSUSED*/
static void
slave(arg)
       void *arg;
{
       void * (*func)();
       void *arg;
       void *result;

       /* Reset signal handlers that interactive programs often catch.
          The assumption is that if the master has a handler for these
          signals, it will be a cleanup function.  The slave must die
          from these. */
       dosig(SIGHUP);
       dosig(SIGQUIT);
       dosig(SIGTERM);
       dosig(SIGPIPE);

       /* Ignore SIGINT if caught or ignored */
       if (signal(SIGINT, SIG_IGN) == SIG_DFL)
               signal(SIGINT, SIG_DFL);

       /* Let the handler install itself */
       handler(MYSIG);

       /* Set slave_pid.  This is also done in the master thread, but
          there is a race condition whereby the slave begins execution
          before the master has assigned the result of sproc() to
          slave_pid.  So we set it here as well -- since this sets the
          same value it should be OK. */
       slave_pid = getpid();

       /* Set the dummy result returned by the first rendezvous */
       result = NULL;

       /* Loop forever, waiting for and executing work */
       for (;;) {
               /* First rendezvous: store previous result */
               if (blockproc(slave_pid) < 0)
                       perror("slave: [result] blockproc(slave_pid)");
               work_result = result;
               if (unblockproc(master_pid) < 0)
                       perror("slave: [result] unblockproc(master_pid)");

               /* Second rendezvous: fetch work */
               if (blockproc(slave_pid) < 0)
                       perror("slave: [func,arg] blockproc(slave_pid)");
               func = work_func;
               arg = work_arg;
               if (unblockproc(master_pid) < 0)
                       perror("slave: [func,arg] unblockproc(master_pid)");

               /* Execute work, computing new result */
               if (func == NULL) {
                       result = arg;
               }
               else {
                       result = (*func)(arg);
               }
       }
}

static int
slave_init()
{
       if (slave_pid > 0)
               return slave_pid;
       master_pid = getpid();

       /* Reset the queue, in case this is a re-init after asa_done() */
       work_result = NULL;
       work_func = NULL;
       work_arg = NULL;

       /* Create the slave process, sharing all segments and properties */
       slave_pid = sproc(slave, PR_SALL, (char *)NULL);
       if (slave_pid < 0)
               perror("slave_init: sproc(slave, PR_SALL, NULL)");

       /* Set up initial conditions---tricky!
          Both the master and the slave start with one credit, since
          both the result slot and the work/func slots are initially
          free.
          Note that we use setblockproccnt() for the master so a
          possible indeterminate semaphore value caused by a previous
          asa_done() at an unfortunate moment doesn't harm us.
       */
       setblockproccnt(master_pid, 1);
       unblockproc(slave_pid);

       return slave_pid;
}

static void
slave_done()
{
       if (slave_pid > 0) {
               if (kill(slave_pid, SIGKILL) < 0)
                       perror("slave_done: kill(slave_pid, SIGKILL)");
       }
       slave_pid = -1;
}

/* Queue new work and return result of previous work */

static void *
rendezvous(func, arg)
       void * (*func)();
       void *arg;
{
       void *result;

       if (slave_pid <= 0)
               abort(); /* Illegal call: not initialized properly */

       /* First rendezvous: store new work */
       if (blockproc(master_pid) < 0)
               perror("rendezvous: [func,arg] blockproc(master_pid)");
       work_func = func;
       work_arg = arg;
       if (unblockproc(slave_pid) < 0)
               perror("rendezvous: [func,arg] unblockproc(slave_pid)");

       /* Second rendezvous: fetch previous result */
       if (blockproc(master_pid) < 0)
               perror("rendezvous: [result] blockproc(master_pid)");
       result = work_result;
       if (unblockproc(slave_pid) < 0)
               perror("rendezvous: [result] unblockproc(slave_pid)");

       return result;
}


/* Asynchronous audio interface (higher layer) */


int audio_fd = -1;     /* File descriptor -- not initialized yet */

static struct queue {
       int func;       /* 0 = read, 1 = write */
       char *buf;
       int len;
       int result;
       int error;
} queue[2];

static int qindex = 0;

int
asa_init()
{
       int fd;
       char *p;

       if (audio_fd >= 0)
               return audio_fd;
       fd = open("/dev/audio", 2);
       if (fd < 0) {
               perror("asa_init: Can't open /dev/audio");
               return -1;
       }
       if (slave_init() < 0) {
               perror("asa_init: Can't create slave process");
               close(fd);
               return -1;
       }
       audio_fd = fd;
       return fd;
}

void
asa_done()
{
       slave_done();
       if (audio_fd >= 0) {
               if (close(audio_fd) < 0)
                       perror("asa_done: close(audio_fd)");
       }
       audio_fd = -1;
}

static void *
runjob(arg)
       void *arg;
{
       extern int errno;
       struct queue *q = (struct queue *)arg;
       char *buf = q->buf;
       int len = q->len;
       int n = 0;

       if (q->func == 0)
               n = read(audio_fd, buf, len);
       else
               n = write(audio_fd, buf, len);
       if (q->func == 0 && n >= 0) {
               while (--len >= n && buf[len] == '\0')
                       ;
               n = len+1;
       }
       q->result = n;
       q->error = oserror();
       return arg;
}

static void
startjob(func, buf, len)
       int func;
       char *buf;
       int len;
{
       struct queue *q;

       q = &queue[qindex];
       qindex = (qindex+1) & 1;
       q->func = func;
       q->buf = buf;
       q->len = len;
       (void) rendezvous(runjob, (void *)q);
}

void
asa_start_read(buf, len)
       char *buf;
       int len;
{
       memset(buf, '\0', len);
       startjob(0, buf, len);
}

void
asa_start_write(buf, len)
       char *buf;
       int len;
{
       startjob(1, buf, len);
}

int
asa_wait()
{
       struct queue *q;

       q = (struct queue *) rendezvous((void*(*)())NULL, (void *)NULL);
       if (q == NULL) {
               setoserror(0);
               return -1; /* No work was queued */
       }
       setoserror(q->error);
       return q->result;
}

int
asa_poll()
{
       int err;

       err = prctl(PR_ISBLOCKED, slave_pid);
       if (err < 0) {
               perror("prctl(PR_ISBLOCKED, slave_pid)");
               return -1;
       }
       else if (err == 0)
               return 0;
       else if (work_result == NULL) {
               setoserror(0);
               return -1;
       }
       else
               return 1;
}

int
asa_cancel()
{
       int result;

       kill(slave_pid, MYSIG);
       result = asa_wait();
       return result;
}


#ifdef MAIN

/* Test program */

#include <sys/audio.h>

main()
{
       static char buf[10*16*1024]; /* 10 seconds of sound at 16K/sec */
       int n;
       int afd;

       if ((afd = asa_init()) < 0)
               exit(1);
       ioctl(afd, AUDIOCSETRATE, 3);
       ioctl(afd, AUDIOCSETOUTGAIN, 0);
       printf("Poll returns %d\n", asa_poll());
       go("Hit enter to start recording:\n");
       asa_start_read(buf, sizeof buf);
       go("Hit enter to stop recording:\n");
       /*printf("Poll returns %d\n", asa_poll());*/
       n = asa_cancel();
       if (n < 0)
               perror("Read failed");
       else {
               printf("Got %d bytes\n", n);
               printf("Poll returns %d\n", asa_poll());
               go("Hit enter to start playing:\n");
               ioctl(afd, AUDIOCSETOUTGAIN, 50);
               asa_start_write(buf, n);
               go("Hit enter to stop playing:\n");
               printf("Poll returns %d\n", asa_poll());
               n = asa_cancel();
               if (n < 0)
                       perror("Write failed");
               else
                       printf("Stopped at %d bytes\n", n);
       }
       ioctl(afd, AUDIOCSETOUTGAIN, 0);
       asa_done();
       exit(n < 0 ? 1 : 0);
}

go(str)
       char *str;
{
       char line[100];

       sleep(1);
       fputs(str, stdout);
       fflush(stdout);
       fgets(line, sizeof line, stdin);
}

#endif /* MAIN */
