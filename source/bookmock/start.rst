Unit Testing
============

Testing Basics
--------------

Writing unit tests is really easy in python. The real basics of testing is, we know what our function is supposed to
do and then we ascertain via code that function does what we expect.

Let's take the famous fibonacci series as an example. If I use the paper and pencil version, I will be writing
fibonacci series like this.

::

    0   1   2   3   5   8   13  21  34  55  ...


I wrote the first two numbers, 0 and 1, and then derived the next number by adding previous two numbers.

::

    0       # stated
    1       # stated
    2       # 1 + 0
    3       # 2 + 1
    5       # 3 + 2
    8       # 5 + 3
    13      # 8 + 5
    21      # 13 + 8
    34      # 21 + 13
    55      # 34 + 21


And then I got tired, but I have derived the logic of this function and I can write a program for this function.
Then I can write another program, that will check if the output produced by this program is correct. By manually
working on this program, I know correct answer to expect from 0 to 34.

First let me write a program.

.. literalinclude:: start/program.py
   :language: python
   :linenos:


This imitates the human behavior of the fibonacci series as close as possible. This is an interactive program, so
when the program is run, it asks the user for a number and it gives the nth fibonacci number.

::

    $ python3.5 program.py
    Hi Friend, give me a number, n, and I will give nth Fibnacci number. 422
    6971065820139782390806954219541689244276624212074373456653600330331675492690805039973161


How do we know that output is correct? Well, we wrote the programs using the first principles of fibonacci and we
also wrote tests for the inputs we derived manually.

Here is our test program. The important thing to note is our program is structured in such a way that the tests need not
emulate a user, each time being prompted for a number and then given a number. The test program can test the curx of the
program, the function that calculates the nth fibonacci number.

.. literalinclude:: start/tests/test_program.py
   :language: python
   :linenos:


As you can verify, we encoded our complete understanding of the fibonacci program in this test. By running this tests,
we can  ascertain that our logic of our program is correct.

There are multiple ways to run this test program. The simplest is simply running the program from the test module.

::

    $ python -m tests.test_program -v
    test_fibonacci (__main__.TestProgram) ... ok

    ----------------------------------------------------------------------
    Ran 1 test in 0.000s

    OK

Python unittest module, also provides a discover functionality that you can use to discover the unittests in the
package and run them.

::


    $ python -m unittest discover -v
    test_fibonacci (tests.test_program.TestProgram) ... ok

    ----------------------------------------------------------------------
    Ran 1 test in 0.000s

    OK

In addition, there are libraries that does the discovery of unittests and exercise the tests. One such package is
called nose tests.


Here, I install nose on my system and then run nose test.

::

    $ pip install nose
    Collecting nose
      Downloading nose-1.3.7-py3-none-any.whl (154kB)
        100% |████████████████████████████████| 163kB 2.8MB/s
    Installing collected packages: nose
    Successfully installed nose-1.3.7


Running note tests on my package.

::

    $ nosetests -v
    test_fibonacci (tests.test_program.TestProgram) ... ok

    ----------------------------------------------------------------------
    Ran 1 test in 0.004s

    OK



There is another testing tool called pytest, does the discovery and running of the tests.

::

    $ pip install pytest
    Collecting pytest
      Downloading pytest-2.9.2-py2.py3-none-any.whl (162kB)
        100% |████████████████████████████████| 163kB 2.0MB/s
    Collecting py>=1.4.29 (from pytest)
      Downloading py-1.4.31-py2.py3-none-any.whl (81kB)
        100% |████████████████████████████████| 92kB 3.3MB/s
    Installing collected packages: py, pytest

pytest produces colorized fancy output on test execution.

::

    $ python -m pytest -v
    ==================================================================== test session starts =====================================================================
    platform darwin -- Python 3.5.1, pytest-2.9.2, py-1.4.31, pluggy-0.3.1 -- /Users/senthilkumaran/.pyenv/versions/3.5.1/bin/python
    cachedir: .cache
    rootdir: /Users/senthilkumaran/projects/learntosolveit/source/bookmock/start, inifile:
    collected 1 items

    tests/test_program.py::TestProgram::test_fibonacci PASSED

    ================================================================== 1 passed in 0.03 seconds ==================================================================



You might wonder why are there so many testing tools?

The reason is same as why there are different types of houses, when any house satisfies the purpose of living.

Some tools have more features than others, some are designed to be run on large program, produce output in a format
that could be understood by a report parsing frameworks. Some frameworks support parallel execution of tests etc.

There are good reasons, and a little research will help you pick the suitable one for your project.

All these give good confidence in our program that we wrote a correct one. If, we wrote a program that was incorrect,
all these frameworks will inform us that a bug has surfaced in our code. Our expected values are not the same as what
the program gives as the output.

.. literalinclude:: start/invalid_program.py
   :language: python
   :emphasize-lines: 13
   :linenos:

Failure from unittest.

::

    $ python -m tests.test_program -v
    test_fibonacci (__main__.TestProgram) ... FAIL

    ======================================================================
    FAIL: test_fibonacci (__main__.TestProgram)
    ----------------------------------------------------------------------
    Traceback (most recent call last):
      File "/Users/senthilkumaran/projects/learntosolveit/source/bookmock/start/tests/test_program.py", line 11, in test_fibonacci
        self.assertEqual(2, fibonacci(3))
    AssertionError: 2 != 1

    ----------------------------------------------------------------------
    Ran 1 test in 0.001s

    FAILED (failures=1)


unittest discovery throws the same error too.

::

    $ python -m unittest discover -v
    test_fibonacci (tests.test_program.TestProgram) ... FAIL

    ======================================================================
    FAIL: test_fibonacci (tests.test_program.TestProgram)
    ----------------------------------------------------------------------
    Traceback (most recent call last):
      File "/Users/senthilkumaran/projects/learntosolveit/source/bookmock/start/tests/test_program.py", line 11, in test_fibonacci
        self.assertEqual(2, fibonacci(3))
    AssertionError: 2 != 1

    ----------------------------------------------------------------------
    Ran 1 test in 0.001s

    FAILED (failures=1)


And so does our nose tests.

::

    $ nosetests -v
    test_fibonacci (tests.test_program.TestProgram) ... FAIL

    ======================================================================
    FAIL: test_fibonacci (tests.test_program.TestProgram)
    ----------------------------------------------------------------------
    Traceback (most recent call last):
      File "/Users/senthilkumaran/projects/learntosolveit/source/bookmock/start/tests/test_program.py", line 11, in test_fibonacci
        self.assertEqual(2, fibonacci(3))
    AssertionError: 2 != 1

    ----------------------------------------------------------------------
    Ran 1 test in 0.004s

    FAILED (failures=1)


The pytest module gives more details on the failure and gives the details on the failure and the context.

::

    $ python -m pytest -v
    ==================================================================== test session starts =====================================================================
    platform darwin -- Python 3.5.1, pytest-2.9.2, py-1.4.31, pluggy-0.3.1 -- /Users/senthilkumaran/.pyenv/versions/3.5.1/bin/python
    cachedir: .cache
    rootdir: /Users/senthilkumaran/projects/learntosolveit/source/bookmock/start, inifile:
    collected 1 items

    tests/test_program.py::TestProgram::test_fibonacci FAILED

    ========================================================================== FAILURES ==========================================================================
    _________________________________________________________________ TestProgram.test_fibonacci _________________________________________________________________

    self = <tests.test_program.TestProgram testMethod=test_fibonacci>

        def test_fibonacci(self):
            self.assertEqual(0, fibonacci(1))
            self.assertEqual(1, fibonacci(2))
    >       self.assertEqual(2, fibonacci(3))
    E       AssertionError: 2 != 1

    tests/test_program.py:11: AssertionError
    ================================================================== 1 failed in 0.03 seconds ==================================================================
