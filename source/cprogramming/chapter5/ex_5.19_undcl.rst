=============================================
5.19 undcl does not add redundant parentheses
=============================================

Question
========

Modify undcl so that it does not add redundant parentheses to declarations.

.. literalinclude:: cprogs/ex_5.19_undcl.c
   :language: c
   :tab-width: 4


Explanation
===========

The book provides this undcl implementation

::

    /* undcl:  convert word descriptions to declarations */
    main() {
      int type;
      char temp[MAXTOKEN];
      while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
      }
      if (type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if (type == '*') {
        sprintf(temp, "(*%s)", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else
        printf("invalid input at %s\n", token);
    }

The important change in our implementation from the book program is, if the nexttoken is a PARENS or BRACKETS then we
print them out.

::


       if (type == PARENS || type == BRACKETS)
         strcat(out, token);
       else if (type == '*') {
    +                if ((type = nexttoken()) == PARENS || type == BRACKETS)
         sprintf(temp, "(*%s)", out);
    +                else
    +                    sprintf(temp, "*%s", out);
         strcpy(out, temp);
       } else if (type == NAME) {



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20undcl%20builds%20declaration%20string%20by%20prepending%20%2A%20for%20%22pointer%20to%22%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20out%5B40%5D%2C%20temp%5B40%5D%3B%0A%20%20%20%20%2F%2A%20%22p%20pointer%20to%20int%22%20-%3E%20%22int%20%2Ap%22%20%2A%2F%0A%20%20%20%20strcpy%28out%2C%20%22p%22%29%3B%0A%20%20%20%20sprintf%28temp%2C%20%22%2A%25s%22%2C%20out%29%3B%0A%20%20%20%20strcpy%28out%2C%20temp%29%3B%0A%20%20%20%20printf%28%22int%20%25s%5Cn%22%2C%20out%29%3B%0A%20%20%20%20%2F%2A%20%22fp%20pointer%20to%20function%20returning%20char%22%20-%3E%20%22char%20%28%2Afp%29%28%29%22%20%2A%2F%0A%20%20%20%20strcpy%28out%2C%20%22fp%22%29%3B%0A%20%20%20%20sprintf%28temp%2C%20%22%28%2A%25s%29%28%29%22%2C%20out%29%3B%0A%20%20%20%20strcpy%28out%2C%20temp%29%3B%0A%20%20%20%20printf%28%22char%20%25s%5Cn%22%2C%20out%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
