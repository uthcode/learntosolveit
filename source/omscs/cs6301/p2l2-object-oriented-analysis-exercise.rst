.. title: P2L2 Object Oriented Analysis Exercise 
.. slug: P2L2 Object Oriented Analysis Exercise 
.. date: 2016-05-27 23:39:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L2 Object Oriented Analysis Exercise
======================================


01 - Analysis
-------------

As you know, this is a class about design.


And the question is, how do you get started doing a design? Well, before you can solve a problem, you need to understand
it. And the process for understanding a problem is called analysis. In this lesson, we will be concerned with a specific
type of analysis called, Object-Oriented analysis, or OOA.


02 - Object Oriented Analysis OOA
---------------------------------

OOA is a requirements analysis technique developed by Abbott and


Booch in the 1980s. It concentrates on modeling real-world objects based on their descriptions in natural language to
produce an object analysis model.


We will express these models primarily using UML class model diagrams.


Object oriented analysis pays primary attention to the objects with which a problem's concerned. Prior to OOA, on the
other hand, the predominant method of analysis is analysis and design. With structure design, also called functional
decomposition. In contrast with OOA, functional decomposition was concerned with the functions that the solution, that
the solution was required to provide rather than the objects.


03 - Object Quiz
----------------

To get you started thinking about this, I'd like you to, for a moment, reflect on why objects might be a better starting
point for analysis than functions. Choose among the following four possible reasons.


First, functions are provided by all programming languages, whereas many languages don't include objects. Second choice,
during maintenance functions change more frequently than objects. Third, functions are too mathematical. And fourth,
objects are a more modern technique.


Which of those do you think is the best answer?


04 - Object Quiz Solution
-------------------------

>> Well, you're right about that. Software systems have long lifetimes.


During which they undergo evolutionary change.


Unless, the responsible developers are careful. The original structure of the program may be lost as features are added,
bugs fixed and libraries migrated. For example, consider a banking application. Over time, the particular functions such
as interest computation, fees and tax rules may change. All of these are functions. However, the need to represent
accounts, account holders and transactions. All of which are objects, will continue.


That is objects are more stable than functions, over the lifetime of a system.


Hence, designing a software around them, leads to more sustainable designs.


05 - Object Oriented Analysis and Design
----------------------------------------

Structured analysis and design techniques are functionally oriented.


They concentrate on the computations that need to be made.


The data upon which the functions operate are secondary to the functions themselves. Object Oriented Analysis and


Design on the other hand is primarily concerned with the data objects.


These are defined first in terms of their attributes and data types.


Later the functions are defined and associated with a specific objects.


06 - OOA
--------

Well how does OOA work? First it takes a textual description of a system to be built, such as a requirements document.
And looks for different kinds of words such as, nouns, verbs and adjectives.


It's goal is to use the identified words to built up descriptions of classes and their relationships. Nouns will
correspond to classes.


Action verbs to operations. Adjectives to attributes. And stative verbs to relationships. The resulting class model can
be reviewed with a customer for accuracy and completeness. Here is an overview of the steps involved


07 - Steps in OOA
-----------------

First off, candidate object classes are indicated by the occurrence of nouns in the natural language description of the
system to be built.


The nouns can then be organized into related groups termed classes.


The next step looks for adjectives, which often indicate properties that can be modeled as attributes.


Subsequently, action verbs can be modeled as operations and assigned to the appropriate provider class.


Other stative verbs are indi, indicative of relationships among the classes.


08 - Technique
--------------

More specifically, the actual OOA technique to apply is the following.


First off, obtain or prepare a textual description of a problem.


Underline in your textual description all the nouns.


Organize the nouns into groups to become candidate classes, then underline all the adjectives.


Assign the adjectives as attributes of the candidate classes.


Then, underline the verbs, differentiating action verbs from stative verbs.


Assign the action verbs as operations of classes, and assign the stative verbs as attributes of classes or
relationships.


Sounds simple, but we will also see that there are some stumbling blocks along the way, which we'll have to apply our
own thinking to, to solve appropriately.


09 - Step 1 Locate Nouns Quiz
-----------------------------

So let's see what happens when we try an example on this. I'm going to give you a paragraph describing a small program
for counting the number of leaves on a tree. A tree is a data structure consisting of nodes connected by directed arcs,
in which occurs a single root node from which all other nodes descend.


Nodes without outgoing arcs are called leaves, and the intent of the program is to count the number of leaves in a given
tree. Here's the paragraph description.


So counting tree nodes, keep a pile of the parts of the tree that have not yet been counted, initially get a tree and
put it on an, the empty pile.


The count of leaves is initially set to zero. As long as the pile is not empty, repeatedly take a tree off the pile and
examine it. If the tree consists of a single leaf, then increment the leaf counter and throw away that tree.


If the tree is not a single leaf but instead consists of two subtrees, split the tree into its left and right subtrees
and put them back on the pile.


Once the pile is empty, display the count of the leaves. Okay, step one, go through the description and underline all
the nouns, see what you get.


10 - Step 1 Locate Nouns Quiz Solution
--------------------------------------

>> I think you're right there. Pronouns are going to refer to something else that's already in the text, so you don't
worry about pronouns


11 - Issues
-----------

So here are some of the issues that arise when we try to accomplish the first step in OOA.


As Jared mentioned, some of the words are duplicated.


You know, we'll try to condense those and just have one copy of each of the words.


Some words share the same stem, for example, pile and piles.


And some words are, are close to each other and really share the same underlying concept like leaf and leaves.


And in these cases we're going to do what's called stemming.


Stemming removes the prefixes and the post fixes, the suffixes to the words, and just uses the root word as the
corresponding candidate and class.


That leaves us with a question that you, you, you indicated both counter and count, okay?


In this case, we're going to use our kind of discretion and say, let's for the, the moment treat those as separate
classes, even though by getting rid of the, the suffix on counter, we get the same word as count.


12 - Step 2 Candidate Classes Quiz
----------------------------------

>> Okay.


13 - Step 2 Candidate Classes Quiz Solution
-------------------------------------------

>> Counter? >> Sure. So, a counter's going to count something, and one of the possible things he is going to count is he
going to have values and one of the values that might have is zero. So I think you are right at this stage in saying,
let's not worry about zero as being a class. Okay? But we can't forget about it either.


Okay? It's going to, it's going to be part of our model eventually.


14 - Initial Class Model Diagram
--------------------------------

An object oriented analysis the above groupings that you've produced from candidate classes. In object oriented analysis
a class is a description of a group of related objects, these objects are also sometimes called instances.


We're going to use UML class model diagrams. And in those diagrams, classes are represented as rectangles, possible
vertically partitioned into sub-compartments. Thus, taking what you have, we can come up with some initial class model
diagram that has rectangles for counters and leafs and piles and parts and trees. And in your case in your case node.


15 - Caveats
------------

Note that like in any analysis process, the conclusions that we reach are always tentative. As we engage in the process,
we learn more about the problem, which may lead to revisions of our analysis. In fact, it was one of the early lessons
of software engineering, is that requirements documents are always wrong in the sense that they're incomplete, or
inconsistent, or they don't truly reflect what it is that the customer ultimately wants. And as an analyst it's your job
to elicit that correct description. And OOA can help you do that.


Questions that arise during OOA may require research on your part, or even going back to the customers. Often, the
customers may not have even considered, what you, what you bring up as a question. And will thank you for realizing that
there was more to the problem than what they originally had in my mind. Thus, the overall process of analysis is
inherently incremental, hopefully leading to a joint understanding between the analyst and customer so that the design
and implementation can proceed


16 - Step 3 Adjectives Quiz
---------------------------

So let's move on to the second step. We have some candidate classes, okay, and we're now going to look at the features
of those classes. And in object-oriented analysis, there are two candidate, two kinds of features.


One kind are attributes and these are going to correspond to adjectives, and the other kind is operations, which
correspond to the action verbs in the text.


So for the next step, I'd like you to go back to your textual list and this time, underline the adjectives, along with
the corresponding noun, indicate the corresponding noun that the adjective modifies. And then by underlining these
phrases and, and then combine them as you did with the nouns, we'll have candidates as candidate attributes for the
various classes. Take a crack at that now. [BLANK_AUDIO]


17 - Step 3 Adjectives Quiz Solution
------------------------------------

>> So you have a leaf counter. So let's examine these possibilities as candidates for attributes of the, of the classes.


18 - Adjective Issues
---------------------

Long is, is normally an adjective of some sorts, but that doesn't mean that every adjective is going to necessarily
contribute to this list of attributes.


So, it's fine to have one and then discard it as not being relevant.


Okay? You had single leaf, you have leaf counter.


We have this one set modify sub trees. There is another, call it a trick, another way of getting modifiers that aren't
directly, that don't correctly come from adjectives, and that is if you've got a prepositional phrase, such as parts of
the tree, or count of the leaves, you could think of tree parts. Okay? And leave counts and so on. So once again, the,
the, the simple rule of saying adjectives doesn't quite get you all the, all the way where you want to go. So, some of
the issues that arise when you, when you try this technique. Okay? As we said, parts of the tree doesn't appear.


In, in the natural language to be an adjective. However we still want to recognize that the word part signifies an
attribute of tree. Same for count of leaves. As you indicated the use of the word long even though it's, nominally a, an
adjective doesn't really contribute here in the sense of being a modifier for one of these classes. The phrase single
leaf, if we think about it for a minute, has to do with the count of the leaves.


This is a one, of a, of a potential different number of counts that leaves could have. That is, there's a count
attribute that has a value of one.


Okay, single being, single meaning one.


Similar to the phrase two sub trees can be interpreted as a count of the number of a sub trees, in the tree class.
Having a value of two


19 - Updated Class Model
------------------------

>> Okay. >> Okay? And similarly, we can do the same thing with Part, thinking of part of the tree being an attribute, of
the tree.


The tree class now has attributes for the left sub tree, the right sub tree, for leaves and for parts. The Pile class,
will have some kind of emptiness attribute associated with it. And we initially, we can say that's maybe a Boolean and
has a value of true or false depending upon whether it's empty.


And we can add all these into the diagram and we'll, we'll see, now that we've added a second compartment. Below the top
compartment which had the label the class, the second compartment, has the list of these attributes.


20 - Step 4 Operations
----------------------

Now let's look for candidate operations.


An operation is a computational service provided by an object.


In OOA, candidate operations are suggested by looking for verbs, particularly action verbs.


In addition to action verbs there are other kinds of verbs including linking verbs.


Which are typically associated with the word is, they're more likely to be descriptive, hence related to attributes
rather than to actions.


Another category contains the stative verbs, typically descriptions of situations rather than of objects.


And they're going to be indicative of relationships among the objects


21 - Action Verbs Quiz
----------------------

Well let's take one more crack at your, paragraph. And this time, go and look for action verbs and underline them.


22 - Action Verbs Quiz Solution
-------------------------------

>> Okay.


23 - Operations in Class Quiz
-----------------------------

24 - Operations in Class Quiz Solution
--------------------------------------

>> Sure, okay. So you can see the back and forth in trying to understand these things that goes on.


All the process we saw before of combining words together, stemming, and now trying to associate the various operations
with, with the classes.


25 - Operations in Classes
--------------------------

If we now try to summarize what we have so far, we have a pile class and its got operations. We can put a tree onto the
pile. We can get a tree from the pile.


We can take a tree off of the pile. For the counter we have increment and display. And for the tree class we have split
and throw away.


Now, a minute ago we talked about throwing away from the pile, and sometimes these things can go back and forth. For the
moment we are going to associate with the tree class. In our class model diagram we added a new compartment at the
bottom of the rectangle to hold the operations. In general, we could also at this time list of various arguments that go
arguments to the operations, what their types are, what is the type of the return value, or we could hold off that
process later.


What we are trying to do is get a feel for what the elements of the problem are, and how, how, how they are represented
in terms of attributes, and then what services the various the various classes can have in terms of operations.


26 - Operation Issues
---------------------

Some of the issues that arise from doing this, we talked about keeping a pile, and it's really the system as a whole
that keeps the pile and we're not going to explicitly represent the system ourselves. There was the phrase that we had,
has been counted, and really has been counted is more a description of a state then an action verb. Okay, so we could
say count is an action verb but has been counted as more a stative, or stative situations, so we're going to revisit
that when we get to looking at relationships. And the phrases is set to, examine, and consists of. Well if you think
about it those are really an expression of what is the case.


So, when you examine something, you find out what is the case there.


If you examine a counter, you get back the count. These are really ultimately going to be represented in our
implementation with some kind of eq, equality check. And so, we're going to assume that all the classes that we have
eventually come out with are going to have an equality operator associated with them. So we're not going to explicitly
model those at this time.


27 - Step 5 Relationships
-------------------------

Step five in the object or in analysis process has to do with relationships.


The main elements in the class model diagram are going to correspond classes and relationships. And we're going to
depict the classes ash compartmentized, rectangles and relationships are going to be indicated by lines connecting the
rectangles. And there are going to be three different kinds of relationships that we'll look at. One kind is
generalization, and that's indicated by a line at, and at one end of the line will be a little open triangle. The second
kind is called aggregation.


This is going to be used for situations like what we mentioned parts of, and in this case, the line ends with an open
diamond, and then if we don't have any adornment on the line at all, that's going to be a general association.


So let's look at each of those three categories of relationships and see if we can find examples of them in our, our
example problem.


28 - Generalizations
--------------------

The first kind of relationship we look at is generalization.


This relationship between two classes indicates that an instance of one of the two classes, the child class are, are the
instances of one of the two classes are a kind of instance of the other class, called the parent class. This means that
the instances of the child class are the subset of the instances of the parent class. In our text, words like kind of
and type of, indicate a generalization relationship.


Even if these words aren't explicit in the text, the class names, themselves, can serve as indicators. For example, cars
are a sub class of vehicles.


29 - Generalization Quiz
------------------------

So implicit in our text, it's not there explicitly is a generalization relationship. Can you, can you guess what it is?
You kind of men, you kind of mentioned this earlier on


30 - Generalization Quiz Solution
---------------------------------

>> So, let's add to our diagram a a rectangle for leaf and make it a specialization of the tree class. That is, tree is
a generalization of leaf. And we indicate that by a line between the two.


And there's a little open triangle at the, at the tree end of the relationship.


What that meant was, that we took the leaf attribute outside, that was inside the tree class. And made it now, a
separate, separate class


31 - Aggregations
-----------------

The second kind of relationship to look for are aggregations. Aggregations are some kinds of collection, or set of
things.


An aggregation is heralded in text by words like consists of, part of, contains, has, incorporates or belongs to.


32 - Aggregation Quiz
---------------------

Can you think in our example of instances in the description of leaf counting, where aggregation relationships might be
indicated? [BLANK_AUDIO]


33 - Aggregation Quiz Solution
------------------------------

>> Right.


34 - Associations
-----------------

Generalizations and aggregations are two specific structural relationships, between classes. More general, is the idea
of association. For example, went to school at, is an association between the university class and the student class.
Stative verbs, denote a state of being. For example, the house sits on top of a hill. Stative verbs, often indicate
associations.


In class models, associations are indicated by lines connecting the associated classes. There are no special adornments
on the ends, but the line is usually labeled with the name, of the association.


35 - Associations Quiz
----------------------

In the tree counting example, there are no explicit associations indicated.


However, there is an implied association. Can you determine what it might be, and what classes it associates?


36 - Associations Quiz Solution
-------------------------------

>> Okay, so there's and association between the counter and the leaves, okay.


And we indicate that by a line, and we can come up with a label on it that says.


Count the, count the leaves in or just counts there. When we have, when we have done that, when we have added that line,
when we now have our, our, our class model diagram relatively complete and it's gotten a little bit more complicated
than we might have thought. If we have four classes, there's one generalization relationship. There's a couple of
aggregations.


There's general association. And then there are some, attributes and operations.


37 - Relationship Issues
------------------------

Some of the issues that arise when we try to determine relationships.


First of all, all of the indicated classes are really part of an overarching TreeCountingSystem class, as we mentioned
before.


Such system classes are not normally displayed in these diagrams. But you can think of each of the rectangles as being a
part of, or an attribute of.


The, this overarching class. The textual description from which we, began was not truly characteristic, obviously, of
typical requirements documents, which can go on for hundreds of pages and have lots of specialized vocabulary. Also, we
went into implementation details. It was actually describing an algorithm.


Requirements documents don't necessarily describe solutions, they describe problems. In general it is important to
distinguish the analysis and design phases of a software development effort in order to avoid prematurely biasing the
approach taken towards solution.


38 - Summary
------------

So to wrap this up, Object Oriented Analysis is a valuable first step to take during a software development effort.


It can get you started in understanding the problem to be solved, and suggesting a breakdown of a solution system
indicate, its component parts.


However, as with all analysis techniques, it is important to validate the results with other stakeholders, and
particularly with the customer.


