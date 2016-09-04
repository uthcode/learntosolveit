.. title: 21 - Configuration 
.. slug: 21 - Configuration 
.. date: 2016-01-23 06:51:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

==================
21 - Configuration
==================


01 - Preview
------------

Today, we'll talk about configuration. Configuration is a very routine kind of design task in which all the components
of the design are already known.


The task now is to assign values to the variables of those components so they can be arranged according to some
constraints.


Configuration will be your first part under the unit on designing creativity.


We'll start by talking about design, then we'll define configuration. Then we trace through the process of
configuration, a specific measure called planned refinement. Finally, we'll connect configuration to several earlier
topics we have discussed such as classification, case based reasoning, and planning.


02 - Define Design
------------------

Let us talk about what is design. Design in journal takes us input some sort of needs, so goals or functions. It gives
us output that's specification of this structure of some artifact that satisfies those needs and goals and functions.
Note that the artifact need not be a physical product.


It can be a process. A program, a policy. Some example for design, design a robot that can walk on water.


Design a search engine that can return the most relevant answer to a query.


The Federal Reserve Bank designs and monitor the policy to optimize the economy.


Note the design is very wide ranging, open ended and ill-defined. In problem solving, typically the problem remains
fixed, even as the solution evolves. In design, both the problem and the solution co-evolve.


The problem evolves as the solution evolves. We are studying design and


AI because we are working with AI agents that can do design.


At least potentially, we want AI agents that can design other AI agents.


03 - Exercise Designing a Basement
----------------------------------

>> Thanks, Isuke so right now, my wife and I are actually building a house and as part of that, we need to configure the
basement for the house. I've taken a list of some of the requirements for this basement and listed them over here on the
left. And on the right, I have the variables that we need to assign values to, we have things like the width of the
utility closet, the length of the stairwell, we also had two additional rooms, each must have their own length and
width. So try to configure our basement, such that we meet all the different requirements listed over here on the left,
write a number in each of these blanks.


04 - Exercise Designing a Basement
----------------------------------

>> Thank you, David. There are several things to note from David's analysis.


One is that, in configuration final, we want an arrangement of all the components of all the parts. So in this case,
finally, we want an arrangement of all the rooms and these tables, and the utility closets, and so on. Not just the size
of each one of them, but the actual spatial layout. Second, they would begin by assigning values to some variables here.
Because he thought that these variables were more restricted.


One can use a number of different heuristics for ordering the variables.


Perhaps, we can choose those variables which are most restricted first, or we can choose those variables that restrict.
Others the most first.


We can choose the most important variables, first. The point is, there can be a large number of variables, and we can
impose an ordering on them.


05 - Defining Configuration
---------------------------

>> Designing journal is a very common information processing activity and configuration is the most common kind of
design.


Now that we have looked at the definition of the configuration task, we are going to look at matters for addressing the
task. Once again, recall that the components in case of configuration are already known.


We are deciding on the arrangement of those components. We are assigning values to specific variables of those
components, for example, sizes.


06 - The Configuration Process
------------------------------

>> So for an example that might hit a little bit closer to home for many of you, as you've been designing your agents
that can solve the Raven's test, you've done a process somewhat like this. You start with some specifications, general
specifications that your agent must be able to solve as mini problems on the Raven's test as possible. You can start
with an abstract solution of just the general problem solving process, that you may have then refined to be more
specific about the particular transformations to look for or the particular problem solving methods to use. That got you
to your final result. But when you ran your final result, you may have found something like, it would work but it would
take a very, very long time to run, weeks or months. So that thing causes you to revise your specifications. You not
only need an agent that can solve as many problems as possible, but you also need one that can solve it in minutes or
seconds instead of weeks or months.


07 - Example Representing a Chair
---------------------------------

Let us look at how the process of configuration would work in detail.


Recorder will met a file of represent in reason, will represent knowledge and then reason over it. So suppose it asked
the configure a chair. We must then somehow represent all of the knowledge of this chair then we can reason over it.


So we will represent all of our knowledge of the chair in the form of a frame.


Here's is the frame, here are the beta slots. For the time being, let's just assume that there are six slots that are
important. The last four of the slots may point to their own frames. So there might be a frame for legs, a frame for
seat, and so on. Now some of these frames have slots like size, and material, and cost. For legs, you may have an
additional slot like count.


What is the number of legs on the chair? And this particular frame representation captures of the knowledge of the
generic, prototypical chair.


To do configuration design is to come up with a specific arrangement of all the parts to this particular chair, to
assign values to each of the variables, which means filling out the fillers for each of the slots. Of course, the values
of these variables depends in part on the global constraints of mass and cost. We may, for example, have a global
constraint on the mass of the chair, or in the cost of the chair, or both. We may have additional constraint as well.


For example in material of a chair might become an, perhaps the material needs to be metal.


08 - Example Ranges of Values
-----------------------------

Now in configuration design, we not only know all the components like legs, and set, and arms, and so on. We not only
know the variables for each of the components, like size and material, and cost.


But we also know the ranges of values that any of these variables can take.


Thus the seat of a chair may have a certain weight, or length, or depth. Here between the sides and the seat in a very
simple matter in terms of the mass of the seat as measured in grams. So 10 to 100 grams, you'll see in minute why we're
using this simple measure. So when it is brackets for this material slot suggests that there is a range here, it will
show the range on the left [UNKNOWN]. TThe cost then will be determined by the size and the materials. Let us suppose
that this table captures the cost per gram for certain kinds of materials. Now you can see why we're using gram as a
measure for the size of the seat. We wanted to very easily relate the size to the cost.


The material slot now can take one of these three values. This is the range of values that can go into the material
slot. Given a particular size and a particular material, we can calculate this cost. Note that this representation
allows us to calculate the total mass of the chair and the total cost of the chair, given the total mass and the total
cost at least of the components.


09 - Example Applying a Constraint
----------------------------------

Now let us suppose that we get a new order in which a customer wants a chair that weighs over 200 grams, costs at most
$20, and has four legs.


Given the specification, what configuration process can use this knowledge to fill in the values of all the variables to
satisfy the specification. So the first thing the process might do is to write down all the constraints that are given
as part of the input specification. So the mass is greater than 200 grams, the cost is less than $20, and the count of
legs is 4. Now suppose that a configuration process has an abstract plan which first decides on the value of the cost
variable before it decides on other variables. Let us also further suppose that this plan for deciding the cost evenly
distributes the cost between the greatest components until unless specified otherwise by the specification. In this case
the cost plan distributes this cost of $20 between the four components and assigns less than five for each one of them.
Now we define an expanding plan.


This is two aspects to it, refine and expand. Index and aspect we deal with the components instead of the chair as a
whole. And the define aspect we deal with more detailed variables that were not there in the chair. Consider the
component legs, for example. We already know the count, four, in the input specification. We know the cost, no more than
$5 from the higher level plan. Now we can design by using the other two variables,


25 grams and wood, for example. We can do the same for the other components.


As we assign values to the variables of each of these components, we get a complete arrangement of all these components
here, with values assigned to each of the variables. Given the specific values we assign to the variables for each of
the components, we can now compute whether the constraint given in the input specification are satisfied. In this
particular example, both the mass and the cost of the chair satisfy the input constraints. Note that the define and
expands step in this particular process might have operated a little differently. It is also possible that define and
expand step might say, the less, decide on the material before we decide on any of the other features.


Plus within thin complex configuration process, different designers may use different plans and different plans to find
expansion mechanisms.


Of course it is also possible that once we have a candidate solution, the candidate solution may not necessarily satisfy
the input constraints. So the cost may turn out to be more than $20, for example.


In that case there are two options. Either we can iterate on the process, loading the cost, or we can go about changing
the specification.


10 - Exercise Applying a Constraint
-----------------------------------

Let us do an exercise together. This exercise again deals with the configuration of a chair. The input specification is
a chair that costs at most $16 to make, and has 100 grams metal seat. Please fill out the values of all of these boxes.


Try to use a configuration process that we just described, and make a note of the process that you actually did use


11 - Exercise Applying a Constraint
-----------------------------------

>> That's good, David. It's important to note that David used several different kinds of knowledge. First, he had
knowledge of the generic chair. He knew about the components. He know about the slots, but not necessarily all the
fellows for these slots. Second, he had heuristic knowledge. He used the term heuristic, recall that down here,
heuristic stands for rule of thumb. So, heuristic knowledge about how to go what filling the values of some of these
slots. Third, explicit in this is not just the knowledge about legs and seats and arms and so on, but also how does
chair as a whole is decomposed in these components.


That is one of the fundamental rules of knowledge and knowledge based AI.


It allows to struck to the problem so this problem can be addressed efficiently.


Note this process of configuration design is closely related to the method of constraint propagation that we discussed
in our previous lesson.


Here, are some constraints, and these constraints have been propagated downwards in the pan obstruction hierarchy.


12 - Connection to Classification
---------------------------------

>> So it sounds to me like, while classification is a way of making sense of the world, configuration is a way of
creating the world.


With classification we perceive certain details in the world and decide what they are. With configuration, we're given
something to create and we decide on those individual variables


13 - Contrast with Case-Based Reasoning
---------------------------------------

We can also can cross configuration with case based reasoning.


Both configuration and case based reasoning are typically applied to routine design problems, problems of the kind that
we've often encountered in the past.


Gives a configuration, we start with a prototypical concept, then assign values to all the variables as we saw in this
chair example.


In case of case-based reasoning we start with the design of a specific chair that we had designed earlier. Look at its
variables and tweak it as needed to satisfy this constraint so the current problem.


Case-based reasoning assumes that we already designed our other chairs, and we have stored examples of the chairs for
designing the memory.


Configuration assumes, that we already designed enough chairs so that we can in fact extract the plan. When a specific
problem is presented to an IA agent, the IA agent, if it is going to use the method of configuration, is going to call
upon the plan obstruction hierarchy and then start defining plans. If the AI agent uses the method of case based
reasoning, then it'll go into the case memory, retrieve the closest matching case, and then start tweaking the case.
Little bit later we will see how an AI agent select between different methods that were able to address the task. As we
have mentioned earlier in the course, the chemical periodic table was one of the really important scientific
discoveries. Similar to chemical periodic table, we are trying to build a periodic table of intelligence.


Unlike the chemical periodic table which deals with balance electrons.


Our periodic table of intelligence, deals with tasks and methods.


In this particular course, we have considered both a large number of tasks, configuration being one of them, as well as
a large number of methods, [UNKNOWN] instantiation and case-based reasoning being two of them.


14 - Connection to Planning
---------------------------

The process of configuration is also related to planning.


You can consider a planner that actually generates the plan in this plan obstruction hierarchy. But then for any plan in
this plan obstruction hierarchy, then it converts a plan in this plan obstruction hierarchy into a skeletal plan.


It drops the values of the variables in the plans and constructs it into a plan it's simply specify the variable without
specifying the values.


The process of configuration planning then, takes these plans, organizes them into obstruction hierarchy and goes about
[INAUDIBLE] shading and refining and expanding them. We already discussed how configuration is connected to a number of
other lessons like case based reasoning, planning and classification. You may also consider this plan to be kind of
strict for physical object. In addition, this plans have been learned, through learning methods similar to the method of
incremental concept learning.


In addition, this plan hierarchy might be learned through learning methods similar to the method for incremental concept
learning. One of the things that we are doing in knowledge based AI is, to describe the kinds of knowledge that we need
to learn. Before we decide on what is a good learning method, we need to decide on what is it we need to learn? The
configuration process tells us of the different kinds of knowledge that then become targets of learning.


To connect this lesson back to our cognitive architecture, consider this figure once again. So knowledge of the
prototypical chair, as well as knowledge about the radius, plans, and the abstraction hierarchy are stored in memory. As
the input gives specification with the design problem, the reasoning component instantiates those plans, refines them
and expands them.


The knowledge itself is learned through examples of configuration of chairs that presumably, the agent is already
encountered previously.


15 - Assignment Configuration
-----------------------------

So how might you use the idea of configuration to design an agent that can answer Raven's progressive matrices? We've
talked in the past about how constraint propagation can help us solving these problems. If configuration is a type of
constraint propagation, how can you leverage the idea of variables and values in designing your agent? What are the
variables and what values can they take? We've also discussed how planning can be applied to


Raven's progressive matrices. If configuration leverages old plans, how you build your agent to remember those old plans
and reconfigure them for new problems? Will it develop the old plans based on existing problems, or will you hand it the
problems in advance?


16 - Wrap Up
------------

So today we've talked about configuration, a kind of routine design task. We do configuration when we're dealing with a
plan that we've used a lot in the past, we need to modify to deal with some specific new constraints. So for example,
we've built thousands of buildings, and thousands of cars, and thousands of computers, and each of them is largely the
same. But there's certain parameters, like the number of floors in a building, or the portability of the computer, that
differ from design to design. So we need to tweak individual variables to meet those new constraints. We started this
off by defining design in general, and then we used that to define configuration, as a certain type of routine design
task. We then discussed the process of configuration and how it's actually very similar to constraint propagation that
we've talked about earlier.


Then we connected this to earlier topics like classification, planning and case-based reasoning, and saw how in many
ways, configuration is a task, while other things we've talked about provide us the method for accomplishing that task.
So now we'll move on to diagnosis, which is another topic related to design, where we try to uncover the cause of a
malfunction in something that we may have designed. In some ways, we'll see that diagnosis is a lot like configuration
in reverse.


17 - The Cognitive Connection
-----------------------------

Design is a very common cognitive activity. Some people even claim that design is a single cognitive activity that has
the most economic value of all such activities. Configuration is a type of routine design, that occurs every single day.
For example, you need to run some errands.


You know the roads, you know the vehicle, you know the traffic patterns.


Now you need to configure the specific route that can optimize some constraint such as time. Cooking is another everyday
example of configuration.


We know the recipes, which tell us about the high level plans and the ingredients we need to assign values to specific
variables that can optimize some constraints such as taste. Notice that we can separate task from method.


Configuration is a task that can be addressed by many methods. We will look as several of them, such as [UNKNOWN]. Plant
refinement, [UNKNOWN] test, and so on. [BLANK_AUDIO]


18 - Final Quiz
---------------

Please summarize what you learned in this lesson in this blue box.


19 - Final Quiz
---------------

Great, thank you very much.


