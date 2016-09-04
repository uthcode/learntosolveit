.. title: 26 - Wrap-Up 
.. slug: 26 - Wrap-Up 
.. date: 2016-01-23 06:56:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

============
26 - Wrap-Up
============

01 - Preview
------------

Today we'll wrap up this course. It's been a fun journey. But like all journeys, this one too must come to an end. The
goal for today's lesson is to tie together some of the big things we have been discussing, and to point to some of the
other big ideas out there in the community.


We'll start by revisiting the high level structure of the course.


Then we'll go through some of recurrent patterns and principles we've encountered throughout the course. Finally, we'll
talk about all the broader impacts and applications of knowledge based AI.


02 - Cognitive Systems Revisited
--------------------------------

Let us revisit the architecture for a cognitive system.


We have come across this several times earlier in this course. We can think in terms of three different spaces. A
Metacognitive space, a Deliberative space, and a Reactive space. The Reactive space directly maps percepts from the
environment into actions in the environment. The Deliberative space maps the percepts into actions, with the mappings
mediated by reasoning and learning and memory. So, while this is a see act cycle, this is a see think act cycle. The
metacognitive space monitors the deliberative reasoning. It sees the deliberative reasoning and acts on the deliberative
reasoning. As we had discussed earlier, it's better to think of these in terms of overlapping spaces rather than
disjoint layers.


When we were discussing metacognition we also saw that we could draw arrows back from here like this because
metacognition could also act on its own.


This cognitive system is situated in the world.


It is getting many different kind of input from the world. Percepts, signals, goals, communication with other agents.
Depending on the input, and depending upon the resources available to the agent to address that input, the agent may
simply react to the input and give an output in the form of an action to a percept, for example. Or the agent may reason
about the input.


And then decide on an action after consulting memory and perhaps invoking learning and reasoning. In some cases, the
input that the agent receives might be as a result of the output it had given to a prior input. For example, it may have
received a goal.


Then come up with a plan. When it had received the input of the plan, failed upon execution. In that case, deliberation
can give an alternative plan.


A metacognition may wonder about, why did the planner fail in the first place?


And repair the planner, not just the plan. Just like reaction and deliberation are situated in the world outside,
metacognition, in a way, is situated in the world inside. It is acting on the mental world.


While deliberation and reaction act on the objects in the external environment.


For metacognition it is the thoughts and the learning and the reasoning that are objects internally in the amygdala. Of
course, this input is coming constantly. Even now, as you and I are communicating, both you and I are receiving input.
And we're giving output as well. In fact, the cognitive system is constantly situated in the world. It is never separate
from the world. There is no way to separate it. It has input coming constantly.


There is output going out constantly. The world is constantly changing, and the cognitive system is constantly receiving
information about the world.


It uses this knowledge in it's knowledge structure to make sense of the data about the world. And it decides on actions
to take on the world.


Recall that we had said that intelligence is a function that maps the perceptual history into action. And to some
degree, intelligence is about actions, reactions. About selecting your right output to act on the world. Depending on
the nature of the input the output may vary. If the input is a goal, the output might be a plan or an action. If the
input is a piece of knowledge, the output might be internal to the cognitive system. And the cognitive system may
assimilate that knowledge in its internal structures.


If the input is a percept, the output might be an action based on that percept.


If the input is new information, the cognitive system will learn from the new information, and then store the result of
the learning in its memory. The world here consists not just of the physical world, but of the social world as well.


Thus, this cognitive system is situated not just in the physical world but is also situated in the social world,
consisting of other cognitive systems and constantly interacts with them. Once again, the interactions between these
cognitive systems can be of many different kinds. Percepts, goals, actions, plans, information, data. Any cognitive
system is not just monitoring and observing the physical world, but it's also monitoring and observing the social world,
the actions of other cognitive systems in the world, for example. Any cognitive system learns not just from its own
actions but also from the actions of other cognitive systems around it. Thus a cognitive system needs to make sense not
just to the physical world but also by the social world.


We saw some of this when we were talking about scripts.


There we saw how a cognitive system used a script to make sense of the actions of other cognitive systems. This
architecture is not merely an architecture for building AI agents, it is also an architecture for reflecting on human
cognition. Does this architecture explain large portions of human behavior?


03 - Course Structure Revisited
-------------------------------

>> This summarizes 30 topics that we covered in this class, which is quite a lot. Of course, there is a lot more to talk
about each of these


30 topics than we have covered so far. Therefore, we have provided readings for each of the topics. And you are welcome
to pursue the readings for whatever topic that interests you the most.


We'll also love to hear about your views about this on the forum.


04 - The First Principle
------------------------

At the beginning of this course we enumerated seven major principles of knowledge based AI agents that we'll cover in CS
7637.


Now let's wrap up this course by revisiting each of the seven principles.


Here is the first one. Knowledge based AI agents represent in organize knowledge into knowledge structures to guide and
support reasoning. So the basic paradigm here is represent and reason.


Represent and reason. If you want to reason about the world, you'd have to represent knowledge about the world in some
way. You not only want to represent knowledge to support reasoning, you also want to organize this knowledge into
knowledge structures to guide, to focus the reasoning.


Let us look at a few examples that we covered in this course about dispensing.


Semantic networks not only allow us to represent knowledge about the world, they also allows us to organize that
knowledge in the form of a network. We use semantic networks to address the problem of the guards and prisoners dilemma.


The advantage of the semantic network was that they expose the constraints of this problems so clearly, so that we can
in fact reason about it. And notice that the organization helps us focus the reasoning. Because of the organization,
there's so many other choices we don't have even have to reason about them.


Frames were on to the knowledge structure that organize knowledge, and guided and supported reasoning. Given frames for
things like earthquakes, we could reason about sentences like, a serious earthquake killed 25 people in a particular
country. We'll also use frames to support common sense reasoning.


Here, Ashok is moving his body part to a sitting position. Here,


Ashok is moving himself into a sitting position. Here, Andrew sees Ashok.


Now Andrew moves to the same place as Ashok, and Andrew then moves in menu to Ashok. This is about a story about
visiting a restaurant. Once again, there are knowledge structures here. These knowledge structures are not only
representing knowledge, they are organizing knowledge into a sequence of actions. These knowledge structures help
generate expectations. So we know what Ashok expects to happen next in any of these situations.


We also know how Ashok can detect surprises. When the non-obvious thing happens,


Ashok knows that it has warranted the expectations of the scripts, and can do something about it. This is how the script
support in guided reasoning.


We also saw this principle in action, when we were talking what explanation based learning. In order to show that an
instance was an example of a particular concept, cup, we constructed complex explanations. In this case, we were
constructing the complex knowledge structure on the fly out of smaller knowledge structures. The smallest knowledge
structures came out of precedents, or examples we had already known.


Then we composed the knowledge of these various knowledge structures, into a complex explanation to doable reasoning, to
guide and support their reasoning.


You've seen this principle in action in several other places in this course.


This is one of the fundamental principles. Represent, organize, reason.


05 - The Second Principle
-------------------------

Our second main principle for CS7637 was that learning in KBAI agents is often incremental. This means that information
or data or experiences arrive one at a time. This is one of the key differences between knowledge based AI, and other
forms of AI, like machine learning. In those forms a large amount of information is often given right at the beginning.
Here, our agents learn step by step, incrementally. We first encountered this with learning by recording cases. Our
agents learned each individual case one by one.


The experiences themselves were the increments in this learning strategy.


Case based reasoning also operated on individual cases, but it organized them into much more complex knowledge
structures.


Like tagging them in an array. Or organizing the my discrimination tree. But the fundamental object of knowledge were
still individual cases that arrived one by one. We did a complex exercise where one by one we added these new cases into
our discrimination tree. Incremental concept learning was, as the title suggest, incremental. Here were received
positive and negative examples one at a time.


Based on the difference between our current concept, and our new example, and whether or not the new example was a
positive or negative example.


We would change our concept. This is always done example by example, incrementally. Version spaces involved a very
similar kind of knowledge.


Here experiences came one at a time, and we generalized a specific model and specialized the general model to converge
down to an understanding of the concept. Finally, learning by correcting mistakes is also deeply incremental. Here, the
individual mistakes arrived incrementally, and based on the individual mistakes, our agent modified it's knowledge base
to repair the cause of the previous mistake.


To take away here is that many of our methods in learning, reasoning and memory.


All involve dealing with information that comes incrementally, bit by bit, instead of processing a large amount of data
all at the same time.


One can also see this connects more closely to human experience, where we're constantly experiencing the world
experience by experience instead of being given a lifetime of experiences all at once.


06 - The Third Principle
------------------------

The third principle of knowledge based AI agents in CS7637 is that reasoning is typically top-down as well as bottom-up.
Ordinarily, we assume that data is coming from the world and most of the reasoning is bottom-up as we interpret the
data. In contrast to knowledge based AI, low level processing of the data results in the invocation of knowledge
structures from memory. These knowledge structures then generate expectations, and the reasoning becomes top down.


Frames were an example of this kind of top down reasoning. We had the input,


Angela ate lasagna with her dad last night at Olive Garden. And the processing of this input led it to the invocation of
this particular frame.


Once this frame has been pulled out of memory, then this particular frame can generate a lot of expectations. For
example, was the object alive when Angela ate it? False. Where is the object now?


Inside the subject. What is the subject's mood after she had dinner?


She was happy. A similar kind of top down generation of expectations occurred when we used frames to understand simple
sentences about earthquakes.


Scripts are another example of this kind of top-down generation of expectations and expectation based processing. Once
we have a script, then that script generates expectations over the next action. [BLANK_AUDIO]


It tells us what to look for in the world, even before that happens. And when that doesn't happen, we know an
expectation has been violated and we are surprised. Constraint propagation is another way of thinking about top down
processing. We will input data in the form of pixels representing this cube.


We have to infer that this image, in fact, is that of a cube. We have knowledge about this constraint of various kind of
junctions that can occur in the world of cubes and this knowledge then generates expectations of what might be a blade
and what might be a fold. This notion of top-down processing using knowledge structures to generate expectations of the
world in order to be able to interpret data essential to knowledge based AI.


It's also deeply connected with human cognition.


Some current theories of human cognition think of brains as predictive machines.


We are constantly generating expectations, we are constantly making predictions over the world, that guide our
reasoning, that guide our actions.


07 - The Fourth Principle
-------------------------

Our fourth principle was a Knowledge Based AI agents match methods to tasks.


At the beginning of this course we covered several very powerful problem solving methods like Generate & Test, and


Means-Ends Analysis. But because they were very powerful and very general, they also weren't necessarily the best for
solving any one problem.


We also covered some more specific problem solving methods like planning that addressed a narrower set of problems but
addressed those problems very, very well. We also covered several tasks in this class, like configuration and diagnosis
and design. These tasks could all be carried out by a variety of methods. For example, we can imagine doing
configuration with Generate & Test or we generate every possible configuration of a certain plan and then test to see
which one is best. We could also do configuration by


Problem Reduction where we reduce the problem down into the sub parts and solve them individually and then compose them
into an overall solution.


In this way, knowledge based AI agents match methods to tasks.


In some cases we do the matching, we decide that generate and test is the best way to address this diagnosis problem. In
other cases we might design AI agents with their own meta-reasoning such that they themselves can decide which method is
best for the task that they're facing right now.


Note that this distinction between methods and tasks is not always necessarily absolute. Methods can spawn different sub
tasks, so for example, if we're doing design by case-based reasoning that spawns new problems to address. And we might
address those new problems, those new tasks, with analogical reasoning, or with problem reduction. This gets back to our
meta-reasoning notion of strategy integration. In this way, knowledge based AI agents match methods to tasks not only at
the top level, but also at every level of the task-subtask hierarchy.


08 - The Fifth Principle
------------------------

The first principle of knowledge based AI, as we have discussed it in CS7637, is that AI agents use heuristics to find
solutions that are good enough, but not necessarily optimal. Some schools of AI put a lot of emphasis on finding the
optimal solution to every problem. In knowledge based AI, we consider agents that find solutions that are good enough.


Herbert Simon called this satisficing. The reason for finding solutions that are only good enough is because of the
trade off between computational efficiency on one hand and optimality of solutions on the other.


We can find optimal solutions, but that comes with the cost of computational efficiency. Recall one of the conundrums of
AI. AI agents are with limited resources, bounded rationality, limited processing power, limited memory size. Yet, most
intrusting problems are impractical. How can we get AI agents to solve impractical problems with limited rationality and
yet give nearly a ten performance? We can get AI agents to do that if we can focus on finding solutions that are good
enough, but not necessarily optimum.


Most of the time you and I as human agents do not find optimum solutions.


The plan you may have to make dinner for yourself tonight is not necessarily optimum, it's just good enough.


The plan that you have to go from your house to your office is not necessary optimal, it's just good enough. The plan
that you have to walk from your car to your office is not necessary optimal, it's just good enough.


Further, AI agents use heuristics to find solutions that are good enough.


They do not do an exhaustive search, even the exhaustive search might yield more optimal solutions because exhaustive
search is computationally costly.


We came across this notion of heuristic search several times in this course.


Once place where we discussed this in some detail, was in incremental concept learning. Given a current concept
definition and a negative example, we arrive at a new concept definition by using heuristics like require-link
heuristic.


The require-link heuristic adds the must clause to this support link between these two bricks. Mean-sense analysis was a
heuristic method. It said that given the current position and the goal position, find the differences and then select an
operator that will reduce the difference. Because mean-sense analysis was a heuristic method sometimes it ran into
problems and did not follow guarantees of optimality. But when it worked, it was very efficient. Another case where we
explicitly made use of heuristic laws in the generate interest method. Here we had a heuristic which said, do not
generate a state that duplicates a previously generated state which made the method more efficient. Does the focus of
knowledge based


AI agents is a near real time performance? They're addressing computational intractable problems with bounded resources.
And yet being able to solve a very large class of problems in robust intelligence and flexible intelligence. And that
happens not by finding optimal solutions to a narrow class of problems, but by using heuristics to find solutions that
are good enough to very large classes of problems. This principle comes very much from theories of human cognition.


As I mentioned earlier, humans do not normally find optimal solutions for every problem they face. However, we do manage
to find solutions that are good enough, and we do so in near real time, and that's where the power lies


09 - The Sixth Principle
------------------------

Our sixth principle, was knowledge-based AI agents make use of recurring patterns in the problems that they solve.


These agents are likely to see similar problems over and over again and make use of the underlying patterns behind these
similar problems to solve them more easily. We talked about this first with learning about recording cases.


Here we assumed that we had a library of cases, and that the solution to a former case would be the exact solution to a
new problem.


Ashok's example of tying shoe laces was similar to this.


When we tie our shoelaces, we aren't resolving the problem of tying our shoelaces from scratch. Instead we're just
taking the solution from an earlier time when we tied our shoelaces and doing it again. We assumed that the solution to
the old problem will solve this new similar problem. In case-based reasoning, however, we talked about how the exact
solution to an old problem won't always solve new problems. Instead sometimes we have to adapt an old problem.


Here we assumed that there were recurring patterns in the world that would help us solve these new and novel problems
based on previous experiences.


Even though the new experience is novel, the pattern is similar to a prior experience. Analogical reasoning is very
deeply rooted in this principle.


Here we explicitly talked about the idea of taking patterns from one problem, abstracting them, and transferring them to
a problem in a different domain.


Whereas in case-based reasoning, the pattern was within a domain, here the pattern can span different domains.


In configuration, we assumed that the underlying design, the underlying plan for a certain device or product was pretty
similar each time. But there were certain variables that had to be defined for an individual instance of that object.


In a chair example, the overall design of a chair is a recurring problem, they all have legs, they all have seats, they
all have backs, but the individual details of a specific chair might differ. Now, it might be tempting to think that
this is actually at odds with the previous principal when the knowledge-based AI agent's consult a novel problems. Here
we're saying that knowledge-based AI agents solve recurring problems based on recurring patterns, but in fact these are
not mutually exclusive. Knowledge-based AI agents leverage recurring patterns in the world, but they do so in
conjunction with the other reasoning methods to allow them to also address novel problems.


10 - The Seventh Principle
--------------------------

So the seventh and last principle of knowledge based AI agents in CS7637 is that the architecture of knowledge based AI
agents enables reasoning, learning, and memory to support and constrain each other. Instead of building a theory of
reasoning or problem solving by itself or a theory of learning by itself or a theory of memory by itself, we are trying
to build unified theories, theories where reasoning, learning, and memory coexist. Memory stores and organizes
knowledge. Learning acquires knowledge. Reasoning uses knowledge.


Knowledge is the glue between these three. One place that we saw reasoning, learning, and memory coming together very
well was in production systems.


When reasoning failed, an impasse was reached then. Memory provided some episodic knowledge and a learning mechanism of
chunking extracted a rule from that episodic knowledge. And that rule broke the impulse and reasoning could proceed a
pace. This is a clear example where reasoning, learning, and memory came together in a unified architecture. In logic,
memory, or the knowledge base, may begin with a set of axioms.


And those set of axioms decide what we can prove using that particular logic.


To look at the problem, conversely, depending upon the reasoning, we need to put into the knowledge base, so that the
reasoning can be supported.


Exploration of this learning was under the place. Where reasoning learning and memory came together so well. Memory
supplied us with the earlier precedents.


Reasoning led to the composition of this explanation which explained why this instance was an example of a cup. This
lead to learning about the connections between this weirdest precedence to an explanation.


Here in the correcting mistakes was yet another example of, learning, reasoning, and memory coming together. Where a
failure occurred, when the agent used it's previous knowledge, memory, to reason and identify the fault responsible for
the failure, reasoning, and then corrected that particular fault, learning, in order to get the correct model. This
knowledge based paradigm says that we want to be able to reach unified, that connect reasoning, learning and memory. And
this also connects very well with human cognition, human cognition, of course, has reasoning and learning and memory
intertwined together. It is not as if memory and human cognition works by itself or learning works by itself or
reasoning works by itself. You cannot divorce them from each other.


11 - Current Research
---------------------

Knowledge based is a dominate field with a very active research program. There are number of exiting projects going on
right now. Here is a small list of them.


CALO is a project, in which cognitive assistant learns and organizes knowledge.


CALO, in fact was a pick cursor for the CD program of Apple. Cyc and OMCS.


OMCS stands for Open Mind Common Sense. Cyc and OMCS are two large knowledge bases to support everyday common sense of
reasoning. Wolfram Alpha is a new kind of search engine that uses some of the same kind of pilot structures we have
considered in this particular class, different from many of the search engines.


The three projects in the right column are projects here at Georgia Tech. VITA is a computational model of visual
thinking in autism. And particular it solves problems in the real world raven's progressive matrices test using only
visual spacial representations. Dramatis is a computational model suspense in drama and stories. Recall that in this
class we talked about the theory of humor and surprise. Dramatis tries to do the same thing for suspense. DANE is a
system for supporting design based on analogies to natural systems. We've come across this idea of biologically inspired
design earlier in the class and DANE supports that kind of biologically inspired design. We have provided references for
these and many other knowledge based AI projects in the class notes.


Your welcome to explore depending on your inquests.


12 - Our Reflections
--------------------

>> We'd also like to thank our colleagues here at Georgia Tech, including David White at the College of Computing. And
Mark Weston, and the staff of the Georgia Tech Professional Education Department.


It's been a real fun journey for us. We expect to hear from you.


We hope it's the beginning of a beautiful friendship.


