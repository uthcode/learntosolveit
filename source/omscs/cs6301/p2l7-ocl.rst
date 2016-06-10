.. title: P2L7 OCL 
.. slug: P2L7 OCL 
.. date: 2016-05-27 23:44:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L7 OCL
========

01 - OCL
--------

The topic today is the Object Constraint Language, a part of UML. So far when we've looked at UML we've been looking at
diagrams. But diagrams don't tell the whole story. There are places in the specifications and the designs of your system
where you need more details. And that is what OCL was designed to provide to designers.

OCL is a language, it's not a programming language, it's a specification language. It's declarative, it's strongly
typed, and allows you to specify the functional details of system properties.

OCL consists of a means to express constraints plus some collection classes. And an ability to navigate around the
various classes of relationships in your diagrams. OCL's a mature technology is part, an official part of UML and
supported by various tools. Such as Rational Rose, ArgoUML, Eclipse, Poseidon, Enterprise Architect and so on


02 - Why Do We Need OCL
-----------------------

Why do we need, a language that goes beyond the diagrams?

The diagrams are great, at describing structural relationships. We'll see with state charts, that they can also describe
some behavior, but there's, there're times when you need to be more precise, particularly about the functional details.
Of exactly what it means for this particular component, to do this particular task. OCL extends UML, with class in
variance.

With descriptions, precise descriptions of operations in terms of pre and post conditions. And they can also be used as
guards on transitions in state chart diagrams, which we'll see, subsequently in the term.


03 - OCL Overview
-----------------

As an overview, three aspects of, of OCL to be aware of, is first of all it's declarative. It's not a procedural
language, it's not a programming language, it's a way of specifying properties. In programming language terms it's a
pure expression language, that is, it describes values, it doesn't, describe activities. It doesn't have any assignment
statements, instead it, it specifies assertions or constraints or properties, usually with equal signs. The language is
strongly typed and it comes with some primitive types that you might expect in terms of reals and integers and so on.
And the neat thing about OCL is it only has one key concept involved with it. And that's the concept of a constraint.

A constraint is some formal assertion of system properties.


04 - Uses of OCL
----------------

You can use OCL for a variety of voices. You can specify invariants on classes in your class model diagrams. You can
describe pre and post conditions on the operations, in your diagrams. You can specify derivation rules for derived
attributes. Remember them? You can describe guards on transitions in statecharts. You can specify the targets for
messages and actions, you can specify type invariants for stereotypes, which we'll describe a little bit later. You can
even use it as a query language. Class model diagram is describing a set of Possible instances, and you might wish to
query those instances for certain things, OCL can be used as a query language in that sense.


05 - Syntax
-----------

Here's the Syntax. There's only one statement in the language.

It's a statement which is a constraint. The constraint has a couple of keywords in it, and a couple of expressions. The
first keyword is context.

And it's followed by an identifier. That identifier gives a name to the context.

The context is where you are in a diagram. Usually this means a class, so it's the name of a class. It might be the name
of a particular method in a class. Then there comes another keyword which is the kind of constraint, and we'll see that
there's three kinds of constraints. One is invariance, one is pre, preconditions, and one is post conditions. And then
comes a Boolean expression, which is the actual constraint that the statement is expressing.

From what I've just said you can infer correctly that OCL constraints are inherently connected with UML class model
diagrams, and you probably will have already developed the class model diagram. And then gone into details by specifying
the details with the OCL constraints


06 - Invariants
---------------

An invariant is a statement of a property that's always true. You can think of it as an expression of a key system
requirement.

Might be an essential relationship among the values of objects in, in your system. The keyword that's used to indicate
that, you know, you're expressing an invariant constraint is **inv**. For example, you might say in large companies that
the official definition of a large company is a company that has more than 50 employees.

And you could express a constraint that says that in OCL by having in the context of the large company class. An
invariant that says its number of employee's attribute must be greater than 50.

07 - Role of Invariants
-----------------------

If you're familiar with the relational databases, you may have come across the idea, of integrity constraints. And can,
integrity constraints are just another name for invariants. For example, in a database, you wouldn't want to have a
record for a, a person saying that they work for a company, and that company has gone bankrupt and is no longer in the
database. In programming terms that's a dangling pointer.

You want to make sure that your database or your system, never gets in situations where there's those. There are those
kinds of integrity violations.


08 - Invariant Constraint Quiz
------------------------------

Here's a short quiz for you. See if you can come up in the large company example with another integrity constraint.


09 - Invariant Constraint Quiz Solution
---------------------------------------

As far as the stock market is concerned, large companies have to have a certain amount of capitalization, and here we've
invented a constraint that says the market capitalization for large companies had better be at least $1 million.


10 - Pre and Post Conditions
----------------------------

The other two kinds of constraints are pre and post conditions.


These are used for expressing precisely what it means to use an operation that belongs to some class. The key words here
are P-R-E for pre, and post for post. In a given, constraint, you can have one of these or both of these.


Or you could have two constraints, one with pre and one with post in it.


Preconditions says the circumstances under which it's allowed that a particular operation to take place. Post conditions
says what is the results of executing this particular operation. Typically that means, what's the relationship of the
return value to the input parameters? However in an object-oriented language it might also mean what are the effects on
any attributes of the classes that take place because of the operation has been invoked.


11 - Pre and Post Conditions Example
------------------------------------

For example of pre and post conditions think about an operation for taking a square root. In English we might say
something as far as a precondition is concerned, the argument had better be a non-negative number.

As far as a post condition is confirmed something like the square of the computed results must equal the argument.
That's a little bit backwards way of thinking about things but in fact it is a true expression of equality okay, that
must, must be the case if square root has the meaning we expect it to have.

If we were to express these particular constraints in OCL, we might do them in the context of the built-in class reel.
And having, adding an operation called square root, that returns as a result, a real answer.

The precondition is that the argument which is, in, in this case, is the number we're taking a square root of had better
be better than or equal to zero. And the post condition is that the argument should be equal to the result when
multiplied by itself.


12 - Changes to Attribute Values
--------------------------------

The square root example has to do with specifying the properties of the results of a computation of a function. We might
also consider situations where the effect of a particular operation is to change the attribute values for some class.
How might we do that? Well, let's consider the example of a bank account.

And has an attribute which is the current balance and has operations for deposits and withdraws. We might wish to
guarantee that the balance, the current balance reflects any deposits that are made and any withdrawals that are taken
out. How might we express such a constraint?

Well here's an example, if we have a deposit operation in the account class, that takes a real argument. Which is the
amount being deposited and as the sanity check we make sure that the amount is greater than 0, that's the precondition.
We might try to express the post-condition with something like saying the balance equals balance plus the amount.

However, remember that the OCL is a declarative language. An equal sign here means equality it doesn't mean assignment.
So what we're saying with this as the way that it's written is the balance equals the balance plus the amount.

Well, that can't be the case. All right, that doesn't make sense. Fortunately, OCL has a mechanism for allowing us to
express these sorts of situations where we're changing, changing values. And that particular mechanism is, consists of
an @ sign followed by the, the word pre.

And what that denotes is the value before the operation executed. If we don't use @pre than what we're seeing when we
express balance or deposit is the value afterwards. So we can express the post-condition this time correctly by saying
that balance equals balance @pre plus amount.

That is, we take the previous ba the previous balance, add in the amount being deposited and we get the new balance.
Looks like an assignment segment, but it's really an equality.


13 - Post Condition Quiz
------------------------

To check this out, try the following quiz. Imagine that you had a class with two attributes, a and b. And you wanted to
write an Operation swap that swaps the value of the two attributes. Say you're going to do this in a post-condition. See
if you can write down a post-condition that expresses that the effect of executing swap as if those two values had been
interchanged.


14 - Post Condition Quiz Solution
---------------------------------

It's even easier in OCL than it would be in a programming language.

You don't have to use some temporary variable to hold one of the results. You could say simply the post-condition is
that a's resultant value is b's previous value. And similarly, b's resultant value is a's previous value.


15 - OCL Built in Types
-----------------------

And that's pretty much all there is to the basics of OCL.

We have some Built-in Types, Booleans, Integers, Reals, and Strings. We have the ability to express literals of those
types. And we have some Built-in Operations on those types. So we can combine Booleans with your favorite, Boolean
operators ands, and ors, and so on. We can add and subtract and multiply integers and reals. And we can we can deal with
strings, we can convert them to upper case or we can concatenate them together.


16 - OCL Keywords
-----------------

The entire OCL language has a small set of keywords. We've already seen invariant, pre, and post. There's an if-then-
else if you need that to, describe conditional expressions. There are Boolean operators.

There's a packaging mechanism that reflects UML's ability to partition things into packages. The context keywords you've
seen. There's, several key words that allow you to do some definitions. Definitions can be useful to save you typing
effort if define something to use the short version there's ability to indicate that your computing the value of derived
attribute the derived key word. There's the ability to indicate that you're specifying an initial value, we, and we've
already seen result and self.

17 - Let Clause
---------------

Let's just have a look for a minute at the let clause, which is way of doing a local abbreviation or a local definition.

Say you have you a relatively complex computation that you're going to include in one of your constraints, and you're
going to use it more than once.

Now, you could type it out more than once, but that's extra effort and you might make a mistake. So instead, you could
use a let clause to introduce a new identifier that has the value of that expression, and then use that identifier in a
subsequent constraint. So for example, if our income is expressed in terms of the sum of our of our salaries for all of
our jobs, okay, we could use a let clause which says exactly that.

We could introduce a new variable, or identifier called income and then we could have expression, in this case is an if
then else expression that says if someone is unemployed then their income is less than 100 else their income is greater
then or equal to 100. It's just as if we've typed in the long expression in both the places where we used to.


18 - Navigation
---------------

I said at the start that OCL had constraints, it had collection classes, and have navigation. Let's say, let's talk for
a minute about the navigation aspect.


I also said that OCL typically is associated with a particular class model diagram. And when you remember that the, each
of the OCL constraints has a context clause that says which class or operation you are starting with.


Well, it's certainly a value to be able to give constraints on the instances of a particular class. But it's even more
powerful to be able to say, that several classes are related in certain ways. That means, that in your constraints, you
need to not only be able to specify the attributes of the, the context class.


But the attributes of other classes, as well. Okay? Well, how do you do that?


In OCL, there's the concept of navigation, which allows you to essentially walk your way through the diagram. And every
time you take a step, you add the period and the name of the next class or relationship along the way.


19 - Navigation Example
-----------------------

Here's a diagram that involves a group of classes and we're going to assume, that our contacts class is the customer
class in the upper left hand corner.


Now let's say that you would like to write a constraint that involved, the date in which an order was made. Remember
you're in the cu, you're in the customer class. To do that, you can use this series of steps each separated by a period.
You can say self.order.date.


Self is your class, order is the next class along the chain, and date is the attribute, of that particular class.


20 - Navigation  Multiplicity
-----------------------------

What do I mean by multiplicity? Well, we've seen with class models, that we can adorn the associations, with stars and
numbers and so on. And this indicates, how the number of instances of one class, is related to the number of instances
in another class. For example, we could have 1 to 1 associations, like spouses. Okay, we could have 1-m, 1 to multiple
associations, like a parent and the parent's children. Or we could have m to n, multiple to multiple associations, like
we might have between students and courses. That is, a student could take multiple courses, and a course could have
multiple students in it. There's the ability in UML to express each of those possibilities by, adorning the ends of the
association with numbers or stars and so on. In UML, when multiplicity is used, the result of navigating is some kind of
collection. It might be a set.


It might be a bag, it might be a sequence. And, UML, and


OCL in particular, has a notation, that allows you to po, perform operations on those collections. The notation is a
hyphen followed by a greater than. You can think of this as an arrow.


21 - Bank ID Quiz
-----------------

See if you can express the navigation from Customer to BankID in order to determine the number of different banks that
were used to make payments.


See if you can come up with an expression that gives the number of banks.


And as a hint, collections have an operation, a built in operation, called size, which for any collection will return
the number of elements in that particular collection.


22 - Bank ID Quiz Solution
--------------------------

Here it is, self.order.check.bankID and then our pointer that says to the size operation.


23 - Collections
----------------

So we've, we've been over constraints, we've been over navigation, the third main element of OCL is collections. I've
hinted at what that is.


There's, there's four built in collection classes.


We already talked about sets, and bags, and sequences a little bit.


There's an abstract class that sits above them all called the collection class.


These four classes are organized with the collection class being a parent class, and the collection class has various
operators such as, size which we saw and count, and sums, and ways of interrating over the collection and so on.


That are inherited by all of the three other collection classes. Moreover, those collection classes, those three other
concrete collection classes may themselves have some specialized operations. The OCL reference manual has a complete
list of all the operations that are available to you for dealing with collections


24 - Other OCL Features
-----------------------

In addition to the three main features, there's some other relatively lesser, less used features of OCL that I just
wanted to mention.


There's the concept of tuples. This is similar to what you would do in a programming language where you would have
structs or records.


There are frenzy enumerations that you see in, in Java and other languages.


There's the ability to express messages. We haven't gone into this as much but in UML diagrams, you can express
messages. There's access to the UML meta model.


And there's the concept little word concept of automatic flattening.


Say, we did our navigation, and along the way we came upon two situations, two associations which were have many
participants in them.


So we might end up with a set of sets, or a set of bags, or something like that. OCL has made the decision to do
automatic flattening, that says if you have a set of sets, you just get one set.


You don't in your syntax have to express two levels of access in order to get at the contents. This can make it a little
bit easier to write your expressions.


25 - Summary
------------

And that's it for OCL. It's a, it's a, it's a relatively simple language.


There's some tool support for it. What it is, does is it gives you the ability to precisely specify the properties of
your system.


They're a complement to the diagrams, which can give you the structural and behavioral aspects of things. But OCL allows
you to become as precise as you'd like. In order to get a true sense of what it is your system is supposed to do


