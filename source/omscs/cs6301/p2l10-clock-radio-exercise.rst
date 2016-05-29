.. title: P2L10 Clock Radio Exercise 
.. slug: P2L10 Clock Radio Exercise 
.. date: 2016-05-27 23:38:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L10 Clock Radio Exercise
==========================


01 - Modeling with Statecharts
------------------------------

Statecharts are a precise way of modeling the behavior of complex reactive systems. Such systems are ubiquitous and
errors can lead to safety, security, and usability problems. In this lesson, we will go through an exercise in modeling
the behavior of a common clock radio.


02 - Description
----------------

The radio is powered by electricity from a wall socket at not a battery.


It can be controlled by two manual knobs. One for volume on the top right and one for tuning on the right side. The
chosen frequency is displayed on the right side of the front panel with a small vertical white bar.


The display features a twelve hour clock on the left front and two small lights. The light in the upper left hand corner
of the display labeled AM indicates whether the displayed time is in the morning, when the light is off or in the
afternoon or evening when the light is on.


The light in the lower right hand corner of the display is labeled wake.


If it is lit indicates you have armed the alarm. In addition to the above, the radio has two switches and five buttons.
One of the switches on the top edge of the back determines whether the frequency band is set to AM or FM.


The second switch found in the center front of the top has four positions.


The switch slides horizontally from left to right. In order, the positions indicate whether the radio is on, off, armed
for wake by radio or armed for wake via a beeping sound. Four buttons are found on the left side of the top of the
radio. They can be used to set various timers in the clock.


They are labeled hour, min, wake, and sleep. By pressing the wake button, you can set the time you wish the alarm to go
off. By pressing the sleep button, you can set how long you would like the radio to play before automatically shutting
off. Using this feature allows you to fall asleep with the radio playing. If neither button is pressed you can set the
current time of day.


You've actually set these three timers using the other two button on the front left of the top of the radio, they are
labeled hour and min. By pressing hour you increment the hour of, of the respective timer, the wake, sleep or time of
day timer. Similarly for min, if you wish to be awakened 15 minutes later tomorrow morning than you were this morning
you would hold down the wake button while pressing the min button 15 times. The final button is the snooze button.


It is the large button found in the center front of the top of the radio.


The snooze button is useful when the alarm is trying to wake you up.


Each time you hit the snooze button the alarm shuts off for


10 minutes. The final feature to note about the radio is that the alarm will automatically turn itself off after one
hour, to prevent the situation where you forgot to turn it off and it was audible all day long.


03 - Exercise Introduction
--------------------------

>> Okay clearly there are lots of other ones, like just listening to the radio, turning it on and just listening to it
or getting shocked out of bed by the beeper going off lots of possibilities here.


And ultimately our state chart model, needs to be able to cover all the pos, all the cases that might, might arise
including error cases.


Including situations where what you had hoped to happen doesn't happen, and the radio has to respond in that situation.


04 - Percepts Quiz
------------------

Once we have the use cases, we can use them to determine the radios percepts.


Recall that a percept is an externally, sensible, by that I mean visual, audible, tactile aspect of a device. That is
you can walk through a use case to determine what percepts the user interacts with.


Typically a device's output and some of its input comprise its percepts.


05 - Percepts Quiz Solution
---------------------------

>> So we definitely are going to have to model the fact that when the snooze button is hit, something happens with the,
with the speaker. So to summarize the various precepts that are involved here. The speaker. The time display we just
went through. those, along with those indicator lights on the, on the time display, saying whether the alarm is is
turned on.


And the AM, FM percept. There's also as we indicated the rotational position of the tuning knob. The horizontal
position. The left and right position of the vertical frequency bar. Rotational position of the volume dial. The current
setting of the switch which is the AM/FM band and the current setting of the slide switch, which is on off radio or
alarm.


Think of it as a mode switch there. The other devices that the, the various buttons are in fact that. They don't retain
any state.


But you can still use them to cause other effects in the clock radio


06 - Percept States Quiz
------------------------

So to drill down one step deeper, the next step in analysis is to determine, what stage, each percept can be in. Each
percept will in general, be modeled with a finite state machine, and these finite state machines can be though of, as
executing concurrently. That is a state chart in this particular situation is going, the models of clock radio is going
to be carved up into different, different, concurrently executing state machines, in which, each state machine is, going
to, or most of the state machines are going to correspond to the states of the particular perceps. For example, the mode
switch can be in four states. And when the user sets the switch to one of these states, this naturally affects the
device's behavior. Let's see how this works for one of the clock radio's percepts, its time display. How many different
states can the time display be in? For the moment ignore the two accompanying lights, the AM/PM light and the alarm
indicator.


Just the rest of the display, how many different states can it be in.


07 - Percept States Quiz Solution
---------------------------------

>> Third grade math. 'Kay? Exactly right. However it's unlikely we're going to have it, we're going to want to model a
state machine that has 720 states in it.


With state charts, we can reduce this to two concurrent finite statement machines totaling 72 states. One for the hour
and one for the the minutes. But even that seems little bit over, overkill here. Resi regardless of which version we
choose, the resulting state chart would still be crowded and not all that useful. Instead, we will abstract the machine
into a single node, labeled clock time. And assume, that the underlying logic for computing the correct signals to cause
the lights to display.


There are 720 different possibilities work as expected. Deciding just how to abstract the many possibilities for
percepts is a key skill in state chart model. We can do the same abstraction on the WakeTime and SleepTime displays,
giving us a simple three state machine that looks like what we're seeing here.


Note that we have not yet labeled the transitions between the states with events, that step will come later.


08 - Display FSM
----------------

What we're looking at, is a finite state machine, a state chart that is carved up into a collection of concurrently
executing sub machines. And the one that we filled in, that pivotal state chart is labeled Display. And the Display, if
you think about it, can be in one of three states.


Either, it can be displaying the current clock time, time of day. The time when you wish to be awoken. And, the amount
of time that you'd like the radio to run, as you're going to sleep at night. And between these each status is an oval.


And between the states are some transition arcs. And in this case to make it a little bit simpler, we've abbreviated the
two arcs, the ones that go back and forth with a single arc with double-headed arrow. But in general those are two
transitions and we have to take care that we represent them both


09 - Mode Switch Quiz
---------------------

Let's turn that to a physical, rather than an electronic percept, the mode switch. Remember, that was on the top, front
of the, radio. The sliding mode switch controls, whether the device is off.


On playing the radio continuously, on laying the radio only when the wake up time is reached or on beeping, only when
the wake up time is reached.


Can you model this percept with a finite state machine?


10 - Mode Switch Quiz Solution
------------------------------

>> So we'll just go ahead and, and plunk that one into our into our composite machine now.


11 - Station Indicator
----------------------

Another percept of the clock radio is the tiny bar on the front that indicates the current station. This device is
physically controlled by the StationKnob, and like the knob, can take an infinite number of positions.


It can be modeled as a single state with no transitions. Now, we would expect that the StationKnob and the station
indicator are coordinated with each other.


After all, when you turn the knob you would expect the indicator to move.


And later we'll figure out how, using our state chart modeling notation, we can connect those two, those two concurrent
activities together.


But for now we'll just treat them as separate machines.


12 - Station Indicator FSM
--------------------------

In our growing diagram, the indicator that is the frequency indicator, is a single state which I have labeled here
frequency. And there is no transition, that is the user can't directly move that vertical bar around.


It will be the job of the station knob when the user does undergo a particular transition. By turning the knob to
somehow affect the station machine, concurrently executing machine. As I said, we will delay dealing with that until a
little later.


13 - Speaker
------------

>> Okay. Clearly it can be on or off and, a part of the abstraction process is deciding that for the purposes of, our,
our understanding of the radio here. That, we're not going to be concerned with as if there were any states between the
two. Now if we were, went down to the electronic level, there would be some voltage levels and there would be, you know,
transitions going on there.


But that's that's not what we're concerned with here.


14 - So Far
-----------

So far, we have been developing a StateChart to describe the behavior of, of a clock radio.


Thus far, we have used seven concurrently executing machines to model the radio's percepts.


We have left some placeholders for other machines we will need to complete the diagram.


We have also left out the transitions for the time being.


Let's begin to look at the events that can provide the impetus for these transitions.


Recall that an event is a spontaneous or instantaneous occurrence.


That is, we're not concerned with its duration.


It can communicate information such as if we turned the dial what position are we turning the dial to.


But that the state machines can be sensitive to those events taking place and cause a change of state when they detect
them.


15 - External Controls and Stimuli
----------------------------------

>> Okay, if you press the wake button first, it's, then press the hour button, it's going to change when you wake up. So
it's important that the stage chart that we end up with reflects that difference, because it, the user intends them to
be used, used differently. The event is pressing the wake button, the event is releasing the wake button the, another
event is pressing the hour button and, and pressing the minute, minute button. And our, our machine, as we eventually
refine it to deal with all these contingencies, had better behave in an expected way as far as all of the, the, the
precepts when, in all of those possibilities. All those possible situations.


16 - From Actions to Events
---------------------------

So, imagine that you were a programmer implementing the internal logic of the clock radio. You would have to take into
account all of the different events, okay? And all of the possible combinations of those events.


So, ultimately, you have to deal with all those cases. And consequently, it makes sense during the analysis phase, to
list them all, okay?


To give a fairly precise description of what are all the different events.


What information comes in along you know, its parameters to those events. And ultimately then, what the system, how the
system's going to respond to those events. And for the purposes of this exercise, I've expressed that in a table in
which we have numbered events, and we have the the description of the event, and then the systems response to that
event. So, listed here at the beginning of that table


17 - Outermost Layer StateChart Quiz
------------------------------------

State charts can be nested. That is a state may have a state chart nested within it. Let's, for a second, step out from
our layer in which we've been modelling and think about the outermost layer of this, of this particular device and work
inward. If you recall the paper I've asked you to read by Harrell the digital watch had the same outermost layer having
to do with whether the batteries are in the watch or not. What might be the analogous situation here, as far as an
outermost state is concerned?


18 - Outermost Layer StateChart Quiz Solution
---------------------------------------------

>> Okay. So we have a two state machine and we have some, two events that, that cause transitions between those states.


19 - Adding Events
------------------

So, here's a, a very simple outermost state chart in which we have an unplugged state and a plugged-in state. The
pulling the plug causes us to go from the plugged-in state to the unplugged state. And I've labeled here, this is not
part of the state chart notation, but


I've labeled here, what the event number is in our table.


So vent number five is the pulling of the plug. Symmetrically, the, going from the unplugged to the plugged-in state is
plugging in the plug, and that's, that's event number six, okay? But for the remainder of the, this exercise, we're only
going to, consider sub states of the plugged-in state.


That is, now, imagine that, the rightmost state here has all of those other concurrently executing machines which we
were, talking about previously.


20 - Event Allocation
---------------------

>> Here are the additions to our machine to handle events 1, 2, 3, 4, 12, and


13. So, with respect to event one, that's the volume knob, that's similar to our station one, for, switching the band
between AM and FM, those are events two and three, one going to the left and one going to the right, and similarly,
sliding the mode switch to the right and left are events twelve and thirteen.


21 - New Sub-Machines
---------------------

>> Yes. >> Okay. And that state then allows us to to press the hour button.


Okay, so pressing that hour button while we are in that state has a different effect than pressing it when we're not in
that state, okay? So, let's see what such a state machine might look like


22 - Setting the Time
---------------------

Now recall that a minute ago I said that we had no spontaneous transitions and yet we have what looks like a spontaneous
transition between the none state and the clock state. We'll see that we are going to need that distinction because the
user can actually have an event here like hitting the arrow button which causes us to move from the none state into the
clock set state.


So we'll come back to that when we get to these other events.


23 - Responses to Events
------------------------

The ultimate value of the clock radio to its user is how it responds to these listed events. Each of the events we have
listed should have some effect on the radio state. Consider what happens when you turn the volume knob.


Certainly you would expect the sound coming from the speaker to be louder. But there is another response. The rotational
position of the knob will also have changed. This is an important piece of feedback to the user, who may be adjusting
the loudness, in the dark of the night.


We can fill this in, this information into, into a table of responses.


24 - Stimulus Response Table Quiz
---------------------------------

So we have three columns. One, one is our event number the second column is the event or stimulus that we're talking
about, and the third column is, just in English, what a, what response we expect from from the clock radio when that
event takes place. Also, we have already talked about Events 5 and 6, so they also can be filled in. See if you can fill
in for the table for


Events 12 and 13, which is sliding that mode switch left and right


25 - Stimulus Response Table Quiz Solution
------------------------------------------

>> So if you were in state On, you'd be one shift to the right would put you into state Off and in the same way Off to
Music and then Music to Alarm.


And similarly for going left. And we can we can list that by saying, using the word if or some conditional. Ultimately
in the code, we are going to have to have a conditional statement that indicates these various possibilities.


26 - Stimulus Response Table
----------------------------

And we can continue this process of filling in the table, with the rest of the responses for each of the, possible
events that are listed in the table.


27 - Timer Events Quiz
----------------------

As with the external events we considered earlier, we need to model any events the internal states respond to.


The most interesting such event is when the clock time reaches the alarm time.


After all, that's why you have a clock radio, right? You want it to go off in the morning and wake you up. What response
should the the, the radio, the clock radio have when those times when, when the clock time reaches the alarm time?


28 - Timer Events Quiz Solution
-------------------------------

>> So recall that we have this timer which is timing up to an hour for how long the radio is going to play or the beeper
is going to beep.


And Jerrod's question is if during that time the user hits the Snooze button to shut them off, whether that timer
resets. I, I don't personally know, but that's an excellent question that the developer would have an answer to.


My, my intuitive reaction is that, no it doesn't reset the timer, it just allows you to snooze a little while longer.


29 - Internal States
--------------------

>> So yeah, we're, we're, we're, we're clocking the minutes and, and and hours as they go by and so there has to be some
timer to do, that particular thing. So, we can add these timers as submachines, and when we do, the results, is, is what
you see here.


30 - Other Internal Events
--------------------------

For other internal states, their events and responses look like the following.


We have, new event 19, which is the alarm timer expiring, we have the snooze timer expiring. And we have the, clock
timer reach the wake time plus one hour. That is, we expect things to be shut off. And for each of those we have what we
expect the response of the clock radio to be.


31 - Guarded Transitions
------------------------

For guarded transitions, earlier we looked at situations where the response to an event is conditioned on a sub-machine
being in a state. For example, with event 20 we had the response that looked like the following.


If in mode music, go to speaker go in the speaker sub-machine to mode playing.


This response can be coded as a transition between the silent state. And the playing state for the speaker that occurs
when event 20 happens.


And there is a guard that looks like the phrase in, in music.


And that particular logical expression is in square, square brackets.


32 - Cascaded Events
--------------------

The second way of coordinating activities would be cascaded events.


In state charts the response to an event can be the broadcasting of another internal event. Because all states listen
for all events, this mechanism can be used to communicate between concurrently executing sub-machines


33 - Example
------------

For example, when the frequency knob is turned, which was event four, three responses are required.


The physical knob ends up in a new position. The radio channel must be changed.


And the white vertical line indicating the current station must be moved.


The position of the vertical bar is in the province of a different machine from the one that was recording the moving of
the knob.


Somehow, it must be, this, this other state must be informed of the new station.


This can be accomplished by using, by issuing a new internal event which we'll just call event A to which the station
machine responds.


34 - Still To Do
----------------

We can do this, the same sort of invention of new events were appropriate to make sure that all of the news cases that
we started out with actually cause the machine or make the radio behave in a way we like or behave. Well, we're going to
stop the exercise here, but there's some things which we would still have to do to get a complete model.


Although this model process, we have undertaken seems quite long there's still some things we'd have to do. We'd have to
indicate what the default states for each of the concurrent machines is. Recall that for a state machine we can indicate
what the state is when we turn things on, and we would need to do that for these concurrent machines.


We would have to place the guards on the transitions where required, and we'd have to invent these in, internal events.


The results of this process can be seen in, in the diagram shown here. [BLANK_AUDIO]


35 - Validation
---------------

We're not quite done however, so far we've been in the, we've been engaged in building the state chart model. Once the
modeling is over, the resulting stays sharp but still be validated.


There are various ways we could, we could perform this check.


We could hold a review that is get a team of people involved in.


I'll walk through the use cases and make sure that each of the concurrent machines is doing what you would expect it to
do. You could do model checking.


Model checking is a, is an automated technique where you can encode all of the concurrent state machines and any
questions or tests. You'd like to determine whether or not the state machine can ever happen in the state machines and
then you can run what's called a model checker to determine whether those things can ever happen.


And we could even and this is similar to but he could have a separate, we could build a simulator of the execution using
some kind of state chart interpreter, which probably others as, as well, including going back to the users with any
questions that arise during this validation process.


36 - Statechart Modeling Method
-------------------------------

So this exercise that we've gone through with the clock radio, really is a, an example of a process which you could use
to do say chart modeling. And here are the step that we went through. We prepared a use cases to start with of typical
uses of the clock radio. We determined the external percepts, that is, what the user can see or hear or feel, with
respect to the device.


We modeled those percepts with states, which may be corresponding to currently executing state machines. We determined
the external controls and the stimuli or actions or user actions that could occur. In doing so, we might model with
additional states and, or add in additional transitions or events. Then we began to consider the responses that the
system have and we did this with a table in which we listed. The various events and the responses of the systems to
those events. We added in some external internal states or state machines to handle the timing situation.


We provided coordination mechanisms including the guarded transitions and new internal events. And added any additional
actions and activities that the clock radio is required to do in order to implement, or, or implement these particular
responses, and then we, we validated the resultant a state chart


37 - Conclusion
---------------

Clock radios are a common consumer device which people can use without any training and without normally making any
mistakes. Never the less they are complex, as the state chart we have produced indicates. In fact, the clock radio that
I have at home has a bug in it. If you get awakened by the radio, turn it off and then change the alarm time to a later
time. For example, to waking your spouse, the radio comes back on. It still thinks that within, that it is within the
hour window. Okay I call that a bug and


I think that the original designers of the radio should have detected this particular situation and change that
implementation. In any case it is only by carefully modeling and validation that such situations can be avoided.


State charts are a device that can help you do that careful thinking and hopefully lead to better implementations,
better understanding of complex situations and ultimately better implementations of them.


