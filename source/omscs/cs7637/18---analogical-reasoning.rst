.. title: 18 - Analogical Reasoning 
.. slug: 18 - Analogical Reasoning 
.. date: 2016-01-23 06:48:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

=========================
18 - Analogical Reasoning
=========================

01 - Preview
------------

Today we'll talk about Analogical Reasoning.


Analogical Reasoning involves understanding new problems, in terms of family of problems. It also involves addressing
new problems, but transferring knowledge of relationships from known problems across domains.


We introduced a notion of transfer previously in explanation based learning.


We also have talked about Case Based Reasoning.


Today we'll talk about transfer in a much more general manner.


We'll start by talking about similarity then revisit case based reasoning.


Then we'll talk through the overall process of analogical reasoning, including retrieval, and mapping, and transport.
Then we'll close by talking about a specific application of analogy, called Design by Analogy.


02 - Exercise Similarity Ratings
--------------------------------

To illustrate the notion of similarity, let us consider an example. Consider that a woman is climbing up a ladder. Here
are seven situations. Can you please rank these seven situations by their order of similarity to the given situation?


03 - Exercise Similarity Ratings
--------------------------------

>> Interesting answer, David, note that there are several factors in


David's answers. In the two situations that he thought were most similar to a woman climbing up a ladder, in the
similarity in the relationship, climbing up as well as similarity between objects, woman and ladder. In contrast, one
that he did not think was really similar to a woman climbing up a ladder, woman painting a ladder. Although there is
some similarity between the objects woman, and ladder, the relationship is very different here it is climbing up a
ladder, here it is painting a ladder which are two very different activities.


Between one and two we notice, that both of them have the same relationship, climbing up, but an object is different, In
one case it is the step ladder and in another case it is a set of stairs. So one can have similarities in relationships,
one can have similarities in objects, of course some of you may have different rankings with the similarities of the one
they would give.


Because, your background knowledge might be different or your priorities might be different, but the point here is the
similarity can be measured around several dimensions. Around the dimension of relationships, around the dimension of
objects, around the dimensions of features of objects, and around the dimensions of values of features of objects that
are participating in relationships, we'll talk more about this in just a few minutes.


04 - Cases Revisited
--------------------

We have come across the notion of similarity earlier in this course.


When we were discussing learning [INAUDIBLE] cases, that particular point, we came across the matter of finding the
nearest neighbor. At that point we found the nearest neighbor simply by looking at the [INAUDIBLE] distance between the
new situation, and the familiar situations. We came across the notion of similarity when we were discussing case
reasoning as well at that point, we came across at least two different methods of organizing the case library.


And that, in one method, we could simply organize all the cases in array here's an array of several cases in the domain
of navigation and urban area, each case here is represented, by the x and y location of the destination.


A different and smarter method, also organizes cases that are discriminatory, the leaf nodes of this discrimination tree
represented the cases. The root node and the interior nodes in the discrimination tree represented discrimination, or
decisions about the values of specific features for example, east of 5th Street or not east of 5th street, both of these
[INAUDIBLE] schemes are based on measures of similarity.


In the first scheme the similarity is based on the similarity between the tags,


If a new problem were to come along it would be more or less similarly one of these cases depending on whether or not
its tags match the tags of a particular case here. In the second scheme of this [INAUDIBLE] tree, similarity is based
on, traversing this particular tree,


If a new problem came along, we would use the features of that new problem to traverse this tree and find the case whose
features best match your new problem.


Note that the new problem, and the source cases in all of these examples so far have been in the same domain. Here for
example, both the new problem and the source case are in the same domain of navigating in an urban area, in the previous
example, the new problem and the source case were the domain of colored blocks in the blocks world. What happens if the
new problem and the SOS case are not in the same domain? So consider the example of, a woman walking up the ladder and
walking up the wall. The two dimension are the same, we're talking about woman in one case and in other case, a ladder
in one case, a wall in other case yeah, there's some similarity. Situations like this, where the new problem and the
source case are from different domains, lead to cross-domain analogies. So the question now becomes, how can we find
leaf similarity between the new problem, the target problem, and the source case, if they happen to be in different
domains?


05 - Need for Cross-Domain Analogy
----------------------------------

To dig into this issue of similarity between a target problem and a source case in different domains, let us look at
another example.


Let us suppose it is a patient who has a tumor in his stomach.


There is a physician who has a laser gun. She knows that if the laser light were to shine on this tumor, the tumor will
be killed and the patient will be cured.


But the physician has a problem. The laser light is so strong that it will also kill all the healthy tissue on its way
to the tumor, and thereby killing the patient. What should the physician do?


This is actually a very famous problem in cognitive science. It was first used by a psychologist called Don Curry around
1926. What do you think the physician should do in this situation? Take a moment and think about it. [BLANK_AUDIO]


We'll return to the physician and the patient example in just a minute. First let me tell you another story.


Once there was a kingdom ruled by a ruthless king, there was a rebel army approaching the fortress in which the king
lived. Well there was a problem.


The kings' men had mined, all the roads approaching the fort.


As a result, if an army was to walk over the roads, the mines would go off, and the soldiers would be killed. So what
did the army decide to do?


The army decided to decompose itself into smaller groups, so that each group could come from a different road, and reach
the fort at the same time.


Because each group was small enough, the mines on the roads did not go off.


The soldiers were able to attack the fort at the same time and overthrow the bad king. Now let's go back to the problem
of the physician and the patient. What do you think now? Has the answer to the problem changed?


Some of you indeed may have changed your answer because of this story I told you about the king and the rebel army. One
solution to this problem is that a physician would divide a very intense laser beam into several smaller, less intense
beams. As these beams come from different directions, they do not harm the healthy tissue. However, they reach the tumor
at the same time and manage to kill the tumor. You will note that this is an example of cross-domain analogy. Here the
target problem had to do with the physician and the patient. The source case had to do with the king and the rebel army.


The objects in these two situations were clearly very different.


In one case we had a physician and the patient, the laser beam and the tumor.


And in the other case we had the king and the rebel army, the fort and the mines. Some of the relationships were very
similar.


In capturing the fort case, we had a resource, the army, which was decomposed into several small armies, which was sent
to the goal location at the same time.


We took this battle, we took this strategy, abstracted it out, and then applied it to the patient and physician example.
A physician used the same strategy. Resource decomposes into several smaller resources, and sent to the goal at the same
time. Now you can also see why the ant climbing a wall is similar to a woman climbing a ladder. The objects are
different, ant and wall, woman, and ladder, but the relationship is similar. Climbing up.


The cross-domain analogy is then, the objects and the features and the values of the objects can be different. The
similarity is based on the relationship.


It is the relationship that is important. It is the relationship that gets transferred from the source case to the
target problem.


06 - Spectrum of Similarity
---------------------------

We can think of a spectrum of similarity. At one end of the spectrum, the target problem and the source case are
identical.


At the other extreme end of the similarity spectrum, the target problem and the source case have nothing in common. We
can evaluate the similarity between the target problem and source case in similar dimensions. In terms of the
relationships occurring in the source case and the target problem.


In terms of the objects occurring between the two. In terms of the features of the objects and in terms of the values
that the features of the objects take.


At the end of the spectrum, where the target problem and the source case are very similar, with relationships, objects,
features, and values are all similar. At the other end the values, features and objects may be different, but the
relationships are similar.


If the relationships too are different, then there'll be nothing in common with the target problem in the source case.
When the relationships, objects, features and values are all similar, then that is an example of recording cases, and we
have come across it. An example of that was from the colored blocks in the blocks world. When the similarity between the
target problem and the source case is along the dimension to relationships and objects, but not along the dimensions of
values or values and features, then that's an example of case-based reasoning. We discuss this method in the domain of
navigation and urban areas. The objects of the concept between the target problem and the source case being the same
means that the domains are the same.


So cased-based reasoning is within domain analogy. An analogical reasoning in general, objects in the target column and
the source case too, might be different. We saw an example of analogical reasoning in the Dunker radiation problem, when
we were talking about cross-domain analogical transfer.


Actually recording cases in case based reasoning are also examples of analogical reasoning, except that they occur in
the same domain.


The target firm and the source cases in the same domain, which is why we consider them earlier. By analogical reasoning
here, we mean cross domain analogical transfer. As in the Dunker radiation problem.


07 - Process of Analogical Reasoning
------------------------------------

Analogical reasoning allows us to look at new problems in terms of familiar problems. It also allows us to transfer
knowledge from familiar problems to new problems. A hierarchy process of analogical reasoning is shown here.


It consists of five major phases, retrieval, mapping, transfer, evaluation, and storage. We'll discuss all five stages,
in detail.


Let us compare for a moment, the process for an illogical reasoning in general, with a process for, case based
reasoning, within domain and illogical reasoning that we discussed earlier. Notice that retrieval, evaluation, and
storage, are common between the two processes.


In case based reasoning the target problem and this first case, were from the same domain. They had the same kind of
relationships, and the same kind of objects. We simply had to adapt the source case to address the target properly. An
analogical reasoning in general, the target form and the source case need not be from the same domain.


When they are not from the same domain, we can't just take the source codes and adapt it. We first have to map the
target problem with the source case that is, we need to address the correspondence problem. What in the target problem,
corresponds to what in this source case as an example? The laser beam and the target Duncker's radiation problem
corresponds to the rebel army in the source case. Once we have mapped the conceptual relationship in the target problem
to the conceptual relationships in the source case, then, we can try to transfer some of the relationships in the source
case to the target problem.


We can first abstract those relationships and then transfer them to the target problem. As an example, the Duncker's
radiation problem we first did the alignment, that is, we just did the correspondence problem, what in the target
[UNKNOWN] corresponds to what in the source case?


Then we took the relationship, and abstructed it. The relationship in that case was, take the resource and decompose it
into several smaller resources, and send them to the goal at the same location. That particular relationship, that
particular pattern, is what we abstracted and transferred to the target problem.


Note that this is just one theory of analogical reasoning. In other theories, some of these boxes are configured
differently. For example, in another theory, mapping is a part of retrieval. We do mapping in order to do retrieval.


08 - Analogical Retrieval
-------------------------

Let us look at analogical retrieval more closely. Once again, we have come across this idea earlier. We did analogical
retrieval in recording cases by the k nearest neighbor method. We did analogical retrieval on a case based reasoning
using two different methods, the array method and the discrimination tree method. Here the criteria for evaluating
similarity were very clear, as we discussed earlier. [UNKNOWN] distance, same tags, as well as placement in this
discrimination tree. The question now becomes, what criteria should be used to decide on the similarity between the
target problem and the source case, given that they come from different domains?


On surface, there seems to be little similar between the two. None of the objects are similar. None of the values of
features are similar. Yet, there is a deep similarity there. We can distinguish now between superficial similarity
between two situations and deep similarity between two situations.


Superficial similarity deals with features of objects or counts of objects or objects themselves. Deep similarity deals
with relationships between objects, or sometimes relationships between relationships. Examples of this arise from the
variables test with which you are already familiar. Features here refer to the size of the square, the size of the
circle, or perhaps where there is a hollow square, or a solid dot. The count refers to the number of squares, or number
of circles, in a particular image. Objects here refer to circles and squares and dots. Let us look at relationship
between objects.


Two situations are said to be deeply similar, if the relationship between the objects is similar. As an example, a and b
are similar, in that, that the dot is outside the circle here and the square is outside the circle here. A and b are
also similar in that the dot is above the circle here and the square is above the circle here. What about relationships
between relationships?


Let us compare a and b. In going from A to B, the dot has disappeared, and a square has come outside the circle, and
become bigger. Now we can compare this relationship between a and b, with some of the relationship between a c and a b,
in which too, some object might be disappearing, and another object which may be in the center of the circle comes out
of the circle.


I'm sure you've come across problems like that on the variable test.


This is an example of a binary relationship, a relationship between two objects.


This is an example of a higher order relationship, a tertiary relationship if you wish. This is a relationship between
the relationship between objects.


You might even say that these are examples of unary relationships.


These are just examples of objects and their features and counts. In general, as we go from unary relationships to
binary relationships to tertiary relationships to even higher order relationships, the similarity becomes deeper and
deeper. This means that mind decides two situations to be more similar if the similarity is at the level of relationship
between objects rather simply at the level of objects or features or counts and objects.


09 - Three Types of Similarity
------------------------------

Semantic similarity used with conceptual similarity between the target problem and the source case. If we recall the
original exercise that David had answered, in that exercise, a woman climbing up a ladder is conceptually similar,
semantically similar to a woman climbing up a step ladder.


The same kind of concepts occur in both situations. Woman, and step ladder or ladder. Pragmatic similarity concerns with
external factors.


Factors external to the presentation, such as goals. As an example, in the Dunker radiation problem, the physician had a
goal of killing the tumor, which was similar to the goal of capturing the fort in case of the rebel army and the king.
Pragmatic similarity refers to similarity of external factors, factors external to the representation, such as
similarity of goals. The Dunker radiation problem for example, the physician had the goal of killing the tumor, which
was similar to the goal of capturing the fort in case of the rebel army in the king example. The third measure of
similarity is structural similarity.


Structure here refers to the structure of presentations, not to physical structure. Now structural similarity of the
first two, similarity between the representational structures of the target problem and the source case, and we'll look
at an example of this in just a few minutes.


Know that one can assign different kinds of weights to these three measures of similarity. So some queries of analogy
focus on structural similarity.


Other theories of analogy focus on semantic and pragmatic similarity. That is also why you may have given slightly
different answers to the questions in the first exercise than David did.


10 - Exercise Analogical Retrieval I
------------------------------------

Let us do another exercise together now that we know about deep similarity and superficial similarity. Consider the
situation again, a woman is climbing up a ladder. Give this set of situations, mark whether each of the situations is
deeply similar or superficially similar to this given situation. Know that some might be both and others might be
neither


11 - Exercise Analogical Retrieval I
------------------------------------

>> This is good, David. Once again, different people may give different answers to this exercise. Why do we do so? Well,
let's examine it next.


12 - Exercise Analogical Retrieval II
-------------------------------------

Many science textbooks in middle school or high school explain the atomic structure in terms of the solar system.


Here's a representation for the solar system, here's a representation for the atomic structure. Let us see how this
model of the solar system helps us make sense of the atomic structure. We'll use this example often going forward.


And this representation of the solar system is arrows are denoting causality. So the sun's mass is greater than the
planet's mass, which causes the planet to revolve around the sun. Similarly for the atomic structure, there is a force
within the nucleus and the electron, and that causes the nucleus to attract the electron and the electron to attract the
nucleus.


Given these two models, what are the deep similarities between them?


13 - Exercise Analogical Retrieval II
-------------------------------------

>> Now we can see why these textbooks write about the solar system, and the atomic structure in such a way that these
relationships become salient.


They help us make sense of the atomic structure, by pointing to the deep similarities between the relationship that
occur in the atomic structure, and the relationship that are occurring in the solar system.


14 - Analogical Mapping
-----------------------

Now let us consider analogical mapping. The problem here is called the correspondent's problem. There are a number of
obvious relationships in this target problem. There are a number of obvious relationships in this source case.


What in the target problem corresponds to what in the source case?


If we can address the correspondence problem. If we can say, for example, that the laser beam corresponds to the rebel
army, then we can start aligning the target problem and the source case so it makes the deep similarities between
relationships salient.


Note there are several parts of a target problem and several in the source case.


In principle, any of these objects of the target problem could correspond to any of the objects in the source case. In
which case we would have an m to n mapping, and that becomes computationally inefficient. If you and I, often do not
have much of a problem deciding, if the laser beam must correspond to the devil army. How do we do it? And how can we
help AI agents make similar kind of correspondences? Our answer is, we'll make use of relationships.


In fact, we'll make use of higher order relationships, whenever possible.


We'll give precedence to higher order relationships, over other relationships.


As a unary relationship, we might say that a patient is a person here, and king is a person there. The binary
relationship we might say, that physician has a resource, the laser beam. And that the rebel army has a resource, the
army itself. It's a higher ordered relationship, a tertiary relationship between say, that between the goal and the
resource is an obstacle. They held a tissue in this case. Similarly between the goal and the resource is an obstacle,
the minds in this case. We focus on the higher ordered relationship there, that's where the deepest similarity between
the two situations lies. This is how we know to mark between the king and the tumor and not between the king and the
patient. Although the king and the patient are superficially similar, a deeper similarity lies in viewing the king and
the tumor in terms of goals which need to be cured or captured using a resource when there is an obstacle in between
them.


15 - Exercise Analogical Mapping
--------------------------------

Let us do an exercise on deep relationships. Let's get back to for example the solar system and the atomic structure.
Let us suppose that you've given this representation of the solar system and this representation of the atomic
structure. How would you map the solar system to the atomic structure?


16 - Exercise Analogical Mapping
--------------------------------

>> This is right, David. Another thing to take away from here is note the depth of understanding it requires in order to
be able to make your right kind of correspondences. If one didn't have the right kind of model for the solar system and
atomic structure that captures the deep relationships, then the mapping may not be done. The alignment wouldn’t work,
and we would not be able to understand the atomic structure in terms of the solar system. Thus, models, deep and rich
models of the two systems, the target problem and the source case, are essential to deciding how to align them, how to
map them, and as will see in a moment, what to transfer and how to transfer it.


17 - Analogical Transfer
------------------------

Now let us consider analogical transfer. So, given this target problem, analogical retrieval has led to this source
case.


Given a model of the target problem and a model of the source case, analogical mapping has also occurred, correspondence
has been established.


This we now know that a king corresponds to the tumor, not to the patient.


And that the rebel army corresponds to laser beam. For the source case we also know the solution. The rebel army divided
itself into smaller groups, and the smaller groups all arrived at the fort at the same time. Now the question becomes
how can we transfer this solution to our original target problem.


>From the source case now, we're inducing a pattern of relationships, a strategy.


In this case the pattern is that if there is a goal, capturing the king, and a resource, the rebel army and an obstacle
between the resource and the goal.


They march on the road, then decompose the resource into several smaller resources. And send them to the goal from
different directions at the same time.


This abstract pattern is now transferred to the target problem and instantiated.


Because we know that the goal is the tumor, the resource is the laser gun, and the obstacle is the healthy tissue, we
know what to do.


We must decompose the resource, the laser gun, into smaller pieces, smaller, less intense laser beams, and send them to
the tumor, the goal, at the same time from different directions. This is how we can transfer the problem solving
strategy, from the source case to the target problem.


Note that this transfer depended upon the correct mapping, the correct alignment between the target problem and the
source case, which in turn depended upon the retrieval of the source case corresponding to this target problem. Note the
important rule or goal here. The goal was to capture the king. So this is an example of pragmatic similarity. With a lot
of similarities at the level of the goal, capturing the king, curing the tumor.


18 - Exercise Analogical Transfer
---------------------------------

Let us do an exercise on analogical transfer together. Back to our example of this sort of system in the atomic
structure. Given this representation of the solar system and this representation of the atomic structure, what would be
transferred from the solar system into the atomic structure model?


19 - Exercise Analogical Transfer
---------------------------------

>> That's a smart answer David.


Recall that originally I had said that I'll explain structural similarity, and


I have not done it so far. I'm going to use the spherical example and


David's answer to explain it now. Given the solar system as the source case, and the atomic structure as target problem.
We can see that there is little semantic similarity between them. The kinds of objects that occur in the solar system
are not at all like the kinds of objects that occur in the atomic structure.


We can also see that pragmatic similarity is not a major issue here. We're not talking about the goal of the solar
system or the goal of the atomic structure.


Although we might have the goal of understanding atomic structure in the solar system, there is nothing in the solar
system, or in the atomic structure, which has a goal. Yet, David was able to answer this question correctly.


This is because of structural similarity. Let us consider the top part of the model of the solar system. You can think
of this top part like a graph.


The vertices in this graph, correspond to objects and their properties.


The edges in this graph correspond to relationships, such as force between Sun and Planet. Or, Sun attracts Planet, and
Planet attracts Sun. Once again, this graphical representation of the model atomic structure.


The words are representing the objects and the features. And the edges are representing the relationships between the
objects. Although there's little semantic similarity, or pragmatic similarity between the two situations, we can see a
structural similarity. A similarity in the structure of the graphs.


Because this part of the graph of the representative of the solar system.


The similar this part of the graph of the representative of the atomic structure. We can differ infer that we can
transfer this part of the graph of the solar system to infer this part of the graph of the atomic structure.


Structural similarity then captures relational similarity.


What is common between these two situations is neither the objects or the goals. Where as common here as the relational
similarity, and that is what structure similarity captures.


20 - Evaluation and Storage in Analogical Reasoning
---------------------------------------------------

Let us briefly talk about evaluation in storage. These evaluation and storage steps in analogical reasoning are very
similar to the evaluation and storage steps in case based reasoning. Analogical reasoning by itself does not provide
guarantees of correctness. So the solution that it proposes must be evaluated by some manner. For the down correlation
problem, for example, we may evaluate the proposed solution by doing a simulation.


Once the evaluation has been done, then the new problem and a solution can be encapsulated as a new case and stored back
in memory for later potential reuse.


To return to the down correlation problem, as an example. Once we have the solution of decomposing the laser beam into
several smaller beams and sending them to a tumor at the same time from different directions, we can do a simulation of
this solution and see whether they are successful. If it is, then we can encapsulate the target problem and the proposed
solution as a case, and store it in memory. It might be useful later. It could potentially become a source case for a
new target problem to come later. Once again, in this way, the AI agent learns incrementally. Each time it solves a
problem, the new problem and its solution becomes a case for later reuse.


21 - Design by Analogy
----------------------

It is often useful to look at specific problem domains, both to see how we can apply current theories of chronological
reasoning to them and also to see how we can use those problem domains to build new theories of chronological reasoning.
So let us turn now to the domain of design. In design, there is a new movement that is sometimes called biologically
inspired design, or biomimicry. This movement is pulled by the need for environmental sustainability and is pushed by
the desire for creativity and innovation and design. On the top left here is a picture of the Shinkansen 500 train in
Japan. This is a bullet train. It's called a bullet train because of the shape of its nose. This particular shape is
inspired by the shape of the beak of the Kingfisher. The story goes something like this.


Japanese railway engineers were interested in building faster trains.


However, they had a problem, these trains had to go through tunnels. And as they went through tunnels, they created
shock waves, which created a lot of noise, bothering the neighbors. The shock wave was created because outside the
tunnel and inside the tunnel were two different mediums. By serendipity, the railway engineers looked at how the
Kingfisher goes from the medium of air into a medium of water, dips its beak and catches its prey.


The shape of its nose allows us to create a smaller shock wave.


We use the same principle to create the design of the nose of the bullet train.


Shinkansen 500 travels faster than previous trains and also makes less noise than previous trains, mostly because of the
nose shape.


Another example often cited in biomimicry is the example of a Mercedes Benz box car, designed by inspiration to the
Boxfish. Notice as biological inspired design entails analogical reasoning. There's a target problem.


There's a source case. There is cross-domain analogical transfer.


22 - Design by Analogy Retrieval
--------------------------------

To illustrate analogical reasoning and design, or analogical design, we'll talk about a specific problem, let us suppose
we design a robot that can walk on water.


Nature already offers several examples of organisms that can walk on water, this is a picture of the basilisk lizard,
which can walk very well on water and catch it's prey. Recall that we said earlier that for analogical mapping and
crossword worker row, requires a deep understanding of the source case and the target problem. That is true here as well
in case of analogical design, we require a deep understanding of the locomotion of the basilisk lizard, in order to be
able to design a robot that can walk on water, inspired by the design of the basilisk lizard. Here is a model of the
basilisk lizard, this model is sometimes called structure behavior function model.


This particular picture doesn't show the structure, it just shows the function and the behavior. The function is shown
at the top here, It is shown by it's initial state and it's goal state, and it's function is achieve by behavior shown
here. The behavior is represented as a series of states, and transitions between those states. We will not talk about
the representations in more detail here, readings given in the class notes give this sort of representations a lot more
detail if you are so interested.


23 - Design by Analogy Mapping  Transfer
----------------------------------------

Recall that we started with a problem of designing a robot, that can walk on water. Let us suppose that, that particular
target problem resolves in the retrieval of a source case, of a robot design that we already encountered. One that can
walk on ground. Now the question becomes, how can we adapt this particular design of the robot that can walk on the
ground, into a robot design that can walk on water? Let us now suppose, if we reuse this particular problem of designing
a robot to walk on water.


As a probe into the case memory. And now the case returns to us, the design of the basilisk lizard. That might happen,
because the design of the basilisk lizard, is indexed by it's functional model, walk on water. So there is a pragmatic
similarity between the two.


We now have the design of a robot who can walk on ground, and we have the design of a biological organism, the Basilisk
Lizard, that can walk on water. For the Basilisk lizard, we also have a complete model, a complete explanation of how
its structure achieves its function. Now that we have a partial design for the robot, this is a design of the robot that
can walk on ground. And we have a design of an organism that can walk on water.


We can try to do an alignment between these two. This alignment will be based on the similarity between relationships.
Clearly, the objects here, and objects there are very different. Once we have aligned these structural models, or the
robot that can walk on ground, and the basilisk lizard that can walk on water. Then, we can start doing transfer. We can
transfer specific features, of the structure of the basilisk lizard. For example, the shape of its feet, to this model,
of the robot that can walk on ground. In order to convert it into a robot, it can walk on water. Having constructed a
structural model, for this robot that can walk on water then we can try to transport the behavioral model, and then the
functional model. And then this way we have a complete model of a robot that can walk on water. Along with an
explanation of how it will achieve it's function. This is sometimes called compositional analogy.


We'll first do mapping at the level of structure, and that mapping at a level of structure helps us transfer some
information.


That in turn allows us to transfer information at the behavioral level.


Once we have transferred information at the behavioral level, we can climb up this abstraction hierarchy, and transfer
information at a functional level.


We can now revisit our computational process, and our logical reasoning.


Initially we had presented this particular process like, a linear chain,


Retrieval, Mapping, Transfer, Evaluation and Storage. In general, however, there can be many loops here. We may do some
initial mapping, for example, that may result in some transfer of information. But that transfer then, may lead to
additional mapping, and then to additional transfer and so on. Here is another brief example, from biological inspired
design, in this case we want to design a robot that can swim under water in a very slowly manner.


This particular function of swimming underwater in a stealthy manner, reminds a design team of a copepod. A copepod is a
biological organism, that has a large number of appendages. It moves underwater, in such a way that in generates minimum
wake, especially when it moves very slowly.


On the other hand, when it moves rapidly, then the wake becomes large, when the wake is small then its motion is very
steady, when the wake is large, its motion is no longer steady. An analogically transfer of knowledge about this
particular copepod, gives a design for the microbot for slow velocity.


This analogy, decomposes our original design problem. We had the original design problem, as moving underwater in a
stealthy manner. Now that we have a design of an organism, for moving underwater at low velocities, we are still left
with the sub goal of moving underwater at high velocities.


The goal of designing a microbot, that can move underwater in a stealthy manner, at fast velocities, may remind the
design team of the squid. The squid uses a special mechanism, like the jet propulsion mechanism to move underwater in a
stealthy manner at pretty high velocities. Now we have created a designed for microbot. Where part of the design comes
from the design of the copepod, and the other part comes from the design of the squid.


Instead of borrowing the design from one source case, we are borrowing parts of the design of multiple source cases.


This is a compound analogy. Notice that there's a problem evolution going on, which started with one problem. We arrived
at a partial solution to that.


Which then leads us to a problem evolution. And the problem transformation.


We then have a new understanding of the problem. So, this example we saw, how we first did analogical retrieval of the
coco powder organism. Then Mapping, then Transfer. That then lead to addition retrieval, in this case with a squid.


Once again this process is not linear. Just like we can iterate between


Mapping and Transfer, similarly we can iterate between Transfer and Retrieval.


24 - Design by Analogy Evaluation  Storage
------------------------------------------

Evaluation too can play a very important role in the iterative loops in this analogical reasoning process. One can use
several different methods for doing evaluation. In the robot that can walk on water, for example, we can do a
simulation, or we can build a physical prototype. If the evolution succeeds, then well and good, we can encapsulate the
target polymer solution as a case and store it in case memory. If the evaluation fails, we may need to revisit transfer
and see whether we want to transfer some of the knowledge or revisit mapping, and perhaps align things differently or
revisit retrieval and perhaps try to retrieve a different source case. As an example, supposing that the evaluation
shows, then the robot that we designed for walking on water is a little too heavy. In that particular case, we may
change the problem specification and retrieve a different kind of organism that perhaps is a little lighter. Let us
suppose that we evaluate the design of the robot that can walk on water and find that the design is a little too heavy.


In that case, we can go back to the transfer stage and see whether we can transfer some of the relationship that might
make the robot a little lighter. Or we can go back to the mapping stage and see whether we can align the source case and
the target problem slightly differently so that we can transfer a different relationship. Or alternatively, we can go
back to the retrieval state and try to retrieve a source case, a different kind of biological organism altogether.


Thus, we see that the process of analogical reasoning is not linear at all and see it can have many different kinds of
iterations.


Analogical reasoning continues to be an important topic in our research and biological-inspired design is becoming one.


We provide several readings with both topics in the class notes.


25 - Advanced  Open Issues in Analogy
-------------------------------------

There're a number of advanced and open issues in analogical reasoning, that are the subject for current research. First,
because analogical reasoning entails cross-domain transfer, does it mean that we necessarily need a common vocabulary
across all the domains? Consider the example of the atomic structure and the solar system once again. Suppose I were to
use this term revolve, to say the electron revolves around the nucleus. But use the term rotate to say the planet
rotates in an orbit around the sun. I have used two different terms.


How then can I do alignment between these two situations? Should I use the same vocabulary? If I don't use the same
vocabulary, what alternative is there?


Second, analogical reasoning entails problem abstraction and transformation. So far we have talked as if the problem
remain fixed, it's source case is retrieved and transferred across. But often, the agent needs to abstract and transfer
the problem, in order to be able to retrieve the source case.


A third issue in analogical reasoning concerns compound and compositional analogies. So far we have talked that given a
problem, we can retrieve a case and transfer some knowledge from that case to the problem.


But often we retrieve not one case, and we transfer knowledge from not one case, but from several cases. If you're
designing a car, you might design the engine binology to one vehicle and the chassis binology to some other vehicle.
This is an example of compound analogy. But how can we make compound analogy work?


In compositional analogy, analogy works at several levels of abstraction.


Supposing we were to make an analogy between your business organisation and some other business organisation. We might
make this compositional analogy, first at the level of people. Next to the level of processes. Third of level of the
organisation as a whole. This is another example of compositional analogy, where mapping at one level supports transfer
to the next level. How do we do compositional analogy in AI agents? Fourth, visuospatial analogies. So far we have
talked about analogies in which it transferred necessarily engages causal knowledge. But a large number of analogies in
which causality is at most implicit. We'll consider these visuospatial analogies later in the class.


Fifth, conceptual combination. A powerful learning mechanism is learning a new concept by combining parts of familiar
concepts. Analogical reasoning is one mechanism for conceptual combination. I have a one concept, [UNKNOWN] concept,
that of the atomic structure, another concept, the solution concept.


The concept of the solar system. I take some part of the solar system knowledge, combine it with my concept of the atom
to get a new concept of the atom.


If you're interested in any of these issues,


I invite you to join the PhD program in Computer Science.


26 - Assignment Analogical Reasoning
------------------------------------

So how would you use analogical reasoning to design an agent to answer Raven's progressive matrices? This might be a
tough question at first, because the agents we're designing only operate in one domain, taking the Raven's test. They
don't look at other areas. So, we're going to get the knowledge necessary to do cross domain analogical transfer.


In this instance instead of the agent doing the analogical reasoning, maybe it's you doing the analogical reasoning.


Can you take inspiration from other activities to inspire how you design your agent? Or can you take knowledge from
other activities and put them in your agent, so that it can do the analogical reasoning?


27 - Wrap Up
------------

So today, we've been talking about analogical reasoning. We started by talking about similarity. As we saw in our
opening exercise, similarity is something that we evaluate very easily without even really thinking about it.


How can we design agents that can do the same kind of similarity evaluation?


We then talked about analogical retrieval, which can be difficult, because we're trying to retrieve examples across
other domains.


How can we structure our knowledge to facilitate this kind of retrieval?


How can a system know the given a model of the atom, it should retrieve a model of the solar system? Then we talked
about mapping, which is figuring out which parts of different systems correspond. For example, how can figure out that
the troops in the four example correspond to the lasers in the tumor example? We then talk about transfer, which is
moving knowledge from the concept we know to the concept we don't. For example, we used what we knew about the solar
system to fill in our knowledge of the atom. Then next, we talked about evaluation and storage. How do we evaluate our
analogies?


In the tumor example, we might actually try that medical procedure. But for other analogies, how do we evaluate them?
And then how do we store them for future use? Last, we talked about a special kind of analogy, design by analogy, where
we use something that we know a lot about to inform our design of something new. We'll talk a lot more about this,
especially design by analogy, when we come to the design unit later in our course.


28 - The Cognitive Connection
-----------------------------

Analogy is often considered to be a core process of cognition. A common example of analogy we encounter everyday is that
of metaphors. For example, you can imagine someone saying, I had to break up with her. We had grown very far apart.


Far apart here is a spatial metaphor. One of the famous examples of metaphors comes from Shakespeare. All the world’s a
stage, all the men and women merely players. The theater here is a metaphor for the world. A third connection is the
Rubin’s test of intelligence.


The Rubin’s test is considered to be one of the most common and reliable test of intelligence, and as you well know by
now, it is based entirely on analogies. An analogy is that central to cognition.


29 - Final Quiz
---------------

Please summarize, what you learned, in this lesson.


30 - Final Quiz
---------------

Great, thank you for your answer.


