.. title: 10 - Incremental Concept Learning 
.. slug: 10 - Incremental Concept Learning 
.. date: 2016-01-23 06:40:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

=================================
10 - Incremental Concept Learning
=================================


01 - Preview
------------

Today we'll talk about[br]incremental concept learning.


In case based reasoning,[br]we're storing new examples in memory.


Today we'll talk about how we can[br]abstract concepts out of those examples.


This is our second major[br]topic of learning.


We'll start with the learning goal.


Then we'll talk about very near spaces[br]of learning like variabilization, specialization, and generalization.


We'll also talk about heuristics for[br]specializing and generalizing concepts as[br]examples come in incrementally.


02 - Exercise Identifying a Foo I
---------------------------------

Let us try to do a problem together on incremental concept learning.


I'm going to give you a series of examples, and we will see what kind of concept one can learn from it. I'll not tell
you what the concept really is, for the time being I'm just going to call it foo. Here is the first example.


In this first example, there are four bricks. A brick at the bottom, horizontal brick at the bottom, or horizontal brick
at the top. And two vertical bricks on the side. Here is a second example. And this time I'll tell you that this
particular example is not a positive instance of the concept foo.


Once again, we have four bricks, a brick at the bottom, a brick at the top, and two bricks on the side. This time the
two bricks aren't touching each other.


Here's a third example of the concept foo. This is a positive example.


This is a foo. Again we have four blocks. This time they are two bricks, and instead of having two bricks, vertical
bricks, we have two cylinders.


They are not touching each other. So I showed you three examples of the concept foo. And I'm sure, you learned some
concept definition out of it.


Now I'm going to show you another example and ask you, does this example fit your current definition of concept foo,
what do you think?


03 - Exercise Identifying a Foo I
---------------------------------

>> And in coming up to this answer David used some background knowledge.


The background knowledge that he used was that the bricks that were in the vertical position in the first example, and
the cylinders that were in the vertical position in the third example, and the special blocks that are in the vertical
position in this example. Are all examples of something called a block. They can be replaced by each other. So instead
of having a brick, one could have a cylinder, or some other thing that's vertically placed here.


Now, someone else in the class may have a different background knowledge, and he or she may not consider this to be an
example of a block, in which case the answer might be no. The point here being that background knowledge is playing an
important role in deciding whether or not this is an example of foo.


04 - Exercise Identifying a Foo II
----------------------------------

Let's try another example. This time, again, there are four blocks. There are two bricks, at the bottom and the top. And
the two cylinders, both vertical, but they are touching each other.


Is this an example of the concept foo based on what we have learned so far?


05 - Exercise Identifying a Foo II
----------------------------------

>> Once again, David, is using his background knowledge.


In his background knowledge he says that the bricks are like the cylinders.


The vertical bricks are like the vertical cylinders. So, what holds for the vertical bricks, they must not be touching,
also holds for the vertical cylinders. They too must not be touching. Again, someone else may have a different
background knowledge and may come up with a different answer.


06 - Exercise Identifying a Foo III
-----------------------------------

Lets try one last example in this series. So, in this example, there are four blocks again. There are three bricks at
the bottom and two on the side, not touching each other. And there is a wedge this time at the top, not a brick. Is this
an example of the concept foo?


07 - Exercise Identifying a Foo III
-----------------------------------

>> So to give this answer, David again uses background knowledge.


Someone else in the class might say that, well, he does not think that this particular wedge here is the same kind of
block as the brick. And therefore this is not an example of foo. So I want to draw a number of lessons from this
particular exercise. First, learning is often incremental.


We learn from one example at a time. Cognitive agents, human beings, intelligent agents in general, are not always given
hundreds or thousands or millions of examples right from the beginning. We get one example at a time.


Second, often the examples that we get, are labeled.


There is a teacher which tells us this a positive example, or this is a negative example. This is called supervised
learning in machine learning literature.


Because here there is a teacher which has labeled all the examples for you. Third, the examples can come in a particular
order.


There are always some positive examples, always some negative examples.


The first example, typically is a positive example. Fourth, this is quite different from case based reasoning. In case
based reasoning, which we had discussed last time, we had all of these examples, which we stored in their raw form in
memory. We'll reuse them. I this particular case, however, we're abstracting concepts from there. Fifth, the number of
examples from which we're extracting concepts is very small. We're not talking here about millions of examples from
which we're doing the abstraction.


Sixth, when we are trying to abstract concepts from examples, then, what exactly to abstract? What exactly, to learn?
What exactly to generalize, becomes a very hard problem. There is a tendency to often overgeneralize, or often, to
overspecialize. How does the intelligent agent find out, exactly what is [UNKNOWN] generalization? These are hard
questions, and we'll look at some of these questions in just a minute.


08 - Incremental Concept Learning
---------------------------------

>> That's good, David. It connects things with our everyday lives.


09 - Variabilization
--------------------

Let us look at the algorithm for incremental concept learning more systematical in more detail. This time, imagine that
there is an AI program, and there is a teacher which is going to teach the AI program about the concept of an arch.


So teaching this first example and suppose the teacher gives the example which has four bricks in it. Two vertical
bricks that are not touching each other and there is a third brick on top of it and a fourth brick on top of it. To the
AI program, the input may look a little bit like this, there are four bricks, A, B,


C and D. And there are some relationships between these four blocks. So brick C is on left of brick D. Brick C supports
brick B. Brick D supports brick B as well, and brick B supports brick A. This then is the input.


What may the error program learn from this one, single example?


Not very much. For this one single example, the AI program can only variablize.


There were these constants here, brick A, brick B, brick C, brick D.


Instead, the AI program may be able to variablize these constants and say, well, brick A is an instance of brick, and
therefore, I just have brick here.


Brick B is an instance of a brick. Therefore, I'll just have a brick here. So now, I can have any brick in these spaces
as long as these relationships hold, it's an example of an arch. Note the first example was the positive example.


Now we are going to see a series of positive and negative examples, and each time we see an example, the AI program will
either generalize or specialize. If it sees a positive example, then it may generalize, if the positive example is not
covered by a current concept definition.


If it sees a negative example, it may specialize the current definition of the concept to exclude that negative example.


10 - Generalization to Ignore Features
--------------------------------------

Now suppose that the teacher gives the error program this example as the second example, and the teacher also tells the
error program this is a positive example, so these are labeled examples. Here's a representation of the second example.
Again, I have done the variabilization, so the constant here, Brick A, has been replaced by Brick. This was the current
concept definition of the AI program for the concept of arch. And here is a new example.


How should the AI programmer revise its current concept definition of an arch in order to accommodate this positive
example? Because it is a positive example, therefore the AI program should try to generalize. So one good way of
generalizing the current concept definition is to drop this link.


If the AI program can drop this link, in that case this will be the new current concept definition. Note that this
current concept definition covers both the second example, as well as the first example.


This is called the drop-link heuristic. It's a heuristic because as we discussed earlier, a heuristic is a rule of
thumb. So here is what has happened.


When an AI program needs to learn from a very small set of examples, just one example or two examples, then the possible
generalizations and specializations, the learning space, is potentially very large.


In order to guide the AI program about how to navigate the learning space, we'll develop some heuristics. The first such
heuristic is drop a link if you need to generalize in such a way that the new concept can cover both earlier examples.


So drop-link heuristic is useful when the structure of the current concept definition and the structure of the new
example have a lot of overlap.


They overlap almost exactly, except for one link that is extra in the current concept definition. The extra link can be
dropped because in the new definition will cover both the previous concept as well as the new example.


11 - Specialization to Require Features
---------------------------------------

So here now is the, current concept definition of arch that the AI program has.


Now, the teacher shows a new example, here is the new example shown. There are three bricks, but the third brick here,
is not on top of the first two.


This is the input to the AI program with a third example. And the teacher tells, the AI program that this is not a
positive example of an arch. So here is a current concept definition. Here is a representation of the input example, and
information that this is a negative instance of the example.


What may the AI program learn from it?


The AI program must refine it's current definition of the arch, in such a way that the, new negative example is ruled
out. But how can we do that? One way of doing that is to say, that, we will put extra conditions on these links.


These support links must be there. These are not optional. We'll call it, the require-link heuristic. This require-link
heuristic says that, if the structure of the presentation of the concept and is structure of the representation of the,
negative example have some things in common.


But there are also some differences. Then revise the current definition, in such a way that, those things that are not
in common become, must be required.


12 - Specialization to Exclude Features
---------------------------------------

Let us continue this exercise a little bit further.


Imagine that the teacher gives this as a third example to the AI program.


This time again you have three bricks, but the two vertical bricks are touching each other. So here is a representation
of this input example.


Three bricks, the two vertical bricks are supporting this brick at the top, however, the two bricks are touching each
other. Recall, this is the current concept definition that the AI program has. It mus support links here.


And here is the representation of the new example. And the AI program knows that this is a negative example. How might
the AI program refine or specialize this particular current definition, so that this negative example is excluded? Well,
AI program may say that the current definition can be devised in such a way that for these two bricks, where one is left
of the other one, these two bricks cannot touch each other. This particular symbol means not.


So it is saying that this brick does not touch that one. And we have bi-datashield links. Because this one cannot touch
the other one, and that one cannot touch this one. This is called a forbid-link heuristic. So, here some particular
link, in this particular case touches, is being forbidden.


13 - Generalization to Abstract Features
----------------------------------------

Now let us look at examples that are even more interesting than previously.


Recall that earlier we were talking about background knowledge.


Let's see what role background knowledge plays more explicitly. So imagine this is the fourth example that the teacher
gives to the AI program, and this is a positive example. So the AI program may have this as the input representation.
There are two bricks, this brick is left of the other brick, there's a wedge on top, the two bricks are supporting the
wedge. So now the AI program has this as the current definition, recall the not touches links here, and this is the new
example. And this is the positive example. How may the AI program revise its current concept definition to include this
positive example?


Well the simplest in the AI program I do is to replace this brick here, in the current concept definition by brick or
wedge. So that makes sure that a new example is included in the definition of the concept.


We'll call this the enlarge-set heuristic. This particular set here, which had only brick here as an element, now has
two elements in it; brick or wedge.


14 - Generalization with Background Knowledge
---------------------------------------------

>> Good connection David.


15 - An Alternative Visualization
---------------------------------

I hope that algorithm for incremental concept learning makes sense to you.


Here is another way of visualization that algorithm.


Imagine that an AI agent was given a positive example and the AI agent may come up with a concept definition that covers
that positive example.


Now let us suppose that the AI agent is given a negative example, and this negative example is covered by the current
concept definition. Well in that case the current concept definition must be refined in such a way that the negative
example is excluded, while still including the positive example. So you can visualize a new concept definition which
includes the positive example, but excludes the negative example. Now let us suppose that the AI agent is given another
positive example, in which case the AI agent must revise its definition of the concept so that the new positive example
is also included so that's also covered. So we may revise this concept definition something like this. And we can repeat
this exercise many times. Imagine there is a negative example and the current concept definition covers it.


Well, we can refine it in such a way that a new negative example is excluded and so on. We can imagine going through
several of these iterations of positive and negative examples. Eventually we'll get a concept definition that includes,
that covers all the positive examples, and excludes all the negative examples.


So again, the problem is the same. Given a small set of positive and negative examples, the number of dimensions in
which the algorithm can do generalization and specialization is very large.


How do, how do we constrain the learning in this complex learning space?


That's where those [UNKNOWN] and background knowledge come in.


The [UNKNOWN] guide the algorithm so that it revises the concept definition in an efficient manner and the background
knowledge helps in that process.


16 - Heuristics for Concept Learning
------------------------------------

Here is a summary of the kind of Heuristics that an AI agent might use in criminal concept learning. You only come
across five of them, require-link, forbid-link, drop-link, enlarge-set and climb-tree. Here is another one called close-
interval, let's look at it briefly.


Let's go to David's example of a child having a dog and suppose that child has only come across dogs that were very
small in size.


Now the child comes across a large dog. In that case the child might change the concept definition, expand the range of
values that the dog can take, that dog size can take so that the larger dog can be included. So the difference here
being that it's values can be continuous like size of a dog and sort of indiscreet as in the other hero sticks


17 - Exercise Re-Identifying a Foo I
------------------------------------

Let us do a series of exercises together. This time, the concept that the AI agent is going to learn about,


I'll call it foo. Here is a first example the teacher gives to the AI program.


All right, because there is only one example the only kind of learning that can occur here is variabilization. What do
you think will be the values that can go in these boxes here that will variabalize these four bricks.


Initially, they are brick one, brick two, brick three, brick four.


18 - Exercise Re-Identifying a Foo I
------------------------------------

>> So initially we're given labels for these individual bricks. They're brick one, brick two, brick three, brick four.
We're going to abstract over them and say that they're all just instances of bricks.


So our four things in this concept are bricks.


19 - Exercise Re-Identifying Foo II
-----------------------------------

So how would we reflect the relationship with the concepts on the right?


20 - Exercise Re-Identifying Foo II
-----------------------------------

>> Now we'll give you some more examples, some positive, some negative, and we'll ask you how the AI agent can go about
refining its concept definition.


21 - Exercise Re-Identifying Foo III
------------------------------------

So let us suppose that the teacher gives this as a second example of the air program. And labels it as a negative
instance of the concept, foo. How could the agent refine its current concept definition in order to exclude this
negative example?


22 - Exercise Re-Identifying Foo III
------------------------------------

>> Good job, David.


23 - Exercise Re-Identifying Foo IV
-----------------------------------

Here is the next example.


This is a positive example. How would the current definition be refined?


24 - Exercise Re-Identifying Foo IV
-----------------------------------

>> That looks good to me, David. And you are right.


While humans may have a lot of background knowledge, we have not yet ascribed any background knowledge to the AI agent.
So the AI agent might be able to simply say brick or cylinder and nothing more than that


25 - Exercise Re-Identifying Foo V
----------------------------------

With this next example, suppose that the AI agent does have some background knowledge which tells it that brick and
cylinders are both both sub classes of blocks.


In that case, how might the AI program refine this current concept definition?


26 - Exercise Re-Identifying Foo V
----------------------------------

>> That's good, David. Notice here the important role that knowledge is playing in learning. Once again, this is why
this particular method of incremental concept is part of analogous AI class because we are looking at the critical role
that knowledge plays in guiding the learning process.


What we learn at the end depends upon what type of knowledge we begin with.


27 - Exercise Re-Identifying Foo VI
-----------------------------------

Let us consider one last example in this series of examples.


Let us suppose the teacher gives this as the negative example of foo.


Note, negative example. How do think the AI agent may refine this concept to exclude this negative example?


28 - Exercise Re-Identifying Foo VI
-----------------------------------

>> Good. Very good. If the example is a negative instance and the current definition of the concept already excludes it,
we don't have to do anything.


29 - Final Concept of a Foo
---------------------------

So, given the input series of examples, and the background knowledge, this is the final concept definition for [UNKNOWN]
that this particular [UNKNOWN] agent will learn. Notice, that there are no must support lengths here, because input
[UNKNOWN] of examples did not require them.


Now it is also, that we did not generalize this bricks into something else, or further generalize these blocks into
something else, because there was no background knowledge to do that.


So the result of learning here, depends not just on the input examples, but on the background knowledge that the AI
agent has. This method of incremental concept learning differs quite a bit from some of these standard algorithms in
machine learning. Often in machine learning, the AI agent is a given a large number of examples to begin with and the
learning begins with those large number of examples where the number of examples could be in thousands or millions or
more. When you have a large number of examples to begin with, then one can apply statistical machine learning methods to
find patterns of regularity in the input data. But if the number of examples is very small, and if the examples come one
at a time, the learning is incremental.


Then it becomes harder to apply those statistical methods to detect patterns of the [INAUDIBLE] input data. Instead, in
that case, the algorithm must make use of its background knowledge to decide what to learn and how to learn it.


30 - Assignment Incremental Concept Learning
--------------------------------------------

So for this assignment, discuss how you[br]might use incremental concept learning to design an agent that can
solve[br]Raven's progressive matrices.


What are the concepts that you're[br]trying to learn in this case?


What are you incrementing over?


This might depend on[br]the scope of your problem.


So are you doing concept learning at[br]the level of the individual problem?


Or are you doing it between problems?


What concepts are you learning here and how are you actually[br]tweaking them over time?


What would a specific concept look like?


Or what would a general[br]concept look like?


Once you establish these concepts, how will actually help[br]you solve knew problems?


Or how are you going to[br]instantiate them or leverage them in new problems[br]that your agent faces?


31 - Wrap Up
------------

So today we've talked about[br]one particular method for doing what's called[br]incremental concept learning.


We started by talking about why we[br]need incremental concept learning.


We have instances in the world where we[br]encounter a limited number of examples.


We need to discern a concept[br]based on those limited examples.


So we start by variablizing our current[br]understanding to arrive at a more abstract notion of the concept.


Then based on new positive or negative[br]examples, we either generalize or specialize our understanding.


We talked about a few heuristics for[br]doing this, like the forbid link or require link heuristics.


That allow us to develop a better[br]concept based on new examples.


Next we'll talk about classification[br]where we leverage the concepts that we developed through[br]incremental concept
learning.


But we'll also revisit incremental[br]concept learning in some later lessons as well such as through version
spaces,[br]explanation based learning, and learning by correcting mistakes.


32 - The Cognitive Connection
-----------------------------

Incremental concept learning[br]is intimately connected with human cognition.


We can adopt two views of learning.


In one view of learning, the intelligent agent is given[br]with a large number of examples.


The agent's task, then, is to detect[br]patterns of regularity in those examples and learn those patterns of regularity.


In the alternative view, the agent[br]is given one example at a time.


And the agent has to gradually, incrementally learn concepts[br]out of those examples.


Now you and I as agents,[br]as cognitive agents in our daily lives, deal with one example at a time.


Rarely is it that we[br]encounter millions or hundreds of thousands of[br]examples given at once.


Incremental concept learning is[br]a lot closer than kind of learning that you and I as cognitive agents do.


33 - Final Quiz
---------------

So please write in this box once again what you learned from this particular lesson.


34 - Final Quiz
---------------

Great. Thank you very much.


