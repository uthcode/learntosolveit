.. title: 17 - Explanation-Based Learning 
.. slug: 17 - Explanation-Based Learning 
.. date: 2016-01-23 06:47:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===============================
17 - Explanation-Based Learning
===============================


01 - Preview
------------

Today, we'll talk about explanation-based learning.


In explanation-based learning, the agent doesn't learn about new concepts.


Instead, it learns about connections among existing concepts.


We'll use explanation-based learning to introduce the notion of transfer of knowledge from an old situation to a new
situation. This will help us set up infrastructure needed for talking about analogical reasoning next time.


Today, we'll start by talking about a concept space where we will map out all the concept and relationships between
them. Then we introduce the notion of abstraction that helps us do transfer. Finally, we'll use transfer to build
complex explanations that will lead to explanation-based learning.


02 - Exercise Transporting Soup
-------------------------------

To illustrate explanation-based learning, let us begin with an exercise.


Imagine that you want to transport soup from the kitchen to the dining table.


Unfortunately, all of the usual utensils you use to transport soup are unavailable. They're dirty, or just not there.


So you look around, and you see some objects in the vicinity.


Here is your backpack, here is a pitcher, here is a box, here is your car. And you wonder which one of these four
objects could you use to transport soup from the kitchen to the dining table. Well, which one would you use?


03 - Exercise Transporting Soup
-------------------------------

>> I think most of us would give the same answer.


The pitcher, not the backpack or the car or this box. Now for humans, for you and me, this is a little bit of an easy
problem.


All of us get it right pretty much all the time. And what about a machine?


What about a robot? How would a robot decide that a pitcher is a good utensil to use for transporting soup from the
kitchen to the dining table, but not a backpack and not a box? For a robot, this is a surprisingly hard problem.


So the question then becomes, well, what is it that makes it easy for humans and hard for robots? How can we program AI
agents so that it would be easy for them as well? One important thing to note here, this is another example of
incremental learning. Now we have come across incremental learning earlier, when we were talking about incremental
concept learning.


There we were given one example at a time, that was the example of art, and we were learning one concept, the concept of
art. This is in contrast to other methods of machine learning. Where one is given a, large amount of data, and one has
to detect patterns with a variety in that data. Here, there is learning occurring one step at a time, from a small
number of examples, one single concept has been learned. We also came across the notion of incremental learning, when we
were talking about chunking. Day two, there was one particular problem, and from a small number of previous episodes, we
chunked a particular rule. This notion of incremental learning, for me it's much of knowledge based AI. Another thing to
note here, this notion or expression based learning is related to creativity.


We talked earlier about the relationship between creativity and novelty.


Here is an example in which an AI agent is dealing with a novel situation.


Usual utensils for taking soup from the kitchen to the dining table are not available. What should the robot do?


The robot comes up with a creative solution of taking the pitcher as the utensil


04 - Example Retrieving a Cup
-----------------------------

So imagine that you have gone to the hardware store and bought a robot. This is a household robot. Usually the robot
goes into the kitchen, makes coffee and brings it to you in a cup. However, last night you had a big party, and there's
no clean cup available in the kitchen. The robot is a creative robot and looks around, and it finds an object. And this
object is light and made of porcelain. It has a decoration. It is concave. It has a handle.


The bottom is flat. The robot wonders, could I use this particular object like a cup? It would want to prove to itself,
that this object, in fact, is an instance of this concept of cup. How might the robot do it?


05 - Concept Space
------------------

So let us now see how the AI agent may go about building an explanation.


Why this particular object is an instance of this cup?


So this what the robot wants to prove, the object is a cup.


And this what the robot know about the object. Object has a bottom, the bottom is flat, the object is made of porcelain
and so on and so forth.


So the question then becomes, how might the AI agent embodied in the robot, go about using its prior knowledge, in order
to be able to build this explanation?


But another way, what prior knowledge should the AI agent have, so that it can, in fact, build this explanation?


06 - Prior Knowledge
--------------------

Let us suppose that the A agent has prior knowledge of these four concepts.


A brick, a glass, a bowl, and a briefcase. Let us look at one of these concepts in detail. So the brick is stable
because the bottom is flat. And a brick is heavy. So first, this particular conceptual characterization has several
parts. About stability and about heaviness. Second, there is also something about causality here.


The brick is stable because its bottom is flat. This is an important element of the brick, and similar things occur in
the other four concepts.


Let us now consider how an AI agent might be able to represent all of this knowledge about a brick. Here is a visual
rendering of this representation.


First, the A agent knows about a lot facts about the brick. So a brick is heavy.


The brick has a bottom and the bottom is flat. That comes from the second part of the first sentence. Bottom is flat.
And also that the brick is stable. So here are some observable facts and this is a property of the brick. So this is
part of the structure of the brick. This is part of its function. In addition, the A agent knows that the brick is
stable because the bottom is flat. So we need to capture this notion of causality. So this yellow arrows here, are
intended to capture this notion of causality. The AI agent knows that the brick is stable because the brick has a bottom
and the bottom is flat. And this way, it connects these structural features into these factional features, to these
causal connections. To take another example, here is a conceptual characterization of a briefcase and here is it's
knowledge for representation. I'll not go through this in great detail, but briefly, a briefcase is liftable because it
has a handle and it is light.


And it is useful because it contains papers. Notice the notion of causality here again. Once again there're these facts
about the briefcase, for example the briefcase is portable, the briefcase has a handle, you know, these structural
observable features. And then there is this functional features like briefcase is useful and briefcase is liftable. And
then we have these yellow arrows denoting the causal connections between them.


Similarly for the bowl, here is its conceptual characterization and the knowledge representation. So the bowl contains
cherry soup that one of the fact here. The bowl is concave, that's another fact here and it is a causal relationship
here. It carries liquid because it is concave.


Finally the fourth concept the A agent knows about, a glass. And a glass enables drinking because it carries liquid and
it is liftable, and it is pretty.


So the glass is pretty. The glass carries liquids. It is liftable. And the fact that it enables drinking is because of
these two other facts. Note quickly that not all these structural features participate in this causal explanation.


07 - Abstraction
----------------

Now that we have the characterizations and the knowledge representations the four concept's worked out, let us see how
the AI agent might actually use them. So let's look at the bowl.


Here was the knowledge representation of the characterization of the bowl.


The AI agent will abstract some knowledge from this particular example.


Here is its abstraction. Two things have happened here.


First, it is abstracting only those things, that are in fact causally related.


Simple features that have no causal relationship with other things, are not important and they can be dropped. So we can
add one other element of a notion of an explanation. The explanation is a causal explanation. The AI agent is trying to
build a causal explanation that will connect the instance, the object, into the cup. Second, the AI agent creates an
abstraction of this characterization of the bowl. And so in the bowl, it replaces it with an object.


So here the bowl carries liquids, because it is concave, and it is abstracted to the object carries liquid because it is
concave. This is the abstraction that is going to play an important role in constructing the causal explanation.


08 - Transfer
-------------

>> This kind of explanation with learning, actually occurs in our everyday life.


So you and I are constantly improvising. Papers are blowing off my desk. How can


I stop them from blowing off? So, I need something to stop them blowing away.


What is available? What can act as a paper weight? A cup. Here is a cup.


Let me put it on the papers. This is an example of improvisation, where we use explanation based learning to realize
that, anything that's heavy and there's a flat bottom, can act as a paper weight. Here is another example.


I need to prop open a door. A door stopper is not available. What can I use?


Perhaps an eraser or a chair. You and


I do this kind of improvisation all the time, and often we are building these explanations that tell us that an eraser
can be used as a door stopper


09 - Exercise Explanation-Based Learning I
------------------------------------------

Okay let us do an exercise together.


This time instead of showing that an object is an instance of a cup, we are going to try to show that an object is an
instance of a Mug. So here is the definition of a Mug. A mug is an object that is stable, enables drinking, and protects
against heat. Notice that we have added one more element here, not only stable like a cup, not only enables drinking
like a cup, but also protects against heat. Here is an object, I will label in the cushion.


The object is light and is made of clay. It has concavity and has a handle.


The bottom's flat and the sides are thick. You can assume that the agent knows about all four examples as earlier, the
glass, the bowl, the brick, and the briefcase. [UNKNOWN] in this particular case the agent also knows about yet another
example, a Pot. The Pot carries liquid because it is concave,


It limits heat transfer because it has thick sides and is made of clay. Your task is to. Build an explanation that
shows, that this object is an instance of a Mug. Can we prove this?


10 - Exercise Explanation-Based Learning I
------------------------------------------

>> That is good David. Let us make sure that we understand the processing that


David did. He wanted to show that the object is a Mug. So, he looked at the condition, the open conditions were proving
that the object is a Mug and there were three of them. For each of them, he tried to build a proof.


He could do so for the first two, but this was the open one.


So, he came up with the closest example that was a part and he did the extraction here but he was unable to link these
two because there is no knowledge which links these two in the present time


11 - Exercise Explanation-Based Learning II
-------------------------------------------

So let us do another exercise that builds on the previous one.


Which of this four concepts will enable the a agent to complete the proof in the previous exercise?


12 - Exercise Explanation-Based Learning II
-------------------------------------------

>> There are a couple of other points to note about this exercise.


An important question in our [INAUDIBLE] is, what knowledge does one need.


It's not a question of putting in a lot of knowledge into a program.


Instead, the real question is, in order to accomplish a goal what is the minimal amount of knowledge that the AI agent
actually needs?


Let's see how this applies here. The goal was to show that the object is a mug.


Instead of putting in a lot of knowledge, the agent starts asking, what do we need in order to show that the object can
protect against heat?


What do we need to know to show that the object is stable?


And then it goes about searching for that knowledge. The second point to note here is, depending on the background
knowledge available, the agent will opportunistically build the right kind of causal proofs. So if the agent knows about
the wooden spoon, it will approve this proof. If, on the other hand, the AI agent knew not about the wooden spoon but
about the oven mitt, then it could use this particular proof. Which proof the AI agent will build, will depend upon the
precise background knowledge available to it


13 - Explanation-Based Learning in the World
--------------------------------------------

Exploration-based learning is very common in the real world. You and


I do it all the time. You need to prop open a door, you bring a chair, and you use it to prop open the door because it
just put an explanation for why the chair, in fact, can prop open a door. There is a sheaf of papers on a desk with the
shuffling around. You take a coffee mug, put it on the sheaf of paper that acts as a paperweight. Another example or
explanation best learned.


You and I are constantly dealing with novel situations, we are constantly coming up with creative solutions to them. How
do we do it?


One way is if we use existing concepts but use them in new ways.


We find new connections between them by building explanations for them. This is sometimes called Speed Up learning
because we're not learning new concepts, we're simply connecting existing concepts. But it's a very powerful way of
dealing with a large number of situations. And today in class, we'll learn how we can build AI agents that can do the
same thing that you and I do so well.


14 - Assignment Explanation-Based Learning
------------------------------------------

So how would you use explanation based learning to implement an agent to can solve Raven,s progressive matrices? The
first question you're asking here is what exactly are you explaining? Are you explaining the answer to the problem, or
are you explaining the transformations between figures in the earlier stages of the problem? Given that, what new
connections are you learning,


Is it learning performed within the problem or old connections an justify the figure to fill in the blank, or to perform
the cross problems, where new transmissions and types of problems can be learned and connected together.


For example you might imagine that you've encountered two problems before, one are rotation and one are reflection. A
new problem might involve both, how do you use those earlier problems to explain the answer to this new problem?


15 - Wrap Up
------------

So today, we've talked about explanation-based learning, a type of learning where we learn new connections between
existing concepts.


We first talked about our concept space.


A space of information that enables us to draw inferences and connections about existing concepts. We then talked about
how prior knowledge is mapped onto this concept space for new reasoning. Then we talked about how we may abstract over
prior knowledge to discern transferable nuggets. And how we might then transfer those nuggets onto the new problem we
encounter. Next time, we'll expand on this idea of transfer to talk about analogical reasoning, which is inherently
transfer-based. Explanation-based learning will also come up significantly in learning about correcting mistakes and in
diagnosis. So feel free to jump ahead into those lessons, if you're interested in continuing with this example.


16 - The Cognitive Connection
-----------------------------

Explanation based learning is a very common classroom task, you and


I appear to do it all the time. We can use a chair to prop open a door, and we can deliver a very quick explanation for
why the chair is a good prop.


We can use a coffee mug to hold down a pile of papers, and pull out an explanation for why the coffee mug would make a
good paper weight.


Of course there is a lot more to it than we have discussed sso far.


Explanation based learning is central [INAUDIBLE] on cognitive science, because we are trying to build human like, human
level intelligence. Explanations and explanation based learning nowhere is prominent in other schools of AI.


Second, note that humans are not very good at explaining everything.


We can only explain those things which appear to be consciously accessible.


We have a hard time explaining memory processes, for example, or we have a hard time explaining certain kinds of
physical actions.


For example, when I play tennis, my feet move the way they do, and


I can't explain to you why I can't make them move better. Third, although we can generate explanations, this does not
necessarily mean that our process for generating explanation is the same process that we use to arrive at the decision
in the first place. Explanations can be post talk. Further, the very act of [UNKNOWN] explanations could interfere with
the reasoning process. [BLANK_AUDIO]


However, when we can generate explanations, it can lead to much deeper, much richer understanding and learning, because
it exposes the cause of connections. Finally, for AI systems to be accepted in our society they must be able to generate
good explanations. You, for example, will be unlikely to accept the advice of a medical diagnostic system if the
diagnostic system cannot explain it's answers.


I must be able to explain it's answers as well as the process it used to arrive at those answers. Explanation is
fundamental to trust.


17 - Final Quiz
---------------

Please write down what you learned in this lesson.


18 - Final Quiz
---------------

Great. Thank you so much for your feedback.


