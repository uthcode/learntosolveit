.. title: 16 - Scripts 
.. slug: 16 - Scripts 
.. date: 2016-01-23 06:46:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

============
16 - Scripts
============

01 - Preview
------------

Today, we'll talk about another knowledge representation called scripts.


Scripts allow us to make sense of discourses and stories and scenes. Scripts are the culmination of of frames and
understanding and common sense reasoning these last few lessons. We'll take what we learned about frames and
understanding and common sense reasoning to build superior scripts.


We'll start by defining scripts, then we'll talk about the form and the content of scripts. Then we'll discuss how we
can use scripts to generate expectations about discourses and stories that help us make sense of the world around us.
Finally, we'll talk about the hierarchical nature of scripts. I think you'll enjoy this lesson.


02 - Exercise A Simple Conversation
-----------------------------------

To motivate our discussion of scripts, let us continue with our metaphor of machines with whom we can talk in stories.
Now the Watson program and the Siri program, normally they understand stories that are limited to one sentence. You can
ask Watson a question, you can ask Siri a question, and those questions are one sentence questions. Similarly when Siri
and


Watson reply, they typically give their answers in one word or one sentence at most. The story plays a very important
role in the life of quadrant division and we would expect AI agents that live among quadrant divisions also to be able
to understand stories. And one of the common roles that story players that they enable more common sense reasoning. To
see how stories enable common sense reasoning, consider two simple sentences. Imagine the first sentence was,


Ali asked, do you think we'll have many customers in the next half hour?


And the second sentence is, Sarah replied, go ahead and grab your lunch.


So these are two sentences of a story. Does this story make sense to you?


03 - Exercise A Simple Conversation
-----------------------------------

>> So you and I as human beings have little difficulty in understanding stories like this. You might be given two
sentences like this and we can connect them...


Causally connect them, coherently connect them, even if sometimes we use very active imaginations to do so. How can we
do this conjoining of sentences into a coherent story? Put another way, how can we make an AI agent do it?


What kind of knowledge should the AI agent have? And what kind of inferences must it make in order to be able to connect
these two sentences?


04 - Story Understanding for AI Agents
--------------------------------------

>> That's a good story David. Now let's consider a different set of issues.


Imagine that I told you a story. Bob went to a restaurant and sat down. But nobody came to serve him for quite awhile.
Eventually, when someone did appear, he ordered a hamburger. The hamburger took a long time before it came.


And when it did come, it was burned. Bob was not very happy.


He didn't even finish the hamburger. Do you think Bob left a large tip?


Well, I expect most of you would say no. He did not leave a large tip.


If we had to wait for a long time. And if the food that came eve, eventually, was not of very high quality. You'd
probably not even ask tip. But how did you come to that answer? Why did you expect, that in this particular case, Bob
will not leave a large tip? Again, this connects to your notion of a story. It connects to your notion of a story, of
what happens in a restaurant. Why do people leave tips? When do they leave them? To put it another way, stories help you
make sense of the world.


They help you [INAUDIBLE] expectations, even before [UNKNOWN]. They allow us to make connections between evens that
otherwise might appear disparate. So in this lesson, we'll look at another structured knowledge representation called
scripts. For representing stories or the kind that we are talking about.


And we will see how this knowledge for presentation allows us to make sense of the world. And answer the kinds of
questions that we are talking about.


05 - Visiting a Coffeehouse
---------------------------

>> Notice I didn't need to tell David what coffee house, what time of day, what he was ordering, who the cashier was
etc. He has a script for that scene.


And he associates it when needed. It helps with different expectations like, the cashier's going to give me my total, my
drink should be coming up soon.


If those expectations are not met, he knows something has gone wrong and he needs to react. This is the power of script.


It helps to generate expectations about scenes in the world.


06 - Definition of Scripts
--------------------------

So what is a script? A script is a knowledge representation for capturing causally coherent set of events. Casually
means that one event sets off another.


So when David goes to the coffee house, as soon as he approaches the counter, the barista comes to him and says, what do
you want? One event has set off the next one. Coherent means the links between these events make sense in the context of
the world around us. So in David's script again, ordering coffee doesn't cause the barista to slap in the face.


Because that would not be causally coherent in the context of the world.


These events are referent to events in the world. Some events, like deciding or concluding, might be in the actor's
mind, but for the most part these events are observable events.


07 - Parts of a Script
----------------------

So the structured knowledge for a presentation called script has six parts to it. The first part is called entry
conditions. These are the conditions necessary to execute the script. So, for a restaurant script, as an example, the
entry condition might be that there is a customer who is hungry and the customer has some money. The result refers to
the conditions that will become true, after the script has occurred, after it has taken place. So, for restaurant
script, the result might be that the owner of some restaurant has more money, the customer has less money, and the
customer is now pleased and is no longer hungry. So the third part of a script is our props. So the third part of script
are called props. Props are the kind of objects that are involved in the execution of this script so in case of the
restaurant script the props might include tables and menus and food items and so on. So the fourth part of a script is
roles.


These are the agents involved in the execution of the script. As an example in the restaurant script it might be a
customer who goes to a restaurant, the owner of the restaurant, the waiter or the waitresses in the restaurant, and so
on. The fifth element of a script is a track. Track are variations or subclasses of a particular script. So for example
in case of the restaurant script we may have tracks for going to a coffee house, or going to a fast food restaurant, or
to a fine dining house. And finally the sixth element of a script refers to scenes. Scenes are specific sequence of
events that occur during the execution of the script. So in case of the restaurant script there might be a scene for
entering a restaurant. And a scene for ordering food. And a third scene for accepting the food and so on.


When you put all of the six elements together then you get a complete script.


In the previous lesson we had taken the metaphor of a molecule as a knowledge representation. That is, knowledge
representations that are not small or short or not atomic, but are molecule in nature, script is a big, large molecule.


08 - Constructing a Script
--------------------------

So here is a representation of the restaurant script. Here is the name of the script, restaurant, and the six elements
that we talked about earlier.


Track, props, roles, entry, result and scenes. So this particular track refers to formal dining. Here are the props,
tables, menu, check, money, food and place. And for food and place we can use symbols. These symbols can be used as
variables. So where I may different kinds of foods and different kinds of places in a restaurant. Here are the rules, so


S is a customer, W is a waiter, C is a cook, M is a cashier, O is an owner and so on. The entry conditions are S is
hungry, S as the member is a customer,


S has money and those conditions are that S has less money. S is not hungry.


S is pleased. But O has more money. And scenes, well, let's discuss them in the next slide. Here is a representation of
scene one.


We'll call it the entering scene. This particular scene consists of several events. So in the first frame, the customer
S, S stands for the customer. Moves himself or herself. So S is moving himself or herself to some restaurant, some place
P. And the second frame, the agent S, the customer Sees some table. So this frame, the customer S decides to, take an
action. The particular action is, where this agent S this customer S moves. Customer S himself or herself to the table.


So this is a walking action going on. Let us continue another set just a little bit longer. So now S is moving his own
body into a sitting position. Here, the waiter sees the customer, and now the waiter moves himself to the customer.


And now the waiter moves the menu, to the customer. And this completes a representation of the first scene of entering
in a restaurant.


One can imagine many more scenes. The next scene might be a way to customer orders food. The third thing might be the
way the waiter brings food, and so on and so forth. And then the last thing is the customer pays the bill and then walks
out. This is a stereotypical notion of a script.


Your notion of a script, might be slightly different depending on what kinds of restaurants that you go to. In different
cultures, the script for going to a restaurant might be quite different. The point here is that the script is capturing
in a knowledge representation, what is known about the stereotypical situation of going to a restaurant of a particular
kind.


09 - Form vs Content
--------------------

So so far we have talked about a journal script of going to a restaurant, or an abstract script for going to a
restaurant. This is like a class. We can instantiate it. So let's do this same script instantiated with these values
with the greatest variables. So, Salwa is not a customer. Lucas is the waiter.


And so on. And this instantiation is an important aspect of intelligence. Let's go back to our intelligent agent. It
might be that Salwa is really a robot. Now, how would a robot know what to do in a restaurant? How do we program a robot
in such a way that it would know what actions to take in a particular situation?


Well, suppose that, Salwa the robot, in its memory, had a number of scripts like this one? And when it entered a
restaurant, it invoked the restaurant script, which told it exactly what kind of actions to take. We could also see how
this script allows Salwa, the robot, to generate expectations, to guess what will happen even before it happens. There
is one more thing worth noting here.


Notice how we are composing scripts of these primitive actions here, the same primitive actions that occurred in the
last lesson.


So, these primitive actions are now providing the fundamental units of frames that compose together in some causally
coherent sequence, make a script.


This brings up another point. Notice how some knowledge structures are composed out of other knowledge structures.
Earlier, we had frames for these primitive actions, gave them social knowledge structures. Now, we have scripts which
are composed out of these framelike knowledge structures.


10 - Using a Script to Generate Expectations
--------------------------------------------

>> David, that's a good point. That happens in many different kinds of movies.


So when I go and see a science fiction movie or even a romance movie,


I'm expecting certain things to happen. And sometimes, I think a movie is really good if it is new and novel and
different and offers some surprising things.


Notice that this could also be the beginning of a period of creativity.


In the last lesson, we were talking about puns and humor.


Now, we're talking about surprises. Some current theories of creativity say that a situation is creative if it is. A,
novel; B, if it is useful or valuable in some way; and C, if it is unexpected or surprising. Now, this begins to capture
at least one of the three dimensions of unexpectedness or surprise, and that's an important part. We'll return to
computational creativity at the end of this course when we'll talk a lot more about these issues.


11 - Tracks
-----------

Now, another part of the script was the track. And we really haven't talked a lot about track so far. So let's talk a
little bit more about it. So here are four tracks with the restaurant script.


That really [INAUDIBLE] to going to restaurant, four kinds.


Here's a coffeehouse, fast food, casual dining, formal dining. You could add more if you wanted to. Now in restaurants
of all kinds, some even so common.


You have to go to a restaurant, you have to order some food. You eat that food.


You pay the bill. And then you leave. That is common to all of them which is why all of them are part of the restaurant
script. On the other hand what happens in a Coffeehouse is quite different from what happens in Formal Dining, which is
quite different from what happens in a Fast Food restaurant.


So you may have specific cracks that correspond to Coffeehouses and


Fast Foods and so on. In effect, we are building a semantic hierarchy or script.


Here is a script for going to a restaurant. Here is a script for going to a coffeehouse, going to fast food. And this
can be tracks in the overall script.


Of course, we can build a semantic hierarchy of something higher than this.


We could think about going to, for social events and [INAUDIBLE] going to this restaurant becomes part of going to a
social event of various kind. Okay now that we know something about the [UNKNOWN] representation called script, the next
question becomes how many AI agent actually use these scripts? So imagine an AI agent that is hungry has some money and
decides to do something about it. So it may go into its long term memory and find out the script that will be most
useful for the current situation. This really becomes a classification problem.


In long term memory a large number of scripts, and the agent is trying to classify the current situation into one of
those scripts.


Let us suppose the agent picks a restaurant script, and decides to execute it.


As it enters the restaurant, the scene it observes in the restaurant matches the conditions of a fast food script. So it
decides to invoke the fast food script. This way the robot may walk down the semantic hierarchy, first in working the
restaurant script, then working the fast food script, and so on. Now a robot could have taken a different stance.


A robot could have decided to do planning. Given some initial conditions, and cold conditions, a robot may have used the
operative that is available to it, to generate a plan at one time. While the script is doing it, it is giving it a plan
in a compiled form. The robot doesn't have to generate this plan at runtime. It is already available in memory in a pre
stored form. This is very useful because one of the central conundrums that we have been talking about is, how is it
possible that AI agents can't address computationally complex problems with limited resources in near real time? In a
complex dynamic world, planning can take a lot of time. But if I already have the store plans, then in working the
script and executing it is much faster.


12 - Exercise Learning a Script
-------------------------------

So, we have talked a lot about how the notion of scripts is connected to many of the topics that we have discussed
earlier in this course. So, let's do an exercise together. Which of the following topics might help an agent learn a
script? Please check all that apply here.


13 - Exercise Learning a Script
-------------------------------

>> Of course, if you think you see a connection between production systems or learning by recording cases in scripts
that I haven't seen, or if you think that the connection between these other topics and scripts is not quite as close as
I described, feel free to head over to our forums and we'll discuss it there.


14 - Exercise Using a Script
----------------------------

Okay, let us do one more exercise together. This predicate exercise has to do with using a script rather than learning a
script. Which of these topics that we have discussed earlier apply to an agent using a script?


Check all that may apply.


15 - Exercise Using a Script
----------------------------

>> This is good, David. Thank you for sharing this. Note that generate and trust and case-based reasoning might be
applicable to the use of scripts after all. So one can imagine a situation where there are a large number of scripts of
a level. The robot has to decide which of these scripts should I use for this particular situation, and may not be able
to classify the situation directly into scripts. And with that case the robot might pick a script, generate it, try it
out, see if it works. If it does not, pick another one.


Also case-based reasoning is currently the application of scripts in the sense that, both case-based reasoning and
script-based reasoning are extremely memory intensive. What both of them are saying is that memory often supplies most
of the answer. Like we said earlier when we were discussing case-based reasoning, we don't think as much as we think we
do. Most of the time, memory gives us the answer. The difference of course, like David pointed out is, that case is
there for instances where scripts are abstractions over instances.


16 - Assignment Scripts
-----------------------

So how would scripts help inform the design of an agent to solve Raven's progressive matrices? Remember, scripts are
ways of making sense of complex events in the world and we can certainly consider individual Raven's matrices to be
complex situations.


You thus might have a script for different broad categories of Raven's problems.


If this was your approach, what would your entry conditions be for each script?


What would the tracks be? What would the scenes be? Where are these scripts going to come from? Are you going to tell
the agent what script it should use or will it learn a script from prior problems? If the agent succeeds using the
script that you give it, who is intelligent? You or your agent?


17 - Wrap Up
------------

So today we've talked about scripts, a complex way of understanding stories in the natural world. Stories aren't just
narratives, though.


Painting, songs, buildings are all stories of different kinds.


Stories are around us every single day. We started off by defining scripts.


Scripts are causally coherent series of events. They give a prototype for what to expect in certain situations. The form
of the general script shows us the form of the overall prototype for the situation.


A specific instantiation of the script then specifies the content. Scripts can have different tracks as well. At a high
level, any kind of restaurant involves entering, ordering, paying, and leaving. More narrowly though, fast food and
drive through restaurants involve different scripts from casual or formal dining. This concludes our unit on common
sense reasoning, but note that some of what we cover in the future will be applicable to learning, differentiating, and
refining scripts.


18 - The Cognitive Connection
-----------------------------

Scripts are strongly connected to current theories of human cognition.


In fact one recent theory says that brain is a predictable machine. We do very quick bottom up processing followed by
mostly top down processing with general expectations of the world. Then we act on those expectations. This idea in fact
is so strong, that when it fails it leads to amusement, or surprise, or anger. If I violate the expectations of your
script, you might find it funny or surprising or you might be upset about it. An interesting and open question is,
whether we carry the scripts in our hear or do we generate them at run time?


Scripts are also current with the notion of mental models. You and


I have mental models, or scripts. Not just about social situations like going to a restaurant, going to a movie, but
also about how the computer program works, how the economy works, how the car engine works, your physical, social,
economic works. Note that scripts can be culture specific. In the U.S. for example, going to a restaurant typically
involves leaving a tip. But in many countries, this is not the case. In fact in some countries, tipping is considered
insulting. So scripts presumably evolved through cultural interaction over long periods of time. But once there, they're
a very powerful source of knowledge.


19 - Final Quiz
---------------

Please write down what you learned in this lesson.


20 - Final Quiz
---------------

Great. Thank you so much for your feedback.


