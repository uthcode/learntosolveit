.. title: 25 - Advanced Topics 
.. slug: 25 - Advanced Topics 
.. date: 2016-01-23 06:55:57 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

====================
25 - Advanced Topics
====================


01 - Preview
------------

To close this class, we are talking through a handful of advanced topics, related to the course material. In this course
we already discussed a variety of goals, matters and paradigms of knowledge based AI. Now let's close by talking through
about some of the advanced applications of this content.


We'll also talk quite a bit about some of the connections with both AI and human cognition. Many of the topics we'll
discuss today are very broad and discussion oriented. So we encourage you to carry on the conversation on the forums and
discuss all the issues that this content raises.


02 - Visuospatial Reasoning Introduction
----------------------------------------

Visuospatial reasoning is reasoning with visuospatial knowledge.


This has two parts to it, visual and spatial. Visual deals with the what part.


Spatial deals with the where part. So imagine a picture in which there is a sun on the top right of the picture. There
are two parts to it.


Sun, the what, the object. And where, the top right of the picture.


We have come across visuospatial reasoning a little bit when we use constraint propagation to do line labeling and 2D
images. One way of defining visuospatial knowledge is to say that in visuospatial knowledge causality is, at most,
implicit. Imagine a picture in which there is a cup with a pool of water around it. You don't know where the pool of
water came from.


But you and I can quickly infer that the cup must have contained the water, and the water must have spilled out as the
cup fell. So visuospatial knowledge, causality is implicit when it enables inferences about causality.


03 - Two Views of Reasoning
---------------------------

There're several ways of how we can deal with visuospatial knowledge.


In fact in your projects you've already come across some of them. So imagine there is a figure here. Here is a triangle
with the apex facing to the right.


Here is another triangle with the apex facing to the left. So in one view, the AI agent can extract propositional
representations out of figures like this.


And similarly propositional representations out of figures like this. So this is a propositional representation, this is
a propositional representation.


And then, the AI agent can work on these propositional representations to produce new propositional representations. So
some AI agent can use a logic engine or a production rule to say that this particular triangle, which was rotated 90
degrees, has not been rotated to 270 degrees. So although the input wasn't in formula's figures, the action here was at
the level of propositional representations of these figures. The agent may extract propositional representations like
this through image processing, through image segmentation, perhaps using some techniques like constraint propagation as
well.


Alternatively, the agent may have analogical representations.


In these analogical representations, it is a structural correspondence between the representation and the external
figure. So the external world headed triangle like this, and the analogical representation will also have a triangle
like this. Notice that


I'm using the term Analogical Representation, we use a separate thing from analogical reasoning. We are not talking
about analogical reasoning right now.


We're talking about analogical representation and analogical representation is one, which is some structural
correspondence with the external world that is being represented. Give a certain analogical representation, then I might
want affine transformations or set transformations to get this. So I may say that I got this triangle out of that one,
simply by the operation of reflection or rotation. So these proposed representations in the previous view are A model.


They are separated from, divorced from the perceptual modality.


These analogical representations on the other hand, are modal representations. They're very close to the perceptual
modality.


And human cognition, mental imagery, appears to use analogical representations.


What would be an equally intuitive of computational imagery?


Human cognition is very good at using both propositional representations and analogical representations. Computers
however, are not yet good at using analogical representations. Most computers, most of the time, use only prepositional
presentations. The same kind of analysis may apply to other perceptual modalities, not just to our visual images. So
here are two measures and we can either extract proposed representations out of them and then analyze those
propositional representations. Or, we could think directly with the relationship in these two particular measures. There
is a question for building queries of human cognition. When you're driving a car, and you listen to a melody on your
radio and you're reminded of something.


Reminded of a similar melody that you had heard earlier.


What exactly is happening? Are you extracting a purpose for your presentation out of the melody that you just heard? And
then the proposition representation reminds you of the proposition representation for a previously heard melody. Or,
does a new melody somehow directly remind you of a previously heard melody without any intermediate propositional
representation? These are our open issues in cognitive science, as well as in knowledge based AI. In cognitive science,
it is by now, significant agreement that human cognition does use mental imagery at least with visual images. But we
don't know how to do mental imagery in computers.


04 - Symbol Grounding Problem
-----------------------------

This chart summarizes some of the discussion so far. Content deals with the content of knowledge. Encoding deals with
the representation of knowledge.


Content and form. The content of knowledge can be visuospatial, that deals with what and where. Where is spatial, what
is visual, and the encoding of the visuospatial knowledge could be either analogical or propositional. An analogical
inquiry of visuospatial knowledge is a structural correspondence between the encoding and the external world that is
being represented. In the propository presentation of visuospatial knowledge, there is no such correspondence. Examples
of this verbal knowledge include things like scripts or going to a restaurant. The script for going to a restaurant
again can represented either propositionally or potentially analogically. And a propository presentation of the kind we
say we may have tracks and props and actors. In an analogical representation of the script for going to a restaurant, we
may have a short movie. In much of the codes, we have dealt with the right hand side of this chart with verbal knowledge
and prepositional presentations. Part of the point of this lesson on visuospatial knowledge and reasoning is that
reasoning and knowledge can be visuospatial, and representations can be analogical. But we have yet to fully understand
the role of human cognition and you [UNKNOWN] agents that can deal with visuospatial knowledge and analogical
representation.


05 - Visuospatial Reasoning An Example
--------------------------------------

1


One air system that does do visual spatial reasoning is called Galatia.


2


It was developed by Jim Davies here at Georgia Tech, about 10 years back.


3


Which is why it looks black and white and has this particular form.


4


We provide a reference to the paper and in notes.


5


There is a very famous problem and


6 a logical reasoning called a Duncke problem.


7


The Duncke problem goes something like this.


8


First I'll tell you a story.


9


And then I'll give you a problem.


10


And you should try to find an answer to the problem.


11


Let me begin with the story.


12


Once there was a king and not a specially good king who ruled a kingdom.


13


There was an army.


14


That was trying to overthrow the king.


15


But the king lived in a fortress and it was very hard to overthrow.


16


Moreover, the king had mined the roads, so that when the army went over


17 the roads, it would blow off, and most of the soldiers in the army would die.


18


The leader of the army decomposed the army into smaller groups, and


19 these smaller groups then came to the fortress from different directions.


20


Because each group is small enough, the mines did not blow off and


21 each group was able to reach the fortress at the same time.


22


They are able to overthrow the bad king.


23


This was a story, now let me tell you about the problem.


24


There is a patient with a cancer tumor in his body.


25


There is a physician with a laser gun.


26


She can use the laser gun on this tumor to kill this tumor and cure the patient.


27


However, the laser light is so strong that it will


28 also kill all the healthy tissue in the way, and the patient can die.


29


What should the physician do?


30


In most computer models of this problem,


31 this problem is solved using propositional representations.


32


So an example for proper surplus reduction for


33 the original story might be that if there is a goal,


34 and there is a resource, there is an obstacle between the resource and


35 the goal that split the resource into many different smaller resources and


36 bring them to the goal all at the same time but from different directions.


37


Most composition models or decomposition problem extract some causal pattern.


38


The causal pattern might be that if there is a goal and


39 there is a resourcable level, and


40 your resource can achieve the goal but there is an obstacle in the way.


41


Then decompose the resourcing to many smaller resources and


42 bring them to the goal in the same time from different directions.


43


The important part here is that this is the causal pattern


44 extracted out of the first story.


45


Once this causal pattern has been extracted,


46 it can be applied to this new problem.


47


So the physician may decompose the laser being into smaller beams and


48 focus them on the tumor at the same time, thus curing the tumour.


49


Jim wanted to ask whether one could do the same kind of problem solving


50 without extracting these causal patterns.


51


Could one use simply visual spatial knowledge?


52


So this is visual spatial knowledge because there is both a sense of what,


53 the fortress, as well as where, in the middle of the figure.


54


Notice there is visual spatial knowledge is represented prepositionally.


55


There are words here like fortress, and right road, and top road, and so on.


56


But there is no causality that is explicit.


57


You and I can infer the causality but it's not explicit.


58


His Galatea program was able to find a solution to the new problem


59 by transporting the visual spatial knowledge to the new problem,


60 one step at a time.


61


Thus it would map this top body part to the top rod.


62


One here, the left body part, the left rod here, and


63 therefore beside that, this can be decomposed.


64


This resources, denoted by this arrow,


65 can be decomposed into smaller resources.


66


And then the smaller resources can arrive at this central tumor


67 from different directions at the same time.


68


In this way, Galatea was able to solve the addition problem


69 without abstracting any causal pattern from it.


70


Of course, one might say that the causal pattern is implicit here, and


71 that is indeed true.


72


But the entire point of a visual spatial knowledge here is that the causal


73 pattern is not being obstructed, but as long as it is a problem-solving


74 procedure where each step is represented only visually spatially.


75


It is possible to transfer this


76 problem-solving proceeded to the new crop.


06 - Visuospatial Reasoning Another Example
-------------------------------------------

We just saw an example where visual spatial knowledge by itself, suffices too in our logical reasoning under certain
conditions.


Now let us look at a different problem. There suddenly are situations where we might want AI agents to be able to
extract [UNKNOWN] presentations.


Your projects one, two, and three did exactly that. One task, where AI agent might want build proper [INAUDIBLE]
representations out of regional spatial knowledge is when an AI is given a design drawing. So here is a vector graphics
drawing of a simple engineering system.


Perhaps some of you can recognize what is happening here. This is a cylinder and this a piston. This is the rod of the
piston. The piston moves. Left and right. The other end of the rod is connected to a crankshaft.


As this piston moves left and right, this particular crankshaft starts moving anticlockwise. This device translates
linear motion into rotational motion.


I just gave you a causal account. Although because [INAUDIBLE] only implicit in this [INAUDIBLE] spatial knowledge. You
and I were able to extract a causal account out of this. How did we do it? How can we help AI agents do it?


At present if you were to make a CAD drawing using any CAD tool that you want, the machine does not understand the
drawing. But can machines of tomorrow understand drawings by automatically building these causal models out of them?


Put it another way. There is a story that has been captured in this particular diagram. Can a machine automatically
extract the story from this diagram?


In 2007, Patrick Yaner built an AI program called Archytas. Archytas was able to extract causal models out of vector
graphics drawings of the kind that I just showed you. This figure is coming from paper and Archytas and hence the form
of the figure. We'll have a pointer to the paper in the notes.


This is how Archytas works. It began with a library of source drawings.


These were drawings that we already knew about. For each drawing order it knew about it already had done the
segmentation. The basic shapes for example might be things like circles and the composite shapes which were then labeled
like piston and cylinder. Then a behavioral model or a causal model which said what happens when the piston moves in and
out, namely the crankshaft turns. And then a functional specification we've said this particular system can work in
linear motion into rotational motion. So there was a lot of knowledge with each previous drawing that Archytas already
had seen. All of this knowledge was put into a library. When a new drawing was input into Archytas then it generated
line segments and arcs and intersections from it. And then, it started mapping them to the lines and segments and arcs
of previously known drawings.


Retrieve the drawing that was the closest match in drawing to the new drawing.


And then started transferring basic shapes, and then composite shapes, and it transferred each element through this
abstraction hierarchy all the way up to the functional level. As an example, if Archytas library contains piston and
crankshaft drawings like this along with causal functional models for them, then given a new drawing of a piston and
crankshaft device Archytas will then be able to assemble a causal functional model for the new drawing. Thus Archytas
extracted causal information from which spatial presentations to analogical reasoning.


07 - Ravens Progressive Matrices
--------------------------------

>> Wrote another computer program that used a different kind of analogical representation called a fractal
representation. And he was able to show that the fractal representation also enables.


Addressing problems from the Raven's test with a good degree of accuracy.


It provides references both Maithilee's work and Keith's work in the notes.


08 - Systems Thinking Introduction
----------------------------------

In this class we have talked a lot about how AI agents must be able to reason about the work. But the external work
consists of systems from many different kinds. A system is composed of heterogeneous interacting components.


The interaction within components, lead to processes of different kinds.


These processes can occur at many different of those abstraction.


Some of the processes might be invisible. Consider an ecosystem.


In an ecosystem, processes occur at many levels of abstraction. Physical, biological, chemical. Some of these processes
are invisible to the naked eye, but they influence each other. Similarly in business, businesses are composed of a large
number of interacting units, manufacturing, marketing, delivery, and so on. Each of these units can be described at many
levels of abstraction, from individuals, to teams, to full organizations. Given that the extra work consists of systems
of different kinds. Their agents must be capable of systems thinking.


They must be capable of thinking about the invisible properties of systems.


About the complex behavior of the systems. In particular, they must be able to derive the invisible processes from the
visible structure.


This is systems thinking.


09 - Systems Thinking Connections
---------------------------------

>> In any complex system, there will be many levels of abstraction, some invisible, some visible. The human eye or human
senses, more generally, can see only some of these levels of abstraction in visible levels of abstraction. System
thinking helps us understand invisible levels.


10 - Structure-Behavior-Function
--------------------------------

So AI has drawn up representations that help capture both divisible levels of obstruction structure for example. And the
indivisible levels like behavior and function. Therefore these models are sometimes called structure, behavior,
function. Let's take a simple example. All of us are familiar with the household flashlight. You press on the button and
light comes out of the bulb. What you can see is, the button and the bulb and the body of the flashlight. You can even
open the body of the flashlight and you might see some batteries inside your flashlight. That's all you can see.


But of course there is more going on here. To begin with, this particular flashlight has a function. This function is
invisible.


You can ascribe to it, but it's nowhere inside the body of the bulb.


One level at which it is used would analyze the flashlight is, to ask ourselves what does it do. Not yet, how does it
work? Just what does it do, its function. Here is a representation of the function. Here is the function, create light
off that light bulb circuit, or the flashlight light bulb circuit.


There is some stimulus, some external force on the switch.


Initially there was no light, zero lumens and finally there is some light,


30 lumens. This captures the notion that when I press on the switch, light comes out. Here is a presentation of the
structure of the flashlight.


Here is a light bulb, the switch, and the battery. And they're connected.


All of them are attached. Here is the invisible causal process that we're calling behaviour. We'll capture this behavior
through a series of states and transitions between these states. So here is electricity initially in the battery. Then
this electricity flows from the battery to the bulb, and then the bulb converts this electricity into light. But in
order for this electricity to flow to the bulb, this particular switch has to be in the mode ON. The switch goes into
the mode ON, when someone presses on it.


Electricity is converted to light, because that's the function of the bulb.


Notice that these SBF models are nested.


We just gave an SBF model of the flashlight circuit. But now if you want, we can do the SBF model of the lightbulb
itself. How does it create light? In this way, structure behavior function models capture not just the visible
structure, but also the invisible cause of processes, the behaviors and the functions. Moreoever, they capture the
multiple abstraction, at the level of the flashlight, at the level of the bulb, and so on.


We'll not describe it in detail here, the structure behavior function models and other similar models enables systems
thinking in the context of diagnosis and design of complex systems. You're provided some readings about this in the
course materials, if you want to read more about it.


11 - Design Introduction
------------------------

When we talked about configuration, we alluded to design.


Design is a very wide ranging, open ended activity. But then we settled on to configuration, very routine kind of
design, where all the parts of the design are already known, we simply have to figure out the configuration of the
parts.


It is time now to return to design thinking. What is design thinking?


Design thinking is about thinking about ill-defined, underconstrained, open ended problems. Let's a design a house that
is sustainable is an example of design thinking. Sustainability here is ill-defined. The problem is open ended.


In design thinking, it is not just that a solution that evolves, it is that the problem it was as well. We have problem,
solution, coevolution.


12 - Agents Doing Design
------------------------

As we have mentioned earlier, configuration is a kind of design, a kind of routine design. And one material
configuration is bound refinement.


In configuration, all the components of the design are already known, but we are to find some arrangement with the
components, and we assign values to some of the variables of those components, to arrive at the arrangement. Here is a
design specification working it's way.


Here might be a plan for designing a chair as a whole. And once we assign values to some of the variables at the level
of the chair, then we can refine the plan for the chair into a plan for the chair legs, the chair seat, and so on. All
of this might be subject to some constraints.


There are in fact a number of AI systems, that do configuration design.


Many of them are being used in industry. Some of these AI systems use, matters like brand refinement the way we are
showing it here.


Others use case based reasoning. And various systems use a variety of methods, for doing configuration design, including
model based reasoning and rule based reasoning. What about more creative kinds of design? Design in which not all the
parts are known in advance. Since we just discussed the flashlight example, in the context of systems thinking, let us
revisit that example in the context of creative design. So this is a schematic of the flashlight circuit.


Here is the switch, the battery, the bulb, as earlier. On the systems thinking, we discussed how structured behavior
function models capture the knowledge that when the switch is closed, electricity flows from the battery to the bulb,
and the bulb converts the electrical energy into light energy. Let us suppose that this particular electrical circuit
use a 1.5 volt battery and created 10 lumens of light. Tomorrow someone comes to you and says, I want 20 lumens of
light. Design a flashlight electrical circuit for me.


How will you do that? You might go to the structure, behavior function model for this particular circuit and do some
thinking. You may recognize, the amount of light created in the bulb is directly proportional to the voltage of the
battery. Instead of creating 10 lumens of light you need 20 lumens of light, you might say, I'm going to use a 3 volt
battery. So far, so good. You've done system thinking in the context of design thinking. But now let us add a wrinkle.


Suppose that a 3.0 volt battery is not available. At this point, a teacher tells you it's okay if a 3.0 volt battery is
not available.


You can connect two 1.5 volt batteries in series. Two 1.5 volt batteries connected in series will give you the voltage
of three volts.


Accepting the teacher's advice, you can now create an electrical circuit that will use two 1.5 volt batteries in series
and create light of 20 lumens.


But you're not just creating this particular design, you also learned something from it. Every design, every experience
is an opportunity for learning.


In the 1990s, Sam [UNKNOWN] here at Georgia Tech created a program called IDOL,


IDOL did creative design. In particular, IDOL would learn about design patterns.


From simple design cases, the kind we just talked about.


I'm sure most of you are familiar with the notion of design pattern, design patterns are a major construction software
engineering. But design patterns are not just in software engineering but in all kinds of design, for example
architecture and engineering and so on. There is some way of capturing the design pattern that can be learned from the
previous case. A field of design of a device that changes the valuable variable from one value to another value.


And you want another design that changes the value the same variable to some other value not the same as the previous
design. One way you in which you can create the new design is. By replicating the behavior of the previous design.


So not just having behavior be one for the first design, but having this behavior be one as many times as needed. Let us
connect this to the example we just saw. If you have a design of an electrical circuit that can create 10 lumens of
light, and you know how to do it through some behavior B1.


I need to design an electrical circuit that can create 20 lumens of light, but you don't know the behavior of B2. Then
this behavior B2 is a replication of behavior B1 by connecting components and series.


Once Sam's program IDOL had learned about this design pattern of cascading, of replication, then, when it was given the
problem of designing a water pump of higher capacity than the one available.


It could create a new water pump by connecting several water pumps in series.


Thus, ideal, created new designs in one domain, the domain of water pump, through analogical transfer of design patterns
learned under the domain, the domain of electrical circuits. You would form the perspective of the new domain of water
pumps initially did not know about all the components about all the water pumps that will be needed. With Sam's program,
IDOL is creative enough to know that the pattern of problems here in the water pump is exactly the same pattern that was
also occurring in the domain of electrical circuits.


Sam's theory provides a computational account of not only how design patterns can be used, but also about how these
design patterns can be learned and transferred to new domains. There is of course a lot more to design.


We said earlier that design thinking engages problem solution, core evolution. It's not just that a solution evolves but
the problem remains fixed. But the problem evolves even as the solution evolves.


It's not quite clear how humans do this kind of creative design, with this problem solution co evolution. There is
certainly a few AI systems capable of problem solution coevolution at present


13 - Creativity Introduction
----------------------------

This brings us to the topic of creativity. We humans are naturally very creative, and I'm not talking just about an
Einstein or a Mozart. You and


I are very creative on an every day basis. You and


I constantly deal with our problems. And with dealing with our problems, we don't just give up, we address them and most
of the time fairly successfully.


Now the goal of knowledge-based AI is to create AI agents that can think and act like humans. So shouldn't we also
create knowledge-based AI agents that are creative? But in order to answer this, we have to define what is creativity.


In lesson one, we saw how hard it was to define intelligence.


Defining creativity is no less hard. But we will give it a try anyway.


14 - Exercise Defining Creativity I
-----------------------------------

In order to build AI agents that are creative, it might be useful to think about, what is creativity? Please write down
your answer in this box and also post your answer in the class forum.


15 - Exercise Defining Creativity I
-----------------------------------

>> So after much deliberation I decided I would define creativity simply as anything that produces an non-obvious,
desirable product.


I think that we have to have to sort of output for creativity in order for it to be actually be identifiable as
creativity. I think that the output has to actually be wanted in some way. Doing something that no one wants is not
necessarily creative. I think the output has to actually be desirable in some way, and it also has to be something non-
obvious. Doing the obvious answer is not a very creative solution. If I'm propping open a door and


I use a chair, it's a slightly more creative solution to that problem.


Thank you David. Or course everyone's answer to this question may differ. For example, some people may not put the word
product here.


It's not clear that the result of creativity is necessarily a product.


Some people do not put the word desirable there because sometimes creativity may not result from some initial desire.
Let us carry on this discussion of what is creativity on the forum. Feel free to add your own notions.


16 - Defining Creativity II
---------------------------

>> Good question, David. Novelty had use with newness, the unexpectedness had use with something non-obvious or
surprising.


Perhaps this will become clearer if I take an example. So in my deal, we decide to entertain a group of 20 friends. We
already know how to make soufflés according to a particular recipe. We'll make soufflé for 20 friends this time.


We have never made soufflé for 20 people, so something is novel, something new, something we haven't done earlier. On
the other hand, we have known this recipe for ages. Something unexpected would be if we come up with a new recipe for
this soufflé which taste dramatically different, surprisingly different.


Not just something new, but something unexpected. So far we have been talking about the product of creativity, the
result of creativity, the outcome of creativity. What about the process of creativity? You use it on here some and
other, both of these terms are important. Let's first look at the term other.


In this course we've only talked about several processes of creativity.


An analogical reasoning is a fundamental process of creativity. You already explored an analogical reasoning in the
context of designing. We just did that when were talking about design thinking. One might be able to design a new kind
of water pump, but composing several water pumps in series if one can analogically transfer a design factor from the
domain of electrical circuits.


Was a very good example. Similarly under analogical reasoning, we were talking about the processes that might be used to
come up with a model the atomic structure the analogy to the model the solar system, which clearly is a creative process
that cuts across large number dimensions of space and time. Another place where we talked about creative processes was
when we were talking about explanation based learning. It seems creative, if the robot can go to the kitchen, and use
the flower pot as a cup to bring you coffee.


Here are three other processes of creativity. Emergence, re-representation, and serendipity. A simple example of
emergences. If I draw three lines. One, two, three. Then a triangle emerges out of it. The triangleness doesn't belong
to any single line. I was not even trying to draw a triangle. I just drew three lines, and a triangle emerged out of it.
Emergence of the triangle to the drawing the three lines is a kind of creativity. Re-representation occurs when the
original representation of the problem is not conducive to problem solving.


So we re-represent the problem and then commence problem solving.


To see an example of this. Let's go back to atomic structure and solve this problem. Suppose that we have a model sort
of system which uses the word the planets revolve around the sun. You also have a model of the atom, and this uses the
term the electron rotates around the nucleus.


The model of the sun had the word revolve. The model of the atom has the word rotates. The two vocabularies are
different. If you were to stay with, with this couple of sort of presentations mapping between rotate and reward would
be very hard. On the hand, suppose we were to re-represent this problem.


Re-represent the atomic structure by growing the nucleus in the middle and the electron around it. We represent the
solar system by drawing the sun in the middle and the earth around it. Then in this new representation, we can see the
similarity, we can do the mock-up.


This re-representation is another fundamental process of creativity.


Serendipity can be of many types and can occur in many different situations.


One kind of serendipity occurs when I'm trying to address a problem but


I'm unable to address it. So I suspend the goal and I start doing something different. Later, at some other time, I come
across a solution, and


I connect it with the previous, suspended goal. The story has it that in 1941 in


France, Josh Mistral's wife asked him to help her open a dress by pulling on a zipper because it was stuck. Mistral
struggled with the zipper, but couldn't pull it down. Later on one day, Mistral was walking his dog, when he found that
some birds were stuck to the dog's legs. Curious about this,


Mistral looked at the bird closely under the microscope, he then connected the solution, the bird solution to the
opening of the zipper problem and out of that was born the notion of Velcro which you and


I now use on a common basis. But just like the word other was important here, these are three processes in addition to
the process we already discussed in this class. The word some is also important here.


This is not an exhaustive list. There are in fact additional things we can add.


For example, another potential process here is called conceptual combination.


17 - Exercise Defining Creativity III
-------------------------------------

Let us do an exercise together. Here are a number of tasks that we have come across in this class. For each of these
tasks, mark the box if you think that the agent that performed that task well, is a creative agent.


18 - Exercise Defining Creativity III
-------------------------------------

>> So actually, I marked none of them. It seems to me that for all of these tasks if an artificial agent that we design
accomplishes the task, we're able to go back and look at its reasoning, look at its processing, and figure out exactly
how it did it. So it's never going to be unexpected.


It's always the output of a predictable algorithm. Interesting [UNKNOWN] David.


Not sure I agree with it. Let's discuss it further.


19 - Exercise Defining Creativity IV
------------------------------------

Do you agree with David's assessment that none of these areas is creative because we can trace to the process that the
agents used?


20 - Exercise Defining Creativity IV
------------------------------------

But let's look at each of these choices, one at a time. The first one says yes, because in order for a result to be
creative, it must be novel, an output of an algorithm cannot be novel. Well, there are a few problems with this
particular answer. What if an output of an algorithm for a small, closed-word problem cannot be novel?


The output of combinations of algorithms for open ended problem can and indeed sometimes is novel. There are algorithms
for example, that do design or that do scientific discovery, whose results are novel. Let's look at the second answer.
Yes, because given a set of input, the output will always be the same.


Therefore, the product can never be unexpected. The output will depend not just on the input. And not only on the
methods of the system, but also the situation in which the methods are situated.


The output depends not just on the input under the method the AI agent uses, but also the context in which the AI agent
is situated. For example, given the same input but different context or the input, the agent will come up with very
different outputs, very different understandings of that same input as we saw in this section on understanding. The
third answer, no because it defines creativity in terms of the output rather than the process.


This answer too has problems, because sometimes creativity can be defined simply in terms of the output without knowing
anything about the process.


We can think of a black box, that creates very interesting creative music. We would not know anything about the process
that it is using. But, if the output's interesting and creative music, we would consider it to be creative. Personally,
my sympathies lie with the fourth answer. But, of course you are welcome to disagree with me. Why don't we continue this
discussion on the forum?


21 - AI Ethics
--------------

Finally, the last topic we'll cover in this class is AI ethics. Often, scientists go about doing science without asking
questions about the ethics of the science they do. We are also engrossed in questions of funding and proposals and
papers. However, part of our job as scientists is to ask the question about are we doing the right kind of things? There
are a large number of questions connected with the ethics of AI. We'll post a small number here today.


There are no easy answers to these questions. So I invite you to discuss these questions on the forum? First, AI Ethics
put into our economy and our society.


We have talked a lot in this course about designing AI agent that can act and think and behave like humans. However, in
the process, we quite likely would replace some human jobs with robots. We have talked, for example, of robots that can
assemble a camera. Does this mean that humans who assemble the cameras today will lose their jobs? Of course, a counter
argument is that new jobs might be created, for example, jobs for designing robots. Nevertheless, there are hard issues,
but ethical implications of AI in terms of human economy and society. Second, much of the modern development of AI is
driven by defense applications all across the world.


We already have drones, for example. It is not far-fetched to imagine a future where there are robot soldiers on the
battlefield. What are the implications of introducing robot soldiers? Should we build morality into these soldiers?


How do we do so? And if you are to build morality into robot, what does it teach us about our own morality? A third and
related question is, that if it's hard building human characteristics like creativity and morality into AI agents, at
what point do these agents become like humans?


At what point do we start talking about civil rights for these machines because they're indistinguishable from humans.
The idea has been touched upon in the popular culture a lot, but it is coming closer and closer to reality.


What are the criteria under which we'd consider machines to be equal to humans?


22 - Open Issues
----------------

So today we've covered some of the most advanced and cutting edge topics in knowledge-based AI. If anything we've talked
about today has really caught your eye, we invite you to check out the course materials, where we've provided several
readings about each topic. As we said at the beginning, many of the things we've talked about today are open issues that
the community is wrestling with right now, so we encourage you to take up the discussion over on the forums. We'll be
there participating as well.


23 - Final Quiz
---------------

Please write down what all you learned in this lesson, in this box.


24 - Final Quiz
---------------

Great, thank you very much.


