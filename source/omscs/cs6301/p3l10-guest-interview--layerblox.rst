.. title: P3L10 Guest Interview- LayerBlox 
.. slug: P3L10 Guest Interview- LayerBlox 
.. date: 2016-05-27 23:48:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L10 Guest Interview- LayerBlox
================================


01 - Introduction
-----------------

>> Yes, so I started at Georgia Tech and ended up getting my PhD there in computer science. Did work in software
architecture, software engineering.


User interface design and kind of the intersection of those, those three.


After I got my PhD I was a faculty member at Michigan State University for about 12 years. Did research in, in formal
modeling of software architecture.


For the past I guess about six years, I've been working at a local company called Logic Blocks. That specializes in
smart databases, and uses a lot of the modeling ideas and formal methods ideas that I've been working on in, in my
research, in, in practice. So it's been very interesting.


02 - LogicBlox
--------------

>> Often on a daily basis. And sometimes, for some customers, even more frequently than that.


03 - Role
---------

>> Yeah, I also, I play a role in that, as you might imagine. we, we, we use, we're an agile shop, and so we, we tend to
like really short iterations.


Where we, we have demos at the end of those iterations.


We use your traditional gira and other kinds of technologies for issue tracking. But yeah, our, our process mainly is
one of, when we have a new project do an initial architectural assessment which may take a month or to to do the kind of
prototyping and and scalability analysis that we need.


And then we proceed and we start bringing developers on. Usually with a small number of developers, it scales up over
time rather than as a, with a big group that starts at the beginning. And we use a very iterative, usually one to two
week cycle iterations. So this, this is grunt process.


04 - Typical Application
------------------------

>> Correct. Correct.


05 - Motivation for LayerBlox
-----------------------------

>> Exactly. Yeah, you don't want to have to develop a system a component from scratch for each customer. You've got a
hundred customers, you don't want to have to develop a hundred components.


Now what you want to do is you want to develop one component very nicely so that it can be configured and packaged in
different ways very easily. And that's what, that's what we developed LayerBlox for.


06 - LayerBlox
--------------

>> Well, can you give us a 4,000 foot view of what LayerBlox is?


>> So, LayerBlox is a software generator for generating different variants of products in the same product line.


>> So you, you want to be able to generate all of these, these variants. how, how how does your generator actually work?


What does it take as input, and, and and, and, and how does it process that?


>> That's a good question.


So I should say first off that our generator is based on a pretty well understood idea from software engineering.


That goes back to, really goes go back to the, the early 90s on product line generation.


And so, each variant that we want to generate is a different program in the same product line.


And we, we organize our product lines in terms of re-useable features that we put into a library.


We've designed them according to a design idiom that, that, that makes them very composable with one another, which I'll
demonstrate here in a little while.


And what you do, then, to, to generate a variant is you write something called an assembly specification.


Assembly specification explains how you put these features together in some novel combination to generate a particular
variant.


And it has some particular useful properties, which I think we'll be able to, to dig into by example here in a few
minutes.


But what's really nice about it is the features you can write once and reuse many times.


And you can very easily understand by virtue of comparing these assembly specifications how two different variants in
the same product line are common and how they differ and be very precise about that.


>> And I'm curious about the, the title, LayerBlox.


Is it, is this related to layered architectures?


>> It is, it is.


When you see some examples of assembly specifications, you'll see that the, the components that we're generating, each
component, when I use the term variant, I mean program or component.


So the when you see how, how a given component is generated, you'll notice that it's, the little program you write to
say how to generate it, the recipe looks, is, is a very layered, very hierarchical form.


It's related to layered architectures in another way too, in the sense that typically with layer architectures, you tend
to think of of software built in stacks.


Where you can understand a layer you can understand one layer, just in terms of the interface that it exports, without
any knowledge of how it's implemented or of the layers that are underneath it. the, the assembly specifications that we
write using LayerBlox have that same property.


>> And, and just to, to clarify a bit.


The layers that you're talking about are, and the generated code you're talking about, they go in that middle tier?


>> No, they actually, in this case they could go in the middle tier.


But in this case they go in, down in the data tier.


>> Okay, so the, the tiering is kind of independent of the, of the layering?


>> That's correct.


That's correct.


>> And in the diagram, there's also this reusable feature library.


Can you say a word about that?


>> So, you know, I mentioned earlier that when we have a number of different clients, their programs and their
applications are very similar, but they're not exactly the same.


What we found is that if we do a decomposition and design of our software by feature and I know you guys have spoken of
feature diagrams and feature modeling in the past.


When you, when you when you do a feature-based design, you actually can get reusable pieces of, they're not whole
applications.


They're little fragments, but the, but they're highly reusable and composable in ways that you can put them together to
make different variants of a, of, of the same application very easily.


So we did a, in the example we'll see we basically did a feature analysis to understand what are the different features
that are put together to do forecasting.


And based on that feature analysis, we we designed our reusable features around it and, and got this ability to, to, to
compose them in this very, very nice way.


>> So the, the unit of variation is kind of, a customer-visible feature?


>> It may not be customer-visible, I, and, and ideally it, it could be, right?


And in other product line work it is the unit of visib, of the unit is customer-visible feature.


In our case, it's more implementation centric.


But, but still, it's, it's much more on the science side than, then the customer side so in our case, we, we're doing
forecasting.


And there are some pretty com, complicated algorithmics that go with, with forecasting.


So that domain is the domain at which we've we've done the future analysis.


07 - Assembly Spec
------------------

>> This is the description of one variant. That's correct.


08 - Components
---------------

>> Yeah, so let's look at this example and the different parts of it in some detail. So what I'm showing here in green
are the four different components that were generating as a virtue of this assembly specification. And as I mentioned a
minute ago, the only one that's the, the, the variant, the one that were interested in is batch. But the other three,
bFsct, mults and iFsct are all kind of sub components that are used to, to, to create batch.


You can think of a component as a little program.


It's clear that batch is a little program. It's a little forecaster but each of the other ones is a little program too.
iForecast is an incremental forecaster.


Mults is a set of multipliers and bFcst is a baseline forecaster.


09 - Interfaces
---------------

>> Yes it's, it's almost exactly the same use. So in Java interfaces you declare signatures of methods that many
different objects would objects of many different classless could could implement. It's essentially the same thing here


10 - Refinements
----------------

>> Exactly yeah, so but it's meant to, to, to appeal to that same sensibility, right? That you start, you can think of
an interface as representing an abstract program that fills in some details, and in particular, as in our case the
signatures of, of the different tables that are going maintain calculations that we, that we want to make, like
forecasts. But they may be implemented in many, many, many different ways. And so each refinement is a generator that
will generate a different way of of implementing that interface.


So it's, it's, it really is meant to appeal the same idea.


11 - Variants
-------------

>> Exactly, exactly and it's a different component. So we can actually put both of these in the install both of these
into our data base if you wanted to and then we would have a batch forecaster and a batch adjusted forecaster if we set
it aside.


12 - Product Lines
------------------

>> Win-win. Yeah.


13 - Possible Limitations
-------------------------

>> And we, we will put on the class resources page some links to some of the some of the some of the papers that Kurt is
referring to in case you want to look into them a little bit more detail.


14 - More on LayerBlox
----------------------

>> Sure. So once we built the code generator, we built a number of supporting tools that were useful in just
understanding these assemblies and communicating them to to others. One of them is a graphical visualization tool
that'll let you, let you look at in graph form in a, in a dot form. One of your assembly specs so that you can see
exactly what the dependencies are, how the different refinements compose with one another.


That's been really useful particularly as we were developing our [UNKNOWN] to begin with, because we've found that over
time we could compare these, these different visualizations and we could see them getting simpler and simpler. So that
was very useful. We also did we implemented some code metrics, so that we could track how large or small our refinements
were.


We, we hypothesized and this actually born out to be true that over time and after a lot of use, big refinements will
break down into compositions of smaller ones and in fact that's happened. And we use code metrics now to, to help us
find candidates that we should, should go kind of proactively dive into. So yeah, there are a number of little tools and
supports like that, that are pretty useful.


15 - Implications  Advice
-------------------------

>> You're very welcome, and thank you for the opportunity to tell the story.


