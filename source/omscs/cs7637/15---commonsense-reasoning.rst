.. title: 15 - Commonsense Reasoning 
.. slug: 15 - Commonsense Reasoning 
.. date: 2016-01-23 06:45:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

==========================
15 - Commonsense Reasoning
==========================

01 - Preview
------------

Today we'll talk about common sense reasoning. You and I, as cognitive individuals, are very good at common sense
reasoning. We can make natural, obvious inferences about the world. How can we help AI agents make similar common
sensical inferences about the world? Suppose I had a robot, and


I asked a robot, find the weather outside. I don't want the robot to jump out of the window to see whether it's raining
outside but, why should the robot not jump out of the window? What tells it that it's not a very common sensical thing
to do? We'll talk about common sense reasoning using a frame representation.


We'll start talking about certain small set of primitive actions.


There are only 14 of them, but they bring a lot of power because they organize a lot of knowledge. These primitive
actions can be organized into hierarchies of sub actions. These actions can result in changes in the state.


This is important, because that is what allows the robot to infer that if I were to take this action, that result might
occur. That state might be achieved. So then it decides not to jump out of the window, because it might get hurt.


02 - Example Ashok Ate a Frog
-----------------------------

Okay. Have you ever wondered how you could write the equivalent of a Watson program or a CD program for your own
computer?


Just imagine if you could talk to your machine in terms of stories.


Simple stories. Perhaps just one sentence stories like Ashok ate a frog. Now, we've already seen how a machine can make
sense of this particular sentence,


Ashok ate a frog. We did that last time. But, of course, eat or ate can occur in many different ways in sentences. Here
are some of the other ways in which I can use the verb eat. Ashok ate out at a restaurant.


I could tell something was really eating him. And, the sense of eating him here, is very different from the sense of
eating here. There's no physical object that is being eaten here. The manager would rather eat the losses. So now this
is a very different notion of eat. The river gradually ate away at the riverbank.


Yet another notion of eat. So just like we had in the previous lesson, take, the word take, which had so many different
meanings, eat has so many different meanings. Now when we were discussing the word take, we discussed how we can use
both the structure of sentences as well as background knowledge to disambiguate between different interpretations of
take.


We could do something similar with eat.


We could enumerate all the different meanings of eat, then for each meaning of eat, we could ask ourselves what is it
about the structure of the sentence and what is it about the background knowledge I have about things like rivers and
river banks which tells me what the meaning of ate here is.


To summarize this part, if you were to start talking to your machine in stories, in terms of simple stories designated
by a single sentence, then one problem that will occur is, that words like ate or take will have large number of
meanings. And we have seen how your machine can be programmed in such a way so as to disambiguate between different
kinds of meanings of the same word.


Now here is a different problem that occurs. Consider a number of stories again.


Each story here is designated by a single sentence. Ashok ate a frog,


Ashok devoured a frog, Ashok consumed a frog, Ashok ingested a frog, and so on. Several sentences here. And if we think
about it a little bit, each of these sentences is using a different verb. But the meaning of each of these words in this
sentence is pretty much the same.


So whether Ashok ingested a frog or Ashok devoured a frog or


Ashok dined on a frog, exactly the same thing happened in each case.


There was a frog that was essentially outside of Ashok's body and then Ashok ate it up and at the end the frog was
inside Ashok's body.


The frog was dead and Ashok was happy. So the next challenge becomes, how can a machine understand that the meaning of
each of these words here is exactly the same? In a way this problem is the inverse of the problem that we had here.


Here the problem was that we had a single word like eat, which had got a lot of different meanings and different context
in different sentences.


Here, the issue is that we have a lot of different words, but they have the same meaning given the context of the
sentences. So another question then becomes, well how can we make machines understand that the meaning of these words in
the sentences is exactly the same?


Each of the sentences telling us exactly the same story. There is one other thing that is important here, and that is
the notion of context.


One of the hardest things in AI is, how do we bring context into account?


In both of these cases, context is playing an important role. On the left side, context is playing an important role
because we understand that the meaning of eat is different in these different sentences, because the context of eat is
different. Here context is playing a different role. We understand that the meaning of each of these words is
practically the same because the context here is practically the same. A couple of quick qualifications here. First,
right now we're dealing with stories that are just one sentences. Very soon in the next lesson, we'll deal with stories
which are much more complicated, which really have a series of sentences. For now, just simple stories.


The second is that here is structural all of these sentences is the same. So structure practically tells us something
about the context. But a situation is a lot more complicated because often two sentences, which have very different kind
of structures can still have the same meaning.


So consider these two studies. Bob shot Bill, and Bob killed Bill with a gun.


Now here the sentence structures are very different, but their interpretations, their meaning are the same. Bill was the
one who got killed. Bob was the one who did the killing. And the killing was done by putting a bullet into Bill.


So the question now becomes, how can we build AI agents that can meaningfully understand stories like this one? And
stories are the kind that Bob shot Bill, and Bob killed Bill with a gun. One thing we could do is, that for each of the
verbs here we could have a frame like we had a frame for take.


So we could have a frame for ate, a frame for devoured, a frame for consumed, a frame for ingested, and so on. Well, we
would have a lot of frames then.


Because there are a large number of verbs in the English language or in any other modern language. Perhaps we could do
something different.


Perhaps we could look that there is a similarity between the interpretation of these things. Perhaps we could use the
same primitive action for each one of them. So when we talk in English language, we might use for communication purposes
all of these verbs. But perhaps we could compare AI agents that have a single internal representation for each one of
them. What might that internal representation look like? We will call that representation a primitive action. Each one
of these is an action. But many of these actions are equal in terms of our interpretation of those actions.


Let's see what these primitive actions might look like.


03 - Primitive Actions
----------------------

>> David, that's a good point. One way of capturing the meaning of that story in terms of these primitive actions is in,
to use the move object primitive action.


So, here about the object being moved and the mover of the object is the same,


I. So, I am moving myself one place to another place. And the nearest point here is that these primitive actions will be
able to capture the meaning of some sentences in a very simple, logical, intuitive sense. And for some other sentences,
it might be a little bit more involved. So let us see how this primitive actions may actually help an AI agent make
sense of stories.


So here is the first thing we can do. Recall there were large number of stories, each expressed by one sentence. Ashok
ate a frog, Ashok devoured a frog and so on. So now, ate, devoured, consumed, ingest, partook. We can think that each
one of them really is an instance of a primitive action called ingest.


Here's the primitive action Ingest. So Ashok ingested a frog here,


Ashok ingested a frog here, Ashok ingested a frog here.


Well, superficially these particular sentences are different.


In terms of their deep meaning, the deep meaning is pretty much the same. But it's true of course that the world may
have a slightly different interpretation than dining. The [INAUDIBLE] might be something that I ravish with my hands for
example, and dining might involve fine dining with silverware. nevertheless, ingest captures the basic meaning of these
sentences. What is the basic meaning?


The basic meaning again is that Ashok is an agent.


Frog is the object that is getting eaten, ingested. Initially the frog was outside Ashok's body, and probably dead or
alive. We don't know its state.


After the ingestion has occurred, a devoured has occurred, a consumed has occurred, the frog is inside Ashok's body, and
it's dead. And further, that Ashok probably is happy at the end of this particular ingestion.


And where is all of that knowledge coming from? It's buried inside the frame for ingest. So each of these primitive
actions has a frame corresponding to it.


And we have come across frame many times already in the class, so by now you should know what it means. And the frame
has a large number of slots like agent, co-agent, object, beneficiary and so on, and those slots deal with still a
difficult situations and have default values already put in there. So when a sentence comes like, Ashok ate a frog, then
the verb ate here, pulls out the primitive action ingest, and the frame for this primitive action and the processing
becomes top down, and they start thinking, where will Ashok go?


Where will frog go? Who is the agent? Who is the object? And so on.


04 - Exercise Primitive Actions
-------------------------------

Okay, I hope you're enjoying this particular lesson, because I certainly am.


Let's see, whether you're also understanding this lesson.


So, here are four sentences, John pushed the cart, John took the book from Mary,


John ate ice cream with a spoon, John decided to go to the store. And here's some of the words, are in these blue boxes.
For each of the sentence, find the primitive action, that would best capture, the meaning of the verb inside the blue
box.


05 - Exercise Primitive Actions
-------------------------------

>> That sounds right David. There are sort of several other things to note here. What is the last sentence that has two
verbs in it? Decided and go. You'll see in a minute, how we can deal with sentences or stories that have multiple verbs
in them. Second, you are right in that it is not always very easy to decide which is the best primitive action for
capturing the meaning of a particular verb here.


So the verb here was pushed, and the reason David propelled or moved object is because in propulsion the body is in some
sense in contact with the particular object that is getting moved. Now we are not sure inherently detailed specification
of each of one of these primitive actions. But


I can tell you that the readings at the end do give them in detail


06 - Thematic Roles and Primitive Actions
-----------------------------------------

So let's dig deeper into, how the agent may do the processing using this primitive action. So, consider the sentence
John pushed the cart. The AI agent beings left to right, because we're talking about English language here.


He first word here John is not a verb. So, the AI agent for the time being, puts this in a list of concepts. And ignores
it it comes to the second word in the sentence. Which is pushed, there's a word here, pushed, and now the AI agent uses
this particular verb, push, as a probe into it's longterm memory. So now, the frame for propel is going to get pulled
out, let's see what the frame would look like. So, here is the frame for propel that has been pulled out of the longterm
memory?


And this frame tells us that we can expect an agent.


We can expect an object. And indeed, although we are not shown here, this frame may have additional slots and perhaps
additional things can be expected. Now for each of the slots, there is a rule budding in here. A rule which tells us,
how can we pull out from a sentence, the entity that goes under the slot?


The filler that must go here. So here's a rule that says that.


If there is a concept just before the word, and that concept is animate, then, whatever that concept is, put it here.
Well, there is a concept just before push, that's John, and let's suppose we have a lexicon which tells us if


John is animate, then we put John here. Similarly there is a rule here for this slot, which tells the agent that if
there is a object, there is a concept that comes after this verb. And that particular concept refers to an object that
is inanimate. Then, take that particular thing, and put it here, and that's the cart. And so, we put cart here. So this
way, this particular scheme, helps us derive the meaning of, John pushed the cart.


And notice that the processing is a combination of bottom up and top down, as we discussed earlier. It begins, bottom
up.


Because we are looking at the data. Right now we don't have knowledge. But, as soon as some data is processed, it pulls
in knowledge from memory. And soon the processing becomes top down, this frame helps to general expectations.


And help pull things out. This is almost acting, like a hook for a fish. So once you have the hook, then you can capture
the fish well. There are several things to be noted here. First representations like this. First, representations like
this, are called structure knowledge representations.


There's not only a representation here, but, there is a strong structure to it.


Earlier when we were discussing predicates and logic, or we discussing rules and antecedents and consequence of rules.
They are like the atoms of knowledge representation. They don't have much structure. But by now, we have this molecule
of forms knowledge representation. And which a large number of atoms are getting connected with each other.


And this connections are important, because once you have that structure of the molecule it tells you what can go in the
place of each atom. Second, this is a simple sentence, and so the processing was quite simple. The sentences need not
always be as simple as this one. What happened to the sentence had the word, push in it? And I picked a frame, that is
not the right frame for it.


Suppose I had pulled out a frame for move object is shown as propel here. Well, one possibility is, that if you were to
select a different frame for making sense of this particular sentence, there's a high I try to fill the slot for this
particular frame, I will find a lot of difficulty. In which case,


I might abandon the frame and try a different one. The second possibility is, that I may even force the interpretation
of this into the slots for the other frame. But, if there is a study here which contains large number of sentences then,
soon I'll realize this is not the right frame,


I may abandon it and pick different frame. So for complex sentences, this processing is not as linear as we have
pretended it to be right here.


It is also possible, that sometimes one of the words en-map into two frames equally well. Indeed, this is the basis of
many of the [UNKNOWN] we encounter.


So consider, I was wondering why the ball was becoming bigger. Then it hit me.


Now, you of course understand the word hit there, that particular word, maps into two different interpretations, and
that's why it is interesting and funny. So here's another one. Two men walk to the bar to, the third one ducks. Now here
the word, the bar is overloaded. So here, walked into the bar, is getting interpreted two different ways.


Indeed, people have tried to build accounts of humor, based on the kinds of story interpretation that we are doing here.
Could it be, that this is beginning of a theory of humor. Of how you can tell stories not only to your machines?


07 - Exercise Roles  Primitive Actions
--------------------------------------

Let's do an exercise together. Here is a sentence. John took the book from Mary.


For this sentence, first write down the primitive action that best captures the meaning of the sentence. And then write
down the fillers for each of the slots of this primitive action.


08 - Exercise Roles  Primitive Actions
--------------------------------------

>> That's good, David. Notice how lexical syntactical semantical analysis are all coming together here. The driver does
semantic analysis. The driver does this frame which captures the semantics of this particular sentence that allows us to
draw inferences about it. That's why we are use the term semantics here.


So the semantics has been captured by this frame with terms of all of these slots. But how do we decide on the fillers?
That requires lexical analysis and syntactic analysis. So, when we have the word John here, John is a concept and a
concept is inanimate and that information is coming from a lexicon.


That is the lexicon analysis. And when have a sentence like: John took the book from Mary. And from is a preposition and
Mary follows immediately after that.


This is capturing part of this syntax of this particular sentence. And that is how we derive that the source must be
Mary. So the semantic syntactical analysis is all working together here.


Notice also how frames and routes are coming together here.


You've seen how frames help us understand the meanings of the stories and that is being done part by the rules that are
budded inside the slots. So there is a rule here which tells us how to extract the agent from the sentence and put it
inside the slot. Similarly, there's a particular rule here and a rule here and each one of these slots may have its own
rule. Of course as the sentences become complex and these frames become complex, these rules will become much more
complex and sometimes there will be multiple rules here and multiple rules here. And this can become very complicated,
very soon.


Another point to notice here is that this capturing the semantics like I said earlier and how do we know that. Because I
can ask questions. Who has the book?


Who had the book? What did John take from Mary? And you can answer any of these questions using this frame. Once you
have this frame, question answering becomes possible. Common sense reasoning becomes possible.


09 - Implied Actions
--------------------

The relationship between the structure of these sentences, and background knowledge is very intricate, and complex, and
very entrusting as well. Sometimes the structure of sentences can be used to tell stories, have only implied actions in
them. Consider the sentence,


John fertilized the field. Now it's hard to see fertilized mapping, into any of the primitive actions that we had here.


There is an implied action here, that is not specified in the structure, the sentence here. But, it is much more
meaningful in terms of the background knowledge that we have of those primitive actions. What John fertilized the field
really means, is that John put the fertilizer on the field.


Now put is something that maps in the primitive actions more easily.


The response under the feature that's processing.


Initially the inner agent must talk for the word, given in the sentence. And try to map in the primitive actions. And if
that fails, then the [INAUDIBLE] agent must start thinking in terms of how to transform on the sentences, to bring out
implied actions, that can more easily map the independent actions.


This, again, is common sense reasoning. Through common sense reasoning,


I'm interpreting that there must be implied action here, that captures the meaning of the sentence. Once I have made the
implied action here transparent. The the rest of the processing, easier. The put action, maps into the primitive action
of move object, this frame is pulled out, and the rest of the slots can be filled in, like earlier.


10 - Exercise Implied Actions
-----------------------------

Now let's do an exercise together. So consider the sentence, Bill shot Bob.


Once again, shot is a verb here, that does not quite map internal [UNKNOWN] primitive actions clearly, cleanly. So
perhaps there is an implied action here.


So first write down the sentence in terms of a primitive action, then write down the frame from this primitive action so
fill the slots.


11 - Exercise Implied Actions
-----------------------------

>> That's really interesting, David.


Because notice, if you say Bill took a picture of Bob, it's not clear into what primitive action would this took map
into? Perhaps we can discuss this more on the forum. There's one more thing to notice here.


Like David says, I can have multiple interpretations of Bill shot Bob.


This sentence doesn't help me to resolve between those interpretations. Perhaps, it is something coming before the
sentence in the story, or something coming after that, that will help me this in big way. From the sentence itself, we
can simply construct two particular interpretations.


12 - Actions and Subactions
---------------------------

>> That's a valid question Davis. Move-object was in need of primitive action related to the various superficial forms
in which words can occur in a sentence.


As an example, transported, carried, or moved. However, this primitive action move-object can have its own story in
terms of further decomposition.


Notice this particular decomposition, this particular story is specific to this structural sentence where Ashok puts the
wedge on the block.


This raises lots of hard issues. How many such stories are there?


Do we have a story? Must an AI agent have such a story for every single situation that it encounters? It was a hard
question, so it's not clear that AI currently has an answer to all those questions. So this theory by no means covers
all stories. Many of the stories are beyond the scope of this theory. And in fact, even for the stories that are within
the scope, there is a hard question about confidential tractability, because in number such stories can explode very
quickly.


13 - State Changes
------------------

>> Good point, David. So we can imagine a different action frame for feel because of enjoy being a feel. The agent is
Ashok. Ashok is the one who did the feeling. And the object of the feeling that is being felt is joy.


We can still have a frame for eating and we can relate those two frames. So what specific interpretation an AI agent
will make this particular sentence will depend on the precise rules that we're going to put into these slots so that the
AI agent can make either this interpretation or that interpretation.


We will see another example of this situation in just a minute.


14 - Implied Actions and State Changes
--------------------------------------

Sometimes it might not be clear to what exactly does this particular verb correspond to. So consider,


Susan comforted Jing. Well, what exactly did Susan do to comfort Jing?


It's not at all clear. Not clear what the primitive action should be.


Although if you may not understand what exactly is the primitive action here.


We want agents nevertheless to do common sense reasoning.


Their interpretation might be incomplete, this interpretation might be partial.


Nevertheless, you and I, as humans understand something about Susan and


Jing here, that Susan for example, did something that made Jing happier.


We want the agent to do the same kind of reasoning, without knowing what exactly is the comforting action here. So we
may have a generic primitive action of do.


This generic primitive action will use it, whenever we are unable to decide, whenever the agent is unable to decide,
what exactly is the primitive action that should be pulled out. So the agent will simply say, well, Susan did something
that made Jing's mood happy and this is as much interpretation that the agent might be able to the sentence, which is a
pretty good interpretation.


15 - Actions and Resultant Actions
----------------------------------

Earlier we had problems that will deal with sentences which have two verbs in it. So here are two verbs, told and throw.
Maria told Ben to throw the ball.


How may an AI agent make sense of this particular sentence? So once again, the processing starts on the left. Maria is
not a verb, so let's put in a concept list and for the time being ignore it.


The processing goes to the second word which is told, which is a verb. And so the primitive action calls when the told
is pulled out. The primitive action is speak, and so now we can start putting the fillers for the various slots. So the
agent is Maria and the result is now we go to the second one.


Here the primitive action is propel because we have a throw here.


And the propulsion is being done by Ben and the object is ball and now we relate these two. This second frame is a
result of the first frame's action. So, if we go back to the previous sentence, Ashok enjoyed eating a frog.


We can see how we can represent both verbs there in terms of action frames. So,


Ashok enjoyed. That might be the frame here. The primitive action is feel.


The agent is Ashok. Ashok ate a frog, that's the primitive action of ingest, agent is Ashok, and the object that got
eaten was a frog.


And the result of that is this frame where Ashok had a feeling of enjoyment.


Note that some problems still remain. It is too difficult to figure out exactly how represent a sentence like Ashok
enjoyed eating a frog.


It can be two representations with that particular sentence and see that those are two action frames or one action frame
and one state of change frame. Some of these questions will get answered when we stop thinking in terms of stories that
are only one sentence long, but stories that have a number of sentences. Stories based on a discourse. Because some of
these ambiguities will get resolved when we know more about what happened when


Ashok enjoyed eating the frog. What came before it, or what came after it.


16 - Exercise State Changes
---------------------------

So let's do a couple of exercises together. Here are two sentences at the top.


Anika decided to have a glass of water and Marc loved watching TED talks.


Please write down the action and the state change frames that will capture the meaning of the first sentence and the
meaning of the second sentence.


17 - Exercise State Changes
---------------------------

>> That's good David. Note though, that this sentence is a little bit like, a shark enjoyed eating the frog. This is one
representation for this sentence, and under the representation we may have two action frames.


One corresponding to the word loved, another corresponded to word watching, and then connect them, to the slot result. I
hope you can see how agents might be able to understand simple stories. In fact, this is quite similar to the way Watson
and Siri go about to understand the stories that we talk to them.


Almost surely the human interactions with the machines of tomorrow, will not be based on the keyboards and mouses that
we have today.


We'll talk to the machines, the machines will talk back to us, and when we talk to the machines we'll be telling the
machines stories.


Stories like Anika decided to have a glass of water, or a shark enjoyed eating the frog. And when we tell the stories,
the stories will have context. They will have ambiguities. And we will expect the machines to do common sense reasoning.
The power of this particular lesson lies in the [UNKNOWN] of a representation, that enables a particular kind of common
sense reasoning. We'll continue this discussion, about common sense reasoning of more complex stories, in the next
lesson.


18 - Assignment Common Sense Reasoning
--------------------------------------

So would you use commonsense reasoning to design an agent that could answer


Raven's progressive matrices? Here you might make two connections. First you could connect primitive actions of agents,
to primitive transformations in these matrices. Different problems could be composed out of a finite set of possible
transformations. What would those primitive transformations be?


And what would the action frames involved in each transformation look like?


Second, you might connect those individual primitive actions to higher level transformations. What would your primitive
transformations be?


And what common higher level transformations are possible?


What primitive actions would result in those higher level transformations? And how would composing these like this,
actually help you solve Raven's progressive matrices? In a way that you couldn't do otherwise?


19 - Wrap Up
------------

So today we've talked about common sense reasoning. Broadly, common sense reasoning gives us a formal structure to
interpret the world around us.


Having that formal structure let's us build agents that can then do the same.


We started off with primitive actions, which like primitives in programming, are the simplest things we can interpret
out the world. Then we looked at composing those primitive actions into bigger actions. For a hierarchical, abstract
view of the world. We then looked at how those primitives can cause state changes, which let us predict the effect or
cause of certain events.


Next time, we're going to compose these simple frames into much longer stories, called scripts. Scripts help us make
sense of complex repeated events with relative ease, and generate expectations about the world around us.


20 - The Cognitive Connection
-----------------------------

The connection between common-sense reasoning and human cognition is both very strong and not yet fully understood. Let
us suppose that I were to ask you to go find the weather outside. You would not jump out of the window.


Why not? You would use common sense reasoning to know that jumping out of the window to find the weather is not a good
idea. But what is it that tells you not to jump out of the window? You use the notion of goals.


The notion of context to decide what not to do and what to do.


We use similar notion of context in order to do natural language understanding.


We could use context to disambiguate between various meanings of take.


Can we context also to decide on what would be a good source of plan. So far we have been talking about common sense
inferences about physical actions, what about the social world? You and I also make common sense inferences about the
social world around us. One possibility is that you and


I have a flurry of mind, this is actually called the flurry of mind theory.


You and I as cognitive agents, ascribe goals, beliefs, desires to each other.


And it's the theory of mind that allows us to make inferences about each other, including common sensical inferences.


21 - Final Quiz
---------------

Please write down what you learned in this lesson.


22 - Final Quiz
---------------

Great. Thank you so much for your feedback.


