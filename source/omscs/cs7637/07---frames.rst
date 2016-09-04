.. title: 07 - Frames 
.. slug: 07 - Frames 
.. date: 2016-01-23 06:37:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===========
07 - Frames 
===========

01 - Preview
------------

.. image:: https://dl.dropbox.com/s/makgw7yfxwllzi4/Screenshot%202016-02-12%2021.39.40.png
   :align: center
   :height: 300
   :width: 450

Today we'll talk about frames. Frames are a very powerful and very common knowledge representation. Frames are our first
step, a basic unit towards building a creative common sense reasoning. They'll also come up in several other topics,
such as understanding. We'll begin by talking about the function of frames, what are they useful for, and what makes
them so useful. Then we'll talk about several properties of frames. We'll relate the knowledge representation of frames
with other knowledge representations, such as semantic networks and production systems. And finally, we will show how
frames can be very useful for sense-making. For story understanding.


02 - Exercise Ashok Ate a Frog
------------------------------

.. image:: https://dl.dropbox.com/s/okxzmvilkin63f6/Screenshot%202016-02-12%2021.40.43.png
   :align: center
   :height: 300
   :width: 450


We started this unit by saying, that frames are a useful knowledge representation, for enabling common sense reasoning.
But what is common sense reasoning? You can do it, I can do it. How do we make a machine do it?


To illustrate common sense reasoning, let us consider a simple sentence.


Ashok ate a frog. All right, you understand the sentence. You understand the meaning of the sentence. But, what is the
meaning of the meaning?


What did you just understand? Try to answer the questions on the right.


03 - Exercise Ashok Ate a Frog
------------------------------

.. image:: https://dl.dropbox.com/s/sdqfmchp8ys47tz/Screenshot%202016-02-12%2021.41.29.png
   :align: center
   :height: 300
   :width: 450

>> I believe I did. So is the first frog dead or alive? I can't imagine you eating a frog and the frog staying alive, so
I'm going to say the frog is dead.


Where is the frog if you ate it? It's probably in your stomach.


And are you happy or sad? I don't know if you like to eat frogs, but


I'm going to assume that you do. So I'm going to assume that you are happy.


Thank you, David. So David just did common sense reasoning.


There was nothing in this input which said whether the frog was dead or alive.


There was nothing in the sentence which said Ashok was happy or sad. But David made sensible inferences. I will discuss
a lot more about common sense reasoning a little bit later. For now, I want to talk about the knowledge representation
called Frames that will allow us to make some inferences of this kind.


04 - How do we make sense of a sentence
---------------------------------------

.. image:: https://dl.dropbox.com/s/4y6xhsujq2e73u3/Screenshot%202016-02-12%2021.44.02.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/ettz6xa7i56aqo3/Screenshot%202016-02-12%2021.44.58.png
   :align: center
   :height: 300
   :width: 450

Let us look at the meaning of the sentence, Ashok ate a frog.

When I say the sentence, you understand its meaning immediately. But what did you understand? What is the meaning, of
the meaning, of the sentence?


How can I capture that meaning? How we capture it in a machine? Let us focus for now, on the verb in the sentence, which
is ate. We'll associate a frame.


With the verb in the sentence. Later on we will see that frames can also be associated with the objects or the nouns in
the sentence, but for now we will focus on the verb. Now what is it that we know about the stereotypical action of
eating? What happens when people eat, when you and


I eat? Usually there is an agent, that does the eating. And that particular agent that corresponded the subject of the
sentence. Usually something is being eaten, that's the object. There is often a location where the eating is done or the
time when the eating is being done. Someone might use a, utensil to do the eating. You might eat with a fork or a spoon
for example. There might be other things that we know about the stereotypical action of eating. For example, what is
being eaten typically is not alive. At least not when humans eat it.


Now this vertical slot object-is, this concerns the location of the object.


Where is the object after it has been eaten? And you might say well, it's inside the subject's body. What might be the
mood of the subject? Well, after people have eaten, typically they are happier. So, here is a list of slots that we
associate with the stereotypical action of eating.


This is not an exhaustive list, you can add some more. So each of the slots may take some values. We'll call these
values fillers. So slots and fillers. Some of the fillers are here by default.


Some of the fillers may come from. Parsing the sentence. So, we know that in this particular sentence, the subject is
Ashok and the object is a frog.


Okay so, frame then, is a knowledge structure. Note the word structure.


There are, a number of things happening in this knowledge representation.


If I may take an analogy with something, with which I'm sure you are familiar.


Consider the difference between an atom of knowledge representation, and a molecule of knowledge representation. Some
knowledge representations are like atoms, other knowledge representations are like molecules.


An atom is a unit by itself, a production rule is like an atom.


On the other hand, frames are like molecules, they have a structure.


There are a large number of things happening. These molecules could expand or could contract. You can do a lot more with
frames, that you can do with a simple production rule. So frame isn't like a knowledge structure, which has slots, and
which has fillers that go with it. Some of these fillers, are by default.


A frame deals with the stereotypical situation. Consider now a different sentence. Suppose we had the sentence, David
ate a pizza at home. Now here,


I have filled out what a frame for this particular sentence would look like.


The subject is different, the object is different. This time, there is some information about location, in the previous
sentence there was no information about location. Let us compare these two frames for another second.


Note that these slots. In case of both the frames are exactly the same, because the frame corresponds to the action of
eating. The fillers on the other hand are different, at least some of the fillers are different, because these fillers
corresponded the various input sentences. The only fillers that are the same, are those fillers which have to do with
default values for particular slots.


05 - Exercise Making sense of a sentence
----------------------------------------

.. image:: https://dl.dropbox.com/s/vlglwqmvhqn8omj/Screenshot%202016-02-12%2021.46.34.png
   :align: center
   :height: 300
   :width: 450

Okay, let us do an exercise. On the left I have shown you a sentence.


On the right is a frame for Ate. Please write down the slots for the frame for


Ate, as well as the fillers that will go for these slots for this particular input sentence.


06 - Exercise Making sense of a sentence
----------------------------------------

.. image:: https://dl.dropbox.com/s/63c7zet0ks2dfsk/Screenshot%202016-02-12%2021.47.03.png
   :align: center
   :height: 300
   :width: 450

.. image:: https://dl.dropbox.com/s/04zh9crl2ltn9fy/Screenshot%202016-02-12%2021.48.56.png
   :align: center
   :height: 300
   :width: 450

>> That's a very good answer, David. First of all, your answer is correct.


And in addition, you were able to point out that there is no slot here which is able to take care of the information
coming in as input about her dad.


Before we worry about what information that Angela had lasagna with her dad.


Let us look at some of the properties of frames. So once again there are slots.


You can put fillers in the slots. Each filler may come from a range of values.


Some of these slots have default fillers. Now you can see how some kind of common sense inferences become possible. Some
of them become possible from these default fillers for these slots. So for example, when we said Ashok ate a frog, and
David answered the question whether the frog was dead or alive by saying the frog was dead. Well, we know about it
because there is a default value here, the object that has been eaten is not alive, it's false to say it's alive.


And the location of the object after it has been eaten is inside the subject's stomach, or inside the subject's body.
And so on. We could put here more slots, with more default values for them. Once again, we'll discuss a lot more about
common sense reasoning a little bit later in this particular course. For now, we are trying to understand the knowledge
and presentation of frames.


07 - Complex Frame Systems
--------------------------

.. image:: https://dl.dropbox.com/s/1otdytjnwa5l5o3/Screenshot%202016-02-12%2021.50.36.png
   :align: center
   :height: 300
   :width: 450


>> That's a good point, David. So far, we have been talking about sentence level understanding. The sentence that Angela
ate lasagna at Olive Garden with her dad, for example. But we can also also about discourse level understanding.


A discourse may contain a series of sentences, one after the other.


So the first sentence, for instance, may say something about Angela and her food preferences. And we may construct a
frame for Angela.


The second sentence may say something about a restaurant called Olive Garden, which is located in Atlanta. And we make
construct a frame for the Olive Garden.


When the whole sentence comes and says that Angela had lasagna with her dad at


Olive Garden, we construct a frame, and then we can hook up these radius frames.


Another being you get a discourse level understanding.


Not just a sentence level understanding. So indeed, just like a frame enables us to understand some unit of language,
for example, a sentence or a phrase. When we start hooking up these frames together, we can start understanding larger
units of language, for example, a group of sentences of this course. As we'll go along, we'll see these frames also
allow us to pull information from the input sentences to put in the fillers of this slots. So indeed, the ability to
hook these frames together allows for lot of complex inferences, and they will be a major part of common sense reasoning
as we continue with this course.


08 - Properties of Frames
-------------------------

.. image:: https://dl.dropbox.com/s/ay6xqawr08hm0qn/Screenshot%202016-02-12%2022.14.04.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/for9terhco6juwf/Screenshot%202016-02-12%2022.15.06.png
   :align: center
   :height: 300
   :width: 450

>> David, that is a very good point, in fact there is a history to it.


Frames and object relevant programming came about the same time in the 1960s and the 1970s. And I'm sure they influenced
each other in both directions.

09 - Exercise Interpeting a Frame System
----------------------------------------

.. image:: https://dl.dropbox.com/s/mrw4iq6mt98vmjj/Screenshot%202016-02-12%2022.16.34.png
   :align: center
   :height: 300
   :width: 450

Let us do an exercise together. Imagine that there is a set of frames here that is capturing a conceptual knowledge.


What sentences is expressed by these frames?


10 - Exercise Interpeting a Frame System
----------------------------------------

>> That's good, David. But here's something interesting to note.


It could have been that this was the input sentence and that this frame representation got constructed from this input
sentence. So


Haruto became the subject and the person and ate became the verb and so on. Alternately, this could have been the frame
representation and perhaps the sentence which error gets through language generation from this frame representation. So
the frame representation could potentially act as an intermediate representation for both sentence comprehension and for
sentence generation. Of course, there's a lot more to sentence generation and to sentence comprehension than what we
have shown so far.


11 - Frames and Semantic Nets
-----------------------------

.. image:: https://dl.dropbox.com/s/gftrliwla9ed2ue/Screenshot%202016-02-12%2022.19.16.png
   :align: center
   :height: 300
   :width: 450

.. image:: https://dl.dropbox.com/s/xa5u5rnzdeai0ya/Screenshot%202016-02-12%2022.20.24.png
   :align: center
   :height: 300
   :width: 450


We can also use frames to address the Raven's Matrices problems that we have been talking about all throughout this
course. In fact as we do so we'll note another interesting fact, frames in semantic networks are closely related. So
let's do this problem. Here is a particular image and here is a semantic network for this particular image that we had
come across earlier. I could rewrite this semantic network in the language of frames. But, first of all building a frame
for each of these specific objects.


I have frame for x, a frame for y and a frame for z. So, here are the frames for the three objects, x, y and z. Let's
look at the frame for z in more detail for just a second. So, here are the slots, the name is z, the shape is a circle
the size is small and it is filled, you can see it here.


We can also capture the relationship between these two objects. So let's consider a relationship example. Here y is
inside x, y is inside x.


We can capture that through this slot for the object y. Here is the slot for inside, for the object y, and it is
pointing to x, indicating that y is inside x. Note again the equivalence between the semantic network and the frame
representations. The three objects and the three frames corresponding to three objects. The relationship between the
objects and the relationships being captured by these blue lines here between the frames.


While we can capture relationships between frames through lines like this where one frame points to another frame, we
could also capture them more directly by actually specifying variables of other frame names. So for example, for the
frame y, we might say, inside x which captures the same idea that we were capturing by drawing a line between them. In
fact, this is a notation we'll use with the rest of the exercises in this lesson.


12 - Exercise Frames and Semantic Networks
------------------------------------------

.. image:: https://dl.dropbox.com/s/jqran96hr27a8jh/Screenshot%202016-02-12%2022.21.08.png
   :align: center
   :height: 300
   :width: 450

Let us do an exercise together to make sure that we understand frame representations for images like this. So consider
the image shown here on the top left.


Can you write down all the slots and the fillers for these three frames?


13 - Exercise Frames and Semantic Networks
------------------------------------------

>> Good David, that sounds right to me.


14 - Frames and Production Systems
----------------------------------

.. image:: https://dl.dropbox.com/s/bmr2a1lez521j67/Screenshot%202016-02-12%2022.23.17.png
   :align: center
   :height: 300
   :width: 450

We have actually come across the notion of frames earlier, when we were talking about production systems.


You may recall we had a diagram like this, where we had procedural, semantic and episodic knowledge, and the working
memory container structure like this.


You can see this is really a frame, here are the slots, here are the values for the slots. We can think of these frames
as capturing conceptual knowledge, that is stored in the semantic memory. So let's take an example.


Suppose an input is a shark ate a frog. Remember the word ate there, and that verb ate gets returned to working memory,
and the entire frame for ate gets pulled out. Once this frame is pulled out of semantic memory, it immediately generates
expectations. So we now know, that ate is likely to have a subject, an object and location, perhaps time utensils and so
on. So we can ask ourselves the question, well what will go, under subject here?


What will go under object here? And in the sentence a shark ate a frog.


This frame tells us, what to look for. As a result of which, the processing is not just bottom up, coming from natural
language or the world in general, and going into mind. Also, mind provides knowledge structures like frames, which,
structured knowledge representations, which generate expectations and make the processing, partially top down.


15 - Exercise Frames  Complex Understanding
-------------------------------------------

.. image:: https://dl.dropbox.com/s/3q18bngba1pla6i/Screenshot%202016-02-12%2022.24.14.png
   :align: center
   :height: 300
   :width: 450

To see both the power and the limitations of the frame knowledge representation, let's do an exercise together. So,
please read the story.


The story is talking about an earthquake. And then fill out the slots and the fillers that you might think might go with
the frame of earthquake.


16 - Exercise Frames  Complex Understanding
-------------------------------------------

.. image:: https://dl.dropbox.com/s/qc3esfl25g2g3bc/Screenshot%202016-02-12%2022.25.48.png
   :align: center
   :height: 300
   :width: 450



>> Or, if you're interested in reading more about this now, you can go ahead and go watch those lessons.


17 - Assignment Frames
----------------------

.. image:: https://dl.dropbox.com/s/erbl9vaztquee1h/Screenshot%202016-02-12%2022.26.27.png
   :align: center
   :height: 300
   :width: 450



For this assignment, discuss how you'd use frames to represent Raven's Progressive Matrices. At a basic level, what are
the slots and fillers associated with different Raven's problems? Where are these frames going to come from? Is the
agent going to receive the problem in terms of frames initially, or it going to generate these frames based on its own
reasoning?


Once it has these frames, what exactly are the reasoning methods it's going to use to solve the problem based on these
frames?


We've also talked about frames representing individual figures from the problem.


But what about a frame representing the problem, as a whole? What about a frame representing individual shapes within
figures?


How would representing the problems at that different level of abstraction, help the agents solve the problem more
easily.


What are frames going to enable us to do, that we couldn't do otherwise?


18 - Wrap Up
------------

.. image:: https://dl.dropbox.com/s/pwzxdjhgfze1v4m/Screenshot%202016-02-12%2022.27.52.png
   :align: center
   :height: 300
   :width: 450



So, today we discussed frames, which are one of the knowledge representations that we'll see throughout this course. We
started off by talking about the basic structure of frames which involves slots and fillers, and we talked about how
similar they are to the variables and values that we see in object-oriented programming. We then talked about the three
main properties of frames which are that they represent stereotypes of a certain concept, they provide default values,
and they can inherit from one another. We then talked about frames in terms of other concepts we've already covered in
this course.


We talked about how frames are representationally equivalent to semantic nets, and we've talked about how frames were
actually what we were using when we were doing projection systems last lesson. We finally talked about some of the
advanced reasoning and story understanding that we can do with frames.


Now we're going to move to a topic called learning by recording cases, where we learn from individual cases or
individual experiences. But if you're very interested in frames, you might want to jump forward to our lessons on
understanding common sense reasoning and scripts.


This will all very heavily leverage what we've learned about frames today


19 - The Cognitive Connection
-----------------------------

Frames are typical character of human cognition. Let us consider three specific ways. First, frames are a structured
knowledge representation.


We can think of production systems as being atoms of knowledge representation, and frames as being molecules of
knowledge representation.


A production rule captures a very small amount of information. A frame can capture a large amount of information in
organized manner as a packet.


Second, frames enable me to construct a theory of cognitive possessing which is not entirely bottom-up, but is partially
top-down. I have to see a lot of data from the world. But not all of the cognitive processing is bottom-up. The data
results in the retrieval of information from my memory. That information, that knowledge in the form of frames then help
to make sense of the data.


It has been generating expectations of the world.


So then the processing becomes not just bottom-up, but also top-down. Third, frames capture the notion of stereotypes.
Stereotypes of situations, stereotypes of events. Now, stereotypes can sometimes lead us to incorrect inferences. Yet
you and I have stereotypes of whereas kind of events and situations. So why do we have state effects, because they're
cognitively efficient. And why are they cognitively efficient? Because instead of reasoning about the world anew each
time, they already have default values associated with them.


That's the property of frame. All the default values then, enable me to generate certain number of expectations very
rapidly.


That's cognitively efficient. Here are three formative connections between frames and human cognition. There are a lot
more that we'll get into slowly.


20 - Final Quiz
---------------

.. image:: https://dl.dropbox.com/s/zk8g9v6gn0qw1x4/Screenshot%202016-02-12%2022.30.22.png
   :align: center
   :height: 300
   :width: 450

Please fill out what you learned in this lesson in this box.


21 - Final Quiz
---------------

Great. Thank you very much.


