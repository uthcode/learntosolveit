.. title: 20 - Constraint Propagation 
.. slug: 20 - Constraint Propagation 
.. date: 2016-01-23 06:50:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===========================
20 - Constraint Propagation
===========================


01 - Preview
------------

Today, we'll talk about constraint propagation, another very drawn out purpose method. Constraint propagation is a
mechanism of influence where the agent assign values to variables to satisfy certain conditions called constraints.


It is a very common method in knowledge-based AI, and there are a number of different topics, such as planning,
understanding, natural language processing, visual spatial reasoning. Today, we'll start by defining constraint
propagation.


Then we'll see how it helps agents makes sense of the world around it.


Our examples will come mostly from understand natural language sentences, as well as visual scenes.


Finally, we'll talk about some advanced issues of constraint propagation.


02 - Exercise Recognizing 3D Figures
------------------------------------

To illustrate the technique of constraint propagation, let us consider this figure drawn on a 2D surface. Although this
figure has been drawn on a 2D surface, you and I can almost immediately recognize that this is a 3D cube.


How did we recognize that this is a 3D cube?


How can we help machines do it? Cube is an example of a trihedral object.


A trihedral object is one with three surfaces joined at a particular point, at this particular point. In general, what
[UNKNOWN] a polyhedral surfaces.


A polyhedral surface is one where multiple surfaces join at the same point. So a soccer ball, with its white and black
patterns, is an example of a polyhedral object because at one point several surfaces can join. A pyramid is another good
example of a polyhedral object. A pyramid has four surfaces joining, at the apex. So let's do a simple exercise
together. Here are six figures all drawn on a 2D surface. Which of these six figures do you think represents a 3D
object?


03 - Exercise Recognizing 3D Figures
------------------------------------

>> And this brings us to the point of this exercise. The point of the exercise is that clearly some kind of processing
is occurring in our visual system.


That allows us to group these lines and these surfaces and waves, so that we can identify which one of them is a 3D
object, and which one of them is not a 3D object. Clearly this processing is not completed definitely and that, that
sometimes there is ambiguity. You might come up with one answer to this, and someone else might come up with a slightly
different answer to this, because the processing leaves the room for ambiguity


04 - Exercise Gibberish Sentences
---------------------------------

To look more deeply into the processing that might be a [UNKNOWN] visual system, that allows us to identify which
objects are 3D objects and which ones are just 2D. Let us consider a different example. Shown here are six sentences.
None of the sentence makes much sense semantically.


Nevertheless, some of the sentences are grammatically correct. And you and


I can quickly detect which of the sentences are grammatically correct.


Can you identify which of the sentences are grammatically correct?


05 - Exercise Gibberish Sentences
---------------------------------

>> Note the vocabulary that David used in trying to find out which of these sentences were grammatically correct. It
seemed to me that he was examining the structure of these sentences was fulfilling certain conditions, or fulfilling
certain constraints that he expects from his knowledge of English language grammar. One could even say that he was doing
constraint processing.


06 - Constraint Propagation Defined
-----------------------------------

>> So we've actually come across this idea of constraints in


English language grammar before. During our lesson on understanding, we talked about how a preposition for example can
constrain the meaning of the word that follows it. If we see the word from for example, we expect what comes after it to
be some kind of source for the sentence. There we used grammatical constraints in service of some kind of semantic
analysis. Here, we're just using grammatical constraints to figure out if a sentence is grammatically correct or not.
There's another connection here to understanding as well. [INAUDIBLE] Talked about how we can interpret this shape as
either popping out towards us or down into the screen. We talked about two simultaneously accurate interpretations of
the same thing and understanding.


With regard to sentences that can be read as puns. So, for example, when I said, it's hard to explain puns to
kleptomaniacs, because they always take things literally, the word, take, can simultaneously be interpreted as interpret
and physically remove, while satisfying all the constraints of the sentence.


07 - From Pixels to 3D
----------------------

Let us look at the details of constraint propagation. To do so, we'll take a specific example from computer vision.
Here's an example of a 2D image composed of a large number of pixels. The greyness at any one pixel is a depiction of
the intensity of light at that pixel. Now of course, you and can immediately recognize that this is a cube. But how do
we do it, and how can we make a machine do it? [UNKNOWN] decompose a task of 3D object recognition into several several
sub-tasks. Miles said in the first sub-task, a visual system detects edges, or lines as shown here. At this particular
point, no surfaces have been detected. In this particular point, no 3D object has been fignized. Just these pixels have
been put into lines based on the intensities of light in different pixels. According to Miles the second sub task of
object recognition consists of grouping these lines and the surfaces with orientations, as indicated here. So now these
four lines have been grouped into the surface, and then orientation defined by the perpendicular the surface, and
similarly these four lines, and these four lines. In the third and final phase of the object recognition task, according
to Miles surfaces are grouped into a complete 3D object. At this particular point, your visual system recognizes that
this is a cube. Miles theory has been very influential in computer vision. It has actually also been influential in AI
as a whole. One of the lessons we can take away from Miles' theory of computer vision of object's recognition is that
before we get into our guarded tones for addressing the task, we want to understand how a task gets decomposed into sub
tasks. Throughout this course, we have emphasized task decomposition repeatedly.


As an example, when we were talking about understanding, a big task of understanding got decomposed into a series of
small tasks.


Where surface level cues acted as probes into memory and a frame was retrieved. The slice of the frames dented
expectations.


Lexicon and grammatical analysts led to the identification of objects and predicates that would satisfy those
expectations. And the fillers were put in.


Problem reduction certainly is a general purpose method for decomposing complex tasks into smaller tasks. This notion of
class decomposition is a powerful idea irrespective of what algorithm we use for any of these specific sub tasks


08 - Line Labeling
------------------

Of course, I will focus here is on constraint propagation, not on computive vision, we are simply using some aspect of
computive vision to illustrate constraint propagation. In particular, let us zoom into a specific subtask of object
recognition, In this subtask, lines are grouped into surfaces and the orientations of the surfaces are identified via
the perpendiculars. The method we'll use for this task is called, line labelling, the method of line labelling makes
extensive use of constraints.


09 - Constraints  Intersections and Edges
-----------------------------------------

So let's take the notion of constraints. Consider this cube again. You'll notice this cube has junctions, and these
junctions have different kind of shapes. For example, this looks like a Y junction, this looks like an L junction, this
also looks like an L junction, it's just that this arm of the L is coming in the other direction. This also looks like
an L junction. This junction, on the other hand, looks a little bit like a W junction. So, junctions of various kinds.
Here are the kind of junctions that can occur, in the world of trihedral objects like cubes. Y junction, W junction, T
junction,


L junction. We can say a little bit more about each of these junctions.


Let us look at the Y junction first. If we examine the various kinds of


Y junctions that get formed in the world of trihedral optics, then we find that whenever there is a Y junction formed,
then each of these lines represents a fold, where a fold is a line where two surfaces meet.


Now, the important thing about this is. That if we can infer, that this is a Y junction and that this line represents a
fold, then an image that follows, this line must also represent a fold, and this line must also represent a fold.


Actually I should tell you quickly, that in the world of trihedral objects.


Y junctions can have multiple kind of constraints. But right now, let's just look at this one single constraint. So in
the case of an L junction, which has a shape like this, in the world of trihedral objects, an L junction is
characterized by this being a blade, and this being a blade, where a blade is a line, well we cannot infer that two
surfaces are getting connected with each other. Again, the L-Constraint can actually have many more formulations. But
right now, we're keeping it simple just looking at one single constraint for the L junction. Similarly, in the world of
trihedral objects, one of the ways in which a double junction gets characterized is through a blade, fold, blade. In
effect, we're defining a spatial grammar here, for the world of trihedral objects. The equivalent of this, in case of
grammar of natural language sentences might be that a sentence can have a non phrase, followed by their verb phrase,
followed by a propositional phrase, and so on.


Given this set of very simple constraints for the world of trihedral objects, let us see how these constraints actually
can be propagated, to group edges and to surfaces


10 - Exercise Assembling the Cube I
-----------------------------------

Let us do an exercise together. Here is a cube with its seven junctions. For each of these junctions, identify the kind
of junction that it is.


11 - Exercise Assembling the Cube I
-----------------------------------

>> This sounds good and now let us look at how we will apply these to identify the surfaces


12 - Exercise Assembling the Cube II
------------------------------------

Let us do another exercise together. We have identified the type of each of these junctions. Let us now use, the
constraints for each type of junction to identify the type of each of these edges. For each of these boxes, right?
Either fold or blade for the type of the edge.


13 - Exercise Assembling the Cube II
------------------------------------

>> That's good, David. Note that David started on the top left corner, this is a random selection. He could have started
at any other corner, for example, this one or that one. And found the same answer and that is because we have simplified
these constraints. But now that we know that this line is a fold, by the definition of fold, we know that two surfaces
must be meeting at this line. It follows then, that this must be a surface and this must be a surface.


Similarly, because we know this is a fold and by definition of a fold, two surfaces must be meeting here. Follows this
is a surface, this is a surface and so on. And now we have identified that this one surface, this is another surface,
this is a third surface. In this way, the visual system used knows the different kinds of junctions in the world of
triangular objects, and it constrains at each of these junctions to figure out which of these lines made surfaces.
Instead of thinking of this as one single surface, the visual system identified this as being composed of three
different surfaces.


And now we can recognize that this might be a cube.


14 - More Complex Images
------------------------

>> Now of course, some of us do see this as a 3D shape.


You can think of this as a paper folded here. One plane of the paper and another plane of the paper. This looks kind of
like an open book.


This particular line here then can be ignored, just being a line of these two planes, not signifying a surface by
itself. If you view this only as a line, and not signifying a surface then it adverses David's first problem.


But how do we address David's second problem of this being a fold or a blade depending upon where we started constraint
propagation from? The answer is that we actually have a much more complex ontology of disconnections.


The answer lies in the fact that we have so far used a very simple ontology, just to demonstrate the constraint
propagation process. In reality the ontology risk constraints is more complicated. Let's do Y-constraint may not just
fold, fold and fold, but it might also be blade, blade and blade.


And the L-constraint is not always blade and blade and fold and fold.


It could also be blade and fold and fold and blade. Now we can see


David's second problem disappearing, because the Y junction may have a blade and the L junction may also suggest a
blade. And there is then no conflict. Let me know that what we have shown here, is still not a full anthology of the Y,
W,


L and T constraints. T constraints in particular, may have additional complexity. The advantage of having a more
complete ontology is, that we can use that ontology to interpret more complex scenes like this one, where there are two
rectangular objects, one being partially occluded by the other one.


Of course, the more complicated ontology is not without its own problems.


It now introduces ambiguities of a different kind. This particular junction.


Is it now a blade, blade, blade, or is it a fold, fold, fold? Both of them are permissible in the new complete ontology.
In order to resolve some of these ambiguities, we can come up with additional conventions.


One convention is, that all of these edges that are next to the background, we'll consider them to be blades. So we'll
make this a blade, blade, blade, blade. Once you make all these blades, then it's easy to propagate the constraints.
Notice this W junction could have been a fold, blade, fold, or a blade, fold, blade. But if we adopt the convention of
labeling all of these lines as blades, then, this W junction can only be blade, fold, blade. But if this is a fold, this
Y junction can only be fold, fold, fold, and so on. And yet, helps us resolve the ambiguity of what this junction could
be.


This task of image interpretation is an instance of the abduction task.


In abduction, we try to come up with the best explanation for the data.


This is the data, we're trying to interpret it in terms of an explanation.


We'll discuss abduction in more detail when we come to diagnosis. Well now notice that, we start with what we know.
Blade, blade, blade. And that we propagate the constraints, so that we can disambiguate between other junctions.


15 - Constraint Propagation for Natural Language Processing
-----------------------------------------------------------

Let us again written to the center. Colorless green ideas sleep furiously. You and I can quickly recognize, that this
sentence is grammatically correct even as it is semantically meaningless. How do we do it? Consider this mini-grammar.


This is a small subset of the English language grammar consisting of just three simple rules. The sentence can go into a
noun phrase, followed by a verb phrase.


A noun phase can be, optional adjectives, followed by a noun or a pronoun.


The square bracket here means, optional. A verb phrase, composed of a verb, followed by optional adverb. The variables
in this particular sentence, are the words. The values we assign to them are elliptical categories like verb, objective,
noun and pronoun. If we can make a pastry for this, that assigned values to this variables in a way that is consistent
with this grammar, then this particular sentence is grammatically correct.


Let's try to make a pastry for this sentence. A sentence can a noun phrase, or a word phrase. So we may say, that this
is a noun phrase and this is word phrase. Of course at this particular point we do not know, where we should make this
demarcation, what should go into the noun phrase, what should go into the word phrase? We know whether or not, this
demarcation is correct depending upon whether or not this noun phrase, and word phrase meet the low level lexical
categories. So let's look at colorless green ideas. We know that a noun phrase can go into one or more adjectives,
followed by a noun or pronoun. So we can look at a lexicon, and know that ideas are a noun, so we say that this is a
noun.


We can look at a lexicon that tells us that colorless and green are adjectives, and so colorless and green are
adjectives here.


We have satisfied this part of the constraint. So I am ready for the verb phrase, a verb phrase can be composed of a
verb, followed by one or more optional adverbs. We can look in the lexicon, and sleep is a verb, and furiously is an
adverb, so we have satisfied the constraints for this particular part. Because we have satisfied the constraints, we
know the top level demarcation of this as a noun phrase, and this as a verb phrase was correct. So the processing is not
very top down here.


It also has a bottom up component. In this way we are able to decide, that this particular sentence is grammatically
correct because it satisfies the constraints of [INAUDIBLE] grammar. Know that we have used knowledge of constraints,
and the matter of constraint propagation, both for visual processing and for language processing. This sentence method
is very general purpose in doing independent. Once we have done constraint propagation, to derive the parse tree for the
sentence, then we can do additional processing.


We can use this parse tree to support semantic analysis to build an understanding, a semantic understanding, of the
sentence.


Similarly, in visual processing, once we have used the constraints for doing line labelling. And recognize the surfaces
and their orientations.


We can then go on further and recognize the object in its 3D form.


16 - Assignment Constraint Propagation
--------------------------------------

So how would constraint propagation be useful for Raven's progressive matrices?


This concept has a strong correspondence to the final project where you'll be asked to reason over the images of the
problem directly instead of over the propositional representations that we've given you in the past. So first, if
constraint propagation leverages a library of primitive constraints, what will your constraints be for the final
project?


How will you propagate those constraints into the image to understand it?


Then once you've actually propagated those constraints, how will you actually use those inferences? Will you abstract
out propositional representations? Or will you stick to the visual reasoning and transfer the results directly?


17 - Wrap Up
------------

So today we've talked about constraint propagation, which is a method of inference where we assign values to variables
to satisfy certain external constraints. By doing so, we arrive at strong inferences about the problem, like which
shapes represent objects, or how the words in a sentence interact. After defining constraint propagation, we talked
about how it can be useful in interpreting images by using prior knowledge of constraints to anticipate predictable
shapes out in the world.


Then we talked about natural language understanding, where prior knowledge of the rules of grammar and parts of speech
allow us to make sense of new sentences. Now, constraint propagation is actually an incredibly complex process. We have
numerous constraints for visual scenes and verbal sentences that we haven't discussed here. We all see this constraint
propagation in other areas as well, such as in making sense of auditory and tactile information. Reading braille for
instance, can be seen as an instance of constraint propagation. We'll pick up on this discussion later when we talk
about visual and spatial reasoning.


But this will also come up in our discussion of configuration, which can be seen as a specific instance of constraint
propagation in the context of design.


18 - The Cognitive Connection
-----------------------------

Constraint propagation also connects to human cognition.


First, constraint propagation is a very general purpose method like, means analysis. In both knowledge based AI and in
human cognition, constraint propagation allows us to use our knowledge of the world, in order to make sense of it.
Constraints can be of any kind. Symbolic, as well as numeric. We discussed symbolic constraints in today's lesson.


A good example of numeric constraints comes from XL spreadsheets, with which most of you are familiar. If the columns in
a particular spreadsheet are connected to some formula, and you make a change in one column, then the change is
propagated into all the columns of the spreadsheet.


That's an example of Numerical Constraint Propagation.


We have seen constraint propagation under other topics as well.


For example, planning, and understanding, and scripts. The next topic, configuration, will build on this notion of
constraint propagation.


19 - Final Quiz
---------------

All right. Please write down what you understood from this lesson, in the box right here.


20 - Final Quiz
---------------

And thank you for doing it.


