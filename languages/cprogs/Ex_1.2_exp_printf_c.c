/***
 *
 * Experiment to find out what happens when prints's argument string
 * contains \c, where c is some character not listed above.
 *
 ***/

#include<stdio.h>

int main(void)
{
    printf("a:\a"); /* valid */
    printf("b:\b"); /* valid */
    printf("c:\c");
    printf("d:\d");
    printf("e:\e"); /* valid */
    printf("f:\f"); /* valid */
    printf("g:\g");
    printf("h:\h");
    printf("i:\i");
    printf("j:\j");
    printf("k:\k");
    printf("l:\l");
    printf("m:\m");
    printf("n:\n"); /* valid */
    printf("o:\o");
    printf("p:\p");
    printf("q:\q");
    printf("r:\r"); /* valid */
    printf("s:\s");
    printf("t:\t"); /* valid */
    /*
    * \u below stands for unicode.
    * warning: universal character names are only valid in C++ and C99
    * without anything it will give the error incomplete universal character.
    * we will give 2603 unicode codepoint which stands for snowman
    */
    printf("u:\u2603"); /* valid */
    printf("v:\v"); /* valid */
    printf("w:\w");
    /* \x is for hexadecimals. It should be followed by valid hexadecimal.
     * Lets give D as hexadecimal value */
    printf("x:\xD"); /* valid */
    printf("y:\y");
    printf("z:\z");
    printf("A:\A");
    printf("B:\B");
    printf("C:\C");
    printf("D:\D");
    printf("E:\E"); /* valid */
    printf("F:\F");
    printf("G:\G");
    printf("H:\H");
    printf("I:\I");
    printf("J:\J");
    printf("K:\K");
    printf("L:\L");
    printf("M:\M");
    printf("N:\N");
    printf("O:\O");
    printf("P:\P");
    printf("Q:\Q");
    printf("R:\R");
    printf("S:\S");
    printf("T:\R");

    /*
    * \U below stands for unicode.
    * error: incomplete universal character name \U
    * without anything it will give the error incomplete universal character.
    * we will give 2603 unicode codepoint which stands for snowman
    */

    printf("U:\U00002603");
    printf("V:\V");
    printf("W:\W");
    printf("X:\X");
    printf("Y:\Y");
    printf("Z:\Z");
    printf("0:\0");
    printf("1:\1"); /* valid */
    printf("2:\2"); /* valid */
    printf("3:\3"); /* valid */
    printf("4:\4"); /* valid */
    printf("5:\5"); /* valid */
    printf("6:\6"); /* valid */
    printf("7:\7"); /* valid */
    printf("8:\8");
    printf("9:\9");
    printf("~:\~");
    printf("`:\`");
    printf("!:\!");
    printf("@:\@");
    printf("#:\#");
    printf("$:\$");
    printf("%:\%"); /* warning: unknown conversion type character in : in format. Spurious trailing % in format */
    printf("^:\^"); /* warning: unknown escape sequence \^ */
    printf("&:\&");
    printf("*:\*");
    printf("(:\("); /* valid */
    printf("):\)");
    printf("_:\_");
    printf("-:\-");
    printf("+:\+");
    printf("{:\{"); /* valid */
    printf("[:\["); /* valid */
    printf("}:\}");
    printf("]:\]");
    printf("|:\|");
    printf("\:\\");
    printf("a:\a"); /* valid */
    printf("::\:");
    printf(";:\;");
    /* escape the double-quotes */
    printf("\":\""); /* valid */
    printf("':\'"); /* valid */
    printf("<:\<");
    printf(",:\,");
    printf(">:\>");
    printf(".:\.");
    printf("?:\?"); /* valid */
    printf("/:\/");
}
