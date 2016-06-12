.. title: P2L8 Library Exercise (OCL) 
.. slug: P2L8 Library Exercise (OCL) 
.. date: 2016-05-27 23:45:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L8 Library Exercise (OCL)
===========================


01 - Library Exercise
---------------------

Remember back, several lessons ago, when we analyzed a set of requirements for a library information system, and we
expressed the results in a UML class model diagram. Along the way, we were actually able to improve the quality of the
requirements as we discovered several things, that weren't mentioned explicitly. But there were some aspects of the
problem that the UML diagram could not express. In this lesson, we will use, the object constraint language, a part of
UML, to fill in the gaps.


02 - Library Problem Requirements
---------------------------------

.. image::  https://dl.dropbox.com/s/x8rjyw9m9xgxrv8/Screenshot%202016-06-11%2009.14.15.png
   :align: center
   :height: 300
   :width: 450



As a reminder, here are the requirements.

A simple set of 11 sentences that describe possible behaviors, and elements of the information system we're trying to
design.


03 - Class Model Diagram
------------------------

And here's the Class Model diagram we, derived from it. You, you recall, it had a Patron class, it had a class of
Loanable Item, and we had to invent a Title class, in order to be able to correctly deal with the user's requests to
reserve a a book.

Along the way we also came up with several associations, one for making requests and the other that recorded the actual
checking out of the loanable items.


04 - Requirements Quiz
----------------------

As a first quiz on this, I'd like you to look through the set of 11 requirements and determine which of these the
diagram is able to, by itself, adequately address and which of these requires something more to be said.


05 - Requirements Quiz Solution
-------------------------------

>> Okay.


06 - Limitations
----------------

So as far as the answer to the question's concerned, two and nine are completely expressed with the diagram.


But the others require some varying amounts of work ih, to, to get precisely at what's intended by those requirements.
And so to, begin our exploration of the use of OCL here, we're going to look at Requirement number 6.


07 - Requirement 6
------------------

Requirement 6 recall, says, "Books are checked out for three weeks unless they are currently bestsellers, in which case
the limit is two weeks." Okay, what's happening a key that points to an issue here is that they're explicit numbers.


And if they're explicit numbers then typically that means there has to be some kind of a check. And if there's a check,
where you going to express the check okay. It turns out that UML provides a way to express requirements like this and
associate them with elements of the diagram, and this part of UML is called the Object Constraint Language, or OCL. It's
an official part of the language.


It's available and supported by tools, including drawing tools that you can then annotate various parts of the diagram
with, with the OCL.


It provides, that is OCL provides sufficient expressive power to convey to any level of detail the functional
requirements of a system because it's essentially equivalent. In power to the first order of logic, okay? So, let's see
how we would express Requirement six using OCL


08 - Requirement 6 Quiz
-----------------------

So to think about writing something up in OCL, the first thing to think about is, which of the classes in the diagram,
is the most appropriate place to annotate to make that expression.


And, OCL has a key word called context. And the context is typically the name of a class or a method in a class, and in
deciding that you're going to write an OCL expression, you need to first decide, which of the classes or methods you sh,
you should use. Okay. So, with respect to these books are checked out, requirement, which of these classes do you think
would be the appropriate one to associate with that requirement.


09 - Requirement 6 Quiz Solution
--------------------------------

>> Well, that was easy. Okay, the, the, the keyword there is the first word of the requirement is books, are currently
are checked out for three weeks. So our context is going to be, is going to be book.


10 - Checked Out Quiz
---------------------

The second thing to decide about in coming up with a constraint is whether the constraint is associated with the system
or a part of the system that is a class. Or whether it is associated with an operation. If it's associated with a system
as a whole or with a class then we're going to use an invariant. Saying what must be true about the system or what must
be true about the class. Whereas if it's associated with an operation, then we talk about the pre-conditions for the
operation and the post-conditions for the operation and we will use the pre and post keywords to express those.


Okay, in this, in this case, when we're talking about the check out period, does it sound to you more like it's an
invariant or as an operation.


11 - Checked Out Quiz Solution
------------------------------

>> It holds true. It's invariant okay so yeah, we're going to say that there's an invariant over the book class, that
we, we now want to express, okay?


Now one. one, one thing to realize is, just like when, in drawing the diagram, there's never only one correct answer.


And so we could if we wished have for the the check-out operation, we could have postcondition there which says that
that, that this is true.


And do it that way but it ma, makes more sense in situations where something is always true, so you have an invariant
for it


12 - Requirement 6 OCL
----------------------

So once we have determined the class to use and the type of constraint, we can actually express the constraint in OCL
and here's what it slooks, looks like. What I've put in bold are key words that belong to the language and the parts in
plain text, not bolded text correspond to the particular.


Particulars of the UML diagram so we have the context is book.


We have the keyword invariant and then we have a conditional expression.


Recall from the statement of the requirement that there were two situations, one for books in general and the other is
for bestsellers. So it makes sense that we have some kind of conditional going on there. This is a conditional
expression.


It's not a statement in the sense of a, a programming language.


That is it produces a value rather than a change of state.


Okay? And so if we read through it says, if bestseller and recall that bestseller was a bullion. Then it is the case
that the check out period, which is an attribute of book, is two weeks. And otherwise, the check out period is three
weeks. So, one of two possibilities exist, and it depends upon the value of that, that boolean.


13 - Explanation
----------------

What we've written expresses a single constraint, that is a single property of the system which must always ho, hold.
Okay? It happens to be an invariant as indicated by the INV, keyword.


What, one thing that I've glossed over is, the fact that, we use the numbers 2 and 3, explicitly. Without any indication
that they're, they're dates. Now that can be inferred from the type of checkout.


But if we were to get this completely right, we have to make sure that all the types matched up.


And in fact, we were talking about two weeks here or three weeks here. We do have a date class but we have to make sure
that we're using it appropriately.


Each OCL constraint is interpreted in the context of a particular class.


What that means is that any names that occur without qualification.


That means without having only a single part without any period in there are interpreted in the context of a particular
class. And what that means is that the name could be the name of the class, it could be the name of an attribute, or it
could be the name of an operation.


We're also allowed within the language to refer to elements of other classes.


And in that case, we're going to have to explicitly name the class. And then put a period separator. And then the name
of the attribute or the name of the operation in the other class. Those are qualified names. But if we're doing it in,
if we're referring to names that belong with the class itself, we don't have to which is why we have the context
keyword.


This particular constraint is conditional and says that for each book object, if the bestseller attribute of that object
is true, then the checkout period attribute for that object must have the value of 2. Denoting two weeks, otherwise the
checkout period attribute must have the value if 3


14 - Requirement 7 OCL Quiz
---------------------------

Your turn. This time for requirement, 7 which is that A V material may be checked out for two weeks. Remember the series
of steps that we went through.


What's the, what's the context, and what kind of invariances is it?


15 - Requirement 7 OCL Quiz Solution
------------------------------------

>> So very similar to the, very similar to the previous one.


This one doesn't have to be a conditional. Because there's only one possibility here.


16 - Operations
---------------

So in the, the previous two examples we were talking about the value of an attribute and those are usually pretty
straightforward. Let's now talk about operations. OCL provides a way to specify operations using pre and post-condition
constraints. These are different keywords in the language.

In this case, we're going to look at requirement three, which describes some query operations. Now by query operation, I
mean an operation that is asking about the value of an attribute, but not changing anything. So, in this case, it should
be straightforward to have an operation that returns that value.

So, the requirement itself says, in addition, at any particular point in time, the library may need to know or to
calculate. The items a patron has checked out, when they are due and any outstanding overdue fines. So, let's
concentrate on a part about the items a patron has currently checked out.

So, previously when we did our analysis, we associated this text with an operation class patron called items currently
checked out.

What we need to do now is to say something about that particular operation.

We need to make it stated more precisely then just saying that it exists. And in fact, we have to say that the value
computed by this operation corresponds to just those items that are checked out for that patron. Recall that we have a,
an association between patron and loanable item.

And that association is going to record what items are checked out.

And now we're talking about the operation in patrons, so essentially that operation is querying the association, and we
want to make sure that what the operation returns is in fact, what's appropriately expressed in the association.

17 - CheckedOut Operation
-------------------------

>> Okay, so great point. And so we call one of the, one of the subtleties of the original requirements analysis. I had
to do, what happens if you check out a book, hold it overdue, you have money due on it, you return it so it's not
accruing any extra as far as the fine is concerned, but the system has to remember that, right? So in a sense that
checked out record has to still be there. To hold that information, now what happens if you try to check it out again?
Okay. If we use a set here we run the risk of clobbering the record and breaking things. So


I think you've pointed out a place where we have to be very.


Very careful about doing this right and in this case it looks like yes we would clobber things in that particular
situation. For operations that we're trying to model in OCL the next question typically is, what are the preconditions?
And that means the circumstances under which it is meaningful for the operation to execute. In the case of items
currently checked out as with most operations that provide a value without affecting any change in state, there are no
preconditions. In OCL we have two ways of dealing with that, we could have a precondition which has the value, the
boolean value true which says. It always is the case that it's okay to run this operation, or we can leave out the
precondition entirely, which has the same, same implications and, so for readability purposes you may want to do that to
make the, make the overall constraint a little shorter.


The third part in specifying operations is to specify which value is returned by the operation to compute the items that
are currently checked out, we merely navigate along the checked out association to the corresponding loanable items.


So here's what the overall constraint looks like.


We have the context which had our signature and then we had a post condition.


Now the post condition lists another O-C-L keyword which is result and that stands in for whatever it is that's computed
by that operation, and what, what needs to be computed in this case is those. Links in the checked out association which
correspond to you know, items checked out by this particular patron. Now, we already are restricted by our context to
just the, the patron of interest for the query. and, that patron is then going to be a partner in certain of the links
in the association, and we want to get the partners of the other end, the loanable items that belong to that patron. So
we navigate from patron, which is our context through checked out to loanable item and that will be the set of loanable
items that are currently associated with that that pattern, and it once again leaves us in the situation where, what is
checked out mean Okay, it means either you currently have them checked out. And haven't returned them, or you checked
them out, you held them too long, you returned them, and the system is remembering that you still owe something on them


18 - Explanation
----------------

The phrase checkedOut.LoanableItem is an example of a compound name in OCL.


The checkedOut part is an association which is adjacent to patron, and then the qualification of that is LoanableItem
which is also adjacent to the association. So it's as if we're walking through the diagram. And every step along the
way, is going to be a name in our qualified name.


OCL yomilla as a, in general, treats the names of these associations syntactically, just like it would treat an
attribute.


19 - Requirement 4 OCL Quiz
---------------------------

20 - Requirement 4 OCL Quiz Solution
------------------------------------

>> Okay, okay.


21 - Requirement 4 Explanation
------------------------------

There are several noteworthy features of this constraint.


The first is the use of the implies keyword to denote logical implication, which is just a way of saying the restriction
is only true for children.


It is equivalent to the use of the right right arrow in first order logic.


The second feature is the, the OCL use of the right arrow, this one with only one horizontal line. And that's used with
collection classes.


So in the case where there's a collection on the left hand side and you wish to, access or make use of one of the built
in operations in this case size, you can use this right arrow to say you'd like to bring in the size operation on this
particular collection class. The other types of collections that we'll get to but all of them have a size operation
associated with it


22 - Side Effects
-----------------

So, so far the two operations that we've looked at have been query operations.


That is, they've been asking about the values of attributes. However, in interesting information systems, in addition to
querying, you need to have operations that actually change the state of things.


And, so this is going to be ultimately implemented with the database and you need the ability to add records, to change
records, and that sort of thing.


We call particular operations that don't make any changes like this pure, as in pure functions. Because they're similar
to mathematical functions, which always compute the same result. Functions which are impure, are said to have side
effects. And side effects might be changing the values on the database. They might be doing IO operations, input output
operations.


Or flashing something on the screen that the user sees. what, whatever it is.


So, those are side effects. And, so, now, as the next, next step in our, modeling of these requirements, let's try to
specify a more complex situation.


One where an operation actually results in a change of state. In this case, we choose to model the actual process of
checking out a Loanableitem as indicated in requirement five. A patron can check out books or audio visual materials


23 - Requirement 5 Signature
----------------------------

>> Okay. >> Okay. So, that was, that was the the context and the signature for checked out in this case.


24 - Checkout Preconditions Quiz
--------------------------------

Now we're talking about adults. So, the question for you is, there are various preconditions that must hold in order for
you to check something out.


25 - Checkout Preconditions Quiz Solution
-----------------------------------------

>> My, my library they say you want to pay the $0.10 now or, or hold off on it and they make me pay it, but I can hold
off on it


26 - Requirement 5
------------------

So the, these three conditions that Jared has come up with about whether it's available, whether it hasn't been
requested by somebody else and the one that we had before concerning age correspond to three conjuncts.


You know, three, three possibilities that all must hold. And as we talked about a minute ago we could have three
separate preconditions, or we could have one precondition with three, with, with two ands separating the three parts of
it. The other thing to note in the expression of it is.


We've use some new operation names, in expressing it.


So we said, is available. Now, is available is not one that came out of the process of building the [UNKNOWN] class
diagram. But that's okay.


It's like. Breaking the writing of a a method into, into pieces and calling other methods along the way. Okay it's, it's
just divide and conquer. So, we're going to assume we can invent the names of these convenient operations. And, that
simplifies the, not only the writing here, but the reading as well, if we're trying to show the requirements to the
customer.


27 - Checkout Postconditions
----------------------------

>> Okay, cool.


28 - Further Checkout Explanation
---------------------------------

>> Okay


29 - Postconditions
-------------------

30 - Derived Data Quiz
----------------------

So far we have seen how OCL is used to specify invariants and operations. There is another part of our analysis model
that OCL can help with.


That's derive data. There were two places in the [UNKNOWN] model for the library, where derive data, was used. The
Patron's age and the amount of the overdue fine. Remember that derive data are, they're attributes, like any other
attributes but, they're going to be computed along the way, rather than something that is a, is a set piece of data.
Okay?


And the, the situation here had to do, for example, with the, Patron's age, which is changing on a day to day basis. So,
at any moment when we need the age, we compute the value. Okay, so we need to say what value is being computed. And the
same, the same holds true for the amount of fine which changes on a day to day basis, and depending upon how long your
book is overdue. So let's, let's do a little exercise here.


See if you can come up with a constraint in OCL or a Patron's age.


And as a hint here, there's a keyword in, in OCL called derive, and you use that instead of pre or post interim variant.
See if you can express it.


31 - Derived Data Quiz Solution
-------------------------------

>> Okay, so clearly this, any information system is going to live within some some context in which, there's going to be
libraries and, and system calls and that sort of thing. So we're assuming here that there's some class, which I've
called operating system and it's got a, a, operation associated with it called getDate and that we can then compute the,
the difference between those two and the difference will be a. What we, we call the persons age. Now notice that we're
also finessing some details here.


In this case the subtraction operation has to work on dates. And we we often, when we say age think of age in terms of
years. And we did that for, the amount that could be checked out and, but the subtraction between dates might be years
and months and days and sort of things. So, we would have to get that right depending upon how we're going to use date
within the system.


32 - Missing Pieces
-------------------

This lesson has illustrated some uses of OCL to provide precise specifications for simple library information system.
Even so there are many more things we need to do to complete this exercise.


We haven't even mentioned some of the other requirements like numbers one, three, eight, ten, 11 which we would need to
specify. We haven't of course at all in this whole exercise mention anything having to do with non functional.


Requirements. Along the way we invented some axillary operations like is available, and is available is actually pretty
complicated itself and we'd have, we'd have to white that out. We'd have to handle some situations implicit in the
requirements such as returning a loanable item, as returning a book we checked out. Paying a fine, cancelling a request,
and so on. And, we might have to consider some new some new issues that arise during the course of doing this. For
example, if one item in a title is a best seller, need all of them be best sellers, okay? It would make sense in a
library if you have some. Designated a book as a best seller that all the items in that title, are a best seller. But we
haven't stated anything explicitly that would require that. We would also need to op, add in some specifications for
operations for classes date. And money. Money had to do with paying fines. Although in those situations we could
presumably reuse those specification in other systems that we're building.


Likewise, for the operating system operations. We also haven't said anything about constructing instances of loanable
items and patrons. Although, we did construct instances of associations and we can use similar techniques for
constructing h, the instances of the other two classes.


33 - Observations
-----------------

So, some observations about this exercise. Be aware that there may be more than one answer. And we, we saw some
instances of that. Be open during the process of analyses to the possibility of new requirements arising or that there's
ambiguities. Or infact, that there, mistakes have been made.


And this may mean for the consultation with the customer. The fact that a simple set of requirements can have so many
issues, should illustrate the value of performing this kind of careful thinking that is but the kind of careful thinking
that is required in order to construct an OCL specification.


