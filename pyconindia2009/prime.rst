=======================
Numbers. Prime Numbers.
=======================

Let us start with a simple algorithm and look at the python code.

Prime Numbers have exactly two factors 1 and itself.
====================================================

Eratosthenes invented a sieve that would drain out composite numbers and give the primes.
=========================================================================================

.. literalinclude::      py31/eratosthenes.py

This is an interesting algorithm. It is maintaining a dictionary of the nearest composite numbers and the smallest prime.
=========================================================================================================================

You may want to print out the variables at diffent point to see it (If you dont get it in the first shot) 
=========================================================================================================
