.. title: 06 - Production Systems 
.. slug: 06 - Production Systems 
.. date: 2016-01-30 10:01:45 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

=======================
06 - Production Systems
=======================


01 - Preview
------------

Today, we'll talk about production systems. I think you're going to enjoy this, because part of production systems is
going to do with learning.


And this is the first time in the course we'll be talking about learning.


Production systems are kind of cognitive architecture, in which knowledge is represented in the form of rules. This is
the last topic under the fundamental topics part of the course. We'll start by talking about cognitive architectures in
general, then focus on production systems, then come to learning, a particular mechanism of learning called chunking.


02 - Exercise A Pitcher
-----------------------

To illustrate production systems, let us imagine that you are a baseball pitcher. This illustration is coming from a
game between Atlanta Braves and the Arizona Diamondbacks. Here is a pitcher on the mound, and a pitcher has to decide,
whether to pitch a ball to the batter, or whether to walk the batter.


To be more specific, take a look at the story here in the left. Read it.


And to decide what would the pitcher do. What would you do?


What would an intelligent agent do? If you don't know much about baseball, don't worry about it. Part of the goal here
is to see what someone who does not know about, a lot about baseball may do.


03 - Exercise A Pitcher
-----------------------

>> David, it's clear that you know more about baseball than I do. So


I assume that your answer is the right one. But notice what is happening here.


David has a lot of knowledge about baseball, and he's using that knowledge to make a decision. How is he using his
knowledge to make a decision?


What is the architecture? What is the reasoning that leads him to make that specific decision? This is one of the things
we'll learn in this lesson.


How might intelligent agents make complex decisions about the world?


04 - Function of a Cognitive Architecture
-----------------------------------------

Before we talk about cognitive architectures in more detail, first let us characterize what is a cognitive agent.


Now, there are many views of what a cognitive agent is. Here is one characterization of cognitive agent which is very
popular in modern AI.


A cognitive agent is a function that maps a perceptual history into an action.


So it's B asterisk map into A where the asterisk on P stands for the history percepts. So this characterization says
that one of the major tasks of cognitive agents is to select actions. You're driving a car. What action should you take
next? You're having lunch, what action should you do next?


You're conversing with someone, someone else, what action should you do next?


All the time we are taking actions, we as humans. And the question is, what should we do next? We base that action in
part on the history of percepts in that particular situation. So this characterization captures the basic notion of
cognitive agent in a very concise manner.


05 - Levels of Cognitive Architectures
--------------------------------------

We can build queries of knowledge based AI at many levels of instructions.


This is the scale here, low level to high level. At one level, we can build queries at hardware level. So we can talk
about a brain or transistor sort of microchip. At the next level, we can talk about the kinds of methods and the kinds
of representations we have been talking about, means-ends analysis that has an algorithm associated with it, or semantic
network that's a knowledge representation in some symbolic form.


At a yet higher level, we can talk about knowledge and tasks. So, the question here becomes what exactly is the task the
decision maker has to make? What exactly is the knowledge the decision maker has?


So, when David was giving his answer about what the pitcher might do in the situation I showed you earlier, David was
clearly using a lot of knowledge, and he was trying to use this knowledge toward to a particular task. Now, in the
history of AI, David Mark talked about three levels, the level of tasks, which he called the [UNKNOWN] theory, the level
of algorithms and the level of implementation. And [INAUDIBLE] talked also about multiple levels.


He was talking about the knowledge level, the symbol level and lower levels like the hardware. The various levels are
connected with each other. So I might think that, the hardware level is a level for implementing what is happening at
the algorithm level. And the algorithm level provides and architecture for implementing what is happening at the task
level. In the opposite direction,


I might think that the task level provides the content of what needs to be represented or manipulated at the algorithm
level. And the algorithm and symbol level provide the content for what needs to be manipulated at processor, the
hardware level. So as an example, one might say, we're representing this in a form of a semantic network, fair enough.
But, what exactly are you going to represent in a semantic network? That's going to come from the knowledge level.


It is the knowledge level that tells us, what is the content of the knowledge that is required to play baseball? Once
you have the content of knowledge, you can perhaps implement it in many different ways. One way is through semantic
network. Similarly, once you know what kind of decision you have to make, and what a decision-making process might look
like overall, there might be many different methods of making that particular decision. Just like we can build a
relationship between the task level and the algorithm level, a similar relationship exists between the algorithm level
and the hardware level. This is an important point, so let me take another example.


All of you are familiar with your standard smartphone. Let us suppose that I was coming from Mars, I was a Martian. And
I did not know how your mobile phone works. So I would ask you, well, how, exactly, does your mobile phone work? And you
might give an account of how the phone works at that level of distraction.


There will be a legitimate account, you have somewhere else for give an account of how the smartphone works at a, at a
level of tasks and knowledge. This person might say, well, a phone allows you to communicate with other people at long
distances. How that is implemented is a different matter.


Now you will see, I'm sure, that all three of these interpretations, all three of these descriptions are legitimate and
valid.


You will see also, that we really need all three of these levels of description.


We do need to understand what this smartphone does, and that kind of knowledge it uses to do it. We do need to
understand what kind of algorithm and knowledge presentations it uses, and what kind of hardware implements all of this.
Now, you can do a similar kind of analysis for other kinds of devices.


Let's say, like your calculator. Could we do a similar kind of analysis for intelligent agents? Are these different
layers also meaningful for analyzing what happens in cognitive systems, whether they are natural or artificial? And at
what layer should we be building a theory?


Our hypothesis is, that these three layers are also useful for trying to analyze how cognitive systems might work, but
natural cognitive systems and artificial cognitive systems. Further, our hypothesis is that we want to build theories at
all three of these different level, levels of abstraction, not at any one of them. In fact, their constraint's flowing
in both directions.


If we know about what kind of tasks we want to do and what kind of knowledge we want to use, then that tells us
something about what kind of algorithms we need to and what kind of knowledge representations we need.


And that tells us something about what kind of hardware we need. In the other direction, if we know what kind of
hardware we have that imposes constraints and provide [UNKNOWN] for what kind algorithms and knowledge representations
can be there, which then provides accordance within constraints. Well, what kinds of tasks can be done and what kind of
knowledge can be used.


In this class, we'll be concerned mostly with the top two layers, although I allude occasionally to the third layer as
well.


A lot of work in AI is at the top two layers of abstraction.


06 - Exercise Levels of Architectures
-------------------------------------

Now we have talked about Watson as a possible example for cognitive system earlier. And now we have talked about various
layers of abstraction at which we can analyze a cognitive system. So what do you think are the layers of analysis of
Watson?


07 - Exercise Levels of Architectures
-------------------------------------

>> That was a good answer, David. So, again, the three layers. And note that in the task layer here, answering the
inputted clue,.


Knowledge is also a part of it. Knowledge that Watson must have in order to answer that particular question. How that
knowledge is implemented.


What kind of presentations it uses, goes in the second layer.


08 - Assumptions of Cognitive Architectures
-------------------------------------------

The school of AI that works on cognitive architectures makes sort of fundamental assumptions about the nature of
cognitive agents.


First, that cognitive agents are goal oriented, or goal directed.


They have goals and they take actions in the pursuit of those goals.


Second, that these cognitive agents live in a rich, complex, dynamic environments. Third, this cognitive agent used
knowledge of the world in order to pursue their goals in this rich complex dynamic environments. Fourth, that this
knowledge is particular abstraction that captures the important things about the world that the level of abstraction and
removes all the details. And at that level of abstraction, knowledge is captured in the form of symbols.


Fifth, the cognitive agents are very flexible.


The behavior is dependent upon the environment. As environment changes, so does the behavior. And sixth cognitive agents
learn from their experiences.


They're constantly learning as they interact with the world.


09 - Architecture  Content  Behavior
------------------------------------

We can capture the basic intuition behind work on cognitive architectures by a simple equation, architecture plus
content equals behavior.


Let us look at this equation from two different perspectives.


First, imagine that you want to design an intelligent machine that exhibits a particular kind of behavior. This equation
says that, in order to do that, you have to design the right architecture, and then put the right kind of knowledge
content into that architecture, to get the behavior that you want from it. That's a complicated thing.


But suppose that I could fix the architecture for you. In that case, if the architecture is fixed, I simply have to
change the knowledge content to get different behaviors, which is a really powerful idea. From a different direction,
suppose that we were trying to understand human behavior.


Now we could say, again, that the architecture is fixed, we could say that, this behavior is arising because the
knowledge content is different.


We can map now, behavior to content because the architecture is fixed.


That simplifies our understanding of how to design machines or how to understand human cognition. By the way, the same
thing happens in computer architecture.


I'm sure you have, are familiar with computer architecture.


Computer architecture has stored programs in it, that's the content, and that running of the stored program gives you
different behaviors.


The computer architecture doesn't change, the stored program keeps on changing, to give you different kind of behaviors.
Same idea with cognitive architectures.


Keep the architecture constant, change the content. Now, of course, the big question will become, what is a good
architecture? And that's what we'll examine later.


10 - A Cognitive Architecture for Production Systems
----------------------------------------------------

So we have come across this high level architecture for deliberation earlier.


Today we will talk about a specific cognitive architecture for deliberation.


This architecture is called SOAR. I should mention that SOAR not only covers deliberation, SOAR can also cover certain
aspects of reaction, and some aspects of meta cognition. But we are going to focus mostly on the deliberation component
and so on. SOAR was initiated by Allen Neville, John Lear, and


Paul Rosenbloom. And John Lear and Paul Rosenbloom have been working on it for the last 30 years or so. The highest
level consists of a long term memory and a working memory. The [INAUDIBLE] itself contains different kinds of knowledge.


In particular SOAR talks about three kinds of knowledge. Procedural, semantic, and episodic. Episodic knowledge has to
do with events.


Specific instances of events, like, what did you have for dinner yesterday.


Semantic knowledge has to do with generalizations in the form of concepts and models of the world. For example, your
concept of a human being, or your model of how a plane flies in the air.


Procedural has to do with how to do certain things. So as an example, how do you pour water from a jug into a tumbler.
Notice that this makes an architecture.


There are different components that are interacting with each other.


This arrangement of components will afford certain processes of reasoning and learning. That's exactly the kind of
processes of reasoning and learning that we'll look at next.


11 - Return to the Pitcher
--------------------------

Let us now go back to example of the baseball pitcher who has to decide on a action to take in a particular
circumstance. So we can think of this pitcher as mapping a percept history into an action.


Now imagine that this pitcher is embodying a production system. We are back to a very specific situation, and you can
certainly read it again. Recall that


David had given the answer, the pitcher will intentionally walk the batter. So we want to make the theory of how might
the pitcher or internal and


AI agent come to this decision. Recall the very specific situation that the pitcher is facing. And recall also that
David had come up with this answer.


So, here is a set of percepts, and here is an action. And the question is, how these percepts get mapped into this
action? We are going to add one build a theory of how the human pitcher might be making these decisions, as well as a
theory of how an AI agent could be built to make this decision.


So let's go back to the example of the pitcher having to decide on a action in a particular situation in the world. So
the pitcher has several kinds of knowledge. Some of its knowledge is internal. It already has it. Some of it, it can
perceive from the world around it. As an example, the pitcher can perceive the various objects here, such as the bases,
first, second, third base.


The pitcher can perceive the batter here. The pitcher can perceive the current state of the game. The specific score in
the inning, the specific batter.


The pitcher can perceive the positions of its own teammates. So, all these things the pitcher can perceive, and these
then are become exact specific kinds of knowledge that each pitcher has. The pitcher also has internal knowledge.


The pitcher has knowledge about his goals and objectives here.


12 - Action Selection
---------------------

So imagine that Kris Medlen from Atlanta Braves is the pitcher.


And Martin Prado from Arizona Diamondbacks is at the bat.


Kris Medlen has the goal of finishing the inning without allowing any runs.


How does Kris Medlen decide on an action? We may conceptualize Medlen's decision making like the following. Medlen may
look at various choices that are available to him. He may throw a pitch. Or he may choose to walk the batter.


If he walks the batter, then there are additional possibilities that open up.


He'll need to face the next batter. If he chooses to pitch, then he'll have to decide what kind of ball to throw. A
slider, a fast ball, or a curve ball.


If it was a slider, then there is a next set of possibilities open up.


There might be a strike or a ball or a hit or he may just strike the batter out.


Thus, Medlen is setting up a state space. Now, what we just did informally can be stated formally. So, we can imagine a
number of states in the states space.


The state space is a combination of all the states that can be achieved by applying various combinations of operators,
starting from the initial state.


Each state can be described in terms of some features, f1, f2, there could be more. Each feature can take on some
values. For example, v1, there might be a range of values here. So initially, the picture is at state s0.


And the pitcher wants to assume some state S101. And at a state S101 presumably the pitcher the pitcher's goal has been
accomplished. So we may think as the pitcher's decision making as some kind of a part of its current state to this
particular goal state. This is an abstract space. The pitcher has not yet made any action. The picture is still
thinking. The picture is sitting up an abstract state space in his mind and exploding that state space.


13 - Putting Content in the Architecture
----------------------------------------

Okay, now in order to go further, let us start thinking in terms of, how we can put all of these precepts and goal, into
some feature value language, so that we can store it inside Sole. It is one attempt at capturing all of this knowledge,
so I can say that it's the 7th inning. Inning is 7th.


It's the top of the 7th inning. It's the top here. Runners are on 2nd and


3rd base. 2nd and 3rd base. And then so on and so forth. Note that at the bottom I have goal is to escape the inning.


Which I think means in this particular context, to go to the next inning, without letting the batter score anymore
points. So now that we have. Put all of this precepts coming from the world and the goal, into some kind of simple
representation which has features and values in it, the fun is going to begin.


14 - Bringing in Memory
-----------------------

So, source working memory not contains all the things that we had in the previous shot. Some of these are percepts. Some
the things are the pitcher's internal goals. Let us see how the contents of the working memory, now invoke different
kinds of knowledge from the long term memory.


So, let us imagine that the procedural part of source long term memory contains the following rules. The procedural
knowledge and source long term memory is represented in the form of rules.


The system sometimes called production group. In fact, the term production systems comes from the term production group.
So, each rule here is a production group. I've shown seven here, there could be more rules.


Once again, these production rules are captured in the procedural knowledge, and soource long-term memory. Recall that
one of the first things that the pitcher had to decide was whether the pitcher should throw a pitch or walk the batter.


Therefore, we assume that there are some rules which allow the pitcher to make a decision between these two choices.
Thus there is a rule here. If the goal is to escape, and I perceive two outs, and I perceive on the second, and


I perceive a runner on the second and I perceive no runner on the first base, then I'm suggest a goal of intentionally
walk batter. There is another rule.


The second rule says, if the goal is to escape, and I perceive two outs and


I perceive a runner on the first base. Or if perceived not out on the second, or if perceived no runners, then suggest
the goal to get the batter out via pitching. And what might happen if I pick the goal of intentionally walking the
batter? The goal is to intentionally walk the batter then suggest intentional walk operator. Now, this intentional walk
operator corresponds to some action available to all. And similarly, the other rules. Let's consider one other rule,
rule number seven.


If only one operator has been selected, then send the operator to the motor system and add the pitch thrown to the
state. So, there is both now an action has been selected, and the action is going to be executed.


As well as the state of the working memory is going to be changed, so it will say that now the pitch has been thrown.
Before we go ahead, let me summarize what we just learned. Source long term memory consists of various kinds of
knowledge. One kind of knowledge, the one that we are considering right now is procedural knowledge. Procedural
knowledge is about how to do something.


And so procedural knowledge is represented in the form of production rules.


Each production rule is, is of the form, if something then something.


There are antecedents and their consequence. These antecedents may be connected through various kind of relationships,
like and, and or. The consequence too might be connected through various kind of relationships like and, and or. So I
may have if some antecedent is true, and some other, other ante, antecedent is true, and so on, then do some consequent.
Now that we understand a little bit about the representation of production rules. What about the content? What should be
the content that we put into these production rules?


Earlier we had said that cognitive architectures are goal oriented. So we'll expect goals to appear in some of the
production rules. Indeed, they do.


R1, r2, r3, and so on. Earlier we had said that knowledge based


AI cognitive systems, use a lot of knowledge. And you can see how detailed and specific this knowledge is. In fact, the
knowledge is so detailed and specific that in principle we can hope that as different percepts come from the world, some
rule is available that will be useful for that set of percepts.


15 - Exercise Production System in Action I
-------------------------------------------

Okay, given these productions in the procedural part of sol's long term memory.


And given these are the contents of the working memory which capture the current set of percepts and the current goal.
What operator do you think sol will select? Note that one of the choices here is none, the system cannot decide.


16 - Exercise Production System in Action I
-------------------------------------------

>> That was right, David. So note what happened.


There were the contents of the working memory. Here were all the rules of a level in the procedural part of the long-
term memory. And so then, match the contents of the working memory with the antecedents of the various productions.
Depending on the match between the contents of the working memory, and the antecedents of the rules, some rules got
activated, fired as some people say. Depending upon what rule got fired, that resulted in, perhaps, firing of additional
rules. So as David said, if the rule number one got activated because the goal became intentionally walk the batter,
that then lead to the activation of rule number three, which was to select the intentional-walk operator. In this way,
given the set of contents of the working memory and a mapping between those contents and the antecedents of the various
production rules that capture the procedure knowledge. Some rules get activated, and this activation continues until
sort cannot activate any additional rules.


At that point, sort has given an answer, based on the consequence of a rule that matches a motor action. Note that sort
just provided an account of how the picture decided on a specific page, on a specific action.


Note that, we're started with the goal of providing an account of how the pitcher selects on an action or how an AI
agent selects on an action.


So what is the account? Based on the goal and the percents, match them with the antecedence of the rules that captured
the procedural knowledge.


And then, accept the consequent of some production that matches some motor action from some precepts we have gone to
some action.


17 - Exercise Production System in Action II
--------------------------------------------

Now let us consider another situation. Suppose that our pitcher actually was able to walk the batter. So, now, there are
runners on the first, second, ands third bases. Not just on the second and third bases, but one on the first, also. So
the picture succeeded in accomplishing it's goal in the last shot.


So the current situation then is discard, but this side of percept and this goal. The confidence of the working memory
have just changed. Of course, the production rules capturing the pursuit of knowledge have not yet changed. So these are
exactly the same productions that we had previously.


Only the contents of the working memory has changed.


We now have a runner at the first as well as the second and the third. And this exercise is very intrusting because it
will lead us to a different set of conclusions. Given the set of precepts in this goal and the set of production rules,
what operator do you think the picture will select?


18 - Exercise Production System in Action II
--------------------------------------------

>> That was right, David. Thank you.


Let's summarize some of the things that David noted. So based on the contents of the working memory, some rules get
activated. As these rules get activated, some consequences get established. As these consequences get established, they
get written. These consequence get written on the working memory.


So the contents of working memory are constantly changing.


As the contents of the working memory change, new rules can get activated. So there is a constant interaction between
the working memory and the long term memory. The contents of the working memory change quite rapidly.


The contents of the long term memory change very, very slowly.


19 - Exercise System in Action III
----------------------------------

Aha, so this situation keeps becoming more complicated David.


Let's think about what might happen if the manager of the Arizona Diamondbacks anticipated what the Atlanta Braves
pitcher would do, and actually change the batter so the batter now is left handed?


If the batter is left handed, then the percept is slightly different.


The content of the pitcher's working memory is slightly different.


The production rules capturing the pursuit of knowledge are still the same. What do you think will happen now? What kind
of decision will the pitcher make now?


20 - Exercise System in Action III
----------------------------------

>> Good David. That was the correct answer. So note what has happened. So far, we had assumed that the match between the
precepts, and the production rules capture on the procedural knowledge was such that given the percept, we'll always
have one rule which will tell us what action to take.


It may take some time to get to this rule, some rules may need to be established and then only some other rules get
established, then only we get the action. But nevertheless, this system would work. The difficulty now is, there is no
rule, which tells us exactly what action to take.


21 - Chunking
-------------

So for this situation source cognitive architectures selected not one goal but to.


So this SOAR theory this is called an impasse.


An impasse occurs when the decision maker cannot make a decision either because not enough knowledge is available or
because multiple courses of action there are being selected and the agent cannot decide among them.


In this case two actions have been selected and the agent cannot decide between them.


Should the pitch throw a curve ball or a fast ball?


At this point SOAR will attempt to learn a rule that might break the impasse.


If the decision maker has a choice between the fast ball and the curve ball and it cannot decide it, might there be a
way of learning a rule that decides between what to throw in a particular situation given the choice of the fast falling
curve ball.


For this now SOAR will invoke episodic knowledge.


Let's see how SOAR does that and how it can help SOAR learn the rule that results in the breaking of the impasse.


So imagine that SOAR had episodic knowledge about the previous event, about the previous instance of an event.


And this previous instance of an event in another game it was a fifth inning bottom of the fifth inning, if the weather
was windy it was the same batter though, Parra, who bats left handed.


It was a similar kind of situation and the pitcher threw a fastball and


Parra hit a homerun out of it.


Now we want to avoid that.


The current pitcher wants to avoid it.


So given this episodic knowledge about this even set occurred earlier,


SOAR has learning mechanism that allows it to encapsulate knowledge from this event into the form of a production rule
that can be used as part of the procedural knowledge.


And the learned rule is, if two operators are suggested, and threw a fast ball is one of those operators, and the batter
is Parra, then dismiss throw-fast-ball operator.


This is the process of learning called chunking.


So, chunking is a process, a learning technique that's SOAR uses to learn rules that can break impasse.


First note, that chunking is triggered when impasse occurs.


In this situation, the impasse is that two rules got activated and there is no way of resolving between them.


So the impasse imagery tells the process of chunking, what the goal of chunking is.


Find a rule that can break the impasse.


SOAR now searches for the episodic memory and finds an event that has some knowledge that may break the impulse.


In particular, it looks like a perceptual current situation that we had in previous shot.


And compared to the perceptions of previous situations, of the event memory, the episodic memory, and find that any
information available of the current batter.


If some information is available that tells, SOAR the result of some previous action that also occurs in the current
impasse, then SOAR picks that event.


So now it tries to encapsulate the result of the previous event, in the form of a rule.


In this case, it wants to avoid the result of a homerun, and therefore it says dismiss that particular operator.


If it wanted that particular result, it would have said throw that particular operator.


We said earlier that in cognitive systems, reasoning, learning and memory are closely connected.


Here is an example of that.


We're dealing with memory, procedural memory, we're dealing with memory that can deal with procedural knowledge and
episodic knowledge.


Dealing with reasoning, decision making.


We're also dealing with learning, chunking.


If you want to learn more about chunking then the reading by


Lehman Leodon Rosenblum, and the further readings at the end of this lesson gives lot many more details.


22 - Exercise Chunking
----------------------

Let's do one more exercise on the same problem. Note that,


I have added one more rule into the procedural knowledge. This is the rule that was the result of chunking. If two
operators are suggested, and throw-fast-ball operator suggested, and the batter is Parra.


Then dismiss the throw-fast-ball operator. Okay, given these rules and the same situation, what do you think will be the
operator that will be selected?


23 - Exercise Chunking
----------------------

>> So it looks like the entire goal of that chunking process was to help us figure out between these two operators which
one we should actually select.


We decided that, if a fast ball is suggested, which it was, and if two operators are suggested, which they were, and the
batter is Parra, which it is, then to dismiss the throw-fast-ball operator. That means we only have one more operator
suggested, throw-curve-ball. So that would be selected.


24 - Fundamentals of Learning
-----------------------------

This is the first time we have come across the topic of learning in this course, so let us examine it a little bit more
closely.


We are all interested in asking the question, how do agents learn?


But this question is not isolated from a series of other questions.


What do agents learn? What is the source of their learning? When do they learn?


And why do they learn at all? For the purpose of addressing what goal or what task? Now here is the fundamental stance
that knowledge based AI takes. It says that we'll start with a theory of reasoning.


That will help us address questions like, what to learn, when to learn, why to do learning? And only then will we go to
the question, of how to do the learning. So, we reasoning first, and then backwards to learning. This happened in
production systems.


When the production system reach an impasse, then it said let's learn in order to resolve this impasse from episodic
knowledge. So once again, we are trying to build a unified theory of reasoning, memory, and learning where the demands
of memory and reasoning constrain the processing of learning.


25 - Assignment Production Systems
----------------------------------

So how would you use a production system to design an agent that can solve Raven's Progressive Matrices. We could think
about this kind of at two different levels. At one level we could imagine a production system that's able to address any
incoming problem. It has a set of rules for what to look for in a new problem and it knows how to reply when it finds
those things. But on the other hand, we can also imagine production rules that are specific to a given problem. When the
agent receives a new problem, it induces some production rules that govern the transformation between certain figures
and then transfers that to other rows and columns. So in that way, it's able to use that same kind of production system
methodology to answer these problems, even though it doesn't come into the problem with any production rules written in
advance. So, inherent in this idea though, is the idea of learning from the problem that it receives. How is this
learning going to take place? How is it actually going to write these production rules, based on a new problem? And
what's the benefit of doing it this way? What do we get out of actually having these production rules, that are written
based on individual problems?


26 - Wrap Up
------------

So let's wrap up our discussion for today and also wrap up the foundational unit of our course as a whole. We started
off today by revisiting this notion of Cognitive architectures that we talked about at the very beginning of the course.
We use that to contextual our discussion of


Production systems, specifically those implemented in a framework called SOAR.


As we saw, production systems enable action selection.


They help us map percepts in the world into actions. Of course, this is only one of the many things that a production
system can do.


It can really map any kind of antecedent into any kind of consequent. But in our example, we saw how the production
system for a pitcher can map percepts from a baseball game into pitch selection.


We then talked about impasses and how when a production system hits an impasse, it can use chunking to learn a new rule
to overcome that impasse.


This is the first time we've encountered learning in our course, but learning is actually going to be foundational to
everything we talk about from here on. This wraps up the fundamentals unit of our course.


Next time we're going to talk about frames, which we actually saw a little bit of today. Frames are going to become a
knowledge representation that we'll use throughout the rest of our course.


27 - The Cognitive Connection
-----------------------------

The connection between production systems and human cognition is both powerful and straightforward. In fact, production
systems, right from the beginning were proposed as models of human cognition. We can look at it from several
perspectives. First, the working memory in production system has a counterpart in human cognition in the form of short-
term memory. Short-term memory and human cognition, at least for the verbal part, has a capacity for approximately seven
plus or minus two elements. Working memory and production systems plays a similar role.


Second, people have connected studies which they have given the same problems, both to humans and to cognitive
architectures [INAUDIBLE]. These problems typically are from closed worlds like arithmetic or algebra. At a consult,
there are strong similarities between the behavior of programs like SOAR and the behavior of humans when they address
problems in arithmetic and algebra.


This, however, does not mean that we already have a very good complete model of human cognition. This is just the
beginning. Humans engage in a very large number of problems, not just arithmetic or algebra problems in closed worlds.


So there still remain a large number of questions open about how do you build a cognitive architecture that can capture
human cognition at large in the open?


28 - Final Quiz
---------------

So we are now at the final quiz for this particular lesson. What did you learn in this lesson?


29 - Final Quiz
---------------

And thank you for doing it.
