.. title: P1L3 Design Concepts 
.. slug: P1L3 Design Concepts 
.. date: 2016-05-27 23:36:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P1L3 Design Concepts
====================

01 - Design Concepts
--------------------

Good day, class. Today's concept is design concepts. And design is everywhere.


From super complex manufactured artifacts like the International Space Station, to the dinner party you were planning
for next week. In the course, although we are going to be specifically concerned with software design, many of the
concepts of design in general are going to play a role, so we'd like to get into that. Let's start with a few
definitions.


02 - Terms Quiz
---------------

For this quiz, I've listed four different terms, along with their definitions.


The terms are overlapping, and include design, engineering, craft, and art. See if you can connect, the definition to
the term that's being defined.


03 - Terms Quiz Solution
------------------------

What is design? Design is deliberative, purposive planning.


As far as software is concerned, this translates into solving some problem.


Given in a, as a set of requirements. What is engineering?


Engineering adds in the element of science and mathematics. And we're going to see the role of formal methods play in
software design.


What is craft? Craft is some sort of skilled occupation.


Those skills come from long experience, and we'll see that with software design, the more experience you have on a
particular kind of problem the better.


And what is art? Art is the conscious use of skills. Taste and creative imagination in the production of aesthetic
objects. And later in this lesson, we'll see that, certain design principles and aesthetic principles can play a role in
software design.


04 - Programming or Design Quiz
-------------------------------

1


Another quiz for you.


2


Think for a minute about the difference between software design and programming.


05 - Programming or Design Quiz Solution
----------------------------------------

1


Here are two important differences.


2


One difference is scale.


3


When you're doing software design, iit's probably because you


4 are dealing with a big problem that's going to have a big solution.


5


If you're doing programming, you're more likely concerned with programs that


6 are going to end up being 100 or 1,000, or maybe even 10,000 lines.


7


The International Space Station has 30 million lines of code.


8


Another key difference between programming and


9 design, software design, is the role that non-functional requirements play.


10


For programs, you may at a, occasionally be concerned with performance but


11 by and large, non-functional requirements don't play a big role.


12


With software design, the whole story is how you


13 are going to deal with trade-offs among non-functional requirements.


06 - Software Design
--------------------

What is software design? Software design is the process of building a program while satisfying the program's functional
requirements and not violating any of its non-functional constraints. This is going to turn out to be a question of
trade offs. How do you trade off between performance and resource consumption, for example? Software design is normally
broken into two different phases, architectural design and detail design. Architectural design is the process of carving
up the programs into components and assigning responsibilities for aspects of behavior to each component and talking
about how the components are going to interact with each other. We're going to spend a great deal of time in this course
talking about architectural design.


Detail design is the process of dealing with the individual components.


Particularly, with respect to their data structures and their algorithms.


Let's look for a minute at some of the aspects of detail design.


07 - Design Notation
--------------------

Here's a quote from Tony Wasserman about detail design. [BLANK_AUDIO]


The primary activity during detail design, is designing the data structures that are there and by implication the
algorithms that are going to work on those data structures. As far as those algorithms are concerned, sometimes you may
wish to represent them using some kind of design notation.


Here are a few that have been used in the past in which you may have little familiarity. Their pseudo code, which is
like writing a programming language algorithm without the programming language. There's structured programming, which is
a set of control structures, which allow you to organize the algorithm into sequences, conditions, repetition, and
chunking in the form of calling subprocedures.


Flow charts and call graphs are graphic representations of programs, that may be useful in helping you understand how
that program is going to, going to work. And in some cases decision tables, which are lists of rules and the conditions
under which those rules are going to apply, can be useful in helping to understand complex situations.


08 - Weather Quiz
-----------------

Here's a little quiz for you that deals with detail design.


Imagine that you were writing a program to predict the weather. The way that these programs normally work is by taking
some geographical area and carving it up into a rectangular grid or mesh. That is, there are numerous cells and each
cell contains some data such as temperature, wind pressure, humidity, and so on. And then running an algorithm which
diffuses the information from cells to their neighbors in order to come to some conclusion about what the future weather
will be. If you had to develop a weather prediction program you might have the choice between using arrays or objects.


09 - Weather Quiz Solution
--------------------------

The main reason for choosing arrays is performance.


Arrays have been part of programming languages since Fortran in the 1950s. And those programming languages have been
tuned to take advantage of the hardware architecture available in order to do array computations very rapidly. Objects
on the other hand are a little slower, but they're much more flexible. If, for example, your weather program changed
from having a rectangular grid to one where there's different kinds of shapes adjacent to each other, having an object
oriented representation may allow you to deal with that situation more flexibly.


10 - Approaches to Software Design
----------------------------------

There are many approaches to software design.


Some espouse a particular point of view as to how best to structure a system, such as object orientated design. Some of
them are intended for a particular class of application. That is the design of real time systems. And some of them are
structured to deal with only a part of an application, such as user interface design. All approaches to design however,
include three aspects that may be compared, the design method, the design representation, and how that design is going
to be validated.


Let's first look at design method. A method is a systematic series of steps by which you undertake to do your design and
solve your problem. Typically, a design method suggests a particular way of viewing the problem. With object oriented
design, we view the problem in terms of a set of cooperating objects.


Only later do we assign the services or functions that each of those objects are going to be able to provide to the
system. Other methods that we may be mentioning during the course of the term include structure design, and role based
design. The design method that is chosen acts as the discipline for the participants, the designers and ultimately the
implementers, forcing them how to organize their thoughts and and activities in certain ways.


11 - Issues with Design
-----------------------

There are, however, some issues with design methods. You as a architect or designer have to make some choice. Are you
going to go do things top down, bottom up, inside out? There are a variety of choices there.


Are you going to begin by thinking of the procedures and functions? Or are you going to begin by thinking in terms of
the nouns and objects like you would with objectory development. A topic which we'll come back to later in the lesson is
the issue of conceptual integrity versus cooperative development.


An important decision in many, software development shops is the trade off or the tension between doing a design that
takes a little bit more time.


In order to save yourself effort and money in the long term, by supporting maintainable and general structures. Or are
you going to be dominated by short term delivery schedule. And finally, is the role of tools.


What, what tools are you going to use in terms of your particular design.


12 - Design Review Quiz
-----------------------

1


So imagine in your shop that you have a design method, and


2 you've, you've chosen a design representation, and you've done a design.


3


The result is some artifact expressed in the design notation.


4


Now typically, these days, that representation is reviewed by a team, that is,


5 there's some validation the design in fact meets it, the system's requirements.


6


The question for this particular quiz is,


7 why bother with the validation now if you're going to build the program and


8 have tests, many of which may be automated, to check it for you?


13 - Design Review Quiz Solution
--------------------------------

The key reason of course is that the earlier you find problems, the less expensive it is to fix them.


Particularly if you've got a design problem and you don't detect it until you're about to deliver to the customers, it
can be quite expensive to fix.


14 - Design Validation
----------------------

The third important aspect of approaches to design, is how they are validated.


As I just said, typically that means some kind of review, walk through, inspection by a team.


It could also be the case that the tools that you're using, to represent the design can do some checking for you.


Some issues arise with design validation.


And a key one is the independence of the validators.


The problem here is that if you have the design team, doing its own validation.


They may be blind to particular issues.


If they didn't think about them when they were doing the design, they may not think about them when they're inspecting
the design.


Bringing in independent val, validators can help with the effectiveness of the design review.


Second issue that arises is the, dependence of the design validation on the design method.


For structured design, there's a complete set of rules associating metrics with each of the design artifacts.


On the class resource page, there's some guidelines that I've written up concerning the things that you can ask about
during a object oriented design review.


A third key issue with validation is when do you do it?


One strategy is to do it as you go along.


That is, on a daily or weekly basis, review what you have and make adjustments.


An alternative is to wait until you get to ma, major milestones, have design reviews and make your changes at that
point.


15 - Other Design Issues
------------------------

In addition to design methods, representations and validations, there are some other issues that arise with software
design.


We already talked about the difference between architectural and detail design and exactly where that boundary is. Of
key importance is the respective energies we put into designing the functional part of the system versus dealing with
those non-functional constraints. At a more abstract level, there's the difference between what and how. The
specification process deals with what the system will do. The design process begins to say how we're going to do it.
Finding the right boundary between those two is a key issue. And finally, what is there about your particular
application that is going to affect the design process? For example, you have some existing resources that you want to
reuse and build in your solution. They can affect the design that you do.


16 - Design Documentation
-------------------------

The next key concept to consider is design documentation. If we're talking about the software design of large systems,
the systems are likely to be complex and the scale and complexity beg for having good design documentation.


If you've invested all that energy in developing the system, it's likely that that system is going to around for a while
and is going to be under maintenance, maybe by people that were different than the original designers. And having some
form of written communication can be a big help. Different kinds of methods, different kinds of applications, require
different kinds of documentation.


Those may range from formal, multi-volume documents, to scribbled notes or, or slides in, that are used for
presentations


17 - Documentation Quiz
-----------------------

Here's a brief quiz for you. Think of organizations that are doing software development.


Pick a typical organization that would require a lot of formal documentation.


18 - Documentation Quiz Solution
--------------------------------

One example of organizations that require lots of, of detailed documentation are military contracting organizations. On
the other hand, if you're in a small research lab, and you're doing exploratory development, you may not need a lot of
documentation, because it would only get out of date very rapidly


19 - Traditional Design Documentation
-------------------------------------

Traditionally design documentation has included information about the components you've carved the system up into, what
their responsibilities are, what their primary data flows are and so on. Other elements of traditional documentation
include, how you going to deal with performance considerations.


And resource consumption, by resource here we might mean memory, we might mean use of peripherals, bandwidth and so on.
It that's not enough for you, if your organization needs more detail documentation, you might rely on some IEEE
standards, such as standard 1016.


Some of the key elements that the standard add to the list that is traditionally used are things like who is the
designer? It might be nice to know if you have to go back for a question, who was responsible for a particular piece of
the design. What are the dependencies among the elements?


Are there hidden assumptions that one component is making about other components? What are the tradeoffs among the non-
functional constraints?


How did you decide to take a particular tradeoff? What assumptions are you making about your users, about the technology
that will be available for the hardware, and about the changing customer base? And which particular. Views of the
software system as your documentation providing.


20 - Leonardo Objects
---------------------

An even more elaborate approach to design information was taken by the Leonardo Project at the MCC in the 1980s. They
devoted, a whole project to determining what is a suitable set of design information, and some of the, elements that
they came up with that go beyond these, we've talked about already are. Explicit lists of the stakeholders involved.


Okay. Most important is what issues were raised during the course of the design.


And for those issues, what were the possible resolutions and why.


Was a particular choice made? That is, design decisions and the reasons for making them. Leonardo also stressed various
relationships among the design artifacts. such as versions. In producing this system you actually maybe producing
several versions. Like the professional version and the free version and so on. And what exactly is in each version, and
what design compromises had to be made in order to accommodate multiple versions. There is also the questions of
revisions. And the time, the historical progress of the design. What went into each of the, the revisions along the way.
Specific. Descriptions of constraints, upon the solution and how they're being dealt with. [INAUDIBLE] important, and
what groupings or aggregates of, of design, artifacts implementation, artifacts configuration files, packaging,
components and so on, did you decide to use, as far as your solution is concerned.


21 - Design Rationale
---------------------

Taken together, a lot of this design information, can be thought of as design rationale. Rationale here means, the
reasons that you did what you did in coming up with your design solution.


The more you can make explicit choices with reasons for those choices, the better off we'll be, the downstream people
who are trying to maintain the system. The bottom line as far as design information is concerned, is that there's many
options to you. And you need to decide upfront, what it is that's going to be important in your documentation, and then
capture it as you go along. Now I'd like to introduce you to some key design concepts that are going to be used
throughout the term, when we talk about software design.


22 - Coupling and Cohesion
--------------------------

First, let's look at conceptual integrity, which I mentioned earlier in today's lesson. Let me give you two historical
quotes that, that give an idea of what conceptual integrity is all about. The first is from the philosopher Descartes.


He said of these thoughts on the very first that occurred to me was, that there is seldom so much perfection in works
composed of many separate parts,.


Upon which different hands had been employed, as in those completed by a single master. More recently, Fred Brooks, in,


The Mythical Man-Month, has said much the same thing. I will contend that conceptual integrity is the most important
consideration in system design.


It is better to have a system omit. Certain anomalous features and improvements, but to reflect one set of design ideas,
then to have one that contains many independent, and uncoordinated ideas. A couple of related concepts are coupling and
cohesion. These originally came out of structure design, but they also apply to object orientated design, and other
design approaches.


Assuming you've carved your system into separate components, those components may be coupled to each other. Coupling is
the extent to which two components depend on each other for successful execution. If you think about it for a minute low
coupling is good. After you've delivered your system, and you have to maintain it. If you have a highly coupled system,
and you change one module, that means that you're likely to have to change other modules. Whereas if there's low
coupling, that likelihood goes down.


A related concept is cohesion. With cohesion we're talking about a single module, and cohesion is the extent to which
that module, or component has a single purpose or function. High cohesion is good.


For example highly cohesive modules are much more easy to reuse.


They have a single purpose. You need to reuse them to accomplish that purpose.


23 - Java Quiz 1
----------------

Here's a two part quiz for you having to do with coupling and cohesion, and the Java language. Which of the two
possibilities reduced coupling, or increased cohesion, is Java's package designed help with?


Reduced coupling or increased cohesion?


24 - Java Quiz 1 Solution
-------------------------

Packages are for reducing coupling. A package encapsulates a set of names and requires the programmer to explicitly
import those names in order to get access to them. So a module can't get access and depend upon the names in another
module unless it's been explicitly imported.


25 - Java Quiz 2
----------------

Second part of the quiz. How about Java's class inheritance mechanism, does that decrease coupling of increase coupling
between the parent and child classes?


26 - Java Quiz 2 Solution
-------------------------

It actually increases coupling. That is the child knows about and depends upon, the details in the parent. This can be a
problem, if you then later change the parent.


27 - Information Hiding
-----------------------

Next concept is information hiding, developed by David Parnas. And it has to do with encapsulating the capabilities that
a particular module has behind an abstract interface. After all, if the rest of the world that's going to make use of
that module only knows the abstract interface.


It gives you freedom later to change the implementation details without breaking all the client programs. One key
example of information hiding is if you're dealing with a system that has access to many hardware devices, hiding that
access to the devices behind an abstract interface.


See if you can come up with some other good examples of places in the system where you might like to hide information
behind abstract interfaces.


Some typical examples include access to a database or some server some place, the specifics of an algorithm or how
you're implementing, a data structure.


28 - Abstraction and Refinement
-------------------------------

Now another pair of concepts.


Abstraction and refinement.


All design methods support these ideas.


After all, we're dealing with large systems and the only way that we can wrap our mind around those large systems is to
think about them in terms of abstract concepts, and then how we're going to refine each of those abstract concepts into
lower level implementations.


Programming languages, design techniques typically provide some conceptual mechanisms for dealing with abstraction.


Here are a few, for example, the whole process of specification where we're dealing with the what, abstracts away all of
the details of how we're going to solve the problem.


Programming languages is typically have various aggregation abstraction such as arrays and structs and records and
objects, that allow you to, if you wish, avoid the details of what all the features of those aggregations are.


Obviously in object oriented languages, the whole idea of the class hierarchy and generalization allows you to abstract
away from all the special cases.


Even a fundamental thing like the, the parameters to procedure calls are function calls.


Allow you to abstract away from what all the various possible calls to those functions are by specifying names for the
parameters rather than all of the specific arguments.


And finally, non-determinism, at least at the specification level, where you can avoid giving details of exactly how
you're going to implement something by specifying that you in certain circumstances, you don't care.


29 - Aesthetics
---------------

Now let's come back to aesthetics.


I mentioned this at the start, and I wanted to see how some two, in particular, two classical authors have kind of
captured the notion of aesthetics and what relationship that might have to software design.


The first is Aquinas.


I won't quote for you the, the Latin but what it, what it boils down to is that beauty, elegance, resolve to wholeness,
harmony and radiance.


And we can think of that as far as software is concerned as completeness, consistency and conceptual integrity.


Other quote comes from Pascal, you may have heard of the Pascal programming language.


Pascal was a French mathematician, and one of my favorite quotes is he said, he apologized in a letter saying, sorry I
didn't have I would have written you a shorter letter, but I didn't have time.


If you think about it for a minute, what this means is it takes a lot of time and energy to come up with an elegant
solution that looks quite simple on the surface, but really satisfies the complex requirements.


30 - Design Philosophy
----------------------

Finally, I'd like to finish this lesson with talking about philosophy a little bit. And these insights come from the
Danish Design researcher Piete En, and he is relating the process of software design to the thinking of four important
philosophers. So, first philosophers, Descartes.


We think about Descartes with analytic geometry. And this may translate for us into thinking about the analysis phase of
software design.


On the other hand, Marx is very concerned with social processes and classes. And understanding the social context of
design, maybe even involving the users in the design process. Martin Heidegger, was concerned, among other things, with
tools. And of course, tools play a big role in the automation of our development process and tools like IDEs in our
active development environments and case tools, computer aided software engineering tools of course play a big role.


And finally, my favorite is Wittgenstein, the Austrian philosopher, who came up with the concept of language games. And,
what this means, is the inventing of a vocabulary, that helps you think about a particular problem.


For example, think about the introduction of personal computers and the role that thinking, the role of the terminology
of the desktop, folders, trash baskets, and so on, play in doing that.


31 - Metaphors Quiz
-------------------

Can you think of some other metaphors that are important to us in, in dealing with computers place your answers into the
text box


32 - Metaphors Quiz Solution
----------------------------

Here are a few that come to mind. Client-server organizations for systems, icons, firewalls. There are many more.


33 - Summary
------------

Tying up this whole lesson, the important thing is that design is the most creative part of the software development
process. Consequently, overall system quality is highly dependent on the designs produced.


A key determinate of design quality is the extent of experience of this, on similar projects in particular, of the
members of the design team.


