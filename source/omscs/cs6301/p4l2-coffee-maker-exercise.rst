.. title: P4L2 Coffee Maker Exercise 
.. slug: P4L2 Coffee Maker Exercise 
.. date: 2016-05-27 23:58:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P4L2 Coffee Maker Exercise
==========================


01 - Status
-----------

In the course so far, we have looked at analyzing problems, modeling them in


UML, and designing architectural solutions. Now we want to look at the actual process of designing objects. To get
started, we will do an exercise from


Robert Martin that involves designing software to control a coffee maker.


02 - Robert Martins Coffee Maker
--------------------------------

Here's how we will proceed. The following slide contains a textual descriptions of the functions of a coffee maker. It
is followed by a description of the API to control the coffee maker. Your initial task will be to use the API and the
textual analysis technique, we used at the start of the semester. To design a set of OO classes to control the coffee
maker. You're going to express your answer in the form of a UML class model diagram describing your design.


03 - The Mark IV Special Coffee Maker
-------------------------------------

So this is the Mark IV Special Coffee Maker.


We're going to assume that it is part of a series of coffee makers.


It's the current one but it won't be long before the Mark V is coming out, so we have to be concerned with you know,
the, the whole family of coffee makers and how things are going to change in the future. The Mark IV makes up to 12 cups
of coffee at a time. There's there's a filter that has to be filled with coffee ground, and it has to be, the filter has
to be slid into its receptacle.


The user then supplies some some water in, into the water strainer and presses the Brew button. The water is heated
until it's boiling. The pressure of the evolving system forces the water to be sprayed over the coffee grounds and
coffee drips through the filter, your standard, standard coffee maker.


The pot is kept warm for extended periods by a warmer plate, which only turns on if there's coffee in the pot. You don't
want that baking in those grounds and being unable to wash them out in the future.


If the pot is removed from the warmer plate while water is being sprayed over the grounds, the flow of water is stopped,
so that brewed coffee does not spill on the warmer plate. Those are our very high level description of what the Mark IV
is supposed to be able to do.


04 - Hardware Quiz
------------------

So one way of attacking a problem like this, is from the bottom up. That is, you are given a device that you are going
to provide software support for.


So determine what its capabilities are. Begin by making a list of all of the hardware devices that are part of the
coffee maker.


05 - Hardware Quiz Solution
---------------------------

>> Okay. And then there have to be some sensors, because, recall, we had to be able to determine whether there was
coffee in the pot. Okay and we had to know whether the all the water was gone, that is had been heated for boiling. So
we needed a sensor there and safety's always a concern so we better have a pressure relief valve which wasn't mentioned
in the requirements. But it's another example of coming up with requirements during the course of thinking about the
system rather than all in advance. And it's for reducing the pressure in the, in the boiler. In case some, something
goes wrong.


06 - Hardware
-------------

As is often the case in software development, the written problem description leaves out some other details. So to the
above list, let's add three more hardware elements, an indicator light when the brewing cycle is over so you know when
you can grab the cup and pour yourself some coffee. A censor for the boiler which determines whether the, water, there
is water in it to be boiled. You don't want to turn on that, heater in the boiler, there's no water there. And, we
mentioned the pressure relief valve.


07 - Hardware Design
--------------------

If we were designing the coffee maker as a whole and not just the software controllers for it, we would now spec out
each of the devices we just listed.


Fortunately, the hardware team has taken care of that task and we have been given a Java API for the hardware. The API
is available to you from the class resources page. It comprises methods and constant values.


The methods provide a way of determining the status of the hardware device and to change them as requested. The
constants give symbolic names to the inner, to integer values that, are needed by the controllers. Note that


Robert Martin wrote this example before enums were added to the Java language.


So he had to define them using the integer constants himself.


08 - Two Approaches
-------------------

In the first phase of this course, you learned about object oriented analysis, in which you searched for various
categories of words, nouns, verbs, adjectives, in the textural description of the system you were building.


Martin contrasts this approach to one in which behavior is central.


We will look at both, beginning with OOA.


09 - Traditional Approach Quiz
------------------------------

1


The traditional OOA approach to doing modeling is to search for


2 nouns, in the problem statement and model them with classes.


3


Do this now,


4 on the textual description of the coffee maker, and produce a list of nouns.


10 - Traditional Approach Quiz Solution
---------------------------------------

>> So, there's many, there's many nouns in this in this paragraph description. let's, let's concentrate on the ones of
those having to do with the electronics, the software for which we're going to be building in this example.


>> Okay. So, I have the water strainer, but in terms of the electronics, there's a sensor that we talked about being
associated with that, that would tell us whether there's water in it or not.


So, there's that, the brew button.


And any other kind of control widgets, the on/off light for the coffee's ready.


As well as the warmer plate.


We're interfaced with that.


I wrote down Mark IV special, that's kind of like the facade.


Everything we're looking at >> The overall system?


>> Right, so, there's that element as well.


The other heating element, to actually, create the steam.


And you know, and then the result with the coffee so those, those are some of the things that are listed.


>> Okay well we could have, we could go through the whole process here of underlining the nouns.


We could put them into groups, we could stem them just like we did before.


But for now it's enough to get a sense of the the particular elements we're going to have to be primarily concerned with


11 - Class Model Diagram
------------------------

So when you do this you could then come up with a UML diagram that organizes the important nouns related to the
electronics into a, into a diagram.


In this case there's main classes having to do with the coffee maker which as you indicated, then has parts
corresponding to the graphical user interface.


That would be the buttons and the, the lights to the the part having to do with the, the boiler which includes a sensor
and a heater and the warming plate which also includes a sensor and a heater. And then you might get excited by the fact
you have two heaters and have an abstract class for heater and the same thing for sensor and come up with a diagram that
looks something like this.


12 - Limitations Quiz
---------------------

One of the points of, of Martin's description of this is that this approach is going to get us into trouble.


So like you to take a minute and think about any, any difficulties you can foresee using this diagram to go forward


13 - Limitations Quiz Solution
------------------------------

>> So I, I hadn't thought about that. One of the guidelines, for OO design, is to break things up into very small
pieces. Okay?


There's reasons, to centralize. Okay? Both at the architectural level.


Where you would like to have knowledge concentrated because you want to control effectively. We might want to do things
with respect to safety or, or security, things like that. But also at the object level, if there are things that might
change separately. You probably want to have those in separate places, so you can change just what you need to change.


14 - Use Cases
--------------

So Martin suggests using an alternative approach to OOA is to write out use cases.


Recall that a use case is a simple story illustrating a single execution or pointing out an important obstacle that the
user might confront.


For the case of the coffeemaker can you come up with a few use cases?


What's brewin'?


>> So if they did press the brew button, but that was,


I guess, the first use case there's a couple of things that could happen.


Everything could be right, because all of our pre-conditions are there, or there could be no water for the brewing
process to start, or just the filter's not in place, or no coffee grounds.


Those are some problems that could happen.


>> So on, on that one notice that so far we haven't, we don't have an sensor for the grounds.


OK. So if there's no grounds in there you're going to get very, very weak coffee.


>> Okay.


>> And if there's no filter, you're going to get your coffee pretty quickly.


>> Right.


I guess I have a question that regards to that use case.


Is the problem of them not having coffee grounds something that the system should even worry about?


Because it seems like that would be hard to tell, like the filter being in place I can imagine being something a sensor
could tell.


But how much coffee is in your, your filter could be, maybe something that's not supported, I don't know.


>> So this is an issue with designing software and hardware at the same time.


So you could imagine, for example in the Mark 5 having a sensor for the recep, receptacle actually clicking in.


Okay.


When you, when you push it in there.


Trying to figure out how many grounds are in there or how, you know, how deep the grounds are or something our hardware
people haven't gotten that one yet.


Okay, so we're, we're not going to be able to sense that very well.


>> It sounds a little bit like trying to count jelly beans in a jar or something.


But anyways the other use cases I have involve remember moving or placing the pot because we have an indicator for that.


>> Right, right. >> So it's something that stood out.


And then also when you fill the water receptacle.


We have an indicator whether the water is there or not.


So that seemed to be a, an interaction that had something the user could see.


>> So let's consider four of those.


The user press, press pushes the brew button, and that's our primary one.


And then some contingent ones containment vessel is not ready.


The coffee is all gone or we could have that the, the brewing is actually complete.


15 - Brew Button Quiz
---------------------

So notice that in this approach we don't have a class model.


We just started with the use cases.


And we're going to actually derive the class model from looking at the use cases.


So let's look at the first use case, user presses the brew button and play through what happens.


First off, which of the three classes, which of these three classes receives this event from the hardware interface?


Check the, check the one that applies.


16 - Brew Button Quiz Solution
------------------------------

>> Sure, that's about as easy as you can get on these quizzes.


Okay, so that's indicating that we'd better have a class for our user interface that's going to be able to detect this
user event.


17 - Brew Button
----------------

>> So then after the user presses the button and the user interface detects it what's the, what's the next thing that
you expect would happen?


>> So I think that the next things that are hap, going to happen are going to be all of our checks to start the brew
process.


So we're- >> Make, makes sense.


>> Mm-hm. Check if the water's there, check if our receptacles in place.


>> Okay, so there's, there's two primary checks.


Do we have, you know, have we loaded up the water, and then, do we have a, a coffee pot to hold the results of, you
know, the coffee after we've brewed it.


So those are two checks.


Is does it matter which one we do first?


>> I don't think so.


Not necessarily.


>> Okay. >> Just as long as they're all held.


>> And so, I, I don't see either.


And so, we're not going to be concerned about that.


At that point things are ready.


We can, we can start the boiler to produce some hot water.


18 - Collaboration Diagram 1
----------------------------

So Martin then does is express these steps using a UML collaboration diagram.


We called that a collaboration diagram.


Was like an object diagram.


But the lines between the objects indicated our operations.


And the lines were numbered indicating the order of the operations.


So in this case, we had the steps of user interface getting, getting the request from the user with the brew button, and
then asking the hot water source for whether it's ready.


And then asking if the containment vessel whether it's ready, and then starting the hot water source heating up the
water.


So there's three steps labeled one, two, and three here.


And we can see that there's, there ought to be at least three classes supported to deal with those three possibilities.


>> Is it possible here for this diagram to be more descriptive?


In the sense that, it seems like when you ask the ho, hot water source.


Is it ready or not?


If it says it is ready, then you might make the next check to see if the containment vessel's ready.


But if it says no, it seems like a whole another steps set of steps may have to be taken to indicate to the user hey.


The water source, hot and ready to go.


>> Okay so remember that a use case, or a representation of a use case in a collaboration diagram or a sequence diagram
is not contingent.


Okay, it's, it's one step by step walk through the system.


And what we're going to have to do is to deal with contingencies which are obviously an important part of this whole
process.


We're going to have to have multiple diagrams.


And one of the things that Martin does is suggest that we can add together those diagrams.


So, I think that maybe is where you're going.


We want to have them, them all there.


But, wha, what we'll do them a step at a time, so to speak.


>> So we would have, I guess a use-case symbol user-presses brew button and a water vessel is not ready.


Like, that would be a separate use case and we can model and tie that in later with this situation, which seems like
we're pressing brew and everything's ready to go.


>> That's where we're going.


19 - Containment Vessel
-----------------------

So in fact, let's, let's go there, let's, let's go to use case number two, which was the having to do with the
containment vessel was not ready.


So our first use case asks the question, but the question might come out negative and in that case we have like a
contingency we have to, have to deal with.


So this is a variant on the, on the first use case.


So, in order to get there, the, the steps are that the query is sent to the containment vessel.


If it is not ready then a message must be sent to the hot water source, telling it to stop or prevent the flow of water.


Now what's, what's going on here is, really a couple things.


One is, the startup situation where, before we even start.


The, we check whether the, the pot is there, but it could also be the case that somebody pulls that pot out too quickly,
okay?


And so in that case it's not going to be ready either.


In both of those situations we want to make sure that water doesn't start pouring through.


We can extrapolate it and indicate that when the containment vessel is returned to the, the heating plate.


Another message is sent to the hot water source, enabling it to resume.


So we're talking about one to turn, turn off the hot water source and the other one to turn it back on.


20 - Collaboration Diagram 2
----------------------------

So if we're just concerned a part of scenario two having to do with, you know, the check being made and we're talking
about maybe the user pulling back a pot after things have started.


We have the first step being the start, being sent from the user interface to the hot water source.


And then the user pulls off the pot and the containment vessel senses this and sends a message to the hot water source
saying, hold it don't pour out any more water.


And then later, the user puts the pot back on and the contain, the containment vessel says, okay, we can now proceed.


And we can indicate that in a collaboration diagram labeling the steps one, two, three in this case.


21 - Use Case Addition
----------------------

Now we can even think about adding together these two use cases.


The notation we'll use is to say that messages labeled with the letter A correspond to use case number one and messages
labeled with the letter B are a part of use case number two.


And the steps are still numbered one, two, three, and so on.


And so we see that we have now a diagram in which both of the use cases are listed there.


And it could also have been the case that the second use case might have, might have used a different class that wasn't
used in the first case.


In which case, adding it in means that we now have you know, four classes in our, in our diagram.


22 - Brewing
------------

So, let's now add in news case number 3.


Brewing is complete.


And started it up, its going and maybe the user pulled the pot or stuck it back in or whatever, but we eventual got to
the end, brewing is complete.


So, in this case, what, what, what steps do you expect to have happened.


>> So at this point we could assume that there should be coffee in the pot.


And if there's coffee in the pot, then we have that warmer plate that needs to be activated to keep the coffee warm.


But I guess there's also the switch, the situation like you mentioned, the cup, the pot could have been removed and then
it's replaced.


So we got to do the check to see If,


I guess, there's still coffee there in the pot after brewing is complete.


But the boiler needs to be turned off, we're no longer boiling.


The water source is not really relevant anymore either.


I guess we need to somehow maybe prohibit our, well,


I guess you could start brewing again but.


I don't think that's an issue, I think I, I jumped to that being an issue, but


I don't think it is.


And then we need to turn on the light to say hey, there's coffee ready.


>> So we got that light there, so we need to inform the user interface as to where the light lives.


So the one other thing that needs to go on is the containment vessel needs to be informed because it keeps track of how
much coffee remains in the pot.


And at the very start, the pot is full and so it has to be told that the pot is full.


So there's a lot of messages and checks that have to go on here.


Let's let's add those into the diagram as well.


23 - Collaboration Diagram 3
----------------------------

So now we have a collaboration diagram in which there are three classes and there are a series of messages going back
and forth between them.


24 - Collaboration Quiz
-----------------------

>> And one more to go.


What happens when, the party's over and all the coffee, maybe the party's not over, and all the coffee's gone, we have
to indicate, the system has to be aware of this, so what, what has to go on as far as the system is concerned in this
situation.


>> So, if the coffee is all gone, the party, yeah, like you said, may just be getting started.


But I guess the brew, or the, the your copy is ready indicate to on the user interface, would be turned off.


>> Right. A lot of this has to do with keeping the state sane across all the classes


25 - Collaboration Diagram 4
----------------------------

And this, this leaves us with our final collaboration diagram which has all the messages going on.


Now it's busy the diagram, the diagram has a lot in it, but it captures at least for this exercise what we expect of the
system.


In terms of the classes that are involved and the messages passing force path, passing back and forth amongst them.


26 - Alternative to OOA
-----------------------

Note that what has gone on here, we use the use cases to build up our diagram rather than starting with the nouns as we
did with OOA.


This approach is called role-based-design.


27 - Role Based Design
----------------------

1


It goes as follows.


2


First of all, we lay out the use cases.


3


For each use case, we construct or elaborate on a collaboration diagram.


4


Now, let's think about the collaboration diagram instead as


5 a class model diagram with the arrows indicating dependencies.


6


The rectangles instead of reflecting instances are going to be


7 reflecting classes.


8


Each class can be thought of as participating in a variety of roles.


9


One for each use case in which incident in which it is evolved.


10


The overall behavior of the class is the sum of its roles.


28 - Hardware API Quiz
----------------------

Now we're ready to go to work with our, our actual object design.


We have now used all of the use cases to describe the behavior of the three classes that comprise the coffee maker.


One approach we could take to going forward would be to implement the described behaviors as methods in each of the
classes by having them call to the hardware API.


That is that, remember the Java code that we had that gave the API to the hardware pieces of the system?


However, Martin says that this would be the wrong approach.


Can you think why that might be the case?


And as a hint here, think about reuse.


29 - Hardware API Quiz Solution
-------------------------------

I can't think of anything right now, but it, I think, it's going to be along, along the lines of it's going to be hard
to extend it, functionality later on at this point.


>> You're getting there.


And, and, you mentioned something about this this earlier on.


One hint to all this, is we have designed three classes that satisfy the requirements of the coffee maker spec, but
they, as yet, don't depend on the specifics of the Mark 4.


If when we added the methods, we were explicitly include calls to the API, then we couldn't reuse those classes when
next years version, the Mark 5, comes out.


A better approach is to use a technique called dependency inversion.


Let's see how that works.


30 - Dependency Inversion Principle
-----------------------------------

So far, we have designed an abstract coffee maker with three classes and a set of behaviors. By abstract I mean we, we
haven't done anything specific to the Mark IV. This design is of value by itself. That is, it could be used in a variety
of different models. And so we want to somehow, be able to capture that and reuse it later.


Hence we should not add specifics to it, instead we should sub class it for each specific coffee maker. By sub class I
mean have a sub class for each of the classes that is part of the overall system.


In particular, the dependency inversion principle says that high level modules, like the ones that we have just
designed, should not depend on low level ones.


Like those wrapping the API.


Note that this is the opposite philosophy from layered architectures, where high level model, modules are built on top
of low-level ones.


31 - Example
------------

Here is a image that describes a common place example of the dependency inversion principle. It features, a, situation,
describes a situation, which there's a lamp that you want to get electricity to.


And the way you do this is by plugging, the lamp into the wall. The lamp depends on the abstract plug interface and not
on the underlying electrical wiring.


It enables you to plugin a variety of different kinds of lamps and other devices as well. We want to, we want to come up
with a similar way of dealing with that in, in our software designs.


32 - Realization
----------------

How do we go about realizing the dependency inversion principle for the coffee maker example? First, we express what we
have done so far as abstract classes. Then we subclass each of them for the mark four. The subclass versions implement
the abstract methods by calling the coffee makers API.


Also the subclasses, when communicating with, with each other, use call to, calls to the abstract methods not to the
specific versions for the mark four.


33 - Abstract Classes
---------------------

When we have done this, we get a class model diagram that looks like the following.


There's classes for the three classes that we had before, and then there's subclasses for each of them, corresponding to
the versions, the specific implementation versions for the mark four


34 - Refinement
---------------

So what do we have so far? We have three abstract classes without abstract methods in them. We've defined three classes
for the Mark IV. But we still have to fill in the details of those particular operations. We want to do this in a way
that we don't compromise our abstraction. What Martin says about this is that none of the three classes we have created
must never know anything about the Mark IV. That is, none of the three abstract classes. This is the depen,


Dependency Inversion Principle. We are not going to allow the high-level coffee making policy of this system to depend
upon the low-level implementation.


35 - Solution
-------------

>> And that policy can take the form of, of protocols.


That is the names of the abstract methods that have to be called. Okay? And the the attitude here is to be as abstract
as possible. Or at least the more abstract you are, the more flexible you are with changes in the future.


Of course you can go overboard if you're only, you know, ever going to have one version of this thing you might not want
to spend a lot of time abstracting on it, and maybe there's a sweet spot in, in between. But in general and, and
reflecting back on some of what we've talked about earlier with re, respect to maintainability of of the modules and so
on. You, you want to provide as, as much abstractness as you can in support of eventual re-use.


36 - Summary
------------

So what have we learned from this exercise? First off, we could, we could use traditional Object Oriented Analysis. But
this doesn't necessarily always lead to the best solution. We can think instead about using use cases to determine
roles. And then use Dependency Inversion to reduce the coupling and promote reuse. And the final lesson that you can get
from this is, don't try to design any programs before you've had your morning coffee.


