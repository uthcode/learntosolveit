#include<stdio.h>
#include <stdlib.h>
//print input one word per line
#define IN_WORD 1
#define OUT_WORD 2

int main(void)
{
    int c, state;

    state = OUT_WORD;//initially not in a word


    while((c=getchar())!=EOF)
    {

        if(c == 32)  //space, (could/should also match tabs )
        {

            //see if current state is in a word
            if(state == IN_WORD)
            {
                printf("\n");//moving outside a word so add a line feed, so the next word is outputted on its own line
            }
            state = OUT_WORD;

        }

        else if(state == OUT_WORD) //if space did not match above, check if were previously outside a word
        {
            state = IN_WORD; //we must now be in a word then,
            putchar(c);//just entered a word, print first chars
        }
        else//we are in a word, output all characters, we put this 'else' here so we do not print space characters
        {
            putchar(c);
        }
    }

    getchar();
    return EXIT_SUCCESS;
}
