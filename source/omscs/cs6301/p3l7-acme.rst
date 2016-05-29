.. title: P3L7 Acme 
.. slug: P3L7 Acme 
.. date: 2016-05-27 23:54:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L7 Acme
=========


01 - ADLs
---------

The topic for today is Acme, which is an architectural description language.


As awareness of the importance of architecture has grown, so too have the tools available for working with them.
Examples include tools for drawing, simulation, analyzing, reverse engineering and reporting on software architectures.
A necessary step for tool interaction is a standard way for representing software architectures, that is for an
architectural description language or ADL. In this less we will look at one particular ADL called Acme.


02 - ACME
---------

Acme is a extensible ADL developed at Carnegie Melon University and


University of Southern of California's ISI. It was specifically designed to facilitate the interchange of architectural
descriptions among tools. And it comes with a variety of tools of its own. Including Acme Studio, which is a graphical
editor by which you can draw architectural diagrams.


AcmeLib which is an API in languages such as Java and C++ for interacting with these artifacts. And


AcmeWeb which is a document generator. More information about Acme can be obtained by following the link on the class'
resource page.


03 - ACME Features
------------------

The primary contribution of ACME is that it defines a vocabulary for talking about architectures. Other features include
an extension mechanism enabling tool specific sub languages to be imbedded in it. For example, a simulator might wish to
deal with timing information. ACME features generics, families and types for defining architectural styles. Further,


ACME is defined in such a way that ACME descriptions can be converted into first order logic suitable for use by
automatic reasoning tools such as type checkers.


04 - Architecture Vocabulary
----------------------------

Here is Acme's vocabulary. Some of it should be similar to you from the Garland and Shaw paper that you read, and terms
that we have been using to describe architecture so far. First off is components, these are computational elements and
data stores. Along with them come connectors, which are communication and coordination among. The components. Ports are
com, component interfaces, possibly including protocols. And roles are similarly connector interfaces. So you can
imagine plugging together components and connectors using their their po, ports and roles. The Acme term for
configuration is a system. It is the set of components and connectors you have for a particular architecture you're
describing, the actual configuration specified via what Acme calls attachments of the ports to the roles. I'll also be
talking about representations, which is Acme's way of describing hierarchical decomposition across multiple levels of
abstraction.


And rep-maps which are specific bindings between those levels of abstractions.


Those seven terms constitute all that Acme requires of you to understand in terms of building architectural
descriptions.


05 - Simple Architecture Example
--------------------------------

Here's a simple ACME description for a client server system.


At the outermost level is the keyword system indicating that what's being provided here is a configuration describing
this particular architecture.


The system has a name, in this case simple CS, and then contained within it, are some other statements describing the
constituents of that particular system.


In this case, there are two components. One is called client and one is called server, and there's one connector. Also
there are two attachments for plugging them together. The first component client has one port out of which requests are
sent. The second component server has one port for receiving a request. The connector, which is called RPC, has two
roles.


One of which is called the caller role and one of which is called the callee role. Then, in a natural fashion to attach
these together, the client's send request port is connected to the connectors caller role.


And similarly the servers receive request port is connected to the connectors callee role, hence we now plug together.


The client, the server, using the connector in such a way that the ports and roles are plugged into each other. The
system is thus configured in such a way that the client can send requests using its port through the connectors so the
server receives those requests and can then act upon them.


06 - ACME Quiz
--------------

To see whether you've understood this idea, here's a little quiz for you.


Take the ACME code you've just seen, and add a means for communicating errors from the server back to the client.


07 - ACME Quiz
--------------

Well we still have the same two components.


We haven't added anything there, but for each of the components we've added another port for dealing with these error
messages.


In particular for the client, it's now got a port which is called here err-trap, and symmetrically the server has
another port, this one for sending the alert.


We're going to add a new connector for dealing with this communication channel.


It's called error, okay, and it's got two roles.


One being the source of the error and the other being the sync or receiver of that error.


We still have the same two attachments we had for, for dealing with the main flow of communication, but now we've added
two more for dealing with error flow.


In particular, a clients error trap is connected to the connector sync and the receiver's alert port is connected to the
connector's source role.


08 - ACME Graphical View
------------------------

Although what we just looked at is, looks like a programming language, syntax, text and so on, if you use ACME, you'll
likely to use it through its graphical editor, in which case, you can draw all of what's going on.


Here is a screenshot from, the ACME studio tool.


It, it contains two rectangles which correspond to the components and one circle which corresponds to the connector, and
you can see that the two components are both plugged into the connector and hence, can communicate with each other. If
you build your description using the graphical editor, you can then generate the code we've just seen in the textual
form.


09 - Decomposition
------------------

What we've seen so far, is capable of dealing with simple, one-level architectures. However, humans deal with complexity
using divide and conquer, breaking things into smaller pieces and then trying to put them together somehow. For software
architecture descriptions there are 2 kinds of such Decompositions, Horizontal and Vertical.


Horizontal de, Decompositions are done at the same level of abstraction.


We understand the human body in terms of its digestive, respiratory, immune and so on systems. However, we can also
decompose vertically by going deeper into the abstraction hierarchy, that is we understand the respiratory system in
terms of Lungs, Trachea, Diaphragm. The Lungs in terms of Alveoli and gas transfer for example. We have already seen
how, Acme deals with


Horizontal Decomposition in terms of components like connectors and so on. now let's look at it's support for Vertical
Decomposition.


10 - Representations
--------------------

Acme supports vertical decomposition by allowing any component or connector to be represented by one or more lower level
views.


Note that there are two things going on here. One is, levels of abstraction, that is a view can be at a lower level
representation of something of a higher level. Also, is the fact that you can have multiple views of the same higher
level thing. Recall from our discussion of architectural views, that no single view is likely to provide all the
information we need.


And hence having multiple views, allows us to develop different representations, that can each add something to our
understanding. Each view in your


Acme description is called a representation. Within representation there's a mapping between levels called a rep-map,
short for representation map


11 - Example Representation
---------------------------

Here is a simple example of a representation. It is a decomposition of a single component, which is called here, the
component. The component involves a, two ports: one for dealing with easy requests, and one for dealing with hard
requests. And then, there's the representation, which describes the details.


In a sub-system, called details that has two components.


One fast but dumb component and second a slow but smart component. The binding section then pastes these two levels
together.


Easy requests are mapped to the fast but dumb component port P and hardRequests to the slowButSmartComponent also called
Port P. Hence we now have the same system described at two different levels of abstraction, the lower one allowing us to
go into the more details than the upper one.


12 - Extending ACME
-------------------

What we have seen so far are the basic features of Acme. That is the vocabulary of keywords and descriptions that you
can build from the keywords describing basic architectures. However, Acme has some additional features that allow you to
go beyond this basic vocabulary. In particular, because Acme was designed in support of interchanging architectural
descriptions between tools.


And each tool may have its own vocabulary that goes beyond what's needed for simple interchange. Acme has a mechanism
for embedding within it tool specific terminology. This additional text is not interpreted by Acme other than for syntax
checking. But is passed along to the various tools. And they can do their own work on it. This extension mechanism is
called Acme's property sublanguage.


13 - Properties
---------------

A property in Acme is nothing more than i, than an identifier that can be associated with a value. That is, you're
giving name value pairs that are then become part of the syntax syntactic description of your architecture.


Examples of uses of such name value-pairs include. Visualization properties, that is, if you are not satisfied with what
Acme Studio gives you, but you have other tools available to visualize architectures, you might wish to communicate
information about those additional properties within an Acme description. Temporal constraints. Archi, architectures
describe systems that actually run and may have timing considerations with them, and you may wish to use tools that can
take advantage of this, such as simulator tools. You might like to have more detailed checking, on the data being
communicated via the ports and roles, and so you might have a type checking tool. The particular communications between
the components across the connectors to other components, constitutes a protocol. And you might wish to enforce that
protocol. Do checking on that protocol, and so on. And hence you could use the property language to describe the
protocol.


If there's scheduling constraints you could put those in.


If there's resource consumptions constraints you can put those in, and so on.


14 - Properties Example
-----------------------

Here's an example of extending our previous top level description with some properties. We still have our client and
server components.


We still have our RPC connector. We still have our attachments. However, we've added some property statements within the
descriptions of the components and connector. In particular, the first property is labeled Aesop-style, and it's some
kind of style ID. Second one is Unicon-style. Now, be aware that Aesop and Unicon are other architectural description
languages with their own tools.


By the way, I've indicated here a comment using C++'s slash, slash commenting style. For the second component, the
server component, there are two properties, and these are not intended for particular external architectural style
architectural description language. The first one is labeled idempotence, and it's got a Boolean value indicated as
true. The second one is an integer, including a maximum concurrent clients that this particular component can, is
capable of dealing with. As far as the connector is concerned, there are properties for synchronization. For the maximum
number of roles that that connector can have and for a particular protocol, in this case, using the Wright, as in Frank
Lloyd Wright, architectural description language.


15 - Families
-------------

Another feature of Acme that goes beyond the basic vocabulary of what are called Families. And


Families are what you would use within Acme to describe architectural styles.


That is they're defining new terms that describe sets of architectures. You can encode style rules as properties, that
describe how to use a particular family.


16 - Example Family
-------------------

For example, here is a brief description of a family called the pipe and filter family, which you should now be familiar
with.


There's a type of component, not a component but a type of component, called the filter type. Another type of component
called the pipe type. And we might then use. This, this additional vocabulary in defining a system. And you notice that
in the declaration of the system, there's a type given to it.


In this case, it's the PipeAndFiltersFamily. And we're now going to define specific components that correspond to the
types we've defined in the family description. So filter 1 is a, a type, filter type and likewise is filter 2 and then
connector is of the pipe type.


17 - Open Semantic Framework
----------------------------

The third advanced feature of ACME is what's called its open semantic framework.


ACME has a simple vocabulary, a simple syntax, and also, a very simple semantics, but there obviously could be lots of
information you'd like to encode in an architectural description.


And, encoding all that complexity you would like to also have some way of checking it for whether it's valid.


ACME itself and the ACME tools don't provide that checking, but they do provide a way for you to essentially export your
description in such a way that it can used, be used by external checking tools.


That's what the open semantic framework is.


In particular, the description that you've either drawn, using ACME Studio, or you've typed in, using the editor, can be
used to generate a description in first order logic.


That description can then be used by an external tool, which takes as input the first order logic.


And proves whatever it needs to do, such, such, for example that the particular architecture you've described obey's
certain rules.


There's an example here for the client server situation.


And it's essentially a an English language keyword version of first order logic.


It says that there exists a thing called client, a thing called server, a thing called RPC such that client is a
component, server is a component,


RPC is a connector, and that they're attached in a way we've described.


This, this contains exactly the information we saw in the ACME description.


But now it's in a form that can be dealt with by a fair improver, or automatic reasoning system.


18 - Acme Features Quiz 1
-------------------------

Here's a quiz to see if you have understood the various features that


ACME provides. In column one there's a list of the names of those features, and in column two there's a definition for
them. See if you can match the term with its definition.


19 - Acme Features Quiz 1 Solution
----------------------------------

Well, what's a role? That is, what's number one. A role is an interface for a connector, which is answer B. Open
semantic framework. That's an export format for use by automatic reasoners. A family, well, that's a means for defining
architectural styles. Properties. Properties are name value pairs for exporting information and ACME descriptions
through external tools.


Rep-map. That's a binding mechanism when we're doing vertical decomposition.


Finally, port. Port is a component interface.


20 - Acme Features Quiz 2
-------------------------

As I've tried to indicate, ACME is relatively simple as far as ADL's go.


There are lots of other features that other ADL's have that ACME does not.


So I'd like you to think for a minute, what other features it might be nice for an architectural description language to
have that ACME doesn't, and see if you can list them here.


21 - Acme Features Quiz 2
-------------------------

Well, clearly you'd like to have a description of what those components do orf what those connectors do. ACME doesn't
provide this, but you can well imagine some additional syntax for describing those kinds of behaviors.


Also, ACME doesn't have representation for functional properties. So going back to our original understanding of systems
having function behavior and structure,


ACME tells you a lot about structure, but it doesn't tell you much about function behavior. Also, ACME doesn't directly
provide a way for connecting code with architectural elements, and you can imagine that going in either direction.


That is, you might like to take an architectural description and automatically generate stub code for it. Similarly, if
you've got some existing code, you can imagine a tool that can do some kind of analysis on that code to generate an
architectural description that can then be imported into ACME and you can visualize it using the ACME Studio Graphical
Editor. Also, of course, is the fact that ACME doesn't say anything at all about non-functional requirements other than
what the property sub-language allows you to describe on your own. The essential role of non-functional requirements in
any architectural description means that it would be of value to come up with some way in a standard fashion, trying to
characterize these particular requirements.


22 - ACME Limitations
---------------------

The main goal of acme is to enable architectural descriptions to be expressed in a way that can be used by a variety of
tools. That is, it's an interchange format. Because of its limited goals, it lacks features found in more elaborate
architectural description languages. Nevertheless, it should give you a feel for the importance of architectural
description and the role that architectural description language can play in describing these architectures.


