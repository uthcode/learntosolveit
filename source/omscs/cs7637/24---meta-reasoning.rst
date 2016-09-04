.. title: 24 - Meta-Reasoning 
.. slug: 24 - Meta-Reasoning 
.. date: 2016-01-23 06:54:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

===================
24 - Meta-Reasoning
===================


01 - Preview
------------

Today we will talk about Meta-Reasoning.


Meta-Reasoning is thinking about[br]thinking, knowledge about knowledge.


In this case, the agent does not reasoning about[br]something outside in the world.


Instead, the agent is[br]reasoning about itself, but its own knowledge,[br]its own reasoning, its own learning.


As an example, I can ask you what is[br]President Obama's telephone number?


I'm sure that all of you can[br]immediately tell me, you don't know.


But how do you know,[br]that you don't know?


We test a little bit about[br]meta-reasoning when we were talking about learning by correcting mistakes.


There, we were interested in[br]errors in the knowledge base.


In journal, errors can also be[br]in reasoning or in learning.


We'll start today by talking[br]about mistakes in reasoning and learning, in addition to[br]mistakes in knowledge.


Then we'll talk about knowledge gaps,[br]not just errors in the knowledge, but when some knowledge is actually missing.


Then we'll talk about a very[br]journal meta-cognitive skill, which leads to strategy selection and[br]integration.


And this class, we have talked about[br]a large number of methods, but we haven't yet talked about how[br]an intelligent
agents can put multiple methods together to[br]address a complex problem.


Then we'll discuss meta-meta-reasoning.


Or meta-meta-meta-reasoning,[br]how far can we go?


Finally, we'll discuss an example[br]of meta-reasoning election that is sometimes called[br]goal-based autonomy.


02 - Mistakes in Reasoning and Learning
---------------------------------------

We have come across the notion of meta-reasoning earlier in this class.


You may recall this was the explanation that an agent had built, to decide why a particular object was an instance of
the cup.


And we told it that it was an incorrect decision. The agent then, reflected on its knowledge. Here was the knowledge.


Here was the explanation it had built. It is now reflecting on it and trying to figure out what makes this particular
explanation incorrect.


Where does the fault lie? That was an example where the agent was reflecting on its knowledge, but has this knowledge
was stored in the short term memory.


It had been pulled out of the long term memory. But just like there can be error in the knowledge, there could also
potentially be an error in reasoning.


Or potentially an error in the learning process. An example of an error in reasoning occurred very early in this
particular class. You may recall this particular diagram from mean sense analysis. This was the blocks micro build.


The agents needed to take the blocks from this initial stage to this goal state.


However there were multiple goals here. D on table, C on D, B on C.


And as the agent tried to accomplish these goals. It ran into cul de sacs, where no further progress was possible
without undoing some of the earlier goals. So, that was an example of metacognition over reasoning, where the agent was
trying to figure out, what was the error in my reasoning, and how can I remedy it. We can similarly have metacognition
over learning. So an example of metacognition where learning occurred.


When we were talking about learning making mistakes. You recall this was the explanation the agent had built, after it
had remedied the explanation.


The remedy in this particular case was adding here that the handle is fixed and relating it to the rest of the
explanation. Given that the agent had used explanation based learning to build this explanation in the first place, we
can think of the agent as, reflecting on this process of explanation based learning and asking itself, what did I do
wrong? And then deciding, well I built the wrong explanation. I must change that explanation. And that's what learning
by correcting mistakes did. We can consider this to be a process of metacognition of learning in the sense that the
agent may say, how did I learn this particular knowledge. Well, they learned it through explanationless learning. So
what was wrong in my process of explanationless learning that lead to this incorrect explanation? How do I fix my
process of explanationless learning so that I do not make the same error, again?


03 - Beyond Mistakes Knowledge Gaps
-----------------------------------

So far, we have talked about the case where there was an error in the knowledge or an error in the reasoning or in the
learning. The knowledge for example was incorrect in some way but the knowledge can also be incomplete.


There can be a gap in knowledge or in reasoning or in learning. A gap in knowledge occur when we're doing this exercise
under explanation-based learning.


In that particular case, the agent had build this part of the explanation, and it also had this part of the explanation.
But it could not connect these two, because there was no knowledge to connect that are object that has thick sides and
it can limit heat transfer that it would protect against heat.


Once the agent detects this as a knowledge gap, then it can set up a learning goal. The learning goal now, is, acquire
some knowledge that will connect these two pieces of knowledge.


Once the agent detects a knowledge gap, it can set up a learning goal.


The learning goal now is to be able to connect these two pieces of information.


Notice that we are seeing how agents can spawn goals.


In this particular case the agent is spawning a learning goal.


You might recall that when we did this exercise on explanation based learning, the agent went back to its memory, and
found a precedent, found a piece of knowledge, that enabled it to connect these two parts of the explanation. And so
this link was formed and the agent was then able to complete its explanation.


This is an example how the learning goal was satisfied, using some piece of knowledge. In this case the knowledge came
from the memory. But the agent could have potentially also acquired the knowledge from the external world.


For example, it may have gone to a teacher and said, I have a learning goal.


Help me with the knowledge that will satisfy that learning goal.


Its ability to spot learning goals and then find ways of satisfying or achieving those learning goals or any goal in
general, is another aspect of metacognition.


So this was an example of how metacognition helps resolve a gap in knowledge.


Now let us see how it can help resolve gaps in reasoning or learning. To see how metacognition can help resolve
reasoning gaps, let us return to this example of using mean sense analysis in the blocks micro build. Once the agent
reaches a cul de sac in the reasoning.


The agent could formally list its goal and ask itself how can I help to resolve this cul-de-sac. It may then be the
reminder of this strategy problem reduction was it uses its goals into several independent goals and then the agent can
go about achieving each goal at one at a time. Thus in this example, the agent set up a new reasoning goal and that used
that reasoning goal to pick a different strategy and thereby achieved that reasoning goal.


Note also that this is one way in which we can integrate multiple strategies. We first use some [x] analysis right in
the cul-de-sac, form a new listening goal, use the listening goal to bring in a different strategy follow reduction and
then go back to the original strategy means and analysis. We're achieving each goal independently


04 - The Blurred Line Between Cognition and Metacognition
---------------------------------------------------------

In this architecture for a cognitive system, we have drawn these boxes as if metacognition was completely separate from
deliberation and deliberation was completely separate from reaction. In fact, there might be considerable overlap
between metacognition and deliberation.


Some processes in deliberation might be viewed as metacognitive processes.


Some processes are metacognitive might be viewed as deliberative processes.


To see where the lines between metacognition and deliberation are blurry.


Let us return to this example from explanation based learning. When we talked about explanation based learning, we did
not talk about metacognition at all.


We can view the agent as saying, well, I do not know how to build a connection between this part of the explanation and
this part of the explanation.


Therefore, I'll set up a reasoning goal which pulls at some other knowledge, and so on. Now that we know the vocabulary
of megacognition, it is easy to view all of that in terms of this new vocabulary. So, instead of thinking of
deliberation and metacognition as two separate independent boxes,.


A better way might be, to think in terms of boxes that partially overlap, as a meta space and as a deliberation space.
We should not be overly concerned, whether something should go into the deliberation space into the metacognition space.
The more important thing is, what is the content of knowledge that we need to carry out a process and what is the
process that we need to carry out.


05 - Strategy Selection
-----------------------

In this course, we have learned about a large number of reasoning methods.


Here are some of them. We could have added a lot more here, for example, plan refinement or logic or scripts. Typically
when you and


I program an AI agent, we pick a method, and we program that method into the agent. One unanswered question is, how
might an agent know about all of these methods and the autonomously select the right method for a given problem? This is
the problem of strategy selection and metacognition helps with strategy selection. Given a problem, and given that all
of these matters are relative to the agent to potentially address problem.


Metacognition is select between these matters using several criteria.


First, each of these methods require some knowledge of the world. For example, case-based reasoning requires knowledge
of cases.


Constraint propagation requires knowledge of constraint. And so on. Metacognition is select one particular method,
depending on what knowledge is exactly available for addressing that specific input problem.


If that specific input problem, case does not have a label, then clearly the method of case-based reasoning cannot be
used. If, on the other hand, constraints are available, the constraint propagation might be a useful method.


Second, if the knowledge required by multiple methods is available, then metacognition must select between the competing
methods. Under the criteria for selecting between these methods might be computational efficiency.


For a given class of problems, some of these methods might be computationally more efficient than other methods. As an
example, if the problem is very close to a previously encountered case, then a case-based reasoning might be
computationally a very good method to use. On the other hand, if the new problem is very different from a previously
encountered case, then case-based reasoning may not be a computationally efficient method.


We've come across this issue of computational efficiency earlier in this class.


For example, when we were discussing generate and test. If the problem is simple, then it is potentially possible to
write a generator that will produce good solutions to it. On the other hand, for a very complex problem, the process of
generating good solutions may be computationally inefficient. Similarly, if there is a single goal, then the method of
means-ends analysis may be a good choice. On the other hand, if there are multiple goals that are interacting with each
other, the means-ends analysis can run into all kind of cul-de-sacs, and have poor computational efficiency. A third
criteria that metacognition can use to select between these various methods is quality of solutions.


Some methods come with guarantees of quality of solutions. For example, logic is a method of provide some guarantees of
the correctness of solutions.


Thus, if this is a problem for which computational efficiency is not important, where the quality of solutions is
critical, you might want to use the method of logic. Because it provides some guarantees of the quality, although it
might be computationally inefficient. The same kind of analysis holds for selecting between different learning methods.
Once again, given a problem, the agent may have multiple learning methods for addressing their particular problem. What
method should the learning agent choose? That depends partly on the nature of the problem.


Some methods are applicable to that problem, and some methods may not be applicable to that problem. Second, for
example, in this learning task, if the examples come in one at a time we might use incremental concept learning.


On the other hand, if all the examples are given together, then we might use decision-tree learning or identification-
tree learning. Another criteria for deciding between these methods could be computational efficiency that lay down what
the criteria could have to do with quality of solutions.


06 - Strategy Integration
-------------------------

Now we have looked at strategy selection a little bit, let us look at strategy integration. Even if the agent selects a
particular strategy, it is not necessarily stuck with that strategy. As the problem-solving evolves, it may well decide
to shift from one strategy to another strategy.


As an example, consider that for a given problem, metacognition decides to select the strategy of case-based reasoning.


Now case-based reasoning spawns a number of sub-tasks. Retrieval, adaptation, evaluation, and storage. Metacognition can
now examine the requirements for each of the sub-tasks. And then, with each of the sub-tasks, it may decide on some
strategy. For example, for the task of adaptation, metacognition may pick the method of case-based reasoning
recursively. Or it may pick the method of rules to adapt a case. Or it may use models for the case adaptation. If
metacognition picks the method of rule based reasoning, then note that metacognition has shifted from the method of
case-based reasoning overall to the method of rule-based reasoning. For a sub-task of case-based reasoning. We can also
use a similar analysis at the next lower level. Suppose that metacognition decides to pick the method of rule-based
reasoning for doing the case adaptation. Now the question becomes, what rule to apply. Rule 1, 2, or 3. We can imagine
meta-rules that select, which rule to apply in any given condition.


We've come across a use of metacognition for strategy integration earlier.


And this blocks microworld, we saw how means [INAUDIBLE] can reach a cul-de-sac.


When the cul-de-sac happens, metacognition may, set up a new reasoning goal and select a strategy of problem reduction
for resolving the cul-de-sac. Problem reduction then, sets up four independent goals. We made it work back to mean
internal assist to achieve each goal independently. In this particular case, we have integrated means and internal
assistance and problem reduction and the reasoning has shifted between these two strategies in a seamless way.


07 - Process of Meta-Reasoning
------------------------------

>> To summarize the spot then, metacognition can use the same reasoning strategies, that we have been studying at the
deliberative level.


08 - Discussion Meta-Meta-Reasoning
-----------------------------------

So if metacognition reasons over deliberation, could we also have an additional layer, where meta-metacognition reasons
over metacognition? And to take that even further, could we have a meta-meta-metacognition reasons over meta-
metacognition all the way up, infinitely up in a hierarchy?


Is this a good way to think about the levels of metacognition?


09 - Discussion Meta-Meta-Reasoning
-----------------------------------

>> This is really cool. So agents don't need multiple levels of metacognition, because metacognition [UNKNOWN] over
itself, recursively. In fact, current theories of metacognition, all talk about this kind of two-layered system between
deliberation and metacognition.


10 - Example Goal-Based Autonomy
--------------------------------

>> David's example of a robot that knows how to assemble cameras, but then is given the goal of disassembling a camera
is a good example of goal based autonomy. Earlier we had looked at, how an agent can go about repairing his knowledge or
reasoning or learning when it makes some mistake or reaches a failure. But sometimes it is not so much that the agent
reaches a failure, as much as it is that the agent is given a new goal.


When the agent is given a new goal, we do not want the agent to just fall apart.


We do not want brittle agents. We want agents that can then adapt their reasoning methods and their learning methods to
try to achieve the new goal.


Even if they were not necessarily programmed to achieve that goal.


We know that human cognition is very robust and flexible. You and


I address a very large number of tasks, a very large number of problems and achieve a very large number of goals. If we
are to design human level, human like AI agents, then those AI agents will have to be equally robust and flexible.
Metacognition provides a powerful way of achieving that robustness and flexibility. It does so by flexibly, dynamically,
selecting among competing strategies. It does so, reflexively and dynamically, integrating multiple strategies as the
problem solving evolves.


It does so, by using reasoning strategies and knowledge that were programmed into it to achieve new goals.


11 - Connections
----------------

So, like we said earlier in this lesson, we've actually been talking about kinds of meta-cognition throughout this
course, even if we didn't call it that at the time. We were talking about agents reflecting on their own knowledge, and
correcting it when they were introduced to a mistake. Earlier in this lesson, we also talked about the possibility that
an agent would reflect on the learning process that led it to the incorrect knowledge, and correct that learning
process, as well. Back during partial order planning, we talked about agents that could balance multiple plans and
resolve conflicts between those plans. This could be seen as a form of meta-cognition as well. The agent plans out a
plan for achieving one goal, a plan for achieving the other goal, and then thinks about its own plans for those two
goals. Then it detects the conflict between those two plans and it resolves that conflict accordingly. Then it detects
the conflict between those two plans and creates a new plan to avoid that conflict.


Here the agent is reasoning over its own planning process. We saw this in production systems as well. We had an agent
that reached an impasse, it had two different pitches which is suggested and it couldn't decide between the two.


Let's find a new learning goal to find a rule to choose between those pitches.


It then selected a learning strategy, chunking, went into its memory, found a case, and chunked a rule that would it
resolve that impasse. In this case, the agent used that impasse to set up a new learning goal. It didn't select the
strategy, strategy selection, to achieve that learning goal. We can also see medicognition in version spaces. Our agent
has the notion of specific and general models, and it also has the notion of convergence. The agent is consistently
thinking about it's own specific and general model, and looking for opportunities to converge them down into one model
of the concept. And finally, we can very clearly see metacognition in our lesson on diagnosis.


We talked about how all the results for our treatment become new data for our iterative process of diagnosis. If our
treatment didn't spond desirable results, it also sponds data for the metal layer. Not only do we still want to diagnose
the current malfunction,. But we also want to diagnose, why we weren't able to diagnose it correctly in the first place.
So, now we're diagnosing the problem with our diagnosing process. So as we can see, meta cognition's actually been
implicit in several of the topics we've talked about in this course.


12 - Meta-Reasoning in CS7637
-----------------------------

So finally, to make things as meta as possible, meta reasoning has actually been a motivating pedagogical goal for the
design of this very course. You'll notice that for almost every lesson, we start with an example of a problem that you
could solve. In incremental concept learning, for example, we start by giving you several examples of foos and not foos.
And then we asked you is this a foo?


In production systems, we gave you some information about a baseball game and asked you to decide what the pitcher
should do next. In learning by recording cases, we gave you a world of rectangles and asked you to decide what color a
new rectangle might be. In classification, we gave you a bunch of pictures and asked you to decide which of those
pictures were birds. In planning, we gave you our blocks micro-world and asked you to develop a plan to go from our
initial state to our goal state.


In each of these, we've started with the problem that we could solve, that we then wanted to design an agent to solve.


These examples then motivated our discussion not necessarily of how we did it, but how we could design an agent to do
it. Then at the end of each lesson, we revisited that example. We took the reasoning method that we designed for our
agent and looked at how that exact reasoning method would allow it to answer the same example with which we started the
lesson. When you did the example at the start of the lesson, you didn't necessarily know how you were able to solve that
problem. You could speculate, but you never know for sure. But then by building an agent that can solve that problem, we
start to gain some understanding for the processes that we must be able to engage in, in order to solve that problem as
well. So by designing the agent, we develop a greater understanding of our own cognition. So in this way, the very
design of the lessons in this course has been driven by trying to develop metacognition in you. In fact, developing
metacognition in students is the entire goal of my own PhD dissertation.


13 - Assignment Meta-Reasoning
------------------------------

So, how would you use meta-reasoning to design an agent that can answer Raven's progressive matrices? Throughout this
course we've covered a wide variety of different methods for addressing this test. And each method has its own strength
and its own weaknesses. Certain methods are better for some problems, and other methods for other problems. Meta-
reasoning will tell us, though, that you don't have to choose just one. Your agent can have multiple methods to choose
from. Discuss how you might design an agent to have meta-reasoning.


What methods would it have to choose from?


How will it evaluate a new problem and decide what method is best for that problem? How much improvement do you really
expect to see in your agent's performance based on equipping it with meta-reasoning? And finally, will your agent engage
in any kind of meta-meta-reasoning as we've discussed?


Will it not only think about the methods themselves but also about how it's selecting a method? And if so, how will that
improve it even further?


14 - Wrap Up
------------

So today we've talked about meta-reasoning. This very strongly leveraged and built on nearly everything we've talked
about so far in this course.


Meta-reasoning is, in many ways, reasoning about everything we've covered so far. We started off by recapping learning
from correcting mistakes and the related notion of gaps. Then we covered two broad metacognitive techniques called
strategy selection and strategy integration. We then discussed whether or not meta-meta-reasoning might exist. And we
decided, ultimately, that such a distinction isn't even necessary. After all, the structures involved in meta-reasoning,
like cases, and rules, and models, and the same as those involved in a reasoning, itself. So, meta-reasoning is already
equipped to reason about itself. Finally, we discussed a particular example of meta-reasoning, called goal-based
autonomy.


Meta-reasoning is in many ways the capstan of our course.


It covers reasoning of all the topics we've covered so far, and it provides a way that they can be used in conjunction
with one another.


We do have a few more things to talk about though, and we'll cover those in our Advanced Topics lesson.


15 - The Cognitive Connection
-----------------------------

Meta reasoning arguably is one of the most critical process of the human cognition. In fact, some researchers suggest
that, developing meta-cognative skills at an early age in life, may be the best predictor of a student success later in
life. Actually, this makes sense. Meta reasoning is not about simply learning new information, it is about learning how
to learn. About, learning new reasoning strategies.


About integrating new information into memory structures. Meta reasoning is also connected to creativity. In meta
reasoning, the agent is monitoring its own reasoning. It is spawning goals. It is trying to achieve them.


Sometimes it suspends a goal, sometimes it abandons a goal. These are all part of the creative process. Creativity is
not just about creating new products.


It is also about creating a processes, that lead to interesting products.


16 - Final Quiz
---------------

So you might notice that these quizzes at the end of every single lesson have asked you to talk about what you learned
in this lesson, to reflect on what you learned in this lesson. One of the goals of these final quizzes is to facilitate
your own metacognition about your learning of this material as well.


So by answering this, you think about your own learning, and hopefully improve it for the future. So what did you learn
during this lesson?


17 - Final Quiz
---------------

Thank you, for answering this quiz, on metacognition.


