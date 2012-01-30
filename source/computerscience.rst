======================
Computer Science Notes
======================

.. warning::
        Rough Notes

Physical Science Monologues 
===========================

This is the list of twelve best physical sciences monologue of the 20th century
according to American Scientist.

Found this at TAOCP_ page.

* Dirac on Quantum 
* Einstein on relativity
* Mandelbrot on fractals
* Pauling on the chemical bonds
* Russell and whitehead on Foundations of Mathematics
* von Neumann and Morgenstein on Game Theory
* Wiener on Cybernetics
* Woodward and Hoffman on Orbital Symmetry
* Feynman on Quantum Electrodynamics
* Smith on Search for Structure
* Einstein's collected papers.
* Knuth's The Art of Computer Programming

.. _TAOCP: http://www-cs-faculty.stanford.edu/%7Euno/taocp.html

Unix Operating System Documents
===============================

http://docs.freebsd.org/44doc/

Assignments
===========

http://nifty.stanford.edu/

Assignments help in learning new stuff. This page provides some.

Algorithms
==========

http://ace.delos.com/usacogate

Theory of Computation
=====================

* A language is called a regular language if some finite automaton recognizes it.
* What is finite automata?

A finite automata is a 5-tuple (Q, E, ∂, q, F), where:

1) Q is a finite set called the states.
2) E is a finite set called the alphabet
3) ∂: is  Q x E -> Q is the transition functions.
4) q belongs to Q is the start state.
5) F belongs to Q is the set of accept states.

* Regular Operations are union, concatenation and star.

* Operator is a unary operator; it attaches any number of strings in A together
  to get a string in the new language.

* Generally speaking a collection of objects is closed under some operation, if
  applying the operation to the members of the collection still returns an
  object in that collection.

P vs NP problem
===============

Suppose that you are organizing housing accommodations for a group of four
hundred university students. Space is limited and only one hundred of the
students will receive places in the dormitory. To complicate matters, the Dean
has provided you with a list of pairs of incompatible students, and requested
that no pair from this list appear in your final choice. This is an example of
what computer scientists call an NP-problem, since it is easy to check if a
given choice of one hundred students proposed by a coworker is satisfactory
(i.e., no pair taken from your coworker's list also appears on the list from
the Dean's office), however the task of generating such a list from scratch
seems to be so hard as to be completely impractical. Indeed, the total number
of ways of choosing one hundred students from the four hundred applicants is
greater than the number of atoms in the known universe! Thus no future
civilization could ever hope to build a supercomputer capable of solving the
problem by brute force; that is, by checking every possible combination of 100
students. However, this apparent difficulty may only reflect the lack of
ingenuity of your programmer. In fact, one of the outstanding problems in
computer science is determining whether questions exist whose answer can be
quickly checked, but which require an impossibly long time to solve by any
direct procedure. Problems like the one listed above certainly seem to be of
this kind, but so far no one has managed to prove that any of them really are
so hard as they appear, i.e., that there really is no feasible way to generate
an answer with the help of a computer. Stephen Cook and Leonid Levin formulated
the P (i.e., easy to find) versus NP (i.e., easy to check) problem
independently in 1971. 

A problem is of type P, if it can be solved using an algorithm whose running
time grows no faster than some fixed power of number of symbols required to
specify the initial data.

Theory of Computation 1.1 
=========================

1.1 Write formal descriptions of the following sets.
----------------------------------------------------

a. The set containing the numbers 1, 10 and 100.

A = {1,10,100}

b. The set containing all integers that are greater than 5.

SET = { n | n ∈ Z and n > 5 }

c. The set containing all natural numbers that are less than 5.

SET = { n | n ∈ N and n < 5 }

d. The set containing the string aba.

SET = {aba}

e. The set containing an empty string.

SET = { ∊ }

f. The set containing nothing at all

SET = ∅

1.2 Let A be the set {x, y, z} and B be the set {x, y}
------------------------------------------------------

a. Is A a subset of B? FALSE.

b. Is B a subset of A? TRUE.

c. What is A ∪ B?  Answer: A

d. What is A ∩ B?  Answer: B

e. What is A x B?  Answer: {(x,x), (x,y), (y,x), (y, y), (z, x), (z, y)}

f. What is the power set of B?

Answer: { ∅, {x},{y},{x,y}}

1.3 If A has a elements and B has b elements, how many elements are in AxB? 
---------------------------------------------------------------------------

A x B has a*b elements. A x B stands for cartesian product which is formed as set
of tuples taking each element from each set.

So for 2 x 2 set.
{a,b} x {c, d} = { (a,c), (a,d), (b,c), (b,d)} Thus there are 4 elements.


1.4 Description
---------------

1.4 Examine the following formal descriptions of sets so that you understand
which members they contain . Write a short informal English description for
each set. 

a. { 1, 3, 5, 7 ...}

It is the set of all odd natural numbers.

b. { ..., -4, -2, 0, 2, 4 ...}

It is the set of all even real numbers.

c. {n | n = 2m for m in N}

It is set of even natural numbers.

d. { n | n = 2m for m in N, and n = 3k for some k in N}

It is set of natural numbers which are divisible by both 2 and 3.

e. { w | w is a string of 0s and 1s and w is equals the reverse of w}

It is set of binary numbers which are bi-directional (that is read the same from left to right and also from right to left).

f. { n | n is an integer and n = n + 1}

It is set of all integers.


1.5 If C is set with c elements, how many elements are in the power set of C? Explain your answer.
--------------------------------------------------------------------------------------------------

{x, y}  = { ∅, {x}, {y}, {x,y}}

{x, y, z} =  { ∅, {x} , {y}, {z}, {x, y} , {y, z}, {x, z}, {x, y, z} }

{a, b, c, d} = { ∅, {a}, {b}, {c}, {d}, {a,b}, {a,c}, {a,d}, {b, c}, {b, d}, {c, d}, {a,b,c}, {a,b,d}, {c,a,d}, {d,a,b}, {a,b,c,d}}

Answer: cC0 + cC1 + cC2 + cC3 + ... + cCc


Take c = 4
Answer = 4C0 + 4C1 + 4C2 + 4C3 + 4C4 = 16

Actually it is 2^n^. I have to find the proof for this.

1.6 Transistion Functions
-------------------------

Let X be the set{1,2,3,4,5} and Y be the set {6,7,8,9,10}. The unary function
f: X -> Y  and the binary function g: X x Y -> Y are described in the following
tables.

::

        ||*n*|| f(n)||
        ||1||  6||
        ||2||  7||
        ||3||  6||
        ||4||  7||
        ||5||  6||

        ||*g*||6||  7||  8||  9||  10||
        ||1||10|| 10|| 10|| 10|| 10||
        ||2||7||  8||  9||  10||  6||
        ||3||7||  7||  8||   8||  9||
        ||4||9||  8||  7||  6||  10||
        ||5||6||  6||  6||  6||   6||

a. What is the value of f(2) 

Ans: 7

b. What is the range and domain of f

range = {1,2,3,4,5} and domain = {6,7}

c. What is the value of g(2, 10)?

Ans: 6

d. What are the domain and range of g?

domain: {(1,6),(1,7),(1,8),(1,9),(1,10) .... (5,10)}
range: {6,7,8,9,10}

e. What is the value of g(4,f(4))?

Ans: 8

1.7 For each part, give a relation that satisfies the condition. 
----------------------------------------------------------------

a. Reflexive and Symmetric but not transitive.

Ans:  (a+b) ^ 2

b. Reflexive and transitive but not symmetric.

Ans:  / operator?

c. Symmetric and Transitive but not relexive.

Ans: multiplication by -1.

1.8. Graph 
----------

Ans: Drawing in the Notebook

Degree of 1 is 3.
Degree of 3 is 2.
Path from 3 to 4 is 3-2-4.

1.9  Formal Description of the Graph 
------------------------------------

Ans: {[1,2,3,4,5,6},{(1,4),(1,5),(1,6),(2,4),(2,5),(2,6),(3,4),(3,5),(3,6)}}

PROBLEMS 
--------

1.10 The error is dividing by (a-b) which is 0 because we assume a = b. Dividing by zero is not-defined and hence the proof is not valid.

1.11 The Induction Step is wrong. After assuming that H=K+1 are of same color instead of proving mathematically that K+n can be true, it goes about sub-classing the same set and without proceeding to prove a generality.

1.12 Every graph with 2 or more nodes contains 2 nodes that have equal degrees. 

Each edge contributes equally to 2 adjoing nodes or when there is not a edge,
the two seperate nodes have an equal lose.  Taking both the situations into
account, for a given graph with 2 or more nodes, there are 2 nodes that have
same degree.

1.13

Clique of a graph is subgraph in which every 2 nodes are connected by an edge.
Anti-Clique is the subgraph in which every 2 nodes are not connected by an
edge. This is also called as independent set.  Show that every graph with
n-nodes contains either a clique or an anti-clique with at-least 1/2log2 n
nodes.

Answer: This is Ramsey's therom. Generalized for k=2. For which the minimum number of
nodes required is 3.

* Have two sets m and n.
* Take each node in the graph and if the degree is greater than 1/2 number of
  remaining nodes add to set m else add to set n.
* Take all the nodes that are connected to m and add it set m.
* All the nodes that are not connected add to the set n.
* In this way, we have a clique in m and anti-clique or an independent set in n.

1.14

Theorem 1.25

P(t) = P*M^t - Y ( M^t - 1) / (M - 1)

P is the principal sum
I is the interest rate
Y is the monthly payment.
M is convenience term for writing M = 1 + I/12

This problem can be solved by using a calculator.

Curious
-------

There are 2^903 ways to arrange red, green strings among 43 pegs so each pair
is either connected by red string or by a green string.


Links
=====

1) Ramsey Theorem:
http://www.math.uchicago.edu/~mileti/museum/ramsey.html

In the book proof of Ramsey Theorem, it divides the nodes into connected
(forming cliques) and disconnected (forming anti-cliques), but checking if the
degree is greater than 1/2 of no. of remaining nodes, is not understood. (It is
like is having a theorem and and following a procedure in order to prove the
theorem, there is no counter intuitive example given).

Notes 
=====

* Floyd's contributions include Floyd's algorithms which efficiently finds the
  shortest paths in a graph and his work on parsing. Concept of error diffusion
  for rendering images, also called Floyd-Steinberg dithering. Program
  verification using logical assertions.

* Chomsky Normal Form. 
* Grieback Normal Form.
* Non-deterministic push down machine.
* Every CFG has an equivalent NDPM.
* Push Down Machine is a Finite State Machine with Stack.
* Finite State Machine with two stacks is equal in power with Turing machine.
* CYK ⊙(n^3) 
* Syntax Diagram, Backus Norm Form, Extended Backus Norm Form are convenient way to write Context free Grammers.

ADUni.org courses
=================

Theory of Computation 
---------------------

Video Lecture 2: Closure and Non-Determinism 
--------------------------------------------

* FSM are closed under reversal.
* Convert a Non Deterministic FSM to a Deterministics FSM, the example of every 1 followed by two zeros.
* Reversing a machine, wherein final state is the start state and arrows get reversed and start state is the new final state.
* Theory of Computation Folklore. To convert to the minimize the Deterministic FSM   
* Reverse the Machine ( This would make it Non Deterministic)
* Convert to Deterministic FSM
* Reverse the machine (Again Non Deterministic FSM)
* Covert to Deterministic FSM again. *This would be minimal machine.* I kind of
  trust Shai Simonson's word on that. :)
* The above method of minimizing involves DFA to NFA and it is exponential time complex.
* There are better methods using Polynomial Time Complexity using Dynamic Programming Strategy.
* Union of two machines using NFA.
* Intersection of two machines ( Using De Morgan's law. WOW!!!) But that is
  costly again, you can do it by working it out with pair or states as in
  cartesian product of the two machines. 
* Union means the set of accept states are either of the accept states in M1
  and M2.
* Intersection means that set of accept states are BOTH the accept state in M1
  and M2.
* Union, Intersection and Complement. Any two of the operations are enough and the third one is guaranteed.
* Complement Operations means changing 1s to 0s.
* Finding Intersection using Non Determinism is difficult, because Non
  Determinism does not mix well with OR operations, It mixes well with AND
  Operation.
* NFA ~ DFA ~ REGULAR EXPRESSIONS ~ NFA ( They form a nice group).
* Regular Grammars ~ DFA
* Trying to represent 0^n^1^n^ can be represented by FSM??
* Well, if I try it, equal number of 0s and 1s can be represented by FSM, but
  equal number of 0s followed by equal number of 1s ( this involves counting)
  cannot be represented by FSM.
* Anything that involves counting cannot be represented by FSM.
* The FSM can also be tested using Pumping Lemma, because they test a particular kind of regularity.
* Regular sets can be pumped out at Regular Intervals and are identified by pumping lemma. 
* Thus Pumping lemmas are yet another test for FSM.. 

ACM Meeting
===========

* Assertion Checking Problem - It is not solvable.
* YOGI reaches the close points by Static Verification.
* Basic block profiling, Edge Profiling and Tracing.
* Acyclic, Intra Procedure Path finding.
* http://research.microsoft.com/~tball Ball Laurus Algorithm - Linear time complexity.
* Preferential Path profiling.
* Holmes - Automated Root Cause Analysis.
* CNF SAT - Area for Research
* www.satcompetition.org
* QBF - Valid or Not Valid - Area for Research - Quantified Boolean Formula Satisfiablity.
* www.qbflib.org  
* Complexity Analysis of Concurrent Data Structures - Area for research again.
* When asked about the advice for pursing a PhD, he suggested the path of MS and PhD.
* I could also sense or felt, that if I want something, I should know how to get it. 

Pumping Lemma
-------------

* How to minimize the finite state machine in O(nlgn) times. Aho, Ullman Paper.
  Fun programming problem.
* Pumping Lemma - to prove that a set is not acceptable by the FSM.
* Regular Set -> ( Implies) Pumping property; ~ Pumping Property (Implies) -> ~
  Regular Set.
* If L is a regular set, it has a string long enough that is longer than the
  number states in the set, then it has a symbol that loops, then looping that
  symbol results in the string in the same set (recognizable by the language).
* The four quantifiers represent the pumping property.
* How to show that it is not true? 
* If you push not sign through quantifiers, it changes universal to existential
  and vice versa.
* Not of pumping property. For any n, there exists z in L such that ``|z|`` >=
  n, there exists v,w,x such that z=vwx and ``|vw|`` <= n and ``|w|`` >= 1 and
  there exists i >0 vw^i^x is not in L.
* Converse of Point 3 is not true. A set having pumping property does not mean
  that the set is a regular set. It is not a iff property. 
* A set of Palindromes, dont satisfy the pumping property. 
* Palindrome - Latin for running backwards.
* In the pumping lemma proof for palindrome, for sets = K, chosing 0^K^10^K^
  forces the opponent to choose the looping in 0, because of the property that
  ``|vw|`` <= K. :) Palindromes are not a regular set.
* While a bad choice of z = 0^K/2^1^K/2^ would make the loop to be in 1 and it
  would result in a palindromes. 
* Palindromes cannot be described by regular expressions.
* 0^k\^2\^^ is not a regular set, because k can be 0.
* 0^k^ k = composite. Pick up z=0^2n^. z = vwx. It has a pumping property but
  it is not regular.
* 0^p^ p = prime is not regular.  These are complements of one another.
* That is the idea of closure.
* Diagnolization - Have you known it yet?
* Can a FSM recognize one of its own kind? It is not regular.
* Turing machines can recognize FSMs. Turing machines can recognize their own
  kind, but cannot identify properties of their own kind.
* ->RE->DFM->NDFM  ( Linear Grammer) - Grammer way of looking at set.
* Productions of Grammer to generate some strings.  Using the productions is
  called derivations and get a string.
* Linear Grammers. Single Capital Letter on the LHS, the RHS consists of a
  small letter(terminal) and a capital letter ( non terminal). The terminal
  comes in the left, it is a left Linear Grammar.
* Context Free Grammer - A Single Non Terminal Symbol on the Left and Right
  side can be anything. Linear Grammer is a subset of Context Free Grammer. 
* Left linear grammer and right linear grammer are the same. One can be
  converted to another.
* Grammers by their nature are non-deterministic.

Big O Notation
==============

* Big O denotes a limiting behavior of function when the argument tends towards
  a particular value or infinity, usually in terms of a simpler function.
* Big O notation allows its users to simplify functions in order to concentrate
  on their growth rate. Different functions with same growth rate may be
  represented with the same big O notation.
* Description of a function in terms of big O notation usually only provides an
  upper bound on the growth rate of the function; associated with big O are
  several related symbols o, Ω, ω, and Θ to describe other kinds of bounds on
  the asymptotic growth rate.
* Formal Description:
   f(x) = O(g(x)) as x -> ∞ 
* T(n)  ∊ O(n^2^) - That is T(n) has n^2^ time complexity.
* O(n^c^) and O(c^n^) are very different. The latter grows much, much faster,
  no matter how big the constant c is (as long as it is greater than one).
* Changing units may or may not affect the order of the resulting algorithm.
  Changing units is equivalent to multiplying the appropriate variable by a
  constant wherever it appears. For example, if an algorithm runs in the order
  of n^2^, replacing n by cn means the algorithm runs in the order of c^2^n^2^,
  and the big O notation ignores the constant c^2^. This can be written as
  c^2^n^2^ ∊ O(n^2^) . If, however, an algorithm runs in the order of 2^n^,
  replacing n with cn gives 2^cn^ = (2^c^)^n^. This is not equivalent to 2^n^
  in general.

What is Amortized time?

What is inverse Akerman function or even straight Akerman function?

disjoint set?
Priority Queue?
Polylogarithmic? AKS Primality Test?
What is KD-Tree?
Lineararithmic?
Fast Fourier Transform?
Shortest Path on a weighted Digraph with the Floyd-Warshall Algorithm.

Computer Architecture
---------------------

Make a list of 10 general-purpose processors including the details like clock speed, word size and manufacturer.

::

        ||*uP*||Clock Speed || Word Size || Manufacturer||
        ||Intel Core i7 EE || 3.33 `GHz` || 64 bit(bus-size) || Intel||
        ||AMD K10 || 3.1 `GHz` || 64 bit || AMD ||
        ||ARM 11 ||528 `MHz` ||32 bit ||ARM||
        ||Cyrix 5x86 || 133 `MHz` || 32 bit || Cyrix||
        ||DEC 21-40535-04||275 `MHz` ||64 bit ||DEC ||
        ||IDT Win Chip `W2A` ||300 `MHz` ||32 bit ||IDT||
        ||Motorola 68060 ||75 Mega Hz ||32 bit ||Motorola||
        ||NS 320 16 N -10 ||10 Mega Hz ||32 bit ||National Semiconductor||
        ||NEC D70216 L || 10 Mega Hz || 16 bit || NEC ||
        ||Nex Gen Nx 586 || 100 Mega Hz || 32 bit || Nex Gen||
        ||C7 D || 2 Giga Hz || 32 bit || VIA||
        ||Crusoe TM 5800 || 933 Mega Hz || 64 bit || Transmeta||


The number of bits a CPU can process at once; word size is usually the same as
the width of the CPU's external data bus, but sometimes is smaller.
Justify that CPU in personal computer is a general purpose processor.

* It is not just for sine and cosine but can do a large number of small scale mathematical calculations.
* It can fairly handle the graphic requirements.
* It can do multi-tasking to satisfy the users requirements.

In a mathematical sense, only three operations are needed to compute any
computable function: add one, subtract one and branch if a value is non-zero.

Minimizing Finite State Machines 
--------------------------------

* All FSM can be minimized to a unique FSM. Cool. :)
* Not true for turing machine or middle level (push down machine) programs.
* Decision algorithms about FSM are possible because of its property of minimize.
* Cave example, Dungeon and Dragons. 
* Minimising FSM
* Make it such a way if one state is distinguishable from another.
* `` NC_2_`` are the number of pair of states for N states.
* Draw a Matrix and X each pair of states which are distinguishable.
* Proceed on 0,1 and on each pair and note the dependency and mark them for backtracking.
* The amount of backtracking, determines the size of the string that distinguishes it.
* Based on the number of X, which are number of states which are
  indistinguishable from one-another, we can collapse them to one state.
* That is the basis of equivalence relation.
* In the matrix, seperate the distinguishable states into sets.  (AFDC) and (BE).
* That is kind of Non Determinisitic Machine.
* Minising FSM is commomly used, when you write the opcodes and then you want
  to minimize it implement it in the architecture.
* Dependency Graph drawing it from the Matrix.
* Any kind of search over the graph from the dependency graph will give
  depdency. the 2(nC2) = n(n-1)
* Funny way, suttle way to represent and work with the graph and transmitting
  the operation with back arrows.
* Backtracking it easy to put an X than say searching if the backtracked note
  already has an X.
* That was a reduced one for "Every string that does not have 1 in the second
  position".
* Graph Traversal vs Diagonalization method. Complexity analysis. The
  Diagonalization involves backtracking. But that the worst case of
  backtracking for going to every single state for every single value is never
  going to happen. Because in each loop we go about cancel symbols.
* Different way of doing it by a student. Do you stay in the same group (ABCD)
  and or different group (EF).
* Hopcraft and Ullman for reducing the FSM in nlogn times.
* Switch Gears:  What questions can we answer about FSM?
* Lex: Describe the FSM and given the Input string and it says whether it
  accepts or not.
* We can answer almost everything about FSM.
* Membership question.
* Are two FSM equal? Graph Isomorphism problem - Given two graphs are they
  same. (You got to relabel the graph and see if there is a set of labels that
  match. But that takes N! times)
* Start with a graph and re-label the other nodes till you get a match.
* If two FSMS are equal, if you calculate their difference A-B = 0. 
* A-B = A ⋂ ~B
* Language is infinite. Look for a cycle, and if there is a state which goes to
  Final State and if it does, then it is infinite. easier way, convert to RE.
* No 2 RE have smallest RE. To figure if two RE are same, is NP Complete.
* SET Theory and Graph Theories are coming into picture here.
* Is a Regular set A contained in Regular set B? 
* Remind of the Discrete Math. Intersection is AND, Union is OR, Complement is NOT.
* A ⊆ B means A -> B (A implies B). 
* Decidable means can be done or not?
* Only thing that can be done from next level is membership problem.
* There are not any interesting undecidable questions in FSM.
* Any non-trivial property of turing machine is undecidable.
* A Trival property of Turing machine is How many states it has?

Asymptote is a tangent to a curve at infinity. Something that is asymptotic
relates to an asymptote, which is defined as "A Line whose distance to a given
curve tends to zero."

Something asymptotic refers to a limiting behaviour based on a single variable
and a desired measure.  A common notation that removes constants is called Big
O notation, where O means "order of".  Big O denotes the upper bound, how much
the time complexity will grow. If we say that a function is O(N) then if N
doubles, the funtion's time complexity at most will double.

I don't understand this aspect:
But because the array is split in half each time, the number of steps is always
going to be equal to the base-2 logarithm of N, which is considerably less than
O(N).

http://www.eternallyconfuzzled.com/jsw_home.aspx

Big-O is not a mathematical function. It has no inverse.

The Art of Sorting 
==================

* C's qsport and C++ std::sort and std::partial_sort.
* It should be really obvious that Upper Bound of any sorting algorithm is infinite, as long as it eventually sorts the items.
* The Lowest possible bound for most sorting algorithms is Ω(N logN).
* There must be as many leaves as the permutations of the algorithm to be correct.
* It is possible to meet the safe lower bound of O(N) for sorting.
* Selection Sort is not a viable option for things that come through input an
  stream or random number generator. The array has been completely filled in
  before it is sorted.
* In the selection sort, if you swap the items (the largest vs n), then you
  displace the items of their original relative order.
* But thats not the case when you kind of shift the items one after the other,
  so it remains stable in this case, albeit taking a lot of space and time.
* Stable Selection Sort. Understand it.
* Priority Queue can be used to do a selection sort. The best known priority
  queue implmentation is done with a max_heap.
* Max Heap is a complete binary tree, wherein the children of a node cannot be larger than the parent.
* In a valid max heap, the largest item is the root of the tree.
* Heap Sort has the worst case as the same complexity as the average case.
* Array can be coverted to a heap, wherein for each index i, the child nodes are i*2 + 1 and i*2 + 2.
* The relative order of children in the Heaptree is irrelavent.( Funny, because it is binary tree)
* Insertion sort is blazingly fast on arrays that are sorted or partially sorted. That makes it a good one to use as the last part of quick sort.
* What is knuth sequence?

Recitation-1 Theory of Computation
==================================

* Programs are condensation (or compressed versions) of strings.
* KOLMOGOROV_ complexity.
* Turing Machine
* Shannon/Fischer Information.
* Entropy
* Streams - All scheme programs

.. _KOLMOGOROV: http://en.wikipedia.org/wiki/Kolmogorov_complexity 

* Locality
* Architecture.
* Cache and memory systems.
* Pre-fetching.
* Pre-Computation.

* Scheme Interpreter is just a program.
* Abstraction.
* Language allows us to define certain constructs in the realm of that language.

* Register Transfer Language ( Machine Language).
* After 1985, no machine code was directly transfered to actual hardware. There was micro-code.
* Every level of translation involves expanding amount of code and reducing efficiency.
* Lisp machines that directly implemented Lisp interpretor in hardware.
* VAX-11 (CISC) One instruction to solve polynomial equation. :)
* All scheme expression we have pre-fix notation ( op arg1 arg2).
* Tag based dispatch of data-structures. That's what interpreters do.
* Parsing in infix is difficult and prefix is easy.
* Read-Eval-Print loop for evaluating the lisp expressions.

Lecture 5 Context Free Languages 
================================

* FSM -> CFL
* CFL, Inside they are DPDM and Outside they are NDPM.
* CFL are equivalent to NDPM.
* DPDM are equivalent to LR(K) grammers.
* LR(K) grammars are subset of CFL.
* LR(K) grammers are the one most compilers are built from.
* Context Free Grammers are Grammers that have a single Capital Letter on the LHS.
* S-> 0S1 | e
* S-> 0S1 | SS | e
* If there are more than two parse trees, its bad, bad, bad.
* trees give a semantic interpretation in the programming languages.
* Grammar is AMBIGUOUS if any string has two parse different trees.
* Its undecidable to figure out if the grammer is ambigous or not.
* ``S-> S+S | S*S |0..9 is ambiguous.``
* ``S->(S+S) |(S*S) | 0..9``
* Grammers tend to challenge people more than machines do.
* Use recursive idea and find the grammar inductively.
* Semantic meaning for the non-terminal.

::

    S -> 0A | 1B | e
    A -> 1S |0AA
    B -> 0S |1BB

* Ambiguity is at AA.
* Recursive example of grammar.

::

    S-> SAB | e
    A-> 0S1 | e
    B-> 1S0 | e

* Single Tree Grammers ( But the trees may get pruned at different levels)
* This is equal number of 0s and 1s.
* We prove by induction because they are recursive.
* You cannot decide anything about the Grammer, except if that accepts Nothing! ( Turing machine can't do that too).
* There is a pumping lemma for Context Free Languages.
* 0^n^1^n^0^n^ cannot be generated by Context Free Languages.
* Give more power and make it Context Sensitive, then the above strings can be generated.
* Context Sensitive Grammers look very much like machines.
* A, B and C are non terminals that will eventually turn into 0s,1s,0s.

::

  S -> L D A B C R
  LDA -> LAAD
  ADA -> AAD
  ADB -> ABBD
  BDB -> BBD
  BDC -> BCCD
  CDC -> CCD
  DR ->  ER
  CE -> EC
  BE -> EB
  AE -> EA
  LE -> LD
  A->0
  B->1
  C->0
  R->e
  LD->e

* Context Free Languages are closed under union.
* 0^n^1^n^0^p^

::

 S -> 0S1M |e
 M -> 0M |e

 * 0^p^1^n^0^n^
 * Context Free Language are closed under concatenation.
 * Intersection the above two?   0^n^1^n^0^n^
 * Context Free Grammare are not closed under Intersection.
 * CFG Are NOT closed under Complement.

Video 6. Relationship with Compilers 
------------------------------------

* Compiling a programming language.
* Chomsky Normal Form.
* Convert the Context Free Language to Chomsky normal form.
* Motivation for Chomsky Normal Form. Every string of length n is derivable
  from (2n-1) steps.
* Try every simple production to the depth of 2n-1, if it does not success it
  fails. If 3 nodes then 3^(2n-1)^ choices exists. It is decidable, but
  exponential time algorithm.
* Chomsky Normal Form helps with Proof of Pumping Lemma for Context Free
  Languages.
* Context Free Grammars are equivalent to Non Deterministic Push Down Machine.
  This equivalence becomes easy to prove of the grammar is in Chomsky Normal
  form.
* Every CFG has an "equivalent" NPDM.
* Push Down Machine is a FSM which can push and pop symbols from a stack.
* Good Algorithm for membership in Context Free Grammar. The CYK O(n^3^)
  algorithm for membership, this is easy if the Grammar is in Chomsky Normal
  Form. But there are linear grammars for this.
*  *Connection between Compilers and Context Free Languages*

:: 

        <stmt> -> <assgn> | <ifthen> | <ifthenelse> |<beginend>
        <ifthen> -> if <expression> then <stmt>
        <ifthenelse> -> if <expression> then <stmt> else <stmt>

* Syntax Diagrams, Backnus Normal Form, Extended Backus Normal Form are different ways of writing Context Free Grammer.
* Chomsky Normal Form.

::

         A-> BC
         B -> o

* Any grammar can be turned into Chomsky Normal Form.

Video 7 - Theory of Computation
-------------------------------

* Non Deterministic Pushdown machines. 
* Uni-direction movement with a set of inputs and manipulate a stack.
* YACC simulates the actions of push down machines.
* WW^R^ recognize it with NPDM. W ∊ (0+1)^*^
* Is queue more powerful than stack? How many queues are required to simulate a stack?
* Deterministic Context Free Languages are Closed under Complement.

Recitation Video 3 - Theory of Computation 
------------------------------------------

* Lex and Yacc usage.

Video 8 - Theory of Computation
-------------------------------

* NDPM is different from DPM
* CFG => NPDM
* LR(K) Grammars are equivalent to DPDM.

Discrete Maths 
--------------

* The course is about Counting. Clever about Couting, if the are same. Tools to find this is not easy to count.
* Fermat's little theorem
* Congruence.
* √2 is irrational - Aristotle's problem.
* Infite number of prime numbers. Euclid's Elements.
* Halting Problem. What is that?
* Bowling number problem, it is Triangular numbers, pentagonal numbers, hexagonal numbers.
* Tn = 1 + 2n + ... + n-1
* Cutting a pie

::

  1 - 2
  2 - 4
  3 - 7 
  4 - 11
  n - Tn + 1 ?

* Pn = Pn-1 + n, using induction hypothesis.
* Logic is used in Automated Theorem Proving.
* The discussion about logic gates and the truth table is A-> B.

::

  R ⊕ W = (R+W) -(RW)  
  R ⊕ W = (-RW) + (-WR)

* Puzzle: Swap A and B without using a temporary variable.
* R->W <=> -R + W
* --R <=> R
* (R+W)S = RS + WS
* RW+S = (R+S)(W+S) ( Its ugly), so we use the (R⋂W)⋃S = R⋃S ⋂ W⋃S
* De Morgan's Laws

::

  -(A⋂B) = -A ⋃ -B
  -(A⋃B) = -A ⋂ -B


* Notation is important in mathematics. They let you think properly.
* Prove the Ex-OR logic.

::

  (R+W)-(RW)
  (R -(RW) ) + (W  -(RW))
  (R (-R + -W)) + (W (-R + -W))
  (R-R) + R-W + W-R + W-W
  R-W + W-R

Graph Theory
------------

* In graph theory, an independent set or stable set is a set of vertices in a
  graph no two of which are adjacent. Exciting!
* Maximum independent set problem is a NP-Complete Problem.
* Disjoint set, two sets A and B are disjoint if they have no element in
  common.
* A Bipartite graph does not contain any odd length cycles.
 
I discovered later that I wasn’t even a very good C programmer, hiding my
ignorance of structures, _malloc( ) and free( ), setjmp( ) and longjmp( ),_ and
other “sophisticated” concepts, scuttling away in shame when the subjects came
up in conversation instead of reaching out for new knowledge.

* The concept of implementation hiding cannot be overemphasized.

Maximum Flow 
------------

* What does no full forward edges or empty backward edges mean?
* This implies that the maximum flow is less or equal to every cut of the network.


Problem Set 1 - Theory of Computation
-------------------------------------

* Unable to figure out Questions 3) b and c. What are figures 1.12b and 1.12c.
* Discrete Maths proofs - Read the Solution and Don't understand it completely. But I can prove in my own way.
* Understand the Prefix(L) given in the problems further.
* Converting FA to Regex. 

Video Lecture 8 
---------------

* 0^n^1^n^0^n^ is not a Context Free Language.
* All the Programming Languages that we write are Context Free Languages.
* Context Free Languages are closed under Intersection with Regular Set.

Algorithms Video 1
------------------

* Greedy Approach for minimal spanning tree.
* Map Coloring Algorithm.
* Planar Graph (No Crossing Edges) can be done with 4 colors.
* NP Complete Problem ( No one has an idea to do it in the polynomial time.
* 2 colors. Polynomial Problem called Bipartite Problem (can be tried with DFS and BFS).
* Recursion. Thinking about the problem top-down, breaking it into sub-pieces, divide and conquer.
* Dynamic Programming. Bottom Up. Opposite of Recursion. Solve Subproblems in polynomial time.
* Greedy Strategy. Hope that it works locally and hope that it works globally. Sometimes it works with polynomial time and sometimes it does not.
*  Recursions goes with Recurrance equations, Proofs by Induction, Stacks.
* Dynamic Programming goes with  Queues and tables.
* Greedy Strategy has a mathematical theory behind. Matroid Theory. Minimum Spanning Tree can be done with greedy strategy. Scheduling Problem works with Greedy Strategy too.
* Shannon Switching Game.
* Claude Shannon described how a chess playing program should work.
* Pspace complete (Buzzword. Even worse than NP Complete. HEX game)
* Applications of Algorithms
* Sorting / Searching.
* Graph Algorithms
* Shortest Path Problem. Basic problem and polynomial time complete.
* TSP seems similar but it is NP Complete.
* Hamiltonian Circuit Problem - Hard
* Euler Circuit Problem - Easy.
* Max Flow and Min Cut problem.
* Marriage Problem. Polynomial time solvable and Bi-partite solving. Related to Max flow Min cut problem.
* Three Dimentional Matching is hyper-graph problem. (Martian Marriage Problem).
* NP Complete Problem for finding values for variables to make the CNF Circuit solve.
* NP Complete Problems - Approximation Probablitics Problem.
* Organized Scientific Discipline related to Computers.
* Interested in 'Why' questions and 'How' questions.
* Worst Case Complexity.
* Average Case Complexity.
* Amortized Complexity.
* Winner of the tournament n + logn -2 times.

Sorting Algorithms - Video 2
----------------------------
* Find out about triangular numbers.

Sorting Algorithms - Video 3
----------------------------

* Quick Sort.

Searching Algorithm - Video 4
-----------------------------

* Data Strutures.
* Heaps, Graphs,
* AVL Trees or Red-Black Trees.
* How do you get the n'th biggest number.

Algorithms Video 5
------------------

* Counting sort.
* Delete Nodes in Binary Tree.
* Insert Nodes in the Red Black Tree.

Programming
===========

* [http://www.htdp.org/ How to Design Programs]
* [http://savannah.nongnu.org/projects/pgubook/ Programming Ground Up]

Endian-ness 
===========

* Integer is 32 bits.
* 8 bits make a byte.
* So, integers are 4 bytes.
* Least significant byte is the one with lower order of power. Like 2^0^ to 2^7^
* Most significant byte is the one with highest order of power. Like the one with 2^n^ 
* When we are giving address to the bytes, if we start numbering from the Least Significant Byte, we say it is Little Endian.
* If we start address numbering from the Most Significant Byte, we say it is Big Endian format.
* 0x12345678 be the integer. The LSB is 0x78, If that is starting address, 0. then it is Little endian.
* If the addressing starts at 0x12, then it is in Big Endian Format.

::

          1    2    3    4  - Big Endian 
          0x00 0x00 0x00 0x01
          4    3    2    1  - Little Endian

          $ python -c "import struct;print 'little' if ord(struct.pack('L',1)[0]) else 'big'"
          little

Visual Programming Language Links
---------------------------------

* `Logo Programming Language`_

.. _`Logo Programming Language`: http://en.wikipedia.org/wiki/Logo_(programming_language)

Programming languages
---------------------

* Processing_

.. _Processing: http://www.processing.org/

Discrete Maths Video 3
----------------------

1. Demorgan's laws.
2. Set Inclusion Exclusion Theorem.
3. Cardinality of the Set.
4. Rules of Counting.
   a. Count what you are not interested in.
   b. Count double (multiple) times of what you are interested in.
5. Programming and Maths. Dont sit and think you will get an idea. Do something wrong and fix it.
6. Derangement problem (distributing lunch boxes to others). It uses Inclusion and Exclusion theorem.
7. How many numbers are divisible by 1,5,7 between 1 and 1000. This is worked out by inclusion-exclusion theorem.

Discrete Maths Video 4 
----------------------

* Diagnolization.

Discrete Maths Video 5
----------------------
* Recurrance Equation. Every next step is a function of the previous step.
* Towers of Hanoi problem and Analysis.

Data Structures and Algorithms
==============================

Problem A1: Prime Number Generation
-----------------------------------

Given a positive number N, generate all the prime numbers
from 2 to N. The primary emphasis in the solution to this
problem should be on speed. In addition, you must not consume
an inordinate amount of memory.


Problem A2: Arbitrary Precision Arithmetic
------------------------------------------

Implement an arbitrary precision arithmetic calculator.
You should implement addition, subtraction, multiplication
and division in the respective order. Try to make your
program as fast as possible and keep memory usage to the
bare minimum.


Problem A3: Sub-string Search
-----------------------------

Given two strings S1 and S2, determine whether S2 occurs
as a substring in S1 and if so, find the first occurrence
of S2 in S1. Your program should be extremely fast. Try
to come up with a linear solution to the problem.



Section B

Problem B1: Simple File-system Implementation
---------------------------------------------

Implement a simple filesystem within a normal file on the
hard disk, i.e. treat the file as a virtual disk and
implement the filesystem by manipulating records within the
file.

You are free to devise your own scheme for the file system
but it should minimally support the following operations:

   1) Create - Create a virtual hard disk on a file of the
      specified size and "format" it. Formatting would
      essentially involve initialising disk allocation
      structures and whatever else you need to do before
      you can have a valid filesystem.

   2) Open, Read, Write, Close - All the normal file operations
      to use the files.

   3) Delete, Rename - Remove unwanted files or rename existing
      files.

Do not place artificial restrictions on file names, sizes, etc.

In addition, if you can, provide support for folders (also known
as directories) which can be arbitrarily nested. Provide all
the common operations for folders.

You should implement this as a library of routines that can be
used by anyone wanting to treat a file as a filesystem.
Demonstrate the correctness of your routines by writing a demo
program that lets one manipulate files interactively.

Sites
-----

http://www.programminglogic.com/
