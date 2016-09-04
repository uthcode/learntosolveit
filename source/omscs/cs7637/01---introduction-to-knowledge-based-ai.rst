.. title: 01 - Introduction to Knowledge-Based AI 
.. slug: 01 - Introduction to Knowledge-Based AI 
.. date: 2016-01-23 06:32:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

========================================
01 - Introduction to Knowledge-Based AI
========================================

01 - Introductions
------------------

>> We have had a lot of fun putting this course together.


We hope you enjoy it as well. We think of this course as an experiment as well.


We want to understand how students learn in online classrooms. So if you have any feedback, please share it with us.


02 - Preview
------------

.. image:: https://dl.dropbox.com/s/vhhih7rip3md8yy/Screenshot%202016-02-07%2021.18.56.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/ae4yd94ylaaaopq/Screenshot%202016-02-07%2021.19.51.png
   :align: center
   :height: 300
   :width: 450

So welcome to 7637 Knowledge Based AI. At the beginning of each lesson, we'll briefly introduce a topic as shown in the
graphics to the right.


We'll also talk about how the topic fits into the overall curriculum for the course. Today, we'll be discussing AI in
general, including some of the fundamental conundrums and characteristics of AI.


We will describe four schools of AI, and discuss how knowledge based AI fits into the rest of AI. Next, we'll visit the
subtitle of the course,


Cognitive Systems, and define an architecture for them.


Finally, we'll look at the topics that we'll cover in this course in detail.


03 - Conundrums in AI
---------------------

.. image:: https://dl.dropbox.com/s/5t69k8xwqm1lymh/Screenshot%202016-02-07%2021.21.49.png
   :align: center
   :height: 300
   :width: 450



Let's start a recognition today. We're discussing some of the biggest problems in AI. We obviously are not going to
solve all of them today, but it's good to start with a big picture. AI has several conundrums,


I'm going to describe five of the main ones today. Conundrum number one.


All intelligent agents have little computational resources, processing speed, memory size, and so on. But most
interesting AI problems are computationally intractable. How then can we get AI agents to give us near real time
performance on many interesting problems? Conundrum number two.


All competition is local, but most AI problems have global constraints. How then can we get AI agents to address global
problems using only local computation?


Conundrum number three. Computation logic is fundamentally deductive, but many AI problems are abductive or inductive in
their nature.


How can we get AI agents to address abductive or inductive problems? If you do not understand some of these terms, like
abduction, don't worry about it, we'll discuss it later in the later in the class. Conundrum number four.


The world is dynamic, knowledge is limited, but an AI agent must always begin with what it already knows. How then can
an AI agent ever address a new problem?


Conundrum number five. Problem solving, reasoning, and learning are complex enough, but explanation and justification
add to the complexity.


How then can we get an AI agent to ever explain or justify it's decisions?


04 - Characteristics of AI Problems
-----------------------------------

.. image:: https://dl.dropbox.com/s/p3mbxd347haf34n/Screenshot%202016-02-07%2021.30.01.png
   :align: center
   :height: 300
   :width: 450

I hope our discussion of the big problems in AI didn't scare you off, let's bring the discussion down, closer to work.


And talk about [UNKNOWN] fundamental characteristics of AI problems. Number one, in many AI problems, data arrives
incrementally not all the data comes right at the beginning. Number two, problems often have a recurring pattern, the
same kinds of problems occur again and again. Number three, problems occur at many different levels of abstraction.
Problem number four, many interesting AI problems are computationally intractable. Number five, the world is dynamic,
it's constantly changing but knowledge of the world is relative to static. Number six, the world is open ended but
knowledge of the world is relatively limited. So, the question then becomes, how can we design air agents that can
address air problems with these characteristics, those are the challenges we'll discuss in this course


05 - Characteristics of AI Agents
---------------------------------

.. image:: https://dl.dropbox.com/s/y5kgwdfqflo67d1/Screenshot%202016-02-07%2021.31.25.png
   :align: center
   :height: 300
   :width: 450



In addition to AI problems having several characteristics,


AI agents too have several properties. Property number one. AI agents, have only a limited computing power, processing
speed, memory size, and so on. Property number two. AI agents have limited sensors, they cannot perceive everything in
the world. Property number three.


AI agents have limited attention, they cannot focus on everything at the same time. Property number four. Computational
logic is fundamentally deductive.


Property number five. The world is large, but AI agents' knowledge of the world is incomplete relative to the world. So,
the question then becomes, how can AI agents with such bounded rationality address open-ended problems in the world?


06 - Exercise What are AI Problems
----------------------------------

.. image:: https://dl.dropbox.com/s/sng3ear1hgrrmyh/Screenshot%202016-02-07%2021.37.09.png
   :align: center
   :height: 300
   :width: 450


Now that we have talked about the characteristics of AI, agents in AI problems.


Let us talk a little about for what kind of problems might you build in AI agent. On the right are several tasks. Which
are these AI problems? Or to put it differently, for which of these problems would you build an AI agent to solve?


07 - Exercise What are AI Problems
----------------------------------

>> I agree. In fact, during this class we'll design AI agents that can address each of these problems. For now, let us
just focus on the first one: how to design an AI agent that can answer Jeopardy questions?


08 - Exercise AI in Practice Watson
-----------------------------------

.. image::  https://dl.dropbox.com/s/qqrkvk9mrneakjx/Screenshot%202016-02-07%2021.39.46.png
   :align: center
   :height: 300
   :width: 450

>> What is event horizon?


09 - Exercise AI in Practice Watson
-----------------------------------

>> That's right. And during this course, we'll discuss each part of David's answer.


10 - What is Knowledge-Based AI
-------------------------------

.. image::  https://dl.dropbox.com/s/y76e93w3z1gsqzw/Screenshot%202016-02-07%2021.43.08.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/s3m4y25oe9dla54/Screenshot%202016-02-07%2021.43.43.png
   :align: center
   :height: 300
   :width: 450

Let us look at the processes that Watson may be using a little bit more closely.


Clearly Watson is doing a large number of things. It is trying to understand natural language sentences. It is trying to
generate some natural language sentences. It is making some decisions. I'll group all of these things broadly under
reasoning. Reasoning is a fundamental process of knowledge based data.


A second fundamental process of knowledge based AIs learning.


What simply is learning also? It perhaps gets a right answer to some questions, and stores that answer somewhere. If it
gets a wrong answer, and then once it learns about the right answer, it stores the right answer also somewhere.


Learning to is a fundamental process of knowledge based AI.


A third fundamental process of knowledge based ai is memory. If you're going to learn something, that knowledge that
you're learning has to be store somewhere, in memory. If you're going to reason using knowledge, then that knowledge has
to accessed from somewhere, from memory. From memory process it will store, what we learn as well as provide access to
knowledge it will need for reasoning. These three forms of processes of learning, memory, and reasoning are intimately
connected. We learn, so that we can reason.


The result of reasoning often. Result in additional learning.


Once we learn, we can store it in memory. However, we need knowledge to learn.


The more we know, the more we can learn. Reasoning requires knowledge that memory can provide access to. The results of
reasoning can also go into memory.


So, here are three processes that are closely related.


A key aspect of this course on knowledge based AI is that we will be talking about theories of knowledge based AI that
unify reasoning, learning, and memory. And sort of, discussing any one of the three separately as sometimes happens in
some schools of AI. We're going to try to build, unify the concept.


These 3 processes put together, I will call them deliberation. This deliberation process is 1 part of the overall
architecture of a knowledge based AI agent.


This figure illustrates the older architecture of an AI agent.


Here we have input in the form of perceptions of the world. And output in the form of actions in the world. The agent
may have large number of processes that map these perceptions to actions. We are going to focus right now on
deliberation, but the agent architecture also includes metacognition and reaction, that we'll discuss later


11 - Foundations The Four Schools of AI
---------------------------------------

.. image:: https://dl.dropbox.com/s/qgo9ty6wnbig4bi/Screenshot%202016-02-07%2021.53.05.png
   :align: center
   :height: 300
   :width: 450


.. image::  https://dl.dropbox.com/s/x3vhqf23th4q5id/Screenshot%202016-02-07%2021.58.10.png
   :align: center
   :height: 300
   :width: 450




Another way of understanding[br]what is knowledge based AI, is to contrast it with the other[br]schools of thought in
AI.


We can think in terms of a spectrum.


On one end of the spectrum, is acting.


The other end of[br]the spectrum is thinking.


As an example, when you're driving[br]a car, you're acting on the world.


But when you are planning what route to[br]take, you're thinking about the world.


There is a second dimension for distinguishing between different[br]schools of thought of AI.


At one end of the spectrum we can[br]think of AI agents that are optimal.


At the other end of the spectrum,[br]we can think of air agents that act and think like humans.


Humans are multifunctional,[br]they have very robust intelligence.


That intelligence need not be optimal[br]relative to any one task, but it's very general purpose, it works for[br]a very
large number of tasks.


Were as we can pick up here, agents on[br]the other side which are optimal for a given task.


Given these 2 axis we get 4 quadrants.


Starting from the top left and going[br]counter clockwise, here are Agents that think optimally, Agents that
act[br]optimally, Agents that act like humans.


And agents that think like humans.


In this particular course[br]in knowledged based AI, we're interested in agents[br]that think like humans.


Let us take a few examples[br]to make sure that we understand this four quadrants world.


Here are some well known[br]computational techniques.


Consider many machine[br]learning algorithms.


These algorithms analyse[br]large amounts of data, and determine patterns of[br]the regularity of that data.


Well I might think of them as[br]being in the top left quadrant.


This is really doing thinking,[br]and they often are optimal, but they're not necessarily human like.


Airplane autopilots.


They would go under acting optimally.


They're suddenly acting in the world,[br]and you want them to act optimally.


Improvisational robots that can perhaps[br]dance to the music that you play, they're acting, and they are
behaving[br]like humans, dancing to some music.


Semantic web, a new generation[br]of web technologies in which the web understands the various pages,[br]and information
on it.


I might put that under[br]thinking like humans.


They are thinking.


Not acting in the world.


And is much more like humans,[br]than, let's say, some of the other[br]computational techniques here.


>> If you're interested in reading[br]some more about these projects, you can check out the course materials.


Where we've provided some recent papers[br]on these different computational techniques.


There's a lot of cutting edge research[br]going on here at Georgia Tech and elsewhere, on these[br]different
technologies.


And if,[br]if you really are interested in this, this is something where we're[br]always looking for contributors.


12 - Exercise What is KBAI
--------------------------

.. image:: https://dl.dropbox.com/s/2qa2x4hpc8pucj1/Screenshot%202016-02-07%2023.01.19.png
   :align: center
   :height: 300
   :width: 450



>> What do you think? Do you agree with David? [BLANK_AUDIO]


13 - Exercise What is KBAI
--------------------------

>> So the autonomous vehicle may really belong to the acting rationally side of the spectrum. At the same time, looking
at the way humans write might help us design a robot. And looking at the robot design might help us reflect on human
cognition. This is one of the patterns of knowledge-based data.


14 - Exercise The Four Schools of AI
------------------------------------

.. image:: https://dl.dropbox.com/s/uogyb9xufa848xi/Screenshot%202016-02-07%2023.02.26.png
   :align: center
   :height: 300
   :width: 450



Let us do an exercise together. Once again, we have the four quadrants shown here, and at the top left are four
compression artifacts. I'm sure you're familiar with all four of them. C-3PO is a fictitious artifact from Star Wars.


Can we put these four artifacts in the quadrants to which they best belong?


15 - Exercise The Four Schools of AI
------------------------------------

.. image:: https://dl.dropbox.com/s/yntb257lsitesid/Screenshot%202016-02-07%2023.03.10.png
   :align: center
   :height: 300
   :width: 450



>> So if you'd like to discuss where these technologies belong on these spectrums or, perhaps, discuss where some other
AI technologies that you're familiar with belong on these spectrums, feel free to head on over to our forums where you
can bring up your own technologies and discuss the different. Ways in which they fit into the broader school of AI.


16 - What are Cognitive Systems
-------------------------------

.. image:: https://dl.dropbox.com/s/pc5bqrewo60jm2p/Screenshot%202016-02-07%2023.05.06.png
   :align: center
   :height: 300
   :width: 450



I'm sure you have noticed that this class has a subtitle, cognitive systems.


Let's talk about this term and break it down into its components. Cognitive, in this context, means dealing with human-
like intelligence. The ultimate goal is to dwell up human level, human-like intelligence. Systems, in this context,
means having multiple interacting components, such as learning, reasoning and memory. Cognitive systems, they are
systems that exhibit human level, human-like intelligence through interaction among components like learning, reasoning
and memory. Thus, on a spectrum, what we'll discuss in this class will definitely lie on the right side of the spectrum,
on the human side.


We will be talking about thinking and acting, but we will always be concerned with human cognition.


17 - Cognitive System Architecture
----------------------------------

.. image:: https://dl.dropbox.com/s/pge50gf6ccyynfj/Screenshot%202016-02-07%2023.07.03.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/sz677lh1diuwz0e/Screenshot%202016-02-07%2023.08.06.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/afrs6jiqbd35zki/Screenshot%202016-02-07%2023.09.04.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/0wlayzlvd3d5o5i/Screenshot%202016-02-07%2023.10.07.png
   :align: center
   :height: 300
   :width: 450





So let us take a look at what is a cognitive system.


Notice that I'm using the term cognitive system and not the term knowledge-based AI agent. I could have used that term
also.


When we talk about knowledge-based AI agent, then we could take two views.


One view is that we are going to build a knowledge-based AI system, which need not be human like. Another view is that
the knowledge based AI agent that we will build will be human-like. The cognitive system is situated in the world.


Here by the world I mean the physical world. For example, the world that I am interacting with right now, with this
screen in front of me and this microphone. This world is perceptionate. There's an example, the percept something being
a straight line or a color of some object. Or the smoothness of some of the texture of some object. This perceptionate
around the world and cognitive system is using sensors to perceive this percept. That's the input of the cognitive
system. The cognitive system also has some actuators. So, for example, I have fingers that I'm using right now to point
to things. And a cognitive system uses actuators to carry out actions on the world.


Cognitive system then is taking perceptor's input and giving actions as output.


So far, we've talked about a single cognitive system. But of course one can have multiple cognitive systems. These
multiple cognitive systems can interact with each other. Just like a cognitive system situated in a physical world, it
is also situated in a social world. Let us now zoom into the inside of a cognitive system. What is the architecture of a
cognitive system?


So the cognitive system takes as input certain percepts about the world. It has a task of giving as output actions of
the world. The question then becomes, how can these percepts be mapped into actions? One way of mapping them is that we
will do a direct mapping. These percepts will be directly mapped into actions.


Let's take an example. Imagine that you're driving a car, and the brake lights of the car in front of you, become bright
red. Should that happen, you will then press on the brakes of your car. Well, that is an example of a reactive system.


The percepts were that the break lights on the car in front of you became bright red and the action was that you pressed
on your own brakes. In doing so, you may not have planned. This is now a direct mapping of percept into actions.


Alternatively, consider a slightly different problem.


Again you're driving you're car on the highway, but as you're trying to drive on the highway your task this time is to
change lanes.


Now, in order to change lanes, again you may look around and look at the percept of the road. There are other cars on
the road, for example, and you need to take some action that will help you change lanes.


This time you may actually deliberate, you may actually look at the goal that you have as well as the percepts of the
environment and come up with a plan that will tell you what action to take. As we discussed in the last lesson, the
deliberation itself has a number of components in it.


Three of the major components that we'll studying in this class are learning, reasoning, and memory. These three
components interact with each other in many interesting ways that we will decipher as we go along.


Now, deliberation was reasoning about the world around us. So if I take that example again of changing lanes, as I'm
driving on the highway, then I'm reasoning about the world around me. Where are the other cars? Should I change lanes to
the left or to the right. Metacognition on the other hand, the third layer here, has to do with reasoning about the
internal mental world.


So metacognition reasons about the deliberation. Or metacognition can also reason about reaction. Let us take an example
of the metacognition also.


Image again that I had to change lanes. And I did, as I changed lanes to the left, the cars behind me honk because I did
not leave enough space for the car that was already moving on the left lane.


In that case I know that the lane changing did not go very smoothly.


I may now think about my own actions in the world, about the deliberation that led to those actions, and I may then
decide to change or reconfigure, or repair the deliberation that led to that sub-optimal plan for changing the lanes.
That is an example of metacognition. So now I have this three layered architecture, reaction, deliberation,
metacognition.


Note that we have defined intelligence in a way, intelligence here is about mapping percepts in the world, interactions
in the world. Intelligence is about selecting the right kind of action given a particular state of the world.


But there are many different ways in which we can map the percepts into actions.


Purely reactive, deliberative, or also entailing metacognition on the deliberation and the reaction. This then is the
overall architecture of the cognitive system. This is called a three layered architecture. We'll be returning to this
architecture many times in this course.


18 - Topics in KBAI
-------------------

.. image:: https://dl.dropbox.com/s/9z8lynhypyr16rt/Screenshot%202016-02-07%2023.12.37.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/nhsg5srrv1z3nja/Screenshot%202016-02-07%2023.13.25.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/99x7f8de6ch9ux9/Screenshot%202016-02-07%2023.14.38.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/yzyd62gjmtp3fmz/Screenshot%202016-02-07%2023.15.17.png
   :align: center
   :height: 300
   :width: 450

.. image:: https://dl.dropbox.com/s/ocr2adnun698eo7/Screenshot%202016-02-07%2023.16.05.png
   :align: center
   :height: 300
   :width: 450

.. image:: https://dl.dropbox.com/s/eyhswdeie14ztdf/Screenshot%202016-02-07%2023.16.30.png
   :align: center
   :height: 300
   :width: 450

.. image:: https://dl.dropbox.com/s/pmhme4lyyt4fhh3/Screenshot%202016-02-07%2023.17.01.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/ouws4ry1c5nmwpe/Screenshot%202016-02-07%2023.17.23.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/e0quc01vavysosy/Screenshot%202016-02-07%2023.17.42.png
   :align: center
   :height: 300
   :width: 450




We have organized the materials in this course, into eight major units, this chart illustrates those eight units. So
starting from the top left, the first unit has to do with Fundamentals of presentation and recent, Panning,


Common Sense Reasoning. Analogical Reasoning, Metacognition that we just talked a little about, Design & Creativity,
Visuospatial Reasoning, and Learning.


Now let's look at each of these circles, one at a time. So in the first part, dealing with the Fundamentals of this
course. We'll be dealing with certain, knowledge representations, and reasoning strategies. Two of the major knowledge
representations that we'll discuss in the first part of this course, are called Semantic Networks, and Production
Systems. Three of the reasoning strategies, are called Generate and Test, Means-End Analysis, and


Problem Reduction. Note that, the arrows here imply an ordering.


There is an ordering. In that, when we are discussing our Production Systems, we might allude to things that we are
discussing in the Semantic Networks.


Similarly, when we discuss Means-End Analysis, we might allude to things that we are discussing in Generate and Test.
However. It is important to note also, that these three methods are completely independent from each other.


It's just that we are going to discuss them, in the order shown here.


Similarly these two knowledge representations, are independent from each other.


It's simply that in this course, we'll discuss them in this order.


So the second major unit in this course. Pertains to Planning. Planning is kind of problem solving activity whose goal
is to come up with plans, for achieving one or more goals. Before we discuss Planning, we'll discuss Logic as a
knowledge representation. This knowledge representation, will then enable us to discuss Planning in a systematic way.
The third major unit in this course is common sense reasoning. Common Sense Reasoning, pertains to reasoning about every
day situations in the world. As an example,


I may give you the input, John gave the book to Mary. Note the input, does not specify who has the book at the end. But,
you can draw that inference easily. That is an example of Common Sense Reasoning. In our course, we'll discuss both
knowledge representations like frames, as well as methods for doing Common Sense Reasoning. As we discussed earlier,
when we were talking about the architecture of a cognitive system,


Learning is a fundamental process within deliberation. And therefore, we will be visiting the issue of Learning many,
many times throughout this course. However, we also have a unit on Learning, which has several topics in it. There are
other topics in Learning, that do not show up in this particular. Circle here but are distributed throughout the course.
Another major unit in our course is


Analogical Reasoning. Analogical Reasoning is, reasoning about novel problems or novel situations, but, analogic to what
we know about familiar problems, or familiar situations. As I mentioned earlier, Learning is distributed throughout this
course. Therefore Learning comes here in Analogical Reasoning also. In fact


Learning by recording cases appeared in the Learning topic as well as here, and you can see explanation based Learning
occurring here. Visuospatial Reasoning is another major unit in our course. Visuospatial Reasoning pertains to reasoning
with visual knowledge. As an example, I might draw a diagram and reason with the diagram. That's an example of
Visualspatial Reasoning.


In the context of Visualspatial Reasoning, we're talking both about


Constraint Propagation, and using that to do Visualspatial Reasoning. Design & Creativity is the next topic in our
course. We want to build AI systems, that can deal with novel situations, and come up with creative solutions.


Design is an example of a complex task which can be very, very creative, where we are discussing a range of topics in
the context of Design & Creativity.


So in the next topic in our courses Metacognition, we have already come across a notion in Metacognition, when we were
talking about the architecture of the cognize system. Metacognition pertains to thinking about thinking. And we'll
discuss a range of topics and then, we will end the course by talking about Ethics in Artificial Intelligence.


This figure illustrates all the eight major units once again, as well as the topics within each major unit. I hope this
will give you mental map of the organization of the course as a whole. In preparing this course, we came up with a
ordering of the topics, which will interleave many of these topics. So we will not do the entire first unit, before we
go to the entire second unit and so on. Instead, we will do some parts of first unit, then go to some other part that
follows conceptually from it, and so there will be some interleaving among these topics. And one aspect of the
personalization is, that you are welcome to go through these topics in your own chosen order.


You don't have to stay, with the kind of order that we'll be using.


This is an exciting agenda. I hope you are as excited as I am.


There are very few, opportunities where we can talk about exotic topics, like Analogical Reasoning, and Creativity, and
Metacognition. And, in this particular course, we'll talk about all of them together.


19 - Wrap Up
------------

.. image:: https://dl.dropbox.com/s/233n7xuvmk714gv/Screenshot%202016-02-07%2023.19.27.png
   :align: center
   :height: 300
   :width: 450



So at the end of every lesson, I will briefly recap what we talked about during that lesson and try to tie it into some
future topics.


Today, we started off by talking about the central conundrums and characteristics of AI. This may have connected with
some of your previous experience with other AI classes, like machine learning in AI for robotics. We then talked about
the four schools of AI, and we talked about knowledge-based AI more specifically, what is it and where does it fit in
with the other schools? Then we talked about cognitive systems and how cognitive systems are always concerned with human
like intelligence. Lastly, we talked about the overall structure of the course, which is broken up into eight large
categories, like learning, planning and analogical reasoning. Next time we'll talk a little bit more specifically about
this class in particular. The goals, the outcomes and the learning strategies, and what projects you'll complete.


20 - The Cognitive Connection
-----------------------------

At the conclusion of this lesson, we'll have a short video after the wrap up called the cognitive connection. Knowledge
based AI is richly connected to cognitive signs. And so many of the topics that we'll cover in this class are connected
to human reasoning and human learning, and human memory. The cognitive connections are not separate from the course. One
of the goals of this course is to learn how to use the design of AI agents to reflect on human cognition. The cognitive
connections will serve this purpose.


21 - Final Quiz
---------------

.. image:: https://dl.dropbox.com/s/gyhp4ml7b92yfnm/Screenshot%202016-02-07%2023.20.17.png
   :align: center
   :height: 300
   :width: 450



This brings us to the first quiz. After every lesson in this course we'll have a short quiz, in which we'll ask you to
write down what you learned in this lesson in this blue box here. These quizzes have two goals.


The first goal is to help you synthesize and organize what you have learned.


The process of writing down what you learned may help you, in fact, learn it more deeply. The second goal is to provide
us with feedback. Perhaps we could have been clearer or more precise about some of the concepts. Perhaps we left some
misconceptions. Note that these quizzes are completely optional.


22 - Final Quiz
---------------

Great. Thank you so much for your feedback.


