.. title: P4L5 Design Principles 
.. slug: P4L5 Design Principles 
.. date: 2016-05-28 00:01:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L5 Design Principles
======================


01 - Design Guidelines
----------------------

At the start of this course, we mentioned that design can't really be taught, but has to be learned through experience.
That said, we have offered several ways in which we can learn from the experience of others.


Including catalogs of architectural styles and design patterns. In this lesson, we'll go over another catalog, that of
design principles. Which are informal guidelines to be judiciously applied in appropriate circumstance


02 - Design Quality
-------------------

Design guidelines are one of several ways of gauging the quality of your designs.


Of course, the ultimate validation of a design is to build a program and have its users report their satisfaction.


Short of that, you can build a prototype or conduct design reviews.


There are also various metrics based on the structural properties of your design that compute actual numbers assessing
the design's quality.


Least expensive, but conceivably most valuable, is adherence to the principles we will go over in this lesson.


03 - Design Guidelines
----------------------

A Design Guideline, also called a design principle or design heuristic, is an informal piece of advice about the
structure of a design.


With respect to objected-oriented designs, we are concerned with Design Guidelines that take the form of do's and
don'ts. We will survey some of the most well known design principles. But first, let's review several important
foundational concepts


04 - Coupling
-------------

1


Recall earlier on when we talked about coupling.


2


Which is the extent to which the module is independent, from other modules.


3


You would like the coupling of your modules to be low in order to make it


4 easier to maintain them.


5


Coupling, as a software design principle was invented by Larry Constantine.


05 - Cohesion
-------------

Another foundational concept is cohesion, which is the extent to which a module has a single purpose. You would like the
cohesion of your module to be high in order to enhance its understandability and promote its reuse.


Cohesion as a software design principle was also invented by Larry Constantine.


06 - Orthogonality
------------------

The third foundational concept to review is orthogonality. Which is the extent to which the features of a system can be
varied independently. You would like to enhance the orthogonality of your system in order to make more options available
to its users. Orthogonality also clarifies system descriptions and documentation, and supports automatic generation of
system components.


The principle of orthogonality was developed by David McGovern and


Christopher Date.


07 - Information Hiding Principle
---------------------------------

The fourth foundational concept is information hiding, which is also called encapsulation. This is the extent to which
the implementation details of a system are hidden behind abstract interfaces, thereby protecting other parts of the
program from changes to those details.


Information hiding is one way to reduce the coupling of a system.


On the other hand, the use of inheritance can violate information hiding by making parent classes implementation
details, details visible to child classes.


This principle was developed by David Parnas.


08 - Foundational Concepts Quiz
-------------------------------

Here's a quiz for you to try out what, your understanding of those four foundational concepts. In column one are the
four concepts, and in column two is an effect or benefit of concepts. And see if you can match concept to its effect, by
putting the letter for the concept into the box on the right.


09 - Foundational Concepts Quiz Solution
----------------------------------------

In terms of the first benefit in proving reusability. Well, cohesion does that by making each of the modules that you
have, have a single purpose which you can then identify and reuse that module if you have that particular need. The
second benefit is enabling maximum variability, and that's what orthogonality is intended to support. A third one, in
terms of raising the level of abstraction, is what information hiding does by preventing access to details and
implementations and finally, the fourth factor is requiring more code reading and that one is coupling if you have
highly coupled systems and then you change one of them you may have recode in many other modules


10 - Design Principles Catalog
------------------------------

We now begin the catalog and for each of the particular principles we're going to give the principle's name, its author,
a definition and the implications of its, of its use. But, before we start, please remember these are guidelines and not
hard-and-fast rules and in any given situation you have to decide which principle may or may not be appropriate and
whether just how you're going to apply it. The guidelines presented in this catalog are taken from the writings of many
different authors and more details on the sources are found on the class resources page.


11 - Liskov Substitution Principle
----------------------------------

The first principle is the Liskov Substitution Principle named after


Barbara Liskov and she proposed the principle that subclass instances should, should satisfy parent class constraints or
contracts. That is, if the client module accepts and works correctly on a parent class instance it should also work when
a child class instance is substituted.


This implies that child class instances should obey parent class invariants and method contracts including their pre and
post conditions.


12 - Law of Demeter
-------------------

Karl Lieberherr has developed the Law of Demeter, which suggest limits on the classes that can be refered to by a given
method.


Imagine that you are writing code for a method m of an object o.


Your code can refer to features of other objects or features, either in attribute or a method.


The question is, what other objects is it reasonable for you to refer to?


Answering everything can lead to typely, tightly coupled systems.


Instead of everything,


Lieberherr proposed some limits to the objects that can be referred to.


You can refer to features in O itself.


You can refer to features.


In classes that are the, the classes for the parameters that go to the MethodM.


You can refer to any objects created or instantiated within M, and you can refer to the objects O's direct component
objects, that is, its attributes.


Obeying the Law of Demeter reduces coupling, but sometimes requires introduction of extra wrapper classes.


13 - Hollywood Principle
------------------------

Donald Wallace introduced the Hollywood Principle for object oriented frameworks. These frameworks consist of a set of
abstract classes together with rules for the ways in which, their concrete subclasses may interact. These rules suggest
that calls should be made from the framework to client classes, rather than the other way around.


The pattern of frameworks calling clients is the opposite of the situation where normally a client would call the
resources in a library. Hence the principle is also called inversion of control. Wallace dubbed the principle the
Hollywood principle, after the supposed response by a Hollywood producer, to yet another unsolicited screenplay. Don't
call us, we'll call you.


14 - Dependency Inversion Principle
-----------------------------------

The next principle is Robert Martin's dependency inversion principle, which we have seen in an earlier lesson. It says
that high level modules should not depend upon low level modules. Both should instead depend upon abstractions.


This is related to inversion of control, in which normally abstraction framework classes would make use of concrete
client classes. It is the opposite to the way that modules are structured in traditional layered architectures.


Stated another way, Martin is saying that our layering should be one of abstraction, rather than one of control or data
access. Doing so will lead to designs in which the controlling principles are enforced at the highest levels of our
architecture


15 - Open Closed Principle
--------------------------

Bertrand Mayer, author of the Eiffel programming language has proposed the open-closed principle: that a class should be
open for extension but closed for modification.


The implication is that after you have released the class, any enhancement to it should be made only in subclasses. This
policy, this policy will help deal with the fragile base class problem that we mentioned in an earlier lesson.


16 - Design Principle Quiz
--------------------------

Here's a short quiz that looks at the principles we just covered.


Imagine that you have designed the following classes, one for a Motor, one for a FancyMotor, and one for a Robot.


The Robot class contains within it an attribute of type motor.


That is, it calls upon that motor to perform some computation, here called motor.run.


Assume that the Robot class is very complex, and we now want to change it to instead make use of a new FancyMotor.


Making this change will difficult with the current design because it violates which design principle?


There are five choices for you here.


There's the Substitution Principle, the Law of Demeter, the Hollywood principle, the Dependency Inversion Principle, and
the Open-Closed Principle.


Which of these is the one that's violated?


17 - Design Principle Quiz Solution
-----------------------------------

Well, the answer is the dependency inversion principle.


We've got things just backwards from way that they should be.


If we want it to be easy to make this change.


In particular, if instead of the given design, we have an iMmotor interface that motor implements and robot uses.


Then, when we add FancyMotor, we merely have to make sure it implements iMotor.


Robot doesn't have to change at all.


The solution is inverted because instead Robot depending downward on Motor and


FancyMotor, all three classes depend upward on iMotor.


18 - Interface Segregation Principle
------------------------------------

Here's another principle by Robert Martin, called the Interface Segregation Principle. Robert Martin developed this,
principle, which suggests that clients depend on an interface to a part of a large class's features rather than directly
on the large class.


Note the relationship of this principle to role-based design that we discussed earlier in the course. In role based
design, classes are synthesised from interfaces each of which reflect a role that objects of that class might play.


The implication of this principle, like that of role based design, is that class interfaces should be broken into small
pieces, each corresponding to a single use case.


19 - Reuse Equivalency Principles
---------------------------------

Several other principals proposed by Martin concern Reuse.


One of these is the release Reuse Equivalency Principle that says that the granules of reuse should be the granules of
release.


That is you should release your your software in such a way that the pieces can be individually reused. Of course, reuse
can take place at all levels so, what Martin is really suggesting is that we re, Release highly cohesive code units. In
particular, Martin suggested Java packages as a good unit of release.


The converse of this principle is the Common Reuse Principle, also by Martin.


Classes that aren't reused together should not be grouped together.


20 - Common Closure Principle
-----------------------------

Sometimes we can't hide the implementation of a design decision inside a single method or class.


It's just too big.


Martin's Common Closure Principle says that regardless of the level of granularity that we are forced to use, we should
group the related elements into a common release unit.


In Java, this would typically be a package.


Stated succinctly, this principle says that classes that change together, should be released together.


21 - Dependency Structure Matrix
--------------------------------

The next few principles make use of a device called a dependency structure matrix or DSM. This device was devised by
Baldwin and


Clark, to deal in general with management of design changes.


A DSM is a Boolean matrix in which the rows nad columns correspond to components with a one in a cell indicating that
the component in a given row depends on the component in the given column. Note that the order of rows and columns
doesn't matter to the information conveyed. So we can feel free to permute them, in order to produce more meaningful
views.


22 - Lattix Image
-----------------

1


Here is a screen capture from a tool called Lattix, that can construct these


2 dependency matrices from code and point out violations of various principles.


3


The Lattix tool provides several interesting features.


4


On the left hand side of the image,


5 actually is conveying the hierarchical structure of the system's components.


6


This hierarchical structuring can be dynamically specified by the user.


7


So within the left hand column there are some sub columns.


8


The ones on the extreme left, contains the ones that are just to the right of


9 that, which contains the ones just to the right of that and so on.


10


In the Lattix version of the DSM, here shown,


11 the numbers in the cells are not just zero and


12 ones, they are integer values which indicate the number of dependencies.


13


More over, the user of the tool can specify the kinds of dependencies and


14 get numbers for each of the different kinds.


15


The red triangles on some of the cells indicate violations of


16 user specified design principles.


17


And, the internal brown squares that subdivide the overall


18


DSM indicate candidate modules having no violations.


19


The user can construct such modules, by suitable column and row permutations.


20


And once you've done that and you can then focus on the remaining cells that


21 have violations and try to get the whole matrix to be violation free.


23 - Acyclic Dependency Principle
---------------------------------

Martin's Acyclic Dependency Principle states that the dependencies between packages must not form cycles. Expressed in
terms of D.S.M.'s this says that you should be able to permute the rows and columns of the D.S.M. in such a way that the
transitive closer of the matrix is lower triangular.


What this means is that there's a strict ordering among the Components, such that a Component only depends on other
components beneath it, and never on one above it. A violation of this property is seen in a system where component A
depends upon component B, and component B depends directly or indirectly on component A.


Not only is it difficult to maintain such systems it is even hard to understand them in other words, you can't
understand A without understanding B, and you can't understand B without understanding A. There are several ways to deal
with violations of the Acyclic Dependency Principle. If you have a situation where A depends on B and B depends on A,
you can invent a module C, take the part of A that B depends on and place it in C, and have both A and


B depend upon C. Another way to break the cycle where the packages are siblings is to add an interface class into b and
have a implement it.


24 - Stability
--------------

Martin uses the term stable to mean hard to change. Or, if you try to change it, it's going to have many implications.
Typically, a module's hard to change if a lot of other modules depend on it. Martin's stable dependency principle
suggests that you should depend in the direction of stability. In other words, no package should be dependent on
packages that are more likely to change than it is. This principle is similar to the previous one, that is, you should
depend downward and not introduce loops into the dependency hierarchy.


Note that we usually think of the term stable as a positive term but Martin is treating it as undesirable. A corollary
to this stable dependency principle is Martin's Stable Abstraction Principle in which stable packages should be abstract
packages. The idea is that they're hard to change but easy to extend.


25 - Bad Smells
---------------

Kent Beck and Martin Fowler popularized the notion of refactoring as part of extreme programming in the 1990s. The idea
was to move some design activities that were previously done before implementation was started into the actual
implementation phase of development. The intent was to reduce rework in situations with rapidly changing requirements.
The first step in refactoring is the recognition of bad smells, which are code situations that are suggestive of design
problems, such as duplicate code, too many comments, or long classes. So you can think, bad smells as being, things to
avoid in other words, design principles describing situations which you, you don't want to be in.


The Fowler's book recognizes dozens of bad smells and the avoidance of each should be, could be thought of as a design
principle. For example, the duplicate code bad smell should be thought of as the avoid duplicate code by factoring
principle. You're encouraged to explore Fowler's book as a way of becoming familiar with these situations, it is
referenced in the class resources page.


26 - Design Heuristics  Riel
----------------------------

Another participant in the development of design principles is Arthur Riel, whose book is titled Design Heuristics,
referenced on the class resources page.


Here are some examples of Riel's heuristics.


You will notice the overlap with some of the principles, principles that we have already talked about.


These particular heuristics don't have names that are catchy like the but they do exhibit.


Advice to you about situations that you want to avoid or ways of structuring your code that you want to try to promote.


First one is, most of the methods defined on a class should be using most of the data members of the class most of the
time.


Otherwise there's an opportunity to split the class into pieces that indi-, individually obey this principle.


Another Riel Heuristic, check constraints in constructors, rather than in method preconditions where possible.


Following this principle will reduce the overall amount of checking that needs to be done by the class.


Another Heuristic, factor the commonality of data, behavior, and interfaces as high as possible in the inheritance
hierarchy, thereby facilitating reuse.


This of course is standard O-O dogma.


Here's another Riel heuristic.


Inheritance should be used only to model a generalization hierarchy, hierarchy and not to facilitate the sharing of
implementation code.


We've heard this one many times in this course.


Another prefer composition which we can also think of as aggregation or delegation.


Over inheritance.


Particularly with respect to implementation inheritance.


Another.


It should be illegal for a derived class to override a base class method with a no-op method.


That is, essentially, a method that does nothing instead of the behavior that the base class prescribes.


Doing so, by the way, would violate the substitution principle that we saw earlier.


Riel also suggests that we not change the state of an object without going through its public interface.


Doing so would violate information hiding.


If we, kind of extend this idea to deal with, subclassing, and we strictly obeyed it, this heuristic, it would mean that
a method in a class cannot change an instance variable without calling the setter.


Method in that class.


That is, you couldn't make a direct assignment to an attribute.


You'd have to call the setter which did it.


And another Riel principle, users of a class must be dependent on it's public interface.


But a class should not be dependent on it's users.


Finally here are two Riel heuristics indicating how you should distribute key design knowledge among the components of a
system.


Distribute system intelligence horizontally as uniformly as possible.


That is, don't artificially concentrate knowledge in one place.


This heuristic is sometimes expressed as, do not create God classes, or


God objects in your system.


A corollary heuristic is to distribute system intelligence vertically down narrow and deep containment hierarchies.


You're, I encourage you to have a look at Riel's book, where there's many more such pieces of advice.


27 - Single Choice Principle
----------------------------

In procedural code, systematic variation is often dealt with via case statements or else-if cascades. In object-oriented
code, this approach is considered a bad smell. Instead, you should use parallel, factored subclasses with the choice
specific code embodied in a subclass method.


This approach is called the single choice principle.


28 - Transparency and Intentionality
------------------------------------

I want to end the catalog by mentioning two other principles that I have gleaned from my personal work. Transparency and
intentionality.


29 - Transparency
-----------------

Of course, we came across transparency when we talked about middleware and we listed various kinds of transparency that
was appropriate to middleware situations. In general, transparency suggests providing interfaces that enable client code
to be written without having to be concerned with specific details.


Of course, this generality comes with a cost of extra design and testing work.


30 - Intentionality
-------------------

The last principle that I would like to mention to you is also the most abstract one. It is called the Principle of
Intentionality. That is, design your software in such a way that your intent is manifest and localized in the code. What
this means is that the conceptual distance between the problem that you are trying to solve, and the code with which you
are solving it is as small as possible.


Intentionality supports traceability, validation and maintainability. You can improve intentionality by appropriate use
of cohesion, and naming conventions.


31 - Principles and Heuristics Quiz
-----------------------------------

1


Here's a quiz that covers the various principles that we've seen in the catalog.


2


James Gosling was the author of the Java programming language.


3


At a Java users group meeting he was asked,


4 if you could do Java all over again, what would you change?


5


He replied, I'd leave out classes.


6


This, of course, got a lot of laughs, and


7 after the laughter died down he went on to explain what he meant.


8


I'll turn it around and ask you, which of the principles or heuristics that have


9 been mentioned in this lesson, support Gosling's idea about leaving out classes.


32 - Principles and Heuristics Quiz Solution
--------------------------------------------

1


There're actually several relevant principles,


2 such as the Liskov Substitution Principle,


3 the Interface Segregation Principle, the Stable Abstraction Principle.


4


Riel's Inheritance, should be used only to model a generalization hierarchy.


5


All of these express Gosling's belief that inheritance should not be


6 used share implementation, but


7 instead use implementation of interfaces to share abstractions.


33 - Summary
------------

I recognize that a catalog of design principles is too abstract to be immediately useful to you. I hope, however, that
by being made aware of these principles, you'll be sensitized to problematic situations when they arise.


You can then look up the relevant principle and it's suggested solutions to help you resolve the issue that you you've
seen.


