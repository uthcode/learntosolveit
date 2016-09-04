.. title: 14 - Understanding 
.. slug: 14 - Understanding 
.. date: 2016-01-23 06:44:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

==================
14 - Understanding
==================

01 - Preview
------------

Today, we will talk about understanding. Understanding is a very big general world. We'll be talking about understanding
of even some stories in the world.


Understanding will be very heavily on what we learn about Frames. And it will help us set up the infrastructure for
learning about common sense reasoning in the next lesson. We'll start with talking about thematic role systems, which
are the most structured type of frame representation. Then we'll talk about how these roles, these thematic roles can be
used to resolve ambiguity in understanding the world. Finally, we'll talk about how grammar and other constraints can be
used to guide our interpretation of the world.


02 - The Earthquake Report
--------------------------

We'll use story understanding,


To examine the general[br]processes of understanding.


Here are two stories that we[br]have encountered earlier.


The first story is talking about the[br]earthquake that hit lower Slabovia and caused some damage.


The second story is talking about the[br]President of lower Slabovia who killed a number of proposals.


Both of them deal with killing.


But the meaning of the two[br]stories are very, very different.


Humans make use of stories to[br]understand the world around them.


The world offers a very large[br]amount of data at any given time.


We use the stories to provide[br]structure to that data, to make coherent sense of it.


When we discuss these[br]two stories earlier, using frame as a knowledge[br]representation language, we found that we
could have[br]a frame of this notion of killing, killing of 25 people, and this notion[br]of killing, killing of 25
proposals.


And there was no simple way in[br]the frame knowledge representation to disambiguate between those[br]two meanings of
killing.


Now we'll examine how we can construct[br]a different interpretation of the first story, or[br]the interpretation of the
second story, based on different interpretations of[br]the word killing in the two stories.


In order to make the two[br]stories simpler, and to illustrate our point, we're going to[br]focus on one sentence from
each story, sentences that contain the word kill.


Humans that have lived[br]through difficulty and understanding the first sentence means[br]completely different from the
second sentence because the killed in the first[br]sentence means something completely different from the killed[br]in
the second sentence.


How can we build an err program[br]that can do the same thing?


We will see that err program will need[br]to use a lot of background knowledge in order to be able to do that,
and[br]that would generate hypotheses about how humans might be using that[br]background knowledge to similarly
disambiguate between different[br]senses of the word killed.


03 - Thematic Role Systems
--------------------------

Let us first consider a simpler sentence. So consider the sentence Ashok made pancakes for David with a griddle.


I'm sure you understood the meaning of this sentence almost immediately. But what did you understand? What is the
meaning of meaning? We can do several different kinds of analysis on this sentence. We can do lexical analysis, which
will categorize each of these words into different lexical categories. For example, Ashok is a noun, made is a verb,
pancakes is a noun, and so on. We can do syntactic analysis. In terms of the structure of this particular sentence.


So, you might say Ashok is a non phrase. Made pancakes for David with a griddle is a verb phrase. And this particular
verb phrase itself has sub phrases in it.


Or we can do semantic analysis on this, and say that Ashok was the agent.


Made was the action. Pancakes were the object that got made. David was the beneficiary. Griddle was the instrument. The
knowledge base here as oppose to understanding stories like this. Semantic analysis is at a forefront.


Syntactic analysis and lexicon analysis will serve semantic analysis. So here are some of the semantic categories in
terms of which we can classify the different words in the sentence. So Ashok is an agent, made is an action or verb in
the lexical sense, pancakes are the thematic objects, the things that are getting made and so on. The frame for
representing understanding of this sentence has the verb of the action make, the agent Ashok, and so on just like we
just discussed. This then is the meaning of meaning. This is what the agent understands when it understands the meaning
of this sentence.


This is perhaps also what you understand when you understand the meaning of this sentence. How do we know that you
understood the meaning of this sentence?


Well, we know that because I can ask you some questions and you can draw the right kind of inferences from it. So for
example, given this sentence,


I can ask you, well who ate the pancakes? And you might be able to say, well David ate the pancakes because Ashok made
the pancakes for David.


Notice that this information about who ate the pancakes was not present in this particular sentence. This is an
inference you're drawing. This is a very similar to what we had encountered earlier when we had sentence like Ashok ate
a frog.


At that time too, we'd ask questions like, well, was Ashok happy at the end?


And the frame had some default values which said Ashok was probably happy.


Or, was the frog dead at the end, and the frame for eating had some default value which said that the frog was dead at
the end?


So according to this theory, the meaning lies in the inferences we can draw from it. You understand the meaning of this
if you can draw the right inferences. You do not understand the meaning of this if you cannot draw the right inferences
or if you can draw only the wrong inferences. This frame representation of the meaning of this particular sentence
allows you to draw the right inferences.


Given the action make here, the thematic role pertains to the relationship of various words in the sentence. To this
particular action of making.


Ashok is the agent, David is the beneficiary, and so on. So far we are describing meaning of this sentence, and how we
can capture that meaning in this frame. We have not yet described the process by which this knowledge is extracted out
of that sentence. The extraction of the meaning of this sentence is exactly the topic that we will discuss next.


04 - Thematic Role Systems
--------------------------

>> Not that even though David isn't talking about a specific instance of throwing, he's still able to generate an
expectation of the general action of throwing. This is what a temeric case fame does for you. It is able to generate
expectations. Let us look at how it would actually work in action.


05 - Exercise Thematic Role Systems
-----------------------------------

Now that we understand how to represent the meaning of stories, let us consider a different story. David went to the
meeting with Ashok by car.


Please write down the meaning of this story, in terms of the slots of this particular thematic role frame.


06 - Exercise Thematic Role Systems
-----------------------------------

>> That's right, David. But how did we know that David was the agent?


How did we know the destination was the meeting?


How did we know that car was a conveyance? That's what we'll look at next.


07 - Constraints
----------------

Let us use the assignment of car as the conveyance, to illustrate how these different words get assigned to different
categories, different slots in this frame. Now, we know that car was a conveyance because of the role that this
preposition, by, plays here. That is, an intelligent agent might make use of the structure of the sentence to make sense
of the story. We have designed human language in such a way that there is a particular structure to them. Prepositions,
for instance, play a very important role. Here are some of the common prepositions: by, for, from, to, with. Each
preposition plays certain thematic roles.


By can be an, by an agent, or by a conveyance, or by a location. Similarly for the other prepositions. So the moment we
see by, here we know that, whatever is going to come after by, the care can be a agent, or a conveyance, or a location.
Note again that the categories we are using here are semantic categories, we are not saying noun, or verb or anything
like that, what we are saying here is beneficiary and duration, and source which are semantic categories, that allow us
to draw inferences. But how did we know that car was a conveyance, and not an agent, or a location?


In general, while the structure of language does provide constraints, these constraints do not always definitely
determine the meaning of that particular word. We'll use additional knowledge to find the exact meaning of the word car.


08 - Resolving Ambiguity in Prepositions
----------------------------------------

But first let us look at examples of the three kinds of semantic categories that by point to. So here is a sentence in
which by points to an agent. That was written be Ashok. Actually, this particular sentence was written by David.


The second sentence, David went to New York by train, here by is pointing to a conveyance. David stood by the statue.
Here, by it is pointing to a location.


By the statue. So the use of the word by helped us, in that it constrained the interpretation of Ashok to either an
agent, conveyance or location. It by itself doesn’t tell us whether Ashok is an agent or a conveyance or location. We
need some additional knowledge. Let us suppose that the agent has an ontology of the world. The term ontology initially
comes from philosophy where it means the nature of reality. An artificial intelligence determine ontology often
reference to the conceptualization of the world.


The categories and terms of which I specify the world.


These categories have become the vocabulary of the knowledge representation. So let us supposed that the agent has this
ontology of the world.


The world is composed of things, and things can be agents or objects or locations. Agents are people, and Ashok and
David are examples of agents.


Objects can be conveyances. And trains and cars are examples of conveyances.


Obviously this is a very small part of someone's ontology about the world.


Now this ontology helps us decide that Ashok, in the first sentence, is an agent. Let's see how. Here we have by Ashok,
and we know from the prepositional constraints that by can refer to an agent, conveyance, or location. So the question
now becomes, is Ashok an agent,


Ashok a conveyance, or Ashok a location? We can look into this ontology.


Ashok is people, which is an agent. So now we know, that Ashok must be an agent. Similar the second sentence. Train can
be an agent, conveyance or location. Let's look at our ontology. A train is a conveyance. So now we know the train is a
conveyance. Similarly for statue.


Statue in this case specifies a location. Note that this analysis applies to different prepositions, not just to by.
Supposing this first sentence was,


That was written with Ashok. In which case, this preposition with will point to


Ashok either being a coagent or being an instrument. So again, we now know that Ashok is a coagent in the sentence which
contain the preposition with. There is another important thing to note here.


Initially, when we were give this sentence, David went to New York by train, we started doing bottom-up processing.
David was a noun, went was a verb. But pretty soon we shifted to top-down processing. As an example, you already have
this background knowledge, and this background knowledge tells us in a top-down manner that by, here, can refer to an
agent, a conveyance, or a location. We also have this additional background knowledge, and this background knowledge
tells us that in this particular sentence.


The train describes frame to a conveyance, because train is a conveyance in this ontology. So low-level bottom up
processing generates queues, which access probes into memory. Memory then returns knowledge like this, and the
processing becomes top down. The top down processing tells us how to interpret the various words in this sentence, how
to make sense of this story.


09 - Ambiguity in Verbs
-----------------------

>> Did you know that knowledge based AI was going to be t his much fun? Our goal going forward is to look at how agents
may resolve some ambiguities, when one correct meaning, and only one correct meaning is possible. Note however, that we
might already have [UNKNOWN] theory of humor. Perhaps, one form of humor is, when a single sentence can be made to fill
multiple [UNKNOWN] simultaneously.


10 - Resolving Ambiguity in Verbs
---------------------------------

We saw in the previous example how sentences in a story can be ambiguous. For example, by, could have referred to an
agent, a conveyance, or a location.


This is true, not just for prepositions, but is also true of other [UNKNOWN] categories, like words. In fact, words
often can have several interpretations.


Let us consider the word take as an example. Take is a very common word.


It has at least these 12 different meanings. Consider for instance to medicate.


Ashok took an aspirin. Here, the meaning is that Ashok took aspirin as a medication. Each of these meanings has a common
meaning of take, as we will say in just a minute. But given a sentence in which take occurs, how do we know which of
these meanings is intended by the word, take? So suppose the input sentence was, my doctor took my blood pressure.


The taken in this sentence refers to, to measure and not to any of the others.


Let us examine this issue further. So, for each of these 12 interpretations of take, we have a frame-like
representation. So take 1 to take 12.


Each of this frame-like representation specifies the thematic roles that go with that particular meaning of take. So in
this particular meaning of take, take 1, we have an agent and an object. In this meaning of take, take 12.


We have an agent, an article, and a particle. Another word that typically occurs with take which signifies this meaning,
so to take clothes off from a body.


Let us consider another example of particle. Let us consider take11.


The meaning of this take is to assume control, as in to assume control of a company, or to assume control of a country.
When the meaning is intended to be to assume control, then take typically occurs with the word over.


Take over a company. Take over a country. So, over then is a particle that signifies this eleventh meaning of take. To
go deeper into story understanding, consider the simple story I took the candy from the baby. What is the meaning of the
word take here? You and I get this immediately, but how can an agent get it?


To keep it simple, we have shown here just nine meanings of take, you could have added the other three as well. Although
we started with bottom-up processing, we're now going to shift to top-down processing. Because there's something about
the background knowledge about candy that we have, which is going to eliminate lots of choice. In particular, we know
that candy is not a medicine, so this particular choice goes away. We know that candy is not a quantity, so this choice
goes away. Several of these choices disappear, because of our background knowledge of candy. Just like some of the
constraints came from our background knowledge of the semantic category of candy, other constraints come from our
background knowledge of the preposition, from. In the table showing prepositions earlier, from referred to a source.


These three frames do not have anything to do with the source, and therefore we eliminate them. We're left only with
this particular frame, which has source in it as required by the preposition from. And thus we decide that the
interpretation of took in this particular sentence is to steal from a baby. And thus we infer the correct interpretation
of take, in this particular sentence. It refers to, to steal. This is the only frame that is still active


11 - Exercise Resolving Ambiguity in Verbs
------------------------------------------

Now that we have examined how the thematic role frames help us disseminate between different meanings of take, let us do
some exercises together. In fact, let's do three exercises together. Here are three sentences. Please pick a box which
best captures the meaning of take in each of these three sentences.


12 - Exercise Resolving Ambiguity in Verbs
------------------------------------------

>> Feel free to take up that discussion over on our forums, especially if you yourself don't speak English as a first
language.


You might be particularly aware of the different structures present in


English compared to whatever language you speak natively.


13 - The Earthquake Sentences
-----------------------------

So let us now return to our original example of these two stories and see how the analysis we have done, this semantic
analysis, can help disambiguate between the two meanings of kill here.


So, first my background knowledge tells me that kill can have several meanings, just like take had several meanings
earlier. Kill can have the meaning of causing the death of someone, or kill can have the meaning of, to put an end to
something. There could be other meanings of kill as well.


Second, my background knowledge tells me that when kill has the meaning of, to cause the death of someone, it typically
is a victim as well as an agent.


In this particular case, the victim is 25 people, the agent is a serious earthquake. My background knowledge also tells
me, that when the meaning to kill is to put an end to something, then typically it is both an agent that puts an end to
something and an object that gets put an end to. In this particular case,


25 proposals is the object, and the agent is President of Lower Slabovia. It is this combination of background knowledge
that allows me to infer the meaning of, kill, in the first sentence as, to cause the death of, someone. And kill, in the
second sentence as, to put an end to something. I hope you can appreciate the power and beauty of this theory. But it is
also important to point out that this theory has many limitations. To understand some of the limitations of this theory,
let's go back to the sentence, I took the candy from the baby. In this sentence, we inferred that took signifies
stealing the candy from the baby. And in fact, we had a large number of rules that told us how to make sense of the word
take by making sense of the word candy, making sense of the word from.


But as we look at increasingly large number of forms of the sentence, the number of rules that we need starts exploding.
So consider small variations of the sentence. I took the candy for the baby. I took the toy from the baby.


I took the medicine from the baby. I took the smile from the baby.


I took a smile for the baby. They're all valid English language sentences, and each one of them tells a story. As I look
at more and more variations of this sentence, I'll need to find more and more rules that can disambiguate between
different interpretations of cake in those variations of sentence.


In practice it turns out that it's very hard to enumerate all the rules for all the variations of sentences like this
one. Nevertheless, the story appears to cover a good percentage of stories that we routinely deal with.


14 - Assignment Understanding
-----------------------------

So how would you use the notion of understanding [UNKNOWN] frames, constraint, and ambiguity to address Raven's
progressive matrices? One example of an application here, would be to the idea of multiple possible transformations,
that we saw in some of our earlier problems.


We saw certain problems that could be solved with either rotation or a reflection, but they would give different
answers. You might imagine a frame that dictates certain expected values for different transformations. And the degree
of fit to those expectations can dictate the accuracy of that particular answer. Try to think of the different phases of
the understanding process. How do you first understand what's happening in the problem?


How do you fit that, into a thematically role frame representation? And how would that representation then help you
transfer and solve the problem?


15 - Wrap Up
------------

So today we've talking about understanding, which how agents make sense of stories, events and other things in the world
around them. We started off by creating a more formal type of frame representation called thematic role systems that
captures verbs and tell us what to expect in certain events.


We then talked about how single verbs can actually have ambiguous meanings. But thematic role frames can help us
differentiate which meaning a verb has in a particular sentence. Finally we talked about constraints and how certain
words or frames can constrain the possible meanings of a sentence and help us figure out those ambiguous meanings. Today
we've largely been talking about how single words or phrases can have multiple possible meanings, but next time we’ll do
this in reverse. We’ll talk about how multiple words or multiple phrases or multiple sentences can actually have the
same meaning.


We'll talk about how we can discern that sameness, and then react accordingly


16 - The Cognitive Connection
-----------------------------

In the lesson today, all of our examples came from natural language understanding. But understanding is a very journal
purpose cognitive task.


Natural language understanding is just one instance of understanding.


Understanding is about making sense of the world.


The world bombards us with data that comes in many forms. Acoustic, visual, verbal, numerical. It's a very hard problem.
How do we make sense of the world?


There are three sources of power. First, we exploit constraints about the world.


We know that the world behaves in certain ways. Whether it's a physical world or the social world, or grammatical world.


Second, we have structured knowledge representations. The structured knowledge representations in memory capture not
just knowledge and its representation, but the organization of knowledge, and there is power in that organization.


The power lies in the third part. Low level problem with processing helps us activate these knowledge structures from
memory. Once activated, these knowledge structures generate expectations that make the processing top down. And there's
a lot of power in being able to generate those expectations.


17 - Final Quiz
---------------

Please write down what you learned in this lesson.


18 - Final Quiz
---------------

Great. Thank you very much.


