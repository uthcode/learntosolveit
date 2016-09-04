.. title: 09 - Case-Based Reasoning 
.. slug: 09 - Case-Based Reasoning 
.. date: 2016-01-23 06:39:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

=========================
09 - Case-Based Reasoning
=========================

01 - Preview
------------

Today we will talk about Case-Based Reasoning. In Case-based reasoning, the cognitive agent addresses new problems by
tweaking solutions to similar previously encountered problems. Case-based reasoning builds on the previous lesson on
learning recording cases. In learning recording cases, the new problem is identical to the previous problem. In case-
based reasoning, the new problem is similar to a previously encountered problem. Case-based reasoning typically has
several phases, case retrieval, case adaptation, case evaluation, and case storage. We'll also discuss certain advanced
processes of case-based reasoning which will include new methods for case retrieval.


02 - Exercise Return to Block World
-----------------------------------

To illustrate the difference between case-based reasoning and learning by recording cases, or instance-based learning,
let's revisit our micro-world of blocks. Once again, you can see all of these blocks in this micro-world. So you can see
the colors, you can see the shapes, and you could even touch them, so you have some idea about their approximate sizes.
Now let us suppose I give you a new block. Note that this new block, the size, is very different from the size of any of
the other blocks. What color do you think this block will be?


03 - Exercise Return to Block World
-----------------------------------

>> And that's the point. The point being that often, the new problem is not identical to the old problem. And when it's
not identical, then we have to do some reasoning. We can not just retrieve something from memory, and use the same
solution that was used earlier.


Case-based reasoning, the phrase case-based reasoning, has two parts to it, case-based, and reasoning. So far we have
looked at the case-based part, where we can just extract something from memory and reuse it.


Now we can look at the reasoning part. Once you have extracted something off memory, how can you reason about it, and
adapt it, but for the new problem?


04 - Recording Cases to Case-Based Reasoning
--------------------------------------------

To examine a more realistic problem, let's revisit the problem that we had in our last lesson. Once again, this is a map
of a part of Long Island, and the problem is to go from Q to the end location here. So I'll call it Q problem.


We'll retrieve from memory the D case, which takes us from this initial location to this collocation. Clearly, this D
case is potentially useful for addressing the Q problem. But it is not useful as is. The initial location of the D case
is not the same as the initial location of the Q problem. And the end location of the D case is not the same as the end
location of the Q problem.


So we can start with this D case but we need to adapt it. So, this leads us to the overall process of case-based
reasoning. The basic process of case-based reasoning consists of four steps. The first step is retrieval, and we already
and considered this when we were considering learning by recording cases. K nearest neighbor is one way of retrieving
cases from memory. Once we have retrieved a case from memory that is delivered to the current problem, we need to adapt
it. For example, in the previous problem we had the D case and the Q problem. And we needed to adapt the D case into the
Q problem.


There are many similar examples. All of us program and all of us, as computer programmers, sometimes use case-based
reasoning.


We are given a new problem to address, and we often look at the design of a program that we have come across earlier. So
there's retrieving a case and they're adapting a particular design of the old program to solve the new problem. Once we
have adapted the case to meet the requirements of the new problem, we have a candidate solution for the new problem.
With it, the candidate solution is to be evaluated. For example, in the navigation problem, when we have a solution of
the Q problem, we can evaluate it but they would actually take us to the end location. We can do a simulation, we can
walk through it. As we walk thought it, we will be able to evaluate whether the solution actually succeeds in meeting
the requirements of the problem. For the programming problem, once we have a new program that we obtain by adapting the
old program, we can actually run the program to see, whether or not it will meet the requirements of the new problem.
Let us suppose for a moment that we evaluate a candidate solution and it succeeds. Then, we could encapsulate the new
problem and the new solution into a case, and store it back into the case memory, so that case memory is constantly
increasing.


Notice that this case-based reasoning process unifies memory, reasoning, and learning. There is a case memory that
contains a large number of cases and that's how we retrieve cases that are relevant to the current problem.


We'll reason when we adapt and evaluate. And we learn when we store the new case back into the case memory.


05 - Assumptions of Case-Based Reasoning
----------------------------------------

>> That's a good example,


David. So we have at least two examples now with similar problems and have quite different solutions. Nevertheless, this
assumption is valid most of the time. Most of the time, two problems that are quite similar will end up having two
solutions that are quite similar as well.


06 - Case Adaptation
--------------------

>> That's a good point David. In fact in the design community there is a old cliché, which says that all designers
redesign. Designer is fundamentally is evolutionary. We take old designs and we evolve them slightly. And that's how we
get a new design. And the same thing is happening in case based reasoning here.


It is saying that, often this particular solutions that we come up with, are revolutionary in the nature, in the sense
that, they are small tweaks over previous solutions. So, the next question becomes, how can we adapt an old case to meet
the requirements of a new problem? There are potentially several ways of doing it. We will discuss three important ways,
perhaps the three most common ways of adapting a case. They are called the model based method, the recursive case based
method, and the rule based method.


07 - Case Adaptation by Model of the World
------------------------------------------

>> Good example, David. Here is another one. This one is from design. When we design various kind of products, let's
suppose a VLS high circuit, for example, then we not only know something about the configuration of the elements and
their design, we also have a model of how that particular configuration is supposed to work. In fact, it might amuse you
David, that about 25 years back in the 80s, when I wrote my PhD dissertation, it was one of the first PhD dissertations
that integrated model based spacing and case based spacing. That was exactly the idea in my PhD dissertation.


You use models to be able to adapt, evaluate, and store cases.


08 - Case Adaptation by Recursive Reasoning
-------------------------------------------

>> If you're interested in that example, we've provided a paper on it in the course materials for this lesson, so you
can read more about the process of adapting those cases to solve that very unique and complex design problem.


09 - Case Adaptation by Rules
-----------------------------

>> David, to generalize on your answer to design.


Designers, often use heuristics of the kind that you mentioned. For example, if you want to make an artifact lighter,
try a different material.


That's a heuristic, expressed as a rule.


10 - Case Evaluation
--------------------

>> Design more generally, we can simulate your design or we can actually prototype a design. Under the method for
evaluating a design could be to share it with other designers and let them critique it. So there are a number different
methods that are possible for evaluation as well.


11 - Case Storage
-----------------

So we just talked about how the evolution step in the case based reasoning process when decided a correct solution in
fact meets the requirements of the given problem. Now that we have the new problem and the solution for it, we can
encapsulate them as a case, and store them in a case memory.


We saw the advantages of this kind of storage earlier, when we went from home to restaurant. We stored that case is
memory so that when wanted to go back from restaurant to home. We could retrieve that case and try to adapt it. So case
choice is an important way of learning.


We are constantly accumulating and assimilating new cases. We talk about two kinds of storage mechanisms. Indexing and
discrimination crease.


12 - Case Storage by Index
--------------------------

>> That's an important point.


We want to use an indexical structure which allows for effective and efficient retrieval, because we are storing things
only because we want to be able to retrieve them at a later times. In case of design more generally, people have
developed indexical structures that had to do with functions, with operating environment, with performance criteria, and
so on.


13 - Exercise Case Storage by Index I
-------------------------------------

But for now, let's go back to where, original navigation micro world.


Imagine that we have a nucleus Y. Given our index equals scheme here, of X were coordinates of the initial location,
what do you think of the indices of the case Y?


14 - Exercise Case Storage by Index I
-------------------------------------

>> Precisely.


15 - Exercise Case Storage by Index II
--------------------------------------

Let's consider a different case. Supposing we have a case Z of going back from the restaurant or the home. Let's also
suppose that we're change our index equal


Kim. Now we are indexing things by the x square coordinates of the destination not the origin. What will be the indices
for the case Z?


16 - Exercise Case Storage by Index II
--------------------------------------

>> That's a good point David. Remember that we're trying to store things, because we want to retrieve things later. And
if our storage mechanism is such that it doesn't not allow for efficient retrieval, then it's not a very good storage
mechanism. And as you correctly point out, David, as the number of entries increase in this table, and the number of
dimensions we are looking at increase also increases.


This is going to be coming an inefficient for retrieval. Therefore, let's look at a second method called discrimination
trees which provides an alternate way of storing these cases in memory.


17 - Case Storage by Discrimination Tree
----------------------------------------

A discrimination tree is[br]a knowledge structure, in which the cases themselves[br]are the leaf nodes of the tree.


At the root node, and at all[br]the intimated nodes are questions.


The questions of the root node and[br]the intimidated node pertain to the pertain to the indexical[br]structures of the
cases.


So recall that, we were using the origins of the cases[br]as the index equal structure.


Let's stay with that point[br]just a while longer.


So now I might have a question that the[br]root node which says is the origin not of 5N?


If the answer to that question is yes,[br]then it brings us to this branch.


If the answer is no,[br]it takes us to the other branch.


At this node I might ask,[br]is the origin east of 5 of E?


If yes, it brings us to this branch.


If no, it brings us to that branch.


In this way we are able to[br]discriminate between C and


A, in fact we able to disconnect[br]with C not all of the cases.


Similarly for this part of the graph.


So now that we have learned, what is the knowledge structure[br]discrimination trees for organization the case memory,
let us now[br]look at how will we store a new case.


How will we incrementally learn this[br]knowledge structure as new cases are put into the case library?


Imagine that there is a new case, X.


So we can navigate this tree using X.


Is the origin of X North of 5 of A?


Yes it is.


So we come to this branch.


Is the origin of X East of 5 of E?


No it is not, so we come to this branch.


But now we have a problem.


Both A and X, have the same[br]answer no to this question.


We must find a way of[br]discriminating between A and X, so we'll add a new question here.


Perhaps we can add a new question.


Is the origin East of 3 of E?


In the case of X, the answer is yes.


In the case of A, the answer is no.


That's why adding a right[br]node at the right place, we have found a way of[br]discriminating between X and A.


This now is a modified[br]discrimination tree.


Each time we add a location to memory, the organization of[br]the case of memory changes.


This is an example of[br]incremental learning, with the addition of each case some[br]new knowledge structure is
learned.


We learn more about incremental[br]learning in the next lesson.


>> So going back to our programming[br]example, we were dealing with cases of file input, and we could use[br]the same
indexical structure according to which we organize our cases[br]to now design a discrimination tree.


At the very top level I would probably[br]ask, what language is the casing?


Is it in Java, C++, Python?


Now the discrimination trees don't have[br]to be binary like they are right here.


We can have more than[br]two answers coming out.


So at the top level, I could have[br]a question of what language is the case in, and the branches could be JAVA,[br]C++,
and Python, and so on.


I could similarly have questions about,[br]is it an efficient solution, is it for a big problem or a small
problem,[br]is it for my personal use or is it for consumer use, and so on until I get[br]down to individual cases that
represent different things I might want to[br]consider when I'm doing a new solution.


>> David a point you make about this[br]not being a but a very important one.


Let's go back to our original example,[br]where we had a micro world of blocks and the blocks had different colors.


So I can ask a question at the root[br]node, what is the color of the block?


And have a large number of branches[br]coming out of it corresponding to different colors.


Here's an example of a discrimination[br]tree, not a binary print.


18 - Exercise Storage by Discrimin Tree I
-----------------------------------------

Let us do an exercise. Supposing we're given the case Y, as shown here.


And we're given the discrimination tree, shown on the left. Where would you store the case Y in this discrimination
tree?


19 - Exercise Storage by Discrimin Tree I
-----------------------------------------

>> That's good, David.


But, of course, we must find a way of discriminating between A and Y.


20 - Exercise Storage by Discrimin Tree II
------------------------------------------

But know that A and Y were in this same branch. So we now we need to find a way of discriminating between A and Y. How
could we do that?


21 - Exercise Storage by Discrimin Tree II
------------------------------------------

>> So, for those of you familiar with Big O Notation, you'll notice that the efficiency of searching the case library
organized by indices was linear, whereas here, it's logarithmic.


22 - Case Retrieval Revisited
-----------------------------

Now that we have considered storage, let's revisit retrieval. We talked about two different ways of organizing the case
memory, a tabular way and a discrimination tree. How can we retrieve the case relevant to a given problem?


We assume here that the new problem has the same features in its description as the cases stored in the memory. Earlier
when we were storing a case in memory, at that time we were navigating this tree to find where in this tree should we
store the new case. This time, we'll use the problem to navigate this tree and find out which case is most similar to
the problem.


23 - Exercise Retrieval by Index
--------------------------------

Let us suppose that the case library is organized in the form of a table as shown here. Let us also suppose that we're
given a new problem, how to go from this initial location to this goal location. Which case should be retrieved?


24 - Exercise Retrieval by Index
--------------------------------

>> That's right, David.


25 - Exercise Retrieval by Discrimin Tree
-----------------------------------------

Let's repeat this exercise, but this time using discrimination tree for organizing the case memory. So here is a
discrimination tree, containing the cases currently in the case memory. And here is the, new problem. You could go to
the initial location, to the goal location.


Given this problem, what case would be retrieved from this discrimination tree?


26 - Exercise Retrieval by Discrimin Tree
-----------------------------------------

>> That's right David. Y is the closest matching case to the new problem.


27 - Advanced Case-Based Reasoning
----------------------------------

>> Failures are great opportunities for learning. When failures occur, we can try to repair the failure by going back
from the evaluation step to the adaptation step.


Or we can try to recover from the failure by going from the ed, evaluation step, all the way to the retrieval step. In
addition, we can store these failures in the case memory. When we store them in the case memory, then these failures can
help us anticipate failures that might occur with new problems.


There's a flip side to this. Just like it is useful to store failed cases, it is not useful to store every successful
case. If we stored every successful case, then very soon, the case memory will become very, very large, and the
retrieval step will become less efficient. This is sometimes called the utility problem.


We want to store only those successful cases that in fact help us cover a larger span of problems. This means that even
when a case succeeds. We want to store it only if there is something entrusting or noteworthy about that case.


28 - Assignment Case-Based Reasoning
------------------------------------

In this assignment, discuss how you'd use case-based reasoning to develop an agent that can answer Raven's Progressive
Matrices. Make sure to describe how this is different from learning by recording cases alone. Where is your adaptation
phase? How are you adapting past solutions to the new problem?


What is evaluation in this context? How are you evaluating the strength of your answer? Are you going to record the
cases that your agent encounters as they're solving the test, or are you going to equip them with past cases beforehand
for them to use to solve new problems?


29 - Wrap Up
------------

So today we talked about the broad process of case-based reasoning. Learning by recording cases gave us a method for
case retrieval called nearest neighbor method. So we went ahead and jumped into the adaptation phase. Given an old
solution to a problem, how do we adapt that old solution to a new problem?


We talked about three ways of doing that. We can do it by model of the world, we can do it by rules, or we can do it by
recursion. Then once we've adapted that old case, how do we then evaluate how good it was for our problem? Then after we
evaluated how good it is we looked at storing it back in our memory. We want to build up a case library of past
solutions, so if we've solved a new problem we will now sort that back into our case library.


Then based on that we revisited the notion of case retrieval.


Based on how our case library is organized, how do we retrieve a prior case that's most similar to our new problem? Now
there are a lot of open issues here.


For example, should we store failed cases? Should we store failed adaptations?


Do we want to store them so we can avoid failing in the future? Should we ever forget cases? Can our case library ever
get so big that it's intractable, and we can't really use it efficiently? Should we abstract over cases, so should we
use these individual cases to develop a more abstract understanding of a concept, or should we stick the individual
cases and adapt them from there?


If you're interested in these questions you can over to our forums and we'll talk about it there.


But we'll also be revisiting these questions throughout the rest of the course.


Next time we'll talk about incremental concept learning, which takes individual cases and abstracts over them to learn
some kind of higher level concepts.


30 - The Cognitive Connection
-----------------------------

Caseless reasoning has a very strong connection with human cognition as well.


Analogical reasoning in general is considered to be a core process of cognition.


But analogical reasoning depends upon a spectrum of similarity. At oned end of this spectrum are problems which are
identical to previously encountered problems. In that case, we simply have to retrieve the previous solution and apply
it. At the other end of the spectrum, are problems with just semantically very dissimilar from previously encountered
problems. We'll discuss those problems later in the class. In the middle of the spectrum are problems.


Which are similar, but not identical, to previously encountered parts. So now, we need to retrieve the past solutions,
tweak them, and apply them.


It is this middle of the spectrum, which is most common in human cognition.


Again, going back over cognitive architecture, which had 3 components.


Reasoning, learning, and memory. Learning by recording cases shifted the balance from reasoning to learning and memory.
Case we can contrast unifies the three of them. It says learning is important because we need to acquire and store
experiences. Memory is important because we need to be able to retrieve those experiences when needed. And reasoning is
important because we need to be able to tweak those experiences to encounter the needs of new problems.


31 - Final Quiz
---------------

Please write down what you learned in this lesson.


32 - Final Quiz
---------------

And thank you for doing it.


