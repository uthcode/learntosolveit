.. title: 04 - Generate & Test 
.. slug: 04 - Generate & Test 
.. date: 2016-01-23 06:35:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

====================
04 - Generate & Test
====================

01 - Preview
------------

.. image:: https://dl.dropbox.com/s/bkfnazcgmotmw1l/Screenshot%202016-02-12%2009.10.28.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/z2d24ajfuq79z0x/Screenshot%202016-02-12%2009.11.39.png
   :align: center
   :height: 300
   :width: 450

Today, we'll talk about a very general method called generate and test. We have looked at knowledge representations like
semantic networks.

We'll shift our attention now to problem solving methods. Generate and test is a problem solving method. This is another
item in our fundamental topics part of the course. The generate and test method in a way, is very simple. Given a
problem, generate potential solutions to it, and then test the solutions for the efficiency for addressing the problem.
If you had complete knowledge of the world, complete and correct knowledge of the world. If you had infinite
computational resources. And if you had a method of reasoning that was guaranteed to be correct, then you can generate
the correct, the optimal solution.


You don't need to test it. In general however, you do not have complete or correct knowledge of the world. You do not
have infinite computational resources, and not all methods are guaranteed to be correct. In that case, you can generate
potential solutions. Plausible solutions, and then test them. Estimates that will generate, and test. We will use this
method in conjunction with semantic networks, or the prisoners and guards problem that we discussed last time.


02 - Guards and Prisoners
-------------------------

.. image:: https://dl.dropbox.com/s/8sbamw63563dt7m/Screenshot%202016-02-12%2009.13.15.png
   :align: center
   :height: 300
   :width: 450


Knowledge-based AI is a collection of three things.


Knowledge representations, problem solving techniques and architectures.


We have already look at one knowledge representation, semantic networks.


We have not so far looked at problem solving methods or architectures.


Today, I'd like to start by talking about the problem solving method.


Let us illustrate the problem solving method of generate and test with the same examples that we have discussed earlier.
When we were discussing this example in the case of semantic networks, we simply came up with various states and pruned
some of them without saying about how an AI agent would know what states to prune. So imagine that we have a generator
that takes the initial state and from that initial or current state, generates all the possible successive states. For
now, imagine it's not a very smart generator, it's a dumb generator.


So it generates all the possible states. So the generator test method not only has a generator but also has a tester.
The tester looks at all the possible states the generator has generated and removes some of them. For now, let's also
assume that the tester is is dumb as well. And so the tester is removes only those states that are are clearly illegal
based on the specific of the problem.


Namely, that one cannot have more prisoners than guards on either back.


So the first and the third states are removed by the tester.


03 - Exercise Generate and Test I
---------------------------------

.. image:: https://dl.dropbox.com/s/2e0gtj8y7ya15yn/Screenshot%202016-02-12%2018.42.47.png
   :align: center
   :height: 300
   :width: 450

Let us continue with this exercise one step further. So now we have three successor states to the initial state. Given
these three successor states, what states might the dumb generator generate next?


04 - Exercise Generate and Test I
---------------------------------

.. image:: https://dl.dropbox.com/s/u4w81zr0fx4vus5/Screenshot%202016-02-12%2018.43.21.png
   :align: center
   :height: 300
   :width: 450

>> So from the top state we have three possible next states.


We can move both of them, we can move just the prisoner, or we can move just the guard. From this one we can either move
one prisoner or two prisoners, and from this one all we can really do is move the prisoner back over to the left.
Remember that David is not generating these successive states.


David is saying that the DOM generator will generate the successive states.


05 - Exercise Generate and Test II
----------------------------------

.. image:: https://dl.dropbox.com/s/59symczlik592y7/Screenshot%202016-02-12%2018.44.24.png
   :align: center
   :height: 300
   :width: 450

So now that we have all of these states that the generator has generated, given that we have a dump tester what states
will the dump tester dismiss?


06 - Exercise Generate and Test II
----------------------------------

.. image:: https://dl.dropbox.com/s/22w7nde94a66x43/Screenshot%202016-02-12%2018.45.12.png
   :align: center
   :height: 300
   :width: 450



>> So the only one of these six states that disobeys our one rule against having more prisoners than guards on either
shore, is this state over here. So, that's the only state that's going to get thrown out. These five states are all
legal according to our dumb testers understanding of the problem. So after we dismiss that state, though. We'll notice
that we only have two unique states, we have everyone on the left coast and one prisoner on the right coast. So like we
did earlier, we can collapse these two down into only these two states.


It won't matter how we got there, once we're there.


07 - Dumb Generators, Dumb Testers
----------------------------------

.. image:: https://dl.dropbox.com/s/ppdy1vlboal85xo/Screenshot%202016-02-12%2018.46.00.png
   :align: center
   :height: 300
   :width: 450

Now we can continue to apply this method of generate and test iteratively. So we can apply it on this state and that
state and see what successor states we get.


If we do so, then we get a very large number of successor states. This is a problem of call many total explosion. While
one was tasked with a small number of states, but the number of successor states keeps on increasing very rapidly.


Now, the reason it is occurring here and it did not occur when we are talk, dealing with semantic networks is because
here we have states like this one which have three guards and three prisoners on the same side of the bank, exactly the
same state that was the initial state to begin with. This is because we have a dumb generator and a dumb tester. So this
state never got pruned away, although this particular state is identical to the initial state that we started from. This
method of generating test, even with a dumb generator and a dumb tester, if applied iteratively could finally lead to
the goal state.


In which case, we will have a path from the initial state all the way to the goal state, but this will be
computationally very inefficient.


This is because we have a dumb generator and a dumb tester. So the question now becomes, can we make a smarter generator
and a smarter tester? Before we make a smarter generator and a smarter tester, we should note that generate and test is
a very powerful problem solving method.


08 - Smart Testers
------------------

.. image:: https://dl.dropbox.com/s/h6oaserxk1qv4rj/Screenshot%202016-02-12%2018.53.17.png
   :align: center
   :height: 300
   :width: 450


.. image:: https://dl.dropbox.com/s/gc2fdbz8pob9cul/Screenshot%202016-02-12%2018.57.06.png
   :align: center
   :height: 300
   :width: 450

So suppose that we have a smarter tester, a tester which can detect when any state is identical to a previously visited
state. In that case the tester may decide that this, this, and this state are identical to the initial state and
therefore dismiss them. The tester also dismisses this state, as usual, because of the problem specification that one
cannot have more prisoners than guards on any one bank. This leaves the following state of affairs.


Note also that this particular state has no successor states, all successor states of this have been ruled out.
Therefore this particular part clearly is not a good path to get to the gold state. If we notice also, that these two
states are identical, then we can merge them. If we do so, then we get exactly the same kind of configuration of states
that we had when we were dealing with the semantic network in the previous lesson. There is something to note here. We
had this semantic network in the last lesson, but the knowledge representation of semantics network, while very useful,
by itself and of itself doesn't solve any problems.


You need a problem solving method that uses knowledge afforded by the knowledge representation to actually do the
problem solving. Generating test is one of those problem solving methods. In general, when we do problem solving or
reasoning, then there is a coupling between a knowledge representation and a problem solving method, like semantic
networks and generating test.


What we did so far had a dumb generator, but we made the testers smarter.


The testers started looking for what states had been repeated.


Alternatively we can shift the balance of responsibility between them and make the generator smarter. Let's see how that
might happen.


09 - Smart Generators
---------------------

.. image:: https://dl.dropbox.com/s/imr5a7qmd7mhmzx/Screenshot%202016-02-12%2019.00.14.png
   :align: center
   :height: 300
   :width: 450

Instead of the generator generating all the successive states and then a tester finding out that this state, this state
and this state are identical to the initial state. One could make the generator itself smarter and say that a generator
will not even generate these three states, but it will know that it should not generate states that are already up here.


This means that we can either provide the generator with some additional abilities or the tester with some additional
abilities or both. If the generator was smarter, then it would not even generate these three states because they are
nonproductive. I would exclude maybe the tester, the determinant of this state is illegal and therefore dismisses it.


We could even go one step further and make the generator even smarter, so the generator will not generate this
particular state. And thus, the balance within the generator and the tester can shift depending on where we try to put
knowledge. For this problem, for this relatively simple and small problem, the balance will responsibility between the
generator and test might look like a tree relationship. But imagine a problem in if there are a million such states.
Then whether we have generated very smart or the tests are very smart or both can become a important issue. Despite
that, genetic testing factors are a very popular method used in some schools of AI.


Genetic algorithms, for instance, can be viewed as genetic [INAUDIBLE].


Given a number of states, they try to find out all the potential successive states that are possible, given some simple
rules of recombination. And then of a fitness function that acts as a tester. Genetic algorithms, therefore, are an
effective method for a very large number of problems.


They're also a very inefficient method because neither the generator nor the testing generator algorithms are especially
smart.


10 - Discussion Smart Generators and Testers
--------------------------------------------

.. image:: https://dl.dropbox.com/s/sa7ibcum7s43rn7/Screenshot%202016-02-12%2019.01.41.png
   :align: center
   :height: 300
   :width: 450

>> What does everyone else think? Is David right about this?


11 - Discussion Smart Generators and Testers
--------------------------------------------

.. image:: https://dl.dropbox.com/s/v0z6auyrls3sc4g/Screenshot%202016-02-12%2019.02.25.png
   :align: center
   :height: 300
   :width: 450

>> That sounds like a good answer, to me. So once again, we are back to the issue of where do we draw the balance of
responsibility between the generator and the tester?


The important thing to note from here however is that generation test when in doubt with the right kind of knowledge can
be a powerful method.


12 - Generate  Test for Ravens Problems
---------------------------------------

.. image:: https://dl.dropbox.com/s/9ss6zu6gybi09j0/Screenshot%202016-02-12%2019.03.10.png
   :align: center
   :height: 300
   :width: 450

Let us return to our problem from the intelligence test to see how generate and test might apply as a problem solving
method. Again, here is a problem that we encountered earlier. Notice that this is a more complicated problem than the
guards and prisoners problem. Here is why. In case of the guards and prisoner problem, each transformation from one
state to another, was a discrete transformation. One could take a certain number of guards to the other side. One could
take a certain number of prisoners to the other side, or one could take a certain of number of guards and prisoners to
the other side.


In this case, if I look at the approximation between A and B, and I notice that the diamond inside the circle is now
outside the circle and is larger. Now suppose I were to try the same transformation from C to D. So I can look at the
circle inside the triangle, put it outside, and also make it larger. I notice that when I put it outside,


I can put it outside right next to the triangle, a little bit farther, a little bit farther, a little bit farther away.
I can make it the same size, or a little larger, or a lot larger. Increase its size by 50% or 51% or 52%.


So this space of possibilities here is very large. So for problems of this kind, the need for a smarter generator and a
smarter tester is critical, because this space of possibilities can become very large, very quickly.


13 - Semantic Networks for Generate and Test
--------------------------------------------

.. image:: https://dl.dropbox.com/s/g1mw5gp2bcz2zov/Screenshot%202016-02-12%2019.04.11.png
   :align: center
   :height: 300
   :width: 450

This is where the knowledge representation helps a lot.  The semantic network knowledge representation provides a level
of  abstraction at which the problem gets represented and analyzed.  So, although this particular diamond y could have
been displaced here or  a little bit further, it could have been of this size, maybe a little smaller,  a little bit
larger.  The semantic network really doesn't care about it.  With the level of extraction which a semantic network is
dealing,  y gets expanded, and that is all that matters.  An important point to note here is that any knowledge
representation  picks a level of extraction at which it represents the world.  There's a lot of power in it because that
knowledge  representation ignores things that are at a low level of detail.  And therefore the problem-solving method
doesn't have to worry  about those things.  So it is not the knowledge representation alone  that solves the problem, or
the problem solving method that solves the problem.  It is the knowledge representation and the problem solving method
coupled together that solve the problem, that provide the reasoning.


14 - Generate  Test for Ravens Problems II
------------------------------------------

.. image:: https://dl.dropbox.com/s/6gsnncfc7jqrrfw/Screenshot%202016-02-12%2019.05.14.png
   :align: center
   :height: 300
   :width: 450

>> So let's assume that we're using[br]semantic network as a representation for this particular class of problem.


Given that, how would you apply generate[br]and matter to this problem, David?


>> So it sounds like would[br]I would do is I would use the transformation between A and B,[br]transfer that
transformation to C and use it to generate my answer for D.


I then take my answer for D and compare[br]it against 1, 2, 3, 4, 5 and 6 and see which one most closely[br]matched what
I generated.


If I wanted to make my tester and[br]generator even smarter,


I might say that in order[br]to be the correct answer, it has to meet the generated answer[br]with a certain level of
confidence.


And if it doesn't meet that level of[br]confidence, it should go back and see if there's a different
transformation[br]we could have transferred.


That would take care of the problem[br]earlier where either the middle shape disappeared or[br]the outer shape
disappeared.


>> That's a good answer, David.


It is another way of[br]solving this problem.


It is another way of solving[br]this problem using test and semantic networks.


One could take one, put it under D.


Generate the transformation[br]from C to D and then test it against[br]the transformation from A to B.


One could do the same thing with 2,[br]put 2 here into D, directly transformation tested[br]against the transformation A
to B.


One could do this for[br]all six choices and then find out, which one of these transformations is closest[br]with the
transformation from A to B.


Thus, in this problem, one can use[br][INAUDIBLE] test methods in two very different ways, all of the
knowledge[br]representation ribbon is the same.


So knowledge representation captures[br]some knowledge about the world at a level of abstraction.


It is coupled with problem[br]solving methods, but more than one problem solving method,[br]more than one variation of a
problem solving method might be applicable[br]using technology representation.


15 - Assignment Generate  Test
------------------------------

.. image:: https://dl.dropbox.com/s/jof05l0jlalrcvl/Screenshot%202016-02-12%2019.07.07.png
   :align: center
   :height: 300
   :width: 450

So how would you use generate and test to actually solve[br]Raven's Progressive Matrices?


We've talked about this[br]a little bit already, but take it a little bit further and talk[br]about how you would
actually implement the problem solving[br]approach you've seen today.


We talked about a couple[br]different ways of going about it.


We talked about generating[br]multiple answers and testing them against the answer options.


Or generating one answer and testing it more intelligently against[br]the different options available to you.


So talk about which one you would do and[br]how you would actually implement it.


In doing so, make sure to think of[br]three by three problems as well.


With more transformations and[br]more figures going on, it can be a lot more difficult[br]to figure out what to
generate, and the problem space can[br]explode very quickly.


Also make sure to think about how you're[br]actually going to infer the mapping between different[br]figures in the
problem.


How do you know which shape in[br]one frame maps up to a different shape in another frame?


And then talk about how you[br]would use that information to generate what you[br]think the answer is.


16 - Wrap Up
------------

.. image:: https://dl.dropbox.com/s/ewsxgi40r81bvxs/Screenshot%202016-02-12%2019.08.14.png
   :align: center
   :height: 300
   :width: 450

Let's wrap up our topic for today.


So today,[br]we've talked about generate and test, which is a very general purpose[br]problem solving method.


As Ashok mentioned earlier in[br]our lesson, we see generate and test every day in our regular lives and it's something
in which[br]we engage very naturally.


We talked about strong generators and[br]strong testers and how we can build intelligence into one[br]side or the other
in order to make the problem solving process easier and[br]more efficient.


We also talked about how generating[br]tests is more difficult and unconstrained domains and[br]how our generator and
tester need to be equipped with special kinds of knowledge[br]in order to make this problem solvable.


Next, we're going to be looking at two[br]different problem solving methods that build on what we've seen[br]today with
generate and test.


Means and analysis and[br]problem reduction.


Like generate and test, these are both[br]very general purpose, but they're going to do things a little bit
differently[br]and make certain problems easier.


17 - The Cognitive Connection
-----------------------------

Let us examine the relationship[br]between the method of generate and test, and human cognition.


Humans use generate and test as[br]the problem-solving method all the time.


This is because we do not have complete[br]or correct knowledge of the world.


We do not have infinite[br]computational resources.


And we also do not always have[br]recourse to a method of reasoning that is guaranteed to be correct.


When you do not have these things,[br]then you use your own test method.


You come up with particular solutions to[br]a problem, you test the solutions out.


Beyond human cognition,


I'm sure you've come across[br]the notion of genetic algorithms.


Genetic algorithms are inspired by[br]the processes of biological evolution.


Through operations like crossover and[br]mutation, one can generate solutions that can then[br]be tested against some
fitness function.


Genetic algorithm are a good example[br]of the genetical test method.


First, genetic solutions,[br]then test them out.


So this method of generating test is[br]connected not only with human cognition, but dependently,[br]also with
biological evolution.


It's all over the place.


18 - Final Quiz
---------------

Once again, will you please complete[br]the quiz at the end of this lesson?


What did you learn in this lesson?


19 - Final Quiz
---------------

Great. Thank you so much for your feedback.


