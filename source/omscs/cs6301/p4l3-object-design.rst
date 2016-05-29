.. title: P4L3 Object Design 
.. slug: P4L3 Object Design 
.. date: 2016-05-27 23:59:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L3 Object Design
==================


01 - From OOA to OOD
--------------------

Earlier in the course we saw how object oriented analysis can give you a better understanding of the problem you are
trying to solve.


The results is a set of diagrams, interface specifications, expressed in OCL, and a list of non-functional requirements
and constraints. Then the architectural design process can help you determine appropriate subcomponents. Understand the
tradeoffs among the constraints.


Select appropriate methods for satisfying the nonfunctional requirements. And choose a suitable architectural style. The
eventual target is to produce a program written in some object oriented language like Java.


The purpose of this lesson is to introduce you to Object Oriented Design,


OOD. The process of getting you from your analysis and intended architecture to the point where you can write the target
program.


02 - OOD
--------

The primary concern of OOD relates to the individual classes and relations in the class model in our, analysis diagram.
This process is sometimes called object design. Before considering object designs however, several other preliminary
topics need to be discussed. In particular the inter model.


Consistency among your diagrams. The actual steps in going from analysis to design. Some system design considerations.
Abstraction mechanisms you might use.


And, I want to take a moment to talk about as, a somewhat, different approach called collaboration-based design.


03 - 1 Intermodel Consistency
-----------------------------

First of is Intermodel Consistency. The analysis process may have produce multiple diagrams, each of which we can think
of as a model.


These must be checked for inter-model consistency. For example, if you produce use cases, in, in the form of a use case
diagram, you want to make sure that you have some representation for the individual use cases. Possibly in terms of a
communication. Or sequence diagram, and the names would have to match up.


Similarly, if you have classes that have complex behavior, you want to make sure that you have a StateChart for those
classes, and in the StateChart, any events, actions and activities correspond to methods in the class model.


And, if you, have data conditions on your StateChart.


Those data conditions are going to refer to attributes. It had better be, the case that those attributes are listed in
your class model diagram.


04 - OOA to OOD Quiz
--------------------

For a start off quiz, lets consider the situation when you're about to begin object oriented design.


You come in with a set of UML diagrams, possibly including OCL constraints, which you produced during the analysis
phase.


When you've completed the OO design, you also have a set of diagrams and these diagrams serve as a direct expression of
what the target program will look like.


What I'd like you to consider for a moment, is what is the difference between these two sets of diagrams.


In particular, what UML elements used in the OOA models don't have direct equivalents in object-oriented programming
languages, thereby requiring some change to be made to the object-oriented design diagrams.


05 - OOA to OOD Quiz Solution
-----------------------------

Are here are four.


First off is associations.


Associations are everywhere inside the OOA diagrams, but object-oriented programming languages don't have associations.


It's going to be up to you to decide during object-oriented design how you're going to implement those associations.


Related is the question of aggregation.


We know in our diagrams that various, the diamond is used to represent aggregations.


You will have some choices at programming time as to how you are going to represent what programming language futures
you are going to use to represent those aggregations, and during O-design you have to make those decisions.


Third off, is invariants, so in your OCL you may have to express certain invariants.


And it's up to you in your program to enforce those invariants.


That is, make sure that it's always the case that the invariant holds.


During OOD design, you have to come up with some strategy whereby those invariants are going to be maintained.


And finally with StateCharts,


OO programming languages don't have state machines.


And as we seen, the state charts that are produced during OOA can be complex, so you will need some kind of approach in
your OOD for how you're going to deal with that complexity.


06 - 2 From Analysis to Design
------------------------------

As far as going from analysis to design and process there, here's three things that you should consider.


First off, I would suggest treating the entire system itself as an object.


And that any of the objects which you are actually going to have in your program would be attributes of that overall
system object.


Second is we just men, mentioned.


It may be the case that we're going to have to decide how to deal with associations and invariants.


And third, as you'll see a little bit later in this lesson.


Although you're going to have in your OO design, classes that were originally specified during your object oriented
analysis, you're also going to have some addition, additional classes.


And we want to look at what are the circumstances that would lead you to having some additional classes.


07 - 3 System Design
--------------------

The third preliminary topic is system design, and that is considering the system as a whole, possibly with respect to
the environment in which it's going to run.


First item is architecture.


Okay? We've already talked about nonfunctional requirements and their effect on architectural style.


Second is how you're going to deal with concurrency and there's a spectrum of possibilities here between having
everything in a, in a single process to having one thread per object.


Physical design has to do with how you're going to allocate tasks to processors and deal with any peripheral advi-,
devices that are part of the system.


If your application has a, a significant data storage requirement you have to make some decision about whether you're
going to use a database to do that.


Whether you're going to do files.


And how you're going to deal with issues like lock, locking.


And protocols talking back and forth to the data repository and the system.


What is going to be the overall control regime of your application?


Okay.


Is your application going to be reactive, such, such as would be the case with, when you have a GUI and the user is
controlling things with mouse clicks and, and key presses?


Or is your application going to be proactive, that is, it has its own it has its own control in mind Whereby it calls
the appropriate subcomponents in order to accomplish whatever its goal is.


And finally, an important thing to consider is how you're going to handle errors and failures of various sorts.


Okay?


Is there a recovery technique you have in mind?


Are there error reporting approaches you're going to take with the user?


How are you going to deal with that overall problem?


08 - 4 Abstraction Mechanisms
-----------------------------

The fourth topic I'd like you to be aware of is the Abstraction Mechanisms which you can bring to bear in solving
problems. As I indicated at the start of the course, the key element in success in doing design, is having experience in
solving similar problems. The way that the human mind stores this experience is in terms, of chunks or vocabulary, such
as words like client server, or visitor pattern. This Vocabulary can be thought of at different levels. So at one end
are, programming idioms that is snippets of program text which, it's almost as if you've memorized in order to
accomplish some specific task.


Classes of course are an Abstraction Mechanism, and being aware of whatever Classes are available to you in system
libraries can ease your task of, of constructing the application. A little while later we're going to be talking about
design patterns and I mentioned one a second ago the visitor pattern.


Being aware of those already existing solutions can help you avoid problems. And we'll be talking in this course about
aspects but aspect orientated programming is a way of specifically dealing with cross cutting concerns.


We'll also won't be talking much about object orientated frameworks. Well, they too are existing patterns of solutions
which, if you are aware of them, can significantly increase your productivity. And, as we've already talked about,
architectural styles, [UNKNOWN] approaches to solutions at the architectural level, are a powerful mechanism you want to
be familiar with.


09 - 5 Collaboration Based Design
---------------------------------

Finally, I want to say a word about collaboration-based design.


When we did object-oriented analysis, we were essentially picking out the important objects in the description of the
real world.


And we're using those as the basis of deciding on classes and and the associations among them.


And eventually we got to the stage where we were mentioning methods that the classes might provide as services.


Collaboration-based design takes a somewhat contrary approach to things.


In particular it's concerned, it starts with use cases.


Individual use cases sometimes called user stories or scenarios.


And with these use cases, each use case has various actors playing a specific role for that use case.


Collaboration design, by the way, is sometimes called role-based design.


So we can say that for a particular actor, participating in a particular use case, that actor's fulfilling some kind of
role.


So let's specify that role.


That role takes the form of the actions that, that user takes in that user's story.


Once we have catalogued those actions, okay, we can then examine other use cases that involve that same actor.


And from the set of activities which that actor under, undergoes in the various use cases, we have built up a set of
roles and the combination of that set of roles is in fact going to be what the overall capabilities that that class must
provide.


So we can synthesize the classes from the set of roles we've defined during this, this process.


I'm not going to go into role-based design any further, but you may come across it in the literature or you may want to
look into it more yourself and, and try it out.


Because it can be an alternative approach that might be helpful under some circumstance


10 - Object Design
------------------

1


With those preliminaries out of the way, let's jump into Object Design.


2


In particular, we're going to look at some of the specific elements that


3 are currently analysis model and


4 how we're going to deal with them during the design process.


5


Those elements include methods, new classes you might have to devise,


6 how we're going to deal with generalization, associations, and dependencies.


7


How we're going to implement control, and then how we're going to deal


8 with abstraction abstraction, such as abstract classes, interfaces and types.


11 - 1 Sources for Methods
--------------------------

First, as far as methods are concerned, where do the methods come from?


One obvious source is the operations in our analysis model.


In addition to the specific services provided, there are signals, okay, and there maybe actions, activities, and events
in any behavior model such as state charts.


We also have to make sure that we're signing those operations in the form of methods to particular classes.


In addition to those that come directly from the analysis model, there's others we should always be aware might need to
be included in our classes.


You should include constructors and destructors, getters and setters,copy constructors, printers or, or methods that
construct string versions of the data inside of a class.


Selectors, if you have, complex data, how you're going to take out the pieces of it.


And, any kind of, iterators if you have, if your class has more than one, you know, is a collection class of some sort.


How are you going to provide the elements of that collection.


It's not necessarily the case that every class has to have all of these methods, but you should be aware of the
possibility of their existence so you can determine early on whether or not that you need to define them


12 - 2 New Classes
------------------

I mentioned earlier that your analysis model has classes in it, and those classes are likely to show up in the design
model.


However, some additional classes may also need to be there.


What's going on is the following.


Object-oriented development methods have an advantage called traceability.


What this means is that you can see, starting with the real world that's being modeled, classes that directly represent
those real world objects.


Those classes show up in the object-oriented design as well and in the ultimate code.


That is, you can trace a line in either direction between the real world problem and the code constructs.


This can be a real benefit in dealing with maintenance of the system.


However, along the way, you may have to invent some other classes and that's which we want to examine.


First and foremost, you may need to implement relationships.


Your programming language doesn't have associations in it, and it's going to be up to you to come up with a way for each
of the associations in the analysis model, how you're going to deal with it at design time and in your program.


You're also going to have to deal with intermediate results.


For example, if you have some complex computation that's going to be used in several places, you want to store it in
some intermediate inter, intermediate variable and then reuse it in the two places so you don't have to recompute it.


Constructing those intermediate results may mean you are inventing new classes.


And third, you may want to invent new classes for abstraction purposes.


Object-oriented languages provide you the ability to have abstract classes, which capture common features of lower-level
classes, and inventing those abstract classes and including them into your design can improve long-term maintainability.


13 - 3 Generalization
---------------------

I now like to begin looking at how you're going to deal with, you, and you'll know, relationships that show up in your
analysis model.


In your ultimate program, there aren't any, direct representations of those, particular relationships, so during design
you need to come up with a strategy for how you're going to deal with them. First one we like to look at is
generalization. Now, object oriented programming languages have a feature called inheritance, and I want to take a
minute to describe to you the differences between inheritance and generalization, because it can get you into trouble if
you just routinely treat one as the same as the other.


First off, Generalization is an abstraction between two classes that mean that all instances of the child class are also
instances of the parent class.


Inheritance, on the other hand, is an implementation technique, whereby messages sent to a child may be delegated to a
parent. You can use inheritance to, implement Generalization, but you have to be careful how you do it.


14 - Generalization Example
---------------------------

Here's an example of how not to do it. Say you have a nice address book application with an address book class in it,
and that class has a sort method in it. And now you're writing some financial application that or, or a financial part
of an overall application, in which you'd like to do sorting.


And the piece you are working on has to do with ledgers, for keeping track of credits and debits, and so on. So you'd
like to, to use the sort that's part of the address book in your ledger class. So one strategy for doing that might
merely be to have ledger be a subclass that is inherent from address book. But this would not be an example of
generalization.


An address book is not a general version of a ledger.


This would be an abuse of power. So what can you do instead?


15 - Generalization Advice
--------------------------

So how should you go about thinking about implementing generalization.


You certainly want to be able to take advantage of whatever inheritance feature is in your programming language. You
just need to stick to certain rules.


Typically, this means that in children classes, you can add features, but you don't want to take away features. And you
want to really restrict how you do any kind of overriding, in the child class. When you do want to override a method in
the child class, make sure that you obey the two following rules.


First of all, when calling that particular method, you want to make sure that the child method can accept any arguments
that the parents method could accept.


That is, the child has to be as open to inputs as the parent does.


Secondly, the output produced by the child method, when given the same arguments that were given to the parent method
should produce the same result. What we're saying with both these rules is that for the same situation in the parent,
the child needs to do the same thing.


It needs to be, a special case. Now the child can do more.


If the child is handling a special case of the parent it, it can deal with that particular special case. It just has to
always, act as if it is, it is also obeying whatever rules it specified for the parent.


16 - Generalization Quiz
------------------------

Here's a little quiz for you.


Imagine that you're concerned with two classes, Squares and Rectangles.


Do you make Square a subclass of Rectangle or do you make Rectangle a subclass of Square?


17 - Generalization Quiz Solution
---------------------------------

I would say that it depends on what you actually mean by square and rectangle.


So, if you define a square as a rectangle with both sides equal, then square is, in fact, a specialization of rectangle.


That is, rectangle is the parent class, and square is the child class.


If you defined square as a class having one attribute, which is the length of a side, and one method, for example, to
compute the area.


And, if you define rectangle as having two sides, that is an additional attribute, one for the height and one for the
width.


Then every rectangle is, in fact, a square, in the sense that it has all of the attributes the square does, and has all
the methods a square does.


So, this case, we would say that the square is the general class, and the rectangle is the child class.


The point being, you have to be a little careful what you mean by these classes, in order to decide who's the parent and
who's the child.


18 - Implementing Generalization
--------------------------------

There are a variety of different approaches to implementing generalization in object oriented languages.


One that we just alluded to, is inheritance that follows specific rules.


Second, you could just simply use a single class that has some kind of flag that indicates whether a particular instance
is of a certain type, and you might have multiple types and the fly could have multiple different, different values.


If you did that you would then be hiding the child data that particular type inside that that that class as indicated by
the flag.


In Java you could use interfaces or enums which are two mechanisms that allow you that enforce the rules that I've that
I've laid out, you can use the state pattern when we get to design patterns you'll see.


That there might be situations where you want to have some flexibility that's not provided by using strict sub-classing.


For example imagine that you're implementing a, application having to do with a library and the library might have
different categories of books.


It might have one-week books, two-weeks books, four-week books, and it would, might be natural to say well,


I'll have three subclasses of the, of the class book.


But what happens when a one-week book becomes a two-week book?


And auditory language is you can't change the class of something.


Once you've established as as being of a class, it's, it's there for ever.


So the state patterns allow, allows you to have a way to have dynamically be able to adjust the class of an object.


And then for languages like C++ that have multiple inheritance, this gives you the, the ability to specify the
properties that you wish to inherit in more than one class and be able to inherit from those classes just what you need.


19 - 4 Implementing Assocations
-------------------------------

Well that was generalization.


Even trickier than generalization is figuring out how to implement associations.


OO programming languages do not directly support associations so the OO design process must choose the best means of
implementing these associations.


Some of the factors you have to take into account, first off is directionality.


What this means is, if your program is going to need to interact with several classes, is the direction of that
interaction always in one particular way?


First A and then B or might you go in either way.


Second is cardinality.


That is for particular instance of one class are there multiple instances in another class?


And third is the kind of access you will make into classes.


Sometimes these are called the CRUD properties.


Where C stands for create, that is how you going to create instances, R is for read, that means are you just going to
query or access the, the instances,


U is for update, that is, could you change the instances and D is for delete.


Depending on, which of these particular kinds of accesses and how frequently they occur, it might particularly in the
performance area effect how you choose to implement them.


And finally as far as invariant maintenance is concerned, okay associations often have invariance associated with them.


Like referential integrity constraints and it's up to you as the designer and programmer, to build your program in such
a way that these invariants are maintained


20 - One Way Assocations
------------------------

Let's start with the simplest case.


That is, we have a one-to-one association and we're always going to traverse it in a single direction.


We can do that with a simple pointer.


Instances of class a are always going to refer to instances of class, exactly one instance of class b.


And we're always going to go from the direction from a to b.


You just have a simple pointer, which means in an object-oriented language, we have an attribute of the target type in
our, in our class.


Okay, this is quite simple to do.


And it even extends in the case where there might be multiple instances in the target class associated with a particular
instance in the source class.


In that case, instead of just using a simple pointer, we use a vector of pointers.


21 - Pointers
-------------

Here's an illustration of that process if we have an object of class Foo and it has various attributes in it. And if we
wanted to associate with each class Foo, Foo, some number of instances of class Bar, we could just have a vector in each
instance. And each of the vector elements would refer to one of the instances of the, the target class.


22 - Two Way Associations
-------------------------

Two-way associations are trickier than one-way association.


One approach is to just duplicate the approach we had with one-way associations.


That is have your attribute in class A pointing to an instance in class B and have in class B, an attribute which points
to an instance in class A.


Or you could do these with, with vectors if there's many, too many relationships.


You can use this approach if if you don't run into referential integrity constraints.


If you have referential integrity constraints, you have to make sure, for example, when you're deleting an element from
a vector in instance of class A, that you also go over and find the instance in class B.


And look in its vector to find the back pointer over to the instance in class A and make sure that's deleted.


Puts an extra burden and complexity on your program.


An alternative to having a symmetric solution is to just have pointers in one direction.


If you want to traverse in the other direction, you have to do a search.


So, let's say we'd like to go from an instance in class B to an instance in class A.


First you have to find that instance in class B and from it go back and find the instance in class A.


It's extra work.


And a third approach I want to mention is to use associations themselves as objects.


23 - Associations as Objects
----------------------------

Recall our situation where we want to loop through all of the elements in all the instances of class B.


And they're pointed to by instances of class A.


What this means is we have to loop through all the A's in order to get to all of the B's and do whatever we're going to
do with them.


This approach if which is involves pointers in one direction only can be cumbersome and costly.


Instead, you could implement the association between classes foo and bar by intros, by introducing a new class an
association class that has two attributes.


One is a name of or pointer to foo instance and the other is a pointer to the bar instance.


That is, the instances are essentially a set of pairs.


We have reified or made our association itself into an object.


It's then an easy matter to link through all the possibilities, to loop through all the possibilities, because they're
all instances of this association class.


There is a cost associated with, with doing this, it, the cost takes the form of an extra step.


If we want to go from a particular foo to a particular bar, instead of having a, a reference or a pointer directly to
it, we have to go to the association object, look up that particular instance of the foo class, find the associated
instance of the bar class and traverse in an extra step.


24 - Tables for Assocations
---------------------------

Here's what it might look like. That is, we use some kind of collection class, a hash table or a set or an array to hold
all the pairs of associated objects.


Each of the columns is going to correspond to an attribute in an instance and we have one instance for each of the links
in the original association.


25 - Associations Quiz
----------------------

Here's a short quiz for you.


Imagine that you've had an association between classes for students and classes for courses.


The association was called Take and the implication was that a student is taking a particular course.


I have four options for you in how to implement this association, and


I'd like you to give me a reason for each one which might be thought of as a disadvantage of that particular approach.


The first approach would be a reference in each Student object to a Course the student is taking.


Second option is a vector of references to students in each course.


Third is to do a, an association class containing two attributes, one for a Student and the other for a Course.


And the fourth possibility is symmetric vectors in Student and, and


Courses pointing back to the other class.


26 - Associations Quiz Solution
-------------------------------

For approach one, where we have a single reference in a student course.


The problem is that using this scheme a student can only take one course.


So for the second approach a vector of references to students in each course, this solves the first problem.


But it makes it hard to find the courses taken by a student.


That is you have pointers from courses back to students but you don't have pointers from students to courses.


And the third option was to have an association class.


And the disadvantage here, as I indicated a moment ago, was that there's an extra step involved in doing any kind of
traversal, which might have a performance hit.


And finally, the symmetric Vector approach in which there are vectors in each instance of the student class and each
instance of the course class is perfectly general, but it may lead to referential integrity problems.


That is when a student drops a course, we have to make sure that you remove that particular reference in the student
class but also in the course class.


27 - 5 Implementing Dependencies
--------------------------------

The third kind of UML relationship that we have to deal with during design is how are you going to implement
dependencies.


Dependencies are at once both the most common and the most varied kind of relationship.


Having a dependency between two classes merely means that one class somehow uses the other.


This relationship can be implemented in a variety of ways.


Most simply you can have an attribute or a global object having the type of the target class.


You could receive arguments of the target class in one of your methods.


You could make a method or construct your call to the target.


Or you could import the target as either directly or as part of a, a, a package into your class.


All of those are examples of how you're using the target in your particular implementation.


28 - 6 Implementing Control
---------------------------

The sixth issue you have to deal with in doing object design, is how you're going to implement control. Recall then, in
your analysis model, you may have some state charts. Those state charts describe the allowable behavior of objects of a
particular class.


How are you going to implement that behavior? Regardless of how you do it, recall that the state that you're dealing
with, is essentially, the possible values of the class's attributes. The ad hoc approach merely says, write the code,
okay? Treat it as each particular situation, that is each state is detected and you take appropriate events.


So you are essentially implementing by hand that, that state chart.


Fortunately, there are more productive ways to spend your time.


There are libraries that already exist that support finite state modeling, finite state implementations and you can make
use of one of those or as an intermediate step you could write your own table driven interpreter.


That is the table rows have particular situations that you're in and corresponding events or inputs that might arise and
the table then tells you what to do or what to call when that particular, that particular situation obtains


29 - 7 Abstract Classes
-----------------------

1


The final topic in object design, that I want to mention,


2 has to do with how you're going to deal with abstraction.


3


During the process of development,


4 you may wish to increase, maintainability by enforcing abstract interfaces.


5


And there are various mechanisms in object oriented languages, available for


6 you to do this.


7


For example, there are abstract methods.


8


An abstract method is essentially a method signature,


9 in a parent class that says the types of the arguments and


10 the type of the return value possibly also any exceptions that might arise.


11


Child classes then, have to provide the implementation of the abstract class,


12 obeying that particular signature.


13


Any class, with an abstract method becomes an abstract class.


14


And abstract classes can have no direct instances.


15


It's only the child classes,


16 that have implemented the particular method that can have instances.


17


Essentially then, abstract class is providing a kind of contract.


18


That all subclasses must obey.


19


Java provides, goes one step further and provides the concept of interfaces, and


20 interface is an abstract class in which all the methods are abstract.


21


For example, the serializable class is an abs, is an interface.


22


I should say that serializable interface is an interface.


23


In addition there are no non-final attributes in interfaces.


30 - Modeling to Implementation Quiz
------------------------------------

Here's a quiz matching OOA modeling concepts with the corresponding Java concepts that might be used for their
implementation.


The four OO modeling concepts are generalization, aggregation, invariants, and states.


The Java concepts that might be used for the implementation include collection classes, methods and constructors,
enumerations and subclassing.


31 - Modeling to Implementation Quiz Solution
---------------------------------------------

First, the answer for generalization is D, subclassing.


Subclassing is one way of expressing generalization relationships in code.


The answer for aggregation is A, Collection Classes.


Collection classes are designed to support aggregation.


Examples in Java include ArrayList, List, Set, and so on.


The answer for Invariants is B, Methods and Constructors.


Constructors are responsible for establishing invariants in the first place.


Subsequently, each method is also responsible for maintaining them.


And the answer for States is C, Enumerations.


Simple states can be modeled as enumerations, such as moods like happy, sleepy, sad.


Java supports adding behaviors to enumeration instances, enabling custom actions.


32 - Summary
------------

The object oriented analysis you perform goes a long way to determining what your final solution will look like. There
however some issues that arise that you have deal with before you get there. Okay many of these resolve around how best
to deal with UML elements at the associations and state machines.


They don't exist directly in the OO programming language you're going to use.


While there are many tools like design patterns, architectural styles, and design guidelines available to you. In most
cases, you're going to have to think through the tradeoffs involve before choosing an appropriate solution.


