.. title: P3L6 Connectors 
.. slug: P3L6 Connectors 
.. date: 2016-05-27 23:53:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L6 Connectors
===============


01 - Connectors
---------------

Recall our terminology for describing architecture in terms of components, connectors and configurations. The
components are mainly determined by the system's functionality, with a few invented to handle non, some non-functional
requirements. Now it's time to take a look at connectors.

The main material for this lesson comes from the [UNKNOWN] paper, which I have asked you to read. There is also some
material in the optional text by Taylor [UNKNOWN] on software architecture foundations.

According to Shaw and Garlan, connectors are responsible for mediating the interactions among the components. They
establish the rules that govern component interaction and specify any auxiliary mechanisms required.


02 - Atomic Elements
--------------------

Let's come at this from the bottom up, in terms of the atomic elements out of which connectors are built. The base
element is called, in the meta-paper, ducts, as in air-conditioning ducts. Okay? This, this is the channel, has no
associated behavior, with it.

It could, for example, be some kind of internet connection. Or it could be all on one machine in terms of the
underlying electronics. It could be provided by the program language implementation, for example in a
virtual machine. It could be the operating system through some kind of system call. Okay? Or it could be an
inter machine communication, for example with sockets. Ducts provide the mechanisms for transmitting the data, and
it could also be control information among the components.

Connectors go beyond ducts, by providing the protocol used by the ducts for doing that communication. That is the
sequence of interactions.

In addition to ducts, connectors may include internal mechanisms. For example, some storage,uh, like, like would be used
for buffers. Or computation, computational elements such as might be involved if you, if the, if the connector were
fighting some kind of translation capability.


03 - Pipe and Filter Quiz
-------------------------

To get started, here's a little quiz. For our friend the pipe and filter architectural style. Which is the component and
which is the connector?


04 - Pipe and Filter Quiz
-------------------------

I hope you said that Pipes are the connectors and Filters are the components.


05 - Service Categories
-----------------------

In addition to [UNKNOWN] mehta talks about, meta at all talks about services.


Now these are not, services in the sense of services that the, user sees or even service in the sense of client server.
Okay that words, it's a unit of computational service. These are services that connect or provides the overall
architecture. According to Mehta, it's a service category that represents the broad interaction role the connector
fulfills, and they lay out four different categories of services including Communication.

That is the transmittal of data. Coordination which is the trans, transfer of control. Conversion that's when some kind
of a translation is going on, particularly among data formats. Okay? And

Facilitation that is some kind of mediation or operation optimization activity.

And they use the abbreviations, T,O,X and F respectively on, in their diagrams to abbreviate those particular four
categories of services.


06 - Services Quiz
------------------

For this particular quiz I provided some types of services and asked you to say what categories those fill in.

See if you can provide one of the four letters next to each of the service names to give its major category of service
that it provides.


07 - Services Quiz
------------------

Well, for data buffering, that's really a facilitation.

It makes the system work better, but it's not in itself a major communication of either data or control.

Acknowledgement, guaranteed delivery, multiplexing, transactions, scheduling, synchronization, all about the
collaboration aspects of, that a particular connector could provide.

As far invocation is concerned, there is a collaboration aspect there, but there's also a data transmission aspect as
far as the parameters are concerned.

Dynamic reconfiguration is a, an advanced technique for making a system run better at runtime.

So that's a facilitation operation, as is load balancing.


08 - Variety of Connectors
--------------------------

So we've talked about the atomic elements, the ducks.

We talked about the different surface categories.

Now we'd like to actually look at a variety of different kinds of connectors.


09 - Procedure Call Connectors
------------------------------

Let's drill down a bit into a very simple connector, the procedural call connector provided by all, all your friendly
programming languages.

First of all there's a flow of control, that is, control is with the calling routine and then control shifts to be with
the called routine. So that's a coordination role. There's transmission of data via the parameters, so that's a
communication role. Procedure call is so common, so pervasive a part of programming languages that it's basis for all of
the composite connectors, that is when we make a complex connector out of simpler connectors. For example in the Java
method call we have the caller, the callee, there's exactly one, at any given time there's exactly one caller and one
callee. So we can say the fan in is one and the fan out is one as well.

Sounds simple right, but there's all kinds of variations. For example,. How are the parameters transmitted? Well,
there's call by reference, call by value, call by name. There could be default values, keyword parameters, inline
parameters. If there's a return value, things could be provided by invocation records, by a hash table.

And even the order of valuation is a variant. Are the arguments which might themselves be procedure calls, method calls
evaluated left to right, right to left or whatever. Some languages provide for multiple entry points that is when you
call a method you may enter that method in different places.

Is the invocation explicit as it would be in a method call, or is it implicit as it might be in an object oriented line
in which there's delegation, and the ultimate callee is known specifically by the caller. Usually we think of procedure
calls as synchronous but there are also situations where procedure calls can be asynchronous. We mentioned the
possibility of different fan ins and fan outs, okay? And then there's the issue, the variation that is allowed as far as
accessibility is concerned. We know, for example, programming languages allow for only private access that is within the
same class. Or protected access, to the method from the particular class or it's parents, or children classes, and then
public acc, access, where any other, the caller can be anyplace

10 - Event Connectors
---------------------

The second kind of connector we'd like to look at are event connectors these are, these are also very common. In fact
[INAUDIBLE] book on the resource page.

They devote a very nice section to describing all the different variations that might exist with event connectors.

First of all event connectors are responsible for a flow of controls so that's a coordination role. They may also pass
parameters. Typically this might involve time stamps, or actual data, so that's a communication wall.

Event connectors, once an event is detected, generate messages, method calls.

After detecting the event or some combination of events that it's, it's prepared to detect. Event connectors are
particularly relevant for distributed, asynchronous applications in which we need to know when certain things happen.
The set of event connectors that exist is dynamic.

That is, the application itself can turn on or turn off the ability to detect certain events. Some of the variations
that might exist among implementations of event connectors include cardinality.

That is how many different components can produce the event? How many different observers of the event might exist? And
might there be patterns of events?

In which, we like to be able to detect currents of the pattern.

How were the events actually communicated? Is it via best effort, exactly once, at most once, at least once? Do we have
a priority among a set of events?

Do we always handle the outgoing ones before the incoming ones?

Are there different priorities embedded with the event that are handled in a certain fashion? Synchronous, asynchronous,
or based upon certain time out?

How is notification handled? Is it polled? That is, does the potential receivers have to periodically look to see
whether the event occurred? Is there a published, published subscribe interface in which a particular component
registers it's interests in events. And then, gets told when events happen? Is there a central updating mechanism that,
a registry that receives all of the events and distributes them to the known, known parties. Or is, are there queues
sitting there that everybody's responsible for looking at. Causality refers to the circumstances determining the actual
issuing of the events. Are there, absolute, absolute event occurrences?

Or, could could the events be relative to other situations that is conditional type events. And what's is the ultimate,
generator of the event.

Might it come from hardware such as pa, page faults, interrupts, or traps. Or are they software signals or triggers or
even, inputs from the, from the GUI.

11 - Data Access Connectors
---------------------------

The 3rd main category of connector are the data access connectors. And this is as the name indicates, this, is where the
connector is responsible for dealing with access to some kind of data repository. Hence, there is a communication
service provided.

Moreover, the, the access connector may provide some kind of translation.

Surfaces could be character set translation, or something at a higher level.

Hence, there's a conversion service being provided. Some of the variations and data access connectors include locality
that is. Are the connectors specific to a particular thread, or to a particular processor are they global?

What kinds of access are allowed? Is it simply query retrieval, or might there be changes allowed? What's the
availability of the data access?

Is it transient? Is it persistent that is could it be long lasting as with the earlier connectors accessibility in terms
of private, protected or public. With respect to, to life cycle who is responsible for doing the construction or
building and who's responsible for cleaning up when things are. Over think your instructors and destruction, and as far
as, cardinality is concerned who, who's responsible for defining the messages and who's responsible for receiving them
or using them.


12 - Linkage Connectors
-----------------------

1 The fourth category of connector is a little bit different than the other.

2 This is linkage connectors.

3 And they're responsible for describing the structure of the system.

4 That term linkage here, you can think in terms of link editors,

5 if you've ever heard of those ways of organizing or constructing or

6 putting together the pieces of a system.

7 Linkage connectors are responsible for

8 establishing the ducts and enforcing the interaction semantics.

9 Hence, they provide a facilitation service.

10 Because they're responsible for putting the system together but not for

11 actually running the system, they may disappear after setup is complete.

12 The unit of linkage might be a module, might be a file might be an object.

13 And related to this are tools like configuration management tools and

14 the make command for actually building a system.

15 There are semantic issues with respect to the granularity of the pieces and

16 the semantics that is the, what are the protocols among the pieces.

17 Among the variants that are involved with linkage connectors are whether they're

18 implicit or explicit.

19 For example, implicit might be something like make where you

20 merely state a overall target that you're trying to build and

21 the other building steps are done, done for you.

22 The granularity that is what, what unit is being put together.

23 Could it be variables, procedures, functions, and, and so on?

24 And then of course, the semantics, the cardinality in terms of defines and

25 uses provides and

26 requires, and a key one is binding, that is when does all this happen?

27 It might be at compile time, it might be at run time, or

28 might even be before compile time if, well,

29 part of your construction process involves things like templating or generics.


13 - Stream Connectors
----------------------

Streams are another popular form of connector. They're primarily concerned with data transfer, that is communication
services. Common examples include pipes


TCP sockets and proprietary client-server type protocols. Some of the possible variations available with stream
connectors include delivery guarantees.


Whether the stream itself is bounded, that is, it only has a certain capacity or whether it's unbounded and whether it's
capable of buffering the information.


What its units of transmission are, that is, is it bytes or is it something more higher order, more structured? Is it
stateful or stateless? Is it named or unnamed? Is it available only locally or is it, is it more remote? Synchronous or
asynchronous or timed? Law or structured? And what's the cardinality? That is, is it definitely a one to one type
connection or might there be multiple receivers? Or might it even be end to end where there are multiple riders and
multiple receivers?


14 - Arbitrator Connectors
--------------------------

A powerful category of connector are arbitrators.

These are primarily responsible for facilitation services, but because they can redirect control there's also a
coordination service they provide. You might be able to use them to negotiate service levels.

That is how much resources are being devoted to a particular problem.

Hence they support reliability and atomicity, scheduling and load balancing, trapping of faults and even
synchronization.

Some of the variations for arbitrator connectors include how they handle faults.

Typically with a simple arbitrator scheme, there's a single decision made but more complex systems might involve a
voting scheme. That is if there are three arbitrators around, they would have to vote on the course of action and the
majority would rule. How concurrency is dealt with. The mechanism is it semi fours, a rendezvous, monitors, locks
there's lots of approaches to this.

And whether it's a light weight approach or a heavy weight approach.

Variations involved with transactions such as whether they're simple or they're nested. Whether the arbitrator is there
if you need it or is required.

And whether the arbitrator supports reads, writes, or both. And then a major category of, of capabilities and variation
of arbitrators involves security. Authentication, authorization, screening, durability that is how long the particular
decision last. Is it a single session, or is it a multi session? And then the scheduling of the arbitrator activities.


15 - Adaptor Connectors
-----------------------

Another category of connector is called the adaptor connectors. These are responsible for putting together components that were not designed to be put together. This often means there's some kind of translation going on.

It might be converting protocols and policies and hence there's a conversion or transformation activity provided.

Some of the variations include invocation conversion, that is is there a dress match, mapping? Is there marshalling,
virtual memory translation, virtual function tables? Are there conversion as far as wrappers or packagers? Is there
protocol conversion or even is the presentation conversion, that is is the output. The actual form of the output
determined by some kind of, computation engine such as XSLT.


16 - Distributor Connectors
---------------------------

1 The final category of connectors to

2 look at it are called Distributor Connectors.

3 They're role is also primarily facilitation.

4 They identify the interaction pads and they rout things among them.

5 In a sense, they are assisting other connectors.

6 A primary example here is DNS, Domain Name Services.

7 Whereby various components on the internet can talk to

8 each other using names rather than strictly by addresses.

9 Some of the variations that are possible with

10 distributor connectors include naming.

11 That is are they structured based.

12 Can they be hierarchical or flat?

13 Or are they attribute based?

14 What's the delivery policy?

15 Is it best effort, exactly once and so on?

16 And is the mechanism unicast?

17 That is point to point or multicast or broadcast, and then routing, okay?

18 Is there a bounded list?

19 Or is it more ad hoc?

20 And is the path static, cached, or dynamic?


17 - Summary of Connector Types
-------------------------------

So there's a variety of different kinds of connector types, and these, these different types provide different
categories of services.

Many of them are familiar, but some of them may be a little bit, new to you.

The point as with, earlier lessons is to be aware of what's out there in case you need it in designing your systems.


18 - Connector Type Quiz
------------------------

1 A quiz for you to try with respect to these different types of connectors.

2 I've listed different mechanisms, and

3 I ask you to determine which kind of connector type each one of them belongs to.

4 So remote procedure calls,

5 schedulers, buffers, shared library configuration, or SQL.


19 - Connector Type Quiz
------------------------

1 Well the simple one was remote procedure calls or examples of procedure calls.

2 Schedulers, are really arbitrators, right?

3 They're determining what's going to happen and when.

4 Buffers are used with stream connectors.

5 Shared library configurations is a linkage connector.

6 And SQL is a data access connector.


20 - Composite Connector Examples
---------------------------------

1 So far the connectors we have been talking about have been simple connectors.

2 It's also possible to put connectors together; that is, to compose them,

3 make it more complex connectors.

4 One example I'd like to give is a science data server.

5 Whether you're aware of it or

6 not, there's lots of data being generated out there.

7 Think of all the land sat photographs being taken.

8 Using different frequencies of light they can record all kinds of

9 information that's stored away on data servers.

10 Then there are clients for these servers.

11 The clients may be synchronous or asynchronous.

12 That is, they may have specific requests or

13 they might want to get a stream of data themselves.

14 Okay, and we need to be able to build a composite connector to provide this

15 overall capability.

16 It may involve event connectors, data acc, certainly will involve data

17 access connectors might be streaming of data, and it might be distribution.

18 There are different policies that we might want to enforce for delivery.

19 We might, we almost certainly will have multiple producers and consumers.

20 There's going to be almost certainly some data transformation going on and

21 the access may be public or it may be, may be private, okay?

22 It may be transient, or

23 it may be persistent, persistent depending upon the policy of the data server.

24 It might be packaged into streams or it might be packetized, okay?

25 And there might be a naming registry involved so

26 that they information can be accessed via a specific query.

27 Another example of a composite connector are various FTP applications,

28 such as Globus, bbFTP, and GridFTP.

29 These combine procedure call, data access, steam, and

30 distributor simple connectors.

31 Therefore moving and distributing large amounts of grid data.

32 Could be hierarchically or flatly named.

33 Typically synchronous.

34 Using web protocols such as SOAP might involve time-outs,

35 authentication would prevent unwanted access to the data.

36 There's parameter passing.

37 The data might be transient or

38 it might be persistent might be public or it might be private.

39 And it might be at the level of byte stream or

40 the underlying bytes might be raw or structured.

41 Probably one exactly-once deliver, a bounded buffering, and

42 unicast, that is, point to point transmission.

43 The third example of a composite connector is client-server based distributed

44 distribution connectors that involve things like REST architectural style,

45 HTTP protocol.

46 Remote messaging vocation.

47 CORBA, FTP, SOAP, this particular kind of connector,

48 kind of composite connector might use procedure call connectors, data access,

49 stream and distributor connectors.

50 Involve revoke procedure call, would name parameters, persistent and

51 transient data, and naming registry, and typically unicast type connections.

52 The final example of composite connector is peer to

53 peer based data distribution connector such as BitTorrent.

54 Here there is a combination of arbitrator, data access, stream, and

55 distributor connectors.

56 Typically peer-to-peer is, major facility is controlling the flow of, of things.

57 And that is, control flow redirection.

58 If one of the peers is not available,

59 you go to another peer to provide the information.

60 There may be negotiation of protocols, scheduling and timing.

61 There may be voting involved,

62 depending upon circumstances might use either rendezvous or transactions.

63 The data may be transient or persistent.

64 typically, streams are what's what, what's used.

65 They may be buffering involved.

66 And for these types of applications, typically it's at least one semantics.

67 You don't want to deliver more than once


21 - Connector Design
---------------------

I'd like to take a moment and talk about the design of connectors.

As with components there is a design step required, particularly if you're building your own connector. Starting from
the overall architecture, of course you determine your components and the required interactions among them. Then for
each interaction, determine what required services that interaction needs.

Once you've done that you can select a con, connector type that provides that service. Each of the connector types has
a variant of dimensions, variation dimensions, that you can choose which of those variants you would like to have.

And from that, define your connector. And then you need to validate. And we'll have one in a minute we'll, we'll
describe some of the rules you can use for checking whether or not the, the choices you made will work out.

And in doing this you may actually have to define your own connector.

You may not find one in the catalog or in available libraries that you can use.


22 - Validation Rules
---------------------

One category of validation rules are requirement requirements placed by the value on one dimension on the values of
another dimension. For example, if you've got event connectors that require delivery notification, then you also need
to be concerned with the cardinality rules, synchronization rules, and mode rules. Might be situations where it's not a
strict rule, but it's some kind of caution. Certain combinations may be unstable or unreliable.


That is they're dynamic, the dynamics of that particular situation may not work in all circumstances having to do with
concurrency and locality. There may be restrictions. 'Kay, certain combinations may be invalid, for example, passing by
name and transient can't be used together. And there might be prohibitions. Total incompatibility of dimensions, such
as streams and atomicity


23 - Linux Case Study
---------------------

1 The meta, paper concludes by having a case study using

2 the Linux operating system.

3 Case study was concerned with higher-order connectors.

4 In particular, a operating system like Linux provides several major

5 elements in support of all the applications they're going to run on the system.

6 One key component is the file system.

7 Another is shared memory.

8 And the third is process, support, support for processes.

9 As far as the files are concerned, the underlying hardware doesn't have files.

10 Right? The.

11 It has bytes.

12 There may be a mechanism by, for, for blocking those bytes into groups.

13 But the operating system self provides some kind of facade,

14 that makes it look like there are files there.

15 And in so doing, it ne, needs to deal with contention.

16 If there are multiple, accesses to the file, are you allowing them

17 to take place concurrently or is there some kind of synchronization.

18 required.

19 And it's the operating system's job to provide these arbitration, adaptation,

20 and coordination connectors to get a composite file facade connector.

21 Shared memory, is a data-access type connector but there are issues there,

22 synchronization as well.

23 And finally, in terms of process scheduling,

24 okay, processes are all about controlled access to resources so

25 an arbitrator type connector is required there.

24 - Summary
------------

It's easy to think that after you have determined the components of a system that your job is done. Just as vital is
determining how those components will correctly interact. Treating connectors as first-class part of the design process
can further that end.
