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


#include "sc_global.h"

void xPrintNum(Num)
TscOperand Num;
{

    printf(" %ld",(long)Num);
}

void xPrintFlags(Flags)
TscOperand Flags;
{
long x;

    x = (long)Flags;
    x = x & 0x0000000F;
    if (x == H_EXTRA) printf(" h_extra");
    if (x == H_SIZE) printf(" h_size");
    if (x == H_OFFSET) printf(" h_offset");
    if (x == H_PORT) printf(" h_port");
    if (x == H_PRIV) printf(" h_priv");
    if (x == PSEUDOFIELD) printf(" h_port and h_priv");
    x = (long)Flags;
    if (x & NOSIGN) printf(" unsigned");
    if (x & INT32) printf(" int32");
}

void xPrintCode(Opcode)
TscOpcode Opcode;
{

    switch (Opcode) {

    case BufSize:      printf("BufSize");
                       break;

    case Trans:                printf("Trans");
                       break;

    case TTupleS:      printf("TTupleS");
                       break;

    case Unpack:       printf("Unpack");
                       break;

    case AilWord:      printf("AilWord");
                       break;

    case ListS:                printf("ListS");
                       break;

    case StringS:      printf("StringS");
                       break;

    case PutFS:                printf("PutFS");
                       break;

    case TStringSeq:   printf("TStringSeq");
                       break;

    case TStringSlt:   printf("TStringSlt");
                       break;

    case PutVS:                printf("PutVS");
                       break;

    case TListSeq:     printf("TListSeq");
                       break;

    case TListSlt:     printf("TListSlt");
                       break;

    case LoopPut:      printf("LoopPut");
                       break;

    case EndLoop:      printf("EndLoop");
                       break;

    case PutI:         printf("PutI");
                       break;

    case PutC:         printf("PutC");
                       break;

    case Dup:          printf("Dup");
                       break;

    case Pop:          printf("Pop");
                       break;

    case Align:                printf("Align");
                       break;

    case Pack:         printf("Pack");
                       break;

    case GetVS:                printf("GetVS");
                       break;

    case LoopGet:      printf("LoopGet");
                       break;

    case GetFS:                printf("GetFS");
                       break;

    case GetI:         printf("GetI");
                       break;

    case GetC:         printf("GetC");
                       break;

    case PushI:                printf("PushI");
                       break;

    case MarshTC:      printf("MarshTC");
                       break;

    case UnMarshTC:    printf("UnMarshTC");
                       break;

    case Equal:                printf("Equal");
                       break;

    default:           printf("Unknown opcode %04x",(int)Opcode);
                       break;
    }
}
