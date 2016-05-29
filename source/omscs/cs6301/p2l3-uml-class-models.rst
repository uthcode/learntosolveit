.. title: P2L3 UML Class Models 
.. slug: P2L3 UML Class Models 
.. date: 2016-05-27 23:40:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L3 UML Class Models
=====================


01 - Introduction
-----------------

In the previous lesson, we talked about object-oriented analysis, the process by which you can begin to come to
understand the problem you're trying to solve.


Today, we're going to talk about how would you express the results of that understanding using the Unified Modeling
Language, UML. In particular, we're going to talk about UML's Class Model Diagram, which is the most popular form of
UML. Besides being popular, it's also the most complex of the diagramming types in UML. However, there's no need for you
to use all of its features, particularly at the start of the modeling process.


There's nothing wrong with having an abstract version that you refine over time.


Nevertheless, I'd like to introduce you to all of the features, so that when you need them you're aware that they're
there. UML class diagrams are also sometimes called Static Structure Diagrams. They're one of UML's structure diagrams
as opposed to the diagrams which you used to model behavior.


Despite being called Class Model Diagrams, besides classes, they also have iconic representations for interfaces,
objects, relationships, and so on.


The official specification for UML can be found on the Class Resources page.


And we're also going to be taking some examples from the UML reference manual, which is referred to on the resources
page as well.


02 - Classes
------------

A class in ULM or in an object-oriented language, is a description of a similar set of instances. Candidates for classes
include domain objects, roles, events, and interactions. In the previous lesson we learned how to use nouns as a way of
giving you ideas of what are good candidate classes.


In UML a class is denoted by a rectangle that is horizontally partitioned in to three or more units. Actually, all but
the first of those units is optional.


The particular units which are most commonly used, are the name, the attributes, and the operations. And we'll be
looking at all of those. In addition, if you wish, you could have units that describe responsibilities, exceptions, and
so on. Here's and example of a UML class. There are three horizontally partitioned units. The top one features the name
of the particular class, in this case it's window, it's the window class. In the middle is an area where the attributes
of that class are described. In this case, they're attributes for the size of the window, the visibility, and other
features. In the bottom most of the three units is a description of the operations which a window object can provide. In
this case it can display, it can hide, and so on.


03 - Name Compartment
---------------------

Okay, so let's drill down into the name compartment.


Obviously, the most important piece is the name, and that should be a noun.


After all, it describes a class of instances. For example, you saw that Window was in italics. That's one way in which
you can express in UML that this particular class is an abstract class. Abstract classes, if you're familiar with object
oriented programming, are contracts which describe the properties of sub-classes, and can never have instances
themselves.


Besides using italics, you can also specify that a class is abstract using a tag with the word abstract in it. Why might
you want to use an abstract class?


Well, for one if you have some related sub-classes that have common features, you can factor those features up into the
abstract class.


Inside the name compartment, you can also have some other affordances.


You can for example have a stereotype. Stereotypes are a way in UML of extending the base UML modeling language. You can
also express some optional properties inside of curly braces. For example abstract is one of those key words you can use
to give properties to the particular class.


04 - Class Features
-------------------

Classes have features. By that we mean its attributes, and its, its operations.


While classes, really describe the real world, that is, the problem that you're solving, features are something that are
going to end up inside the computer. Obviously, your attributes are going to translate, into instance variables in your
object oriented programing language. And your operations are going to be translated into methods.


We're going to look a little bit at the attributes and the operations.


But, in general. In addition to the names of the attributes and operations, we are going to have some type of
information. And possibly also some, some names for the attributes so that they can be referred to in, in, in your
models.


05 - Attributes Compartment
---------------------------

Here is our example class again.


Now let's look at the middle compartment which is for purposes of describing attributes. You'll see that there are
different attributes described.


All of them have names. They have types. And they may have some other symbols that described how the names can be
accessed from other classes. Those symbols, describe the visibility of that name. They're optional you don't have to
provide them and there's no reason, at the start, to do that. They're a refinement that you add later on in the process.
The four options in UML for visibility include.


Publicly visible that's a plus sign. Private, which is a minus sign.


Protect meaning that only sub-classes can access that attribute is the pound sign. And for those situations where you
used UML packages that tilde indicates that the name is visible within the package.


In addition to the visibility of course you must have the name of the attribute.


You can indicate the multiplicity of ordering of the attribute.


Now they're not shown in this example, but we'll see them later. You should give the type of the attribute. And UML has
a set of built in types that you can use.


You can optionally describe an initial value for that particular instance variable. You could indicate that the instance
variable is derived.


That is it's computed rather than being set directly. And you can give some additional properties to the instance
variable using the the braces notation that we mentioned before. For example we can indicate that that particular
instance variable is frozen. That means its value can't change.


06 - Operations Compartment
---------------------------

Returning once again to our, our window diagram. Now let's look at the third compartment, this is the one for
operations. Once again, there's optional visibility, using the same symbols we had before. There's the name. There may
be a return type, if the operation returns some value. It's not shown in, in these particular examples. Then there's a
list of parameters. Just like you would have, if you were describing some method within an object oriented language.


The parameter list includes a name of the parameter. It's type. You may express a default value. And you may also
indicate, whether the particular.


Parameter, is an input parameter, an output parameter or an in, out parameter. In, out parameters are those in which the
value can come in, and a different value can be returned. Those kinds of param adjectives in, out and in out are not
shown in this particular example. In addition to the parameters in the operations section, you can give some properties.
Some of those properties are expressed within the braces, like we've seen before. For example, you can indicate that a
particular operation is a query operation.


That is, it's only providing information about some existing attributes that in, within the class. You can, there's,
there's, properties to describing concurrency. there's, there's properties describing whether or not this particular
operation is abstract, as would be seen in an abstract method in obscuring language. And you can also show, that a
particular operation has Class Scope. That's shown by an underline on the operation name, and what class scope means, is
that it's not a operation of particular instance, but a operation for the class as a whole.


For example, let's say you wanted to know how many instances of vehicles, you had already instantiated. You can't query
any particular instance and ask it about other instances. Instead you query the class, using a Class Scoped operation,
and the class if you've implemented things correctly can provide the answer back to you.


07 - Abstract Class Quiz
------------------------

Okay, let's do a little quiz now. Start with something very simple, a class of vehicles. First, see if you can come up
with some natural subclasses for vehicles. How about now giving some attributes that obtain for all vehicles? Third, how
about some operations that vehicles can provide?


08 - Abstract Class Quiz Solution
---------------------------------

Some natural subclasses of vehicles include cars, trucks and buses.


I'm sure you maybe, came up with some more. Some of the attributes that vehicles have, are their number of axles. Their
VIN, that is their vehicle identification numbers, with their current mileages, and so on. For operations, usually,
vehicles are capable of moving forward, are capable of carrying passengers, and so on.


09 - More Example Classes
-------------------------

Here is two more examples of class rectangles describing classes in a in a system.


On the left is the rectangle class.


It has two instance variables describing points.


These might be, for example, the upper left-hand corner or lower right-hand corner.


The particular instance variables attributes have names p1 and p2.


And they have types point which presumably you've also declared in your UML model.


In the operation section, there are three groups of operations, each group is separated by a stereotype.


You can see the stereotypes because they appear within the double angle brackets.


For example, at the top, there's a stereotype for constructor, in the middle there's one for query operations, and at
the bottom there's one for update operations.


Within the, those three groups, there's obviously going to be a constructor operation.


There's query operations for giving the area, and the aspect ratio of the rectangle, and they're going to return real
numbers.


Real is a primitive type within UML.


And at the bottom we have update operations for moving and scaling the rectangle.


On the right is the reservation class.


You notice things are a little different here.


We don't have any attributes.


We begin initially with operations, and then we have two additional horizontal units.


One for responsibilities and one for exceptions.


Note specifically that the words operations, responsibilities and exceptions here are not part of UML.


They're just here to show you what the boxes are being used for.


10 - Class Description Quiz
---------------------------

Okay, let's do another little quiz now. How about providing a class rectangle for bank accounts? At least give me a
name, give me some attributes and give me some operations for a bank account.


11 - Class Description Quiz Solution
------------------------------------

I've chosen the name Account. You may have something that's slightly different.


But in, in UML there's a convention that class names begin with a capital letter. For attributes I have an account
number, the owner of the account, the current balance, which happens to be a derived attribute. That is, it's computed
rather than being something that is specified and changed. As far as operations are concerned there's obviously going to
be deposits and withdrawals.


Of course you could elaborate on these three compartments by filling in all of the possible notational possibilities
that are, that are there.


But for now this gives you an idea of what class rectangles are used for.


12 - Advanced Features
----------------------

There are some additional advanced features of class models. Four that I'd like to just briefly mention are interfaces,
parametrized classes, nested classes, and composite objects. If you're familiar with an object-oriented language like


Java, you know that you can express in your program, a type by using the interface construct within Java.


In UML you can also have interfaces. And in those interface descriptions, you typically describe what that interface
provides to the rest of the system and what it requires from the rest of the system.


Parameterized classes correspond to Java generics or


C++ templates. That is, that is they provide a way of, for example, describing collection classes by giving a parameter
that is a type of the class.


You have a set of vehicles, you have a set of bank accounts. Thirdly, our nested classes. If you're familiar with Java,
you know that within a Java class definition, you can have other classes.


These are sometimes called nested classes or inner classes. And


UML provides a feature for describing those situations. Finally, you can have composite objects. These are objects that
contain other objects within them.


Diagram allows you to express this by having class diagrams that have class rectangles that have other class rectangles
in them. As I said, these are advanced features just so that you're aware that they're there.


13 - Relationships
------------------

In object orientated analysis we saw that nouns could give us a good lead into what the classes are going to be.
Similarly verbs can be used for several purposes one of which is to describe what the relationships are between the
classes. In UML there are three kinds of relationships.


There are associations. For example, association between people and vehicles, people drive vehicles.


There's generalization, that is a car is a kind of vehicle. And there's dependencies. There might be a dependency
between cars and pollution laws. If a pollution law changes, cars might have to be adapted.


For example, putting on some kind of pollution control device.


14 - Associations
-----------------

Let's have a look at these relationships, beginning with associations.


Associations are denoted by solid lines connecting two class rectangles.


Here's an example of a UML class diagram containing two relationships and three classes. We have the Polygon class, the
Point class, and a GraphicsBundle class. Between Polygon and Point, we have a association called Contains. That is a
polygon contains points.


The little filled triangle to the right of the word Contains means that, when reading aloud that particular
relationship, you would read from left to right. So polygon contains point.


You wouldn't say point contains polygon. You would say something like point is contained by polygon. The second
association at the bottom, between GraphicsBundle and Polygon, isn't named directly. This is fine.


We'll see that we can describe it using roles, which are ways of saying, giving similar information about how the
association is relating the two, the two classes. There's lots of possible notational affordances for associations. You
can have a name, as in contains.


You can have association classes. They weren't shown in this diagram, but we'll look at them a little bit later. And you
can have aggregation and composition. In the example, we saw both of these.


The open diamond indicated aggregation and the closed, that is the filled diamond, indicated composition. In both cases,
we are saying that the two classes are related by some kind of containment relationship, that is a polygon is made up of
points. We saw reading direction, that was the filled, filled triangle. We can also express Navigability, which is the
appearance of an arrowhead on one end of, or both ends of the association line. This indicates that the primary access
pattern for those classes is in the direction of the arrow.


That is, we are going to be going normally from polygons to their points and not in the other direction. You can express
multiplicity, in the, diagram we saw star. We saw 3 dot dot star. Star means any number of, instances. 3 dot dot star
means between 3 and any number of instances.


We also saw a property ordered which indicates that at least for the case of the polygon and its points, those points
are in a particular order.


They might be, for example, in clockwise order.


Not shown in the example diagram is the ability in UML to, UML class model diagrams to express associations which
involve more than two classes.


In our text browser example, there were three classes involved and we used a rhombus into which the various lines, the
various lines come in to indicate all the participants within that particular association. We saw also the fact that you
could have role names.


The word bundle, adjacent to the graphics bundle class, indicates the graphics bundle is playing the role of bundle in
that particular association. You can have these role names on either or both ends of the association line, or you don't
need to have them at all.


Also not shown, are the fact that you can express qualification.


You can think of qualification as this as indicating what are the keys into the set of instances. We'll see an example
of that in a minute. And you can express also, certain, Constraints on the association. For example, that they're
ordered, that they're frozen, that is, the association can't change, that you can only add things to it and so on.


15 - Assocation Class
---------------------

I mentioned, a minute ago, the association class. You can think of an association class as ac-, as an association that
has some class properties. For example attributes, or you can think of it as a class that has some association
properties.


Here's an example. If we have a company class. And a person class, and we have some kind of association between them
that a person, has a job with a company. We might want to indicate what that person's salary is, from that company. So
this is not really a property of the person.


Because the person might have more than one job is not really a property of the company because the company certainly
has more than one person.


It's really a property of the association itself.


Association classes are indicated by having a dashed line.


That abuts into the association line. At the end of the dash line is another rectangle. In this case it is the
association of class called job, and in the class rectangle for job there is an attribute of salary.


Notice something else a little peculiar here. That job, has an association with itself. This is called a recursive
association.


For recursive associations in particular, you better use role names.


This case, we're talking about the manages association. So one job might manage another job. The department head might
manage the staff and therefore we want to have roles for the boss or supervisor, and the worker.


16 - Aggregation  Composition
-----------------------------

I mentioned also, aggregation and composition.


Using aggregation in particular is very common in UML class diagrams. You often want to say that one class is related to
many instances of another class.


And you use the aggregation association to do this.


It's still an association, it's just adorned with an open diamond to indicate that it's a particular kind of association
called an aggregation.


I want to say a word, though, about the difference between aggregation and composition. It's somewhat subtle, and it
gets to the point that aggregation doesn't really say much about the semantics of the relationship. In particular, it
doesn't say much about the lifetimes of the participant objects.


For example, let's say you had a house class and room classes.


Clearly, a house has rooms so you'd expect there to be an aggregation there.


But think further, if you destroy the house you're also destroying the rooms.


Therefore, instead of using aggregation, we would use composition. That is, we'd fill in that diamond. In compositions,
there is a responsibility for managing the lifetime of the constituent objects. That further says that a particular
constituent can only belong to one composition.


Compositions also have the transitive property. That is, a house can have room and a room can have closets. For
aggregations there's no rules like this.


Aggregations are general situations. We might say, for example, that a room has a table. Now this is an aggregation
situation, because we could certainly destroy the room after taking the table out. They have separate lifetimes, and
therefore we'd use aggregation instead of composition.


17 - Aggregation  Composition Quiz
----------------------------------

Okay, now let's have a quiz that tests your understanding of this distinction.


I'm going to list four different pairs of classes and ask you to tell me whether they're associated by a composition, an
aggregation, or a plain old association, which is neither a composition or aggregation. The four examples are courses
and students, person and spouses, bank accounts and patrons, and fonts and glyphs.


18 - Aggregation  Composition Quiz Solution
-------------------------------------------

Courses and students are an example of an aggregation.


That is, you can shut down a course without shutting down the students.


Persons and spouses is a plain old association.


They have independent lifetimes, and there's no containment relationship between them.


However, bank accounts and patrons is an aggregation.


That is, a patron can have a bank account.


Finally fonts and glyphs.


They're composition.


If we get rid of a font, we get rid of all the glyphs that are in the font.


19 - Qualifiers
---------------

Another refinement of associa, of associations that I mentioned, is qualifiers.


Qualifiers are indicated by small rectangles, that are on the sides or edges of class rectangles. The small rectangles
contain the name of one of the attributes, of that particular class. The attribute within the small rectangle is the
qualifier, that can provide access to, instances of that particular class. If you were doing a relational database model
you would think of the qualifier as the key, into the set of the instances.


In the leftmost example here, we have bank, and the account number is the qualifier. Note also that there's some
multiplicity information, that a person can have any number of bank accounts, for example. On the right, we have the
situation with a chessboard and its squares. How would we identify a particular square? In this case, we're going to use
a pair of attributes, giving the rank and the file of the particular squares within the chessboard. Notice also that in
the chessboard situation, we have a, a composition. Notice the filled black diamond.


20 - Links
----------

One further nuance to mention about associations, is the idea of links.


Just like classes can have instances, associations can have links. For example, if we had the situation where a company
hires people, we might have a situation where IBM hires Bob. IBM hires Alice.


Hewlett-Packard hires Tom. Hewlett-Packard hires Alice.


She has two, two jobs. In this situation, we would have four different links.


One for each pair involved in the association. Notice in this particular diagram that in addition to indicating all of
the particular instances of the classes, that the lines here are going to indicate links.


That is lines between rectangles for which the rectangles are instances indicate links, that participate in association.
Notice also that we have role names here and we have qualifiers.


21 - Generalizations
--------------------

The second major kind of relationship that you use in


UML class model diagrams is generalization. Generalization is also indicated by a solid line, but in this case the line
ends with a triangle.


The class rectangle that's adjacent to the triangle is the superclass or parent class. And the other class rectangle is
the child class or subclass.


The semantic import of generalization is that all instances of the subclass are also instances of the parent class. That
is there's a subset relationship. Let me warn you though that generalization is not the same as inheritance in object
oriented programming languages.


Inheritance is an implementation technique, generalization is a modeling, approach. We'll see how that difference plays
out later in the course.


In UML, generalization supports both multiple parent classes for a given class and multiple child classes for a given
parent class. Moreover, you can specify discriminators. That is names of groups of subclasses.


So here's an example of the UML class model diagram in which generalization is illustrated. We have a superclass called
Vehicle.


Note that it's got four lines coming into it each with an open triangle so it's got four sub-classes. Those sub-classes
are wind powered vehicle, motor-powered vehicle, land vehicle and water vehicle.


Notice also that we have two grandchild classes.


We have trucks and we have sailboats. So let's think for a minute about trucks. Trucks are motor powered vehicles are
motor powered vehicles but they're also land vehicles, that is truck has two parent classes.


Similarly sailboat is a wind powered vehicle and a water vehicle so its got two parent classes as well. With respect to
the parent level.


We have two categories of sub-classes. We have a category related to the power that moves the vehicle, it might be wind
or it might be motor. And we have a category having this labeled here as venue, indicating where the vehicle does its
moving. Is it on land or is it on water?


Also visible in this diagram are some properties in curly braces.


Those properties indicate properties of the sub-classes. If a parent class has two child classes, and instances can
belong to both of the child classes.


We want to use the overlapping property. If that can't be the case that is if a given instance can only belong to one
child, we say that those particular sub-classes are disjoint, their members belong to one of the child classes not the
other and. But by our definition of generalization, the instances do belong to the, to the parent class. A second kind
of constrained or property we might want to express is whether or not the set, of child classes covers all of the
instances or not.


If that's the case we say, we would use the, property, complete, and otherwise we would say incomplete. Why might a
modeling situation be incomplete?


Well you might have some weird hybrid vehicle that doesn't belong to any of the.


The child classes, but nevertheless we want to have an instance that, that recognizes it, or, or models it, say the
Segway, for example.


22 - Constraints Quiz
---------------------

Let's do a little quiz that checks you on this, with respect to completeness, and overlapping. I'm going to give you two
examples. The first example is athletes, and let's say we have, subclasses of athlete, for baseball players, football
players, basketball players. Determine whether first of all, those subclasses are disjoint,and are they complete?


Second example is books which can be Paperbacks, ComicBooks or hardboundBooks.


Are they, complete subclasses? Are they disjoint, subclasses?


23 - Constraints Quiz Solution
------------------------------

For athletes, we have overlapping. Remember Dion Sanders? Played both baseball and football? And they're incomplete
because they're are certainly a lot of athletes that don't play one of those three sports. With respect to books,


I'm going to say that these three categories of, of subclass are disjoint.


Moreover, they're incomplete because there's other categories, of, of books.


24 - Superclass  Subclass Quiz
------------------------------

Here's another little quiz that checks your knowledge of, of generalization.


Say we have two classes. One is omnivores, people who can eat anything.


And we have vegetarians, people who only eat vegetables, or, or don't eat meat. Okay. Which of those would you have as
the superclass and which is the subclass? Think about it for a minute.


25 - Superclass  Subclass Quiz Solution
---------------------------------------

Your natural inclination might be to have Omnivores as the superclass, because it's probably going to be bigger, and
doesn't work however.


Omnivores have a property, that is they can eat meat, the vegetarians don't, vegetarians don't eat meat. Remember our
rule that the definition of generalization is. That instances as the subclass have to have all of the properties the
instances the parent class. What that says is that Vegetarians are the superclass and Omnivores are the subclass.


After all, Omnivores can eat vegetables. Okay think about that for a minute in, before you do your next class model.


26 - Summary Quiz
-----------------

Here's on final quiz for you. We saw in the previous lesson that there are 14 different kinds of UML diagrams, some of
those are structure diagrams and some of those are behavior diagrams.


What I'd like you to do is to draw a UML class diagram.


That indicates the parent-child sub-classing relationship, amongst those kinds of diagrams. That is, you're going to
have classes for each of the 14 diagrams. You're going to a class for class diagram and you're going to have a class for
class structure diagram and behavior diagram. See if you can fill in the details.


27 - Summary Quiz Solution
--------------------------

Here's one rendering of the answer.


You have the structure and behavior diagrams as child classes of the diagram class.


And then we have seven different structure diagrams as children of the structure diagram class.


And the other seven behavior diagram types as subclasses of behavior diagram.


28 - Summary
------------

In summary, UML provides a rich vocabulary for modeling system structure.


And the UML class model diagram exhibits many, many different features.


However, there's no need for you to use all of its affordances. Particularly at the start of the modeling process. Never
the less, each affordance implies a question to be answered. What is the multiplicity? Are these values ordered?


What's the qualifier? Does the system that you are modeling, exhibit the property expressed by that affordance? One of
the important benefits of modeling, is that it encourages you to face these questions early, in the development process.
Because if you forget and they, they may later come back to haunt you.


