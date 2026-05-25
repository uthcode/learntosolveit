C Concepts Visualization
========================

Python Tutor's real power is making the **invisible visible**: memory
addresses, stack frames, heap boxes, pointer arrows, and lifetime of
variables — things that are abstract when you read C code but concrete
when you watch the runtime step by step.

Each section below presents a small, self-contained C program paired with
an interactive Python Tutor visualization. Click through the steps and
watch the concept unfold in real time.

Stack Frames and Local Variables
--------------------------------

Every function call creates a new **stack frame** — a private region of memory
holding that function's local variables and return address. When the function
returns, its frame is discarded. Step through the visualization below and watch
the call stack grow (``add``, then ``mul``) and shrink back to ``main``.

.. code-block:: c

   /* Visualization: each function call creates a new stack frame with its own locals */
   #include <stdio.h>
   int add(int a, int b) { return a + b; }
   int mul(int x, int y) { return x * y; }
   int main(void) {
       int p = add(2, 3);  /* new frame for add: a=2, b=3 */
       int q = mul(p, 4);  /* new frame for mul: x=5, y=4 */
       printf("%d\n", q);
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20each%20function%20call%20creates%20a%20new%20stack%20frame%20with%20its%20own%20locals%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20add%28int%20a%2C%20int%20b%29%20%7B%20return%20a%20%2B%20b%3B%20%7D%0Aint%20mul%28int%20x%2C%20int%20y%29%20%7B%20return%20x%20%2A%20y%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20p%20%3D%20add%282%2C%203%29%3B%20%20%2F%2A%20new%20frame%20for%20add%3A%20a%3D2%2C%20b%3D3%20%2A%2F%0A%20%20%20%20int%20q%20%3D%20mul%28p%2C%204%29%3B%20%20%2F%2A%20new%20frame%20for%20mul%3A%20x%3D5%2C%20y%3D4%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20q%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Pointer as a Memory Address
---------------------------

A pointer is just an integer that holds a **memory address**. Python Tutor draws
it as an arrow from the pointer variable to the box it points at. Watch how
``*p = 99`` changes ``x`` — the arrow tells you why.

.. code-block:: c

   /* Visualization: a pointer IS a memory address; * follows the arrow to the value */
   #include <stdio.h>
   int main(void) {
       int x = 42;
       int *p = &x;    /* p holds the address of x */
       printf("x=%d  *p=%d\n", x, *p);
       *p = 99;        /* writing through pointer changes x */
       printf("x=%d  *p=%d\n", x, *p);
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20a%20pointer%20IS%20a%20memory%20address%3B%20%2A%20follows%20the%20arrow%20to%20the%20value%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20x%20%3D%2042%3B%0A%20%20%20%20int%20%2Ap%20%3D%20%26x%3B%20%20%20%20%2F%2A%20p%20holds%20the%20address%20of%20x%20%2A%2F%0A%20%20%20%20printf%28%22x%3D%25d%20%20%2Ap%3D%25d%5Cn%22%2C%20x%2C%20%2Ap%29%3B%0A%20%20%20%20%2Ap%20%3D%2099%3B%20%20%20%20%20%20%20%20%2F%2A%20writing%20through%20pointer%20changes%20x%20%2A%2F%0A%20%20%20%20printf%28%22x%3D%25d%20%20%2Ap%3D%25d%5Cn%22%2C%20x%2C%20%2Ap%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Array and Pointer Arithmetic
----------------------------

``a[i]`` and ``*(p+i)`` compile to the exact same machine instruction.
The array name ``a`` decays to a pointer to its first element. Step through
to see ``p`` advance by ``sizeof(int)`` with each increment, landing on
successive elements.

.. code-block:: c

   /* Visualization: a[i] and *(p+i) are identical — pointer arithmetic on arrays */
   #include <stdio.h>
   int main(void) {
       int a[4] = {10, 20, 30, 40};
       int *p = a;     /* p points to first element */
       int i;
       for (i = 0; i < 4; i++)
           printf("a[%d]=%d  *(p+%d)=%d\n", i, a[i], i, *(p+i));
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20a%5Bi%5D%20and%20%2A%28p%2Bi%29%20are%20identical%20%E2%80%94%20pointer%20arithmetic%20on%20arrays%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20a%5B4%5D%20%3D%20%7B10%2C%2020%2C%2030%2C%2040%7D%3B%0A%20%20%20%20int%20%2Ap%20%3D%20a%3B%20%20%20%20%20%2F%2A%20p%20points%20to%20first%20element%20%2A%2F%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%204%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20printf%28%22a%5B%25d%5D%3D%25d%20%20%2A%28p%2B%25d%29%3D%25d%5Cn%22%2C%20i%2C%20a%5Bi%5D%2C%20i%2C%20%2A%28p%2Bi%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


String as a Null-Terminated Character Array
-------------------------------------------

In C a string is just a ``char`` array whose last byte is ``'\0'`` (ASCII 0).
Every standard library function that walks a string — ``strlen``, ``strcpy``,
``printf`` with ``%s`` — stops when it finds that zero byte. Watch the loop
reveal each character and finally the null terminator.

.. code-block:: c

   /* Visualization: a string is a char array ending with '\0' (value 0) */
   #include <stdio.h>
   int main(void) {
       char s[] = "hi!";
       int i = 0;
       while (s[i]) {
           printf("s[%d] = '%c'  (%d)\n", i, s[i], (int)s[i]);
           i++;
       }
       printf("s[%d] = '\\0' (%d)  <- null terminator\n", i, (int)s[i]);
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20a%20string%20is%20a%20char%20array%20ending%20with%20%27%5C0%27%20%28value%200%29%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%21%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22s%5B%25d%5D%20%3D%20%27%25c%27%20%20%28%25d%29%5Cn%22%2C%20i%2C%20s%5Bi%5D%2C%20%28int%29s%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22s%5B%25d%5D%20%3D%20%27%5C%5C0%27%20%28%25d%29%20%20%3C-%20null%20terminator%5Cn%22%2C%20i%2C%20%28int%29s%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Pass by Value vs Pass by Reference
----------------------------------

C passes arguments **by value**: the called function receives copies, not the
originals. ``swap_wrong`` swaps its local copies; the caller's ``x`` and ``y``
are untouched. ``swap_right`` receives *addresses*, so writes through ``*a``
and ``*b`` reach the caller's variables. Step through both calls and compare
the frames.

.. code-block:: c

   /* Visualization: swap_wrong gets copies; swap_right gets addresses — sees original */
   #include <stdio.h>
   void swap_wrong(int a, int b)   { int t = a; a = b; b = t; }
   void swap_right(int *a, int *b) { int t = *a; *a = *b; *b = t; }
   int main(void) {
       int x = 3, y = 7;
       swap_wrong(x, y);
       printf("after swap_wrong: x=%d y=%d\n", x, y); /* unchanged */
       swap_right(&x, &y);
       printf("after swap_right: x=%d y=%d\n", x, y); /* swapped */
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20swap_wrong%20gets%20copies%3B%20swap_right%20gets%20addresses%20%E2%80%94%20sees%20original%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20swap_wrong%28int%20a%2C%20int%20b%29%20%20%20%7B%20int%20t%20%3D%20a%3B%20a%20%3D%20b%3B%20b%20%3D%20t%3B%20%7D%0Avoid%20swap_right%28int%20%2Aa%2C%20int%20%2Ab%29%20%7B%20int%20t%20%3D%20%2Aa%3B%20%2Aa%20%3D%20%2Ab%3B%20%2Ab%20%3D%20t%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20x%20%3D%203%2C%20y%20%3D%207%3B%0A%20%20%20%20swap_wrong%28x%2C%20y%29%3B%0A%20%20%20%20printf%28%22after%20swap_wrong%3A%20x%3D%25d%20y%3D%25d%5Cn%22%2C%20x%2C%20y%29%3B%20%2F%2A%20unchanged%20%2A%2F%0A%20%20%20%20swap_right%28%26x%2C%20%26y%29%3B%0A%20%20%20%20printf%28%22after%20swap_right%3A%20x%3D%25d%20y%3D%25d%5Cn%22%2C%20x%2C%20y%29%3B%20%2F%2A%20swapped%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Linked List and Heap Allocation
-------------------------------

``malloc`` allocates memory on the **heap** — separate from the stack. Each
call returns the address of a fresh ``node`` struct. Linking them via ``next``
pointers creates a chain. Python Tutor renders each heap object as a box with
arrows showing the chain from ``a`` → ``b`` → ``c``.

.. code-block:: c

   /* Visualization: malloc creates heap boxes; next pointers chain them */
   #include <stdio.h>
   #include <stdlib.h>
   struct node { int val; struct node *next; };
   int main(void) {
       struct node *a = malloc(sizeof *a); a->val = 1; a->next = NULL;
       struct node *b = malloc(sizeof *b); b->val = 2; b->next = NULL;
       struct node *c = malloc(sizeof *c); c->val = 3; c->next = NULL;
       a->next = b;
       b->next = c;
       struct node *p = a;
       while (p) { printf("%d\n", p->val); p = p->next; }
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20malloc%20creates%20heap%20boxes%3B%20next%20pointers%20chain%20them%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0Astruct%20node%20%7B%20int%20val%3B%20struct%20node%20%2Anext%3B%20%7D%3B%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20node%20%2Aa%20%3D%20malloc%28sizeof%20%2Aa%29%3B%20a-%3Eval%20%3D%201%3B%20a-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20struct%20node%20%2Ab%20%3D%20malloc%28sizeof%20%2Ab%29%3B%20b-%3Eval%20%3D%202%3B%20b-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20struct%20node%20%2Ac%20%3D%20malloc%28sizeof%20%2Ac%29%3B%20c-%3Eval%20%3D%203%3B%20c-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20a-%3Enext%20%3D%20b%3B%0A%20%20%20%20b-%3Enext%20%3D%20c%3B%0A%20%20%20%20struct%20node%20%2Ap%20%3D%20a%3B%0A%20%20%20%20while%20%28p%29%20%7B%20printf%28%22%25d%5Cn%22%2C%20p-%3Eval%29%3B%20p%20%3D%20p-%3Enext%3B%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Recursive Call Stack Unwinding
------------------------------

Each recursive call to ``fact(n)`` pushes a new frame onto the call stack, each
holding its own ``n``. When the base case ``n <= 1`` returns ``1``, the stack
unwinds: each pending frame multiplies its ``n`` into the result as frames pop
off. Watch the stack grow four deep, then collapse.

.. code-block:: c

   /* Visualization: each recursive call pushes a new frame; base case unwinds them */
   #include <stdio.h>
   int fact(int n) {
       if (n <= 1) return 1;
       return n * fact(n - 1);
   }
   int main(void) {
       printf("4! = %d\n", fact(4));
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20each%20recursive%20call%20pushes%20a%20new%20frame%3B%20base%20case%20unwinds%20them%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20fact%28int%20n%29%20%7B%0A%20%20%20%20if%20%28n%20%3C%3D%201%29%20return%201%3B%0A%20%20%20%20return%20n%20%2A%20fact%28n%20-%201%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%224%21%20%3D%20%25d%5Cn%22%2C%20fact%284%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Stack Data Structure: sp Index and val[] Array
----------------------------------------------

The RPN calculator from K&R Chapter 4 implements a stack using a global index
``sp`` into a ``double val[]`` array. ``push`` stores a value at ``val[sp]``
and advances ``sp``; ``pop`` retreats ``sp`` and returns the value. Step
through to see ``sp`` tick up and down as values are pushed and popped.

.. code-block:: c

   /* Visualization: sp index advances/retreats in val[] — the LIFO stack in action */
   #include <stdio.h>
   int sp = 0;
   double val[4];
   void push(double v) { val[sp++] = v; }
   double pop(void)    { return val[--sp]; }
   int main(void) {
       push(1.0); push(2.0); push(3.0);
       printf("pop=%.0f\n", pop()); /* 3 */
       printf("pop=%.0f\n", pop()); /* 2 */
       push(9.0);
       printf("pop=%.0f\n", pop()); /* 9 */
       printf("pop=%.0f\n", pop()); /* 1 */
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20sp%20index%20advances%2Fretreats%20in%20val%5B%5D%20%E2%80%94%20the%20LIFO%20stack%20in%20action%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5B4%5D%3B%0Avoid%20push%28double%20v%29%20%7B%20val%5Bsp%2B%2B%5D%20%3D%20v%3B%20%7D%0Adouble%20pop%28void%29%20%20%20%20%7B%20return%20val%5B--sp%5D%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20push%281.0%29%3B%20push%282.0%29%3B%20push%283.0%29%3B%0A%20%20%20%20printf%28%22pop%3D%25.0f%5Cn%22%2C%20pop%28%29%29%3B%20%2F%2A%203%20%2A%2F%0A%20%20%20%20printf%28%22pop%3D%25.0f%5Cn%22%2C%20pop%28%29%29%3B%20%2F%2A%202%20%2A%2F%0A%20%20%20%20push%289.0%29%3B%0A%20%20%20%20printf%28%22pop%3D%25.0f%5Cn%22%2C%20pop%28%29%29%3B%20%2F%2A%209%20%2A%2F%0A%20%20%20%20printf%28%22pop%3D%25.0f%5Cn%22%2C%20pop%28%29%29%3B%20%2F%2A%201%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Struct Memory Layout and Nested Structs
---------------------------------------

A struct lays its fields out in memory **consecutively** (with possible padding
for alignment). Nested structs are embedded inline — no extra indirection. The
``rect`` containing two ``point`` structs occupies exactly
``2 * sizeof(point)`` bytes. Python Tutor shows the nested boxes side by side.

.. code-block:: c

   /* Visualization: struct fields at consecutive addresses; nested structs compose */
   #include <stdio.h>
   struct point { int x; int y; };
   struct rect  { struct point ul; struct point lr; };
   int main(void) {
       struct rect r = {{1, 2}, {5, 6}};
       printf("ul=(%d,%d)  lr=(%d,%d)\n", r.ul.x, r.ul.y, r.lr.x, r.lr.y);
       printf("sizeof(point)=%zu  sizeof(rect)=%zu\n",
              sizeof(struct point), sizeof(struct rect));
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20struct%20fields%20at%20consecutive%20addresses%3B%20nested%20structs%20compose%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Astruct%20point%20%7B%20int%20x%3B%20int%20y%3B%20%7D%3B%0Astruct%20rect%20%20%7B%20struct%20point%20ul%3B%20struct%20point%20lr%3B%20%7D%3B%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20rect%20r%20%3D%20%7B%7B1%2C%202%7D%2C%20%7B5%2C%206%7D%7D%3B%0A%20%20%20%20printf%28%22ul%3D%28%25d%2C%25d%29%20%20lr%3D%28%25d%2C%25d%29%5Cn%22%2C%20r.ul.x%2C%20r.ul.y%2C%20r.lr.x%2C%20r.lr.y%29%3B%0A%20%20%20%20printf%28%22sizeof%28point%29%3D%25zu%20%20sizeof%28rect%29%3D%25zu%5Cn%22%2C%0A%20%20%20%20%20%20%20%20%20%20%20sizeof%28struct%20point%29%2C%20sizeof%28struct%20rect%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Union: Multiple Interpretations of the Same Bytes
-------------------------------------------------

A union's fields all start at the **same address** — the union is exactly as
large as its largest member. Writing the ``int`` field and reading back through
the ``char bytes[]`` field shows you the raw byte representation of the integer
in memory (endian-order). Python Tutor shows one memory box shared by both
fields.

.. code-block:: c

   /* Visualization: union fields share the same bytes — write int, read as chars */
   #include <stdio.h>
   union u { int i; char bytes[4]; };
   int main(void) {
       union u x;
       x.i = 0x41424344;   /* stores 'D','C','B','A' in bytes (little-endian) */
       printf("as int:  0x%08X\n", (unsigned)x.i);
       int j;
       for (j = 0; j < 4; j++)
           printf("bytes[%d] = 0x%02X  '%c'\n", j,
                  (unsigned char)x.bytes[j], x.bytes[j]);
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20union%20fields%20share%20the%20same%20bytes%20%E2%80%94%20write%20int%2C%20read%20as%20chars%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aunion%20u%20%7B%20int%20i%3B%20char%20bytes%5B4%5D%3B%20%7D%3B%0Aint%20main%28void%29%20%7B%0A%20%20%20%20union%20u%20x%3B%0A%20%20%20%20x.i%20%3D%200x41424344%3B%20%20%20%2F%2A%20stores%20%27D%27%2C%27C%27%2C%27B%27%2C%27A%27%20in%20bytes%20%28little-endian%29%20%2A%2F%0A%20%20%20%20printf%28%22as%20int%3A%20%200x%2508X%5Cn%22%2C%20%28unsigned%29x.i%29%3B%0A%20%20%20%20int%20j%3B%0A%20%20%20%20for%20%28j%20%3D%200%3B%20j%20%3C%204%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20printf%28%22bytes%5B%25d%5D%20%3D%200x%2502X%20%20%27%25c%27%5Cn%22%2C%20j%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28unsigned%20char%29x.bytes%5Bj%5D%2C%20x.bytes%5Bj%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Static Variable: Persistent Local State
---------------------------------------

A ``static`` local variable is stored in the **global (static) memory region**,
not on the stack. It is initialized once and retains its value across calls.
Python Tutor shows ``n`` living in the global frame while ``counter``'s stack
frame comes and goes with each call.

.. code-block:: c

   /* Visualization: static n lives in global frame across calls; local would reset */
   #include <stdio.h>
   int counter(void) {
       static int n = 0;  /* persists between calls */
       n++;
       return n;
   }
   int main(void) {
       printf("%d\n", counter()); /* 1 */
       printf("%d\n", counter()); /* 2 */
       printf("%d\n", counter()); /* 3 */
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20static%20n%20lives%20in%20global%20frame%20across%20calls%3B%20local%20would%20reset%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20counter%28void%29%20%7B%0A%20%20%20%20static%20int%20n%20%3D%200%3B%20%20%2F%2A%20persists%20between%20calls%20%2A%2F%0A%20%20%20%20n%2B%2B%3B%0A%20%20%20%20return%20n%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20counter%28%29%29%3B%20%2F%2A%201%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20counter%28%29%29%3B%20%2F%2A%202%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20counter%28%29%29%3B%20%2F%2A%203%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>


Pointer to Pointer: Two Levels of Indirection
---------------------------------------------

``int **pp`` holds the address of a pointer, which in turn holds the address of
an ``int``. Python Tutor draws two arrows: ``pp → p → x``. Dereferencing twice
with ``**pp`` follows both arrows to reach ``x``. This pattern is the foundation
of pointer arrays, ``argv``, and functions that modify a pointer.

.. code-block:: c

   /* Visualization: pp -> p -> x; two levels of indirection, two arrows to follow */
   #include <stdio.h>
   int main(void) {
       int x = 5;
       int *p   = &x;   /* p  points to x */
       int **pp = &p;   /* pp points to p */
       printf("x=%d  *p=%d  **pp=%d\n", x, *p, **pp);
       **pp = 99;       /* write through both levels of indirection */
       printf("x=%d\n", x);
       return 0;
   }


.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Visualization%3A%20pp%20-%3E%20p%20-%3E%20x%3B%20two%20levels%20of%20indirection%2C%20two%20arrows%20to%20follow%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20x%20%3D%205%3B%0A%20%20%20%20int%20%2Ap%20%20%20%3D%20%26x%3B%20%20%20%2F%2A%20p%20%20points%20to%20x%20%2A%2F%0A%20%20%20%20int%20%2A%2App%20%3D%20%26p%3B%20%20%20%2F%2A%20pp%20points%20to%20p%20%2A%2F%0A%20%20%20%20printf%28%22x%3D%25d%20%20%2Ap%3D%25d%20%20%2A%2App%3D%25d%5Cn%22%2C%20x%2C%20%2Ap%2C%20%2A%2App%29%3B%0A%20%20%20%20%2A%2App%20%3D%2099%3B%20%20%20%20%20%20%20%2F%2A%20write%20through%20both%20levels%20of%20indirection%20%2A%2F%0A%20%20%20%20printf%28%22x%3D%25d%5Cn%22%2C%20x%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>

