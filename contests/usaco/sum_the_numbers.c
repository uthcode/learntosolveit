/*
ID: senthil9
LANG: C
TASK: test
*/

#include <stdio.h>

main () {
    FILE *fin  = fopen ("test.in", "r");
    FILE *fout = fopen ("test.out", "w");
    int a, b;
    fscanf (fin, "%d %d", &a, &b);      /* the two input integers */
    fprintf (fout, "%d\n", a+b);
    exit (0);
}
