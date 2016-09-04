.. title: 12 - Logic 
.. slug: 12 - Logic 
.. date: 2016-01-23 06:42:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

==========
12 - Logic
==========

01 - Preview
------------

Today we'll discuss logic. Logic is a formal language that allows us to make assertions about the world in a very
precise way.


We learn about logic both because it is an important topic and also because it forms the basis of additional topics such
as planning.


We'll start talking about a formal notation for writing sentences in logic.


This formal notation will have things like conjunctions and disjunctions. Then we'll talk about truth tables, a topic
that you probably already know. We'll talk about rules of inferences like modus ponens and modus tollens. Finally we'll
discuss methods for proving theories [UNKNOWN] by repetition. One of those methods is called, resolution theorem
proving.


02 - Why do we need formal logic
--------------------------------

Let us begin by asking ourselves, why do we need use formal logic to design an AI agent? The way the formal logic in an
AI agent would work is that there will be two parts to the AI agent.


The first part of the agent will consist of a knowledge base.


The knowledge will contain the agents knowledge all over the world.


That knowledge will be represented in sentences in the language of logic.


The second part will consist of an inference engine. The inference engine will apply rules of inference to the knowledge
that the agent has. So remember again, two parts, the knowledge base and then rules of inference. Now there are certain
situations in which we want the AI agent to be able to show, to be able to prove that the answers, that it derives to
any problem in fact are provably correct.


If we want to show this to itself, or to other users. In other situations, we may want the AI agent to generate only
provably correct solutions. How can we guarantee that? Well we need two things. First, we need a complete and correct
knowledge base. And second, we need rules of inference that will give guarantees of correctness of the answer. The
inference then has two parts to it.


The first part is called soundness. The property of soundness means that rules of inference will derive only those
conclusions that are, in fact, valid. The second property is completeness. The property of completeness means that the
[UNKNOWN] will derive all of the valid conclusions.


These are two very important properties to have. If an AI agent can use logical rules, logical rules of inference on its
knowledge base and provide guaranteed soundness and completeness, then it's a very useful thing for an AI agent to have.
For this reason, logic has been an important part of


AI since the inception of the field. In fact it continues to be an important part of research and modeling AI. In this
course however we'll discuss logic only to a very limited degree. There are two reasons for this. First, our priorities
in this course are a little different.


Instead of talking about knowledge in the form of logical sentences, we are much more interested in conceptual knowledge
and experiential knowledge and heuristic knowledge. Second, recall that we said that a logic based agent has two parts
to it, the knowledge base and the rules of inferences.


Even if the rules of inferences are, in fact, guaranteed to be sound and complete, there is a problem about how do we
construct a correct and complete knowledge base? If the knowledge base of an AI agent is not correct and complete, then
it may not gave you useful answers, even if the roots of inference are sound and complete. Thus, in this course, we'll
use logic only to the degree to which it is useful for specifying other methods. Methods that use conceptual knowledge
or experiential knowledge or heuristic knowledge.


03 - Inferences About Birds
---------------------------

Now we have come across this particular kind of problem earlier.


This was a classification hierarchy. Vertebrates can be of different kinds.


Bird is one kind. Birds can be a different kind. Eagle, bluebird, penguin are three classes of birds. Now imagine we
have knowledge like, if an animal has feathers then it is a bird. When we're discussing this classification hierarchy we
had tried to define the concept of bird, and we had said at that time that if an animal has feathers it is a bird, and
if an animal lays eggs and it flies then it's a bird.


It is sentences like this that we'll try to put in the language of logic.


04 - Exercise Inferences About Foos
-----------------------------------

Before we represent those sentences in the language of logic, let us consider another example of conceptual knowledge
and its relationship to logic first. So here is a concept of four. We have come across this earlier.


They were a block and a block and a brick at the bottom and a brick at the top.


And some relationship between these objects. Given this conceptual knowledge about foo we can ask ourselves, what are
the sufficient conditions for something to be a foo? Here are several choices. Please mark all of those choices that
together make for sufficient conditions for the concept of foo


05 - Exercise Inferences About Foos
-----------------------------------

>> That's good David. So what we are finding here is, given conceptual knowledge, how can we translate it, into the
language of logic?


06 - Predicates
---------------

Recall that we said that a lot of this AI agent will have two parts to it, a knowledge base and then the rules of
inference. We'll come to the rules of inference a little bit later. First let us look at how can we construct a
knowledge base in the language of logic. So what we are trying to do now is that an AI agent has some knowledge about
the world and it is going to express it in the scheme of logic. In earlier schemes of knowledge representation, we
discussed how there were objects and relationships between objects. And any knowledge representation scheme we need to
capture both objects and relationships between those objects. Logic has a particular way of doing it.


So consider an object like a bird. This object may have various arguments.


We'll define something called a predicate, which is a function that maps object arguments to either true or false. So
let us consider an example. Here we have bluebird as the object and feathers as the predicate on this object. Let's
consider this example. Here, bluebird is the object and feathers is the predicate on this object.


Feathers is now a function that can map either into true or into false.


Either bluebird has feathers or bluebird doesn't have feathers. In this particular case, feathers of bluebirds would be
true, because bluebirds do have feathers. Now, just like we had bluebird as the object in the previous example, here we
have animal as the object, the same predicate. Now, of course, not all animals will have feathers, so this particular
predicate may be true or false, depending on the choice of the animal. In this sentence there are two predicates, one
object, animal still, but there is a predicate feathers and a predicate bird. And we can capture the relationship
between these two predicates, by saying that if feathers animal is true, then bird animal is also true. This example has
two predicates. Here there's one object, the animal. But the predicates are feathers and birds. And the sentence is
capturing a relationship between the two predicates. If the animal has feathers, then the animal is a bird. In logic we
call sentences like this as having an implication. This is an implicative relationship. So in logic, we'll read this as
Feathers(animal) implies Bird(animal). Or if the animal has feathers, then it implies that the animal is a bird.


07 - Conjunctions and Disjunctions
----------------------------------

Now, consider another sentence that we have come across earlier.


If an animal lays eggs, and it flies, then it is a bird. How do we write this in the language of logic, given that there
is conjunction here. So this time, we can have two predicates again. There is a predicate of lays-eggs, coming from
here. The predicate of flies, coming from here. And we can denote a conjunction between them. Which in the language of
logic is often put in this form. Now we can re-write this sentence in the following form.


If the animals lays eggs and the animal flies, then the animal is a bird.


Remember again, this semi colon here, really is denoting implication for now. Remember again, that in logic, this really
stands for an implication.


Consider the slightly different sentence. Suppose if the sentence was if an animal lays eggs or it flies it is a bird.
In that case, again, we'll have two predicates, but this time we'll have a disjunction between them.


And the sentence would become or if animal lays eggs or animal flies, then the animal is a bird. And again, this is an
implication. Let us continue with the our exercise in which we are learning how to write sentencable language of logic.
It is under the sentence, if an animal flies and is not a bird.


So, it is a negation here, then it is a bat. How do we write that in logic? So


I'm still interested in writing the antecedent of this particular sentence, and


I may be able to say that animal flies is a conjunction here, because it is an and here, and we have this negation
symbol for this predicate, bird. Now we can write a complete sentence by saying that the animal flies, conjunction.
Animal is not a bird, implies animal is a bat.


08 - Implies
------------

Now, I have talking a little about implication. Let's see how do we actually write, implication and logic. So here is a
sentence, if animal lays eggs and animal flies, it is implication is that the animal is a bird.


In logic we write this using the symbol, arrow symbol, or an indication, so if the animal lays eggs and animal flies,
implication animal is a bird. So here is the left hand side of the implication, here is the left hand side of the
implication.


The left hand side of the implication, implies the right hand side


09 - Notation Equivalency
-------------------------

Generally speaking, you won't have these symbols on your keyboard. You can find them in your character map and you are
welcome to use them if you'd like to.


But for the exercises in the rest of this lesson and in the next lesson, feel free to use the symbols given over here.
These are the symbols for AND,


NOT, OR and Equals that come from Java or Python. So, feel free these when you are doing the exercises that you'll come
across in the rest of this lesson.


10 - Exercise Practicing Formal Logic
-------------------------------------

So remember we are still trying to learn how to build a knowledge based on the language of logic. To put it all
together, consider four exercises.


Here is the sentence. Please put it in the language of logic. Similarly for this sentence, this sentence, this sentence.


11 - Exercise Practicing Formal Logic
-------------------------------------

>> Good, David, that looks right to me. To wrap this part up, let us note that, when we defined what a predicate was, we
said a predicate like flies can map into true or false. Well, okay, a predicate can map into true or false. What about
complicated sentences like this which are multiple predicates as well as implications?


How do we find out whether the sentence as a whole maps into true or false? That's what we're going to look at next.
We're looking at truth tables.


12 - Truth Tables
-----------------

So we'll now build truth tables for conjunctions and disjunctions and negations of sentences, so that we can find the
truth of complex sentences stated in logic. Now many of you probably are familiar with truth tables, and if you are in
fact familiar with truth tables, then you can skip this part and go directly to implication elimination. If you're not
familiar with this then please stay with me, but even so I'm going to go through this quite rapidly. So here is the
truth table for A or B. If A is true, then B.


If A is true and B is true, then A or B is true. If A is true and


B is false, then A or B is still true, because A was true. If A is false and


B is true, then A or B is true, because B was true. One of them is true, makes this true. If A is false and B is false,
than A or B is false.


13 - Exercise Truth Tables I
----------------------------

Let us try a couple of simple exercises. So here we have A, B and we want to find a truth value of A or not B.


Given these values for A and B, can you please write down the truth values for


A or not B. And similarly, for not A and not B


14 - Exercise Truth Tables I
----------------------------

>> So for A or not B, I got that if A is ever true, then this has to be true, because it's A or not B. When A is false
the negation flips the value of B, so it makes it true when B is false, but keeps it false when B is true.


For not A and not B, that means that any time either A or


B is true, then this is all false. So when A is true, this is false.


When B is true, this is false. When both are false, this becomes true, because those negations flip the values of both A
and B.


15 - Exercise Truth Tables II
-----------------------------

Now, we can play the same game, for ever more complex sentences. So, here I've again, three predicates, A, B and C. And
here's a more complicated sentence that involves all three of those predicates. A or B, and within parentheses, B and,
nought C. And we can find the truth values for this particular, sentence, given the truth values for the predicates A, B
and


C. Why don't you give it a try and write down the values here?


16 - Exercise Truth Tables II
-----------------------------

>> So as you can see, this can become very complicated very quickly. But


David did get the answer to the truth value of this particular sentence based on the truth values of the predicates that
are inside this sentence. So, in principle now, we can see how, we can compute the truth value of very, very complicated
sentences written in logic


17 - Exercise Commutative Property
----------------------------------

The construction of these truth tables, allows us to illustrate certain important properties of logical predicates. To
see those properties, let us do an exercise together. So here we have the predicate A, and the predicate B. And here we
have A and B, and B and A. Please fill these boxes, the truth values of A and B, the truth values of B and A.


18 - Exercise Commutative Property
----------------------------------

>> That's good, David. And as you know, this property is called the commutative property. The commutative property says
that the truth value for A and


B is the same as the truth value for B and


A. So whenever I have A and B, and can re-write it as B and A.


19 - Exercise Distributive Property
-----------------------------------

Let us try a slightly more complicated exercise. This time, we have three variables, A, B, and C. And here are the
combinations of the truth values of A,


B, and C. Here on the right are two formulas. The first one says,


A and parenthesis B or C parenthesis closed.


The second says parenthesis A and B parenthesis closed or parenthesis A and


C parenthesis closed. Please write down the truth values for these two formulas.


20 - Exercise Distributive Property
-----------------------------------

>> We can also think of this as distributing the part outside both the predicate and the operator, into both the ones on
the inside. We take the A and, and apply it to B, so A and B. We take the A and, and apply it to C, so A and C. And we
preserve the operator in-between B and C. In between the two new parenthesis.


So if this had been a or b or c. This would become a or b or b or c. This would become a and b and c, a would be all the
operators here


21 - Exercise Associative Property
----------------------------------

Let us do one of their exercising in two tables illustrate one of the property of logical predicate. Again here are
three predicates, and here are two formulas. It should be a simple exercise.


Please write down the truth values, of the two formulas, in these boxes.


22 - Exercise Associative Property
----------------------------------

>> The difference between these formulas and the ones we were doing before, are the values of these operators.


Associative property works when it's, both ors or both ands. Distributed property worked when there was a mixture of
operators.


23 - Exercise de Morgans Law
----------------------------

One other property of logical predicates that we will see very soon in action is called de Morgan's law. So this time
there are two predicates A and B. Here are their truth values. And here are two formulas. Remember this is a negation.


Please write down the truth values of these two formulas in these boxes.


24 - Exercise de Morgans Law
----------------------------

>> That's good David.


So the de Morgan's law is saying that when we try to distribute negation over the predicate inside the parentheses that
are connected with a conjunction, then the conjunction becomes a disjunction between the negations of the pre,
predicates. The same would have been true if we had a disjunction here.


When we distribute the negation, it would have become a conjunction here. David, before we go ahead further, let's
remember why we are trying to do all of this.


So do you recall we said in the beginning of the lesson that a logical agent will have a knowledge base, and then formal
rules of inference that will apply on these sentences as knowledge base. The knowledge base itself may be coming from
many places. Some sentences in the knowledge base may be boot strapped into the logical agent. Other sentences may be
coming from perception. Now when we're trying to apply these rules of inferences to the synthesis of the knowledge base
it is sometimes very useful to rewrite the sentences in different forms. And that's what we are trying to do.


These properties will allow us to rewrite the sentences in such a way that we can in fact apply the rules of inferences
that we will see in a minute.


25 - Truth of Implications
--------------------------

>> So it can be a little bit weird to talk about the truth value of an implication sentence. What we're really saying
here is, whether or not this implication actually holds true. So let's take three different implications to see this.
First let's think of the implication, feathers implies bird. All birds have feathers and only birds have feathers. So,
we know that if an animal has feathers, then it is a bird. That's true.


On the other hand, let's take the implication, if scales then bird. Lots of animals with scales aren't birds and in fact
no animals with scales are birds.


So the implication, scales implies birds. Would be False. For our third example, let's take the implication, flight
implies bird. If we have a penguin, flight is False. But the penguin is still a bird. So, flight can be false and bird
can still be true, meaning the implication can still be true here.


On the other hand, if we have a cat, flight if False. And bird is False.


So, the implication can still be true. So in this case, if flight was false, we can't actually make a determination on
whether or not the animal is a bird.


26 - Implication Elimination
----------------------------

As we go ahead and start applying rules of inferences to sentences in a knowledge base. We'll find it convenient to
rewrite the sentences in a knowledge base. And sometimes it will be very useful to rewrite these sentences in the
knowledge base in a manner that eliminates the implications in a sentence. And this is how we can eliminate the
implication. If a implies b, than we can rewrite it as not a or b. We know this because the truth value of a implies b
is exactly the same as your truth value of not a or b. We can take an example here. Supposing that we are given feathers
imply bird.


Then we can rewrite this as not feathers or bird. And intuitively, you can see the truth value of this. It is either the
animal does not have feathers or, it is a bird. In a little bit, we will see that this is a important rewrite rule in
doing certain kinds of logical proofs.


27 - Rules of Inference
-----------------------

>> You may already be familiar with this line of reasoning, because this is another way of raising contrapositive, that
we see in other areas of logic.


28 - Prove Harry is a bird
--------------------------

Now you can see how we apply these rules of inferences on sentences in a knowledge base or philosophical agent to prove
all kinds of sentences. See, imagine that an AI agent begins with the knowledge that if an animal has feathers, it
implies that the animal is a bird. Now it comes across Harry, who does have feathers. By Modus Ponens, therefore the AI
agent can conclude that Harry is a bird.


This completes the proof for our original goal of proving that Harry is a bird.


Now let us suppose that a goal is to prove that Buzz does not have feathers.


Once again, imagine an AI agent which begins with the knowledge that if an animal has feathers, it implies that the
animal has, is a bird.


The agent comes across a animal, which is not a bird. Then by Modus Tollens it can infer that buzz must not have
feathers. This completes the proof for of a original goal of proving that buzz does not have feathers. Okay. So now, we
have looked at two ways of proving the truth value of various sentences.


The first way was just through truth tables. I could have sentences and logic. Then I could write another sentence. And
ask myself, what, what is the truth value of this sentence? I could construct a truth table for that sentence, composed
of the truth values of all the predicates, with some of which might be coming from earlier sentences. The second way in
which we have seen how we can prove the truth values of sentences and logic is by applying these rules of inferences
like modus ponens and modus tollens. This is very powerful, and in fact the power of this logic has been known since
before the birth of AI. As computer scientists however, we'll analyze this power in a slightly different way. Yes, we
can use method of truth tables to construct a truth table for any arbitrary sentence. However, the sentence was
complicated. Then the truth table very soon will become very complex. Computationally, that is infeasible for very long,
large sentences. Similarly, yes we can apply simply modus ponens and modus tollens to find the truth value of many
sentences. But if the knowledge base consisted of a very large number of sentences, instead of just one or two
sentences, then the kinds of inferences, number of inferences I can draw from those sentences simply by applying modus
ponens and modus tollens, will be very large. Or if I had to find the truth value of a single sentence, then the
different pathways I could take in order to get to the truth value of those sentences can make for long, large problem
space. So while these methods of proving the truth with your sentences and logic have been around for a long time. These
methods are not computationally feasible. At least not for complex tasks. At least not for agents that have only limited
computational resources and from who we want near realtime performance


29 - Universal Quantifiers
--------------------------

Before we show you, a computationally more feasible way of proving theorems in logic, or proving the truth value of
sentence in logic.


We should point out that so far, we have been using only propositional logic.


Propositional logic is sometimes also called the zero-if order logic.


The key aspect of propulsion logic, is that it does not have any variables. So as an example, I may have a sentence that
says if the animal Lays-eggs, and the animal Flies, then the animal is a Bird.


And here I'm talking about a specific animal. Well, sometimes I might want to talk about, animals in general, any
animal, all animals. In that case,


I would want to introduce a variables in it. So in first audilogic, otherwise known as predicate calculus, I might want
to say something like.


If x Lays-eggs and x Flies, then x is a Bird.


Which has a set form very similar to form here, except that instead of animal,


I now have a variable. Now, I have a variable here. But, I must also specify the range of the variable. And what I
really want to say here is for all animals. Therefore I'll introduce a new quantifier over the variable x.


This quantifier is called Universal Quantifier. It is denoted with the symbol, this is the symbol for Universal
Quantifier. And this says now for all x, if x Lays-eggs, and x Flies it implies that x is a Bird.


One thing to note here is that, I could have rewritten this sentence, with the Universal Quantifier back into
proposition logic. But, having lots of sentences like this. In proposition logic. So I could've said


Lays-eggs (animal) one, Flies (animal) one implies Bird (animal) one,


Lays-eggs (animal) two, and Flies (animal) two implies Bird (animal) two.


And so on and so forth, for each and every animal that is possible.


But, by writing it in the form of a variable, a Universal Quantifier statement,


I can reduce the number of sentences I have to write into just one sentence. So we have introduced variables, and we
have talked at least about one quantifier so far, the Universal Quantifier, that applies for all values that that
variable can take. Sometimes I might want to specify a different range of the variable. Not all values of the variable
can take, but, at least some values of the variable I can take. So consider again, this sentence, here the animal is
[UNKNOWN] a specific animal. Now let's look at the second sentence on this screen. And this sentence is the variable y.


It says if y Lays-eggs and y Flies then it implies that y is a Bird.


This sentence is a very similar form, to the previous except for the variable y. I can specify the value, that the
variable y can take.


This time I want to specify not that this sentence is true for all values of y, for all animals, but simply that it is
true for. Some at least one animal in which case I'll use an Existential Quantifier. Here is the symbol for an
Existential Quantifier, this Existential Quantifier says that there is at least one animal, for which this sentence
happens to be true.


30 - A Simple Proof
-------------------

Okay, let us set aside predicate calculus, and return back to population logic.


Recall that we had found ways of writing sentences in population chronologic.


We had found rules of inferences, we could prove theorems.


We could find the truth value of new sentences.


However, we found that those methods were computationally, not very efficient.


So AI has developed more efficient methods.


One of those methods is called Resolution Theorem Proving.


Let us take an example to illustrate how resolution theorem proving works.


So, imagine there is a robot, and this robot.


Is working on an assembly line, it's a factory robot, and on the assembly line are coming weird kind of widgets.


The robot's task is to pick up each widget, as it comes on the assembly line and put it in a truck.


However, there are some humans in this factory.


Who play a joke on the robot once in a while, they glued the widget to the assembly line belt, so that, when the robot
tries to move it, it can not move it.


But the robot is a smart robot, this is a logical agent, so when it can not move it.


It uses its logical reasoning, to figure out that the boxes aren't liftable.


And the moment it knows that the boxes aren't liftable, it lets go of the box and moves onto the next one.


Everyone got the story?


All right.


So let us suppose that the robot begins with some knowledge in its knowledge base.


And this knowledge in its knowledge base, that it begins with says that if cannot move, then it implies that not
liftable.


Now, it tries to move the box, the next box in the widget.


It's biceps tells it, it can not move.


It needs to prove that it's not liftable.


And of course this is a preview example and I'm sure you'll understand it.


You can put essentially a class of the modest components to prove that it's not liftable.


If p then q, p therefore you can infer q.


But, we'll use this example to show.


How does resolution theorem proving works?


So, the first step in resolution theorem proving is, to convert every sentence into a conjunctive normal form.


A conjunctive normal form of a sentence, can have one of three conditions.


It can have a literal.


That can be either a positive atom, or a negative atom.


It can have this disjunctional literals like here can-move, or not liftable, or it can have a conjunction of
disjunctional request.


In this example the third condition doesn't occur.


So, the first thing we must do is to take the first sentence.


The negation of not move implies not liftable.


And remove the implication, because an implication cannot occur in conjunctive normal form.


So the first thing we need to do is, to rewrite the sentence, the first sentence, to remove the implication.


Because the implication cannot occur in a conjunctive normal form.


So now we use the.


Implication elimination rewrite rule.


To rewrite this in the form of can-move, or not liftable.


Remember that was alpha implies beta becomes, not alpha or beta.


So the not of negation of can-move becomes can-move or not liftable.


So, we have done it for the first sentence.


This is now in a conjuncted normal form.


We can do the same thing for the second sentence, but wait, the second sentence already is in a conjunctive form.


We don't have to do anything.


Now, the robot wants to prove that their box is not liftable.


Resolution to improving, is like proof by refutation.


To do proof by refutation we will take the negation of what we want to prove.


We wanted to prove not liftable would take its negation, which makes it liftable.


Okay, so now we got three sentences.


This one's the first sentence that the robot was bootstrap with, you've just converted to a conductor normal form.


This was the sentence that came from a it saw that the box cannot move.


And this is the sentence throughout the negation of the sentence, the refutation of the sentence that it wants to prove.


So we have three sentences now.


The first sentence came from the bootstrapping, of the robot's knowledge base.


This is the axiom that the robot assumes to be true.


The second sentence came from its percepts.


The robot tried to move the box, it could not move it.


The third sentence is coming from taking the negation of what the robot wants to prove.


It wants to prove it's not liftable.


So, it's going to take this negation of it and then, sure that it's going to lead to a null condition that we'll view as
a contradiction.


The resolution for improving lawless begin with a liftable in the sentence that we want to prove.


So here that sentence is liftable, and we'll look for a sentence that contains a negation of liftable in this sentence
that we want to prove.


So the sentence here was liftable, sentence S1 contains liftable which is a negation of that so we pick S1 and not S2.


Note, how efficient it was to decide what sentence on the knowledge based to go to.


In sentence container negation of the liftable.


So, liftable and not liftable can not both be true.


We know that, and therefore we can eliminate them.


This is called resolution.


We resolve unliftable and we remove them from the sentences.


Now, we were sentence as S1, that leaves us can move.


So, now we pick a sentence, that has the negation of literal can-move.


Sentence S2 has a negation of that, and we can resolve one can move, they can not both be true.


When we resolve on both of them, those get eliminated as well.


And now we see we've reached another condition.


This null condition represents a contradiction, and now we can infer that liftable cannot be true, therefore not
liftable is true.


The robot has proved not liftable.


And in this case it appears as a resolution theorem improving is more complex there's more respondents.


In general it is not.


It just appears here, because this condition happened to fulfil the form of more respondents directly.


In general, deciding on which sentence to apply the modest ponents on, and how to combine those groups of inferences
don't suddenly become [INAUDIBLE] harder than deciding how to apply the resolution and improvements.


31 - A More Complex Proof
-------------------------

Let us make this example[br]a little bit more complicated.


Complicated enough that it cannot[br]be proven simply by applying one instance of modus ponens.


Imagine that a robot proved to itself[br]that this box is not liftable.


And the humans in the factory[br]who were trying to make fun of the robots said to the robot[br]well, the reason it's
not liftable is not because it's not movable, but[br]because your battery is not working.


So now the situation[br]is more complicated, the robot must also check its battery.


So now the robot begins with[br]slightly different knowledge in this knowledge case.


So suppose that the knowledge in its[br]knowledge basis, cannot move and battery full means it's not liftable.


It finds from its concept.


Again, it cannot move, so it checks its[br]battery, and it checks its battery and it finds that the battery's full.


So then two new sentences that get[br]written in the knowledge base.


By the knowledge base[br]contains three sentences.


As earlier, the resolutions you're[br]improving, the agent must convert all these sentences, in its knowledge[br]base
into a conjunctive normal form.


That means that the sentences[br]can contain a literal or a disjunctional literal or[br]a conjunction of disjunctional
literals.


So if we begin by removing[br]the implication from sentence one, because an implication cannot occur[br]in a conjunctive
normal form.


So when we remove implication from[br]the first sentence we get this sentence.


Where the sentence is not yet[br]satisfactory, it is not yet a conjunctive normal form because this[br]is a disjunction
of conjunctions.


And what we want are conjunctions[br]of disjunctions.


So we apply the deMorgan's Law and[br]now we get the following sentence.


We're simply taking the negation inside[br]which flips the conjunction into a disjunction and now we have
three[br]liftables connected with disjunctions and this is a conjunctive normal form,[br]disjunctional liftable.


So now we have in the knowledge base,[br]three sentences, all three of them in the conductor normal form,
either[br]literals or disjunctional literals.


Recall that the robot wanted[br]to prove not liftable.


So it takes the negation of that,[br]this is again proof by refutation, so it considers liftable.


So now this knowledge[br]base has four sentences.


These four sentences coming from[br]the negation of what it wants to prove.


Once again the reasoning begins by[br]the literal that it wants to prove, in this case liftable.


It finds a sentence in which[br]the negation of literal is true.


So once again,[br]we begin with the sentence,


S4 because that is[br]what we want to prove.


And we find a sentence in the knowledge[br]base which contains a literal which is a negation of the literal in[br]this
sentence S4 that we want to prove.


We resolve on this because[br]they both cannot be true, and resolution here simply[br]means that we drop them.


Now, in the sentence S1 that is[br]under consideration currently, we have two literals.


We can begin with either one of them.


Let us begin with not battery full.


We'll try to find a sentence[br]which contains a negation of this particle electrode.


There is a sentence, S3, which is a[br]negation of this so we resolve on this.


Battery full and not battery full[br]because they both cannot be true.


We'll drop them.


Now in sentence S1 we are left[br]with just one literal, can-move.


We can try to find a sentence in[br]the knowledge base which contains a negational judge literal.


Here it is, and so[br]we can resolve on them.


And we resolve on them, we drop them.


And once we drop them, then we have a null condition,[br]which stands for a contradiction.


So we reached a contradiction, therefore[br]the assumption that this was liftable cannot be true, therefore not
liftable[br]is true, and we have just shown that resolution theorem proving in this case[br]proves what the robot wanted
to prove.


One important point to note here is[br]the issue of focus of attention.


Often when the problem space is very[br]complex, for example, when the number of sentences is really large, the
sentences[br]are very complex, it can become really hard for the logical agent[br]to decide what to focus on.


But because we have converted everything[br]in a conjunctive normal form, and because resolution theorem proving
is[br]making use of resolution, therefore at any particular time, the logical[br]agent knows exactly what to focus on.


You always begin with this literal, you always try to find a sentence[br]which contains this negation.


You always resolve on that.


You take the remaining literal in[br]the sentence and proceed forward.


This focus of attention, this[br]computational efficiency of resolution theorem proving is arising because[br]a
[INAUDIBLE] called horn clauses.


A horn clause, is a disjunction that[br]contains at most one positive literal.


This is happening in S1.


This is a disjunction that contains[br]at most one positive recall.


This is a negative recall,[br]this is a negative recall, and the fact that it contains[br]just one positive recall, is a
very powerful idea because that's[br]where the focus of attention comes from.


32 - Exercise Proof I
---------------------

Let us do an exercise together to make[br]sure that we get rich solutions for improving.


So consider this sentence[br]if an animal has wings and does not have fur, it is a bird.


Write this sentence[br]down in formal logic.


You can use the predicates,[br]has-wings, has-fur, and bird.


33 - Exercise Proof I
---------------------

David, what did you write?


>> So starting at the beginning, has[br]wings becomes the predicate has wings.


We're doing a conjunction so[br]and, does not have fur, so not has fur,[br]those two things imply that it's a bird.


>> That's good, David.


Now, let us put this in a form, in a conjunctive normal form that we[br]can use in resolution theorem proving.


34 - Exercise Proof II
----------------------

So since an indication cannot[br]occur in a conducted normal form, we must eliminate the implication.


So please eliminate the implication[br]from this sentence, and rewrite it in this box.


35 - Exercise Proof II
----------------------

What did you get David?


>> So[br]this is a little bit more complicated.


We know that from our earlier[br]formula if a implies b, then to rewrite it with implicational[br]elimination we write,
not a or b.


So or b is pretty straightforward,[br]or bird.


We take the not of[br]the conjunction over here and say not has wings and not has fur.


Now some of you may have jumped[br]straight to writing this in full conjunctive normal form, but now we're[br]going to
move on and do that last step.


36 - Exercise Proof III
-----------------------

So this is not conjunctive normal form, because we have a disjunction[br]over conjunction.


What we want are either just[br]disjunctions or conjunctions for disjunctions.


So use de Morgan's law to write[br]this in a conjunctive normal form.


37 - Exercise Proof III
-----------------------

What do you have, David?


>> So with the Morgan's Law,[br]we take the negation on the outside and apply individually to the predicates[br]on the
inside, and flip the operator.


So has-wings becomes not-has-wings,[br]not-has fur because has-fur.


And the and becomes an or.


38 - Exercise Proof IV
----------------------

So imagine that your robot has[br]this in its knowledge base and goes into a country where[br]it finds an animal and
from its perspective knows that this[br]animal has wings and does not have fur.


So these two additional centers[br]is gotten in the knowledge base.


Now the robot wants to[br]prove that this is a bird.


In order to [INAUDIBLE] proving, what should the robot begin[br]by writing in this box?


What should the S4 sentence be?


39 - Exercise Proof IV
----------------------

What do you think, David?


>> So in resolution theorem proving, we always assume the opposite[br]of what we're trying to prove.


We're doing proof by refutation.


So we're trying to prove[br]that it is a bird, so we're going to assume[br]that it's not a bird.


>> That's right.


40 - Exercise Proof V
---------------------

Containing further.


So what part of S1 would[br]we eliminate first?


41 - Exercise Proof V
---------------------

What do you think David?


>> So in resolution theorem proving, we[br]start with whatever it is we assumed and look for the negation of[br]that in
an earlier sentence.


Here we find not bird, and bird in S1.


So we're going to resolve on not bird[br]and bird and leave both of those out.


>> That's good.


42 - Exercise Proof VI
----------------------

So what shall we do next?


What should we resolve on next?


43 - Exercise Proof VI
----------------------

Out of four choices,[br]which one did you pick, David?


>> So, I picked the first one, but


I think there's actually[br]two correct answers.


What we're looking for is something else in S1 that has[br]a negation in another sentence.


Not has wings has a negation in S2, so we could resolve on S2 with[br]the not has wings portion of S1.


Has fur also has a negation in S3.


So we could also resolve on S3 and[br]the has fur portion of S1.


>> This is right, David.


At the end of this, we're left with[br]null, which is a contradiction.


Therefore, an assumption[br]that is not bird is false.


Therefore, it must be a bird and the robot has just proved[br]that this must be a bird.


Note what we have done.


We have mechanized parts of logic.


And sort of coming up[br]with large truth tables.


And it's sort of coming up with[br]complex chains of inference based on modus ponens and modus tollens.


We have found in our garden[br]resolutions are improving, which is a efficient way of proving[br]sentences and the truth
values.


This is how it works.


Take all the sentence and the knowledge base,[br]convert them into conjecture novel form.


Take what you want to prove and[br]its negation.


Put that as a new sentence.


Now, starting with this particular[br]sentence, a new sentence.


Find the literal in another sentence[br]on which you can resolve, and keep on doing it until you find a
null[br]condition, which is a contradiction.


If you don't find a null condition,[br]if you don't find a contradiction, that means that what you[br]started with
cannot be proved.


44 - Assignment Logic
---------------------

So how would you use formal logic to[br]develop an agent that can solve Raven's progressive matrices?


As with production systems, we can kind[br]of face this at two different levels.


One, you could use formal logic to[br]represent the overall algorithm the agent uses to solve any new problem.


Or secondly, the agent could use formal[br]logic to develop its understanding of a new problem that just came in.


It could then use those formal rules to[br]develop the transformations that occur within the problem and transfer
those[br]transformations into the new answer.


Alternatively, you could also use formal[br]logic to allow your agent to prove why it's answer to a
particular[br]problem is correct.


Then if the answer is[br]actually incorrect, the agent may have the information[br]necessary to go back and repair it's
reasoning and[br]do better next time.


45 - Wrap Up
------------

So today, we've talked about formal[br]logic in order to set up a kind of formal language for[br]us to reason with going
forward.


We started off by talking about formal[br]notation, including conjunctions and disjunctions, so that we can[br]write
sentences in formal logic.


We use that to then talk[br]about truth tables, and exam some of the properties that we need[br]going forward, like De
Morgan's law.


Using that, we investigated some of the inferences[br]that we can draw using formal logic.


And finally, we looked at proof by[br]reputation which kind of capitalizes on everything we've talked about so far.


Next time, we'll be discussing planning, which leverages the formal logic[br]that we've developed in this lesson.


It allows agents to reason more[br]formally about initial and goal states.


Interestingly, planning actually has its[br]history in the kinds of proofs we've developed here.


Originally, agents would prove that[br]a particular plan would work, so that's why we talk about formal[br]logic before
we talk about planning.


46 - The Cognitive Connection
-----------------------------

The connection between logic and[br]human cognition is interesting.


Logic is a very important school of[br]thought in AI, for several reasons.


One reason is that logic provides a very[br]formal and precise way of reasoning.


Another reason is that logic provides[br]a formal notation for expressing how intelligent agents reason, whether
or[br]not they're using logical reasoning.


But does this mean that logic[br]is also the basis of cognition?


It suddenly appears that humans[br]use logic some of the time.


For example,


I may have a statement like if I get[br]a big bonus, I'll take a long vacation.


I did get a big bonus, therefore I[br]may infer I'll take a long vacation.


This is clearly.


But simply because of a behavior appears[br]to be logical, does not necessarily imply that we use logic as[br]a
fundamental reasoning strategy.


I might solve a new problem, by analogy[br]to a previously encountered problem,


I did not use logic, but[br]my behavior appears to be logical.


The logic that we have considered so[br]far is deductive logic.


But a lot of human reasoning is[br]inductive or abductive in its character.


If you haven't come across[br]an abductive so far, we will discuss in detail[br]later in the class.


Deduction has to do with[br]reasonings from causes to effects.


Abduction has to do with[br]reasoning from effects to causes.


When you go to a doctor,[br]you go with some signs and symptoms.


Those are the effects.


The doctor comes up with[br]a disease category.


That's the cause.


Abduction is reasoning from[br]data to an explanation to a disease category for the data.


Induction is given some relationship[br]between cause and effect for a sample.


How do we generalize it between[br]a cause and effect relationship for a population?


So while human reasoning appears to be[br]inductive and abductive in character much of the time, the logic that
we[br]have considered so far is deductive.


That's yet another issue that we'll[br]return to later in the class.


47 - Final Quiz
---------------

All right, write what you learned in[br]this lesson in this box right here.


48 - Final Quiz
---------------

Thank you for filling out this box.


It helps us understand how[br]the learning is going in the class.


