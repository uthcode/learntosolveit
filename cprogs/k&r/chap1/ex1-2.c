/* Experiment to find out what happens while printf's argument string contains
 * a \c where c is some character not listed above. */

/* This is an experimentation question. Here is the list of all the characters
 * in my keyboard escaped. */

#include<stdio.h>

int main()
{
    printf("Hello, World\a"); /* accepted */
    printf("Hello, World\b"); /* accepted */
    printf("Hello, World\c");
    printf("Hello, World\d");
    printf("Hello, World\e"); /* accepted */
    printf("Hello, World\f"); /* accepted */
    printf("Hello, World\g");
    printf("Hello, World\h");
    printf("Hello, World\i");
    printf("Hello, World\j");
    printf("Hello, World\k");
    printf("Hello, World\l");
    printf("Hello, World\m");
    printf("Hello, World\n");
    printf("Hello, World\o");
    printf("Hello, World\p");
    printf("Hello, World\q");
    printf("Hello, World\r"); /* accepted */
    printf("Hello, World\s");
    printf("Hello, World\t"); /* accepted */
    printf("Hello, World\u"); /* should be followed by unicode */
    printf("Hello, World\v");
    printf("Hello, World\w");
    printf("Hello, World\x"); /* should be followed by hexadecimal */
    printf("Hello, World\y");
    printf("Hello, World\z");
    printf("Hello, World\A");
    printf("Hello, World\B");
    printf("Hello, World\C");
    printf("Hello, World\D");
    printf("Hello, World\E"); /* accepted */
    printf("Hello, World\F");
    printf("Hello, World\G");
    printf("Hello, World\H");
    printf("Hello, World\I");
    printf("Hello, World\J");
    printf("Hello, World\K");
    printf("Hello, World\L");
    printf("Hello, World\M");
    printf("Hello, World\N");
    printf("Hello, World\O");
    printf("Hello, World\P");
    printf("Hello, World\Q");
    printf("Hello, World\R");
    printf("Hello, World\S");
    printf("Hello, World\T");
    printf("Hello, World\U");
    printf("Hello, World\V");
    printf("Hello, World\W");
    printf("Hello, World\X");
    printf("Hello, World\Y");
    printf("Hello, World\Z");
    printf("Hello, World\0"); /* accepted.*/
    printf("Hello, World\1"); /* accepted.*/
    printf("Hello, World\2"); /* accepted.*/
    printf("Hello, World\3"); /* accepted.*/
    printf("Hello, World\4"); /* accepted.*/
    printf("Hello, World\5"); /* accepted.*/
    printf("Hello, World\6"); /* accepted.*/
    printf("Hello, World\7"); /* accepted.*/
    printf("Hello, World\8");
    printf("Hello, World\9");
    printf("Hello, World\~");
    printf("Hello, World\`");
    printf("Hello, World\!");
    printf("Hello, World\@");
    printf("Hello, World\#");
    printf("Hello, World\$");
    printf("Hello, World\%");
    printf("Hello, World\^");
    printf("Hello, World\&");
    printf("Hello, World\*");
    printf("Hello, World\("); /* accepted.*/
    printf("Hello, World\)");
    printf("Hello, World\-");
    printf("Hello, World\_");
    printf("Hello, World\+");
    printf("Hello, World\=");
    printf("Hello, World\|");
    printf("Hello, World\\"); /*accepted.*/
    printf("Hello, World\<");
    printf("Hello, World\>");
    printf("Hello, World\,");
    printf("Hello, World\.");
    printf("Hello, World\/");
    printf("Hello, World\?"); /* accpted.*/
}

/*  Here is output of the program.
	warning: unknown escape sequence '\c'
	warning: unknown escape sequence '\d'
	warning: unknown escape sequence '\g'
	warning: unknown escape sequence '\h'
	warning: unknown escape sequence '\i'
	warning: unknown escape sequence '\j'
	warning: unknown escape sequence '\k'
	warning: unknown escape sequence '\l'
	warning: unknown escape sequence '\m'
	warning: unknown escape sequence '\o'
	warning: unknown escape sequence '\p'
	warning: unknown escape sequence '\q'
	warning: unknown escape sequence '\s'
	warning: universal character names are only valid in C++ and C99
	incomplete universal character name \u
	warning: unknown escape sequence '\w'
	\x used with no following hex digits
	warning: unknown escape sequence '\y'
	warning: unknown escape sequence '\z'
	warning: unknown escape sequence '\A'
	warning: unknown escape sequence '\B'
	warning: unknown escape sequence '\C'
	warning: unknown escape sequence '\D'
	warning: unknown escape sequence '\F'
	warning: unknown escape sequence '\G'
	warning: unknown escape sequence '\H'
	warning: unknown escape sequence '\I'
	warning: unknown escape sequence '\J'
	warning: unknown escape sequence '\K'
	warning: unknown escape sequence '\L'
	warning: unknown escape sequence '\M'
	warning: unknown escape sequence '\N'
	warning: unknown escape sequence '\O'
	warning: unknown escape sequence '\P'
	warning: unknown escape sequence '\Q'
	warning: unknown escape sequence '\R'
	warning: unknown escape sequence '\S'
	warning: universal character names are only valid in C++ and C99
	incomplete universal character name \U
	warning: unknown escape sequence '\V'
	warning: unknown escape sequence '\W'
	warning: unknown escape sequence '\X'
	warning: unknown escape sequence '\Y'
	warning: unknown escape sequence '\Z'
	warning: unknown escape sequence '\8'
	warning: unknown escape sequence '\9'
	warning: unknown escape sequence '\~'
	warning: unknown escape sequence '\`'
	warning: unknown escape sequence '\!'
	warning: unknown escape sequence '\@'
	warning: unknown escape sequence '\#'
	warning: unknown escape sequence '\$'
	warning: unknown escape sequence '\^'
	warning: unknown escape sequence '\&'
	warning: unknown escape sequence '\*'
	warning: unknown escape sequence '\)'
	warning: unknown escape sequence '\-'
	warning: unknown escape sequence '\_'
	warning: unknown escape sequence '\+'
	warning: unknown escape sequence '\='
	warning: unknown escape sequence '\|'
	warning: unknown escape sequence '\<'
	warning: unknown escape sequence '\>'
	warning: unknown escape sequence '\,'
	warning: unknown escape sequence '\.'
	warning: unknown escape sequence '\/'
*/
