.. title: P3L2 Overview of Architectural Styles 
.. slug: P3L2 Overview of Architectural Styles 
.. date: 2016-05-27 23:49:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L2 Overview of Architectural Styles
=====================================


01 - Introduction
-----------------

With this lesson, we begin the second major unit of the course on software architecture. Which is you recall, is the
highest level of expression to a design problem. In actual practice, software architecture and industry usually amounts
to the preparation of a slide for display that contains some boxes and arrows depicting the major components of a
system, and how they're connected together. We want to take a more principled look at what this essential aspect of
software design is all about.


Here is such a diagram. The boxes depict major components of the system, and the arrows indicate some form of dependency
among the boxes. It might be the flow of control, it might be the flow of data. The point being is that the, there's no
actual semantics to the diagram that is universally accepted.


02 - Informal Definition
------------------------

Let's start with an informal definition of software architecture. It is the organization or the breakdown of the system
in to component subsystems or modules. Architecture is almost universally done in layers.


That is, there's a most abstract version, and then the components of the abstract version are broken down into sub-
components, subsystems and so on, until we get to a level, a low enough level where things can actually be implemented.
So, for architectures as we mentioned a second ago, often also make use of a stereotypical architectural styles and
we'll be looking into those styles in this lesson.


03 - Analysis to Components Quiz
--------------------------------

1


Here's a quiz.


2


Assume we want to determine the components of a software system based solely on


3 an analysis model.


4


Given this situation, mark each text box below either true or false.


5


First box, analysis models can adapt well to changes in customer requirements.


6


Second question,


7 analysis models should represent the approach that will be taken in design.


8


Third, analysis models are resilient to changes in hardware.


9


Fourth question, analysis models include all components required by a system.


04 - Analysis to Components Quiz Solution
-----------------------------------------

Here are the answers.


First question.


Analysis models can adapt well to changes in customer requirements.


This is true because analysis models are constructed before design, therefore they should not be affected by design
constraints and can adjust more easily to changes in customer requirements.


Second question.


Analysis models should represent the approach that will be taken in design.


This is false.


We actually want to avoid mixing analysis and design together or else we might bias the design approach that is taken.


Third question.


Analysis models are resilient to changes in hardware.


This is true.


Analysis models should not make assumptions about the running environment of a system and can adjust to changes in
hardware.


Fourth question.


Analysis models include all components required by a system.


This is false because there will likely be additions to a system for collection classes or other types of utility
classes that an analysis model would not specify


05 - USP Definition
-------------------

Here is a somewhat more formal definition from the definers of the unified software process. I'm not going to recite it
for you, but


I will mention several key elements. One is architecture is all about decisions, choices that the architect makes about
how which, which components are there, how they interact, and how the non-functional requirements are being dealt with.


As far as the components are concerned, these are structural elements, and they're interfaces, that is what they provide
to the rest of the world, and what they require from the rest of the world. Components interact, they, they engage in
collaboration with other components, and it is the composition of these structural and behavioral elements into larger,
and larger subsystems that form the overall architecture. This structuring, this, this composing may be guided by
architectural styles, that provide guidance as to or bring in experience that others have had with building similar
systems.


The decisions about software architecture, concern not only the structure and behavior but other important elements,
such as usage, performance, comprehensibility, understandability, economics, technology constraints and trade-offs and
aesthetic concerns.


06 - Other Definitions
----------------------

Some other definitions we want to, to pull from during this lesson are, one from


Dwayne Perry and Alex Wolf, that involves elements, forms and rationale.


Rationale being the set of dis, the, the decisions and reasons for making them, that the architects have agreed on.


Obviously, architecture involves the fundamental organization, components and relationships.


This comes from the IEEE definition.


Another element from Verhoff is the determination of what makes up the components here based upon hiding away those
things which are hardest to change.


That's a little bit different way of thinking about a system.


But if you imagine what the system is going to be like several years after its initial release, it's going to change.


And those changes have the potential of breaking the system in unexpected ways.


So by hiding away those tough decisions we can help reduce the overall maintenance cost downstream.


And then for the rest of this lesson, we're going to be guided by the Garlan and


Shaw paper which is listed on the class resource page, and they talk about architecture in terms of its components, its
connectors, and its configurations.


What do they mean by these three terms?


Well, a component is a computational or a data element, plus its interfaces, which they call ports, interfaces to the
rest of the system.


The interfaces express what the component requires or needs from the rest of the system, and what it provides.


Recall from the UML component diagrams, this is exactly what the interfaces, represent.


A connector is a, essentially a communication protocol among components, although it may have code associated with it
for enforcing that particular protocol.


It is its, its major element of defining the character is that protocol.


And then configuration is how you put those pieces together.


You plug a connector into a component.


You plug the other end of the connector into another component if it's a binary connector, and the ports then can talk
to each other using the connector.


That overall topology for the pieces is called a configuration.


07 - Components
---------------

A couple of takes on components one from Richard Taylor, a software component is an architectural entity.


It's concerned with a unit of the system's functionality or its data.


Once again, key here is the interfaces that it provides to the rest of the world, and, according to Taylor, the
dependencies on its required execution context.


What that, what that means is, what does it take in order to enable the component to run in a manner that it should?


Szyperski offers the following, that a component is a unit of composition.


We're going to take components, we're going to put them together with contractually specified interfaces.


This means that the interfaces are explicit, the other components know about it, they agree to it, and that these
interfaces when you're putting things together in configurations can be checked and enforced.


08 - Selecting Components
-------------------------

The obvious approach to selecting components is to say, well what is it the system is supposed do or compute and break
that down into, into pieces.


However there are many other factors that might go into deciding which components are going to be part of your system.


Of course, required functionality is, is most important there, but it may also be the case that you already have some
existing reusable components from your libraries that you want to build into your system.


And that may have a important role in deciding on the overall component structure as would the physical machine
architecture, that is the architecture providing you multiple cores in which case how can you take advantage of those
in, in breaking down your computation.


Another element you might not have thought of is your staff, that is the people who are going to do this.


Conway's Law say's that the ultimate structure of a system depends upon the structure of the organization building it.


So it's well to take into account that if you have three people helping you lay out the architecture you're likely to
end up with three major components.


Another important element is that for real systems they're going to have long lifetimes.


And the trajectory of that lifetime, the direction in which it's going to move as we saw in the Brohoff definition,
could and should strongly influence the components into which you divided.


09 - APIs
---------

A word about API's.


I've mentioned it requires and provides part of the components description.


This is sometimes called the component's application programming interface or


API. If you look at documentation for systems at the level of Javadoc for, let's say a bunch of software you may
download. The description of the, of the classes and what their methods are and so on, are this, is that, is that
classes API. It's going to include the names by which you can refer to the elements of that particular unit for example,
the method names, the arguments you, you provide to that component, and, and their types, the return value and so on.
The API could be specified in a particular programming language.


If, if it's, if that's the case, it's called the language binding.


It might be described that a higher level of abstraction, such as using OCL. And a little later were going to look at
specialized notations for describing APIs at the architectural level called Architectural Description Languages, or
ADLs.


10 - Connectors
---------------

That's what I wanted to say about components.


In a sense components are easier because, you're going to, devise them in terms of the functionality, and the
functionality is, dominates what's in the requirements, specification. Connectors are trickier.


Okay. Connectors, are, where the designer has to make some specific choices about how to deal with problems. Taylor's
definition is a, a connector is a, a software connector is an architectural element tasked with effecting and regulating
interactions among components, the piping between those components.


The key way that I like to look at connectors is they provide a protocol for interaction among those components. A
protocol is a kind of a language saying who speaks in what order. What information is passed back and forth, and what to
do if something goes wrong. We're going to later in the course, devote a whole class to discussing connectors.


11 - Example Connector
----------------------

1


As an example, the simplest connector I can think of is a procedure call and


2 return. This is a pair of messages. The first one you're calling some method,


3 and second you're getting every turn value passed back.


4


This is an asymmetric relationship, okay, that is the caller,


5 okay? One of the two roles for the, for the connector is caller and the other's


6 callee. The caller waits, once he's issued the call, for the callee to re,


7 return. Okay? It's a synchronous relationship because the caller blocks or.


8


Stops any further computation. The connector also allows for


9 the passing of information in terms of typed parameters and


10 the second message may include a return value, also a typed value.


12 - Configuration
------------------

Assuming that we have the components and the connectors, now we need to wire them together. And we call that a
configuration.


It's a set of specific associations between the components and the connectors of a software system's architecture,
according to Taylor.


13 - Terminology
----------------

There's some other terms related to architecture that I"d like to mention for a minute just so that if we come across
them later, you'll know what I was intending. The first one is conceptual architecture. Obviously, the word conceptual
connotes that it's vague or high level. The reason is fake or high level is that it's often produced very early in the
development process, in fact before you may even have a complete idea of what the requirements are.


Conceptual architectures are often produces a way to begin the planning process.


Okay, by having an idea of what at a very high level the components and connectors are going to be, you can begin to
block out what the teams might look like and how long it's going to take to produce the ultimate program. A pair of
other terms to be aware of is the As-Intended versus the As-Built architecture.


During the planning process, the architectural planning process in which the architectural team decides on what the
architecture is going to be and produces some documentation for that, the result is the As-Intended architecture.
However, during the course of actual construction of the program, something else may be built, and we'll call that the
As-Built architecture. There are several reasons why the As-Built may not match ideally with the As-Intended. It may be
the case, for example, that during the course of refinement, the development team comes across a available component,
whether it's open source or from another group, that can short cut the development process by providing some needed
functionality. But that additional piece may not match identically with what was intended in the architectural plan.


This process by which the As-Intended becomes the As-Built is sometimes called architectural drift. And if it happens
during software maintenance, that is, after the program is released and the maintenance team then is dealing with bugs
and enhancement suggestions, the term is sometimes called architectural erosion.


This may arise because the maintenance team, under time pressure to get the fixes out to the customers, may not make the
ideal fix that would be done if, if the original development were done in a way that was aware of this particular
problem or enhancement. and, perhaps also didn't go back and make the appropriate changes to the architectural
documentation.


14 - Architectural Views
------------------------

In another lesson later on we're going to be looking at architectural views.


But to anticipate that I'll just mention that architectural description is not just a diagram, it's a set of decisions.
And in fact the, in order to fully communicate that set of decisions, many diagrams and/or textual documents might be
produced. We call these architectural views. Because the set of decisions may be large, and there may be many different
aspects to it, okay? Over the course of time various different kinds of diagrams and tables have been developed and
found useful and so we want to be aware of what those are so if you are confronted by a situation where you need to
convey some aspects of the architecture, you have you're aware of the various diagrams and, and textural processes you
could apply.


15 - UML Diagram Quiz
---------------------

1


In earlier lessons, we reviewed UML and recall that there were lots of different


2 diagrams that UML provided. Some of those might be useful for


3 conveying aspects of software architecture. See if you can list some of


4 the UML diagrams that might be appropriate and place them in the text box.


16 - UML Diagram Quiz
---------------------

Well it turns out that most of the different kinds of UML diagrams could be so used. Of the 14 diagrams I've listed here
nine of them that might be, might be appropriate. Of course a given diagram, like a class model diagram, might be useful
at a very low level that we wouldn't even call architectural.


What it also could be used for lending out what the major classes of a system are. As with some of the other diagrams
they can convey the structural elements, but also some of the UML diagrams can convey the behavioral aspect. For
example, sequence diagrams and communication diagrams. And at a most abstract level in terms of dealing with a systems
overall usage and how its going to be broken out into different aspects of functionality, use case diagram could be
useful for those circumstances.


17 - Architectural Styles
-------------------------

Most of the remainder of this particular lesson is going to be concerned with architectural styles. As with buildings,
software systems come in, in, of different types. Okay, we call those types architectural styles. Taylor's definition of
an architectural style is a named collection of decisions.


Those decisions are appropriate in a particular circumstances that is dependent upon you know, the system specifications
and its major concerns.


The design decisions constrain, what are the possible components and interactions and by using. The architectural style.


You get various benefits from it on the ultimate system you're you're building and the process of building it.


18 - Arch Style Quiz
--------------------

For this quiz, I'm going to list some decisions and you tell me what architectural style it might apply to. Don't worry,
it's a fairly commonly used architectural style. For this particular kind of system, we're going to have software
components that are physically separated, that means on different machines. Some of the components are there to request
services from other components that provide those services. By so doing, this allows for scaling. In the situation where
the number of requests grows over time. We're going to have that the service providers are unaware of the identities of
the service requesters unless those, service requesters provide that identity information. We're going to in this
particular architectural style it isolates the requesters from each other.


They're aware of the service provider or providers but not each other and we're even going to allow for multiple service
providers the number of which may grow dynamically depending upon the demand for the services that are there. Can you
name this particular architectural style?


19 - Arch Style Solution
------------------------

1


Of course, it is the common client-server architectural style. The server is


2 usually a database server. They may be some business logic associated with it,


3 and the clients these days are typically on web browsers making requests over


4 the internet to the database in business logic.


20 - Architectural Styles cont
------------------------------

The benefits that Taylor eluded to included, include the fact that what we have done by documenting an architectural
style is encode our experience on it.


For example with the client server there are certain ways of, of dividing things up and, and connecting them together.
That, work better than other ways.


We also know, with client server what kinds of problems can arise and, how we can best cope with those. And having that
knowledge then allows us to, reduce our overall development effort because we're not stumbling down blind alleys.
Architectural styles can also be encoded into Standards.


Standard sometimes call reference architectures. And those Standards can then support the validation process, the way
that we check whether our architectural solution is, is a good one. Architectural styles can also support Reuse.


The fact that there are, all kinds of, client server.


Systems out there means we maybe able to make use of standard components such as [UNKNOWN] database server. And because
different styles provide different ways of, of structuring the development process, we may even, even be able to. Use
the, the style to guide us in, in what our groups should look like and the steps that they should take when validation
can come and so on. What I'd like to do now is have a look at some of the different architectural styles that have
arisen over the years


21 - Catalog of Styles
----------------------

What I have here is essentially just a big, long list.


And I'm not going to go into all of them, but I will make some, make some comments that are appropriate to a few of
them.


The idea for throwing these at you is that as I said, the key to software design is having experience.


Experience means being aware of possible solutions, and here's a catalog of solutions that have been applied in certain
circumstances in the past.


In the KWIC quick exercise that you undertook you saw the abstract data type architectural style as did the, as you did
the batch sequential one.


Blackboard architecture is one in which the various components post their results and their requests on some kind of
common data repository, and the other components look at the repository and see if there's anything they can react to.


The fourth one here, the big ball of mud is not really any architectural style it's an absence of one.


It usually arises of because of the process of architectural erosion, or because the team didn't even have an
architectural design process in the first place.


We also have already have mentioned client server.


We'll talk about component-based systems later in the, in the course.


This use of the term component is somewhat different than the one we've been using in this particular lesson, but we'll
make that clear when we get to it.


You may not have heard about coroutines.


So I want to ment, take a, take a second to mention that.


With subprograms or subroutines we mentioned that there's this asymmetric relationship.


There's a caller and a callee.


With coroutines, it's a symmetric relation.


Okay? A can call B and B can call A.


Okay? Moreover, if A calls B for a second time, B continues from the point that it was last at when it returned from the
first call.


These are called coroutines.


A primary example of coroutines.


Think about printing out formatted data.


With printing out formatted data such as with print F, typically you have a a list of formatting information and a list
of data items.


And you, the implementation proceeds by taking a, the first formating information and the first data item and then
connecting them together.


Then getting the second format information information and the second data item, and there may be some loops involved,
some formatting information may allow for multiple occurrences.


Moreover the data provided maybe in the form of a loop.


So we're really going back and forth between these two streams of information, and a coroutine is a perfect a perfect
style for dealing with that kind of situation.


If you've got a sequel database and you've got some experience with this, you know that you can include in your standard
sequel some other functions that you've written.


If you do that sometimes the architectural style is called data centric, you, that is, you're using stored database
procedures.


In this course we won't be getting into domain modeling very much but there is a architectural style called domain
driven design.


And here, by a domain we mean a kind of application program.


So think about, for example, tax processing software.


With tax processing software, there's certain vocabulary that everybody's familiar with such as deductions.


And there's typical ways of solving problems.


So, if you've ever used your TurboTax or other tax preparation software, you know if you change something over here,
other things will get changed automatically for you.


That style of data flow updates is inherently part of the tax preparation software application domain.


And so by organizing your tax appropriation software using this particular domain architectural style once again you can
save yourself effort.


We're going to be looking more extensively at implicit invocation.


And, and also in the Garland and Shaw book that's listed on the resources page there's a very nice section that talks
about all the possible options for implicit invocation architectural style.


Another very popular one is layered architectures, in which each layer in the system acts as a virtual machine,
providing capabilities to the layers above it.


22 - More Styles
----------------

Historically probably the first architectural style that became pervasive was called the Master Control. That issued
right at top level routine that was responsible for organizing the use of the lower level routines.


Some of the other ones listed on this particular list listed here.


Are more recent message bus is an analogy with the bus, the hardware bus that organizes computations on a chip message
bus often means asynchronous message passing over some common data channel. With your smartphone or other mobile devices
there are a set of constraints that you have to deal with.


That you wouldn't have to deal with in other kinds of applications. So architectural style in support of mobile code.
Where there might be remote remote evaluation and you have agents of various places on a network is an example of mobile
code architecture and style.


The term object-oriented architectural style is a little bit different, than, object-oriented programming or object-
oriented programming language. But with the object-oriented architectural style, we still have objects, but each of
those objects have an independent existence that is they're running all the time, they have their own thread of control,
and they're sending message to each, messages to each other. Assynchronous messages.


This will allows them to cooperatively address a, address the problem being solved. Peer to peer network, you may have
heard of.


Here there are equal parties sharing responsibility for providing whatever services. Plug in architecture. If you are
familiar with some interactive development environments like Eclipse, you know that there's a whole registry of
available additional functionality that you can plug into Eclipse.


And the mechanism for doing that is a very powerful way of adding extensibility to systems. Pipe and filter you've seen
before with a quick a quick exercise.


One you haven't seen probably, is process control. Think here, nuclear reactor. Think here, your speed control on your
car.


The situation is you have some ongoing hardware process and you'd like a corresponding software. Application to control
that process.


If the process is going too fast, you want to slow it down. If it's going too slow, you want to speed it up. This is
called process control, and its key element is some kind of feedback loop. From the artificial intelligence world,
there's production systems. These are essentially a collection of rules, and the conditions under which the rules fire.
It enables the modeling of systems where we don't have a clear idea of what the control flow needed to implement the
system. A very popular one these days is, is Rest.


Rest stands for representational state transfer and you could think here it's those internet applications that are using
HTTP. that, often have a client server type relationship, and that are stateless, that is each of the, user requests are
handled independently, and some potentially some caching going on to improve performance.


Service oriented architecture or SOA, is where we have carved up the functionality of the system into separate services.
That is, from the users point of view, a service is a unit, a self contained unit of, of, of functionality and that
means that we have to imagine the architecture of the system as being able to support a set of, a set of services.


These are typically done in support of enterprise type applications, and often with internet connectivity between the
user requests through some browser, and the ultimate service being provided by some server. Shared nothing is a term for
a distributed database with no sharing across across the nodes.


I don't have, personally have, a lot of experience with that one.


Stay transition systems, on the other hand, are very common, particularly if yo have a situation where the system is
driven by events, assynchronise events, and has to react to those events. A typical example is, if you've got a GUI and
the user is providing the events. But it could also be some kind of real time system where the events are coming from
the outside world. Shared memory, we saw from the, from the quick exercise and finally we have table-driven interpreter.
For certain kinds of applications where the requests take the form of simple expressions in some kind of language we can
deal with those requests by having a, an interpreter.


The interpreter is essentially taking the request parsing it, and then invoking the, whatever procedure is required to
deal with that sp, specific request.


23 - Style Issues
-----------------

1


Although it may sound like, all the problems have been solved by


2 just selecting the correct architectural style, there are still some issues.


3


One important one is that for real systems, big systems it may


4 require more than one architectural style. We call that a Heterogeneous system,


5 you can imagine for example that the. System might have


6 some client/server elements that might have a GUI make it reactive. It may be


7 the combination of a variety of, of, of of different approaches and the systems,


8 you still have to have an architecture so that, so you have a single concept for


9 how the system is going to work. Secondly. Some situations, although


10 they call for having an architectural style, style are very domain specific. For


11 example, imagine in military context of a particular kind of airplane.


12


It may be the case, it is the case that that airplane comes in a variety of


13 variants. However, the control systems for the airplane is pretty much


14 the same across variance. That is, it shares more than it differs.


15


In this situation, we call it a Domain-specific software architecture, or


16


DSSA. Another term sometimes used is reference architecture,


17 that is the reference architecture describes what's common. And then for


18 any particular variant, the architecture responsible for


19 saying what those variants are, and how they're going to be dealt with.


20


The third issue is one of semantics. It's easier for me, it's easy for


21 me to lay out and say, a client server is XYZ. But what exactly does that mean?


22


It's important, and as the field of software architecture evolves,


23 to get more and more precise definitions of what these styles mean.


24


Which will then enable, reuse of, of existing solutions.


24 - Architecture Description Language
--------------------------------------

I hinted earlier in the lesson about architectural description languages. These are, as it sounds, notations for
describing architectures. They provide an extra modicum of formality and precision, that goes beyond just having a
diagram.


Moreover, by having that extra precision, it then enables some tool support. For example, building to diagram the tool.
Diagram a solution in such a way, that the diagramming tool can check for whether you've done things well.


Analyzers, okay, for determining the structural properties and behavioral properties of your system. And even
simulators.


I've listed here some of the popular architectural description languages.


The one that we'll be looking at a little bit later is called Acme.


25 - Architectural Evaluation
-----------------------------

The final thing that I wanted to mention in this overview of software architecture, is evaluation. It doesn't do you
that much good to develop this fancy architecture, if it's not the right one. Okay? So, we need some process by which we
can judge the correctness, completeness, consistency. And other quality aspects of the architecture we've produced.


Because of its, the importance of software architecture on the ultimate product being developed, it's key to get it
right.


Because if we make a mistake, it's very costly to make a change. So, some approaches have been developed for dealing
with architectural evaluation.


One of those, is architecture review boards. That is, for large systems which are developed by multiple teams. Or, maybe
systems of systems. Making a change can have impacts on various unexpected places in, in the ultimate system. And so
it's good to have the stakeholders, particularly development stakeholders, sit down and evaluate the impact of those
changes. Some organizations have, formalized this into a periodic meetings. That review suggested for architecture,
suggestions for architectural changes. Also some, so, some evaluation techniques have been developed. Software
architecture assessment method, or SAAM. I'm going to show you a slide on this. It's, is a relatively informal one. More
formal one developed at the Software Engineering Institute, is the Architecture Tradeoff Analysis Method, or ATAM.


26 - SAAM
---------

Here's a sketch of SAAM. Assuming that we have already gone through an architectural design process and if we produce
some artifacts like diagrams.


So we generate that architecture. We also generate some scenarios.


Now these are not primarily usage scenarios, or we could think of them as, as elaborated usage scenarios. Where instead
of looking at it from the outside, external view, we're looking for it internally. So for example if, if the external
request is by the user to compute some result, the generated scenario here that we, the team provides is which elements
of the architecture are required. To, be involved in providing that functionality. And in what order. That is, we
essentially are going to, walk through the diagram and see how that particular usage of the system impacts the
architecture.


This is particularly important if what we're talking about is a new scenario.


That is imagine the system that was architected one way and we want to add a new a new, a new functionality to it.


Imagine also that maybe there are thoughts on different ways of doing this. So if we had alternative proposals. Each are
provided in the form of some kind of diagram, we could walk through the two diagrams and see which one, in which one,
there's more impact of the change.


We might want to go with the solution which has the, the lesser impact. And so imagine this all happening in some kind
of design review meeting, in which we systematically go through that proposed changes.


The proposed architectural responses to them. And use the gathered information to come, to come to some kind of
conclusion about the way forward.


27 - Summary
------------

Well, the intention of this lesson is to introduce you to the topic of software architecture. That we're going to be
looking at in more detail in subsequent lessons. The ultimate goal of course, is to produce high quality systems and
reduce the cost of producing them. The key way of doing that is the early detection of problems. And the key way of
detecting things early is to try to layout in advance, what the, what the system is going to look like.


You want to have explicit recognition of what the issues are, explicit rationale for how they are being handled. We want
to be able to on the productivity side to deal with any existing assets we can apply toward the solution. And we want to
be able to construct an architecture at a sufficient level of abstraction. That it can be used to convey all these idea
quickly and effectively to all the stakeholders involved.


