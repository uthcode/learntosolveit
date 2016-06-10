.. title: P2L6 Formal Specification Exercise 
.. slug: P2L6 Formal Specification Exercise 
.. date: 2016-05-27 23:43:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text


P2L6 Formal Specification Exercise
==================================



01 - Specification
------------------

If you want to design a program, you might want to know first what the program is supposed to do. These instructions are
called specifications and they might come from the customer, the end user or the analyst team. They might pr, provide it
to you in informal text, in a structured document, or using a formal mathematical notation.


This lesson focuses on precise specification using mathematical notations


02 - FOL
--------

In this part of the course, we will use two notations, mathematical logic and


OCL. The brand of mathematical logic we will use is called by various names, including first order logic, FOL, and
predicate calculus. You should be familiar with FOL from your undergraduate computer science courses. If you need a
brush up, there's a paper on the class resources page you can look at. Also for purposes of this lesson, we will use a
textual syntax for FOL that is described on another paper on the class resources page. As a reminder, FOL enables you to
precisely express propositions, combine them using logical connectives like and, or, or not. And quantify them using the
operators for all and there exists.


03 - OCL
--------

The other notation we will use, is OCL. OCL stands for the Object Constraint Language, which is a part of the Unified
Modeling Language, UML. OCL provides a syntax for


FOL, that can be used to annotate UML diagrams.


04 - Sorting
------------

To build up our understanding of precise specifications, we will use a simple example. Sorting. Everybody intuitively
knows what it means to sort a list.


Everyone that is except the computer. You need to provide a sorting program too.


Imagine that we want to specify a program that could sort vectors of integers, in ascending order. Let's name the
program sort, and say that it takes an input argument named X, which is a vector of integers.


It returns another vector of integers Y, that was a version of


X sorted in ascending order. We will begin by using First-order logic.


05 - Exercise Introduction
--------------------------

>> So, there's a lot going on in, in trying to e,e, express that in a precise fashion. Let's see what we can, what we
can do about it.


06 - Input Type
---------------

So, the, the first thing to consider here, is whether or not your specification stated what the input looks like. Okay?
And, and


Jared, in fact, said it was a vector of integers. If not, then your program would allow the vector, apples, oranges,
rambutan, physalis and pepino to be sorted in a meaningful way. Those, by the way, are some weird fruits that I came
across on Wikipedia. So you might say, and which Jared did given is a vector of integers named X.


07 - Output Type
----------------

And Jared also mentioned that the output is a vector of integers.


And in this case in named Y.


08 - Ordering
-------------

And of course a key with sorting is that the output is in order and in particular here we're concerned with ascending
order, and


Jerred tried to indicate what that means by talking about the values at particular positions with respect to the
position that comes after them.


In the output vector. And we had to make a special case concerning the, the last element. because it doesn't have
anything that comes after it.


09 - Sensitivity to Input
-------------------------

>> Okay? And if you think about it for a minute, sorting is pretty simple. If you imagine trying to specify the software
on the international space station or something something you had better get right or, you know, if it doesn't work
there's safety issues. it, it makes sense to spend some time, in trying to state precisely what's going on here.


10 - Circularity
----------------

And just to point out that Jared didn't run into this problem.


But, sometimes in people trying to specify things they might use the concept being defined in the definition.


So, saying that sort is defined in terms of sort. That would be a circular definition and you have to look out for that
because. It doesn't really get you any place as far as better understanding of what the problem is.


11 - SORT in English
--------------------

So here's, here's one way of kind of combining the things that we eventually got around to with, with Jared. Given is a
vector of integers named X. Produced is a vector of integers named Y. The output vector Y must be ordered, in order,
okay? And the contents of Y must be somehow the same as. The contents of X.


That is everything in X must be in Y, everything in Y must come from X, and the number of occurrences of each item in Y
must be the same as the number of occurrences of each item in X. Even that seems a little a little long and so we'd like
to now take this same problem and see what it looks like when we express it in a precise mathematical notation.


12 - Process
------------

So how do we go about doing this? Typically, when we want to do mathematical specification, we break it into three
stages.


The first stage is called the signature. The second is the precondition. And the third is the postcondition. Let's look
at each of thee three pieces


13 - Signature
--------------

The signature gives the name of the program, the names and types of the input arguments, and the name and type of the
results. For SORT, the signature looks like the following. Vector of type integer Y equals the SORT of the Vector of
type integer X. That is, SORT takes a single argument named X, that has a datatype, which is a Vector of integers.


And produces, produces, as a result, Vector Y, which also holds ints.


14 - Comments on Signatures
---------------------------

In, in specifying the signature we have given explicit names to the variables Y and X. And we do this because we'd like
to be able to refer to them in the pre and post conditions by, by some, some name.


Clearly this is simple, similar to what you would do in, in writing a stub in a programming language like Java. Where
you can give whatever names you'd like to the arguments as long as you consistently use them.


The other thing to note about this is that, we could apply our SORT program to things other than integers if they ha,
satisfy one particular condition, which is that the basic elements have to be suitable as arguments to some kind of
ordering operation. So greater than, less than, and so on, are ordering operations. So we can sort ints, we can sort
reals, we can sort, strings and lexical graphic order if that's what we needed to do.


15 - SQRT Signature Quiz
------------------------

Okay, here's something.


Here's, here's, here's one for you to try out.


Let's, let's give a signature for a function called SQRT, short for square root, that takes as input a real number, and
returns another real number whose value is the square root of, of the argument.


See what you can come up with.


16 - SQRT Signature Quiz Solution
---------------------------------

>> Straight forward. Hope, hopefully you all got, got that one. So, second step is preconditions. And we're, we are
talking about a function here, or functions. And the precondition will take the form of an assertion about the
function's input arguments. In particular, think. Along the following lines.


If you were writing some code to compute a function that took some arguments, one of the first statements you might have
in your code, is something that checks whether the input arguments are what you expected. What we like to do, is in our
specification, state what those conditions are. And the set of those conditions is the precondition for the function's
execution.


17 - SQRT Preconditions
-----------------------

>> Okay, fair enough, now of course if instead of reels, we had complex result, okay, then we wouldn't have the same
precondition, but deciding what the form of the. Output is whether it's real or complex is an important part of the
specification process. For this particular exercise, we're going to go with, go with the real numbers and the
precondition says that X which is our input argument is greater than or equal to zero. Notice that were not saying what
happens if.


X is less than zero. We're specifying the behavior of the function in terms of what does this function mean when it gets
expected arguments? Now, if you wanted to have a variant. Which worked on any argument.


But race and exception or produced a return code if x was less than 0.


We could specify that as well. But we're going to keep it simple for now and really say we're defining square root over
the non-negative reels.


18 - SORT Preconditions
-----------------------

>> That's right, if we are not concerned about the type checking parts of things, then any input vector of integers,
sort should be able to deal with it.


So in this case, there is no precondition, or we could also say the precondition is true, that is the precondition
always holds.


19 - Postconditions
-------------------

So that was signature and that was precondition. The third part which is usually the trickiest one is post conditions. A
post condition is also an insertion.


And it says what must be true about the output produced by a function.


Typically this means expressing how the output relates to the input


20 - SQRT Postcondition Quiz
----------------------------

So going back to our, our square root example, okay? See if you can come up with a post condition for SQRT.


21 - SQRT Postcondition Quiz Solution
-------------------------------------

>> So y times y equals x. That in fact is something that must be true after square root executes. And so it's a, it's a
post condition. And in fact, it is the only thing we need to worry about, okay, that, so it, it completely specifies any
routine which we would, believe to be a, a, a suitable square root routine. As long as the, the output, that you get
when multiplied by itself gets the input, you say it's the square root.


22 - Comments on Postconditions
-------------------------------

So some Comments on Postconditions. First of all, we've only been concerned so far with pure functions. And a pure
function is one in which the output is completely determined by the input. However, in real programming languages,
computational units like functions, procedures and methods may be impure. For impure functions, in addition to
describing how the output relates to the input you should also indicate any side effect. These include changes to global
variables and any operations like input and output that aren't reflected in the results of the function. And if we're
talking about and


OO. That is, an object oriented programming language, then changes to any instance variables of the of, of the object
that we're dealing with, are also things that we would have to express inside the post conditions. But so far, with
square root we don't have to worry about that.


And it's also the cates that, that sort is going to be a pure function, so we don't have to worry about it there.


23 - Postconditions for SORT
----------------------------

Okay, square root's easy.


Sort's going to be harder, as far as the por, postcondition is concerned.


So I'd like you to, let's go back for a minute to the natural language specification and revisit that and then consider
what the postcondition of sort's going to be.


So we said in the natural language specification.


That the output vector Y must be ordered, and somehow the contents of Y must be the same as the contents of X.


That is, everything in X must be in Y, everything in Y must come from X, and the number of occurrences must, must match
up.


24 - Ordered
------------

>> For every element in Y, if there exists an element that is after it, then that element must be greater than or equal
to the current element we're looking at. Almost there, okay. you, what, Jarrod did is he broke the specification into
two parts.


One part is all the elements except the last one. And he, he stated exactly what the post-conditions is for that. But he
didn't say anything about the last one.


Okay, so if we wanted to have a precise specification, we'd have to deal with, with that one as well. Okay? Now, it turn
out in this particular case that we can do a little proof in our head. To say that if the post condition that he
specified for all the other element is true, that implies that the last one must be the greatest one. So, we could get
we could get away with that, and in fact that's a pretty nice, clean way of expressing it. Notice, also, that Jared used
the word" for each," and when you hear that phrase, it's suggestive of, in our first-order logic, of one of those
quantifiers that I mentioned, the universal quantifier, for each or for all. And so we're going to, we're going to see
when we specify this in first order logic that that, that quantifier is going to be there.


First order logic when we introduce a quantifier at the same time that, or, when we use the quantifier at the same time
we introduce a variable which is going to stand for the typical element of the vector. Okay, so for each i where i is
going to be an index position into y, then we can say something about the value that's held in position i and the
position i plus one Okay? So, the quantifier for each has a variable that comes with it we can call it i or j or
whatever you would like.


25 - Elements
-------------

>> So, in, in this part of the, the lesson, we're going to use first order logic. It turns out, that OCL is just
another, another syntax on top of first order logic. Okay? We're going to stick with first, first order logic here.
eventually, I'll show you a little bit of OCL.


And then, in later lessons we'll get into, the whole OCL as a language. Which in addition to first order logic has some
other things that help it deal with UML


26 - ORDERED Precondition Quiz
------------------------------

That was the signature for ordered. Now think for a minute about what the, precondition for order is.


27 - ORDERED Precondition Quiz Solution
---------------------------------------

>> Sure, sure. And in fact when we think about what Jared was saying earlier about all the elements of greater than,
less than, or equal to the one that comes up, well that's true of an empty vector.


All right so, we're going to hope that our post-condition for ordered when we write it down, will, if, if we plug in an
empty vector, we'll get out a valued true for that. Third step is the post condition for order and this is going to turn
out to be the, the trickiest one but it is a pure program and for all pure programs what you're really saying is what
the relationship of the output is to the input and


I'm going to give you a couple of hints on this one okay. One is you're going to have to use a quantifier. And what you
can say about the value of the ith element of the vector, that is a typical element of the vector in, what can you say
about that in relation to the value of the ith plus first element.


28 - ORDERED Postcondition
--------------------------

It written out in nice predicate logic we have what's shown here. It says for all i, okay, so i, sorry for all is the
quantifier, i is the index variable.


And we're going to qualify i by saying it's, it's greater than or equal to 1. And it's less than the length of Y when we
put a vector inside of the vertical lines that's the, the length or cardinality of it.


It must be case so the, the dot that we have here separating the two parts, you can read it must be the case. We can,
use that i to pick out an element of Y and compare it to the element that Y plus 1 if in fact we have ordered output it
had better be less than or equal to it. Notice that we said less than the length of Y and that gets us around the
problem of trying to index into a value of the vector into a position of the vector that doesn't exist.


29 - RORDERED Spec and Pre Quiz
-------------------------------

Now let's see if you've got it. I, I, want to, I want you to now specify a full specification in FOL for the function
RORDERED, which is just like ordered except it's in, in descending in descending order. So go through the, the three
steps. First do what the signature of RORDERED might be.


30 - RORDERED Spec and Pre Quiz Solution
----------------------------------------

>> This should be, this should be straightforward, pre-condition's going to be true or you can just leave out the pre-
condition


31 - RORDERED Postcondition
---------------------------

Now, see if you can take that quantified expression we had before.

>> Mm-hm.

>> Okay, as far as the post condition is concerned and play with it a little bit to get a post condition.

And this one, I'll give you a hint, is going to be different.

Okay, it better be different.

>> Mm-hm.

>> Or otherwise we're specifying ordered again.

See what you can do with it.

>> So, very much like our other post condition, we will start by saying for every element i.

That of, is index of, of a integer y from one all the way to the element one less than the cardinality of the vector y.

It better be the case that, if we're looking at Y sub i that it is greater than or equal to the element that-

>> Succeeds it.

>> Succeeds it, sorry.

[LAUGH] >> Comes in, comes [INAUDIBLE], okay?

That's precision is, is what this is all about.

>> Mm.

>> So exactly right.

In fact, the only change is that instead of a less than or equal, we have a greater than or equal, okay?

And notice that we could've done this same thing with j.

The exact letter that we use, doesn't make any difference.


32 - SAME-ELEMENTS-AS Signature
-------------------------------

>> Mm-hm.

>> So as I said before, the actual letter that we use doesn't make any difference as long as we're
consistently use it.

So we could say here bool y, we could say bool z, as long as is, it's different than those input names that we used.


33 - SAME-ELEMENTS-AS in English
--------------------------------

>> Okay. And it points out a choice that you have as a specifier here.

We could if we were given a a vector of length three and a vector of length 10, say no they, they don't have the same
elements and remember by same elements as, we're talking about the same number of occurrence as. Or, we could treat it
as a pre-condition, okay? And say that the lengths must be the same in order for us even to apply same elements as, as a
function, and that's the choice that we're going to, we're going to make here. Okay, so remember that the vertical line
is used for cardinality or length. And the cardinality of x must be equal to the cardinality of y.


Now we're talking here about first order logic. We're not talking about a programming language. So equals means equal.
It doesn't mean a sign to or anything else. We don't have to worry about anything like the C or


Java where we'd have to use two equals, symbols in order to designate equality.


So we're just going to say that the length of x equals the length of y, and that's the precondition for, same elements
as. Now, going back to when we first asked the question to state in, in English, what it means for the output to be the
assorted version of the input, we said things like each element in x must be found in y, each element of y must be found
in x, and the number of occurrences the elements in x must be the same as the number of occurrences the elements in y.
And we could take that and we could go through the stage of writing out each of those parts in first order logic.


34 - Permutation
----------------

Fortunately, there's a better way. We can make in, make use of an already defined mathematical construct called a
permutation, that is, we can describe the same elements as in English by the following. X has the same elements as Y if
the elements of X are a permutation of the elements of Y. Or, the other way around. The elements of Y are permutations
of the elements of X.


Because we know that permutation is well-defined, has well-defined mathematical properties, we don't have to write it
out for ourselves. We could just rely on an already existing well-defined concept. Nevertheless, for the, for the
purposes of this exercise, let's, let's build up a a specification of what it, what it means for one vector to be a
permutation of another vector.


35 - PERMUTATION Signature Quiz
-------------------------------

So, once again we start with signature. Why don't you try laying out, what a signature for permutation would be?


36 - PERMUTATION Signature Quiz Solution
----------------------------------------

>> And it makes sense. If we're trying to use permutation in place of the same elements as, that it has a very similar,
or in this case, identical signature except for the name of the, name of the function that we're dealing with.


37 - PERMUTATION Postcondition
------------------------------

>> It is.

>> Okay, so special case number one, the length of the input vector is

We will say in fact that the output is a permutation of the input


38 - Non Empty Case
-------------------

Okay that was a simple case. Okay, and now have to consider the, the case in which the vectors do have elements, and
we're going to also break this down into two more cases, depending on whether or not the first elements of x and y are
identical. Okay? So first case is, yes they are identical. So in this case, determining whether X and Y are permutation,
boils down to whether or not the tails of X and the tail of Y are permutations of each other.


And the tail of a vector is everything except the first element. So we could say that, for this case, in order for the
output to be a permutation of the input, the syntax on the. That you see on the slide holds. In particular that says, if
the length of X is greater than 0, that's our special case.


And our second special case was that the value in the first position of


X is equal to the value of the first position in Y. And the third condition is if the permutation if, if the tail of X
is a permutation of the tail of Y than we can conclude that in fact X and Y are permutations of each other.


So what were doing now we, we handled the case where they were empty vectors and said they were permutations and in this
case if these three conditions hold, they are permutations, okay? The other thing to note, is that, what we've defined
here. Is a recursive definition. Now I warned you before about recursive definitions, often leading to cases where the
definition is not meaningful.


Now here I'm going to give you a specific situation in which you are allowed to do that. And we're allowed to do that
because it essentially is, is an inductive argument. Okay? The permutations that we're using in our definition, are
permutations on the tails of the input and output, okay? And the tails are everything but the first element and so
they're shorter.


And we also already have handled the case where we got down to 0 length.


So we handled 0 length, and we handled everything in terms of its tail.


We have a well founded induction here. And so in fact, our definition of permutation is in fact meaningful.


We couldn't say that, X is a permutation of Y if X is a permutation of Y.


Okay? That wouldn't be a meaningful induction. But here because we're shrinking it at every step, it is in fact a
meaningful induction.


39 - Non Matching Case
----------------------

So two cases down, one third case to handle is if in fact the first elements of x and y are not the same. To deal with
this case what we're going to do is we're going to carve up Y into three pieces, and we're going to determine what those
three pieces are based on where and why the first element of X is. So, the first element of X is five.


Someplace in Y there is a five otherwise it's not a permutation. So let's call the position of five in y the jth
position and our three segments are going to be from one up to J minus one. Second segment is going to be the jth
position all by itself and the third segment is going to be the j plus first position all the way to the nth position.


The last position. Three segments and we are going to define whether or not x and y are permutations in terms of those
three segments.


40 - Recursion
--------------

So to state this in logic, we first have to define what j is.


And we're going to use the other the, the there exists quantifier. And that's represented by a backwards facing E. So
there's going to exist some position which we're going to call j. And it's going to be greater than one.


We've already taken care of the k squared's equal to one.


So it's going to be greater than one and it's up to, the length of Y.


And what must be the case is that the value in Y of the jth position.


At the jth position must be equal to the value in X at the first position.


In order to make use of this we're going to then use the three segments that we have and define. And we're going to use
a recursive definition like we did before. And, but it's going to be in terms of these three segments.


41 - Pasting
------------

The way we're going to deal with this is by pasting together the segments, leaving out the J position. In particular,
we're going to say that in order for the output to be a permutation of the input, in the case where, we don't have a
match in the first position, okay? And it better be the case that, the following two things are permutations of each
other. First thing in our permu, in, in our check is the tail of X.


That is we're going to leave off that first element. And then, we want to compare that permutation wise with the results
of pasting together the first segment of Y with the last segment of Y.


So, we have left out the first element in X. And now, we are going to leave out that same element in Y by pasting
together the first, remember, which J minus one elements, okay? Then from J plus one to N, we're going to paste those
together, leaving out the J position. And we are going to ask the question, is the tale of X a permutation of that? Now
we know from our equality check, that in that J position, we matched the first one of X. We've left that out. We've left
out the one in the J position. And we're now asking recursively the question about whether the remainder of


X matches is the permutation of those two segments pasted together.


42 - Third Case
---------------

>> Okay, so it is another well-founded induction because we've shrunk the lengths of the things that we're comparing
recursively. in, in logic this would look like x is the value at position 1 of x does not equal the value in position 1
in y, that's our condition here and there, what we had before about the position x so there existed j. j is greater than
one, j is less than the length of y where x of 1 equals y of j and it must be the case that there's a permutation
between the tail of x. Leaving out the first element and the results of pasting together y from 1 up to j minus 1 with
the result, with the the third segment which was from j plus 1 through the end of, end of y.


And the little funny symbol with, looks like a cap hair is pasting together and the real name for that is concatenation.
We can concatenate two vectors together using this operator and if those conditions all hold then we'll, then what we're
defining x to be a permutation of y.


43 - All Together
-----------------

>> Okay.

>> Okay? So I, I, I did state it incorrectly.


44 - Some Questions
-------------------

>> Right.


45 - OCL
--------

So far, we have expressed specifications in first order logic. UML includes a variant of first order logic, called the
Object Constraint Language.


We will be going into OCL in subsequent lessons, but for now, I would like to show you, what it looks like.


Here's the complete specification of ordered. That was the first part of our sort routine, in OCL. That is the
signature, the pre and post conditions.


46 - Notes
----------

Several differences that we saw in the OCL from the First-Order Logic. It uses the vertical bar, not only, to get at the
length of things, but I'm sorry.


Not not as we saw in the First-Order Logic to indicate the length of things, but it serves the role as the dot we saw
before to separate the part which is saying. What the, what the variable is from the remainder.


The limitations on the value of i appear as part of the proposition itself.


The limitations on the value of i are separated from the proposition itself, by the use of the implies OCL keyword. I've
also cheated a bit, by using OCL's built in sequence class instead of vectors.


OCL doesn't have vectors, it has sequences, but those are essentially the same.


47 - Summary
------------

To summarize all this, sometimes you need a means to precisely express exactly what the functionality of a required
system is. There are a variety of formal languages, and accompanying tools exist for writing such specification.
Many of these are industrial strength. That means they're used in industry, and there's tool suites that come with them.
Although using them requires you to think hard about exactly what you want to say. The effort can save you a lot of
rework, resulting from misunderstood requirements
