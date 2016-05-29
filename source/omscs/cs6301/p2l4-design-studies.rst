.. title: P2L4 Design Studies 
.. slug: P2L4 Design Studies 
.. date: 2016-05-27 23:41:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P2L4 Design Studies
===================


01 - Design
-----------

Design is all about making decisions. Generally trading off among nonfunctional criteria. There are various sources that
can inform these decisions.


Such as the customer, the end user, technology specifications, and competitor's products. Sometimes however, a more
detailed analysis is required.


Examples of such devices include simulations, prototypes, and the topic for today, design studies.


02 - Design Studies
-------------------

When an architect designs a building, often one of the early steps is to undertake a design study. This takes the form
of a series of scale models where different approaches are explored in order to get a better feel for the design space,
which is the range of possibilities available as solutions.


The same approach is used in other areas, other areas of design such as cars, planes and even clothing.


03 - Definition
---------------

A design study is a rigorous and systematic evaluation of the factors that influence a design. It should begin with a
determination of the relevant criteria, how they are to be measured, and what measurement values are deemed
satisfactory. The study itself consists of a comparison of the various possible approaches in which each approach is
measured against the predetermined criteria


04 - Design Spaces
------------------

The process of doing a design study helps the designer explore a space of possibilities. Although aesthetics may play a
role in the ultimate decision process, other more objective factors should be examined as well.


For buildings factors such as the cost of construction, availability of building materials, conformance to building
codes and zoning regulations and effect of traffic on traffic patterns may be taken into account. For this class, we
want to use design studies to evaluate the design of computer programs.


05 - Design Factors Quiz
------------------------

What are some of the factors that might be used to compare different versions of a program? Type your answers into the
text box.


06 - Design Factors Quiz Solution
---------------------------------

Did you say things like performance, memory footprint, time to construct?


Note that we particularly don't include correctness in the factors to compare.


That is, we assume that all the versions that are constructed work, but differ in other nonfunctional ways.


07 - Teaching and Learning
--------------------------

I hope this doesn't come as a surprise, but


I can't really teach you design. The best that I can do is to teach some of the surrounding skills such as analysis,
modeling and evaluation. Instead, design must be learned, learned from doing. Hence a significant portion of your effort
in this course should be spent actually designing. The vehicle for doing this designing is a series of projects, each
accompanied by a design study.


08 - Projects
-------------

Each of the projects involves solving a design problem in several ways.


To determine which approach is best, you are asked to evaluate your solutions in a systematic way, that is, to conduct a
design study. The result of each study is documented in a report that conforms to a prescribed format laid out in a
template file linked to from the class resources page. We will now go through the contents of the template as a way of
illustrating what a software design study is all about.


09 - Experiments
----------------

You can think of a design study as an empirical scientific experiment. As such, there are research questions, subjects
of study, experimental conditions, methods, tools, metrics, independent and dependent variables, data collection,
statistical analysis, and conclusions. As with a scientific experiment and overall goal of a design study is
repeatability. That is, someone else should be able to take your study report, use it to recreate the study conditions,
and reach the same conclusions that you did.


It is one of the goals of this class that you'll learn the skills to produce and present an industrial quality design
study.


10 - Report
-----------

The design study itself is presented in a report. It may include charts, tables, graphs and screenshots, as well as, as
well as descriptive text. It is, however, not a narrative, but a dish, dispassionate description of a systematic
exploration. I want your reports to be professional in quality. This means that you should treat it like you would if
you were preparing to show it to customers or submit it for publications. Its spelling and grammar should be checked,
and it should be carefully proofread by a team member other than its author.


We will now go through each of the sections of the report, indicating what is expected in that section. This should also
give you an idea of what you need to do during the study itself to gather the data that goes into the report.


11 - 1 Context
--------------

The first section is titled Context. It provides background and motivation for the study. So the reader who is not
familiar with the class or the project can make sense of what you have written.


It should also define any specialized vocabulary necessary for the reader to understand what you are saying in the
report.


12 - 2 Research Questions
-------------------------

Section two is titled research questions.


A designed study examines the tradeoffs between various non-functional requirements, for example, space and time.


Each tradeoff can be expressed in the form of a question, such as, how are execution times and memory footprint effected
as the amount of pre-processing computations vary?


The second section of your report lists such research questions.


Each question should be formulated in a neutral fashion with regard to the due, dependent variables being measured and
also indicate what factors are being varied.


That is, the independent variables.


And each question should be numbered for later reference in your report


13 - 3 Subject
--------------

In experiments, a subject is something that you are studying, usually a program.


A design study compares multiple subjects. In the third section of your report, each subject should be briefly
described, differentiating it from the other subjects.


14 - 4 Experimental Conditions
------------------------------

The fourth section is titled Experimental Conditions. A software design study normally means running several versions of
a program, making measurements, and evaluating the results. These programs' executions take place on computers
configured with resources. Such as their number of cores, the amount of RAM, their clock speed, and potentially net, the
networking that networks them together. To support the goal of repeatability, this configuration information should be
explicitly documented in your report. The fourth section of the design study describes the experimental conditions under
which the study is conducted.


In particular, it describes the environment of which the study will take place.


This includes elements such as the machines, [COUGH] their models, operating systems, programming languages any virtual
machines and their versions. Where relevent, the network, the build and execution parameters, input files, and
confounding factors. Such as other users on the machines at the same time or other, processes going on


15 - 5 Variables
----------------

The fifth section is titled variables. Design studies themselves have to be designed. In particular the independent and
dependent variables must be identified and appropriate metrics specified. Design studies, like experiments, allow
designers, like scientists, to alter conditions and note results. The altered conditions comprise the independent
variables. And the corresponding results comprise the dependent variables each variable has a unique name a description
and a unit of measurement such as seconds. Sometimes the units are easy for example time other variable such as
maintainability require you to think carefully and invent an appropriate way to measure it. But this section of the
design study describes the variables, both independent and dependent, the units and measures, and how the research
questions address them.


The section should also include a summary table, with three columns, which for each research question, lists the
independent and dependent variables you used, in answering the question.


16 - 6 Method
-------------

The sixth section describes the method that you use to conduct the study.


This includes the number of trials or measurement devices and tools, any randomization techniques were appropriate, and
number of significant digits you used in your measurements and so on.


This should also include an explicit statement of which subjects will be run, and the arguments used for each of your
trials. For example if you were studying the relationship of performance to grid size, you would want to specify what
different grid sizes you will be using. The section should also briefly describe any statistical techniques you will
use, for example linear regression


17 - 7 Results
--------------

The point of conducting a design study is to produce data and the seventh section is where you describe these. It's
titled the Results section. It presents the data collected and their statistical analysis.


Any speculations and generalizations are reserved for the next section.


18 - 8 Discussion
-----------------

The eighth section is where you get the opportunity to interpret the data you collected and provide a discussion of its
implications. This often means offering an explanation for of any unexpected values you see. This section also allows
you to reflect on the experimentation itself including any suggestions, any suggested further work or for improving the
study process itself.


19 - 9 Conclusions
------------------

The final section allows you to summarize your results, and draw any conclusions. In particular, in this section you
should provide explicit answers, to each of the research questions you raise in the second section.


20 - Deliverables
-----------------

Each of the projects in this course has three deliverables. The source code, involving, solving a specific problem in
several ways, a project report containing project specific content, and a design study report.


The design study represents an, the explicit knowledge about the design, that you learned during the project. In
summary, here are the expected sections to be included in the design that are important. Section one includes the
context.


That is the background, motivation and vocabulary.


Next section is the research questions. Then descriptions of the subjects, experimental conditions and the variables,
both independent and dependent.


Section six has the method. Then come the results, discussion and conclusions.


21 - Wrap Up
------------

I want to repeat that I can't teach you design, you have to learn it. And


I want you to learn it using the projects that have been defined for the course. I encourage you to invest energy in
those projects and to think systematically about the design issues that each one of them raises.


Express that systematic thinking in the form of some experiments that you run, then write up those experiments in the
form of a report. I think by doing this, it will force you to reflect upon the design process, and thereby, make it much
more real to you.


