.. title: 19 - Version Spaces 
.. slug: 19 - Version Spaces 
.. date: 2016-01-23 06:49:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===================
19 - Version Spaces
===================

01 - Preview
------------

Today, we'll talk about generalization and learning, using the method of version spaces. The issue of generalization and
learning, is closely connected to the issue of incremental concept learning In both cases, there are small sort of
examples arriving one at a time. In incremental concept learning, we made use of background knowledge, In generalization
and learning, background knowledge may not be available. Similarly, in incremental concept learning, we control the
order in which the examples arrived, but in general, in generalization in learning, we may have no control over the
ordering of examples. Today, we'll start by defining version spaces, we'll talk about version spaces that has an
abstract technique.


Then we'll go into the algorithm for executing the technique of version spaces.


We'll also, towards the end, talk about an alternative method for organizing the examples into a decision tree, or an
identification tree.


This method is very similar to the method of incremental discrimination tree learning that we learned when we were
talking about case based reasoning


02 - Incremental Concept Learning Revisited
-------------------------------------------

Version spaces is a technique for learning concepts incrementally.


This means that a technique is going to learn from a small set of examples, that are going to arrive one example at a
time. Now we have come across a different notion of incremental concept learning earlier. In that technique, we started
with a current concept definition.


Then a new example will come about. In this case it's a negative example, not an arch. And then a new concept
characterization would be constructed, by revising the concept characterization that we began with. The revision was
such that, the new concept characterization was a specialization of the old concept characterization, such that that the
example got excluded. So, negative examples led to specialization, positive examples led to generalization, and the
ordering of these examples was important.


We want the first example to be a positive example of the concept that we learned. We want the order to include both
positive, and negative examples.


That technique was very useful when there was a teacher available, who would give you these examples in the right order.
Now, the order of examples was very important in that technique of incremental concept learning.


We want this set of examples to include both positive and negative examples, so that we can do generalization, and
specialization. And we want each example to differ from the previous concept characterization in only one important
feature.


In this case, the only important difference between the new example, and the current concept characterization is the two
bricks touch each other That, the new example, the first one, the current concept characterization in exactly one
feature, is important. Because it focuses the attention of the learner.


It tells the learner, how to do the specialization, or the generalization, so as to include the difference, or to
exclude the difference. This technique is very useful if we teachers have a label that can give the examples in a good
order, in the right order, so that effective learning can occur. In that technique of incremental concept learning. We
also consider the rule of background knowledge.


If the current concept characterization is brick, or wedge at the node, and the learner has background knowledge which
tells it that bricks, and wedges are examples of blocks, then the learner can generalize from brick, or wedge to a block
here. But now we can ask two questions. What happens if these two factors? The presence of a teacher who gives examples
in a particular order.


And the availability of this background knowledge tells the learner exactly how far the generalize. In general, in
learning, deciding how much to generalize.


Is a big problem. Learners tend to either over-journalize, in which case they come to incorrect answers. Or they tend to
under-journalize, in which case the answer might be correct but not very useful. If a child comes across a dog that is
hooligan, furry, black, and called Buddy, and the child decides that a dog by definition is.


Four legged, furry, black, and called Buddy. Then that is an example of under generalization. The conceptual
characterization is correct, but not very useful because we're not transfer to any other dog. On the other hand, if the
trial decides that all four legged, furry animals, are dogs, then it's an example of over generalization. Because it
could also include many cats.


So, the question now becomes what would happen if the examples did not come in the good order? They came in an arbitrary
order. And if this background knowledge was not available, in that case the agent would have a hard time deciding how
far to generalize. Versions places this technique that are in a certain conditions, allows the agent to converse to the
right generalization.


03 - Abstract Version Spaces
----------------------------

So in the versions basis technique of learning concepts incrementally, we always have a specific model and a general
model. As a new example comes along, we ask ourselves is this a positive example of the concept that we learned, or a
negative example of the concept that we learned? If it's a positive example, then we generalize the specific model. If
it's a negative example, we specialize the general model. Here is another set of visualizations to understand the
specific and general models. This is a specific model.


This is a general model. The most specific model, matches exactly one thing.


The four legged, furry, black animal called Buddy. The most general model matches everything, all animals. Here is a
current specific model, and as more positive examples come, you're going to generalize this specific model.


Here are some of the generalizations. Similarly, here is the current general model, and as negative examples come, we're
going to specialize the general model, and here are some of the specializations.


As we'll illustrate in a minute, I'll start with the most general model and try to specialize it. Some of these
generalizations and specializations that we are creating will no longer match the current data. When that happens, we'll
prune them out. As we prune on this side as well on this side, the two pathways may merge depending on the ordering of
the example. When they do merge, we have a solution. The right generalization of the concept for the given examples. So
far we have been talking about this in very abstract terms.


Let's make this concrete with an illustration.


04 - Visualizing Version Spaces
-------------------------------

So Shoke, I tend to think of the difference between the incremental concept learning we've talked about in the past and
version spaces in terms of a bit of a visualization. We can imagine a spectrum that runs from a very specific model of a
concept to a very general model of a concept.


And we can imagine that this circle represents where our model currently is.


If receive a new positive example that's not currently assumed bar concept, we then generalize it a bit to move it to
the right.


If we receive a negative example that is currently included in our concept, we're going to move it to the left and
specialize. As more and more examples come in, we start to see that our concept keeps moving around. [BLANK_AUDIO]


>> Notice that they would use it a model to refer to a concept. In fact, they use in concert with models almost
interchangeably. This is actually quite common for certain kinds of concepts. We have discussed earlier prototypical
concepts when we were discussing classification. But prototypical concepts, concepts are like models. What is a model, a
model is the representation of the world. Such that there is a one-to-one correspondence what is being represented to
the world and the representation itself. As an example, in the world of those blocks that made arches, I can actually
make an arch in the world, and then I can build a representation of that particular arch.


That's a model of the world, so the concept of an arch and the model of an arch in this particular case can be used
interchangeably.


05 - Example  Food Allergies I
------------------------------

So let us suppose that I go to a number of restaurants, and have various kinds of meals and sometimes get an allergic
reaction.


I do not understand why I'm getting this allergic reaction, under what conditions do I get the allergic reaction. So go
to an ER agent and say, dear ER agent tell me, under what conditions do I get allergic reactions.


And I give all the data, shown in this table, to the AI agent. Note that there are only five examples here, like we
mentioned in knowledge-based AI we want to do learning based on a small number of examples because that's how humans do
learning. Note also, that the first example is positive. And that there are both positive and negative examples. That is
important so we can, construct both specializations and generalizations. How then, may an AI agent decide the conditions
under which I get allergic reaction. So this examples are coming one at a time, and let us see what happens when the
first example comes. Here is the first example. The restaurant was Sam's.


Meal was breakfast. Day was Friday. The cost was cheap.


So from this one example, I can construct both a very specific model, which is exactly this example. Sam's, breakfast,
Friday, cheap. You can't have anything, more specific than this. And the AI agent can also construct a more general
model. Which of course is, that it can be any restaurant, any meal, any, day and so on. You can't construct a more
general model than this.


So the most specialized model based on this one example says that, I'm allergic when I go to Sam's and have breakfast on
Fridays and the cost is cheap. And the most general model says, I'm allergic to everything. No matter where I go, what
meal I have, on what day, and what the cost is, I feel allergic.


06 - Example  Food Allergies II
-------------------------------

Let us consider the processing as a second example comes along.


And the red outline for this example means it is a negative example. So now the agent will try to find a way of
specializing the most general model and generalizing the most specialized model, in order to account for this negative
example. So given this negative example, you want to specialize the most general model so that this negative example is
excluded and yet each of the specializations is a generalization of this most specific model because this was coming
from a positive example. We do want to include this.


Let's first specialize in a way so that each specialization is a generalization of this model. There are 4 ways of doing
it because there are 4 slots here.


The first slot here deals with the name of the restaurant like Sam's or Kim's.


One specialization of this most journal concept is to put the name of an actual restaurant there. This is generalization
of this concept because this was deferring to one specific need at Sam's, this is referring to any need at Sam's.


In a similar way I can specialize the filler of the second slot.


In short of having any meal, I can make it a breakfast meal.


This is a specialization of this most general concept that is a generalization of this concept because this refers to
breakfast at any place, this refers to breakfast at Sam's on Friday and so on. Similarly for the third slot and the
fourth slot in this most general concept.


Now I must look at these specializations of the most general concept and ask which one of them should I prune so as to
exclude the negative example.


I notice that Sam's doesn't match Kim's, so this is already excluded in so far as this concept is concerned. Breakfast
doesn't match lunch, so this example is already excluded as far as this concept is concerned. How about with this
concept of characterization and mix this negative example, therefore I must floor it. So we pull away that particular
concept characterization and we are left with three specializations of the most general model.


07 - Example  Food Allergies III
--------------------------------

Let us consider what happens when a third example comes along.


And the green outline of this example shows that this is the positive example of the concept. Because this is the
positive example of the concept, we must try to generalize the most specific model. So a generalization of the specific
concept, that includes this positive example as shown here. Here the meal was breakfast, here the meal was lunch. So we
can generalize over any meal.


Here the day was Saturday, here it was Friday, so we can generalize over any day. Of course we could have also
generalized just Friday or


Saturday, but for simplicity we'll generalize over any day. Similarly for breakfast or lunch, generalized to any meal.
But at this stage, there is another element to the processing. We must examine all the specializations of the most
general concept and see whether any one of them needs to be pruned out.


The pruning may need to be done in order to make sure that each specialization here is consistent with the positive
examples that are coming in.


So in this case, if we look at the first specialization here, which says, I'm allergic to breakfast at any place on any
day.


This cannot be a generalization of this particular concept. Put another way, there is no way that this breakfast here
can include, can cover, this positive example which deals with lunch. But yet another way, the only way I can move from
breakfast to any here would be if I generalize, but in this direction I can only specialize. Therefore, this must be
pruned out.


As you prune this first concept out, we're left with only two.


08 - Example  Food Allergies IV
-------------------------------

Now let us consider, the processing of the fourth example comes along.


Again the red outline shows that this is a negative example of the constant.


Because this is a negative example, we must specialize in most journal concept characterizations available at the
moment. We can begin by checking, whether we need to specialize this particular general concept. But wait, this general
concept characterization, already excludes the negative example.


This says the earlier happens when I go to Sam's, and this has Bob's in it, so this already excludes it, I don't have to
specialize it any more.


Now let's look at this general model. Does this need to be specialized, in order to excluded? Yes, because at the
current stage, this includes this vertical example. It is cheap here, this is cheap, this is any here, and this has
particle elements within. This means that, this concept characterization, must be specialized in a way that excludes
this negative example and yet.


The new specialization, is consistent with the most specialized characterization at present. It is tempting to see the
two pathways as converging here, because this is identical to that, but we also have this branch hanging, and this
branch says that I'm allergic to any meal at Sam's, not just a cheap meal.


So, we're not done yet. In this state there is one other element to consider.


If there is a node, that lies on a pathway starting from the most journal concept characterization, that is subsumed by
a node, that comes from another pathway starting from the same journal concept characterization, then I want to prune
that particular node. The reason I wanted to put on this note is, because this note is subsumed by this note. So this
note is true,


I don't have to carry this around. If I'm allergic to any meat at Sam's,


I don't have to specify that I'm allergic to cheap meat at Sam's, thus I can pull on this particular pathway, and I've
left it only this particular pathway.


At this point in processing, these are the examples that have been encountered so far. There are only two possible. I'm
either allergic to everything at Sam's, or I'm allergic to every cheap meal at Sam's.


09 - Example  Food Allergies V
------------------------------

I know you' are wondering when this is going to end. We're almost done, we're almost done. Let's consider what happens
when the first example comes.


This is a negative example as indicated by the red outline.


Because the negative example, we must specialize in most journal characterization, in such a way that this negative
example is dueled out, and this specialization is consistent with. The most journal version, starting from the most
specialized concept characterization.


The only specialization of this journal concept, that both excludes this and is consistent with this node is, Sam's
cheap. It excludes this, because it is cheap here, it will rule out the fact that this is expensive here.


Now the agent noticed that these two particular consequences positions are the same and if a convergence has occurred.
Now we have the answer we wanted. I get allergies whenever I go to Sam's and have a cheap meal.


10 - Version Spaces Algorithm
-----------------------------

What we have just done here, is a very powerful idea in learning.


Convergence is important. Because without convergence, a learning agent could zig zag forever in a large learning space.
We want to ensure that the learning agent converges to some concept characterization, and that remains stable.


This method guarantees convergence, as long as there is a sufficiently large number of examples. We needed five examples
in this particular illustration, for the convergence to occur. This convergence would have occurred, irrespective of the
order of the examples, as long as the five examples were there. Note that we did not use background knowledge like we
did in incremental concept learning.


Note also that we did not assume that the teacher was forwarding the examples in the right order. This is the benefit of
version space learning. There is another feature to note. In incremental concept learning, we wanted each example
different from the current concept characterization in exactly one feature, so that the learning agent could focus its
attention. However inversion spaces, you can notice that each successful example, the first one, the previous one and
many features, just look at the first two examples.


They differ in many features in the name of the restaurant, in the meal, in the cost. Here is the algorithm for the
version space technique.


We'll go through it very quickly, because we've already illustrated it in detail. If the new example is positive,
generalize all specific models included.


Prune away the general models that cannot include the positive example.


If the example is negative, specialize all the general models to include it.


Prune away the specific models that cannot include the negative example.


Prune away any models subsumed by the other models. Know that in this specific implementation of version space technique
that we just illustrated, there is a single pathway coming from the most specialize concert model.


And therefore there is no need to prune away specific models. In general, there could be multiple generalizations coming
for the most specialized models, and this might be needed.


11 - Exercise Version Spaces I
------------------------------

Let us do some exercises together. This exercise actually is quite similar to the exercise we had done previously except
that we have added one more feature, vegan. Either the meat can be vegan or the meat is not vegan. Suppose this is the
first example that comes along and this is the positive examples indicated by the green outline. Write down the most
specific and the most general models


12 - Exercise Version Spaces I
------------------------------

>> So, this example is pretty similar to the case we had in the previous example. So, the most specific case is that I'm
simply allergic to any breakfast that comes on Friday that's cheap and isn't vegan, so this very specific example. And
the most general model is I'm just allergic to everything, no matter what meal it is, what day it is, how much it costs,
whether it's vegan, or what restaurant I got it at.


13 - Exercise Version Spaces II
-------------------------------

Now suppose a second example comes along, and this example is also positive as indicated by the green outline.


Based on the second example, would you specialize or would you generalize?


14 - Exercise Version Spaces II
-------------------------------

>> That's right David.


15 - Exercise Version Spaces III
--------------------------------

So write down of the generalization of this most specific model that is consistent with this positive example.


16 - Exercise Version Spaces III
--------------------------------

>> And note that David could have put here breakfast lunch but for simplicity has generalized any meal.


17 - Exercise Version Spaces IV
-------------------------------

Let's go a little bit further, suppose a third example comes along, and this is the negative example indicated by the
red outline here.


What would you do this time? Generalize or specialize?


18 - Exercise Version Spaces IV
-------------------------------

>> So, this time we're going to specialize our most general model.


It's obvious that I'm not allergic to absolutely everything everywhere, because here's a particular instance where I
wasn't allergic to what I ate.


So we're going to specialize our most general model.


19 - Exercise Version Spaces V
------------------------------

So like David said, given this negative example, we'll specialize this most general model. And we'll prune out those
specializations that no longer match the data. Given this, how many specializations are left after the pruning?


20 - Exercise Version Spaces V
------------------------------

>> So I said that there'll be three potential general models left after specializing and pruning. Those three models are
going to be that I could just be allergic to everything at Kim's, I could just always be allergic to breakfast, or I
could just be allergic to eating on Friday.


I would prune the ones based on cost and whether or not the meal is vegan, because although I've had bad reactions to
cheap, non-vegan meals in the past, here I didn't have a reaction to a cheap, non-vegan meal. So it's not sufficient to
say I'm allergic to everything non-vegan or I'm allergic to all cheap food.


21 - Exercise Version Spaces VI
-------------------------------

We'd like you to complete this exercise. We've already done the first three examples. Having completed the exercise,
decide which model you converge on.


22 - Exercise Version Spaces VI
-------------------------------

>> Note that in this exercise, there were only seven examples and only five features. So we could do it by hand. What
would happen if the number of examples was much larger and the number of features were much larger?


This algorithm would still work but we'll need a lot more computing power.


It is also possible that the algorithm may not be able find the right concept to converge to because I might be allergic
to multiple meals at multiple restaurants such as breakfast at Kim's and lunch at Sam's. But even in that case, the
benefit of this algorithm is it will show that convergence is not possible even after many, many examples.


23 - Identification Trees
-------------------------

It is one of the method we can use, to process the kind of the data that we just saw. It is sometimes called decision-
free learning. Recall that we were discussing case-based learning, we talked about discrimination tree learning.


There, we learned the discrimination tree incrementally.


A case would come one at a time, and we would ask the question, what feature would discriminate between the existing
cases, and the new case?


And we would pick a feature. Discrimination pre-learning provides no guarantee of the optimality of this tree. That is
to say, at retrieval time, when a new problem comes along, traversing this tree might take a long time because this tree
is not the most optimal tree was during these cases.


We'll discuss an alternative method called decision tree learning, which will give us more optimal trees, however, at a
cost. The cost will be that all the examples will need to be given right at the beginning.


Let us return to our restaurant example. We want to learn a decision tree that will classify these five examples so that
as a new problem comes along, we can quickly find which is the closest example to the new problem.


To do this, we need to pick one of four features, restaurant, meal, day or cost that will separate these allergic
reactions, so that one category contains either only false instances, or only true instances.


As an example, supposing we think of restaurant as being the decisive feature.


So we have picked restaurant as a decisive feature. Now, there are three kinds of restaurants. Kim's, Bob's, and Sam's.
Whenever it's Kim's restaurant, or


Bob's restaurant, there is no allergic reaction. Whenever it's Sam's restaurant, there can be allergic action shown in
green here, or no allergic reaction, shown in red. So the good thing about this particular feature, restaurant, is that,
it has separated all the five examples into two classes.


Into the class Sam's, and into the class not Sam's. Not Sam class consists of only negative reactions, which is good,
because we know that we have now been able to classify all of these five examples into two sets, one of which contains
only negative examples. Now for these three examples, you must pick another feature that will separate them into
positive and negative instances. In this case, we might consider cost to be that feature.


When the cost is cheap, then we get positive examples. When the cost is expensive, then we get negative examples. This
is a classification tree.


And in fact, this is a very efficient classification tree.


When a new problem comes around, for example visit6. Sam's, lunch, Friday, cost is expensive, and you want to decide
what the allergic reaction might be, we simply have to travel through this tree, to find out, the closest neighbor, of
that particular new example. This is called a decision tree.


And this technique that we just discussed is called decision tree learning.


This method of inductive decision tree learning worked much more efficiency and apparently more easily than earlier
method that we have discussed. But the trade off is that we needed to know all the five examples right in the beginning.
Of course, this technique simply appears to be efficient and easy. And that is because we had only five examples, and
only four features that were describing all five examples.


If the number of examples was very large, or the number of features that were describing the examples were very large.
Then it's very hard to decide what exactly should be the feature that we should use to discriminate on.


24 - Optimal Identification Trees
---------------------------------

Let us look at another example of decision tree learning. Here is a data set of people who go to the beach, and some of
them get sunburned, and others don't. In this data set, there are nine examples and each example is characterized by
four features, hair, height, age and lotion.


Once again, how can we construct an optimal decision tree that they classify all of those examples? One possible idea is
to discriminate first on hair color.


Hair color classifies all of these known examples into three categories, brown, red and blonde. The interesting thing
about the choice of hair color is that in the case of brown, all of these sunburnt cases are negative. People with brown
hair apparently don't get sunburned. In case of all the red haired people, there is sunburn. So hair color is a good
choice for picking as a feature to discriminate on because it classifies things in such a way that some of the
categories have only negative instances and no positive instances. And some of the categories are only positive
instances and no negative instances.


Of course, that still leaves blonde-haired people. In this case, there are both some positive instances and some
negative instances, and therefore, will need another feature to discriminate between the positive and the negative
instances. Here, lotion might be the second feature that we pick.


Lotion now classifies the remaining examples into two categories, some people used lotion, other people did not. Those
who used lotion did not get sunburnt.


Those who did not use lotion did get sunburn. Once again, these are all negative instances. These are consisting of only
positive instances.


Thus, in this decision tree, simply by using two features, we were able to classify all of these nine examples. This is
a different decision tree for this same data set. But because we use a different order, therefore, now we have to do
more work. This decision tree is less optimal than the previous one.


We could have chosen a different set of features in a different order. Perhaps, we could first discriminate on height
then on hair color and age. In this case, we did a much bushier tree. Clearly, this tree is less optimal than this one.


Note the trade off with the decision tree learning and discrimination tree learning that we covered in case-based
reasoning.


Decision tree learning leads to more optimal classification trees. But there is a requirement. You need all the examples
right up front. Discrimination tree learning may lead to suboptimal trees, but you can learn incrementally.


25 - Assignment Version Spaces
------------------------------

So how would version spaces be useful to answer Raven's progressive matrices?


Like with the incremental concept learning, think first about what concept you're trying to learn. Are you learning
transformations? Are you learning types of problems? What are the increments?


Are they individual problems? Are they individual figures?


Are they individual transformations in a problem? Second, what are you converging onto? For example, you could use
version spaces within one problem and converge down onto a correct answer, or you could use it for learning how to solve
problems in general and converge onto adoptable algorithm, or you could use it for learning an ontology of problems and
converge onto a single type of problem you expect to see in the future. So what are you converging onto if you use
version spaces for Raven's progressive matrices?


26 - Wrap Up
------------

So today we've talked about version spaces. Version spaces are an algorithm for converging onto an understanding of a
concept, even in the absence of prior background knowledge or an intelligent teacher. We covered the algorithm for
version spaces, where we iteratively refine a general and specific model of a concept, until they converge down onto one
another.


We then talked about using version spaces to address more complex problems.


We've also connected version spaces to older concepts, like incremental concept learning. Finally we talked about the
limitations of version spaces, such as what to do if there's no single correct concept, or what to do in the absence of
either positive or negative examples. To address these, we also covered identification trees, which are a different ways
of approaching the same kind of data that version spaces operate on. We'll touch on version spaces and incremental
concept learning again, when we talk about mistake based learning.


27 - The Cognitive Connection
-----------------------------

Cognitive agents too face the issue of how far to generalize.


We can undergeneralize in which case what we learn is not very useful.


We can overgeneralize in which case what we learned may not be correct.


For example, imagine that I was a Martian who came to your Earth.


I saw the first human being, and I may undergeneralize and say this specific person has two arms. That is not very
useful because that is not applicable to any other human being. Or I may overgeneralize and say everyone on this Earth
has two arms. That may not be correct. [UNKNOWN] is a technique that allows convergence to the right level of
abstraction. This is also connected to the notion of cognitive flexibility.


Cognitive flexibility occurs where the agent has multiple characterizations or multiple perspectives on the same thing.
As we saw in version spaces, the agent has several possible definitions for a concept that converge over time. An
alternate view is to come up with one generalization and try it out in the world. See how well it works. If it leads to
a mistake or a failure, then one can learn by correcting that mistake.


We'll return to this topic a little bit later in the class.


28 - Final Quiz
---------------

Please write down what you learned in this lesson.


29 - Final Quiz
---------------

Great. Thank you so much for your feedback.


