/*  Exercise 1.23
 *
 * Program to remove comments from a C Program.
 *
 * Program should echo quotes and character constants properly
 * C comments do not nest
 *
 */

#include<stdio.h>

int main()
{
    int c;

    while((c=getchar()) != EOF)
    {
        if(c=='"')
        {
            putchar(c);
            c = getchar();
            while(c != '"')
            {
                putchar(c);
                c = getchar();
            }
            if(c == '"')
            {
                putchar(c);
            }
        }
        else if(c == '/')
        {
            c = getchar();
            if(c == '/')
            {
                while(c != '\n')
                    c = getchar();
                putchar('\n');
            }
            else if(c == '*')
            {
                while(c != '/')
                    c = getchar();
                if(c == '/')
                    c = getchar();
                    putchar(c);
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
