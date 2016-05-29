.. title: P4L4 Design Patterns 
.. slug: P4L4 Design Patterns 
.. date: 2016-05-28 00:00:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L4 Design Patterns
====================


01 - Design Experience
----------------------

The single most important predictor of a successful software design effort is the extent to which the development team,
staff, have experience on similar problems.


Because we all want to participate in successful projects, access to that experience is crucial.


One key source of such experience is familiarity with applicable design solutions.


A design pattern is just that.


A description of a solution to a problem in context.


What this means is that for a given problem, a design pattern provides a way of solving it, including a description of
the issues and tradeoffs involved.


Situations where the solution applies, options that you as a designer have, consequences of using a solution, and any
implementation issues.


Thus, design patterns are reusable design experience.


02 - Architectural Patterns
---------------------------

A concept of design patterns actually arose in the field of the design of buildings, architectural design. In the 1970s
Christopher Alexander wrote an influential book called A Pattern Language, in which he described various patterns which
arise in the course of architecting buildings. For example, think about most of the public buildings that you've
entered. You enter into an area called an atrium. Aside from enabling the entrance to orient themselves spatially, an
atrium provide psychological and aesthetic means for adjusting to the building's purpose. Alexander's book describes
many such patterns.


03 - The Gang of Four
---------------------

In 1995, four master software designers documented their knowledge in a now classical book called Design Patterns. They
were Gamma, Helm, Johnson, and


Vlissides. Because of the number of the authors, this book is sometimes called the Gang of Four book, or simply GOF.
After the publication of GOF, the idea of Design Patterns caught fire in the software design community. And books and
websites have been publishing a variety of related topics, including analysis and refinement patterns. As well as
programming language specific pattern catalogs. And even a book on anti-patterns, which are common problems to avoid.
The resources page, of the class includes a citation of the Gang of Four book as well as Alexander's book.


And a pointer to a website which has a catalog of such software design patterns


04 - Definition
---------------

What is a software design pattern?


A design pattern is a solution to a problem in context.


According to GOF, this amounts to a description of communicating objects and classes that are customized to solve a
general design problem in a particular context.


Thus, design patterns are a means of capturing and reusing design knowledge.


We'll look first at an example of a particular simple pattern called the composite pattern.


05 - The Composite Pattern
--------------------------

The problem that the composite pattern addresses is how to organize information about whole parts relationships. That
is, situations where you have to keep track of data about things and their parts.


This is a common problem in software development. Think, for example, about user interfaces which are built from widgets
such as windows, menus and forms. That are made by, made up of other widgets, text boxes, dialogues, color choosers, and
so on. Other examples of composites include web pages made up of frames, pictures, texts, and links. Documents made up
of chapters, tables, diagrams, and paragraphs. And UML diagrams made up of boxes and lines.


06 - Composite Classes
----------------------

GoF is concerned with object-oriented design patterns, those that support building systems using object-oriented
techniques.


Patterns in the GoF book are presented in a stylized fashion, including one or more UML diagrams, primarily class model
diagrams, objects, diagrams, and sequence diagrams. The class model diagrams for the composite pattern comprises four
classes. Client class, component class, leaf class, and composite class.


07 - Composite Client Class
---------------------------

Let's start with the simplest class which is the client class.


That is the class representing all of the possible uses of the composite pattern in some systems.


08 - Composite Component Class
------------------------------

The client interacts with the rest of this pattern through an abstract interface.


For example, if your application provides the end-user a way of drawing diagrams, then the abstract interface might have
the name Graphic.


If you were modeling an organization and its employees, you might use the term Unit.


To indicate the general nature of the pattern, GoF uses the term component.


In the diagram you can see that the client class talks to the component class, and that the component class is abstract
because its name is in italics.


The component class has a variety of operations as well as the ability to add and remove children and access any of the
children of the component that exists.


09 - Leafs and Composites
-------------------------

To the client, the value of the composite pattern is that it can treat all elements if the data one way using the
component abstract class.


That is where the component can contain other components, which is called a composite, or it's treating components that
don't have other components, which are called leaves. Need not be dealt with as far as the client is concerned. For
example, a graphic may be a line or rectangle. Which are Leaves, or it might be a picture containing other graphics
which would be a Composite.


Note that in the diagram Leaf and Composite are subclasses of Component.


10 - Aggregation
----------------

There is one further element to add to the class model for the composite pattern. It is an aggregation line from
composite back to component. That is a composite can be made up of further components, there by allowing for hierarchies
of any depth.


11 - Textual Content
--------------------

The class model diagram gives you the overall essence of the composite pattern, but it isn't by no means the complete
expression of it.


The pattern's textural doc, documentation consists of several other valuable pieces of information. Note that each of
the patterns in the Gang of Four book is formatted in a similar fashion, including diagrams, such as what we just saw,
and a structured, textural description.


12 - Intent and Motivation
--------------------------

We'll now go through each of the structured paragraphs in the Gang of Four description of the composite pattern. First
off is intent, which is a summary of the value provided by the pattern. The intent of the composite pattern is to
describe a way of representing whole-parts hierarchies in such a way that, that the client treats individual parts and
composites uniformly.


The next section of the description is called the motivation section, and this typically takes the form of a scenario,
or story demonstrating that having a problem, having such a solution would be valuable. Earlier, we used Graphic as an
example. Clients of Graphic shouldn't have to test elements to see whether they are leads or composites, if all they
want to do is copy them, for example.


13 - Applicability and Structure
--------------------------------

The next section is called applicability, which includes important design considerations that the pattern addresses.
Stated another way, this is the context in which the sol, solution can apply. The next section is the structure, which
consists of the diagram we've already seen.


14 - Participants
-----------------

After the structure description in the diagram is a section called participants, in which each of the classes in the
descri, in the diagram is described as far as what its role is, what role it plays in the overall operation of the
pattern.


In our case, we had a component, we had a leaf, we had a composite, and we had the client itself. Each of those plays a
particular role with respect to the overall operation of the composite pattern.


15 - Collaborations
-------------------

After the participant sections come the collaborations sections.


Collaboration is how the participants work together to accomplish the pattern's goals.


The composite pattern is an example of a structural pattern.


One in which the organization of the information provides the primarily, the primary value added.


For structural patterns, collaboration plays a less important role than structure in providing information to the
designer.


Nevertheless, understanding inter-element behavior is important.


For example, with the composite pattern, a typical behavior is to have the composites iterate through their children,
performing some operation on each.


16 - Consequences
-----------------

The next section is called Consequences. Which are the advantages and disadvantages of using the pattern. One of the
most important elements of the pattern description is an understanding of what tradeoffs using the pattern entails. For
example, the composite pattern makes the client interface simple at a possible cost of safety. That is, if we were to
refactor the add operation into component. To make the interface more uniform to clients, this might mean that leaves
can have children. Which wouldn't make any sense unless we put in some kind of ugly check to prevent it.


17 - Implementation Alternatives
--------------------------------

The next section in each pattern description talks about implementation.


The design pattern that we've, understood so far has to do with the design of a solution.


Not necessarily It's implementation.


Implementation means translating that design into some code.


Okay?


Doing that often means that there are choices arise.


And it's important to understand the implication of the those choices.


The implementation section of a design pattern description lays out those implementation issues, and alternative ways of
addressing them.


For the Composite pattern, here are some of the issues that arise.


We know that in the pattern so far, we have references from parents to children.


An issue that you might wish to include, or a feature you might wish to include is, do you have pointers from children
back to parents.


Once you do this, of course, referential integrity problems might arise.


Another issue is whether we would allow multiple parents to refer to the same children.


Imagine that you have separate hierarchies in which the leaf elements are shared.


This, of course, can be powerful if you wish to do it because it reduces the overall number of objects that you have.


But it might also increase your code complexity if you were to do that.


Similar to the situation where we just described in which moving the add operation up in the hierarchy has the benefit
of making the uni-, the interface more uniform.


However, it might lead to having unnatural operations at too high a level in the hierarchy.


Similarly placing the list of children up one level, also would mean that somehow now leafs at children.


Now, the issue is what data structure should you use to keep the list of children, their hash tables, their arrays,
link, lesson, so on.


Finally is the question of whether, when you delete a composite, do you also delete its children?


18 - Patterns and UML Quiz
--------------------------

Which leads to the following question.


We all know class model diagrams distinguish associations in which the leading collection deletes its elements from
those that don't. The question for you is, what is the visual indication of the former, that is, the situation in which
deleting a collection deletes its elements?


And I give you four choices. A triangle on the end of an association line, an asterisk on the end of an association
line, a filled diamond on the collection end of the line, and a delete operation in the class itself.


19 - Patterns and UML Quiz Solution
-----------------------------------

Well, if you recall the answer is a filled diamond on the collection end of the line.


20 - Code, Uses, and Related Patterns
-------------------------------------

Patterns in GoF have three other sections. One is sample code and this may be the largest section, in which in a variety
of languages including C++ and


Smalltalk examples of coded uses of the pattern are included.


As a side note, this particular book was written before Java become popular, so there are no java examples. However
there are other books which include java solutions to similar pattern problems. Next section is known uses.


As I said the authors of GoF were master designers and they had themselves had written [or were familiar with many
important object-orientated systems. And they indicate which system use which patterns in this section of, of each
pattern description. And finally, in the final section is related patterns.


That is, how the given pattern relates to other patterns. Turns out that elegantly written applications often use
multiple co-operating patterns.


This is sometimes called pattern density. This section of the book lists other patterns which might be used together
with this pattern.


21 - Composite Pattern Quiz
---------------------------

Here's another quiz for you. Imagine that you are writing an application to manage parts inventories. That is, inventory
management application.


Match the class name from the composite pattern given in column one with the corresponding application data described in
column two.


The classes are Client, Component, Leaf, and Composite. The particular pieces of data are, a description of a
StainlessSteelHexBolt, three eights inches.


Some OutOfStockDetector, indicating you might have to reorder.


InventoryItem class, and the BlueBirdBoxKit.


22 - Composite Pattern Quiz Solution
------------------------------------

An example of a client class here, might be an out of stock detector. That is, you have an application that's going
through your inventory, trying to find places where you might have to reorder. The component class here, is inventory
item. That is, it's an abstract class of which all of the parts subscribe. An example of the leaf class is this
stainless steel hex bolt.


An example of a composite class, might be the BlueBirdBoxKit. Which is itself made up of other parts.


23 - Categories
---------------

Well, that was an example of a gang of four structural pattern, in fact the, the book has three categories of patterns.
In structural patterns, the main value added is the description of the various classes and how they're connected to each
other. The book also has a category called creational patterns, that describe ways in which objects can be constructed.
The largest and most interesting part of the book has to do with behavioral patterns, which describes interesting
interactions, interesting ways in which classes interact to accomplish some particular goal. We will now take a minute
to look at each of these three categories beginning with the creational category.


24 - Creational Patterns
------------------------

The book describes five creational patterns.


Their names are singleton, prototype, builder, factory method and abstract factory.


In a minute we will look at the singleton pattern.


The prototype pattern is a way for designers to make use of a different kind of inheritance.


Most object oriented languages provide class based inheritance.


But some languages like LISP, provide a different way to inherit.


Instead of inheriting from classes, you inherit from other objects.


The prototype pattern tells you how you might get that same facility within a class based language.


The builder patterns gives you a way of separating the actual construction of the object from how it's pieces are built.


Factory method is a way that lets the sub classes decide which class to instantiate.


The framework as a whole merely ask for creation.


Specific creation is done by a concrete factory.


And if you want to apply this method to a set of related classes, you can use the abstract factory pattern.


For example, user interface tool kits may allow you to specify the look and feel of a set of widgets, and the abstract
factory has a way of accomplishing that.


25 - Example Creational Pattern  Singleton
------------------------------------------

We're going to go a little, into a little bit more depth with respect to the singleton pattern and provide you an
example of it.


Singleton's provide you a way to ensure that a class has only one instance and to provide a global point of reference to
that particular instance.


As far as motivation is concerned, consider the top level of your architecture where there may appear components that
should only have one instance.


For example, a database or a log-in manager.


How do you guarantee that only one such instance exists?


26 - Applicability and Structure
--------------------------------

For the single [UNKNOWN] the applicability is fairly obvious.


There must be only one such instance of the class, and it's must be accessible to clients from a well known place.


As far as structure is concerned, there is a single class called here, singleton class, but it can be whatever name you
want to supply.


The singleton class has two particular attributes. One of which is static or sometimes called a class attribute. That
is, it's an attribute of the class and not an instance of the class. Here it's called unique instance.


There may also be whatever data you'd like to have within that singleton as other attributes of the class. The singleton
class also has some operations, and one of those operations is a class method.


That class method is responsible for retrieving for the client the particular instance which is the only instance of the
singleton.


There of course may also be operations within the singleton like there could be in any other class for providing access,
for example, to the other data that's there or doing whatever operations you'd like that singleton to do.


27 - Participants and Collaborations
------------------------------------

As far as participants are concerned there's only one participant it's the singleton, it's responsible for it's own con,
construction and it defines a class level instance operation, lets clients access it's unique instance. Collaborations
are also minimal.


The clients access the single instance through that class method


28 - Consequences
-----------------

There are several consequences of using a singleton pattern.


One of the benefits is, you provide controlled access.


The only way to get access to the singleton instance is through that, that class operation. This has the potential of
reducing problems with the names, the program name space. In particular, the alternative would be to have one or more
global variables that refer to the instance.


Once you've got global variables, they can be copied, and, and, and referenced. Thereby leading to potential problems.
Because singleton is a class, it can be subclassed, which gives you additional flexibility. And if you were so inclined,
you wanted to have a, a class in which there could be exactly two instances or three instances or four instances,
whatever.


Okay, you could take the basic idea of the singleton and adjust it accordingly.


29 - Implementation
-------------------

In order to implement the singleton pattern, the first thing you do is define a class variable holding the instance.
Then, you can define a class operation that creates the instance and saves a reference to it in the class variable.


The operation checks whether the instance already exists and if not creates it.


In order to protect yourself from creating other instances in implementing the Singleton pattern you make the
constructor private or protected.


30 - Implementation Issues
--------------------------

Because access to the singleton is through a class, and class names are normally known globally, singletons somehow,
sometimes act like global state instead of the traditional owned instances that we see in other uses of, of classes in
object-oriented languages.


We can also run into trouble in situations where the clients are multithreaded.


That is, several threads may be trying to create that single instance at one time.


Leading to the production of multiple singletons.


Question arises as to when you create the single instance.


One strategy is to do it at startup.


Which you could think of as eager construction.


Or do you wait until the first use to, to create it, which could be called lazy construction.


Then some issues with respect to what it actually means to be a singleton.


Does singleton a word mean at most once or exactly once?


Similarly, does singleton mean only one ever or only one at a time?


In languages with destructors, like C++, you could get rid of the instance and then later create another instance of
that same singleton without violating the rule that there's at most one such instance.


31 - Singleton Quiz
-------------------

Although they sound simple singletons are actually somewhat controversial because you can run into problems.


Here's a little quiz that might get you into understanding what that problem is.


Say you were in the process of writing a battery of unit tests for an application that you intend to run frequently
during development.


And that implementation might have use of some singletons.


The question is what difficulties do singletons impose on such testing approach.


32 - Singleton Quiz Solution
----------------------------

If the tests are being run by a testing framework such as JUnit, in which a single process is involved in running a
batch of tests.


You have difficulty keeping the tests independent.


That is, each of the tests might like to have its own unique copy of that particular Singleton to test against.


This violates the principle of what a Singleton is.


33 - Structural Patterns
------------------------

The next category of patterns, in the Gang of Four book, are the structural patterns of which the composite pattern is
example we've already seen.


Some other ones that are provided include the adapter pattern which you would use to convert an existing interface to
look like another interface.


The bridge pattern, in which you decouple an abstraction and implementation.


The decorator pattern, in which you would add a single feature to an existing class. The facade pattern, which provides
a higher-level interface for a subsystem. This might typically be used in a situation where you have some non-object
oriented legacy code, which you'd want to access from within an object oriented application. And you need to make it
look like an object oriented interface. The flyweight pattern allows you to use sharing to support large number of fine-
grained objects. So imagine a situation, for example, when you're doing text processing, and each of the characters
you'd like to treat as an object. Well, this can be quite expensive, because, because, there, because be tens of
thousands of such objects. Instead flyweight, allows provides you a way of doing this without creating all those
objects.


Finally the proxy pattern allows you to control access to an object.


34 - Behavioral Patterns
------------------------

The third category of patterns described in the book, comprised the behavioral patterns. As you might guess, usually
these are the most complex patterns and hence the most powerful ones.


Behavioral patterns, describe interesting ways that objects can interact.


35 - Catalog of Behavioral Patterns
-----------------------------------

The gang of four book, includes descriptions of 11 behavioral patterns which I briefly survey here, and then we have an
example of one.


First of is the chain of responsibility pattern which allows you to separate a request from the mechanism by which the
request is handler, and also allows for you to have multiple handlers for a given request.


Second is the command pattern, which takes what sounds like a verb, and converts it into a noun. That is, you can have
objects that represent commands.


Third is the interpreter pattern, which is quite complex because it provides a mechanism, essentially, to have an
interpreter for a language. You can represent the grammar and interpret its instances based upon whatever operations are
expressed in the language. Next is the iterator over enumeration pattern of course, now languages like Java and


C++ have iterators and enumerations. But at the time the book was written, they weren't part of the language and hence
they were described there, you might think of, the occurrence of that pattern in the book as a motivation by which the
eventual feature was added to the other programming languages.


A Mediator pattern is a powerful way of encapsulating object interactions, into an object. The Memento pattern captures
an object's internal state for later restore. Think here about undo and redo, you want to capture the state so you can
go back to it if you do an undo. Next is the Observer pattern, sometimes called the Listener pattern, which is a way by
which classes can notify dependent classes when an object changes. The state pattern is an interesting one, in which
we've alluded to before, that you could use in situations where you might like to change the class of a particular
object.


Example I think we gave before had to do with library books, in which they went from being one week books to two week
books to four week books. Of course, in most object oriented languages you can't change the class of a object,


State Pattern is a way of doing that.


The next pair of classes are often useful for representing algorithms.


The Strategy Pattern is a family of algorithms with the same purpose and interface. An instance of the pattern is a
specific algorithm.


Related to that is the Template Method Pattern, which is a skeleton of an algorithm with hooks for the specific step.


Finally, the Visitor pattern is a way of applying a method to elements in the structure and we're going to use this as
an example of a behavioral pattern.


36 - Visitor Pattern
--------------------

The Visitor Pattern is a popular way of navigating a complex data structure applying item-specific operations. Moreover,
Visitor is a natural complement to Composite, which we saw earlier. That is, the data structure being navigated by the
visitor can often be represented using a, a composite class.


37 - Vistor Pattern Description
-------------------------------

The intent of the visitor pattern, is to vary the operation to be performed on the elements of a complex structure,
without changing the classes of the elements of the structure itself.


As an example use, imagine that you have an abstract syntax tree, it might be in a compiler, useful for representing a
program.


You might wish to walk the tree for various reasons.


For example, to generate code, to pretty print the, the program or to do type checking.


This would result in three different visitors, all walking the same composite data structure.


The motivation that the pattern addresses is to be able to decouple the structural elements that is, the data
structures.


From the operations applies to them.


You think about this.


This means that there are two factors that control how you are applying the operations.


One is the data structure itself which may have, may, may have many different kinds of nodes.


And the other is the class of operations such as, the code generation, pre-printing, and type checking


38 - Visitor Applicability
--------------------------

You would want to use the Visitor pattern. If you need to perform several different categories of operations on the
elements of a complex structure.


And you want to simplify the element code by factoring out these operations. For the Visitor to be a value, the data
structure would be relatively stable.


You wouldn't want to change it very much because that would, that would break the overall structure. However, the
operations can change, you can add new ones without, without breaking the overall structure of the system.


39 - Structure
--------------

Here's a picture of what the visitor pattern looks like, there of course is a client class, which is going to lead the
operations to be applied.


And then two categories of other classes.


One is a category having to do with the data structure itself and the other is a category of classes having to do with
the visitors.


As far as the data structure is concerned, there will be some kind of abstract element and then concrete elements
corresponding to the different parts of the data structure.


The abstract element provides an abstract method called accept with an argument visitor.


That is, as you are navigating through the data structure and you want to apply the operations you send the visitor, as
an object, to each of the elements you come to.


And it must accept that visitor, and essentially call back to the visitor to perform the operations.


40 - Comments on Structure
--------------------------

If we were talking about using the viter, visitor pattern inside a compiler, then the concrete visitors might one might
do type checking, one might do pre-printing, and so on.


And, the concrete elements might correspond to things like assignment statements, or declarations, or other parts of the
Code.


The object structure class, itself, represents the parse tree as a whole, and is your starting point for doing the
navigation through the structure.


41 - Visitor Participants
-------------------------

There are five sorts of classes involved in the visitor structure.


The participants, one is of course, the visitor itself, which is an abstract class declaring a visit operation, that is
then applied by each of the concrete elements.


ConcreteVisitors are specialization of the visitor class, implementing an operation on each of the concrete elements.


And, in addition, they may store local state, that is, if your navigation wants to accumulate statistics, there's a
place to do that accumulation inside the ConcreteVisitor.


The Element class is an abstract class declaring the accept operation that takes a Visitor as an argument.


It is sub-classed by Concrete Elements, representing the various different kinds of nodes in the complex data structure,
and each of those elements takes an except operation with a Visitor as an argument.


Finally, the fifth of the classes is the Object Structure class, itself, which usually provides a way of enumerating the
various elements, serving as the root of the data structure itself.


42 - Visitor Behavior
---------------------

The Visitor pattern is an example of a behavioral pattern.


And in order to describe the behavior, we use a sequence diagram in this case.


Recall that in the sequence diagram, each of the columns corresponds to a different object.


The horizontal lines correspond to messages being sent among the objects.


And that time marches down the page.


The first column in the diagram corresponds to the data structure itself.


And it is responsible for sending messages to each of the concrete classes, and those messages are accept messages
passing in whatever visitor we currently want to implement.


The concrete classes are in the second column.


Their responsibility is for doing the callback.


That is, they are given a visitor as an argument and they need to pass themselves to the particular visitor operation
responsible for whatever visitor they're currently implementing.


Those are the messages at the top which go from the second column over to the fourth column and in the middle of the
screen from the third column over to the fourth column.


Finally, in the visitor operation itself in the fourth column, can make calls back into the elements, taking advantage
of whatever operations those elements provide.


43 - Visitor Collaborations
---------------------------

As far as collaborations are concerned, the client is responsible for creating instances of a concrete visitor object.


And traversing the object structure. The visited concrete elements, called the visit operation. With self as an
argument.


44 - Visitor Consequences
-------------------------

The visitor pattern is quite powerful and popular however there are some issues with it. First off the implementation of
the operations are placed in a different place from the Elements being operated on.


It means that the operations are kept together. The elements are kept together but in a sense encapsulation is
compromised because those two are separated.


Second consequence is that adding new operations is straightforward, you just have new classes on the visitor side of
things.


In a sense you are actually extending the operations on a class without changing the class itself on the other hand
adding new element types is hard.


This would break the data structure and cause a lot of reprogramming.


Final consequences, if you need to, visitors can accumulate state as I indicated before an example would be collecting
statistics.


45 - Visitor Implementation
---------------------------

Couple of issues arise with respect to visitor pattern.


First off, if you think about it, the actual operation called at any time is dependent on two things. An element such as
assignment statement and a particular visitor such as type checking. This dependency is sometimes called double
dispatch. It most of object oriented languages you're familiar with, there's single dispatch. That is, you send a
message to a particular object.


That, whatever method responds to that message, depends on what object you're sending it to. In languages like Ada, the
determination of who's going to handle a particular message is determined not just by one argument, but by all the
arguments. Here we're looking at a situation where we're going to make that determination on what operation we're going
to apply based upon two arguments.


Second issue is, who is responsible for performing the actual traversal, if we're talking about a compiler what we want
to do is a tree walk and there are variant, various variants of tree walks. We can place the code to perform that tree
walk in several places. We can place it in the ObjectStructure class, in the Visitor class, or we can have some kind of
Iterator object.


46 - Pattern Quiz 1
-------------------

Which design pattern does the following object model represent?


Enter your answer in the text box.


The design pattern listed here includes three classes, one labeled Application, one labeled Wrapper, and one labeled
LegacyComponent.


47 - Pattern Quiz 1 Solution
----------------------------

The answer is the adapter pattern, which is responsible for altering the interface that an object provides to conform to
the needs of its clients.


Often these clients comprise legacy code that cannot be readily altered.


48 - Pattern Quiz 2
-------------------

Which design pattern does the following object model represent?


Enter your answer in the text box.


The design pattern features five classes, a reader class, an abstract converter class, and three concrete converter
classes.


49 - Pattern Quiz 2 Solution
----------------------------

The answer is the builder pattern which isolates the steps involved in constructing a complex object from the
representation of that object.


50 - Pattern Quiz 3
-------------------

Which design pattern does the following object model represent?


Enter your answer in the text box.


The pattern comprises seven classes.


There's a Client class and an abstract class called Collection, which has two subclasses, ListCollection and
MapCollection.


There is also an abstract Traverser class with four methods, and two subclasses, a MapTraverser and a ListTraverser.


51 - Pattern Quiz 3 Solution
----------------------------

The answer is the iterator pattern which is responsible for traversing a collection, applying some action to each
element.


This enables clients to visit each element without necessarily knowing how the collection is implemented.


Of course since the time of publication of the Gang of 4 book iterators have been added to the java and C++ languages


52 - Problems with Patterns
---------------------------

As I said earlier the Gang of Four book was immensely popular and has spawned a whole, a whole movement within the
software development community.


However, patterns are not without problems and


I want to look a few of them here. These come from Czenecki and


Eisenhecker book which is listed on my class resources page. First off, patterns are primarily implemented using, using
two standard object-oriented compo, compo, composition mechanisms, inherit inheritance and object composition. But using
patterns can add complexity. Often, there's the introduction of extra objects and extra levels of indirection. So your
code becomes more complicated even though you're using standard techniques.


53 - Problem Area Object Schizophrenia
--------------------------------------

Second problem area is sometimes called object schizophrenia. And this is, an example of this was the visitor pattern,
where we split off the functionality having to do with the elements into a separate place where all the operations were
contained. In a sense, this beaks delegation.


It has also been called the self problem. When you delegate responsibility to perform part of a computation to methods
in your attributes, as opposed to handling them yourself. This can lead to additional complexity, particularly when
you're trying to debug and find out where something went wrong.


54 - Problem Area Preplanning Problem
-------------------------------------

Another problem has to do with the fact that in planning your applications, patterns are only useful if you know enough
in advance to include them in your plans. What do you do if you're part way through the development of your system and
you realize that you should be using a particular pattern. Well, you can use refactoring to get you there but the only
real way to deal with it is to become quite familiar. With the catalog of patterns. So that you can a, think about them
in advance in order to apply them when you need them.


55 - Problem Area Traceability Problem
--------------------------------------

A final problem I want to mention can be called the Traceability Problem.


The code of the program that uses a design pattern does not necessarily make explicit that you're actually using the
pattern.


You don't have to use the names of the classes taken from the book.


And, as you saw, there were lots of options with respect to implementation.


Consequently, somebody reading the code may not realize you're using a pattern.


Therefore, there's an extra obligation on you as a developer for documenting and using certain naming conventions, so
it's obvious what's going on.


If you're not careful, this can lead to increased the failure to do this documentation can lead to increased
fragmentation of the code, having to do with the additional classes and methods which patterns introduce.


56 - Summary
------------

To conclude, patterns are an essential part of developers' vocabularies.


We simply must be aware of what's there in order to take advantage of it.


However, patterns are difficult to learn passively.


You can read all the catalogs you want. But unless you actually get some experience with catalogs, they're not going to
be, come to mind readily when you're in a development situation. However, despite these costs and potential problems
that might arise from using patterns, they are so powerful that you want to take advantage of them when you can.


