.. title: 11 - Classification 
.. slug: 11 - Classification 
.. date: 2016-01-23 06:41:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===================
11 - Classification
===================

01 - Preview
------------

Today we'll talk about one of the most ubiquitous problems in AI called classification. Classification is mapping sets
of percepts in the world into equals classes, so that we can take actions in the world in an efficient manner.


We could learn this concept through incremental concept learning.


We'll talk about the nature of these equivalence classes and how they can be organized into a hierarchy of concepts.
We'll talk about different kinds of concepts, like axiomatic concepts and prototypical concepts.


Given a classification hierarchy, we'll talk about multiple processes for doing the classification, including both
bottom-up and top-down processes.


02 - Exercise Concept Learning Revisited
----------------------------------------

In the previous lesson, we examined some techniques for learning about concepts from examples. But those were simple
concepts that we learned from a few examples. Concepts like arg or foo, which was our imaginary, hypothetical concept.
The real world concepts can be much more complicated than that. Consid, as an example, consider the eight animals shown
here. Each picture shows a very cute animal here. How many of these do you think are birds? Which ones are birds?


03 - Exercise Concept Learning Revisited
----------------------------------------

>> That was a good answer David, thank you. Note that David was able to classify these eight animals into birds. Which
one of these animals belong to the class of birds and which one did not belong to it. Notice also, that he used some
criteria to decide on that. He has some notion it seems so what is a typical bird. What kind of features does a typical
bird have?


He has some notion of what are the basic conditions that something must satisfy in order to be considered a bird, and if
those conditions are not being satisfied he would reject them and say those are not birds.


04 - Classifying Birds
----------------------

So here are four of the animals that David classified as birds. Let us look at the kind of features that he examined in
order to classify whether or not an animal was a bird. He may have used several features, some of which he articulated,
others that he may not have articulated. So whether a animal has wings? Whether it has feathers? Whether it has a beak?
And so on and so forth. One could add more features here if one wished to do so.


We do classification all the time. AI agents need to do classification all the time also. Why? Why is classification so
ubiquitous?


05 - The Challenge of Classification
------------------------------------

To see why classification is so powerful and so ubiquitous, and also to understand what exactly is classification, let
us go to our overall cognitive architecture for an intelligent agent.


This is a diagram that we have come across many, many times. Let us imagine this particular Cognitive System is dealing
with a set of percepts.


These percepts are in the world. So as an example this Cognitive System may see some object, some animal when the
Cognitive System goes to the zoo.


This might be an AI agent, or perhaps your friend who goes to the zoo.


And look at some animals and there are a large number of percepts in that environment. Has wings, Has feathers, talons,
beak and so on. And for the simplicity let's assume that each of the percepts is binary, it's either true or false. So
either the animal has wings or doesn't have wings.


And depending upon the percepts and the combinations of this percepts one might take different kind of actions. So if
it's a friendly animal one might go and pet it, if it's a unfriendly or dangerous animal one might run away from it.


So, all kind of actions are possible. Imagine that there are some M actions that are possible. Send, we can again
imagine that there is a binary choice here.


So, the total number of combinations of actions, as 2 to the power m.


So as an example. If I have a, if I see a dangerous animal in a zoo, then I might both scream and run away. If I see a
friendly animal,


I may approach the animal and make cooing noise to the animal. So, a number of actions and combinations of actions are
possible. And if n is the number of percepts then I have 2 to the power n. Combinations of percepts possible. So how is
the challenge that the cognitive agent faces? The challenges, that the number of percepts and the number of actions
multiplied by the number of combinations of percepts and the number of combinations of actions is very, very large. And
we have to map these percepts, combinations of percepts, actions, combinations of actions. This is a very complex
mapping. So imagine that only 10 percepts. Image at environment, so I'm looking at an animal and let's take 10 percepts
that I'm paying attention to.


Then two to the power 10, the number of combination of percepts is 1024, and doing it two to the power of 10 here
because I'm assuming each percept has a binary value. If I had 100 percepts, I was not looking at one animal, but


I was looking at a scene of animals. Then I may have 100 percepts, in which case I have a much larger number of
combinations. And if I had something like 300 percepts, which is not very large number.


The number of combinations is, well it's a very large number. more than the combinations of atoms in the universe. Now
you and


I, and AI agents more generally. Are constantly faced with a complex environment where there are a large number of
percepts, and a large number of combinations that are possible. So let's go back to something earlier that we had
considered in the class. We defined earlier that, one way of talking what intelligent agent is to think in terms of how
can an intelligent agent map percepts into actions.


Intelligence is, in part, a lot part perhaps, according to this definition, about action selection. The other aspect of
this is.


That if the number of perceptions is large and the number of actions is large.


Then the mapping between them becomes very large and very complicated quickly.


But intelligent agents have only finite resources. How is it then that we can select the right action. Or at least most
of the time select the right action.


Even when the environment is very complex. And do so in near real time.


06 - Equivalence Classes
------------------------

>> Now we understand why classification is such an often studied topic in artificial intelligence. Almost every school
of artificial intelligence has studied classification extensively. If there were no concept, we were mapping this 2 to
the power n combinations of percepts into this 2 to the power m combinations of actions. Then we could think of an
intelligent agent as a one large giant table. The rows of that table are all the 2 to the power n combination of
percepts, there would be that many rows. And the columns are to the power m actions. Given a percept, I know exactly
what action to take, the table tells you that, and it's going to be a very large table.


We don't know how to use it, but will be very costly to use it, and we don't know how to build such a table. What
classification is doing is, it is breaking that large table into a large number of small tables. And that's the power of
knowledge. When you have knowledge, you can take some complex problem and break into a large number of smaller, simpler
problems.


07 - Exercise Equivalence Classes
---------------------------------

So the next question becomes, given a set of animals, or in general, a set of objects or elements, and a set of percepts
for each of those animals, how can we decide what's a good equivalence class for those animals? Consider, for example,
the three animals shown here, eagle, bluebird, and penguin.


Let us suppose that we knew that there are six percepts that are important for each one of these animals. Lays eggs, has
wings, has talons, and so on. But in order to decide what might be a good equivalence class for these three animals, we
first have to decide on what might be the right values for each of these percepts for each animal. So I'm going to ask
you to use your background knowledge, to fill in the values of the percepts that applies to each of the animals.


08 - Exercise Equivalence Classes
---------------------------------

>> Good, David. You know more about those animals than I do.


Imagine that the three animals were given as examples, one after the other.


So we are back to incremental concept learning of the previous lesson.


One can use the techniques that we learn in the previous lesson, to learn some equivalence class. Learn some concept
definition with the three animals. But that's not the point here, the point here is not of the learning of the concept.


The point here is much more about, the nature of the concepts, and how they get organized available each other.


09 - Concept Hierarchies
------------------------

>> So, one of the benefits of this establish and or find approach, is it helps us figure out which variables we need to
actually key in on and focus on. So, for example we saw earlier that Eagles are large, but,


Bluebirds are small. So, Birds can come in different sizes. So if we're trying to establish whether somethings a Bird,
or a Reptile, or a Mammal, we know that Mammals also come in different sizes like tiny mice and large elephants. So size
doesn't really impact our decision whether it's a Reptile, Bird or Mammal. But once we've established it's a Bird, and
we're trying to decide between Eagle and Bluebird for example. We know that size actually can be something, that helps
us differentiate between these two.


So now we'll pay attention to size, as a variable that matters. So note that there are several things going on here. On
one side, there is knowledge of these different classes. But, there's also organization of these different classes in a
hierarchy of a particular colony.


This organization is very powerful. In some ways if knowledge is power, so is organization. Organization too is power.
This organization provides power, because organization tells you what it's controller processing should be.


Establish one node. Refine it. Establish that node. Refine it.


10 - Exercise Concept Hierarchies
---------------------------------

Let us return to the exercise that we were trying to do earlier, where we had eagle and bluebird and penguin. And we had
features, and we had values for the eagle and the bluebird and the penguin. Well, given these three sets of values for
the eagle, bluebird and penguin. And given that bird is a superclass of these three classes. What would be the features
that you would put in the bird node in that classification hierarchy?


11 - Exercise Concept Hierarchies
---------------------------------

>> That's a good answer, David. But I should quickly note that, this idea that we can decide on the features that should
go into a super class, given the features that are shared among the sub-classes. Works only for certain kind of concept.
It doesn't work for all concepts. And vertical work for concepts that have a formal nature as we will see in just a
minute.


12 - Types of Concepts
----------------------

We can think of concepts lying on a spectrum.


On one extreme end are extremely formal concepts for which we can define logical conditions that are necessary and
sufficient for that concept. We'll examine that in more detail in just a minute.


On the other end of the spectrum are less formal concepts for which it's hard to define necessary and sufficient
conditions. Now here are three points on the spectrum. Axiomatic concepts, prototype concepts, exemplar concepts.


There can be other types of concepts as well. We're just going to consider these three concepts because they are the
three most common ones.


And we'll look at each one of them in turn. In general, humans find it easier to communicate about axiomatic concepts
because they are well defined.


There is a set of necessary and sufficient conditions that we all agree with.


Examples are mathematical concepts. Humans find it harder to communicate about prototype concepts, but most of the time
we do quite well. It's even harder to talk about exemplar concepts like, let's say, beauty or freedom. Similarly, it's
easier to teach computers axiomatic concepts or program axiomatic concepts into computers. It's much harder to program
or teach prototype concepts.


And much, much harder to teach a program exemplar type concepts.


13 - Axiomatic Concepts
-----------------------

So let us look at each one of them. Axiomatic concepts, product concepts, and exemplar concept in more detail. Let's
become with axiomatic concept. And axiomatic concept is a concept, it is defined by a formal set of necessary and
sufficient conditions. Geometric objects like a circle are good examples.


Triangles, squares, rectangles, and so on. So as an example, a circle are all points in a plane that are equidistant
from a single point. And the single point is the center of the circle. Now, this is a very formal set of necessary and
sufficient conditions. Given any other object, you can see whether or not the particular object is a circle by looking
for this particular condition.


14 - Prototype Concepts
-----------------------

The notion of axiomatic concepts is the classical view in cognitive systems.


Here's an alternative view. This is called Prototypical concepts.


Prototypical concept is a base concepts defined by some typical properties that can sometimes be overridden. So, an
example is a chair. You and


I have a notion of a prototypical chair. Our notion of a prototypical chair may have, for example, there is a back,
there is four legs and so on. So, here might be your and my notion of a prototypical chair. It has a back, it has a
seat, it has four legs and so on. Now I can represent this notion of the prototypical chair in the language of frames.
This is something we have come across earlier in the class. A frame has slots and fillers, as you may recall, and we use
frames to represent stereotypes. Here we're talking about prototypes, so very closely related. So concept is the a
content you can represent.


Frame is the form in which we can represent it. So a notion for the prototypical chair might be, it has four legs, it,
the material is metal, it has a back, it does not have arms, and it's not cushioned.


Note that these are the typical properties of a chair. Of course, some chairs need not necessarily satisfy all of these
properties. That is why there are no, no necessary and sufficient conditions here. For example, we may come across a
chair. Which is made of wood. While you would still consider it a chair, even if you're not strictly satisfied with this
particular definition.


Thus, these properties can be overridden in case of specific instances.


But we'll still have the basic notion of a prototypical chair so that we can in fact communicate with each other about
what a chair is.


Despite the fact that we can override these properties we do still have a notion of prototypical chair. So the
relationships between concepts and frames actually is quite close. Recall that when we were talking about frames, we
were also talking about inheritance and default. The notion of default in frames is closely connected to the notion of
typical properties and concepts. So chair has this prototypical notion with some of these typical properties, and we can
think of this as having a default values. By default, we assume the number of legs is four, the material is metal and so
on. Here is a stool and this stool is a kind of chair which means that it inherits all the values and all the slots that
are there in the chair directly except for those that happen to be different from the one in the chair. So then an
example here it over writes a notion that the chair necessarily has to have a back.


In the case of a stool, the stool does not have a back.


15 - Exemplar Concepts
----------------------

Like so many concepts with refinement necessary in sufficient conditions, for typical concepts in typical conditions,
what about exemplar concepts?


Exemplar concepts don't even have typical conditions, let alone necessary and sufficient conditions. In case of exemplar
concepts, I can give you examples.


Perhaps I can do some implicit abstraction of some examples, but it's about as far as I can go. Consider the example of
beauty for a second.


There are four examples of something beautiful. Here's a painting by Van Gogh, here's a beautiful sunset, a beautiful
flower, a beautiful dance and so on. While I can give examples of the concept of beauty, it's really hard to come up
with the typical condition of a beauty.


Exemplar concepts are very hard to, define. And for that reason, they are also very hard to, communicate to each other,
or to teach in a art program.


Exemplar concepts can be culture specific, sometimes even individual specific.


16 - Order of Concepts
----------------------

To summarize then, concepts can be of many different kinds. Fro very formal, concepts, like Axiomatic concepts, to less
formal concepts, like Exemplar concepts. Of course, we can, if we want less formal concepts, like exemplar concepts,
philosophers often talk about concepts called qualia,


Q-U-A-L-I-A. Qualia for the raw sensations that we may get from our sensors. And example of qualia is, bitterness. I'm
sure you've come across some bitter fruit, some time or the other. And you can even taste it, inside your mouth right
now, if you wanted to. But it's very hard to communicate what a qualia is to anyone else, what. Your notion of a genesis
to anyone else.


17 - Exercise Order of Concepts
-------------------------------

Let us do an exercise together. On the left again is a spectrum from very formal to less formal. In the right here are
six concepts. Inspirational, reptile, foo. Foo here is the same concept that we came across when we're talking about
incremental concept learning. This is the same foo here. Right triangle, holiday, saltiness. Can you rank the six
concepts according to the notion of formality that we have studied so far?


18 - Exercise Order of Concepts
-------------------------------

>> So part of the point of looking at these two different kinds of concepts is that depending on the different kinds of
concepts we are dealing with right now, you may come up with a different knowledge representation and a different
inference method. Let me explain.


Supposing we're dealing with concepts like Foo or Holiday or Inspirational.


Then the case-based reasoning method might be a very good method for dealing with things of that kind. We may have
experience with specific holidays, but we cannot abstract them out into a concept with prototypical conditions.


On the other hand, if we were dealing with concepts like a right triangle or a reptile, for which we can define
necessary and sufficient conditions, in that case there are alternative methods available that might be more suitable
then case-based reasoning. So instead of thinking in terms of one method that is going to work for all conditions and
all concepts, we might want to think in terms of a array of methods, where each method is more or less useful for
different kind of conditions or different kind of concepts.


David, I am sure you recall mentally who was a Russian chemist who came up with the basic notion of the chemical
periodic table. I'm sure all the students in the class know about the chemical periodic table, which organizes all the
elements according to certain properties like hydrogen, oxygen, calcium, and so on. Now, Mendeleev came up with this
notion of a chemical periodic table, and in some sense what we're trying to do in this course is to build a similar kind
of periodic table, except that this is a periodic table of the elements of mind.


It's a periodic table of the basic fundamental elements that compose intelligence. Instead of talking about elements and
valances and atoms and so on, what we are going to be talking about are methods and representations. So it as if we are
discovering the fundamental knowledge for presentations and organizations and reasoning methods that go with it.


Case based reasoning was one. Reasoning method that went with certain kinds of concepts that are hard to abstract and
into conditions, like typical conditions, are necessarily logical conditions.


19 - Bottom-Up Search
---------------------

Let us build on this metaphor of periodic table a little bit further.


So earlier we came across another method of dealing with classification, which we call top down or establish define.


In that method we had this classification hierarchy which start with a concept, will establish it, then refine it, and
refine it further if needed.


That particular control of processing is very well suited for one kind of organization of concepts. It's very well
suited for one set of situations where we know something is already a vertebrate, we're trying to establish whether it's
a bird or a bluebird. And a different kind of classification task. A better control of processing is to go bottom up.


Let's look at this a little bit more carefully. Here are a number of leaf nodes.


And we know, the agent knows something about the value for each of these leaf nodes. And the task is to make a
prediction at the root node.


So in this particular case imagine the task of the AA agent is to predict the of the Dow Jones Industrial Average
tomorrow. It'll be great to have an AA agent like that. If we had a good AA agent like that, you and


I could both become very rich. Now how could this A, agent make a prediction about the Dow Jones Industrial Average
tomorrow?


Well, one way in which it could do it is it could look at the.


Information it has about the GDP the inflation and employment today. but how does it know about the value GDP or the
inflation or employment today. Well it can look then at the values of the overtime hours.


The consumer sentiment index, new orders index and so on and so forth.


Now, the processing is largely, bottom up. We know something about the values or the features that go into this concept.


And they're going to this concept, they're going to this concept.


You can abstract them and find the value of the GDP. And similarly for this, and then abstract it further. So the
control of processing in this particular case, we might call it identify and abstract, identify an abstract.


Bottom-up controller processing rather than top-down in the previous case.


We have just defined two other elements of our periodic table, of our growing periodic table of intelligence. In this
latter element, the bottom-up classification, the conditions of application are different.


20 - Assignment Classification
------------------------------

How would you apply the principles of classification, to designing an agent that can solve Raven's progressive matrices?


In answering this there's a lot of questions to touch on. For example, will you develop the classification scheme
yourself, or are you going to have your agent learn it as it encounters new problems. So what would that classification
scheme look like? What percepts will the agent use to classify new problems into that classification scheme? Then once
it's classified them, how will that classification actually help it solve the problem? What will it be able to do this
way that it wouldn't have been able to do otherwise?


21 - Wrap Up
------------

So today we've talked about classification, which is one of the biggest problems in AI. We started by revisiting
incremental concept learning and reminding ourselves how it allowed us to take examples and abstract away a concept. We
then looked at the idea of equivalence classes and how we can group sets of percepts into equivalence classes to
establish a particular instance of a concept. Within this is the hierarchies of concepts, such as the animal kingdom,
where animals can grow kind of into vertebrae, birds and penguins.


We then discuss the idea of different types of concepts like axiomatic or exemplar concepts, and how each of them have
different definitions and different affordances. Finally, we discuss bottom-up search, so instead of establish and
refine, we look at the lower level variables and abstract up from them. Next, we're going to move on to logic, which is
a little bit unrelated to this.


But if you're interested in classification, you can look ahead to all our different lessons on design, such as diagnosis
and configuration.


They're going to really heavily leverage our idea of classification.


22 - The Cognitive Connection
-----------------------------

One could say a lot about the connection between classification and cognition.


This is because classification is ubiquitous in cognition. You're driving a car on the street, you see a friend driving
his car, you look, take a look at the car, and you see a Porsche. Classification. You're on a computer program, the
output is faulty. You look at the output, decide on the bug.


You name the bug. Classification. You go to a doctor with certain signs and symptoms, the doctor names a disease
category, classification. The reason classification is so ubiquitous is because it allows us to select actions.


Once the doctor knows what the disease category is, he can suggest a therapy.


Once you know what the bug is you can decide on a repair for that bug. If action selection indeed is a very productive
characterization of intelligence then we can see why classification is central to cognition.


23 - Final Quiz
---------------

All right. Please right down what you learned in this lesson in this box for us to peruse later.


24 - Final Quiz
---------------

And thank you for doing it.


