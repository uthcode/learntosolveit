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

#if 0
#define STACK_TRACE
#define SCDEBUG
#endif
#include <stdio.h>

#include <ailamoeba.h>

#include "PROTO.h"
#include "sc_global.h"
#include "object.h"
#include "objimpl.h"
#include "stringobject.h"
#include "errors.h"
#include "sc_errors.h"
#include "stubcode.h"
#include "tupleobject.h"
#include "intobject.h"
#include "listobject.h"

typedef struct s_loopstruct {
       struct s_loopstruct     *l_next;        /* Make a list of it      */
       TscOperand              l_label;        /* Indentify the loop     */
       int                     l_index;        /* The index of the list  */
       int                     l_size;         /* The size of the list   */
       int                     l_retaddr;      /* Addres to jump back    */
       int                     l_endaddr;      /* Addres to jump to end  */
       object                  *l_list;        /* The list to append to  */
} TsLoop, *TpsLoop;


/*
**     This file contains the Stubcode interpreter.
**     All the instructions have there own function. The interpreter
**     reads an instruction from the data and if needed also an operand.
**     After this it calls the function that executes the instruction.
*/

struct sc_ProcessBlock {
       object          **stack;
       unsigned char   *buffer, *data;
       int             sp, bp, pc, maxbufsize, datsize;
       header          hdr;
       TpsLoop         loops;
};

extern getcapability();

/*
 *      Clean up the mess the loops make.
 */

static void
xCleanUpLoops(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop prev, this;

       if (sc_pb->loops == NULL)
               return;
       prev = sc_pb->loops;
       this = sc_pb->loops->l_next;
       while(this) {
               free((char *)prev);
               prev = this;
               this = this->l_next;
       }
       free((char *)prev);
}

static int
findendloop(label, sc_pb)
       TscOperand label;
       struct sc_ProcessBlock *sc_pb;
{
       TscOperand operand;
       TscOpcode opcode;
       int walk = sc_pb->pc, found = 0;

       while (!found && (walk < sc_pb->datsize)) {
               memcpy(&opcode, &sc_pb->data[walk], sizeof(TscOpcode));
               walk += sizeof(TscOpcode);
               if (opcode & (FLAGS | OPERAND)) {
                       memcpy(&operand, &sc_pb->data[walk], sizeof(TscOperand));
                       walk += sizeof(TscOperand);
               }
               if (opcode == EndLoop)
                       if (operand == label) found = 1;
       }
       if (found)
               return walk;
       return -1;
}

static int
findloop(ret, label, sc_pb)
       TpsLoop *ret;
       TscOperand label;
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop walk;

       for (walk = sc_pb->loops; walk != NULL; walk = walk->l_next) {
               if (walk->l_label == label) break;
       }
       if (walk == NULL) {
               TpsLoop newloop;

               newloop = (TpsLoop)malloc(sizeof(TsLoop));
               if (newloop == NULL) {
                       err_nomem();
                       return -1;
               }
               newloop->l_label = label;
               newloop->l_index = 0;
               newloop->l_retaddr = sc_pb->pc - (sizeof(TscOpcode) + sizeof(TscOperand));
               /*
               **       We need a correction because the pc points to
               **       the instruction after the XXXLoop.
               */
               if ((newloop->l_endaddr = findendloop(label, sc_pb)) < 0) {
                       free((char *)newloop);
                       err_scerr(NoEndLoop);
                       return -1;
               }
               newloop->l_list = NULL;
               newloop->l_next = sc_pb->loops;
               sc_pb->loops = newloop;
               *ret = newloop;
               return 1;
       }
       *ret = walk;
       return 0;
}

#ifdef 0

static void
removeloop(this, sc_pb)
       TpsLoop this;
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop walk, prev = NULL;

       for (walk = sc_pb->loops; walk != NULL; walk = walk->l_next) {
               if (walk->l_label == this->l_label) {
                       if (prev != NULL) {
                               prev->l_next = walk->l_next;
                       } else {
                               loop = walk->l_next;
                       }
                       free((char *)this);
                       break;
               }
               prev = walk;
       }
}

#endif

static int
init(self, sc_pb)
       object *self;
       struct sc_ProcessBlock *sc_pb;
{
object *string;
int datasize;

       string = gettupleitem(self, STUBC);
       if (string == NULL)
               return -1;
       sc_pb->data = getstringvalue(string);
       if (sc_pb->data == NULL)
               return -1;
       datasize = (int)getstringsize(string);
       if (datasize == -1)
               return -1;
       sc_pb->stack = (object **)malloc(STKSIZE * sizeof(object *));
       if (sc_pb->stack == NULL) {
               err_nomem();
               return -1;
       }
       sc_pb->bp = sc_pb->sp = sc_pb->pc = 0;
       sc_pb->loops = NULL;
       return datasize;
}

static void reinit(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       int i;

       sc_pb->bp = 0;
       for (i = 0; i < sc_pb->sp; i++) {
               DECREF(sc_pb->stack[i]);
       }
       sc_pb->sp = 0;
}

static void UnInit(self, sc_pb)
       object *self;
       struct sc_ProcessBlock *sc_pb;
{
       int i;

       free(sc_pb->buffer);
       reinit(sc_pb);
       free((char *)sc_pb->stack);
       xCleanUpLoops(sc_pb);
}

static object *
stacktop(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{

       if (sc_pb->sp == 0)
               return err_scerr(StackUnderflow);
       if (sc_pb->sp == (STKSIZE + 1))
               return err_scerr(StackOverflow);
       return sc_pb->stack[sc_pb->sp - 1];
}

/*
 *      Push an object on the stack.
 */
static int
xPush(element, sc_pb)
       object *element;
       struct sc_ProcessBlock *sc_pb;
{

       if (sc_pb->sp >= STKSIZE) {
               err_scerr(StackOverflow);
               return -1;
       }
       if (element == NULL) {
               err_scerr(ElementIsNull);
               return -1;
       }
       INCREF(element);
#ifdef STACK_TRACE
       printf("pushed :");
       printobject(element, stdout, 0);
       printf("\n");
#endif
       sc_pb->stack[sc_pb->sp++] = element;
       return 0;
}

/*
 *      Perform the RPC.
 */
static int
xTrans(self,cmd, sc_pb)
       object *self;
       TscOperand cmd;
       struct sc_ProcessBlock *sc_pb;
{
       short ret;
       capability cap;
       object *capobj;

       if ((capobj = gettupleitem(self, CAP)) == NULL)
               return -1;
       if (getcapability(capobj, &cap) == -1)
               return -1;
       sc_pb->hdr.h_port = cap.cap_port;
       sc_pb->hdr.h_priv = cap.cap_priv;
       sc_pb->hdr.h_command = (command)cmd;
#ifdef SCDEBUG
       printf("bp = %d maxbufsize = %d\n",sc_pb->bp, sc_pb->maxbufsize);
       {
               int i;

               for (i = 0; i < sc_pb->bp; i++) {
                       printf("%x ", sc_pb->buffer[i]);
               }
       }
       printf("\n");
#endif
       ret = trans(&sc_pb->hdr, sc_pb->buffer, (bufsize) sc_pb->bp,
               &sc_pb->hdr, sc_pb->buffer, (bufsize)sc_pb->maxbufsize);
#ifdef SCDEBUG
       printf("after Trans:ret = %d\n",ret);
       {
               int i;

               for (i = 0; i < ret; i++) {
                       printf("%x ", sc_pb->buffer[i]);
               }
       }
       printf("\n");
#endif
       if (ERR_STATUS(ret)) {
               amoeba_error(ERR_CONVERT(ret));
               return -1;
       }
       if (sc_pb->hdr.h_status != 0) {
               object *v;

               if ((v = newintobject(sc_pb->hdr.h_status)) == NULL)
                       return -1;
               err_scerrset(TransError, v, "Trans");
               DECREF(v);
               return -1;
       }
       reinit(sc_pb);
       return 0;
}

/*
 *      Test the tuple size.
 */
static int
xTTupleS(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *tuple;

       if ((tuple = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_tupleobject(tuple))
               return err_scerrset(TypeFailure, tuple, "TTupleS");
       if (gettuplesize(tuple) != (unsigned int)size)
               return err_scerrset(SizeError, tuple, "TTupleS");
       return 0;
}

/*
 *      Unpack a tuple
 */
static int
xUnpack(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *tuple, *element;
       int i;

       if (size < (TscOperand)2) {
               element = newintobject(size);
               if (element == NULL)
                       return -1;
               return err_scerrset(SizeError, element, "Unpack");
       }
       if ((tuple = stacktop(sc_pb)) == NULL)
               return -1;
       INCREF(tuple);
       if (xPop((TscOperand) 1, sc_pb) != 0) {
               DECREF(tuple);
               return -1;
       }
       for (i = 0; i < (int)size; i++) {
               if ((element = gettupleitem(tuple, i)) == NULL) {
                       DECREF(tuple);
                       return -1;
               }
               if (xPush(element, sc_pb) != 0) {
                       DECREF(tuple);
                       return -1;
               }
       }
       DECREF(tuple);
       return 0;
}

/*
 *      Marshal the Ailword to a headerfiels.
 */
static int
xAilword(headerfield, sc_pb)
       TscOperand headerfield;
       struct sc_ProcessBlock *sc_pb;
{

       switch(headerfield) {

       case H_EXTRA:
               sc_pb->hdr.h_extra = (uint16)_ailword;
               return 0;

       case H_SIZE:
               sc_pb->hdr.h_size = (bufsize)_ailword;
               return 0;

       case H_OFFSET:
               sc_pb->hdr.h_offset = (int32)_ailword;
               return 0;

       default:
               {
                       object *v;

                       if ((v = newintobject(headerfield)) == NULL)
                               return -1;
                       return err_scerrset(FlagError, v, "Ailword");
               }
       }
}

static int
xStringS(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       object *size, *string;
       int s;

       if ((string = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_stringobject(string))
               return err_scerrset(TypeFailure, string, "StringS");
       if ((s = getstringsize(string)) < 0)
               return -1;
       if (xPop((TscOperand) 1, sc_pb) != 0)
               return -1;
       if ((size = newintobject(s)) == NULL)
               return -1;
       if (xPush(size, sc_pb) != 0) {
               DECREF(size);
               return -1;
       }
       DECREF(size);
       return 0;
}

/*
 *
 */
static int
xListS(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       object *size, *list;
       int s;

       if ((list = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_listobject(list))
               return err_scerrset(TypeFailure, list, "ListS");
       if ((s = getlistsize(list)) < 0)
               return -1;
       if (xPop((TscOperand) 1, sc_pb) != 0)
               return -1;
       if ((size = newintobject(s)) == NULL)
               return -1;
       if (xPush(size, sc_pb) != 0) {
               DECREF(size);
               return -1;
       }
       DECREF(size);
       return 0;
}

/*
 * Marshal a fixed string to the buffer.
 */
static int
xPutFS(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *string;
       char *str;

       if ((string = stacktop(sc_pb)) == NULL) {
               return -1;
       }
       if (!is_stringobject(string))
               return err_scerrset(TypeFailure, string, "PutFS");
       if (getstringsize(string) != size)
               return err_scerrset(SizeError, string, "PutFS");
       if ((str = getstringvalue(string)) == NULL)
               return -1;
       if ((size + sc_pb->bp) > sc_pb->maxbufsize) {
               err_scerr(BufferOverflow);
               return -1;
       }
       memcpy(&sc_pb->buffer[sc_pb->bp], str, (int)size);
       sc_pb->bp += size;
       return xPop((TscOperand) 1, sc_pb);
}


/*
 *      Test the size of a string or list
 */
static int
xTStringSeq(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *string;

       if ((string = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_stringobject(string))
               return err_scerrset(TypeFailure, string, "TStringSeq");
       if (getstringsize(string) != size)
               return err_scerrset(SizeError, string, "TStringSeq");
       return 0;
}

static int
xTStringSlt(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *string;

       if ((string = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_stringobject(string))
               return err_scerrset(TypeFailure, string, "TStringSlt");
       if (getstringsize(string) > size)
               return err_scerrset(SizeError, string, "TStringSlt");
       return 0;
}

static int
xTListSeq(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *list;

       if ((list = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_listobject(list))
               return err_scerrset(TypeFailure, list, "TListSeq");
       if (getlistsize(list) != size)
               return err_scerrset(SizeError, list, "TListSeq");
       return 0;
}

static int
xTListSlt(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *list;

       if ((list = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_listobject(list))
               return err_scerrset(TypeFailure, list, "TListSlt");
       if (getlistsize(list) > size)
               return err_scerrset(SizeError, list, "TListSlt");
       return 0;
}

static int
xPutVS(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       object *string;
       char *str;
       int size;

       if ((string = stacktop(sc_pb)) == NULL)
               return -1;
       if ((size = getstringsize(string)) < 0)
               return (size == -1 ? -1 : err_scerrset(SizeError, string, "PutVS"));
       if ((str = getstringvalue(string)) == NULL)
               return -1;
       if (sc_pb->bp + size > sc_pb->maxbufsize) {
               err_scerr(BufferOverflow);
               return -1;
       }
       memcpy(&sc_pb->buffer[sc_pb->bp], str, size);
       sc_pb->bp += size;
       return xPop((TscOperand) 1, sc_pb);
}

/*
 *      The loop instructions.
 */
static int
xLoopPut(label, sc_pb)
       TscOperand label;
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop this;
       object *list, *element;

       if (findloop(&this, label, sc_pb) < 0)
               return -1;
       if ((list = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_listobject(list))
               return err_scerrset(TypeFailure, list, "LoopPut");
       if (this->l_index >= getlistsize(list)) {
               sc_pb->pc = this->l_endaddr;
               /*
               **      Pop the list from the stack
               */
               return xPop((TscOperand)1, sc_pb);
       }
       if ((element = getlistitem(list, this->l_index)) == NULL)
               return -1;
       return xPush(element, sc_pb);
}

static int
xLoopGet(label, sc_pb)
       TscOperand label;
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop this;
       object *element, *integer;
       int i;

       if ((i = findloop(&this, label, sc_pb)) < 0)
               return -1;
       else if (i == 1) {
               /*
                *       It is the first time we enter LoopGet label
                */
               if ((this->l_list = newlistobject(0)) == NULL)
                       return -1;
               if ((integer = stacktop(sc_pb)) == NULL)
                       return -1;
               if (!is_intobject(integer))
                       return err_scerrset(TypeFailure, integer, "LoopGet");
               this->l_size = getintvalue(integer);
               if (xPop((TscOperand) 1, sc_pb) != 0)
                       return -1;
       } else {
               if ((element = stacktop(sc_pb)) == NULL)
                       return -1;
               if (addlistitem(this->l_list, element) != 0)
                       return -1;
               if (xPop((TscOperand) 1, sc_pb) != 0)
                       return -1;
       }
       if (this->l_index >= this->l_size) {
               int ret;

               sc_pb->pc = this->l_endaddr;
               ret = xPush(this->l_list, sc_pb);
               DECREF(this->l_list);
               return ret;
       }
       return 0;
}

static int
xEndLoop(label, sc_pb)
       TscOperand label;
       struct sc_ProcessBlock *sc_pb;
{
       TpsLoop this;

       if (findloop(&this, label, sc_pb) < 0)
               return -1;
       this ->l_index += 1;
       sc_pb->pc = this->l_retaddr;
       return 0;
}

static int
xPutI(flags, sc_pb)
       TscOperand flags;
       struct sc_ProcessBlock *sc_pb;
{
       object *integer;

       if ((integer = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_intobject(integer))
               return err_scerrset(TypeFailure, integer, "PutI");
       if (flags & ALL_FIELDS) {
               long i;

               /*
                *       The integer must be marshalles in the header.
                *       No type casting according to the type flag because
                *       we have to cast to the headerfield types.
                */
               i = getintvalue(integer);
               switch(flags & ALL_FIELDS) {

               case H_EXTRA:
                       sc_pb->hdr.h_extra = (uint16)i;
                       break;

               case H_SIZE:
                       sc_pb->hdr.h_size = (bufsize)i;
                       break;

               case H_OFFSET:
                       sc_pb->hdr.h_offset = (int32)i;
                       break;

               default:
                       if ((integer = newintobject(flags & ALL_FIELDS)) == NULL)
                               return -1;
                       err_scerrset(FlagError, integer, "Ailword");
                       DECREF(integer);
                       return -1;
               }
       } else {
               long i;

               i = getintvalue(integer);
               switch(flags & ALLTYPES) {

               case 0:
                       {
                               int16 x;

                               x = (int16)i;
                               if ((sc_pb->bp + sizeof(int16)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&sc_pb->buffer[sc_pb->bp], &x, sizeof(int16));
                               sc_pb->bp += sizeof(int16);
                               break;
                       }

               case NOSIGN:
                       {
                               uint16 x;

                               x = (uint16)i;
                               if ((sc_pb->bp + sizeof(uint16)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&sc_pb->buffer[sc_pb->bp], &x, sizeof(uint16));
                               sc_pb->bp += sizeof(uint16);
                               break;
                       }

               case INT32:
                       {
                               int32 x;

                               x = (int32)i;
                               if ((sc_pb->bp + sizeof(int32)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&sc_pb->buffer[sc_pb->bp], &x, sizeof(int32));
                               sc_pb->bp += sizeof(int32);
                               break;
                       }

               case INT32 | NOSIGN:
                       {
                               uint32 x;

                               x = (uint32)i;
                               if ((sc_pb->bp + sizeof(uint32)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&sc_pb->buffer[sc_pb->bp], &x, sizeof(uint32));
                               sc_pb->bp += sizeof(uint32);
                               break;
                       }
               default:
                       {
                               object *x;

                               if ((x = newintobject(flags)) == NULL)
                                       return -1;
                               err_scerrset(FlagError, x, "PutI");
                               DECREF(x);
                               return -1;
                       }
               }
       }
       return xPop((TscOperand)1, sc_pb);
}

static int
xPutC(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       capability cap;
       object *capobj;

       if ((capobj = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_capobj(capobj))
               return err_scerrset(TypeFailure, capobj, "xPutC");
       if (getcapability(capobj, &cap) != 0)
               return -1;
       if ((sc_pb->bp + CAPSIZE) > sc_pb->maxbufsize) {
               err_scerr(BufferOverflow);
               return -1;
       }
       memcpy(&sc_pb->buffer[sc_pb->bp], &cap, CAPSIZE);
       sc_pb->bp += CAPSIZE;
       return xPop((TscOperand) 1, sc_pb);
}

static int
xDup(n, sc_pb)
       TscOperand n;
       struct sc_ProcessBlock *sc_pb;
{

       if ((int)n > sc_pb->sp) {
               object *i;

               if ((i = newintobject((long)n)) == NULL)
                       return -1;
               err_scerrset(RangeError, i, "Dup");
               DECREF(i);
               return -1;
       }
       return xPush(sc_pb->stack[sc_pb->sp - n], sc_pb);
}

static int
xPop(n, sc_pb)
       TscOperand n;
       struct sc_ProcessBlock *sc_pb;
{
       int i;

       if ((sc_pb->sp - (int)n) < 0) {
               err_scerr(StackUnderflow);
               return -1;
       }
       for (i = 0; i < (int)n; i++) {
               sc_pb->sp--;
#ifdef STACK_TRACE
               printf("popped :");
               printobject(sc_pb->stack[sc_pb->sp], stdout, 0);
               printf("\n");
#endif
               DECREF(sc_pb->stack[sc_pb->sp]);
       }
       return 0;
}

static int
xAlign(n, sc_pb)
       TscOperand n;
       struct sc_ProcessBlock *sc_pb;
{
       int align = sc_pb->bp % (int)n;

#ifdef SCDEBUG
       printf("Old bp = %d\n", sc_pb->bp);
#endif
       sc_pb->bp += (align == 0) ? 0 : ((int)n - align);
#ifdef SCDEBUG
       printf("New bp = %d\n", sc_pb->bp);
#endif
       return 0;
}

static int
xPack(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *element, *tuple;
       int i, ret;

       if ((tuple = newtupleobject((int)size)) == NULL)
               return -1;
       for (i = 0; i < (int)size; i++) {
               if ((element = stacktop(sc_pb)) == NULL)
                       return -1;
               if (settupleitem(tuple, (int)size - i - 1, element) != 0)
                       return -1;
               INCREF(element);
               if (xPop((TscOperand) 1, sc_pb) != 0)
                       return -1;
       }
       ret = xPush(tuple, sc_pb);
       DECREF(tuple);
       return ret;
}

static int
xGetVS(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       object *string, *integer;
       int size;

       if ((integer = stacktop(sc_pb)) == NULL)
               return -1;
       if (!is_intobject(integer))
               return err_scerrset(TypeFailure, integer, "GetVS");
       size = getintvalue(integer);
       if ((sc_pb->bp + size) > sc_pb->maxbufsize) {
               err_scerr(BufferOverflow);
               return -1;
       }
       if ((string = newsizedstringobject(&sc_pb->buffer[sc_pb->bp], size)) == NULL)
               return -1;
       sc_pb->bp += size;
       if (xPop((TscOperand) 1, sc_pb) != 0)
               return -1;
       if (xPush(string, sc_pb) != 0) {
               return -1;
       }
       DECREF(string);
       return 0;
}

static int
xGetFS(size, sc_pb)
       TscOperand size;
       struct sc_ProcessBlock *sc_pb;
{
       object *string;

       if ((sc_pb->bp + (int)size) > sc_pb->maxbufsize) {
               err_scerr(BufferOverflow);
               return -1;
       }
       if ((string = newsizedstringobject(&sc_pb->buffer[sc_pb->bp], (int)size)) == NULL)
               return -1;
       sc_pb->bp += (int)size;
       if(xPush(string, sc_pb) != 0) {
               return -1;
       }
       DECREF(string);
       return 0;
}

static int
xGetI(flags, sc_pb)
       TscOperand flags;
       struct sc_ProcessBlock *sc_pb;
{
       object *integer;
       long i;

       if (flags & ALL_FIELDS) {

               switch(flags & ALL_FIELDS) {

               case H_EXTRA:
                       i = (long)sc_pb->hdr.h_extra;
                       break;

               case H_SIZE:
                       i = (long)sc_pb->hdr.h_size;
                       break;

               case H_OFFSET:
                       i = (long)sc_pb->hdr.h_offset;
                       break;

               default:
                       if ((integer = newintobject(flags & ALL_FIELDS)) == NULL)
                               return -1;
                       err_scerrset(FlagError, integer, "Ailword");
                       DECREF(integer);
                       return -1;
               }
       } else {
               switch(flags & ALLTYPES) {

               case 0:
                       {
                               int16 x;

                               if ((sc_pb->bp + sizeof(int16)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&x, &sc_pb->buffer[sc_pb->bp], sizeof(int16));
                               sc_pb->bp += sizeof(int16);
                               i = (long)x;
                               break;
                       }

               case NOSIGN:
                       {
                               uint16 x;

                               if ((sc_pb->bp + sizeof(uint16)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&x, &sc_pb->buffer[sc_pb->bp], sizeof(uint16));
                               sc_pb->bp += sizeof(uint16);
                               i = (long)x;
                               break;
                       }

               case INT32:
                       {
                               int32 x;

                               if ((sc_pb->bp + sizeof(int32)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&x, &sc_pb->buffer[sc_pb->bp], sizeof(int32));
                               sc_pb->bp += sizeof(int32);
                               i = (long)x;
                               break;
                       }

               case INT32 | NOSIGN:
                       {
                               uint32 x;

                               if ((sc_pb->bp + sizeof(uint32)) > sc_pb->maxbufsize) {
                                       err_scerr(BufferOverflow);
                                       return -1;
                               }
                               memcpy(&x, &sc_pb->buffer[sc_pb->bp], sizeof(uint32));
                               sc_pb->bp += sizeof(uint32);
                               i = (long)x;
                               break;
                       }
               default:
                       {
                               if ((integer = newintobject(flags)) == NULL)
                                       return -1;
                               err_scerrset(FlagError, integer, "GetI");
                               DECREF(integer);
                               return -1;
                       }
               }
       }
       if ((integer = newintobject(i)) == NULL)
               return -1;
       if (xPush(integer, sc_pb) != 0) {
               DECREF(integer);
               return -1;
       }
       DECREF(integer);
       return 0;
}

static int
xGetC(flags, sc_pb)
       TscOperand flags;
       struct sc_ProcessBlock *sc_pb;
{
       extern object *newcapobject();
       object *capobj;
       capability cap;

       if ((int)flags != 0) {
               switch ((int)flags) {

               case PSEUDOFIELD:
                       cap.cap_port = sc_pb->hdr.h_port;
                       cap.cap_priv = sc_pb->hdr.h_priv;
                       break;
               }
       } else {
               if ((CAPSIZE + sc_pb->bp) > sc_pb->maxbufsize) {
                       err_scerr(BufferOverflow);
                       return -1;
               }
               memcpy(&cap, &sc_pb->buffer[sc_pb->bp], CAPSIZE);
       }
       if ((capobj = newcapobject(&cap)) == NULL)
               return -1;
       return xPush(capobj, sc_pb);
}

static int
xEqual(sc_pb)
       struct sc_ProcessBlock *sc_pb;
{
       object *int1, *int2;

       if (sc_pb->sp < 2) {
               err_scerr(StackUnderflow);
               return -1;
       }
       int1 = sc_pb->stack[sc_pb->sp - 1];
       int2 = sc_pb->stack[sc_pb->sp - 2];
       if ((int1 == NULL) || (int2 == NULL))
               return -1;
       if (!is_intobject(int1))
               return err_scerrset(TypeFailure, int1, "Equal");
       if (!is_intobject(int2))
               return err_scerrset(TypeFailure, int2, "Equal");
       if (getintvalue(int1) != getintvalue(int2)) {
               object *tmptuple;

               if ((tmptuple = newtupleobject(2)) == NULL)
                       return -1;
               INCREF(int1);
               if (settupleitem(tmptuple, 0, int1) != 0) {
                       DECREF(tmptuple);
                       DECREF(int1);
                       return -1;
               }
               if (settupleitem(tmptuple, 1, int2) != 0) {
                       DECREF(tmptuple);
                       DECREF(int2);
                       return -1;
               }
               return err_scerrset(SizeError, tmptuple, "Equal");
       }
       return 0;
}

object *
sc_interpreter(self, args)
       object *self, *args;
{
TscOpcode opcode;
TscOperand operand;
int datasize, ret;
object *returnobject;
struct sc_ProcessBlock sc_pb;

       if ((datasize = init(self, &sc_pb)) < 0)
               return NULL;
       memcpy(&opcode, sc_pb.data, sizeof(TscOpcode));
       sc_pb.datsize = datasize;
       sc_pb.pc += sizeof(TscOpcode);
       if (opcode != BufSize) {
               free((char *)sc_pb.stack);
               return err_scerr(NoBufSize);
       }
       memcpy(&operand, &sc_pb.data[sc_pb.pc], sizeof(TscOperand));
       sc_pb.pc += sizeof(TscOperand);
       sc_pb.buffer = (unsigned char *)malloc(operand);
       sc_pb.maxbufsize = (int)operand;
       if (sc_pb.buffer == NULL) {
               free((char *)sc_pb.stack);
               return err_nomem();
       }
       memcpy(&opcode, &sc_pb.data[sc_pb.pc], sizeof(TscOpcode));
       if (opcode != NoArgs) {
               if (xPush(args, &sc_pb) != 0) {
                       UnInit(self, &sc_pb);
                       return NULL;
               }
       }
       while (sc_pb.pc < datasize) {
               memcpy(&opcode, &sc_pb.data[sc_pb.pc], sizeof(TscOpcode));
               sc_pb.pc += sizeof(TscOpcode);
               if (opcode & (OPERAND | FLAGS)) {
                       memcpy(&operand, &sc_pb.data[sc_pb.pc], sizeof(TscOperand));
                       sc_pb.pc += sizeof(TscOperand);
               }
#ifdef SCDEBUG
               xPrintCode(opcode);
               if ((opcode & FLAGS) && (opcode & OPERAND))
                       xPrintFlags(operand);
               else if (opcode & OPERAND)
                       xPrintNum(operand);
               printf("\n");
               fflush(stdout);
#endif
#ifdef STACK_TRACE
               {
                       register i;

                       printf("Stack trace :\n");
                       for(i = 0; i < sc_pb.sp; i++) {
                               printobject(sc_pb.stack[i], stdout, 0);
                               printf("\n");
                       }
               }
#endif
               switch(opcode) {

               case NoArgs:
                       ret = 0;
                       if (args != NULL) {
                               err_scerrset(TypeFailure, args, "NoArgs");
                               ret = -1;
                       }
                       break;

               case BufSize:
                       UnInit(self, &sc_pb);
                       return err_scerr(TwoBufSize);

               case Trans:
                       ret = xTrans(self, operand, &sc_pb);
                       break;

               case TTupleS:
                       ret = xTTupleS(operand, &sc_pb);
                       break;

               case Unpack:
                       ret = xUnpack(operand, &sc_pb);
                       break;

               case AilWord:
                       ret = xAilword(operand, &sc_pb);
                       break;

               case StringS:
                       ret = xStringS(&sc_pb);
                       break;

               case ListS:
                       ret = xListS(&sc_pb);
                       break;

               case PutFS:
                       ret = xPutFS(operand, &sc_pb);
                       break;

               case TStringSeq:
                       ret = xTStringSeq(operand, &sc_pb);
                       break;

               case TStringSlt:
                       ret = xTStringSlt(operand, &sc_pb);
                       break;

               case PutVS:
                       ret = xPutVS(&sc_pb);
                       break;

               case TListSeq:
                       ret = xTListSeq(operand, &sc_pb);
                       break;

               case TListSlt:

        ret = xTListSlt(operand, &sc_pb);
                       break;

               case LoopPut:
                       ret = xLoopPut(operand, &sc_pb);
                       break;

               case EndLoop:
                       ret = xEndLoop(operand, &sc_pb);
                       break;

               case PutI:
                       ret = xPutI(operand, &sc_pb);
                       break;

               case PutC:
                       ret = xPutC(&sc_pb);
                       break;

               case Dup:
                       ret = xDup(operand, &sc_pb);
                       break;

               case Pop:
                       ret = xPop(operand, &sc_pb);
                       break;

               case Align:
                       ret = xAlign(operand, &sc_pb);
                       break;

               case Pack:
                       ret = xPack(operand, &sc_pb);
                       break;

               case GetVS:
                       ret = xGetVS(&sc_pb);
                       break;

               case LoopGet:
                       ret = xLoopGet(operand, &sc_pb);
                       break;

               case GetFS:
                       ret = xGetFS(operand, &sc_pb);
                       break;

               case GetI:
                       ret = xGetI(operand, &sc_pb);
                       break;

               case GetC:
                       ret = xGetC(operand, &sc_pb);
                       break;

               case PushI:
                       {
                               object *element;

                               element = newintobject((long)operand);
                               if (element == NULL) {
                                       UnInit(self, &sc_pb);
                                       return NULL;
                               }
                               ret = xPush(element, &sc_pb);
                               if (ret == 0)
                                       DECREF(element);
                       }
                       break;

               case Equal:
                       ret = xEqual(&sc_pb);
                       break;

               default:
                       {
                               char errstr[256];

                               UnInit(self, &sc_pb);
                               sprintf(errstr, "Unknow stubcode %d", opcode);
                               err_setstr(RuntimeError, errstr);
                               return NULL;
                       }
               }
               if (ret != 0) {
                       UnInit(self, &sc_pb);
                       return NULL;
               }
       }
       if (sc_pb.sp > 0) {
               INCREF(sc_pb.stack[sc_pb.sp - 1]);
               returnobject = sc_pb.stack[sc_pb.sp - 1];
       } else {
               INCREF(None);
               returnobject = None;
       }
       UnInit(self, &sc_pb);
       return returnobject;
}
