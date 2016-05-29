.. title: P3L3 Architectural Views 
.. slug: P3L3 Architectural Views 
.. date: 2016-05-27 23:50:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L3 Architectural Views
========================


01 - Architectural Views
------------------------

Building architects use sketches and blueprints to convey the architecture of a proposed building.


Similarly, software architects use a variety of notational devices called views for the same purpose.


It's well to remember though that an architecture is not simply a picture, it is a set of these important design
decisions made during the course of thinking about how the building or the software system is going to solve whatever
problem it's suppose to solve.


Specifically, software architecture conveys the set of components that will together compute a solution to the problem
while satisfying or not violating any of the require non-functional constraints as specified in the requirements for the
system.


In this particular lesson we will look at a variety of different graphical and textual approaches for conveying software
architecture views.


We will start with Philip Kruchten's 4 plus 1 architectural views paper which I asked you to read.


And then we will add in some different views that go beyond what he was talking about, the feature view, non-functional
requirements, bug reporting, context, and utility views.


02 - Logical View
-----------------

The first and probably the most popular of Kruchten's five views is the logical view.


This conveys the structural breakdown of the computational, communicational, and behavioral responsibilities of the
system.


There's lots of ways of conveying logical views.


Probably the most frequently used is a box and arrow diagram.


We'll see a slide in a second.


You've already encountered some of the UML diagrams that can be used to convey the logical view, including the class
model diagram, interaction overview, and collaboration diagrams.


And also, we will be seeing the components and connectors that are part of architectural description languages.


Here's a random box and arrow diagram.


It contains boxes which indicate the, the the functional components of a system, and arrows connecting them indicating
some kind of dependency between the boxes.


Box and arrow diagrams have the benefit of being familiar.


And usually can convey a whole lot about the high-level architecture in terms of a single slide.


However, they have the disadvantage of being imprecise.


Just what is it that those arrows mean?


03 - Developmental View
-----------------------

The second of Kruchten's views is the developmental view, and here we're concerned with the source code.


The logical view had to do with the system, primarily with how it's going to execute.


The development view has to do with the source code.


And the units of source code which might be considered for modeling in the development view include packages, classes,
subsystems, libraries, files, and so on.


UML package diagrams, UML component diagrams can convey this sort of thing, as can the mechanisms provided by source
control systems such as CVS or, or, or, or some of it's SVN or, or Github or some of the more modern modern systems
allow the developers to break the system into modules.


Here is a reminder of some of the slides that we saw when we were reviewing UML diagram types.


Here's a class diagram with packages, here's a package diagram, and here's a component diagram where the rectangles
correspond with the components.


The the arrows correspond to specific dependencies among the components indicating that a component supplies what is
needed by a component at the other end of the line.


04 - Diagram Types Quiz
-----------------------

Quiz for you.


Match the diagram in the first column with the text in the second column that most closely describes the meanings of its
lines.


05 - Diagram Types Quiz
-----------------------

The lines in the component diagram are going to indicate that one of, one of the components makes use of or calls upon
the resources of another.


As far as the package diagram is concerned, that's an indication of importing, particularly the names, or a sub-
component of, or is merged with.


And finally, the class diagram, of course, the particular lines on the class diagram correspond to generalization,
association, or dependency.


06 - Process View
-----------------

The third of Kruchten's diagrams is the process view, and here we're very specifically getting into what concurrently
executing processes or threads exist and how executed, execution is divided among them.


Primary means for conveying this is the UML deployment diagram.


Here's an example that we saw before where there are two major concurrently executing components and some indication of
how they're communicating with each other


07 - Physical View
------------------

The fourth of Kruchtens' views is the physical view, and this is very close to the previous one.


Here however we are concerned with how the processes are allocated to the various execution units.


And we can use the deployment diagram that we just saw, or we can use a sequence diagram here.


Here, as a reminder, is a sequence diagram.


The columns correspond to objects, which could be running on separate processors.


Recall that objects are like classes, except the names are underlined and there's usually a colon separating the name
from the class name.


Going down a column corresponds to the passage of time.


And the lines that cross it indicate messages being sent.


So here we have the, the coordination of three particular processes dealing with the handling of a transaction.


Collaboration diagrams had the same content as in sequence diagrams, but they're laid out differently.


Here's the corresponding collaboration diagram for the previous sequence diagram.


Same objects, same messages.


The numbers indicate the orders in which the messages are sent.


08 - Use Case View
------------------

The plus 1 in Kruchtens' 4 plus 1 is the use case view.


Use cases are important execution sequences from the external actors or user's point of view.


We'll have a look at the use case diagram that UML offers.


Some other UML diagrams that can be used to convey individual use cases.


And we'll even see some structured text that can convey a use case.


Here's a use case diagram from UML.


Each of the ovals corresponds to a use case.


The stick figures correspond to external actors.


Some of the lines indicate are, are labeled and indicate that the particular use case is used for a special purpose such
as being included in another use case or being shared among several use cases.


Important thing is that the use case diagram in UML conveys a set of use cases, not an individual use case.


09 - Context View
-----------------

Going back to our historical overview of, of modeling.


Recall OMT, the object modeling technique.


And it had both structural view and behavioral view, but it had a functional, and the functional view made use of what
are called data flow diagrams.


UML does not contain that particular functional view.


It uses use case diagrams instead.


But I wanted to show you the, the data flow diagrams because I have found them personally useful in describing
describing systems.


In particular, a data flow diagram conveys systems activities and the ordering in which they occur.


Data flow diagrams can be nested, and the outermost data flow diagram is called a context diagram.


In the context diagram, there's a single oval which denotes the system as a whole.


That oval can be connected to various external actors.


In the case of the context view, those aren't stick figures.


Instead they're rectangles.


And the actors can be individual users, or they even can be external systems which are communicating with the system
that you're modeling.


The lines that connect the actors to the system are called dataflow lines, that is there's some communication of data
between the actor and the system or the system and the actor.


Here's a context diagram of a system that plays chess.


The external actor is the human opponent and there are three flows of data.


The human opponent can submit moves to the to the chess playing program.


Similarly the chess playing program can communicate moves back to the human opponent, or the chess playing program can
produce a diagram of the current board situation.


10 - Individual Use Cases
-------------------------

I wanted to spend a moment talking about individual use cases.


Individual use cases are extremely valuable in understanding expected user behavior.


They're also used in, in the development shops that use agile methods in doing some of their planning and scheduling.


What it essentially is is a story illustrating a specific act, interaction between a user and a system.


I've listed here a story about buying from Amazon.


It's written out as just narrative text.


And there's no structure to it, but nevertheless, it's a way of expressing, in a very user centered form, a system
requirement.


We could take this same story and also express it in a structured way.


Here in tabular form is the same story, in particular there are three columns,.


The column on the left is the actor, okay?


And there are two actors here, the user and the Amazon website.


There are various actions that could take place.


And sometimes, optionally, there are objects, okay, that are used by the actor to perform the action, or produced by the
action, and those are in the right-most column.


11 - Feature View
-----------------

Well that's it for the four plus one views, but


I think there are some other views which are sometimes useful in understanding, or conveying your understanding, of a
system that you're trying to build at the architectural level.


One that I've found quite useful is a feature view.


A feature is a conceptual unit of system behavior from the user's point of view.


Your camera has a zooming feature available to it.


Or maybe it doesn't, okay?


Typically, features are something which manufacturers provide as options, that you may have to pay extra for.


Feature modeling is used for describing a set of features that a a collection of related applications provide.


There's feature diagram, which I'm going to show you in a second, that conveys the set of possible features that might
be configured into a particular product in that set of products.


The diagram is graphical.


It has icons and so on, but it can also have intra-feature constrains which aren't shown in this particular diagram.


Here's a particular feature diagram showing the features of a car.


At the top is the, what's called the concept or the main manufactured item and then under it are its features.


So the car, this particular car has four features.


Okay.


Three of the features are required.


The body, the transmission, and engine.


And whether or not it pulls trailer is optional.


Whether it's required or optional is indicated by the little circle at the end of arc connecting cart to its features.


If the circle is filled in it's a required feature, and if it's open; then it's an optional feature.


Features can have sub-features.


So, a transition sorry, a transmission can have an automatic transmission feature, or a manual transmission feature.


The or that I just said, is indicated by that open arc connecting those two lines coming out of the transition.


Similarly there are two kinds of engines, electrical and gasoline.


In this case the arc is filled in though, indicating that you can have a combination.


That is you can have a hybrid engine.


We could imagine a constraint here going between automatic transmission and pulls trailer, saying that the pulls trailer
option is only available if you have the automatic transmission and not the manual transmission.


12 - Feature Diagram Quiz 1
---------------------------

As a little test for you, take a second and figure out how many different possible cars are expressed by the feature
diagram that I just showed you on the previous slide.


13 - Feature Diagram Quiz 1
---------------------------

The answer is 12 cars.


To find this answer we can multiply the possibilities together.


First, we know a car body is required, and it has no sub-features.


Then for the transmission we have two options.


Either the transmission is automatic or it is manual.


For an engine, there are three options.


Electric, gasoline, or a combination of electric and gasoline called hybrid.


Finally, for the pulls trailer feature, we can either have the feature or exclude it.


Thus, we can multiply these numbers together: 1 times 2 times 3 times 2, which equals 12, for the 12 possible car
configurations.


14 - Feature Diagram Quiz 2
---------------------------

Second question is, which of the following are valid configurations for cars?


Car having a sunroof body, automatic transmission, gasoline engine, and pulls trailer.


And second, a sedan body, manual transmission, gasoline engine, and electric engine.


Third, coupe body, automatic transmission, manual transmission, gasoline engine.


And fourth option, number d, a hatchback body, manual transmission, and pulls trailer.


15 - Feature Diagram Quiz 2
---------------------------

Well, A is certainly allowed.


You can have the sunroof and the automatic transmission, gasoline engine, and pulls trailer.


And so is B.


But in C, you can't have both an automatic transmission and a manual transmission.


And notice, in D, we don't have an engine at all.


That's not much of a car.


16 - Non Functional View
------------------------

The second view not listed by Cruchen I consider to be quite important, and that's the non-functional view.


In coming up a software architecture, it's youre responsibility not only to describe a system that's going to compute
what it needs to compute, but also compute it in a way that satisfies those non-functional requirements.


Satisfying non-functional requirements is hard, it often involves some kind of tradeoff, okay?


So you need to be expressing what the options are and how you decided to trade things off, and I'm suggesting here some
tabular text.


Here's an example, if you imagine a web browser and you say, what's it's major computational responsibility?


Well it's displaying web pages.


Quite simple.


But if you actually look at the code for a web browser, it's filled with code having to do with managing caches.


There are page caches and connection caches and image caches and so on.


Okay?


Why are there caches?


Well, caches are a technique for dealing with performance constraints and non-functional requirement, okay?


So it's important to relate that information, first of all, that there is a performance requirement, and second of all,
what technique is being used to address that performance requirement, the caches.


17 - Non Functional Requirements Quiz
-------------------------------------

Here's a little quiz for you.


Along with performance, can you name three other important non-functional requirements with which a web browser must be
concerned.


18 - Non Functional Requirements Quiz
-------------------------------------

Well, we know if we're using that web browser to buy something from


Amazon there are security requirements.


Extensibility, we know that web browsers can have plugins to support different presentations of different kinds of web
content and portability.


We'd like our web browser to run on a variety of different platforms.


I'm sure there are others.


19 - Bug Reporting View
-----------------------

Another view which you may not have previously thought of as a view is I call the book reporting view.


If you've got a, a system you're developing most shops will have some kind of tool for reporting bugs.


These are bugs during development or these are bugs after delivery, and those bug reporting tools often have fields
which you fill in which indicate which component does the bug relate to.


I'm suggesting that those components had better correspond to the architectural components in your other views otherwise
there's the potential for some kind of confusion.


Okay?


Similarly, with respect to features, you would like the person who's handling the bug to be aware of, well, this
particular bug arose when the following feature was being used by the, by the user.


Here's a screen capture from a get based web browser interface into a source control system in which bugs are being
listed with respect to a particular component of that system.


20 - Utility Views
------------------

The last view I'd like to talk about is not really a view but a miscellaneous category indicating that there's a lot of
other information having to do with system structure that hasn't been conveyed by the other views we've seen.


Okay? This has to do with supporting software in files which are, are, are part of the system but maybe aren't part
directly of the executing software.


Okay?


And I'm suggesting that this information be conpeyed, conveyed in, in tabular text it includes things like installation
scripts, log file analysis, statistical processing, the make files that are there the configuration files for different
configurations for the system, any documentation.


Okay, the project manifests which describe system structure as part of a, a large delivery package.


And any supporting tools.


Okay, when you're building the system all of these pieces have to actually be there to contribute to the build and hence
they're part of this kind of grander architecture of a system.


21 - Conclusion
---------------

In putting this all together, an important point to get across is there's no such single, tangible thing as in the
architecture.


An architecture is a set of decisions.


You can convey some of the information about those decisions with various views, whether they're graphical or textual,
okay?


And their sum conveys the architecture.


For your purposes as a developer, you need to select the appropriate views depending upon the structure of the system,
that is the complexity and the application domain of the system and the particular people that are going to be looking
at those diagrams or reading that text.


