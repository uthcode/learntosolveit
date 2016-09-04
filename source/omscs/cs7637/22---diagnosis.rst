.. title: 22 - Diagnosis 
.. slug: 22 - Diagnosis 
.. date: 2016-01-23 06:52:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

==============
22 - Diagnosis
==============


01 - Preview
------------

Today we will talk about diagnosis. Diagnosis is the identification of the fault or faults responsible for a
malfunctioning system. The system it could be a car, a computer program, an organism, or the economy. Diagnosis builds
on our discussion of classification and configuration. They start by defining diagnosis. They really setup two spaces.


A data spaces and a hypothesis space. Data about the malfunctioning system.


Hypothesis about the fault that can explain that malfunctioning system.


Then, we'll constructing mappings through data space to hypothesis space which amount to diagnosis. We'll discuss two
views of diagnosis, diagnosis as classification and diagnosis as abduction. Abduction in this context is a new term to
you. We'll discuss it in more detail today.


02 - Exercise Diagnosing Illness
--------------------------------

To illustrate the task of diagnosis, let us begin with an exercise.


When we think of diagnosis, most of us think in terms of medical diagnosis.


The kind of diagnosis a doctor does. So this particular exercise, is coming from medical diagnosis, actually it's a
made-up exercise from medical diagnosis. And here's a set of diseases, fictional diseases, that the doctor knows about,
along with the symptoms that each diseases causes. So, Alphaitis, for example, causes elevated A, reduced C and elevated
F and so on. Given this set of data, and this set of diseases, what disease or set of diseases do you think the patient
suffers from?


03 - Exercise Diagnosing Illness
--------------------------------

>> That's a good answer, David. Note that David did several things in coming up with his answer. First, he made sure
that his answer covers all these signs and symptoms. This is the principle of coverage. We want to make sure that the
diagnostic conclusion actually accounts for all the input data.


Second, we chose a single hypothesis over a combination of hypothesis, although the combination could have explain this
data as well. This is the principle of parsimony. In general, we want a simple hypothesis for explaining the entire
data. Third, these hypotheses can have greatest interactions between them, and these interactions can make your
diagnostic task quite complicated.


Fourth, they would use the term explanation. This is an important aspect for diagnosis. We want a set of hypotheses that
could explain the input data.


Now this [UNKNOWN] we did it in this simple exercise, because there is one single disease that can, in fact, explain all
the input data. What would happen if there was no single hypothesis that could cover the entire input data?


Or what would happen if there were multiple hypotheses that could equally well explain the input data? [UNKNOWN]
diagnostic task can be quite complicated.


04 - Defining Diagnosis
-----------------------

>> Note that we discussed the same diagnostic task in three different domains.


In each domain, there was a discrepancy between the expected and observed behaviors. And we tried to identify the fault
or faults responsible for it. Note also that we eluded to three different methods for doing diagnosis. The method of
rule-based reasoning, the method of case-based reasoning, and the method of model-based reasoning.


We haven't talked a lot about the method of model-based reasoning so far.


We will do so when we come to systems thinking later in the class. Of course, we can use the method of rule-based engine
not only for diagnosing car engines, but also for repairing computer hardware or for diagnosing computer software. In
this particular lesson, our focus will be on the diagnostic task. By now, all of us are already familiar with many
reasoning methods that are potentially applicable to the task.


05 - Data Space and Hypothesis Space
------------------------------------

We can think of diagnosis as a mapping from a data space, to a hypothesis space,


In case of a medical diagnosis, the data may be the greatest kind of signs and symptoms that I may go to a doctor with.
Some of the data may be very specific, some of it may be very abstract, an example of a very specific data is that a
[UNKNOWN] temperature is 104 degrees fahrenheit.


An example of the extraction of the data is that [INAUDIBLE] is running a fever.


The hypothesis space consists of all hypothesis that can explain parts of the observed data. A hypothesis in the
hypothesis space can explain some part of the data, In case of medicine, this hypothesis may reference to diseases.


A doctor may say that my hypothesis is that a shook is suffering from flu, and that explains his high fever. In the
domain of car repairs, this hypothesis may refer to specific faults with the car, for example, the carburetor is not
working properly. In the domain of computer software, this hypothesis may refer to specific methods not working
properly.


And this mapping from data space to the hypothesis space can be very complex.


The complexity arises partly because of the size of data space, partly because of the size of hypothesis space, partly
because the mapping can be M to N. And also, because this hypothesis can interact with each other, If H3 is present,


H4 may be excluded, If H5 is present, H6 is sure to be present and so on. It helps then not to deal with all the raw
data, but to deal with abstractions of the data, so the initial data that a patient may go to a doctor with may be very,
very specific. The signs and symptoms of their particular specific patient, but the diagnostic process might abstract
them from Asok has a fever of 104 degrees farenheit to Asok has a high fever. This abstract data that can be mapped into
an abstract hypothesis,


Asok has high fever can get mapped into Asok has a bladder infection for example. The abstract hypothesis can now be
refined into a suffering from flu or a flu for a particular screen. At the end, we want a hypothesis that is as refined
as possible, and that explains all the available data. When we were talking about classification, we talked about two
processes of classification, bottom-up process and our top down process. The bottom up process of classification, we
started with raw data and then grouped and abstracted, it in case of top down classification we started with some high
level class and then established it and refined it.


You can see that in diagnosis both the bottom up process of classification, and the tope down process of classification
are co-occurring.


This method of bottom up classification and data space, mapping and hypothesis space, and then top down classification
of hypothesis space is called heuristic classification. This is yet another method like rule-based reasoning, case-based
reasoning, and model-based reasoning with a diagnostic task.


06 - Problems with Diagnosis as Classification
----------------------------------------------

>> In general, cancellation interactions are very hard to account for.


In order to address these factors that make diagnosis so complex, it is useful to shift from the perspective of
diagnosis solely as classification to a perspective of diagnosis as abduction.


07 - Deduction, Induction, Abduction
------------------------------------

>> Or given the rule if flu then fever and the fact that Ashok has fever we might be able to abduce that Ashok has flu.
First of all notice that we are back to diagnosis. Diagnosis is an instance of abduction. But notice several other
properties. First, deduction is truth preserving.


If the rule is true, and the cause is true, we can always guarantee that the effect is true as well. Induction and
abduction are not truth preserving.


We may know something about the relationship between cause and effect for some sample, that does not mean that the same
relationship holds for the entire population. Induction does not always guarantee correctness. Same for abduction.


We may know the rule and the effect, and we may suppose that its cause is true, but that may not necessarily be true. It
may be the case, if flu then fever, and


Ashok may have fever, but that does not necessarily mean that Ashok has flu.


Fever can be caused by many, many things. The reason that fever does not necessarily mean that Asoka's flu is because
there can be multiple causes for the same effect, multiple hypothesis for the same data. This is exactly the problem
that we had encountered earlier when we talking about what makes diagnosis hard. We said that deduction, induction, and
abduction, are three of the fundamental forms of inference.


We can of course also combine these inferences. Science is a good example.


You and I as scientists, observe some data about the world. Then, we abduce some explanation for it. Having abduced that
explanation for it, we induce a rule. Having induced a rule, now we can use deduction to predict new data elements. We
go and observe some more. Again, we abduce. Induce. Induce. And we continue the cycle.


Might the cycle also explain significant part of cognition?


Is this what you and I do on a daily basis? Abuse, induce, reduce?


08 - Criteria for Choosing a Hypothesis
---------------------------------------

Now that we understand abduction, and now that we know the diagnosis is an instance of abduction, let us ask ourselves,
how does this understanding help us in choosing hypotheses? So the first principle for choosing a hypothesis is
explanatory coverage. A hypotheses must cover as much of the data as possible.


Here's an example, hypotheses H3 explain data items D1 through D8.


Hypothesis H7 explains data item D5 to D9.


Assuming that all of these data elements are equally important or equally salient, we may prefer H3 over H7 because it
explains for of the data than does H7. The second principle for choosing between competing hypotheses is called the
principle of Parsimony.


All things being equal, we want to pick the simplest explanation for the data.


So consider the following scenario. H2 explains data elements D1 to D3.


H4 explains data elements D1 through D8. H6 explains data elements D4 to D6 and H8 explains data elements D7 to D9.


Now if you went by the criteria of explanatory coverage, then we might pick H2, plus H6, plus H8, because the three of
them combined, explain more than just H4.


However, the criteria of Parsimony would suggest if you pick H4, because H4 alone, explains almost all the data, and we
don't need the other three hypothesis. In general this is a balancing act between these two principles. We want to both
maximize the coverage, and maximize the parsimony. Based on this particular example, we may go with H4 and


H8. The two together explain all the data and in addition, the set of these two hypotheses is smaller than these set of
hypotheses H2,


H6, and H8. The [UNKNOWN] criteria for choosing between competing hypotheses is that we want to pick those hypotheses in
which we have more confidence.


Some hypotheses are more likely than others. You may have more confidence in some hypotheses than in others. As an
example, in this particular scenario,


H3 may explain data items D1 to D8 and H5 may explain more data elements from D1 to D9. So H5 also explains D9 that H3
doesn't.


However, we may have more confidence in H3, and so we may pick H3 instead of H5.


Once again this is a balancing act between these three criteria for choosing between competing diagnostic hypotheses. A
quick point to note here, these three criteria are useful for choosing between competing hypotheses even if the task is
not diagnosis. The same problem occurs for example in intelligence analysis. Imagine that you have some data that needs
to be explained and your competing hypothesis for explaining that particular data, well, you may pick between the
competing hypothesis based on this criteria.


All of the task is not a diagnostic task. These three criteria are useful for explanation. Diagnosis simply happens to
be an example of this [UNKNOWN] task.


09 - Exercise Diagnosis as Abduction
------------------------------------

Let us do an exercise together. The data in this particular exercise, a little bit more complicated than in the previous
one.


On the right-hand side, I've shown a set of diseases. What disease or subset of these diseases best explains the
available data?


10 - Exercise Diagnosis as Abduction
------------------------------------

>> Note that one can use alternative methods for the same problem. For example, one could use K-space reasoning. And for
when we came across a problem very similar to this one previously.


Suppose that the solution of that particular problem was ever labeled as a case.


In that particular case, B was high, C was low, and H was low. And the solution was Thetadesis. In the current problem,
the additional symptom is that F is low.


So case retrieval would first lead you to the conclusion of Thetadesis.


Only to [UNKNOWN] this particular solution to also account for the additional symptom of F being low. We could do that
by adding Kappacide and


Mutension to Thetadesis. Case based system thus would tend to focus the alternate set of hypotheses. One more point to
note here then.


Note that different methods can lead to different solutions.


Given different methods, how might an AI agent decide which method to select?


We'll return to this particular problem when we discuss meta reasoning.


11 - Completing the Process
---------------------------

>> We can also think of this last phase as a type of configuration which we talked about last time. Given a set of
hypothesis about illnesses or faults with a car, we can then configure a set of treatments or repairs that best address
the faults we discovered before.


12 - Assignment Diagnosis
-------------------------

So would the idea of diagnosis help us design an agent that can answer Raven's progressive matrices? Perhaps the best
way to think about this is to consider how your agent might respond when it answers a question wrong.


First, what data will it use to investigate its incorrect answer?


Second, what hypotheses might it have for incorrect answers?


Third, how will it select a hypothesis that best explains that data? And last, once it's selected hypothesis that
explains that data, how will it use that to repair its reasoning, so it doesn't make the same mistake again?


13 - Wrap Up
------------

So today, we talked about diagnosis which is a term we're very familiar with from our everyday lives. But today, we
talked about it specifically in a knowledge-based AI sense. We started off by defining diagnosis, which is finding the
fault responsible for the malfunction in some system.


This can be computers, computer programs, cars or even people and animals.


We then talked about the process of diagnosis, mapping data onto hypotheses and how we can see this as a form of
classification. We discovered though that this can be a very complicated process and classification might not get us all
the way there. So then we talked about diagnosis as a form of abduction.


Given a rule and effect or a symptom, we can abduce the cause of that problem, like an illness or a software bug. Both
configuration and diagnosis have been small tasks in the broader process of design. Now that we talk about them, we can
talk about AI agents that can actually do design in the real world, as well as what it would mean for an AI agent to
really be creative.


14 - The Cognitive Connection
-----------------------------

Diagnosis is a very common cognitive task. It occurs whenever our expectations are violated. We start diagnosing. Why
were our expectations violated?


Within a system, we expect some behavior out of it. We get a different behavior.


Why did the system not give the behavior we expected from it? Notice that diagnosis is a task. We can use several
methods to address it, like case-based reasoning. We have discussed diagnosis on several contexts like medicine, program
debugging, car repair, but it's also very common in other aspects of our life. For example, you get unexpected traffic.
Why did it occur? We review interaction with a co-worker or the economy. All are examples of diagnosis


15 - Final Quiz
---------------

Please write down what you learned in this lesson.


16 - Final Quiz
---------------

Thank you very much.


