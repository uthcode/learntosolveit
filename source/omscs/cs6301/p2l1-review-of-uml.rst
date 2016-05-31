.. title: P2L1 Review of UML 
.. slug: P2L1 Review of UML 
.. date: 2016-05-27 23:37:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L1 Review of UML
==================


Student Provided Notes
----------------------

* `All UML Diagrams in a single pdf`_

.. _All UML Diagrams in a single pdf: https://d1b10bmlvqabco.cloudfront.net/attach/io7x94vh5gz42w/idfwkbgtu6i3ff/iostzz8hjr24/P2L1UMLDiagramTypes.pdf


01 - Diagrams
-------------

Doing design you need to be able to represent those designs and a very popular way of doing that is with diagrams. This
course focused on UML, using UML and constructing those diagrams and the purpose of this lesson is to review for you
some of the different kinds of diagrams that are there. There's lots of diagrams, we're not going to be using them all.
But I'd like you to be at least familiar with what ones are there. So lets step back a little bit in history.


Diagrams have been a popular part of software development from the beginning.


I still have a flow chart template that you use for writing out the control logic of an algorithm. Over the years,
various sophisticated diagramming techniques have developed. Okay.


Among those are SADT, Jackson Design, Structure Design and so on.


Each with their own particular approach to diagramming. In the 1980s, object oriented tech, techniques began to emerge,
and with them. Various techniques for diagramming [UNKNOWN] solutions. The first one we want to look at is called OMT.


02 - OMT
--------

OMT was developed at General Electric corporation by James Rumbaugh and others that were there. It resulted in a book, a
cover of a book as a, a die on which there are three visible faces. And one face has a class model diagram, one face has
a state chart diagram, and one face has a data flow diagram. The class model gave you the structural aspects, the state
chart gave you the behavioral aspects, and the data flow diagram gave you the functional aspects.


That is OMT was a way of putting together three views of a system into a cohesive view. As OMT was coming along other
competitive, object-oriented methods and diagrams were also being developed.


03 - UML
--------

This led to the natural development where there was a goal of trying to unify these various techniques together, which
led to the Unified Modeling Language,


UML. There's a, an industry group called the Object Management Group, called OMG. That is the home for this
standardization effort.


It's where you can find the specification documents, which I referred to you refer you to during the term.


UML has also been championed by IBM. They acquired a company called Rational, which had developed a development
environment called Rational Rose, which supported directly UML. There's lots of such case tools now.


Aside from Rational Rose, one that we've used is Enterprise Architect.


These are commercial tools. There are also all kinds of drawing tools out there, which you can get for free. UML,
itself, had three main architects.


One was Rumbaugh, one was Grady Booch, and the other was Ivar Jacobson. Okay.


They're sometimes called the three amigos. They produced, in addition to a unified modeling language itself, three
books, a reference manual, a user's guide and so on. That had its main author as each one of the three, and then
together. Conveyed the overall approach to UML. It's important to note at this state the UML diagrams can be used both
for design but also for analysis. I'll try to distinguish as we go forward whether we're talking about an analysis
diagram or a design diagram. The main distinction is, analysis is concerned with the problem being solved and design is
concerned with the solution to that problem. I've taken some of these diagrams you're about to see from the UML
reference manual and from the UML users guide.


04 - Diagram Types
------------------

We're now into version two of UML. Which has as a total 14 different kinds of diagrams. We're going to go over those
quickly here but in the course we're not going to be using all of them. We're going to concentrate on just three or four
of them. And we'll have special lessons devoted to those but I wanted you to at least be aware of the different kinds of
diagrams that are there.


That said, on a particular project, you're unlikely to use all the diagrams.


You're going to use the ones appropriate to the particular project.


In particular, determine what is the trickiest part of the project and use the diagram that helps you best understand
that tricky part.


The two main categories of diagrams are structural and behavioral.


Structural diagrams give you the pieces of the system that are always there and the relationships among them. Behavioral
diagrams on the other hand, are concerned with the executions of the system. And the particular diagram may only convey
one execution. That is, you may have to have multiple sequence diagrams in order to get a good feel for all of the
behaviors of the system


05 - Diagram Quiz
-----------------

Imagine you're in a development shop.


And this development shop is old school and don't know anything about diagrams.


And you have to convince them of the value of having design diagrams.


06 - Diagram Quiz Solution
--------------------------

1


One major use of diagrams is that you can use them to convey information to


2 others in the group.


3


The others might be your teammates, but they also might be


4 people on other parts of the project which you don't normally communicate with.


5


They might even be persons down the line time-wise.


6


That is, the maintainers who are going to deal with the system


7 five years from now.


8


Communication is the first answer.


9


Second, we're talking about, in the case of UML object-oriented development, and


10 object oriented development has a particular process often used in


11 association with it.


12


That is, the diagramming technique can support a process that you're using.


13


For example, your process is likely to have some kind of


14 validation step associated with it, maybe a design review, and


15 using a particular design diagram can help you structure that review.


16


Also, by using a particular kind of diagram, there,


17 you may be able to find some tool support for that diagram.


18


The tool support might inform the user when a violation of


19 the visual syntax occurs, or inform the user that a piece is missing.


20


As far as the disadvantages are concerned, just like source code, any time that


21 you build a diagram, you have to worry about it getting it out of date, that is,


22 keeping it up to date with respect to changes in the rest of the system.


07 - Class Models
-----------------

Let's start with the most popular diagram. The Class Model Diagram. This is also sometimes called the static model or
the class structure diagram and it is an example of a structured diagram. It is showing the structure of the system.


In particular, it has classes and the relationships among those classes. And there are numerous embellishments. Class
Model Diagrams have many, many different affordances on them, icons on them and so on that you can use.


And we'll be devoting a lesson later to looking at those, and, how, what, what the meaning of those particular
affordances are


08 - UML Classes
----------------

As a quick reminder, UML classes are depicted as having up to three compartments, separated by horizontal lines.


The top compartment, typically, has the name of the class in it.


The middle compartment has the attributes of that class; the instance variables.


And the bottom compartment has the methods or operations that class provides.


09 - UML Relationships
----------------------

As far as relationships are concerned, there's three main categories of relationships in UML.


There are dependencies, depicted by dashed lines with an arrowhead, indicating that the class at one end uses the class
as the other end.


The solid lines without arrowheads are associations.


And that says that class at one end affects or has a instance of the class at the other end.


The solid line can be adorned with a diamond.


The diamond is used indicate this has a or aggregation embellishment to the association.


Third main category relationship is the generalization relationship.


The class at one end is a kind of a class at the other end.


In this case there is a solid line but it has that triangle at the end of it.


10 - Example Class Diagram
--------------------------

Here's a typical class diagram. It has some examples and associations. The associations don't have labels on them.
There's also couple of places where there are generalizations. As I said, the class model diagrams can have a lot more
adornments to them and we'll see those later on.


11 - Object Diagram
-------------------

Related visually to the class model diagram is the object diagram.


In fact they're the same with one major exception.


Instead of mentioning classes, they mention instances.


The label compartment at the top of the boxes has an underlined text line.


A text line has two parts.


One is the class name, just like in the class model diagram, but it also has the name of a specific instance, and those
two are separated by a colon.


So for example here, we have the company class, and in particular we have the c instance of a company class.


Optic diagrams are obviously used to convey the specific use of the classes involved in a class model diagram.


As you can see, for this particular instances here, many of the attribute fields have attribute values filled in for
them, as they would be for a particular instance.


12 - Composite Structure Diagram
--------------------------------

1


A less popular,


2 less frequently used structural diagram is the composite structure diagram.


3


This one is used for showing the internal structure of a class.


4


Of particular interest to us are its interfaces.


5


So on the left side of the interior class here are two


6 horizontal lines coming out.


7


The top one with the circle on the edge of it is a Provides Interface.


8


That's saying that this class provides some capabilities to


9 the rest of the world.


10


Under it is another line coming out and this one with a semicircle that's open.


11


This is a Requires Interface, that is,


12 what does this class require from the rest of the world?


13


You can then imagine having a variety of classes that plug into each other.


14


That is, a provides from one class plugs into a requires from another class.


15


This is one way of putting together the pieces of a software architecture.


13 - Component Diagram
----------------------

In fact, that's exactly what a component diagram does.


It's a static implementation view of how the components of a system fit together. As far as UML is concerned, a, a
component is a physical, replaceable part of a system that packages implementation and conforms to and provides a
realization of the set of interfaces. It's usually used to model code entities such as binaries, okay, that might
perhaps come from a library.


And relationships in the diagram are meant intended to specify that one of the components uses the services of another
component.


This particular type of diagram can also be used to convey architecture.


14 - Example Component Diagram
------------------------------

Here's an example component diagram.


The rectangles with the two sub-rectangles on their side indicate components.


This is one of Bouche's contributions to UML. He had a diagramming type called Bouchegrams in which these particular
icons were used.


The stick figures represent in this case people or actors of the system, and the dashed line indicates where components
plug into other components.


15 - Deployment Diagram
-----------------------

If we're talking about complex systems, these systems may run on different processing units. And we'd like to convey the
configuration of the run-time processing units, and their component instances in a way, that sees how they can interact.
And this is, included inside a UML deployment diagram.


A node in the diagram will correspond to a computational device, and the arcs indicate some kind of communication.


16 - Example Deployment Diagram
-------------------------------

In this example, there's two major processing units indicated by the shadowed rectangles. Inside rectangles are some
components, and then there are lines indicating the communications between the physical components, but also have
interfaces plugged into each other.


17 - Packages
-------------

UML also supports packages, in the sense of Java packages.


These are general purpose organizing mechanisms. Before UML 2, you could use packages as parts of other diagrams. In UML
2 there was a separate package diagram. Essentially this is providing namespace scoping so that each package can have
its own set of names without worrying about collisions. And that there's dependency arrows between two packages if some
piece of one package has a dependency arrow with some piece of another package. That is, it's an abstraction of that
particular dependency at, to the package level.


18 - Example Class Diagram with Packages
----------------------------------------

Here's a use of packages in UML 1.5.


In general, the indication that something is a package is it had a little tab in its upper left-hand corner, with a
label on it.


You see in this particular example there are also interpackage dependencies.


The dashed line ending in an arrowhead.


19 - Example Package Diagram
----------------------------

In UML 2.0 there's a separate package diagram, but it's conveying the same kinds of information.


20 - Profile Diagram
--------------------

The final structural type of UML diagram that I'd like to mention is the Profile Diagram. But this requires taking a
step back.


UML itself is a language, that has various pieces to it, such as classes and associations and so on. Those pieces.


Essentially provide a, describe a system and therefore you could have a UML description of UML.


That UML description or UML is called the UML meta model and in fact you can have, a UML class model diagram of a UML
meta model.


Even, more abstract is the fact that you, as a user, a designer, can extend the UML middle model.


You can add new kinds of icons. You can give, special labels.


To particular elements in the model. You do that extension in what's called a UML profile. And there's a UML Profile
Diagram in which you can convey it


21 - Example Profile Diagram
----------------------------

So here are three UML profile diagrams. Notice that above the class names are some stereotypes. Those are the things in
the double angle brackets.


And the particular stereotypes here are metaclass and stereotype.


So we're talking at the meta level. There's also some inheritance going on here.


The overall purpose of these particular examples has to do with extending the UML language to deal with describing
certain kinds of systems.


22 - UML Structure Diagram Quiz
-------------------------------

Okay. Well, here is a quiz for you to test your knowledge of these different diagram types. In column one I have the
names of the diagrams, in column two I have some definitions, and I'd like you to match them together.


As a review that particular diagram types of the class diagram, the composite structure, the component diagram,
deployment diagram, object diagram, package diagram, and profile diagram.


And then the definitions are in the right column. The static structure at a particular time. The organization of
physical software components.


Three is the logical groupings and dependencies. Four is the components and structural properties. Five extensions to
the UML metal model. Six internal structure and possible interactions. And the seventh choice is the physical system
resources and how they map to the hardware. Try to match those together.


23 - UML Structure Diagram Quiz Solution
----------------------------------------

Well the class model diagram is the components and their structural properties.


The composite structure diagram is the internal structure and the possible interactions among them.


The component diagram is the organization of the physical software components in the system.


Deployment diagram, that's the physical system resources and how they map the hardware.


The object diagram, that's the static structure at a particular point in time.


The package diagram, well, that's the one with the logical groupings and dependencies.


And finally, the profile diagram, that's extensions to the UML meta model.


Notice that there's a lot of overlap among these terms, which say, that the different diagram types have a lot of
overlapping themselves.


24 - UML Quiz
-------------

Another quick quiz for you on this material is, which of these particular UML structural diagram types could be used to
convey system architecture?


25 - UML Quiz Solution
----------------------

Well, the component diagram, deployment diagram, package diagram, and class diagram, more likely so, some of the other
ones less likely so.


26 - Behavior Diagrams
----------------------

The second main category of UML, Diagram Systems Behavioral Diagrams.


In contrast with the structural diagrams, which describe the system as a whole, the behavioral diagrams are concerned
with a particular instance of behavior of that system. That is, you may have to have multiple sequence diagrams,
multiple collaboration diagrams, to convey, to give an idea of overall system behavior. We're going to now survey these
so you get a feel for what's available to you. Once again, it's unlikely that for a given system you'll use all of these
diagram types.


27 - Use Case Diagram
---------------------

Let's start with use case diagrams. UML does not include OMT's data flow diagram. Instead, it includes Jacobson's use
case diagrams.


A use case is a sequence of user-visible actions along with system responses.


It's a story of how the system deals with a particular user interaction.


Use cases are particularly useful for eliciting requirements.


You lay out different stories of how the system is going to be used, and then explore ramifications. What happens if
something goes wrong, what are some intermediate steps that maybe you didn't make explicit.


28 - Use Case Diagrams
----------------------

Use case diagrams will have two major icons. One are some stick figures and these denote external actors. Typically,
these are system users, but they may also stand for other systems or external devices. In the use case diagram, ovals
are use cases. That is, this is, a use case diagram is not a system story.


It's a description of the set of system stories. Lines in the diagram without annotations indicate participation. That
means that the actor at one end is involved in the use case oval at the other end. There're two annotations available in
use case diagrams. One is the extends annotation and the other is the uses annotation. Extends mean that you have one
story and you'd like to extend it by some other contingencies, essentially getting two for the price of one. The uses
stereotype is like a subroutine or, or function call.


That is, a common piece of behavior that might used by several other use cases.


29 - Example of Use Case Diagrams
---------------------------------

Here's a Use Case diagram. It's got six ovals. It's got four actors. Three of which are human. And one of which is a
separate system. There's annotations on through the lines. One situation involves reusing a particular use case and more
than one other use case. And the other is an extension situation.


30 - Individual Use Cases
-------------------------

1


The use case diagram lays out the set of use cases.


2


But, what's an individual use case?


3


Well, it's a story,


4 and the story can appear as unstructured text or in a tabular form.


5


The unstructured text might tell the story about an individual user


6 named Foster who wants to buy something at Amazon.


7


Foster goes to the Amazon web site,


8


Foster browses until he finds the particular item that he wants,


9 he adds it to the shopping cart, he then goes to the check-out page,


10 he provides information about his billing, and then submits a purchase request.


31 - Tabular Version of Example
-------------------------------

As an alternative formulation of the same story, we could have a table. And typically the table will have three columns.
One column is the agent or actor involved in that particular step of the story, and this is going to be Foster. And it's
going to be the Amazon web server.


The second column indicates the action that's taking place.


This might be the user action it might be the system response and the third column, contains information about any
object, that, is conveyed, in that particular step. So it might be for example credit card information.


Same information in the unstructured version and the tabular version. They’re both examples of use cases, and they would
represent the content of one of the ovals used in this diagram.


32 - Context Diagrams
---------------------

The top level dataflow diagram is called the context diagram.


The context diagram has a single oval. Which is the system as a whole.


There are rectangles there that indicate the system actors. And then the lines indicate the flow of data between them.


33 - Example Context Diagrams
-----------------------------

Here's an example context diagram for a system that plays chess with the user.


The rectangle is the human player, the oval is the chess-playing program, and there are three lines between them. One
line indicates that the human player is supplying a move to the chess-playing program. Another line from the chess
playing program back to the user is the computer's move. And the third line indicates that the computer can also put out
a diagram describing the board.


34 - Sequence Diagram
---------------------

Another one of the most popular UML behavior diagrams is the sequence diagram.


This can be used to convey a single use case.


35 - Example Sequence Diagram
-----------------------------

The sequence diagram has columns corresponding to individual participants, usually objects, in the system.


Time marches down the sequence diagram, and horizontal lines between columns indicate the passing of a message from one
object to another object.


Historically, these sequence diagrams evolved from message sequence charts which had been used in the telephony industry
for many years.


These diagrams will be semantically equivalent to communication diagrams which we'll look at in a minute, but from a
slightly different point of view.


36 - Communication Diagram
--------------------------

An alternative view of a use case to that provided by a sequence diagram, would be a communication diagram. In the
communication diagram, it looks like a class model diagram. That is, there are rectangles corresponding to classes, and
there's lines between them. However, in this case the lines correspond to instances of communication, likely operation
calls.


37 - Example Communication Diagram
----------------------------------

Here's the same information that we saw in the sequence diagram.


There are three particular objects. One is a client, one is a transaction and one is a proxy. There are lines between
these particular objects.


Notice that the lines are annotated with numbered message indicators.


The numbers indicate the orders in which those messages take place.


And it's using a kind of, Dewey Decimal notation. So, first step is number 1, then number 2. And then 2.1, 2.2 and then
step 3.


38 - Activity Diagram
---------------------

The sequence diagram and the communication diagram that we've seen aren't particularly designed to deal with
synchronization. UML has a separate diagram, called an activity diagram, designed for this purpose.


In this diagram it's a variant of a state machine in which.


Multiple states may be simultaneously active. That is have their own threads of control. This activity diagrams are
derived from petri nets.


Petri net diagrams that have been around for many years. In the diagrams trans, transitions are typically triggered by
activity completion.


That is you finished with one state. Rather than by external events. You can use these diagrams to model workflows,
process synchronization, and concurrency.


39 - Example Activity Diagram
-----------------------------

Here's an activity diagram you can think of it executing as follows.


Imagine that you had some token that you could lay on top of any of the states on the diagram.


It would come in at the start at the top where there's the filled in circle, and it would move along the horizontal line
to get to the first state.


And then it would move downward to the diamond. At which point it would split.


That is, we'd have two tokens. One going over to the right and one going downward. The one on the right can continue
downward again and finally coming into the diamond near the bottom. The second token from the top goes straight downward
and is thwarted by the horizontal, the heavy, black horizontal bar that's there. This is a synchronization point.


In this case there's nothing to synchronize with, but there are two lines coming out of the bottom. Those two lines will
themselves both have a copy of the token on them, one will go over to the left into the two activities that are there,
the second will go straight downward, and eventually those two paths will merge into the second horizontal line which is
a synchronization point. You can think of those two paths, each having their own tokens, as running independently, and
the horizontal bar at the bottom being a kind of a gate which only opens with both tokens have arrived from the top,
hence synchronizing those activities.


At the point at which the gate opens the two tokens are merged together, the single token goes out of the bottom into
the diamond, and the diamond is essentially a joint point, which, once again, combines the two tokens and proceeds on
then to the last state, and the final state at the very bottom of the screen.


40 - Interaction Overview Diagram
---------------------------------

Now I want to mention two less frequently used UML diagram types.


One is the interaction overview diagram. It's a kind of activity diagram, where the nodes in the diagram correspond to
lower level interaction diagrams which could be of any sort, sequence, communication, interaction overview, and timing
diagrams.


In the diagram example, the term ref denotes a specific interaction occurrence.


41 - Timing Diagram
-------------------

Here's a example of the UML timing diagram.


If your familiar with the design of digital chips, it should look very similar.


In digital chips obviously you're worried about electrical signals arriving at a certain time in response of the silicon
and germanium in that chip, how long it's going to take to happen. If you need, in fact, to diagram out specific timing
of situations in your system you can use the UML timing diagram to do that. Time marches from left to right and arrows
indicate the places where timing has to be synchronized.


42 - State Diagrams
-------------------

Final behavioral diagram I'd like to mention is the state diagram.


This is the most powerful, the most complex of the behavioral diagrams.


They're also sometimes called state charts. These diagrams convey extended finite state machines extended with the
ability to represent aggregation, concurrency, history, broadcasting events and so on. We're going to devote a whole
lesson to them, but let me give you one example diagram here.


43 - Example State Machine Diagrams
-----------------------------------

In this diagram there are two external states. There's an idle state and a maintenance state. And there's transitions
between the two indicating the lines at the top of the screen. The maintenance state itself has sub-state machines
separated by the horizontal dash line. These two machines, one called testing and one called commanding, are running
concurrently. Each of them as a simple machine starting at, at its left in the initial state and moving towards right.
And the commanding machine has a back loop from its command state to its rating state indicating that, that particular
machine can execute several times before finally getting to its final state.


44 - Behavior Diagram Quiz
--------------------------

Here's a quiz for you on the behavioral diagrams. Once again,


I'd like you to match between the diagram type and its definition. As far as diagram types are concerned there on the
left, there's the Activity Diagram, the Sequence Diagram, Communication Diagram, Interaction Overview Diagram,


Timing Diagram, Use Case Diagram, and State Diagram. Definitions, number 1, system functionality provided to external
actors. Possibility 2, dynamic behavior in response to stimuli. 3 is flow of control from activity to activity.


4, synthesis of lower-level Activity Diagrams. 5, interaction of classes in terms of message exchanges. The next one is
object interaction in terms of numbered messages. And the last one is a rotated sequence diagram.


45 - Behavior Diagram Quiz Solution
-----------------------------------

Activity diagram. Well that's the one that's, of course, there's a flow of control from activity to activity. As far as
the sequence diagram, that's an interaction of classes in terms of message exchanges. Communication diagram.


That's object interaction in terms of numbered messages. Interaction overview.


Synthesis of lower level behavioral diagrams. Timing diagram.


Well that's the rotated sequence diagram.


That's also going to have specific time laid out on it. The use case diagram, well that system functionality provided to
its external actors.


And the state diagram, that's dynamic behavior in response to stimuli. [BLANK_AUDIO]


46 - Object Constraint Language
-------------------------------

Well, those are the diagrams types. I just wanted to repeat that no particular system that you develop is going to use
all of them. And, in fact, you're probably going to concentrate on the most popular ones. But they're there in case you
need them.


I also want to mention two other features of UML that don't involve diagrams. [COUGH] One is the Object Constraint
Language and the other one,


I hinted tthat a few minutes ago, the Metamodel. The Object Constraint Language, and we'll devote a whole lesson to
this, is a textual extension to UML's vis, visual notation. Its purpose is to provide a more precise specification, to
be able to specify things which you can't specify in the diagrams themselves.


You can use this textural extension as annotations to class model diagrams, and statechart diagrams. Essentially, the
Object Constraint Language, this first-order predicate logic, plus the ability to navigate around the diagrams and some
collection classes, like sets and, and bags and sequences.


The overall purpose of the Constraint Language, Object Constraint Language, is to be very precise, if you need to, in
the specifications of your system.


47 - Example OCL
----------------

Here's an example of OCL. In this case, we're talking about using the OCL as an extension to a class model diagram.


In the class model diagram, there's an account class. The account class has a deposit operation. That operation takes in
a real number called amount.


The pre keyword indicates the precondition, in this case, that the amount being provided in this deposit is greater than
zero.


The postcondition, indicated by the post keyword is indicating what must be true after the execution of this particular
operation.


In particular, the balance afterwards must be equal to the balance before plus the amount that was deposited.


48 - UML MetaModel
------------------

The second non textual part of UML to be aware of is the Metamodel.


I mentioned this before, it's UML defined in terms of UML. The UML Metamodel, is a UML description of the UML language.
More over, you can extend the Metamodel. You as a designer can extend the Metamodel.


Using UML profiles and we saw the profile diagram.


Those extensions are more stereotypes, more tag values and you can add the constraints. These are constraints on the
diagrams now, not on the models


49 - Class Model of UML MetaModel
---------------------------------

Here's an example of a UML class model diagram describing UML.


You notice there are classes for class, there's also class for attribute, there's a class for association, and there are
associations among these classes.


You should study this diagram, to make sure that you understand how the various pieces that comprise UML [UNKNOWN]
together.


50 - Summary
------------

Bottomline is you can't design an complex system with having, without having some idea of what it's supposed to do.


That is what problems is it trying to solve. Diagrams can help you express that understanding and express your solution
to that problem.


UML provides a wealth of diagram types for you as well as OCL and the meta model. In general, the more precisely you
understand problem the fewer subsequent problems you will have with that system's history.


