.. title: P3L5 Non-Functional Reqs & Arch Styles 
.. slug: P3L5 Non-Functional Reqs & Arch Styles 
.. date: 2016-05-27 23:52:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L5 Non-Functional Reqs & Arch Styles
======================================


01 - Non-Functional Reqs  Arch Styles
-------------------------------------

Software architecture prescribes the high level structure of a system in terms of it's components and how they interact.


A key determinate of course of the architectural is the functionality the system must provide.


Also important is that the system must satisfy a set of possibly confic, conflicting nonfunctional requirements.


This lesson will provide guidance on the latter aspect.


The material in the lesson is drawn from the book by Bosch listed on the class resources page.


02 - Qualities
--------------

Beyond the functionality that a system provides exists certain non-functional qualities.


These qualities are often crosscutting.


What this means is that their implementation is often spread across the entire system.


For example, consider re-usability.


It is not enough that one of a systems components is reusable, it means that most of the components and possible the
application as a whole must be easily applicable in other contexts.


Because of the crosscutting nature of non-functional qualities, providing them often has a strong effect on the system's
overall structure.


03 - Non Functional Qualities Quiz
----------------------------------

For our first quiz, because there are many different non-functional qualities that a system might have, see if you can
name three of them and put them into the text box.


04 - Non Functional Qualities Solution
--------------------------------------

Here are a few that you might have mentioned.


The ones that are underlined, we're going to consider further in this lesson.


In particular, performance, security, safety, reliability, and maintainability.


05 - Functional and Non Functional Requirements Quiz
----------------------------------------------------

For a second quiz, imagine a program that plays tic-tac-toe against a human opponent.


I've listed a set of four requirements, put an F next to each of the requirements that is a functional requirement and
an N next to each that is a non-functional requirement.


First, the system should check for illegal moves by the human.


Second, the system should respond to human moves within 5 seconds.


Third, the system must be written in Java, and fourth, the system should allow the human to use either a X or O as his
or her marker.


06 - Functional and Non Functional Requirements Solution
--------------------------------------------------------

For the first requirement, concerning illegal moves, that's part of the functionality of the system.


So your answer should be F.


However, the second requirement, that the system should respond within five seconds, is non-functional.


It's not what the system is computing, but it's how or with what quality the system is doing the computing.


Third, the system should be written in Java.


Once again, this is a non-functional requirement and the fourth one, the system should allow the user to use either an X
or an O, that's functional.


That's part of what the system actually computes.


07 - Quality Catalog
--------------------

So let's take a minute and exam each of these five non-functional requirements that we'll be using in this lesson.


After we do this we'll see how each of them influences systems built with different architectural styles.


For each quality we will provide a definition.


The ways in which the quality might be measured.


And some devices that are used to provide this quality.


First off for performance, the Software Engineering Institute's definition of performance is, that attribute of a
computer system that characterizes the timeliness of the services delivered by the system.


And we can measure this in a lot of different ways, in terms of response time, throughput, system capacity, system
utilization.


And there are many devices that programmers can use to improve performance for example caching, concurrency, memory
management, and so on.


The second quality we want to look at is maintainability, and this is the extent to which enhancements can be readily
added to a system.


This is sometimes also called evolvability, flexibility, adaptability, and so on.


The measures and we have talked about these earlier are coupling and cohesion, and there's many devices such as
encapsulation, publishing your interfaces, use of sub-classing, indirection, and wrapping.


The third quality is reliability and this is the likelihood of failure, of system failure, in a given period of time.


That is, the continuity of service that the system provides.


The typical measure for this is called Mean Time To Failure, or MTTF.


Some of the devices that can be used to provide a high reliability include redundancy, fault tolerance, and recovery
blocks.


Software safety is the extent to which a system protects against injury, loss of life, or property damage absence of
catastrophic consequences.


It can be measured in terms of the complexity of the system, the time coupling, and by fault tree analysis.


Some of the devices include hardware interlocks, in the case that the particular system has peripheral hardware devices,
and false containment strategies.


The fifth quality that we'll, that we will look at, it is security.


And this is the extent to which the system protects against unauthorized intrusion or provides confidentiality.


Security is measured by levels such as confidential and top secret.


And sometimes formal proofs are used to guarantee that the system obeys whatever its confidence level is.


Some of the devices include authentication, authorization, security kernels, encryption, auditing and logging, and
access control mechanisms


08 - Applications Quiz
----------------------

Those are the five qualities we're going to look at as a quiz for you.


The first column contains a list of the five qualities and the second column contains some sample applications.


See if you can match these up, that is, what application in column two is a best match or best represents the quality
listed in column one.


09 - Applications Quiz
----------------------

While weather prediction is a good tester performance.


The finer the grid on which the weather is computed, the higher the quality of prediction made, and so having many, many
computations on a fine grid, which might stress the performance of a system is the best way to get good results.


As far as security is concerned, online banking.


Certainly, you don't want anybody interfering with your bank accounts.


And so, having a highly secured banking system is important.


As far as safety conce, is concerned,


I want the cruise control software on my card to be highly, highly safe.


Maintainability, I'm thinking here of the Twitter API.


That is we know that there are many, many applications that are based upon the twitter API, and over time if we can
maintain stability and maintainability of that API, those applications won't be broken.


As far as reliability is concerned, I want my traffic light controllers.


So, at every intersection you come to where there's traffic lights those traffic lights are controlled by some kind of
control box, and we want that control box to be, the software on it to be as reliable as possible.


10 - Architectural Styles
-------------------------

Now that we've had a look at the five qualities that we're going to be digging into, let's also look at the
architectural styles we're going to compare them with, okay?


In particular, we're going to examine be examining the effect of the five selected non-functional qualities on system
architecture for each of these five styles.


The five we will look at are pipe and filter, layered architecture, blackboard, object-oriented software architectural
style, and implicit invocation.


So first, let's take a minute to recall the features of those particular architectural styles.


11 - Review of Architectural Styles
-----------------------------------

The definition of pipe and filter from Wikipedia is a chain of processing elements called filters arranged so that the
output of each element is communicated by a pipe to become the input to the next.


Layered architectures according to MSDN, the Microsoft Developers Network, is the grouping of functionality into
distinct layers that are stacked vertically on top of each other.


Communication between layers is explicit and loosely coupled.


Blackboard architecture, out of the artificial intelligence world, according to Wikipedia, is a common knowledge base.


Is iter, is iteratively updated by a diverse group of specialist knowledge sources, starting with a problem
specification and ending with a solution.


The object oriented architectural style according to MSDN is the division of responsibilities into individual reusable
and self-sufficient objects each containing the data and the behavior relevant to the object.


Note that object oriented architectural style is somewhat different than what we talk about an object oriented program
or object oriented process for developing programmers.


Finally, implicit invocation, according to Garland and


Shaw, is a component can broadcast events.


Other components in the system can register interest in those events, by associating a procedure that should be called
when the event is detected.


When the invent is announced by the system, the system itself invokes all of the procedures that have been registered
for the event.


12 - Pipe and Filter Performance
--------------------------------

Let's begin by looking at the performance issues when using the pipe and filter architecture.


On the one hand, the pipe and filter style can enhance throughput because the filters can run in parallel, that is,
concurrently.


So you're overall system throughput can be reduced.


On the other hand, an individual filter may be slowed down if it, if it is waiting for its supplier.


Moreover, if the hardware only allows one process to run at a time.


There maybe significant overhead due to contact switches among the filters.


13 - Pipe and Filter Maintainability
------------------------------------

So that was a quick examination of the affect of one quality, performance, on one architectural style.


Let's look at the affect of another quality, maintainability, on pipe and filters.


On the positive side each of the filters in a pipeline is an independent unit and this enhance, enhances encapsulation
and reusability.


On the other hand some changes, like the format of the data that's going through the pipe line may affect, all the, all
of the filters, thereby increasing their coupling.


14 - Pipe and Filter  Other Qualities
-------------------------------------

We'll now take a quick look at the other three qualities and their effect on pipe and filter.


For reliability, okay, the reliability of a pipe and filter system may be reduced because, the reliability of an overall
system is only as good as its weakest, weakest link.


That is, if any of the filters in the pipeline or if any of the pipes break down for some reason, the whole application
breaks down.


Safety may also be reduced because of the multiple dependencies.


On the other hand, it's easier to verify because all of the output comes from a single source.


Security benefits because of the simplicity of the architecture increases opportunities for authentication, encryption
and implementation of security levels.


15 - Layering Qualities
-----------------------

Let's now take a look at layering.


By and large, security is enhanced because it is straightforward to add a security layer between the system and its
environment.


As far as the effect of the other four qualities on layering, performance may be reduced because the response to
external events must be passed up and down the layers, which may in, may also increase context swapping.


Maintainability, on the other hand, might be improved because of the stable interlayer protocols and interfaces would
lead to well-defined and reusable components.


It may even be possible to replace an entire layer or insert other layers.


Reliability may be reduced because an event may be handled in multiple layers.


That is, making it hard to find, when something goes wrong, what the responsible layer is.


However the higher layers may have an oversight capability to provide the necessary redundancy to improve reliability.


As far as safety is concerned, similar to security, it maybe easy to insert safety monitoring layers.


16 - Blackboard Reliability and Security
----------------------------------------

Let's take a minute to look at reliability in blackboard architectures.


In a blackboard architecture, the independence of the components can increase system resilience.


That is, the system may continue to function in a degraded fashion if one of its components breaks.


On the other hand, because there is no overall definition of system behavior, it may be difficult to identify the cause
of a problem when something goes wrong.


As far as an advantage is concerned, access control and the blackboard architecture's enhanced because there's a common
data repository.


On the other hand, the flexibility of a blackboard architecture allows for the dynamic condition of new components which
may reduce confidence in overall system security.


17 - Other Blackboard Qualities
-------------------------------

With respect to the three other blackboard qualities, performance, because there's a lack of well-defined control flow,
may lead to redundant and administrative behavior.


For example, the polling of a repository.


Maintainability is enhanced because having independent com, components can lead to in, increased flexibility.


But if we make changes to the common control paradigm wherein the blackboard components are updating the repository, or
if we change the repository's data format, this can have pervasive negative effects on maintainability.


As far as safety is concerned, because the blackboard is a common repository accessible to all the components, if you
somehow get bad data un, that might lead to a safety problem, this can easily spread to the other components.


18 - Object Orientation Maintainability
---------------------------------------

Let's now have a look at the object oriented architecture style and its relationship to maintainability.


The object oriented architecture style is a very powerful way of organizing a system.


And maintainability is significantly increased when using this style, because of the independence of the components,
both their encapsulated data and the hands-off, message passing style of interaction.


On the other hand, objects will have to refer to each other.


Okay? There needs to be some way of identifying other objects in the system.


This can increase the intercomponent dependencies, thereby reducing maintainability.


19 - Object Orientation Security
--------------------------------

I'd like to examine the security issues that arise in object-oriented architectural styles.


On the positive side, the encapsulation inherented in obj, inherent in object-oriented systems, can reduce
vulnerability.


Negatively, the many relatively small and independent objects increase system fragmentation, thereby meaning many more
possible points of infection.


Moreover, the relatively unconstrained message passing paradigm can ease the spreading of a problem throughout the
system.


20 - Other Object Orientation Qualities
---------------------------------------

As far as the three other system qualities in an object oriented architectural style, performance has problems because
of the many small objects linked to multiple context switches.


And delegation, okay, whereby one object may refer to others to provide its functionality, this can increase
indirection, which can reduce responsiveness of the system.


With respect to reliability, decentralized control in object oriented system reduces opportunity for oversight.


But encapsulation can reduce vulnerability to undin, unintended interactions.


For safety, the correspondence between the real-world entities which the system is is modeling, and the objects that the
programmer has developed can improve the intentionality of the system and accountability, thereby enhancing the safety
of the system.


21 - Implicit Invocation Qualities
----------------------------------

Our fifth architectural style is implicit invocation.


And here let's first examine the question of reliability.


Well, if you're approached to event delivery, in an implicit invocation style it's centralized you are more easily able
to deal with unexpected events, thereby improving reliability.


On the other hand, because interactions are implicit, overall system understandability is reduced, potentially
compromising reliability.


Or the other four system qualities, performance, might be compromised because of the extra communication due to the
bookkeeping and indirection can lead to context swapping problems.


Maintainability, there may be increased reuse due to the independents of the components.


On the other hand, as far as safety is concerned, increased interaction complexity may make it harder to ensure safety.


And with to respect security as we saw with object orientated, object orientation, the fragmentation of an implicit
location architectural style can cause problems, but encapsulation can help to mitigate them.


22 - Side Effects Quiz 1
------------------------

Here's a quiz on architectural style.


Match each of the architectural styles with a negative effect it could have on system design.


The four architectural styles are pipe and filter, blackboard, object orientation, and implicit invocation.


The negative effects include increased system fragmentation, reduced system understanding, increased coupling, and can
promote the spread of bad data.


23 - Side Effects Quiz 1 Solution
---------------------------------

Here are the answers for this quiz.


First off, the answer for Pipe and Filter is C, increased coupling.


This is because some changes, like the format of the data going through the pipeline could affect all of the filters,
reflecting their tight coupling.


The answer for Blackboard is D, can promote spread of bad data.


Because the blackboard is a common repository accessible by all components, if it somehow gets contaminated this bad
data could readily spread to other components.


The answer for object orientation is A, increased system fragmentation.


Object orientation can increase system fragmentation because of the many relatively small independent objects that may
exist.


And finally the answer for implicit invocation is B, reduced system understanding.


This happens because server components are not aware of clients which can change dynamically.


24 - Side Effects Quiz 2
------------------------

Here's a related quiz on non-functional requirements.


Please match each of the following non-functional requirements with the side effect using it might engender.


The four non-functional requirements are reusability, reliability, security, and performance.


The possible side effects are increased system fragmentation, reduced system understanding, increased coupling,
compromised delivery schedule.


25 - Side Effects Quiz 2 Solution
---------------------------------

The answer for reusability is A, increased system fragmentation.


High reusability means high cohesion.


That is, that each module has a single purpose.


This might lead to more modules, and hence, to more connections among the modules.


The answer for performance is B, reduced system understanding.


Performance requirements often are dealt with via introducing special cases or


Achaean data structures, which can make the code harder to understand.


The answer for security is C, increased coupling.


Security means data security, and data security is provided by controlling access to the data.


This means that in order for modules in order to access the data, they need to go through some form of data access
control.


Which is typically provided by a centralized control module, to which all the other modules must be coupled.


Finally, the answer for reliability is D, compromised delivery schedule.


Increased reliability typically means extra code to check for potential problems.


Extra code means extra coding, checking, documentation, and so on, which can lead to difficulties delivering on time.


26 - Summary
------------

To summarize, non-functional qualities, not just the five that we've looked at but the whole, whole set of them, can
dramatically affect the architectural software system.


Moreover, real world systems often have multiple conflicting non-functional qualities.


This means that you as a designer have to make tradeoffs among them.


For each of the quality requirements of your system, be sure to take into account both the positive and negative impacts
that it will have on the overall system architecture.


