.. title: P3L8 Refinement 
.. slug: P3L8 Refinement 
.. date: 2016-05-27 23:55:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L8 Refinement
===============


01 - Complexity  Abstraction
----------------------------

As you know the world is filled with complex problems that we try to, that we strive to solve. And our primary weapon
for dealing with this complexity, is abstraction. That is we hide details so we can concentrate on the big picture. For
example, when we have to pick up supplies at the grocery store for dinner. We break the problem down into traveling to
the store, locating the items, paying for them, and so on. It is only when we actually driving to the store that we
worry about things like what turns to take. This lesson is about managing this complexity by carefully refining a design
from an abstract version into an implementation


02 - Levels of Abstraction
--------------------------

Abstraction implies thinking at different levels. For example, there is the level of solving our hunger problem, where
we think about food items and where we can obtain them.


An entirely separate level has to do with our physical body movements, such as insert the key into the ignition or
packing the grocery bag.


For abstraction to help us solve a design problem, a key property must hold.


The work done at a lower level of abstraction must contribute to the solution at the higher level. It doesn't help us to
solve our hunger problem if all we pack into the grocery bag are paper towels and people magazine.


03 - Divide  Conquer
--------------------

In summary, solving a design problem at one level of abstraction means dividing it into subproblems. Solving each of the
subproblems at a lower level of abstraction and ensuring that the lower level solution, indeed, contributes to the
higher level. That is, divide and conquer.


04 - Horizontal Decomposition
-----------------------------

I want to talk about two different kinds of dividing. First off, horizontally dividing things. You can think of design
as a three-dimensional picture puzzle, where you have to cut out the pieces. At any one level of abstraction, you carve
out the pieces and fit them together. This is called horizontal decomposition


05 - Vertical Decomposition
---------------------------

However, solving a problem at one level is not enough. For each piece at that level, you have a whole picture puzzle at
a lower level. This ladder is called a refinement of the former. Devising the puzzles at a lower level, and ensuring
that they satisfy the needs at the upper level is called vertical decomposition. Of course the above holds true for each
of the top level pieces, and for however many levels are involved in your decomposition. So what we really have are a
collection of refinements at one level addressing a, a problem at a higher level.


06 - Proper Refinements
-----------------------

All non trivial design involves refinement. Moving from a high level of understanding to an implementation. Multiple
levels may be involved, not just two, depending on the complexity of the problem. To execute a multilevel design
properly, three properties must obtain. The top level must faithfully represent the requirements. Each level must be
internally consistent.


And third, each lower level must faithfully represent the level above it.


07 - Property 1
---------------

First, Property 1. Property 1 holds of any program that we want to implement.


It must satisfy it's requirements, obviously.


You check this property using traditional methods such as software testing, group reviews, and customer acceptance
criteria


08 - Bank Account
-----------------

In this lesson we are going to do an example of a refinement.


We will start with a very simple bank account application that allows deposits, withdrawals, and queries about the
current balance.


Here are some possible requirements.


The user can make a deposit of any positive number of dollars.


The user may make a withdrawal of any positive number of dollars so long as at least that number of dollars is currently
held in the account.


Their user may request the current value of the bank balance, which is defined as the net value of all the deposits made
minus the sum of all the withdrawals.


And initially the bank account is empty.


09 - Bank Account Class
-----------------------

Now, let's take it a step further and produce a UML analysis model of those requirements.


In particular, let's come up with a particular class called the account class and you can make some assumptions.


You can assume that all of the deposits and withdrawals are made in amounts that are positive integer number of dollars.


And you also do not need to include an attribute for the current bank balance.


We will add that as a refinement later.


Recall that a class description UML has a rectangle with three boxes.


The top box is the name of the class.


Here we're going to call it account.


The middle box has any attributes of that class.


And here the attribute that makes sense is some history of the users' transactions, the, the withdrawals and deposits.


I call that particular attribute transactions.


And I'm treating it as a sequence of integers, because we already assume that all the. wi, deposits and withdrawals
within in integers.


The class also has three operations, corresponding to the requirements.


One is deposits that takes an integer value and doesn't return anything.


Second is a withdrawal which takes a.


Integer value and doesn't return anything.


And the third is the query asking for the balance, which doesn't take any arguments but returns an integer value.


10 - Bank Account Quiz 1
------------------------

So far, so good.


But there's one more step to go, and that is we have to say things a little bit more precisely about what's going on.


So I'd like you to give some OCL constraints for each of those three operations, and for any class invariants.


Confirm to yourself that the class definition and specifications together satisfy the problem requirements.


In other words, satisfying property one.


11 - Bank Account Quiz 1 Solution
---------------------------------

There are four constraints involved.


The first one has to do with the deposit operation, and the precondition, as was stated in the requirements, is that the
amount being deposited is possible.


But the post condition is a little bit more subtle.


In particular, we decided to keep a record of the deposits and withdrawals in terms of a sequence of integer values.


The order of the sequence corresponds to the order in which those deposits and withdrawals are made.


So the post condition for the deposit operation is that whatever sequence you had of transactions at the start of the
operation, at the end will have one more added to it, which has as its value the amount that was deposited in that step.


Similarly, for the withdrawal operation the precondition is the same, however it had better be the case that, as the
requirements stated, that the amount being withdrawn if the account has enough money in it that you can make that
withdrawal.


The way that we express that part of it is that the sum of the transactions made so far is greater than or equal to the
amount being withdrawn.


Post condition is similar to the post condition for the deposit except the amount being appended will be the negative of
the argument indicating that the amount has been withdrawn.


The third operation is the balance query.


This has no precondition, but the post condition is the results returned by the operation are equal to the sum of all
the transactions so far.


That is, we go through them and add and subtract as appropriate to get to the current balance, and return that value as
the results of this operation.


Finally, one other constraint to be aware of, and this is the case for all such models that you produce, you have to set
up the initial conditions.


OCL has the keyword in it to indicate that, and in our case the initial condition is that the list of transactions or
sequence of transactions is empty to start with.


12 - Property 2
---------------

The first property that we looked at is concerned with whether we understand the problem we are trying to solve.
Property two is concerned with whether we have solved it correctly. We can state property two as follows, each level in
a design must be internally consistent. Technically, what this means is that we must make sure that for each operation.
Defined at that level.


Each operation leaves whatever invariants are there true.


That is, if the invariant was true before the operation took place it's still true afterwards. The operations don't
break anything.


13 - Notation
-------------

One of the objectives of this lesson is to give you some tools to think carefully about dealing with complexed, that is
the management of these levels of abstraction. So to do that, I am going to introduce notation. Okay, this notation is
taken from first OR logic. To state property too precisely, we are going to need a little of that notation. And
throughout the rest of this lesson, we are also going to use the term abstract and concrete to refer to the upper and
lower levels of a refinement. First off, we are going to talk about the abstract operations and we are going to use P1,


P2 and so on up to Pn and Pi we'll use to indicate a typical abstract operation. We're going to have abstract states.


The set of abstract states is the capital letter S and a typical abstract, typical element of the abstract state is the
letter s.


And we'll also put an apostrophe after the s if what we're talking about is the abstract state after an operation. We
have invariants, we use inv to indicate invariants and invA will stand for abstract invariants and invC will correspond
to the concrete invariants. We have pre-conditions and post-conditions and we'll just append the word pre and post to
our Pi's to indicate. Whether it's a pre condition or a post condition, and those pre and post conditions can have
states associated with them and arguments. Finally we'll use symbols like the ampersand to indicate and, and the
rightward facing arrow to indicate implies.


14 - Valid Operations
---------------------

Property 2 says that each level must be consistent. In other words, that Operations preserve invariance.


We will use the term Valid to denote Operations with these properties. That is, we wanted to be to, want to ensure that
all our operations are valid.


Using the rotations we just introduced, we can express Property 2 precisely by saying that for each operation. The
following must hold. Well, first off, that we have an abstract invariant over state s', and we have the preconditions
for s, and we have the postconditions for s. If we have all three of those things, then the invariant, the abstract
invariant must hold on the state afterwards.


Remember that that's the state s' with an apostrophe on it.


You have, invariant true before on the state.


You have the pre-conditions all set so the operation can run.


If the operation runs and leaves the post conditions the way we expect. And it better be the case that the invariants
are true on the state resulting.


Now that said for the model that we've done so far there is no invariance.


Okay, but we're going to need this later when we get to the refinement so


I thought I'd introduce it now.


15 - Implications of Property 2
-------------------------------

So, we've got some, some first order logic. What does this really mean to you as a developer. Say you have a spec, you
could have written it, could have been given it, or whatever, and you want to implement it directly. So we're going
from, from spec directly to implementation, just one level of refinement. Property two says that you have an obligation
to make sure that each operation in the spec doesn't break anything.


Any invariant. You can do this. You can insure yourself of this by testing, by code reviews or even by proving. But
somehow you, you have to do it.


16 - Property 3
---------------

Property three is where things get interesting. Okay? It states that each lower level of refinement, must faithfully
represent the level above it.


Okay? But this is going to be a little bit tricky to express, and involves some subtleties, we're going to have to get
at. It's the most involved of the three properties. And, the question one asks is, how exactly can we determine whether
a level implements the piece that is abstracting it? Before answering that, let's go back to our example bank account
and add a level of, refinement to it.


17 - Bank Account Refinement
----------------------------

In the abstract version of the bank account application, each time we wanted to know the bank balance, we had to add up
all the previous deposits and withdrawals.


And if you've done any kind of implementation out there, you know that that screams for having some kind of temporary
variable that holds the intermediate results so you don't have add those all up every time.


So let's add that in as refinement to our to our spec.


That is we're going to add another level of refinement, in which we're going to implement this particular optimization.


Okay, that will reduce the number of computation that we had to do, at the expense of adding this temporary variable in.


For the class model itself, there's just one additional line.


And this is in the attribute box, and it adds in a variable called runningTotal, which is an integer.


18 - Bank Account Quiz 2
------------------------

Of course, you also have to update your operations to update this temporary variable during the course of making
deposits and withdrawals and so on.


19 - Bank Account Quiz 2 Solution
---------------------------------

So as far as a deposit is concerned, in addition to appending that particular amount into the transactions list, we have
to update the running total.


And, as you recall from when we talked about doing OCL invariants when we're updating state.


You have an equation, in this case, it says running total equals running total at pre.


That is the value before the operation started, plus the amount of the deposit, which is A.


Similarly for withdrawals, we have to say that the running total that is at the end, equals the running total at the
start minus the amount being withdrawn.


As far as the balance operation is concerned, here's where we save those computations.


No longer have to do the sum, instead we can just return as the requested value the running total.


As far as initialization is concerned, in addition to initializing the transactions to be an empty sequence, we have to
initialize the running total to be zero.


And finally, here's the invariant, here's what we have to ensure is always true.


Which is that the value of the running total has to, at all times, be equal to the sum of the transactions.


Otherwise this optimization that we are proposing to add in our refinement is not going to be correct. 'Kay, note that,
as in this example, it is typical for invariants to relate the values of two or more attributes.


20 - Property 3 Details
-----------------------

Well now that we've got the exercise part out of the way let's return to the details of property three and see what it
means to faithfully represent that have the refinement faithfully represent the specification. In fact we have to check
three things.


There's three criteria that we have to look at. First of all, is the refinement adequate? That is, is our refinement
rich enough to represent all of the abstract situations? Second, is the refinement total? That is, are we sure that the
cron, concrete level can't get into some state that doesn't correspond to a possible abstract state? And the third
criterion is, does the refinement model the abstract level. That is, is each abstract operation correctly implemented by
a concrete one? We'll look at all three of these criteria separately, after we introduce a little more notation.


21 - More Notation
------------------

First off notation wise, they correspond to the concrete operations.


We're going to have variables Q sub 1,


Q sub 2, so on, to correspond to the abstract ones which were the Ps.


And similarly to correspond to the abstract state which was indicated by s.


We're going to have the concrete state indicated by t as a typical concrete state element. And capital T as the set of
concrete states.


And then, the interesting one is that we're going to introduce a function, a retrieve function. Here, I'm using retr as
an abbreviation for it. And it's going to map from concrete states to abstract ones. That is, retrieve on some t,
concrete state t, is going to be corresponding to some abstract state s.


And it's always going to be the case that, t goes to a single s.


However, it might be the case that different ts go to the same s.


You kind of expect that because at the lower level we have more details. And so, we can get into more states. But those
states are going to map into a fewer number of abstract states.


22 - Adequate Representation
----------------------------

The first property three criterion to consider is adequacy. That is, the lower level implementation must be rich enough
that each abstract state is represented by a concrete state. State it precisely, for each abstract invariant, if the
invariant is true in a state.


Then there must exist a corresponding state in the implementation in which that the corresponding concrete invariant is
also true. And in logic, okay, for every, every abstract state S, okay, if the abstract invariant is true for S, then
there must exist some state T down in the concrete. implementation. And some, some, concrete invariant over that state
T, such that if you were to apply the retrieve function to the concrete state, you would get the abstract state.


23 - Note on the Exercise
-------------------------

So thinking about the exercise for a second, what does adequacy mean?


Well, there's no abstract invariant.


And that really means you don't have to worry about anything for this particular property, for this exercise.


Or you can think about the in, the abstract invariant as just being the Boolean, value, true.


If we make this simplification then the above adequacy criterion looks like the following.


For every abstract state S, there's going to be a concrete state T.


And in that state the concrete invariance hold and if we apply the retrieve function to that state we get back to S.


What this means is that we have to check for each situation we can get into, with the abstract specification there
corresponds a valid concrete one.


24 - Adequacy Quiz
------------------

So, for an exercise, if I give you the abstract state that looks like a deposit of three, withdrawal of two, deposits of
four and five and then a withdrawal of six, I'd like you to give me the corresponding concrete state.


25 - Adequacy Quiz
------------------

Well, as you recall, the concrete state is like the abstract state except we've added in a running total to it. And if
we do the addition and, and if I've done my addition correctly, then the value of the running total attribute is going
to be 4 at this time. That is the valid concrete state is identical to the abstract one with the running total added in.


26 - Total Representation
-------------------------

That was the first criterion adequacy. The second property three criterion is totality. That is our implementation can't
put us in a concrete state that doesn't correspond to an abstract one. No memory fault core dump messages.


Memory fault core dump would be a concrete state. Okay? And it doesn't correspond anything in our spec. And we want to
prevent such situations from arising. We call this criterion total or totality because we must make sure that the
retrieve function is total in the mathematical sense. That it's defined at every point. Here is how this property looks
if we express it formally. For every concrete state t, if the invariants are true on t, then it had better be the case
that there exists, some kind of abstract state s. That's the result of retrieving out of t.


And the invariants of the abstract invariants must hold on, on state s.


27 - Totality Quiz
------------------

So let's now turn the exercise around. I'm going to give you a concrete state and ask you to tell me what the
corresponding abstract state is.


So the concrete state has the transaction deposit 13, withdrawal 12, deposits three and five and then withdrawal six.
And the running total of this is the amount of $3. Now I ask you to give me, what is is the abstract state that
corresponds to this?


28 - Totality Quiz
------------------

Simple right?


We just get rid of the running total. The transactions remain the same.


29 - Models
-----------

The third and last criterion to examine has to do with concrete operations, modelling abstract ones. That is, each
concrete operation must faithfully reflect the intent of the abstract specification.


You had to do your implementation right. And this criterion has two parts, having to do with inputs and outputs to
operations. That is to refine operations, we must assure ourselves of two things. The implementation must be able to
handle all the imports described in the specification. And the outputs produced by the operation, along with any changes
made to class attributes or other side effects, must satisfy the operation specification.


30 - Operation Inputs
---------------------

As far as inputs are concerned, inputs acceptable to an abstract specification must also be acceptable to the concrete
implementation. However, the refined operations, that is the implementation, can accept more.


This might happen if for example you use a particular library routine that's very general to deal with satisfying some
con, some abstract need. Okay, you can accept more inputs, but it has to accept at least as many as the abstract one
requires of us.


In terms of our specification stated more precisely, refinements can weaken operation preconditions. And in logic where
every, concrete state T, if the invariant is true an the, preconditions are true in the abstract state, then it better
be the case that the preconditions are true in the concrete state.


31 - Interpretation
-------------------

To perhaps get you a little more comfortable with looking at first order logic, we're going to parse this a piece at a
time. First, we are concerned with valid concrete states T. In which all the invariants, that is invC corresponds to
concrete invariants, hold on that state. Now consider the corresponding abstract states and remember the retrieve
function.


We can go from the concrete states to the abstract states by using the retrieve function. If we are in the abstract
state, the corresponding abstract state. And we want to execute the abstract operation with arguments, some argument
list, called args here. Then of course, it's preconditioned. Which we've indicated with the prefix ERE, on the retrieve
state, and the arguments must hold. If the abstract precondition does hold, and if we have implemented the operation
successfully. Then the concrete precondition, which has the, uses the Q version on the concrete state t, must also hold.


32 - Inputs Quiz
----------------

1


For our banking application, which of the three operations in


2 the account class that are affected by this part of the modeling criteria?


3


Check all that apply.


33 - Inputs Quiz
----------------

1


The answer is "Withdrawal."


34 - Outputs
------------

Well that was inputs, now let's look at outputs.


In particular the outputs produced by the concrete operations along with any changes made to class attributes and other
side effects must satisfy the abstract specification.


Among other things this says the answers that your implementation give had better satisfy what is required by the
specification.


Stated in logic.


If we have some concrete state t, and the invariant is true, and the preconditions are, the concrete preconditions are
true, and the, after executing the operation the concrete post conditions are true, then it better be the case that the
abstract post conditions are true.


Parsing this one step by step like we did for the inputs.


Valid concrete states as the part that says that for all t element of the set of concrete states, capital T would be
invariant.


The concrete invariant must hold on that state.


And the concrete preconditions are satisfied, and that's the Pre-Q sub i on t and whatever arguments we have.


And running the country operation satisfies the concrete post conditions.


That's the phrase with post Qi on a concrete state.


The arguments, the resulting concrete state T apostrophe, and whatever results are produced.


Then the post condition had better map to the stated abstract post condition, the last part of our post logic.


Which say's the post condition on the abstract operation Pi, with the retrieve state, the arguments, the retrieved
version of the resultant state, and the results produced had better hold.


Note that as you might expect, the implement, the implementation can do more than what the spec says as long as it does
at least what the spec says.


35 - Outputs Quiz
-----------------

Let's ask the same question we did a minute ago about the bank account class.


Which of the three operations in the Account class are affected by this part of the modeling criterion? That is, the
part that has to do with outputs. Check all that apply.


36 - Outputs Quiz
-----------------

Well this time, all apply. You should have a check in each one of the boxes.


All the operations are affected because all of the concrete post conditions refer to running total, the account balance
attribute.


37 - Satisfy Property 2
-----------------------

So now that we've, we've got together all the criteria, and the, first order logic expression of things, let's go back
to Property 2 for a moment.


That requirement that the concrete implementation is consistent.


Recall that this means that all operations preserve invariants.


The relat, relevant invariant is that running total reflects the sum of the transactions that have taken place.


So we have to make sure that each of the operations if that invariant is true before hand, it's also we true, it is also
true afterwards.


So the balance operation is not a problem because it doesn't effect the value if the variables.


For the other two we would need an inductive argument that the invariant is initially true and that deposits and
withdrawals keep it true.


This intern relies on the fact that the sum operation can be defined in terms of re, repeated additions and
subtractions.


38 - Summary
------------

Pulling this all together. The problem is that design is tough. And design mistakes can be costly. Our chief weapons
against complexity are abstraction and refinement. So we must make sure that our refinements do what we expect. One way
to do this is, is to systematically think about what refinements must guarantee.


Here they are, the top level specification, matches the requirements document.


Operations at each level preserve invariants. Each refinement is adequate.


Each refinement is total. And the concrete operation preconditions and post conditions model their abstract
counterparts.


