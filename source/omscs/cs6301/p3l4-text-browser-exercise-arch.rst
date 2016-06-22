.. title: P3L4 Text Browser Exercise (Arch) 
.. slug: P3L4 Text Browser Exercise (Arch) 
.. date: 2016-05-27 23:51:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L4 Text Browser Exercise (Arch)
=================================


01 - Text Browser Case Study
----------------------------

Today, we'd like to revisit the TextBrowser example that we started the class with earlier. And this time we want to
come at it from the point of view of it's architecture. In particular, we want to suggest a process that might be useful
in actually performing an architectural design. Note that this lesson uses UML diagrams and constraints to describe
system architecture.

And there are, there is a paper on the class resources page by Stirewatt and Rugaber. That that comments on several of
the points we're going to be making.


02 - Text Browser
-----------------

We call the following problem that we considered earlier.

You have a source of textual data, a Document, with a file system interface, which we call the FileManager. You have a
resizable viewing window resource capable of displaying lines of text which we call the ViewPort.

And you have a controlling device which we call the ScrollBar capable of selecting a discrete value via handle, where
the purpose of it controlling which lines have actually appear on the screen. The objective of, of this case study is to
specify the properties of a text browser, choose an architecture, and assemble the components together


03 - Exercise
-------------

To construct this diagram, you should take the following steps using a UML class model diagram as notation.

First of all, indicate external actors but only one activity. That is, there's only going to be one class in here and
that's the class of the text browser itself. Indicate in the external stimuli or events that can affect the text browser.
And indicate how the text browser communicates it's results back to the external actors, it's percepts.

So you want to take a crack at producing such a diagram that lays out the text browsers relationship to the
external actors.

>> Okay, so I have I think kind of what are the things that you can do to the system.

>> Okay, let's, let's start with [COUGH] what are the actors, the external actors?

>> So for the external actors, I've shown drawn the user using the text browser, but also I believe we mentioned
previously that the operating system is also an actor, even though you may not think of it visually, like, see that
happening.

>> Okay.

So there's two external actors in here. The end user and the operating system which is going to supply the actual
file contents.

There's the the classic self which represents the system, okay.
And you also have some events okay.
What events do you have?

>> So, an event that the user would, start with the user, what the user can do with a text browser, view the text
browser, can move the handle that's in the tray, and then also resize the text browser.

>> So which one of, which ones of those are events?

>> events?

The movement of the handle's an event, the resizing of the window's also an event. Viewing's kind of like a continuous process, there's no kind of instantaneous event that's happening.

>> Well but the system is not doing the viewser, viewing, the use is doing the viewing, so.

>> Correct. >> That's actually a percept of the system right.

>> Okay. >> It's something that the system provides for the user.

In addition to the actual lines of file, what else is the system communicating back to the user?

>> We're also communicating back the size of the handle.

Something that we're seeing.

>> That, that says something about the proportion of the file that's visible.

>> Correct.

And we're also communicating back to the user the height of the view port.

>> Okay.

Obviously the the user has control over that height.

And the system is going to give feedback by showing a view port with different heights on it.

And you mentioned also that the contents, and that's clearly a percept as well.

So we have the height of the viewport, it's contents, the size of the handle, and the position of the handle on the tray
is another percept.

>> Correct.

>> Okay, and we have the two events, the resizing event and the scrolling event.

We have the two external actors and we have the class itself.

Okay, so we can take the informal sketch that you've done, and we can lay it out using some kind of UML tool into a
precise UML diagram that's got the single rectangle indicating the, the class labeled text browser.

It's got some attributes which include the height, the the contents that are visible, the handle size, the handle
position.

Its got some external actors for the user and the file system.

Its got some events indicating the user what the user can do to affect the text browser, and I've also put into the
image into the diagram some real mode comments which are the rectangles with the dog eared corners on them.

Note that there are some certain subtleties that haven't included in here such as how we're going to deal with zero
length files and so on.


04 - Phase 0   Preparation
--------------------------

We divide this process into phases. Phase 0 is the preparation phase. And to begin, we will look at the TextBrowser from
the outside in to determines its properties that have to be implemented. We will specify these properties using a
context diagram. A context diagram portrays a single system. And the actors that interact with the system and the
information that is passed between them.


05 - Phase 0 Summary
--------------------

So, to summarize Phase 0. The goal of Phase 0 is to understand the system being built in terms of its relationship with
its environment. And this means understanding important external actors and the interactions, the event interactions
that they can have with the system.


06 - Phase 1
------------

After you have a good idea of what the system looks like, from the outside, and how it is expected to behave, you can
begin the architectural design process.

This involves decomposing the system in to it's components, and allocating responsibilities to them. Now we did this
before, when we did this exercise, but that was an analysis model. Here, when we're talking about act, act,
architectural design we're actually going into the solution phase of things.

Now, one of the features of object oriented development is that it's often the case that the particular elements that we
come out of the analysis with, our pieces there, translate into pieces into the architecture and ultimately into the
implementation. In addition to decomposing the system into it's components, we have to allocate responsibilities to the
components, for handling those direct and indirect effects of the events, okay? And we're going to express that using
OCL invariants and pre and post conditions. To indicate how those responsibilities are being satisfied


07 - Phase 1 Steps
------------------

>> Okay.


08 - Decomposition
------------------

So the first step was decomposition.

In order to decompose the systems into components we begin with the analysis model that we produced earlier.
Note that the elements in the analysis model are good candidates to serve as architectural components.
However in general, we might need to make some adjustments or add new components in order to deal with non-functional
requirements.


09 - Phase 1 Diagram
--------------------

So, in this particular slide we have the results of our analysis model. There were classes corresponding to our three major elements and then there were associations among the elements.

There was one binary association having to do with displaying the contents.

And there were other ternary or three part associations that indicated how the misc, how the three components worked
together to make sure that the scroll bar affected the lines on the screen, and that the scroll bar handle and the
position of the scroll bar handle were all right.

Now, in analysis, UML supports the idea of associations.

In design, there are no associations, in programming languages there are no associations.

Instead there are in UML what are called dependencies.

So part of our process here will be going and taking these associations and translating them into dependencies.

Also, the comments which describe the guarantees in the previous, picture have been translated into or, they, they, they
have the OCL constraints which we developed during the analysis phase.


10 - OCL Postcondition Constraint
---------------------------------

As a reminder, what's now examined as one of the OCL Postcondition Constraints, specifying what happens when a user
moves the handle.

Remember, there are direct and indirect effects.

And this, in here, we're talking about the direct effect.

This particular constraint says that when the handle is moved, we expect the handle position to be in a different place.

This says just what we would expect.

After the user moves the handle, the handle is in the expected position.

Note several things about the specification.

For the first, because it's a direct effect, it's very simple.

And that's exactly the kind of thing we like to have in an event handler.

Event handlers have to be very fast, because there's lot's of events, and therefore, they have to do simple things and
we'd hope that the OCL expression, which is specifying that, is similarly simple.

Second it doesn't say anything about what is happening to the viewport.

That's an indirect effect.

This is the responsibility of that display association.

And we will get to how we're going to deal with that in awhile.

11 - Another Postcondition
--------------------------

1 Here's a similar postcondition for resizing a window expressed in OCL.

2 The context part gives the signature, and it's saying that the new size is,

3 is an integer.

4 The precondition is that that new size is greater than or equal to zero.

5 And the post condition is that the height of the window, okay,

6 which was the percept, is going to be that new size.

7 So about as simple as you can get it.


12 - Third OCL Constraint
-------------------------

Here's the third constraint, having to do with the displaying of the document.
In this case it's an invariant, it's an indirect, indirect guarantee.

And it's relating the contents that are visible in the viewport to the data that's provided by the file manager, as far
as it's document is concerned.

And it's saying in, in, in effect that the sequence of lines that we see are determined by the handle position of the
scroll, scrollbar, that is the top line we see is determined by the handle position of the scrollbar, and we're going to
see subsequent lines that and the number of them is the, is the height minus 1.

That is the number of additional lines plus the top line, that gives us height, which is what we would expect.

What this says is that what we will see in the view contents percept is that subsequence of lines that the document,
from the document starting with the line indicated by the scrollbar's handle position and continuing for height minus
one additional lines.

13 - Phase 1 Summary
--------------------

To summarize Phase 1, the purpose of Phase 1 is to divide the system being built into components. The analysis diagram
is a good place to start.

Similarly, the associations in the analysis model indicate the kinds of interactions that will have to occur among the
components.

14 - Phase 2
------------

In Phase 1 we divided our system up into components responsible for handling events and providing percepts. We also saw
how guarantees were specified by invariants. Note that although the example invariants we saw was, were attached to
associations, other invariants, invariants might be directly provided by the components themselves. For Phase 2, we want
to determine the systems architecture. What this means is determining how the components will interact. This
determination takes the form of selecting an architectural style.

An architectural style is a generic pattern of interactions that can be used to to address non-functional concerns such
as performance, reuse, or reliability.


15 - Phase 2 Steps
------------------

Here are the steps we'll employ for Phase 2 in the TextBrowser example. First we're going to choose an architectural
style. For the check, tech, TextBrowser, we're going to choose a layered, implicit invocation architectural style.

We're then going to assign the components to layers in the layered architecture.

Typically users events are at the bottom and percepts are at the top.

Now we're going to determine dependencies among the layers, and we're going to update the OCL into a, an equivalent, but
what's called a constructive format in which there's a single variable on the left hand side.


16 - Text Browser Arch Quiz
---------------------------

Okay, so, layered implicit invocation is just one of many possible architectural styles, that you could think of.

Can you think of some other alternatives that we could use here.


17 - Text Browser Arch Quiz Solution
------------------------------------

>> Uh-huh.

>> Component based architecture, we could try that as well. But for this exercise, we're going to stick with
this layered implicit invocation, architectural style.


18 - Layered  Implicit Invocation
---------------------------------

For this style we will organize the components into layers. For the higher level components register their interest in lower level events and are then called back when the events
occur.

In particular, the upper level components don't know the identity of the lower level components providing the events.

The lower layers are going to handle the external events propagating status changes upward.

So when the user moves the handle, that particular event ultimately has to be handled so that the user sees something
different.

So the event has to be propagated to higher layers into the architecture.

Which then handle it to, to affect all those indirect indirect implications of, of the requirements of the system.

Well, I should say that the upper layers receive these notifications and they prepare and present the results.

This propagation of events is implicit, so we call it implicit invocation.

Event announcement is made without the source component knowing the recipient which is, which reduces the coupling
between all the components.


19 - Benefits and Costs
-----------------------

As with all architectural styles, there are benefits and costs.

The benefits of the Layered Implicit Invocation architecture include im, improved reusability.

Because the lower level components do not depend upon the upper level components, you can use them in other situations.

So you can imagine taking.

Our handler for the resized window and using that in other applications as well.

There's also reduced complexity, because the, there are fewer the, the actual components know less about each other and
everything is implicit but the complexity of the system can be reduced.

Making it easier to understand and maintain.

The, there is a cost, however.

The cost is slightly increased overhead, that is performance overhead because of the extra levels of indirection.

Whenever you have an indirection, okay, that means that there's a two-steps in, in resolving that.

You make the call, and then, the call has to be.

There has to be a call back and so on.

For phase 2 after we have selected the style, we will assign the components to layers, determining the dependencies
between the layers, and update the OCL.

In particular we will insure that each constraint, is an equality with a single variable on the left hand side.

20 - Assigning Components to Layers
-----------------------------------

So first off we want to assign the components to layers. And it turns out that our simple rule, having events at the
bottom and percepts at the top won't quite work for the TextBrowser. Both the ViewPort and the ScrollBar handle events
and provide percepts. So they both can't be at the bottom. And they both can't be a the top. So for the purpose of
illustrating the layered architecture, we will arbitrarily play the ViewPort on the top.

Its percept is the most central one to the, to the user.


21 - Phase 2 Diagram
--------------------

Here's a UML diagram we might come up with. On this we have the viewport at the top, the scrollbar in the middle, and
the file manager at the, at the bottom. Notice that the, whereas in the earlier diagram we had associations among the
components, here we've converted these into dash lines which in UML correspond to dependencies amongst, amongst the
components.

Dependencies are something which the ultimate implementation languages have many mechanisms such as procedure calls to
implement. So we don't have to worry about vague concepts of associations. We can deal directly with, with dependencies


22 - OCL Updates
----------------

1 Next we have to worry about updating the OCL.

2 Recall that in our previous diagram,

3 OCL was associated with components and associations.

4 The component OCL was used for specifying event handlers, and the OCL that, and

5 that OCL will remain unchanged in the architectural diagram.

6 In particular here are the two constraints that we had for

7 dealing with event handling.

8 The first one has to do with moving the handle, and there we saw that

9 the handle has a new position like we expect, and similarly for

10 the resizing the window, where the height of the window is the, is the new size.

11 There was, there was also OCL annotating the associations.

12 [COUGH] As we move from analysis to design,

13 we will replace these associations with dependencies and as part of

14 this process, we must assign each association's OCL to appropriate layer.

15 Here are the three constraints that specify the associations in

16 the analysis model.

17 There was one for scaling the handle, there was one for

18 displaying the document, and there was one for making the lines visible.

19 This is just a repeat of what we, what we saw before, and you'll notice that

20 the, in all three cases we have a single variable on the left hand side.

21 This doesn't necessarily always have to be the case.

22 You could well imagine a constraint, in which we said a plus b equals c plus d.

23 That doesn't have a single variable on the left-hand side and we'd have to

24 subtract b from both sides, or a from both sides or whatever to get that, okay.

25 It could also be the case that there are inequalities.

26 That is the constraint might say that a must be greater than b, okay.

27 That one is going to be

28 we'll have to think a little bit about how we can implement that.

29 In fact, if a is greater than b that's even easier than saying that

30 a has to be equal to be because any value of a that's greater than b will,

31 will satisfy the result.


23 - Resize Window Quiz
-----------------------

Let's take these, these three constraints one at a time, and decide where it would be appropriate to assign
responsibility for managing that.

Before when we had associations we associated the, we, we had the constraints connected with the associations, but we
don't have associations anymore.

We have, just have components. So lets take them one at a time.

The resize window indirect effect, that particular association, which component do you think would might be the
appropriate one to be responsible for managing those indirect effects?


24 - Resize Window Quiz Solution
--------------------------------

>> Sure. We could do this intuitively or we could be a little bit more, systematic about it.

And one way of getting a hint on things is to actually look at the constraints.

And you'll notice that for the constraints that we had the answers that

Jerrod gave were also already on the left hand side of the equations. In fact, they were the in the context part of the
constraint, they were the class that that came first. So that's a hit you can use to try to decide who's responsible for
maintaining them. Now, in actual practice, any component could be responsible, okay? Or we could introduce a new
component to be responsible. In fact that's what were going with this how do we manage the indirect constraints that are
more than one class?

Will that means some kind of interaction among the classes or components, and who's responsible for managing that. That
turns out to be a tricky part of this.

And we want to handle that in a systematic way as well.


25 - Constraint Placement
-------------------------

So, we've now updated the diagram, which we placed the constraints and associated the, the indirect constraints, and
associated the, them with the, the components.

Now we can begin to think about, well, implementing those components is going to involve being responsible for making
sure that those constraints are, in fact, satisfied.


26 - Invariant Maintenance Quiz
-------------------------------

For the two direct effects, which we, we use the term event handlers for, it makes sense to have methods responsible for
doing that.

And, with methods, we have pre and post conditions.

And, it's pretty straight forward, which components are receiving the events, or the ones that responsible for, for
dealing with them.

For the three association, constraints that we've now assigned to components.

Those were invariants.

And remember that, OCL has pre-conditions, post-conditions, and invariants, and, as the system, as the user interacts
with the system and makes a change, let's say, to the scroll bar handle, it's a responsibility of the system.

To make sure that all the inter, indirect affect take place.

That process is called invariant maintenance.

An invariant is something which is always true.

We've temporarily made it untrue.

So we have to reset the system to a consistent state, we move the handle, we have to change what the contents on the
screen.

So that's and example of the, maintaining that particular invariant.

Taking that a step further, when the user scrolls, remember we had three invariants.

Which of those invariants do you think might break?

27 - Invariant Maintenance Quiz
-------------------------------

>> Right.

>> Okay? So that's, that's the job the implementation has to do.

When the user scrolls, the event causes a move handle method to be invoked.

Move handle causes the value the handle pos, position attribute to change.

That's a direct effect. Because the display's document constraint refers to handle position, the value of the view
content's will change as we expect it.

Hence the invariant will have to be reestablished.

28 - Invariant Maintenance Strategies
-------------------------------------

Key question between, going between analysis and design is how we are going to maintain these invariants. What maintains
means is how, once the invariance is broken, you will propagate the knowledge of the break to the appropriate components
so they can take steps to re-establish the invariant.

We can call these invariant maintenance strategies, or we can just say.

How are you going to implement this? And in particular, we're going to have examples of three invariant maintenance
strategies.

The first one is aggregated responsibility. That is, a single component is going to be responsible for managing this
process even if it has to invoke or make use of several other components. That single component's responsible for
handling the external events after delegating the inherent maintenance to the appropriate subordinate components. That's
Strategy One.

Strategy Two is the opposite distributed responsibility. Each component knows about the dependent components and
anything that it's responsible for managing.

And invokes them when this state changes. And third invariant maintenance strategy which is called the mediated
responsibility or mediated strategy, okay?

It involves a special implementation element called a mediator, and it's provided, it's one mediator for each invariant.
The mediator knows all.

Okay, it knows about the both the independent and dependent participants and the invariant. The independent one is the
one that gets informed when the initial event takes place. And the dependent ones are the ones that have to respond to
it. Three strategies, aggregated in one place, distributed, or a new component, a mediator, responsible for dealing with
it.

29 - Centralized Strategy Quiz
------------------------------

Notice that these three strategies differ as to where knowledge of the participants is held.

In general, there's a spectrum between centralized solutions where knowledge of all invariants is in one place, and
completely decentralized strategies, okay?

Which of these three strategies is most centralized?


30 - Centralized Strategy Quiz Solution
---------------------------------------

>> Okay.


31 - Decentralized Strategy Quiz
--------------------------------

And then the flip side is, which of these three strategies is most decentralized?


32 - Decentralized Strategy Quiz Solution
-----------------------------------------

>> Shares the responsibility.


33 - Tradeoff Between Locality and Complexity
---------------------------------------------

In deciding among the possibilities the tradeoff between locality and complexity needs to be considered. In the
centralized choice, there's a single place that handles all invariants, but that implementation of that place can be
quite complex. On the other hand, complete distribution.

While allowing each invariant to be handled in a simple way, can lead to solutions that are hard to debug. Because of
the many moving parts involved.

34 - Example Continued
----------------------

If the user moves the scrollbar handle, the invariant is temporarily broken, because the displayed lines no longer
represent those that exist at the requested position in the file. Now for this particular example, let's look at each of
the three strategies and see how it works. First off, aggregation.

35 - Aggregation
----------------

One of the components that the owning component, that is, the one that is aggregating things, and let's say in this case
it's the ViewPort, has pointers of instance variables to the other two. It owns them.

When the scroll, ScrollBar change request that is the direct event first is in, notified, or announce to the Viewport.

It delegates a responsibility to the other components to handle it. First off, it has to find out from the ScrolBar what
the new position is. The Viewport then determines that it needs additional content from the FileManager in order to
reestablish the invariant. It makes a request to the FileManager for the required lines, and then uses its own method to
display them.

That is, the viewing window has aggregated the responsibility for maintaining this invariant.


36 - Aggregated Responsibility Quiz
-----------------------------------

Let's go with the second event, the resize window.

When you play through the steps of how that's handled, assume that the event comes in to the, the window, it's the
aggregator.

What does it have to do to in order to re-establish the invariant


37 - Aggregated Responsibility Quiz Solution
--------------------------------------------

>> The, the the handle proportions can't change, okay.

So, the if we're aggregating all of this, the view port is then responsible for then informing all those other
components of what it needs, and asking them to make whatever changes they have to make.


38 - Distributed Responsibility
-------------------------------

The second possibility, the second strategy was Distributed Responsibility.

The ScrollBar receives the change requests and determines the new value, that, that is the relative, relative position
in the ScrollBar tray.

It also knows that the ViewPort depends on this information, so it makes a method call passing the relative position to
the ViewPort.

The ViewPort compares the relative position received to the current value associated with the top displayed line, and
realizes that it cannot satisfy the responsibility. It formulates a request to the FileManager for the additional lines.
The FileManager component returns the lines to the ViewPort for display, thereby reestablishing the invariant. That is,

Knowledge of the invariant is distributed among three components that delegate partial responsibility to each other when
needed.


39 - Distributed Responsibility Quiz
------------------------------------

Give a shot with resizeWindow now on how that might be handled in a distributed fashion.


40 - Distributed Responsibility Quiz Solution
---------------------------------------------

>> Mm-hm. >> So although each particular event is each particular segment of code is probably fairly small, consisting
of some method calls. They're distributed all over the place, which might make them hard to understand.


41 - Mediators
--------------

Third strategy is mediators. In mediator situation, a new implementation element is introduced for each invariant. And
it's called a Mediator. Each Mediator is responsible for maintaining one invariant. And knows what the dependent
components are.


The independent event receiving component knows only that they must inform the mediator, when their attributes change
value. For example, when the Scrollbar is adjusted, it alerts the relevant Mediator. Which in turn, requests the new
position from the Scrollbar. The Mediator realizes the new content is required from the FileManager. Requests it, and
pass it to the ViewPort. That is each Mediator has knowledge and responsibility for the maintain, maintenance of one
invariant. And by the way, Mediator is an example of a design pattern. Which we will explore later in the course.


42 - Mediated Responsibility Quiz
---------------------------------

Let's take resize window again and say let's say we had a mediator for dealing with that.

How would that mediator do his thing.


43 - Mediated Responsibility Quiz Solution
------------------------------------------

So the mediator, is essentially like watching over the, the height change of the report and when that happens it will be
reported to the mediator.

And the mediator will make note of it.

And then it will, I guess, request from the handle, its new position and of proportion based on that resizing.

And then, it will then go to the file manager because this has changed and request for the new lines to be passed on to
the b port.

Mediator is, is a very object oriented solution.

That is, there's an object responsible for that invariant, okay?

And you could imagine at, at run time introducing new invariants and turning them on and off, and so on.

Because essentially associated with, with an object.

Okay? In our case the text browser we had three invariants to maintain.

We would have three mediators.

Each one of them would express the knowledge or implement the knowledge having to do with updating that particular
invariant.


44 - Summary of Process
-----------------------

So to summarize this overall architectural design process, phase zero was specifying properties, and this involved
constructing the context diagram.

Indicating the external actors but only one activity the system itself.

We indicated external stimuli or events. That can affect the system.

We have the external actors being the user and the file system.

We indicated how the system communicates its results back to the external actor.

Those are the percepts. And then we specified in English, the behaviors that you want the system to have, and we used as
starting point for that, used cases or scenarios that we developed when we looked at the exercises at the start of the
term. In Phase 1 we componentized. Which meant decomposing the system into components, reallocating responsibilities to
them, for handling events and for delivering percepts, and we assigned responsibility for the vary, guaranteeing the
various properties. In Phase 2 we chose an architectural style, and that in turn specified how the components will
interact. We chose a layered implicit invocation architecture, we have assigned the components to layers, we determined
the dependencies between the layers, we updated our guarantees, we selected an invariant maintenance strategy, and we've
assigned, in doing so, that assigned responsibility for maintaining those invariants.


45 - Conclusion
---------------

This lecture has presented an architectural design process using the text browser as a case study. The main result is a
breakdown of system functionality into components. Also, the components are assigned responsibility for maintaining
important system invariants. However, we haven't yet dealt with with the non-functional requirements, which is a major
concern of software, software architectural design. We will address this issue in a later lesson.

