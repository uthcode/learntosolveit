.. title: P2L9 Behavior Modeling 
.. slug: P2L9 Behavior Modeling 
.. date: 2016-05-27 23:46:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L9 Behavior Modeling
======================


01 - Behavior Modeling
----------------------

The structural models that we have been looking at so far express properties of systems that are true at all times.
Although, these models are general, they fail to convey interesting behavioral aspects of the systems.

That is how the systems respond to external stimuli. UML provides a variety of alternative diagrams that do support the
behavioral modeling of systems.

We will look at these and later we will also go into detail on the state chart diagramming technique. Which is the one
which provides you the ability to precisely describe the system properties.


02 - States
-----------

First, let's start with two key concepts, states and events. Both of these are abstract but nevertheless useful in
describing system behavior.

A state is an abstract description of a set of system values at a given point of time. For example, it's raining
outside.

This is actually some estimation or abstraction over the amount of precipitation in the air at a given point in time.
Let's imagine a slightly more complex situation in the imaginary town of Des Cartes Iowa, that has ten streets and eight
avenues laid out in an orthogonal grid. And let's say we were trying to imagine the state of the town that had one car
in it.

The position of that car in this imaginary scenario is at third street and fifth avenue. The number of possible states
it could be in is 80, ten streets, eight avenues. For two cars though, the number of possible states, goes up with a
square. That is, 80 times 80 or 6400 possible states.


The State Space of a system, is a set of possible states, and its size goes up, multiplicatively, with a number of
different attributes that we're trying to capture. And the number of possibilities, that each attribute has. This is
called the state explosion problem.


03 - Tic Tac Toe Quiz
---------------------

How about the game of TicTacToe? This is played on a 3 by 3 grid, and each of the grid cells can hold an X, an O, or can
be blank. How many different states can a TicTacToe board be in? Forgetting for a moment,whether or not those states are
legal states as far as the game rules are concerned.


04 - Tic Tac Toe Quiz Solution
------------------------------

Well if you do the multiplication it comes out to be 3 to the 9th or


19,683 possible states of the board. As you can see it went up rather rapidly.


05 - Events
-----------

The second key concept is the event. Once again it's an abstraction, and we'll say it's a single, instantaneous,
noticeable occurrence. And also, and also, think of it as some kind of stimulus because the system is going to respond
to it. Events in these kinds of systems can either be asynchronous or synchronous. Asynchronous events you can think of
as kind of randomly occurring, they can come in bursts, they can be spread out. Synchronous events are more likely to
come at periodic intervals, often the system has some sort of clock or event loop that controls.

The current events when they can be dealt with in our approach to modeling these systems the events can serve as the
reason or the stimulus for a change of state in the system.

That, that change of state is sometimes called a state transition. For example, when you got your envelope through the
mail that said you were admitted to college, that's a significant state transition in your life. Events can occur as the
results of user actions like hitting a, hitting a button on the, on the graphical user interface. They can occur because
of changes in the data, in the, in the state space the temperature getting above 90 degrees. Or they can be queued by
the passage of time.


06 - UML Event Taxonomy
-----------------------

UML supports, several different kinds of events which you can use in your modelling. These include, signals, which are
asynchronous notifications.

Method calls, which are, which are synchronous. State changes in the data.

Also called data conditions, and the passage of time.


07 - State vs Event Quiz
------------------------

Okay, here are a list of descriptions of situations.

* And for each of these, determine whether it's a state, an event, or neither.
* Jesse Jones won the Olympic 100 meter in 1936 in Berlin.
* The color magenta.
* A building's sprinkler system turning on due to a fire.
* Your telephone ringing.
* A rainy day.
* Big Ben chiming.
* The International Space Station.
* The screen saver on your laptop turning on.


08 - State vs Event Quiz Solution
---------------------------------

For Jesse Owens, that was an important state in his life.

It was a state as far as the Olympics are concerned.
And it turned out, it was an important state as far as world events were concerned.
The color magenta, however, is neither.
It's not an event or it's not a state.
It's just the value of an attribute.
The building's sprinkler system turning on due to a fire.
That's an event, an instantaneous change of state.
Telephone ringing is also an event.
Rainy day is a state.
Big Ben chiming, now I know it takes a long time for it to chime, but let's just think of it as being the start of
chiming, that's an event.

Once again, an abstraction over that whole sequence of chimes.

The International Space Station is neither. You can think of it as a very, very, very complex object itself.
And the screen saver on your laptop turning on, event.


09 - Modeling Techniques
------------------------

With these two concepts, states and events in mind, let's think a little bit about modeling of behavior. Systems that
respond to events are called reactive systems. If you think about it for a minute that's much different than this other
kinds of systems that you would normally build, in which it's the system in charge of controlling the order in which
things happen. Here is the external world which supplies the stimuli that are causing things to happen in the system,
the system has to react to them.

In general there are a variety of different approaches to modeling behavior. We're going to go through from the
simplest, which is combinatorial systems.

Through sequential systems, to the most complex and concurrent systems. In combinatorial systems, we're just concerned
with states no events. Sequential systems have states, that is they have memory, but they're linearly ordered one state
after another. And then concurrent systems.

Particularly asynchronous concurrent systems have lots of states and lots of events and the events are happening at
unpredictable moments of time.

10 - Combinatorial Modeling
---------------------------

Starting at the simplest combinatorial modeling, this is the simplest form of behavioral modeling, and it merely
expresses the logic of simple combinatorial systems. In these systems, only the inputs and not the history of previous
states determines subsequent states. We'll look for a second at two equivalent forms of combinatorial modeling. Called
decision trees and decision tables.

11 - Decision Tables
--------------------

Start with decision tables. This is a common way for, getting a, getting your head wrapped around a situation where
there are various different, states that can affect ultimate behavior of the system. If you, if you think about decision
tables in terms of input conditions and and, and, and responses to those inputs. That is combinations of inputs yielding
results.

That's where the term netwire comes from. The table will have columns.

Some of which correspond to the inputs and the remainder will correspond to the outputs. And then each of the rows is
going to correspond to a different combination of input values. Let's imagine that we have a workshop and there are
three switches, okay. Each of the switches can have on and off as possible values, okay? So we're going to have three
columns and eight rows. Where did the eight come from? Well, if we have three switches, two possible values for each
switch, that's two to the third or eight. Let's assume that the three switches control two output devices.

Maybe an overhead light and maybe a, a power drill.

The third switch is a master switch which controls all the electricity in the workshop. Well here's the, here's the
decision table for this situation.


Partitioned the columns into three input columns for the three different switches and two Output columns for the lights
and the motor on the power drill. Each of the rows correspond to one of the possible combinations of the values for the
input switches. Due to the third, eight different rows there. For each of the combinations of the inputs there'll be a
resulting situation as far as the outputs are concerned. So for example, if the master control switch is off then it
doesn't matter the positions of the other switches, both the lights and the motor will be off.


12 - Decision Trees
-------------------

1


A graphical version of the decision table is called a decision tree.


2


It's a form of a flow chart in which the decisions are taken sequentially and


3 the resulting output can be seen as a path through the tree.


4


It's exactly the same information as in the decision tree, but


5 you're seeing it in a different form.


6


In the decision tree we'll see in just a second, there are two kinds of nodes.


7


Diamonds denote decisions and rectangles denote the actions that are going to be


8 taken based upon the decisions that are made.


9


The arcs in the diagram indicate the implications when a decision is


10 answered in a particular way, either affirmatively or negatively.


11


Note that in the decision tree you're about to see,


12 some of the nodes have been duplicated.


13


This is a side effect of the redundancy which occurs in the table as well.


14


Here's the tree for the previous situation.


15


On the left is the decision about the master control and


16 the on, on the rightmost is the resultant


17 response from the system in terms of what lights are on and what lights are off.


18


Once again, same information is in the decision table.


19


Note that the two rightmost diamonds contain exactly the same question.


20


And that's it for combinatorial combinatorial logic.


21


As you can well imagine, as the number of possibilities for


22 the input goes up, these tables quickly become unmanage, unmanageable.


13 - Sequential Systems
-----------------------

So then let's move to the next most complex version of behavioral modeling called sequential systems. In sequential
systems and concurrent systems that we'll get to, the main difference from common [UNKNOWN] systems is that there's
history or memory of what happened before.


You were in a previous state and based upon that state and whatever events occur you move to a new state. Systems like
this are sometimes called finite state systems because we're going to limit the number of states that they can have to a
finite number. Okay, and if you recall from your theory course we're going to take advantage of finite statemachines as
a way of doing the modelling.


14 - State Transition Table STT
-------------------------------

We can represent these finite state machines in a variety of ways.

Let's start with a tabular form called a state transition table.

Here the rows correspond to states and there are four columns. One column for the name of the state. Another for the
input event which is going to cause a transition. The third for whatever output action is going to be taken upon the
transition, and the fourth for the next state. That is, the state transition table is going to capture the idea that a
system in a given state, when given a certain stimulus, and when a stimulus occurs.

Is possibly going to produce some action or response, and leave itself in a in a state, possibly the same or possibly a
different state.

To see how this works, let's imagine a garage door opening system. In fact, a, a simplified version of my garage door
opening system. Okay. It's gotta motor and that motor can be lifting the door up, it can be pushing the door down, or it
can be stopped. There's a button that can be pressed to turn the motor on and off. The door itself can be all the way
open, all the way closed, or stopped at some intermediate intermediate state along the way.


Importantly, the, is what happens when you press the button, and in this particular garage door situation, okay. What
happens when you press the button can be one of three things depending upon what state you're in.


If the motor is stopped and you press the button, it starts going but in the opposite direction it was going before. If
the motor is going upward and you hit the button, it stops, leaving the door wherever it was at that time.


However, for security or safety reasons, if the motor's going downward and you press the button, it not only stops but
then it immediately turns on and goes in the other direction. Presumably because something was detected that might be
damaged by the door going down on it. And implicit in this is some sensors. One sensor determining whether the door is
all the way up, and another sensor saying whether the door is all the way down.


15 - Garage Door Quiz 1
-----------------------

Okay, take a second and try to figure out how many different states this system could be in


16 - Garage Door Quiz 1 Solution
--------------------------------

If you do the, the, the work on this there are six different states.


It could be open with the motor off, it could be closed with the motor off, this is probably the most common state, it
could be, stopped that is the door could be stopped, the motor could be stopped partway, up. Partway down, the door
could be moving with the motor on in the downward direction, pulling the door up, upward. Or, the door could be
partially opened because it had been closing and the button was pressed to make it, start moving upward.


That is the motor is temporarily off. Six possible states for this system.


17 - Garage Door Quiz 2
-----------------------

Second part, of the quiz, how many events does the system respond to.


18 - Garage Door Quiz 2 Solution
--------------------------------

Of course it's going to be responding to the button presses, but don't forget that it's also going to be responding to
the sensor notification that the door is up or the sensor notification that the door is down. So, three different events


19 - STT for Garage Door System
-------------------------------

Here's a state transition table for the garage door opener. Notice that there are eight rows, but only six states.


That's because some of the states have two possible, transitions on them, depending upon the events of their arriving.
Second column is the input, as to which of those events there are. Notice that the third column has the actions of
starting and stopping the motor. And the next state is in the, in the fourth column. Well, this table can obviously get
crowded as the number of possible states and events goes up. So we'd like to at least explore the alternative of some
kind of graphical view of it


20 - State Transition Diagrams
------------------------------

These views are called State Transition Diagrams, they're essentially represent, graphical representations of a Finite
State Machines.


In these diagrams we have an indication of a node, typically with an oval, or some kind of rectangle. We have arcs,
directed arcs connecting the nodes, indicating that there's a state transition. The arcs can be labeled.


The arcs can be labeled with an action and a transition.


Typically the actions can be can be optional. Usually, but not always, the transitions are, are not optional, okay? If
you recall your finite state machines from theory, there are these epsilon transitions.


We'll see in fact that the garage door opener has one of these, but they're, they're not, they're not all that typical.
Note that the layout of the nodes, where we placed them in the diagram, doesn't have any semantic import. So you are
free to make the diagram lay it out in a way that conveys what you consider to be the important behavioral aspects of
the system. In terms of how these diagrams work, you can think of yourself as, at any point in time, being in a specific
state. Okay, kind of waiting there until an event happens.


When the event happens, the outgoing arcs are examined to determine whether any of them are labeled with the
corresponding event.


And if so, a transition is made between the current state and the state at the end of that transition. And in so doing
the action, if any, on that transition arc is, is executed.


21 - Example Garage Door
------------------------

Here is the graphical representation of the garage door opener.


I've used rectangles in this case, but there are six, six states indicating the six states we, we listed before. The the
arc, the transition arcs have two two expressions on them.


The first one, the first is the event causing the transition, if there's then a slash, the second one is the event to
take, that will happen upon that transition occurring. So imagine, for example we're at the bottom, in the state labeled
Door Open Motor Off.


And in this case, there's only one outgoing arc.


The user has pressed the button and, in this case, the motor starts and it moves into the state where the motor is
running downward. The door was open, it was at the top. Hence, the only place that the door can go is downward.


Similarly, you can walk yourself through the diagram.


The interesting situation involving epsilon transition takes place if you are in the bottommost state on the right,
labelled Motor Running Down. If, then, the button is pressed, okay, recall that the first thing that happens is the
motor is stopped and we transition into the Door Partially Closed Motor Off state just above it.


But when we go on, okay, remember the, the safety concern. The door was going down and we stopped, and we now want to
take it up. So there's a transition to the left in which there is no event causing the transition. Okay? So immediate
transition and what we want to do is start the motor going upward and end up in the state at the extreme left labeled
Motor Running Up


22 - Example Telephone
----------------------

Here's another example, a graphical example, of a state machine, using slightly different icons on things. In this case,
ovals for the states.


We have the telephone being off hook, we have it when you're dialing or pressing the buttons. We have it when it's
ringing, when it's busy when you are connected to another party. And, when it's in a rest state on hook, on the extreme
left.


Notice in that case, that there are two ovals nested inside of each other.


This is used to designate what the default or start state of the system is.


There are then transitions, these directed arcs going, among the states. One to look at is the one on the top right
labeled dialing, where it's a transition from a state to itself. That is, when you're dialing or pressing the buttons,
okay, you're doing this several times and, you remain in the dialing state until you've finished dialing. Now we could
have had a machine here that had numerous states as part of the dialing process, in which we've dialed the first digit,
the second digit, and so on. And in that case, it would be different states.


Until we eventually got entered our local number or our our long distance number. That would have complicated the
diagram, and remember these diagrams, are abstractions. We abstract over the set of states, and abstract over the
events. That's, that's your choice as a designer or a modeler. Notice also that, the diagram is somewhat busy and that
there are arcs that have a seemingly redundant labels.


This is another example of a situation where we'd like to improve the diagrams by by simplifying them. And that's where
we're going when we get to concurrent systems model with statecharts.


23 - Problems with State Transition Diagrams
--------------------------------------------

So with these, state transition diagrams there are several problems that we've noticed. There are too many arrows, there
are too many states, and there's no concept of nesting in them. As far as the arrows are concerned, if you've got end
states and you've got impossible events. You've got n times m, a multiplicative number of possible arrows.


As far as states are concerned we've already indicated that the number of states goes up with the power of the number of
possible things that can be going on.


As far as nesting is concerned with the example of the dialing the telephone.


In, in essence we would like to have done the modeling by having the, the entering of the particular digits somehow
hidden within that dialing state.


24 - State Charts
-----------------

Well, fortunately, there is, at least a partial solution to the problem of dealing with complexity in these, in these
systems. I say partial because no matter how nature notation is, you'll always going to be confronted with systems that
are more complex than it can deal with. However, state charts, as developed by David Harel. Okay.


Our way of coping with this in, in a fa, in a fashion that allows you to do the modeling of the system in a way that
help you get an understanding of it.


He calls these his improvements to state transition diagrams, state charts.


And they provide, several mechanisms for, dealing with the, with the complexity. 'Kay, and we'll be looking at those.
State charts are a part of UML. Okay.


Tools support them, and, we will be, looking into them in a subsequent.


Lesson and giving you a chance to use them yourself.


25 - State Chart Icons
----------------------

As far as icon are concerned, state chart compromise between the rectangles that we saw in the ovals to a thing called
round-tangles, rounded cornered rectangles. They can, they can have labels indicating state name.


They can have arcs connecting them which is a, a directed arc that is there's going to be an arrowhead at one end.


And the arch's themselves can be labeled with the event causing the transition, possibly with a slash and the action
taken when the the event occurs.


Also, there's a way to indicate what the default or initial state is.


In the case of state charts this is having a small circle that's filled in.


You know blackened. And the final state in this case, the final state is one in which there is a concentric outer ring
around a filled in a filled in circle.


26 - State Chart Extensions to FSMs
-----------------------------------

Statecharts add quite a few features. We're going to be looking at the first two because they're the ones that give the
greatest benefit. But I'll mention also some of the others, okay?

In particular number one thing is statecharts offer nesting or depth, okay?

That is, a particular state in a statechart can be its own state machine.

And you can zoom in that way. Secondly, they offer concurrency. Imagine that you have two things going on, each of which
can have a number of states.

Recall from state transition diagrams that in order to model that we have to multiply the number of states. Statecharts
allow you to treat those separately, okay? Therefore, only getting an additive number of states rather than a
multiplicative number of states. Of course once you've done that, that is separated the concurrent machines into two
parts, you still have to synchronize them. That is, they still have to cooperate somehow, and statecharts offers a way
of doing that called broadcast events.

We'll look at that. And of course you could also use data conditions which are globally available to both machines.
We'll look at entry exit actions, we'll look at event parameters, we'll look at history, and of course the default
states that we've already seen the icons for.


27 - State Chart Nesting
------------------------

I have asked you to have a look at, at Harel's original paper. In there, he has several abstract diagrams laying out the
various features of the state chart notation. On the left, there is a a state machine that has three states.

Notice the default state is the top one and, with the line coming into it, and there are transitions among the states.

Totally, there are six transitions there.


The version on the right labeled b, okay, is a nested state transition diagram.


A new state called D in the roundtangle, surrounds states A and B.


A is still the default state for the the state machine as a whole.


But notice that some of the lines come out of D rather than coming out of either A or C. Going back to the one on the
left, notice there are two transitions labeled f, one coming out from A and going to B, one coming out of C and going to
B. On the right, they're coming out of D. That is, there's there's a an abstraction, saying when you leave any state in
D under transition f, you go to B. So in that case, we reduce two transitions labeled f to one.


There's still the transition from A to C.


There's still the transition from B to A.


Notice also though that there's a transition from B to D labeled h.


In this case, where does it go? Well, notice that we've added a new default state and its transition for C. That is, if
a transition comes into D, to the border of D, where is it going to go? It's going to go to the default state, which is
C.


Well, this is identical to what's happening on the left where there's a direct line from B to C. In this case the line's
a little shorter, saving just a little bit of complexity. We could also have the nesting go further.


That is A or C or B could themselves have substate machines in them


28 - State Chart Nesting UML Example
------------------------------------

Here is an example from UML. It concerns a a machine, that's either heating or cooling. It's some kind of air-
conditioning system.


And on the lower right is a nested state called heating.


Heating is just a two state sub-system.


One of the states is activating, and the others is called act, active. Okay, it's got a default state which is the
activating state, and it's got a transition which occurs when the activating is ready.


And it the action that takes place is to, to turn things on.


This nested state is part of the larger system, which at the top level has three important states. It has an idol state,
a cooling state, and this nested heating state. The default state for the larger machine is idle, and the final state is
a shutdown state. And there are transitions between the various outer states. But notice also the transitions that from
the nested heating state, go only to the boundary of that state and not into the internals of that state. Thereby saving
duplicate copies of the lines coming from each of the internal states in the heating state.


29 - UML Example Harels Notation
--------------------------------

Here's an example of a UML, state chart that illustrates several other features of, Harel's notation. Once again, there
are three outermost states, idle maintenance, and active, and the active state itself is, has nested states inside of
it. There are transitions from idle to the boundary of active. Two transitions there, and as, as we saw similarly, each
of those transitions is going to go to the default state in the internal machine, which is labeled validating.


Another thing to note here is that two of the transitions in the nested machine, in the active state, are labeled with
text inside of square brackets.


These are data conditions. They are tests, logical expressions on the, the the attributes of the object which is being
represented by this particular state machine. In the transition between processing and printing on the right hand side
of the active state, there are square brackets and inside it says not continue. Okay, continue is an attribute,
presumably a boolean attribute, and if it's false, then the transition can take place, otherwise it won't take place.


Also between processing and selecting, there's a transition labeled continue which will take place if the continue
attribute happens to be true.


The other thing to notice about this particular example is that in the bottom, on the left of the active state, there
are two lines of text one labeled entry and one labeled exit. These are actions that will take place upon respectively
entry and exit from the inner state machine, that is when a transition from idle goes to active.


Before anything else happens, the read card action will be executed.


Likewise, upon exit from the printing state, when all the other work is done, the eject card action will take place.


30 - Concurrency
----------------

Well, that was nesting. The other, important addition to state machines that


Harel offers is concurrency. In this case, concurrency is indicated by a dashed line. It separates a larger roundtangle
into two other machines, but in this case, it is nesting that goes on at the same time. That is, we've cranked up two
machines that are running.


Each can have their current state, each can respond to transitions and each can perform actions depending upon the
transitions. 'Kay, once again, this reduces the total number of states from a multiplicative combination to an additive
combination. Here's from Harel's paper on the left, is the bowl of spaghetti, that indicates the multiplicative
combination.


Notice the labels of the states are really indicating where you would be in one of the concurrent machines, and where
you would be in the other concurrent machines hard to understand what is really going on there.


Harel has replaced this jumble by one major state labeled y and left two of the original states, H and I to interact
with it.


The y-state has that dash line indicating concurrent actions that are taking place, they correspond to states a and d.


They each have default states, they each have their own transitions. But, hopefully, you can see it's a little bit
easier to follow what's going on there.


Notice also that Harel allows the splitting of a transition to go to two possible states, one in each of the concurrent
arms.


So the lower right state in the rightmost diagram, I has an E transition coming out of it that's then split into two
places. There's also an example of a data condition in here as well. In UML the concurrency looks like the following.


There are two states here, there's an idol state and a maintenance state.


The maintenance state has the dashed line in this case it's a horizontal line.


And two concurrently executing machines, one called testing and one called commanding, each of which are quite quite
simple. Each has an initial state and and a final state and some transitions between them.


31 - Synchronization
--------------------

Of course if you've got concurrent, concurrently executing machines, they have nothing whatsoever to do with them.


Why did you put them in the diagram in the first place? They're there because, somehow they're cooperating. And, that
cooperation needs to be coordinated or synchronized. State charts provide several ways of doing that. One are called
broadcast events, and the other is the data conditions that we've already seen.


32 - Broadcast Cascade Events
-----------------------------

On some of the transitions there can be an action taking place and that follows the slash. The actions that we've seen
so far you can think of as being equivalent to method calls in our object-oriented class model diagrams.


But they could also be the issuing of another event. For example in in, in state A, there's a transition between
substate C and substate B that the transition itself is labeled with F.


But then there's a slash, which says if I'm taking this transition, also issue a new event called G. That is, we've
cascaded the event.


Now, the events themselves are globally known. So the issuing of the event g here is known to the other machines in the
concurrently executing state chart. And this process of cascading the events can go on


33 - Data Conditions
--------------------

The second way that the differently executing concurrent machines can communicate is by data conditions. We've already,
we've already seen this.


Remember that they occur within square brackets. Okay? And they contain within them Boolean expressions in which the
terms correspond to attributes of a various classes in the overall system model.


You can think of these data conditions as being continuously monitored.


And that when one of them becomes true, that's like an event were issued saying, look at me I'm now true, I can take
this particular this particular transition.


State charts, in addition, support the keywords in and not in.


What in means is, I'll make this transition if in one of the other concurrent machines I'm in state whatever x is. So if
I say in x and in the other machine I'm in state x, then I can make the transition. And similarly from not in. The
variables which occur in these expressions, as I said, come from attributes in the system model. And these attributes
are globally known by all of the concurrently executing machines.


34 - Special Transitions
------------------------

UML supports a couple of special transitions that you can take advantage of, each indicated by a keyword. So, here's a
two state machine. The transition from the active state to idle state. the, transition is labeled after 2 seconds. Okay?
So you can assume that there's a timer here that if you're in the active state 2 seconds later, you'll make the
transition to the idle state. Similarly, the idle state has a self transition, okay? That's labeled when we key, the
keyword when and then a particular clock time that the system waits until that particular clock time happens before
making the transition.


We can put this example in a slightly larger context of to ill, to illustrate one other feature of, state charts. So, we
have the self transition on idle and we have some, normal, transitions labeled by events in the rest of the diagram.


But the transition between idle and tracking, okay? Involves an action, okay?


That action is invocating a method, invoking a method, and the method has a parameter p, that is you can pass
information in the action calls.


Similarly, on the transition itself, the event that led to the transition has an argument p. So, what we're doing here
is we're passing on the information.


That came in on the event to some kind of method call so it can presumably be processed in the tracking state


35 - History States
-------------------

The final major feature we want to look at with state charts are called history states. Here's a nested state machine.


Where the two external states are the command state and the backing up state.


And there are transitions from the backing up state into the command state, two transitions there. And there's a
transition from the command state, to the nested state into a circle labeled with a label H.


This is an example of a history state. And what it says is, let's remember whichever state we were in, in the backing up
machine, the last time we were there. And we left. And, when I'm entered into the history state,


I'll go to the state that I was last in. Whether it was collecting, copying, or cleaning up. I could even go so far as
to label the circular state H star. And that says, if any of the the states and the backing up state were themselves
nested,


I could go to the sub-states that were there. This is quite a, quite powerful feature, but it can get you into diagrams
that are kind of hard to read because you may have to remember what state you were in, and also look into the, the
various nesting levels.


36 - Complete UML State Description
-----------------------------------

Okay let's, let's summarize this. What are all the things that UML can provide for you in state descriptions? At the top
is the word tracking, that's the state label. We can have the entry action, we can have the exit action.


UML supports the ideas of internal transitions. These are, you can think of these as self transitions without the entry
and exit actions. Okay,


UML now also supports the idea of activities. So we have actions and activities.


The difference here is that you can think of actions from the point of view of the system as being things which are
instantaneous. Typically that means that we're turning something on or we're turning something off. And the time that it
takes to do that doesn't play in the rest of the, rest of the system.


Activities, however, are things which take time. Okay, the key word there is do, and we're calling some kind of method
which is going to take some time.


So we're going to be in this state while, while we're following the target. And deferred events are a a, a special
situation in, in UML in which the set of events that the system is responding to are, are queued, that is, put into a
queue, and only processed at a later time.


37 - Complete UML Transition Description
----------------------------------------

As far as transitions are concerned, there's a transition goes from a source state, goes to a target state. The
transition can be labeled with some kind of triggering event. There can be a guard on it. There can be an action.


Okay, that takes place when the transition occurs. And as we've noticed there can be forks in the transition arcs, and
there can even be joins.


38 - Relationship to Class Diagram
----------------------------------

Okay, you should be getting the idea now that the state charts are quite powerful. There's lot's to them, like the
class, diagrams, you don't have to necessarily use all those features in every diagram that you do. How, in fact, do
these state charts relate to the class model diagrams? Well the way to think about it is, that each of the classes. In
the class model diagram, has attributes, and those attributes form a state space. But each of the classes in the state
diagram could have it's own, state chart. And that doesn't mean you're going to be building state charts for each of the
classes because, most of the classes have relatively simple states, and are, perfectly well described by the methods
manipulating the attributes of that class. In th state charts, there's references to attributes.


Those are the attributes of the class. There's also references to actions and activities, and those are the methods of
the class.


The events in the state chart diagrams are going to correspond to signals.


A signal is a dependency in the class model diagram. You can use a stereotype, in this case the stereotype is send,
indicate that the move, movement agent class, is going to send a signal, called the collision signal.


There's a dependency between those two two classes. So what this is saying is that, as you're doing your state chart
modeling, you have to make sure, that it's consistent with respect to the class model diagram. That is, the events have
to be named, the attribute names have to be, correct, the method names have to be correct, and so on.


39 - Harels Digital Watch
-------------------------

When I first came to Georgia Tech, David Harel came and gave a talk.


And, as in the paper, in the talk, he talked about his digital watch.


And he presented a model of the digital watch.


He, he in fact had used that as a way of stressing his diagramming technique to see if it was capable of representing
the features of the, of the digital watch.


From the paper, here's, here's the example of the digital watch, from a high level view.


Notice that there are really two states here.


One is the dead state and one is the alive state, separated by whether the battery is placed inside it or so on.


And then are five concurrently executing sub machines inside the alive state, each of which has their own activities
going, going on, and there's even further nesting down in the lower right-hand concurrent machine.


The fact that state chargts support nesting means you can pull out any of these sub-machines and consider them
independently.


You can even provide details in the pulled out version that weren't visible in the top level version.


Here's an example of the stop watch state.


It makes use of a history state.


You'll notice there it had it's own default state for the, for the stopwatch itself in the zero step.


There's also a guarded transition using the in keyword that I mentioned before.


Here's a pullout on the displays state.


Notice that the state itself has a self transition over on the left that indicates that there's a two minute timer.


What this is saying is if you were in one of the display states, other than the default state, after two minutes it
will, it will flip back unless you were in the stopwatch state, in which case it'll keep, keep you looking at the
stopwatch.


40 - Harels Digital Watch Quiz
------------------------------

So using this diagram, here's some quiz questions that ask you to figure out what's really going on there. And for this
quiz, you should be aware that the events labeled A, B, C, and D correspond to the four buttons on your stopwatch. First
question is how many outermost states does the watch have?


Second, what button must be pressed to turn on the alarm clock feature?


It's the alarm clock, not the stopwatch. Third, in the ALIVE state, how many concurrent machines are running? Fourth,
when the C button is pressed to set the time, which part of the time, that is the day, date, hour, minute, or second, is
the first one the user can change?


And fifth, if you are changing the time on your watch and you press the B button to indicate you are done, what
unexpected side effect occurs?


41 - Harels Digital Watch Quiz Solution
---------------------------------------

Well for question one, how many outer most states?


There's two we've already said this dead and alive states. Which button must be pressed to turn on the alarm clock
feature?


That's button a. In the alive state how many current machines are running?


Well there's five. There's the main one, the power state, the light state and the two that are labeled alarm-st and
chime-st.


When the C button is pressed to set the time, which part is first, that's, the user changes the second setting first.
And then the question about what unexpected side effect. When Harel was at Georgia Tech, he told us about how when doing
the modeling of his digital watch.


He found a bug in the way that it ran. Whenever you hit that B-button, it turned on the light whether you needed the
light turned or not.


Going back to the garage door opener for a minute, when I modeled the garage door opener of my house, I found that there
was a bug in its system as well.


The bug arose when I was going on vacation and I was hitting the security feature. Now this wasn't in the example that I
showed you, but.


The real state machine for the garage door opener has a security feature and that turns off the remote the remote
control so you can't open the garage on the outside and what I was going to do was start the door go, door going down,
hit the security feature and duck out underneath. Okay the system had not been designed to change that security feature
as the door was going down and


I lock myself out. Okay, and it's another indication that getting these reactive systems correct is quite difficult and
careful modeling of things is important. To make sure that you don't get into these embarrassing or possibly situations
that lead to safety problems.


42 - Summary
------------

As I said, these reactive systems are hard to build. You probably have heard of examples of complex systems getting into
deadlock states or otherwise freezing up because of the common [UNKNOWN] blowup in complexity that occurs from all of
the internal things that are going on.


So, you have to spend some time in getting these things right. And some kind of behavioral modeling technique, like
statecharts, okay, can be very helpful to getting that kind of assurance. Besides statecharts,


UML provides other diagrams that can be used for understanding behavior.


Okay, we've already seen these in our review of UML, activity diagrams, sequence diagrams, collaborations, use cases,
communication, timing and interaction overview diagrams. Okay? Outside of UML, there's a couple of other behavioral
modeling approaches which I'll just mention to you, we won't go into it. One of those is temporal logic. If you've heard
of model checking and model checking tools these are ways of modelling system and asking can I ever get into this
certain state that I don't want to get into, okay. Am I ensured that I can't get into it, okay and model checking tools
can help you get answers to that problem.


Another notation for expressing concurrency is process algebras.


These allow you to specify what things can go on concurrently and the reads and write behavior between the concurrently
executing activities.


We will be looking further into statecharts, we will do, be doing an exercise that ask you to learn the features. This
is such an essential part of getting models right that want to make sure that you have kind of acquired that skill.


