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


/*
**     This file contains the data used in Ail, Python and sc2txt.
**
**     If you want to add an instuction to the instructions just define
**     it here and add the instruction in the function sc_interpreter in
**     the file sc_interpreter.c in the switch. You also have to make a
**     new function with the name x{instruction_name} in the file
**     sc_interpreter.
*/

/*
**     When you want to change the types of the opcode or the operand
**     you maybe need to adjust the options to mypf. And the defines :
**     SwapOpcode, SwapOperand.
*/

typedef unsigned char TscOpcode;
typedef long TscOperand;

#define SC_MAGIC       0x19901991

#define SwapOpcode(x)  x = x
#define SwapOperand(l) ((l))=(((((l))>>24)&0xFF)|((((l))>>8)&0xFF00)|((((l))<<8)&0xFF0000)|((((l)) <<24)&0xFF000000))

#define STKSIZE                256

#define OPERAND                0x80
#define FLAGS          0x40

/*
**     The headerfields. The value of the flag is the index of the fields
**     array from the file mhdr.c plus one
*/

#define H_EXTRA                0x00000001
#define H_SIZE         0x00000002
#define H_OFFSET       0x00000003
#define H_PORT         0x00000004
#define H_PRIV         0x00000005
#define PSEUDOFIELD    0x00000006
#define ALL_FIELDS     0x000000ff

/*
**     The specefiers for the integers
*/

#define NOSIGN         0x00000100
#define INT32          0x00000200
#define ALLTYPES       0xffffff00

/*
**     The opcode with no operand
*/

#define ListS          0x00
#define PutVS          0x01
#define GetVS          0x02
#define StringS                0x03
#define        Equal           0x04
#define NoArgs         0x05

/*
 *    Between 0x10 and 0x3f there is space for predefined marshal
 *    and unmarshal functions or macros that do not have an operand
 */

#define MarshTC                0x10
#define UnMarshTC      0x11

/*
**     The opcode with a number as operand
*/

#define BufSize                0x80
#define Trans          0x81
#define TTupleS                0x82
#define Unpack         0x83
#define PutFS          0x84
#define TStringSeq     0x85
#define TStringSlt     0x86
#define TListSeq       0x87
#define TListSlt       0x88
#define LoopPut                0x89
#define EndLoop                0x8a
#define Dup            0x8b
#define Pop            0x8c
#define Align          0x8d
#define Pack           0x8e
#define LoopGet                0x8f
#define GetFS          0x90
#define PushI          0x91

/*
**      Between 0xa0 and 0xbf there is space for predefined marshal
**      and unmarshal functions or macros with a numberas operand
*/


/*
**     The opcodes with flags as operand
*/

#define AilWord                0xc0
#define PutI           0xc1
#define PutC           0xc2
#define GetI           0xc3
#define GetC           0xc4

/*
**     Between 0xe0 and 0xff there is space for predefined marshal
**     and unmarshal functions or macros with flags as operand
*/
