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

/* Silicon Graphics audio module implementation */
/* For SGI Personal IRIS 4D/20 under IRIX 3.3; <sys/audio.h> mentions "IP6" */
/* Note: The set-in-gain ioctl exists but is non-functional */

#include <errno.h>
#include <sys/audio.h>
#include "asa.h"

#include "allobjects.h"
#include "modsupport.h"

static int audio_fd = -1;

static int
init()
{
       if (audio_fd >= 0)
               return 1;
       if ((audio_fd = asa_init()) >= 0)
               return 1;
       err_setstr(RuntimeError, "can't initialize async audio");
       return 0;
}


/* POSIX methods */

static object *
audio_get_ioctl(self, args, code)
       object *self;
       object *args;
       long code;
{
       long x;
       if (!getnoarg(args))
               return NULL;
       if (!init())
               return NULL;
       if ((x = ioctl(audio_fd, code, (char *) NULL)) < 0) {
               return NULL;
       }
       return newintobject(x);
}

static object *
audio_set_ioctl(self, args, code)
       object *self;
       object *args;
       long code;
{
       long x;
       if (!getlongarg(args, &x))
               return NULL;
       if (!init())
               return NULL;
       if (ioctl(audio_fd, code, (char *) x) != 0)
               return NULL;
       INCREF(None);
       return None;
}

static object *
audio_getingain(self, args)
       object *self;
       object *args;
{
       return audio_get_ioctl(self, args, AUDIOCGETINGAIN);
}

static object *
audio_getoutgain(self, args)
       object *self;
       object *args;
{
       return audio_get_ioctl(self, args, AUDIOCGETOUTGAIN);
}

static object *
audio_setingain(self, args)
       object *self;
       object *args;
{
       return audio_set_ioctl(self, args, AUDIOCSETINGAIN);
}

static object *
audio_setoutgain(self, args)
       object *self;
       object *args;
{
       return audio_set_ioctl(self, args, AUDIOCSETOUTGAIN);
}

static object *
audio_setrate(self, args)
       object *self;
       object *args;
{
       return audio_set_ioctl(self, args, AUDIOCSETRATE);
}

static object *
audio_setduration(self, args)
       object *self;
       object *args;
{
       return audio_set_ioctl(self, args, AUDIOCDURATION);
}

/* Compute average bias, and remove it */

static void
unbias(buf, len)
       char *buf;
       int len;
{
       register int i;
       register int c;
       register long bias;
       if (len == 0)
               return;
       bias = 0;
       for (i = 0; i < len; i++) {
               c = buf[i];
               if (c > 127)
                       c -= 256;
               bias += c;
       }
       bias = (bias + len/2) / len; /* Rounded average */
       if (bias != 0) {
               for (i = 0; i < len; i++) {
                       buf[i] -= bias;
               }
       }
}

static object *
audio_read(self, args)
       object *self;
       object *args;
{
       int c, i, n;
       object *v;
       char *s;
       if (!getintarg(args, &n))
               return NULL;
       if (n <= 0) {
               err_setstr(RuntimeError, "audio.read: arg <= 0");
               return NULL;
       }
       if (!init())
               return NULL;
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return err_nomem();
       s = getstringvalue(v);
       n = read(audio_fd, s, n);
       if (intrcheck()) {
               DECREF(v);
               err_set(KeyboardInterrupt);
               return NULL;
       }
       /* Check for errors */
       if (n < 0) {
               DECREF(v);
               return NULL;
       }
       /* But EOF is reported as an empty string */

       unbias(s, n);
       resizestring(&v, n);
       return v;
}

static object *
audio_write(self, args)
       object *self;
       object *args;
{
       int n, n2;
       object *v;
       if (!getstrarg(args, &v))
               return NULL;
       if (!init())
               return NULL;
       errno = 0;
       n2 = write(audio_fd, getstringvalue(v), n = getstringsize(v));
       if (intrcheck()) {
               err_set(KeyboardInterrupt);
               return NULL;
       }
       /* Check for other errors */
       if (n2 != n) {
               if (errno == 0)
                       errno = EIO;
               return NULL;
       }
       INCREF(None);
       return None;
}

/* audio.amplify(sample, f1, f2).
   Amplify a sample by a factor changing from f1/256 to (almost) f2/256.
   Negative factors are allowed.  Sound values that are to large
   to fit in a byte are clipped. */

static object *
audio_amplify(self, args)
       object *self;
       object *args;
{
       object *v;
       char *s, *t;
       int f1, f2;
       int i, n;
       int c;
       if (!getstrintintarg(args, &v, &f1, &f2))
               return NULL;
       n = getstringsize(v);
       s = getstringvalue(v);
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return err_nomem();
       t = getstringvalue(v);
       for (i = 0; i < n; i++) {
               c = s[i];
               if (c > 127) c -= 256; /* If chars are unsigned */
               c = c * ( f1*(n-i) + f2*i ) / ( n*256 );
               if (c > 127) c = 127;
               else if (c < -128) c = -128;
               t[i] = c;
       }
       return v;
}

/* audio.reverse(s): return a sample backwards */

static object *
audio_reverse(self, args)
       object *self;
       object *args;
{
       object *v;
       char *s, *t;
       int i, n;
       if (!getstrarg(args, &v))
               return NULL;
       n = getstringsize(v);
       s = getstringvalue(v);
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return err_nomem();
       t = getstringvalue(v);
       for (i = 0; i < n; i++) {
               t[n-1-i] = s[i];
       }
       return v;
}

/* audio.add(a, b): add two samples.
   Bytes that exceed the range are clipped.
   If one is shorter, the rest of the longer sample is returned unchanged. */

static object *
audio_add(self, args)
       object *self;
       object *args;
{
       object *a, *b, *v;
       char *sa, *sb, *t;
       int i, n, na, nb, c, ca, cb;
       if (!getstrstrarg(args, &a, &b))
               return NULL;
       na = getstringsize(a);
       sa = getstringvalue(a);
       nb = getstringsize(b);
       sb = getstringvalue(b);
       n = (na > nb) ? na : nb;
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return err_nomem();
       t = getstringvalue(v);
       for (i = 0; i < n; i++) {
               c = 0;
               if (i < na) {
                       ca = sa[i];
                       if (ca > 127) ca = ca - 256;
                       c = c + ca;
               }
               if (i < nb) {
                       cb = sb[i];
                       if (cb > 127) cb = cb - 256;
                       c = c + cb;
               }
               if (c > 127) c = 127;
               else if (c < -128) c = -128;
               t[i] = c;
       }
       return v;
}

/* audio.chr2num(s) returns a list containing the numeric values
   of the samples. */

static object *
audio_chr2num(self, args)
       object *self;
       object *args;
{
       object *v, *w;
       char *s;
       int c, i, n;
       static object *ints[256];

       /* To avoid filling memory with all those int objects, we create
          integer objects for all the desired values and reference these. */
       if (ints[255] == NULL) {
               for (i = 0; i < 256; i++) {
                       if (ints[i] != NULL)
                               continue;
                       c = i;
                       if (c > 127) c -= 256;
                       ints[i] = newintobject((long)c);
                       if (ints[i] == NULL)
                               return NULL;
               }
       }

       if (!getstrarg(args, &v))
               return NULL;
       n = getstringsize(v);
       s = getstringvalue(v);
       v = newlistobject(n);
       if (v == NULL)
               return err_nomem();
       for (i = 0; i < n; i++) {
               c = s[i] & 0xff;
               w = ints[c];
               INCREF(w);
               if (setlistitem(v, i, w) != 0) {
                       DECREF(v);
                       return NULL;
               }
       }
       return v;
}

/* audio.num2chr is the inverse of audio.chr2num.
   Excess values are clipped. */

static object *
audio_num2chr(self, args)
       object *self;
       object *args;
{
       object *v, *w;
       char *s;
       int c, i, n;
       if (!is_listobject(args)) {
               err_badarg();
               return NULL;
       }
       n = getlistsize(args);
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return NULL;
       s = getstringvalue(v);
       for (i = 0; i < n; i++) {
               w = getlistitem(args, i);
               if (!is_intobject(w)) {
                       DECREF(v);
                       err_badarg();
                       return NULL;
               }
               s[i] = getintvalue(w);
       }
       return v;
}

static object *stdaudio_buffer = NULL;

static object *
audio_start_recording(self, args)
       object *self;
       object *args;
{
       int n;
       object *v;
       char *s;
       if (!getintarg(args, &n))
               return NULL;
       if (stdaudio_buffer != NULL) {
               err_setstr(RuntimeError, "audio.start_recording: device busy");
               return NULL;
       }
       if (n <= 0) {
               err_setstr(TypeError, "audio.start_recording: arg <= 0");
               return NULL;
       }
       if (!init())
               return NULL;
       v = newsizedstringobject((char *)NULL, n);
       if (v == NULL)
               return err_nomem();
       s = getstringvalue(v);
       asa_start_read(s, n);
       stdaudio_buffer = v;
       INCREF(None);
       return None;
}

static object *
audio_poll(self, args)
       object *self;
       object *args;
{
       int n;
       if (!getnoarg(args))
               return NULL;
       if (stdaudio_buffer == NULL) {
               err_setstr(RuntimeError, "audio.poll: not busy");
               return NULL;
       }
       if (!init())
               return NULL;
       if ((n = asa_poll()) < 0)
               return NULL;
       return newintobject(n);
}

static object *
audio_wait_recording(self, args)
       object *self;
       object *args;
{
       object *v;
       int n;
       if (!getnoarg(args))
               return NULL;
       if (stdaudio_buffer == NULL) {
               err_setstr(RuntimeError, "audio.wait_recording: not busy");
               return NULL;
       }
       if (!init())
               return NULL;
       if ((n = asa_wait()) < 0)
               return NULL;
       v = stdaudio_buffer;
       stdaudio_buffer = NULL;
       unbias(getstringvalue(v), n);
       resizestring(&v, n);
       return v;
}

static object *
audio_stop_recording(self, args)
       object *self;
       object *args;
{
       int n;
       object *v;
       char *s;
       if (!getnoarg(args))
               return NULL;
       if (stdaudio_buffer == NULL) {
               err_setstr(RuntimeError, "audio.stop_recording: not busy");
               return NULL;
       }
       if ((n = asa_cancel()) < 0)
               return NULL;
       v = stdaudio_buffer;
       stdaudio_buffer = NULL;
       s = getstringvalue(v);
       unbias(s, n);
       resizestring(&v, n);
       return v;
}

static object *
audio_start_playing(self, args)
       object *self;
       object *args;
{
       object *v;
       if (!getstrarg(args, &v))
               return NULL;
       if (stdaudio_buffer != NULL) {
               err_setstr(RuntimeError, "audio.start_recording: device rbusy");
               return NULL;
       }
       asa_start_write(getstringvalue(v), (int)getstringsize(v));
       INCREF(v);
       stdaudio_buffer = v;
       INCREF(None);
       return None;
}

static object *
audio_wait_playing(self, args)
       object *self;
       object *args;
{
       int n;
       if (!getnoarg(args))
               return NULL;
       if (stdaudio_buffer == NULL) {
               err_setstr(RuntimeError, "audio.wait_playing: not busy");
               return NULL;
       }
       if ((n = asa_wait()) < 0)
               return NULL;
       DECREF(stdaudio_buffer);
       stdaudio_buffer = NULL;
       /* XXX return newintobject((long)n); ??? */
       INCREF(None);
       return None;
}

static object *
audio_stop_playing(self, args)
       object *self;
       object *args;
{
       int n;
       if (!getnoarg(args))
               return NULL;
       if (stdaudio_buffer == NULL) {
               err_setstr(RuntimeError, "audio.stop_playing: not busy");
               return NULL;
       }
       if ((n = asa_cancel()) < 0)
               return NULL;
       DECREF(stdaudio_buffer);
       stdaudio_buffer = NULL;
       return newintobject((long)n);
}

static object *
audio_audio_done(self, args)
       object *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       asa_done();
       if (stdaudio_buffer != NULL)
               DECREF(stdaudio_buffer);
       stdaudio_buffer = NULL;
       audio_fd = -1;
       INCREF(None);
       return None;
}


static struct methodlist audio_methods[] = {
       {"getingain", audio_getingain},
       {"getoutgain",        audio_getoutgain},
       {"setingain", audio_setingain},
       {"setoutgain",        audio_setoutgain},
       {"setrate",   audio_setrate},
       {"setduration",       audio_setduration},
       {"read",      audio_read},
       {"write",     audio_write},
       {"amplify",   audio_amplify},
       {"reverse",   audio_reverse},
       {"add",               audio_add},
       {"chr2num",   audio_chr2num},
       {"num2chr",   audio_num2chr},

       /* "asa" interface: */

       {"start_recording",   audio_start_recording},
       {"poll_recording",    audio_poll},
       {"wait_recording",    audio_wait_recording},
       {"stop_recording",    audio_stop_recording},

       {"start_playing",     audio_start_playing},
       {"poll_playing",      audio_poll},
       {"wait_playing",      audio_wait_playing},
       {"stop_playing",      audio_stop_playing},

       {"done",              audio_audio_done},

       {NULL,          NULL}                   /* Sentinel */
};

void
initaudio()
{
       initmodule("audio", audio_methods);
}
