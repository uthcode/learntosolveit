.. title: 13 - Planning 
.. slug: 13 - Planning 
.. date: 2016-01-23 06:43:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

=============
13 - Planning
=============

01 - Preview
------------

Today we'll talk about planning. Recall that we had said an intelligent agent maps perceptual histories into actions.
Planning is a powerful method for action selection. We'll use the syntax we learned from logic last week to set up the
specification of goals and states, and operators, for moving between states and achieving goals. We'll see that when
there are multiple goals, there can be conflicts between them. We'll describe a specific technique called partial-order
planning that avoids conflict between multiple goals. Finally, we'll talk about a representation called hierarchical
task networks that allows us to make complex hierarchical plans.


02 - Block Problem Revisited
----------------------------

In order to look at planning in detail, let us consider this problem that we have encountered earlier. This is a blocks
world, in which there is a robot which has to move the blocks from the current state, to the goal state.


The robot has only one arm, so it can move only one block at a time.


It can move only a block which does not have some other block on top of it.


Earlier, when we considered this method, we had looked at weak AI methods like means-ends analysis. Now we're going to
look at more systematic, knowledge-based methods. One question unanswered in our previous discussion was, how can we
find which goal to select, among the various goals that are here?


They simply said, the agent might select a goal.


Now we will look at how the agent can in fact do the goal composition and select the right goal to pursue?


03 - Painting a Ceiling
-----------------------

It is considered a little bit more realistic problem. Imagine that you were to hire a robot, and a task of the robot was
to paint the ceiling in your room, and also paint the ladder. So, two goals here, paint the ladder paint the ceiling and
note that the two goals are in conflict.


Because if the robot paints the ladder first, the ladder will become wet.


And this robot cannot climb on it, in order to paint the ceiling. So, the robot must really first paint the ceiling,
then climb down, then paint the ladder and everything is okay. You would expect a human to get this almost immediately,
you probably got it almost immediately. You have to paint the ceiling first, before you paint the ladder. Of course,
every time I've hired construction workers, they always paint the ladder first. Then they go and take a break, and so
that I had to pay them anyway. We'll accept that kind of behavior from human construction workers, we would not accept
that from robot construction workers.


The robots must be intelligent, they must know how to prioritize the goals.


Well, in order to reason about these goals, the robot first must be able to represent them. So, how can we present the
goal of painted ceiling? Now that we have learned about propositional logic, here is a preposition that can represent
painted ceiling. This is the object, this is the predicate on that.


04 - Exercise Goals
-------------------

So in this box, please write down the second goal of painting the ladder in propositional form. And having done that, in
this box, write down how would we represent the two goals as a conjunction.


05 - Exercise Goals
-------------------

>> Let's move on then.


06 - States
-----------

So, we just talked about goals and the goal state of the goals.


In order to specify the goal fully, we need to not only specify the goal state, but also to specify the initial state.


So, let's do that. Let us suppose that the initial state in this world is, that the robot is on the floor. Note, how I'm
writing this. On is a predicate, that says this is a two [UNKNOWN] and I'm reading this as Robot On Floor. So


Robot on Floor, and the Ladder is Dry, and the Ceiling is Dry.


So, this is the Initial state, this is the Goal State. Now we have fully specified the goal. Let's now ask, how can the
robot come up with a plan?


07 - Exercise States
--------------------

Now that we have learned to specify the initial state of the world and the ghosts of the world, let us do an exercise in
specifying other states of the world. So please write down in this box, the state of the world that would occur after
the robot is on the ladder and the ceiling has been painted.


08 - Exercise States
--------------------

>> That's good David. In general if there is information about the initial state, additional information for example Dry
(Ladder) and


Dry (Ceiling), then those assumptions about the world can be propagated to the subsequent state, provided that, no
operator in the middle, in the middle of this initial state and this state, actually negates or deletes any of these
assertions. We'll see more of this in just a minute.


09 - Operators
--------------

Now that we have learned how to specify states in planning, let us look at how to specify the operators. So consider the
operator, climb-ladder. You might specify the climb-ladder operator, and any other operator in general, to a set of
preconditions, and post-conditions.


So for the climb-ladder operator, the precondition might be that the robot is on the floor and the ladder is dry. Notice
that these are being written in the language of propositional logic. And the postcondition for the climb-ladder operator
might be that the robot is on the ladder.


This captures the notion that the robot has climbed the ladder. It was earlier on the floor and later it's on the
ladder. Several things to note here.


First, by convention the precondition does not have any negative leg holds.


All the leg holds in the precondition are positive.


Post conditions of operators may have negative leg holds.


Second, the meaning of this pre-condition, and post conditions is that, these assertions are true in the world before
this operator can be applied.


And that these assertions become true in the world after this operator has been applied. This captures the syntax of the
operator climb-ladder.


The semantics of this operator is that this operator can be applied if and only if the preconditions of the operator are
true in the world.


It cannot be applied if the preconditions are not true in the world


10 - Exercise Operators
-----------------------

Now that you have learned how to specify an operator, such as climb ladder.


Let us do some exercises about how to specify other operators, like descend ladder, paint ceiling and paint ladder. In
these boxes, please write down the pre-condition and the post-condition in the same notation


11 - Exercise Operators
-----------------------

>> David this this has to do with something of his notations. This notation comes from scripts, a planet developed in
the late 60s at the Stanford research institute. One of the early robot planners that ran on a robot called Shaky.


Strips the planner, used your improving to form plans. And it turned out that the use of only positive recoils and the
preconditions made the cure improving processes more efficient.


This convention is a state in AI, since the times of strips and shaky.


12 - Planning and State Spaces
------------------------------

>> That's good David, and to builder's example, what do we actually do, when we have to? Plan a navigation route to go
from one location, to another location, in an urban area. We use knowledge of the goal.


The goal tells us, what turn to take at every intersection? We want to take a turn, that helps us get closer to the
goal. So one thing we are learning here, is there are different kinds of knowledge. There is knowledge about the world,
the intersections and the turns, the states and the operators more generally.


There's also asset knowledge about how to do the operator selection, how to select between greatest terms at any
intersection? This knowledge is tacit, and is sometimes called control knowledge. Goals provide us with the control
knowledge, of deciding how to select between different operators. Let us recall how means-end analysis work. How goals
poetic control knowledge, and means-end analysis heuristic method, if you would compare the Current State and the Goal
State and enumerate the differences between them.


Then we'll select the operator that will help us reduce, the largest difference within the Current State and the Goal
State. That's one, way of using goals as control knowledge to select between operators. Planning, provides more system
mathematics matters for selecting between different operators. So the real problem now becomes, how to do operator
selection, which is the same problem as, how to do action selection. Recall with me, we're talking about intelligent
agents. We define intelligent agents, as agents that map perceptual history into actions.


Action selection was a key problem, was a central problem. This is where planning is central, because it deals starkly
with action selection, or with operator selection. Operators simply mental representations of actions, that we live with
in the world. So, let us look at what a plan might look like, in the language we have been developing for planning. A
plan might look like this, here is the Initial State, and a set of successor states. A series of states, punctuated by
an operators that transform one state into another. Here we have expanded this operative, paint ceiling, to specify its
peak conditions and post conditions, and there's several things not worthy here. Note that the preconditions of this
operator, exactly match the predecessor's state. So, we have on robot ladder, here, and we have on robot ladder, here.
So, some assertions of the world are true, here. And those assertions match the precondition, which is why this operator
is applicable. Similarly, the post conditions of this operator, directly match the assertions about the world in this
successor state.


So I have painted ceiling here, there is painted ceiling there.


There is not dry ceiling here, there is not dry ceiling here.


So this provides a very precise way, of specifying the states, and the operators, and t he exact connections between
them.


13 - Planning
-------------

Let us return to means-ends analysis for just another minute.


Just to see how means-ends analysis, might try to work with this problem, and get into difficulties. So this is the goal
state, painted ladder and painted ceiling. And this is the initial state. Now means-ends analysis may enumerate the
operators that have to deal with the painted ladder and the painted ceiling. Here the operator might be paint ladder.


Here the operator might be paint ceiling, but that requires some pre-condition climb up ladder which is not satisfy the
initial state.


So maintenance analysis picked the goal painted ladder. And select the operator paint ladder, which gets the maintenance
owner to this state.


This is the holistic method. Here is the paint-ladder specified at the right, and you can see the peak conditions of
paint-ladder, match the initial state, and the post conditions match the successive state. Now that means since analysis
has achieved the first goal of painted ladder it make turn to the second goal of painted ceiling. Recall that this is
the current state. So, mean sense analysis may pick the operator climb-ladder, as a peak condition for the operator of
painted ceiling. But note what happens, when precondition of climb ladder, constitutes a postcondition of paint ladder.


So this is not dry ladder, this is quest dry ladder. There is a conflict here.


In a situation like this now, the robot, would need to just wait for the ladder to become dry again, before climb ladder
is a [UNKNOWN]. So it seems as, as if the people who are sometimes hired for working on a home or using main sense
analysis. The first being the ladder, then the goal weight, until the ladder dries up, and then they of course expect me
to pay them for their time. To summarize, we have a plan for achieving one of the goals,


Painted Ladder. But this particular plan clobbers achieving the other goal,


Painted(Ceiling), because it creates a condition, that makes it impossible to achieve the other goal. The question now
becomes [UNKNOWN] reason about the conflict between these codes? How can planning systematically find out, how to
organize these various operators, so that these conflicts do not occur?


What we have described here, this goal clobbering, is true for all simple planners, sometimes called linear planners.
Linear planner, does not try to reason about the conflict between these goals. Does not try to reason about how the plan
for one goal may clobber another goal. Instead it just goes about making plans as if those goals can be achieved in any
order.


14 - Partial Order Planning
---------------------------

>> Good example. And next we will discuss how partial order planning can help us detect conflicts like this and avoid
them.


15 - Partial Planning
---------------------

Now let us see how partial order planning, sometimes also called nonlinear planning, may work for our ladder and ceiling
problem. So here is a goal state, painted ladder. There is the initial state. We can now use the goal knowledge as
control knowledge to select between different operators available in this world.


The only operator whose post conditions match the goal condition of painted ladder. And whose preconditions are
compatible with the initial status, paint-ladder. So we'll select that operator.


When we think of applying the operator paint-ladder to the initial state, we get this as a successor state. Painted
ladder and not dry ladder are coming from the post conditions of paint-ladder. Robot and floor, and ceiling, dry, have
been propagated from the initial state. We changed dry ladder to not dry ladder because that was the post condition of
paint-ladder. We did not change the on robot floor and dry ceiling because pain ladder was silent about them.


16 - Exercise Partial Planning
------------------------------

Now that we have seen how a simple planner may work for this goal, let us see how the simple planner, the linear planner
may work with the goal of painted ceiling. Pleas write down the operators in these boxes and the states that will be
achieved after the application of these boxes in these bigger boxes.


17 - Exercise Partial Planning
------------------------------

>> So note that we just made a connection back to problem reduction that we talked about right after means and analysis.


Ashok in his description talked about the sub-goal of getting up the ladder.


When we talked about problem reduction earlier, we talked about the need to break big problems down into smaller
problems, but we didn't talk exactly about how an agent would go about doing that.


Here we see one way in which an agent would go about actually identifying those sub-goals to accomplish in order to
accomplish the final goal.


18 - Detecting Conflicts
------------------------

So what the partial or the planner has done so far is to view the two goals as if they were independent of each other.


And come up with a partial plan for each of the two goals. It has not yet detected any conflicts between that will not
resolve those conflicts.


The next thing would be to examine the relationship between these two plans and see if there are any conflicts between.
But how might a partial order plan go about detecting conflicts between two plans? So, here is plan one imagined, here
is plan two. The partial order planner may go about detecting conflicts.


We're look at each precondition of the current plan. Under the precondition of an operator any current plan is clobbered
by some state in the, another plan, in the second plan, than the partial order planner would know that there's a
conflict between them. [UNKNOWN] goal resolving these conflicts, but promoting or demoting one clients goal or another
clients goal.


There's if some stated plan B covers the application of some operator in plan A, then we now want to alter the goals in
this plan and this plan in such a way that this operator's done before that state is achieved. Now, let us see how the
partial order planner may go about detecting conflicts within these two plans. So the partial order planner may begin
with this plan for painting the ladder. And see whether the precondition of this operator, paint-ladder, are clobbered
by any state in the second plan. As it turns out, that doesn't happen in this example. Now, the partial order planner
will look at the operands in the second plan. And see whether the preconditions of any of the operators are clobbered by
some status in this first plan. So let's look at climb-ladder here. The precondition of climb-ladder is, on robot,
floor, and dry ladder. And as this precondition is compared with the states.


In the first plan, we can eventually see the conflict. Here is dry ladder, and here is not dry ladder. And this way the
partial order planner has been able to find that the water-less states here in the first plan proverbs the precondition
of one operator on this second plan. To resolve this conflict, the partial order planner may promote these goals or the
goal of painting the ladder.


Some of you also noticed that after the robot has painted the ceiling, the robot is on ladder. But in order to apply the
paint ladder operator, the robot must be on the floor. So here there is an open condition problem.


This particular condition where this operator is not being satisfied.


When the robot is on the ladder. We'll come to this in a minute.


19 - Open Preconditions
-----------------------

So recall that in order to resolve the conflict, the partial order planner has decided to promote this goal over that
one. As it tries to connect these two plans, it finds that there is an open condition problem that we just talked about
On Robot Ladder, does not match On Robot Floor. So now it needs to select an operator whose first condition will match
this state.


Robot On Floor. And those three conditions will match this state,


Robot On Ladder. And there is just one operator that matches those conditions.


And that operator is descend ladder. So now the partial order planner uses this information to select the operator, the
simulator, and now we have a complete plan. So now you know about the algorithm for partial order planning, and how it
works in practice. But what does this tell us about intelligence?


Let's consider several postulates. First, knowledge is not just about the world.


Knowledge is also controlled knowledge. It is often tacit, but this controlled knowledge helps us select between
operators. Second, that goals provide control knowledge. Goals can be used to decide between different operators, and we
select an operator that helps us move closer to the goal. Third, we can view partial order planning as an interaction
between several different kinds of agents or abilities. Each agent here represents a small micro ability.


There is this agent which was responsible for generating plans for each of the goals independently, then there was an
agent responsible for detecting conflicts between them. Then there was a third agent responsible for resolving this
conflict. So we can think of partial order planning as emerging out of interaction between three different agents, each
one of which is capable of only a small ability. So we can think of partial order planning as emerging out of
interaction between free agents, where each agent is capable of only one small task.


Minsky has proposed a notion of a society of mind. A society of agents inside an intelligent agent's mind that work
together to produce complex behavior, where each agent, itself is very simple. As in this case, a simple agent for
detecting conflict, or a simple agent for resolving conflicts, and of course an agent for making simple plans with
simple goals. It is one other lesson to take away from here. When you and I solve problems like the ladder and the
ceiling problem, we seem to address these problems almost effortlessly and almost instantaneously. So it looks really
simple. What AI does, however, is to make the process explicit.


To write a computer program that can solve the same problem is very hard. It is hard because the computer program must
specify each operator, each precondition, each state, each goal, every step very, very clearly and very, very precisely.


By writing this computer program is this AI agents that consults problem.


We make the process that humans might be using more explicit. We generate hypotheses about how humans might be doing it,
which is a very powerful idea.


20 - Exercise Partial Order Planning I
--------------------------------------

Now that we have seen partial art of planning in action, let us try to do a series of exercises to make sure that we
understand it clearly.


We have come across this problem earlier. This is the micro world of blocks.


Here is the initial state. And here is the goal state. We need to transfer from this initial state to the goal state,
moving only one block at a time.


Please write on the initial state and the goal state in propositional logic.


21 - Exercise Partial Order Planning I
--------------------------------------

David? >> So our initial state, is that each block is on top of the other.


D is on B. B is on A. A is on C. And C is on the table. Our goal state, is each block on top of the other in a different
order, an alphabetic order. So, A is on B. B is on C. And C is on the table. So our initial state is that the blocks are
all stacked up, D is on B, B is on A,


A is on C. C is on the table. And our goal state, is that the blocks are stacked up in alphabetical order, so A is on B,
B is on C, C is on D and D is on table.


22 - Exercise Partial Order Planning II
---------------------------------------

Now that we humans find addressing problems like this almost trivial, we know what to do here. Put D on the table, put B
on the table, and so on.


And then put C on top of D and so on. The question is, how can we write an AI program that can do it? And, by writing an
AI program, how can we make things so precise that that will provide insight into human intelligence. To do this, let us
start writing the operators that are available in this particular work.


There are only two operators. I can either move block x to block y, which is the first operator here. Or I can move
block x to the table.


Note two things. First, instead of saying block A and block B, we have variabalized them, move block x to block y, where
x could be A, B,


C or D, and similary for block y. And this is just a more concised notation.


Second, that in order to move block x to block y, both x and y must be clear. That is neither x nor y should have any of
the block on top of them. Given this setup, please write down the specification of the first operator as well as the
second operator.


23 - Exercise Partial Order Planning II
---------------------------------------

>> So like you said, our precondition for the first one, is that both x and y are clear. We can't move x if there's
anything on top of x, and we can't put it on y if something is already on top of y. Our post condition then, is that x
is on y. For the table it's a little bit easier, the table has unlimited room. So for the table, as long as X is clear
we can move X to the table. And in the postcondition is that X is now on the table.


24 - Exercise Partial Order Planning III
----------------------------------------

So given the various goals here, A and B,


B and C, and so forth, write down the plan for accomplishing each goal, as if these goals were independent of each
other.


We are shown here only three goals here not the fourth goal of D on table, because of lack of space. But D on table
anyway is [UNKNOWN].


25 - Exercise Partial Order Planning III
----------------------------------------

>> So like you said [UNKNOWN], the plan of putting D on table's kind of trivial.


And we actually see that it's the first step of any other plan.


So we don't really need to articulate that explicitly. For putting A on B, our fastest idea would be to put D on the
table, then to put B on the table, then to put A on top of B. I would just get a straight to putting A on B.


For putting B on C, we need to put D on the table, B on the table,


A on the table, and then move B on to the top of C. And then, for putting for C on D, we would need to move D to the
table, B to the table,


A to the table, and then put C on top of D.


26 - Exercise Partial Order Planning IV
---------------------------------------

Now that we have these three plans for accomplishing the three goals, can you detect the conflicts between these plans?
Use a pencil and a piece of paper, to detect the conflicts and resolve the conflicts and then write down the, ordering
of the goals in these boxes.


27 - Exercise Partial Order Planning IV
---------------------------------------

>> But David


28 - Exercise Partial Order Planning V
--------------------------------------

Now that we know about the conflict between these plans, please write down the final plan for achieving the goal state.
To save space, just write down the operators. You don't have to specify all the states in this plan.


29 - Exercise Partial Order Planning V
--------------------------------------

>> That's good David. Note that when we did this problem previously using means analysis and product reduction, we ran
in to all kinds of problems, because plans for property goals and we had no way of ordering these radius goals.


Now we have a way, that's the power of partial [UNKNOWN].


Note also that this partial art of planning, this algorithm makes certain things that are implicit in human reasoning,
explicit. Presumably when you and


I reason about things we must be reasoning something like this, or at least this is one hypothesis about how we might be
reasoning. And we have just made many of the operations of human reasoning so explicit and so precise.


30 - Hierarchical Task Network Planning
---------------------------------------

Our next topic in planning is called hierarchical planning.


We'll introduce the idea to you.


We'll also introduce the representation called hierarchical task network to you.


HTN for hierarchical task network. To illustrate hierarchical planning, imagine that you are still in the box
microworld. Here is the initial state. And here is the goal state. These states are more complicated than any initial
state and goal state that we have encountered so far. So as previously, we can use partial order planning to come up
with a plan to go from this initial state to goal state. Here is the final plan, and as you can see, it's pretty long
and complicated, with a large number of operations in them. So the question then becomes, can we abstract some of these
operations at a higher level? So that instead of thinking in terms of these slow level move operations, we can think in
terms of high level macro operations. And those macro operations will then make the problems space much smaller, much
simpler so that we can navigate it.


And then we can expand those macro operators into the move operations.


31 - Hierarchical Decomposition
-------------------------------

So look at the macro operators at a high level abstraction, consider this one part of the current problem. Here is the
initial state, here is the goal state, there is the final plan. To enlist this idea of macro operators, and hierarchical
planning, at multiple [UNKNOWN] of abstraction, let us read with this problem that we had encountered earlier. This was
the initial state, this was the goal state. And we come up, we came up with this as the final plan.


Now, we can think of these three operations as being abstracted out into a macro operator that we can call unstack. And
these three operations being abstracted out into a macro operator that we can call stack-ascending.


Just simply saying stacking them in a particular ascending order. Here is the specification of the two macro operators.
Unstack, and stack-ascending.


You do preconditions and post conditions. And this macro operator, also tells you how this macro operator can be
expanded in to the lower level move operations. Similarly for the stack ascending macro operator.


32 - Hierarchical Planning
--------------------------

Now that we have illustrated hierarchical planning, what does it tell us about intelligence? Intelligent agents, both
cognitive and artificial, constantly faced with large, complex problems. The problem spaces corresponding to these
problems often have [INAUDIBLE] explosion of states in them. Intelligent agents address these complex problems by
thinking at multiple levels of abstraction. So that at any one level of abstraction, the problem appears small and
simple. In order to be able to reason at these multiple levels of abstraction, we need knowledge at multiple levels of
abstraction. In this case, there was knowledge not only at the level of move operations, but also the level of macro
operations, like unstack and stack ascending. And perhaps even higher level macro operations, like sort.


This goes back to the fundamental notion of knowledge based AI. Intelligent agents use knowledge in order to be able to
tackle hard, complex problems.


33 - Assignment Planning
------------------------

How would you use planning to develop an agent that can answer Raven's progressive matrices? So, the first question you
want to ask here is what are our states? What's our initial state? And what's our final state?


Given that, what are the operators that allow the transition between them.


How would we select those operators?


We are talking about partial ordering planning in this lesson, what conflicts are possible when we are trying to solve
Raven's problems?


How would we detect those conflicts beforehand and avoid them? Note that again we can consider this at two different
levels. First, we can think of the agent as having a plan for how to address any new problem that comes in. Or second,
we can consider the agent as discerning the underlying plan behind a new problem.


34 - Wrap Up
------------

So today we've discussed how to plan out actions using formal logic.


We started off by talking about states, operators, and goals in formal logic.


We then used those to contextualize our discussion on detecting conflicts that might arise. This introduced the need for
partial-order planning which helps us avoid those conflicts beforehand.


Finally we talked about hierarchical tasks networks which can be used for hierarchical planning. Now, we're going to
move on to understanding, which builds on our notion of frames from a few lessons ago, but if you're interested in this,
you can jump forward to our lessons on design. Configuration and diagnosis leverage some of the concepts of planning
very heavily.


35 - The Cognitive Connection
-----------------------------

Planning is another process central to cognition.


It is central because action selection is central to cognition. You and


I are constantly faced with the problem of selecting actions.


Where should I go for dinner today? What should I cook for dinner today? How do


I cook what I wanted to cook? I got a bonus. What should I do with the bonus?


Shall I go for a vacation? How should I go to a vacation?


Where should I go to a vacation? These are all problems of action selection. And


I need planning to select the appropriate actions.


Cognitive agents also have multiple goals. As a professor, one of my goals right now is to talk with you. Another goal
that I have is to become rich, although I know that becoming a professor is not going to make me rich.


The point is that cognitive agents have multiple goals that can have interactions between them. Sometimes interaction is
positive.


Achieving one goal provides an opportunity for achieving the second goal.


Sometime the interaction is negative, there are conflicts. Cognitive agents detect those conflicts. They avoid those
conflicts. And planning, then, is a central process for achieving multiple goals at the same time.


36 - Final Quiz
---------------

Please write down what you learned in this lesson.


37 - Final Quiz
---------------

Great. Thank you so much for your feedback.


