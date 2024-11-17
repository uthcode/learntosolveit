========================================================
Exercise 5.19 - undcl does not add redundant parentheses
========================================================

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


