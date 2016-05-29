.. title: P3L9 Middleware 
.. slug: P3L9 Middleware 
.. date: 2016-05-27 23:56:20 UTC-08:00
.. tags: notes, mathjax
.. category: 
.. link: 
.. description: 
.. type: text

P3L9 Middleware
===============


01 - Architecture of Distributed Systems
----------------------------------------

So far, in this course, we have considered software architectures.


Today, I would like to get into one particular kind of software architecture, the architecture for distributed systems.
And all this means is there's multiple computers involved in providing whatever application technology system it's
supposed to. Moreover, we will consider heterogeneous distributed systems.


Systems in which the different computers are different kinds and provide different capabilities. An example of this is a
typical client server system for example, insurance agents go out into the field, they come to your house, they talk to
you about various insurance options, and they have their laptops. The laptops are connected to some server machine that,
understands the different forms you have to fill out, and the and the rates involved in those in those particular
contracts. And ultimately if you sign up for a particular policy then the business logic connects to a data base that
stores the information about you and your particular policy arrangements. In that particular situation, there was a a
database server machine, there was a web server that was responsible for initiating and computing business logic.


And there were various web browsers running on laptop machines, one for each agent. We'd like to look a little bit more
in how these particular kinds of systems are architected.


02 - Middleware
---------------

Because these types of applications are so common, a group of technologies has evolved to support them. These
technologies are called Middleware. That is, they are technologies between the user or client and the ultimate server.


They essentially are responsible for dealing with satisfying the non-functional constraints of the overall distributed
system. They're similar, in concept, to the architectural connectors that we've talked about. It will be interesting to
contrast those connectors with the kind of middlewares described.


We'll be using in particular the material taken from the Emmerich paper, which I've asked you to read.


03 - Context
------------

Why is this an important application class to consider? Well, obviously the Internet has just opened up so many
different opportunities for applications. That means, not only more applications but more customers, heavier load,
increasing demand on the resources. Hence, performance and resource consumptions considerations, nonfunctional
constraints.


Also, the hardware resources themselves have become more specialized.


Think about ATM machines or card readers at gas stations, or mobile phones, or square card readers.


Just all kinds of devices that have their own peculiarities.


Also we've seen increasingly powerful applications, okay, that involve integrations of existing components, and
sometimes even negotiation among them.


04 - Needs
----------

Well, if we're to deal with this challenge of increasing growth in distributed applications, we should consider what
kinds of technologies we can use to support them. One category are technologies that provide abstractions, okay?


In particular, the abstractions take the form of interfaces realized as application programmer interfaces, or APIs, such
as Ajax or


Enterprise JavaBeans. Standards, think HTTP or new kinds of architectures such as REST architectures or service oriented
architectures. similarly, the development of new notations.


Over the last, maybe ten years we've seen the increasing penetration of


XML into applications. And similarly, there's been the development of tools and that support the development of these
kinds of systems such as WebSphere or


Hibernate. You may have heard of those. In the design space, there's Oracle's Fusion and there are even code generators
for, for transforming or generating the XML such as XSLT.


05 - Exercise Application
-------------------------

Going through this lesson, there will be some opportunities for quizzes. And what I'd like to do is have you consider a
simple application that I'm, then, going to be asking you questions about. The application involves users and a web
browser, visiting some kind of website and being asked to vote on certain questions. The votes are then submitted and
the system responds back after registering the vote with some count of how other people voted on the same, same
question. So the application is web-based, users are polled on a variety of questions, their choices are recorded, and
there's a display of how others voted. And, in this particular situation the actual users remain anonymous as far as the
database is concerned.


06 - Characteristic Issues
--------------------------

So before, we get into the describing the technologies involved and addressing these problems. Let's look at little
deeper into the issues, some of the issues that might involved.


We want to look at network communication issues, coordination among the pieces of the application reliability concerns,
scalability concerns and then just the implications of the heterogeneity of the various parts of the system.


07 - Network Communication
--------------------------

Let's begin with network communications.


Obviously, if you have a distributed application the pieces of the application have to be connected together over some
kind of network.


Some of the issues that arise in dealing with applications that are split across a network are how are errors handled.


And there a variety of different kinds of errors that might arise.


There are synchronous errors.


That is, when a particular request is made, and part of a system awaits a response.


Or asynchronous errors.


That is spontaneous issuing of some kind of notification that the rest of the system has to respond to.


Primary concern here is reliable delivery of these messages, particularly the error messages.


If the network itself is unreliable, various strategies such as delivering more than once can be employed, but then
again, you don't want to have more than one actual copy of a message received and, and acted upon.


And communicating across the network, another issue relates to how the data is represented.


It may well be the case, because we're in a heterogeneous situation, that the different machine and the different
machines represent data in different ways.


And then third is the whole question of transaction.


If there's a database involved, it may well be the case that of the multiple users which might be using the application,
one user is updating the database at the same time another user is reading the database.


And there's the potential for the receipt of information that is not up to date with respect to the, the database.


08 - Data Transportability
--------------------------

To drill down for a minute into this question of data transport ability.


This is sometimes called serialization in Java, or marshaling, or even pickling.


Some of the differences that might arrive have to do with bit order. Yes, some machines order the bits from high order
to low order in different orders.


Byte orders within a word. Different character sets that are used. Alignment, that is, whether, particular pieces of
data are aligned on word boundaries or byte boundaries. Okay? And then the whole question of word length. Now we have,
of course, 64-bit, words, but other machines are only 32-bits. And, of course there are, uses, of, data storage in which
we wish to use less than a full word. Even after these, differences are resolved there's still the question of how the
various pieces of some complex data are, are, are organized. Okay? Must they be kept in a certain order? Can they be,
can they be shuffled around in order to compact them? These days, many, approaches to data representation include self-
definition. That is, not only are you communicating with data, but you're communicating at a description of the data.
That, can then be decoded at the other end. Fortunately, various, standards have, arisen to address these kinds of
questions. Internet standard x680 is one, and then on the commercial side Google has developed the idea of protocol
buffers.


Which are descriptions of data.


Which then can be incorporated into your applications for communication among the pieces and interpretation at either
end by an API.


09 - Voting Application Quiz 1
------------------------------

So going back to our sample application for a moment, here's the first quiz.


Think of how I describe this application, and decide what date it is that needs to be transmitted from the web browser
to the server in that direction.


10 - Voting Application Quiz 1 Solution
---------------------------------------

Of course I expect that you recognize the need to transmit the votes but did you also realize that we have to transmit
the question numbers.


After all if we're storing these things in the data base we have to index into the database to find the right question
information in order to update the statistics and eventually return the reply


11 - Transactions ACID
----------------------

In the situations where a database is involved and we have to be concerned about transactions, that is making sure that
the data that we store and retrieve is consistent with respect to the overall database we have to deal with transaction
processing, and in particular with what are called the ACID properties. The primary concern is reliable database access,
particularly when there are multiple readers and writers. That is parts of the application reading from the database and
other parts writing into the database, particularly on in addressing a particular, a specific record. Imagine that you
were in a situation, maybe you were doing airline reservations or something like that, and you need to understand the
information in the database, but you may want to update it if you're making that reservation. Okay? So you have to read
it, examine it, change it, and then write it back.


What happens if another application changes the record after you've read it, but before your change version has been
written back. So we'd like to have database transactions that satisfy the ACID properties, and ACID is an acronym.


The A stands for Atomic. That means that your transaction, these four steps, reading, examining, changing, and written,
are all treated by the system as if they were one step with no intermittent activities going on. The C stands for
consistency preserving, in the sense of database integrity. Okay. That is if the database satisfied all its integrity
constraints before your transaction, it will also satisfy them after your transaction. Third, the letter I stands for
isolated. Okay, that, what that means is that other transactions can't see into any intermediate states in the
processing of your particular transaction.


And finally D stands for durable, and that mean that once your transaction commits then it's persisted.


That means it, it is a permanent record that the system is aware of.


12 - Voting Application Quiz 2
------------------------------

So second quiz question related to the sample application is whether or not you see a need in this application for
transactions.


13 - Voting Application Quiz 2 Solution
---------------------------------------

In this particular application even though the user is going to see some votes.


If the votes were off by one or two it probably wouldn't matter to the application. Providing transactions in a database
since can have some extra costs associated with it. And the question is do you want to pay that cost if getting the
exact right numbers is not all that important. So I wouldn't answer this particular question's that transactions are not
necessarily required for.


14 - Coordination
-----------------

The second category of issues is coordination.


Remember that we have heterogeneous distributed application, multiple things going on at the same time.


And these multiple things have to synchronize across certain actions.


Okay, and how is that going to be provided?


The two main categories of a synchronization are synchronous applications, synch, synchronous communications and
asynchronous communications.


Synchronous means that when one piece of the application initiates that particular message or interaction that it waits
until it gets a reply back, a response back, before continuing.


Often synchronous types of interactions are clocked.


That means that there's some heartbeat or some other measure of when it can do certain things.


On the other hand asynchronous communication means the client can continue to execute after it sent the message and it's
notified when the response comes back and it can take appropriate steps at that point.


Obviously asynchronous is more general, but writing code for dealing with a, asynchronous coordination is a little
trickier, it makes it a little harder to understand.


So once again there's a trade off.


Another question with respect to coordination is, who's in charge here?


Okay, is it the client or the server?


You've no doubt seen situations where the server is capable of pushing things out to the client such as web pages which
you want to update with current events or it could be that the client requests information as it pulls from the server.


Deciding how you're going to deal with that is a key design question in any distributed application.


It's always the case with such applications that robustness is important.


What this means is that the system can deal with situations where one or more of its components goes down.


Think that you send out a message and you don't get any response back.


And the reason that you don't get any response back is that the the piece of the application you were dealing with goes
down.


How does your part of the application deal with that?


Think for example, if you were user facing you don't want to just wait there and leave the user in limbo.


You want to provide perhaps some time map on a message acknowledgment and be able to let the user know what went on.


Similar to robustness is availability.


How does the system appear to the user as far as being available?


Is it 24/7, type application?


Does it have set maintenance times?


How does it deal with load situations?


That is, does it get so slow that the user gets frustrated?


All those kinds of questions.


Persistence we've already mentioned.


In general this means how a server stayed maintained.


One obvious approach is with a data base.


It might be a file system, but nevertheless the choice has to be made.


And if you've got multiple clients talking to the system, how is that concurrency handled?


Okay, how does the server part of the application deal with all these multiple users?


Related to that is the transaction and integrity constraints which we've talked about on the previous issue.


15 - Voting Application Quiz 3
------------------------------

Going back to our sample application situation.


We have this voting application. Should it be the client or the server that initiates interactions? Write your answer
into the text box.


16 - Voting Application Quiz 3 Solution
---------------------------------------

Well, there's two choices for you. Either the client could do it or the server could do it. In the client situation, the
client sends the votes at the point which the user makes them. If it were the server doing it, the server would have to
periodically poll the clients, to know if there were any votes that it needed to get. Seems to me that in this
situation, because the user interactions are intermittent, that having the client initiate the interaction probably
makes more sense.


17 - Reliability
----------------

Their major issue is reliability, which we've alluded to already.


We have a complex system that has multiple pieces to it and that means a piece might go down, or might, be overloaded
at, at some particular point and how does the rest of the system, respond to that.


Overall we can call that a reliability question.


That is what percentage of the time is the overall application providing the, the services that it should be providing.
Typically you learn about a reliability problem when some message that is sent is not delivered. Or at least you don't
get an acknowledgment back from it.


When strategy is to try sending the message again. The danger there of course is that the, recipient receives two copies
of the message, and does whatever action is doing twice which also may be a problem.


This is an example of a classic reliability performance tradeoff.


That is. Whenever you use replication that's going to take more time and more resources, as well as, as, as compromising
the integrity of the system.


You can do it faster but it may not be as reliable. Various policies for dealing with reliabilities use have arisen such
as the, the client making its best effort. The client's saying it will do at most once, as far as message sending, at
least once, exactly once and so on.


18 - Voting Application Quiz 4
------------------------------

How many different machines might be involved in processing the vote of a single user?


19 - Voting Application Quiz 4 Solution
---------------------------------------

Well, there is three different things going on. There is the web browser that's spacing the user and processing the
immediate user events such as clicking on the buttons. There is the web server that serves the page but also receives
back the information from the user and then there is a database server. So at least three different processes are going
on. Now these might be on three different physical machines. It can even be on a single machine.


20 - Voting Application Quiz 5
------------------------------

Second part of the quiz, whenever you're involved with different machines and having to send messages back and forth.
The question of protocols arises.


That is, how is the message formatted, packaged up, in order to be understood at the receiving end? So, the question
here is, what protocols might be used in support of the sample applications?


21 - Voting Application Quiz 5 Solution
---------------------------------------

Well, one obvious answer is HTTP. This is a web based application, and most, web communication uses the HTTP protocol.
These days, a second protocol often is part of these kinds of interactions, and that's AJAX, in which the web browser,
and the web server cooperate.


In a more timely fashion, then going in a kind of round trip HTTP page rewrite situation. Third, is the fact that,
ultimately we're updating a database.


Typical databases are relational databases and the standard language for dealing with relational databases is SQL. So
SQL can be thought of as a protocol.


In typical applications like that, the SQL is embedded inside of PHP.


You can think of PHP, as a language but any language is in itself a protocol, that is, has certain rules for how it's
programs are expressed.


22 - Scalablity
---------------

What major issue is Scalability. If you've got an interesting application, that's distributed across the internet, it
might grow. That is, it might, have more users over time. Or it might have, a greater load, due to the individual users.
In either case, you want to be able to grow the application. And the question then is, how easy is it to grow? This is
sometimes called scaling. That is, how easy is it to scale your application? Scaling typically takes the form of adding
new hardware. And the question then becomes, to what extent will adding new machines change your system architecture, or
its components? Ideally, we'd like to grow transparently. What transparency means is, whether or not a particular aspect
of a systems architecture is visible externally, that is, to the, the other machines. If it's invisible, of course, you
can scale as much as you want, and the rest of the system would not be concerned.


23 - Kinds of Transparancy
--------------------------

So, the different kinds of Transparency, which you might consider versus Access transparency. That is, it's a particular
computational or data resource which the application requires available locally or remotely and in particular does the
application need to know whether it's local or remote. If it's Access transparent the application doesn't need to know.


Extending this is the idea of Location transparency. Is it necessary to know the physical location of a resource. Third,
is Migration transparency, that is, can we move a resource from one. Physical machine to another, in such a way that the
rest of the system doesn't have to know that it's moved. This can be tricky of course, if you're in the middle of using
a resource when it moves, there's the possibility that, your interaction is going to be inconsistent, or even break. And
finally, Replication transparency. One way for dealing with reliability issues is Replication. At one extreme would be
Database Replication, where all of your data is in more than one place, and if your, one of your databases go down, at
least you have the other one there.


Okay, and then as far as Transparency is concerned, is your application aware that there are multiple database servers
in that situation.


24 - Heterogeneity
------------------

The fifth major category of issues is heterogeneity.


We started with the assumption, we have a heterogeneous distributed system, but the dimensions of heterogeneity are
many. Hardware, this not just what kind of computers, but also are there embedded devices involved.


Are there cellphones involved in this? Are there card readers involved?


Are there other, other devices? Different operating systems.


Different programming languages. All of the different standards protocols and


API's that might be involved in building this application. The pieces of the application that provide access such as a
web browsers or these devices.


All of these can change. More over even if they don't change.


Even if they're uniformly applied. That is every part of the system uses


Linux or every part of the system uses Ruby. Are they using the same version?


For example, imagine the issue of testing a web based application across browser versions. You have three or four main
families of browsers, each coming in three or four different versions.


Also the problem of testing becomes that much more challenging.


25 - Implications of Heterogeneity
----------------------------------

How are you going to deal with a question of heterogeneity? Some approaches include standard APIs. Those standards come
from organizations like W3C, that is the World Wide Web Consortium, OMG the Object Management Group which is the
promogater of GML, ANSI American National Standards Institute, international standards organization. All of these
standard API's and protocols must at least address the issue of backward and forward compatibility.


Backwards compatibility means if you've got a new version, does that version support or break older versions. Tougher is
forward compatibility.


In your current version, are you promising that regardless of how the particular standard may change in the future, that
the current version will be supported.


Second is the question of normative architectures.


Here OMG is taking a stab with what they call Model-Driven Architecture, MDA, in which the parts of a systems
architecture which are machine independent are separated from the machine dependent parts. And then there is a co-
generation process that enables the generation of the dependent parts from some kinds of machine descriptions. The major
vendors or players in the game also offer there own ways of dealing with heterogeneity. For example, Sony has its what
originally was called J2E and is now called JEE.


Microsoft has .Net, IBM has Websphere and so on.


26 - LAMP Quiz
--------------

1


For our sample application, there's a call it a normative architecture or


2 a mild form of normative architecture called LAMP.


3


Look up this acronym, and for each of its four letters, each of its four parts,


4 determine the role that, that part might play in the application architecture.


27 - LAMP Quiz Solution
-----------------------

1


The L stands for Linux, and that's the operating system on which


2 probably the server side of the application is going to run.


3


Linux is a well controlled and uniformed operating system family,


4 and you can take advantage of that as a way of


5 controlling the variation that's going on in the system.


6


The A stands for Apache, and what's meant here is the Apache web server.


7


The Apache web server is the most popular web server, and using it and


8 its configuration file enables you to evolve in a controlled fashion.


9


The M stands for MySQL, which is now part of Oracle.


10


It's the database engine, it supports a standard relational type of


11 database access using the SQL language, so there's another standard.


12


And the P stands for PHP, which is a means of


13 essentially embedding the database interactions into your HTML program so


14 that on the server side, that can then become SQL transactions to the database.


28 - Other Non Functional Issues
--------------------------------

Some other non-functional issues which we've maybe alluded to but that also play a role in dealing with these
distributed heterogeneous application.


Include fault tolerance. How does the system deal with, let's say, exceptions that arise. Flexibility, how to support,
change in any of the components.


In general, you want to be able to support reuse. What that means is, can you take some of the pieces, the components,
and use them in related applications? Thereby, improving your productivity. In general, these applications can get quite
complexed and they are often mission critical.


So you need to be able to manage that complexity. And fifth is quality service.


Quality of service or QOS is an, is a concept who's goal is to be able to specifically measure the non-functional
constraints. And the extent to which the system deals with those. With performance, that's easy.


You can, you can measure the things like response time or throughput. But some of the other non-functional
considerations are harder to get a number around.


29 - Challenges
---------------

Well that's the set of challenges. Variety of different problems that successful distributed systems have to deal with.
And the overall question is, what solution approaches have been developed for dealing with it. In particular we're going
to look at middleware. Middleware between the client and the server that supports, in particular, addressing some of
these non-functional problems.


30 - Kinds of Middleware
------------------------

The first thing we're going to do is carve the problem up into four kinds of middleware. And the four kinds are going to
be based upon the interaction mechanisms between the pieces. In particular we'll look at transactional, middleware
because it deals with distributive transactions. We'll look at message oriented middleware in which the interactions are
messages, message passing. We'll look at procedural mid, middleware, which has to do with remote procedure calls. And
finally we'll look at object or component middleware in which we're making requests on remote objects.


31 - Transactional Middleware
-----------------------------

First off, transactional middleware, recall that we have to deal with reliability and those acid requirements. Various
approaches including two-phased commit are policies which the application can obey in order to get higher reliability
and guaranteed consistency.


We'd like to develop a transactional middleware solutions in such a way that we have location transparency. That is, the
pieces the server doesn't know where the clients are distributed. And moreover, the clients don't know where the server
is other than possibly with some kind of IP address for the web server. Some of the products over the years that have
been developed for dealing with transactional middleware include CICS on IBM mainframes.


Tuxedo, which is a UNIX-based approach, and Encina, from Hewlett Packard.


32 - Message Oriented Middleware
--------------------------------

Second kind of middleware is MOM, okay, Message-Oriented Middleware. Here we are thinking about asynchronous message
passing. Each of the pieces acts more or less autonomally, autonomously sending out messages when it needs to.


These messages are queued up, so, we have some degree of fault tolerance because if a piece goes down the informa, the
messages it has to deal with are still in the queue. And when it comes back up it can peel them off the queue.


Message-Oriented Middleware is not particularly transparent because the clients must implement the coordination embedded
in these messages.


So messages not only transmit data, they also transmit information about about state. Some of the products that are
involved here include IBM's MQSeries,


SUN's Java Message Queues and and some of Amazon Queuing Solutions.


33 - Procedural Middleware
--------------------------

You've possibly in the past used remote procedure calls.


This is an example of procedural middleware. The idea here is that, your piece of a system needs some computation that's
available on another piece, and you'd like to make it look, in your code, as if you're just making some kind of function
call. When really, the function that's doing the comp, computing is on another machine.


Remote procedure calling, technology hasn't been available since the 1980s.


It is typically synchronous, okay, that is you block until you get the procedure call comes back. However, it's
operating system dependent. And there have been technologies developed by SUN and, NDR, for dealing with the data
representations and, and the coordination of the call and return.


34 - Object and Component Middleware
------------------------------------

The most ambitious and most recent type of Middleware is sometimes called


Object, or Component, Middleware. This is an extension of remote procedure calls to deal with objects. Thinking instead
of making a function call, you're sending a message to an object which might happen to be on a remote machine.


Some issues arise when we do this. One is what's called object identity.


If you're on a single machine, the identity of an object is really its memory address. If you've got multiple machines,
those memory addresses you can no longer guarantee to be unique. So you need some kind of a global mechanism for
numbering or naming the various objects so that you can send message to the appropriate object. And then inheritance.
Could it be that a child instance is on one machine and a parent instance is on another machine and there’s delegation
of message passing from child to parent. Features that object and, and component middleware might provide include both
synchronous and asynchronous message passing. Marshaling of data. Exception handling across machines. Some of the the
product approaches for dealing with this include


CORBA which was a mainframe approach developed in the 1990s. COM from Microsoft.


And then SUN, SUN's now Oracle's Java remote messaging invocation RMI


35 - Middleware Quiz
--------------------

For our sample application, here's another quiz question for you.


Which of these four types of middleware do you think would be the most appropriate one to deal with a voting
application?


36 - Middleware Quiz Solution
-----------------------------

Well, there's a database involved, so it's likely transactional middleware is the one that we need in this case.


37 - Software Engineering Issues
--------------------------------

So far, the issues that we've been talking about have been mostly system issues, things like reliability. I'd also like
to spend a moment talking about software engineering side of things, that is building these systems.


First category of issue has to do with requirements. Because non-functional requirements dominate this sort of
situation, the requirements analyst has to elicit this information from the customers. And of course, it's axiomatic
that the customers aren't always sure of what the requirements should be, particularly with respect to quality of
service. That is, some kind of measured understanding of how the system is going to deal with these non-functional
situations. Second concern of software architecture. Recall,


I've been stressing throughout the course that the key element of coming up with a good solution architecturally is how
it's going to deal with a non functional requirements, a corollary to that is in coming up with the architecture and
choosing the connectors how do those connectors relate to a middleware solutions that we have. Can, for example, define
an appropriate middleware technology for dealing with one of the connections we've selected to be included in the
architecture. Third software engineering issue has to do with some design questions. Whenever you have a distributed
application you have a network.


Whenever you have a network you have latency. That is delays in message passing.


How is your system going to deal at the software level with this latency.


Are there timeouts, are there the implementation of some kind of protocol for resending, and so on. Another key question
at the design level as far as distributed applications are concerned is statefulness.


You know that the web applications often are stateless.


That is, every time you interact with the server, the server has to treat your interaction as a self-contained unit
without relying on any variables retaining values. Of course the database sitting there can serve as a persistent but
heavyweight way of keeping track of state.


The question from the designer then is how they're going to deal with this.


One solution is, you've seen probably with respect to cookies, that is the server sends back some of its state to the
client, which then returns that information on the next next interaction. And then there's just the general question of
concurrency. How is synchronization going to be performed, how can you ensure you don't run into any of the problems
like dead like, dead lock or making sure that everyone of the pieces of the system has some kind of interaction on a
timely basis that is, that it's live


38 - Research Questions
-----------------------

So more specific questions about building these applications include the following. One kind of question is, how do the
clients know what capabilities are available to them? One approach, which is typically used, is naming. That is the
client has the IP address or URL of server technology.


Okay? And it, it essentially finds that service by providing that name.


You can think of this as White Pages in the, in the telephone sense.


An alternative to this approach is a client saying, I have a need for service x, and being able to try to find various
resources that can find, can provide that service. That's similar to a Yellow Pages lookup.


Some Yellow Pages technology have come out, but it hasn't proven quite as successful as maybe we had hoped.


Second research question has to do with use of reflection and meta-object protocols. Recall that I mentioned that data
can sometimes be self defining, that is the data itself reflects or represents its own structure. The same thing can
hold with respect to, to programs, that is programs knowing what kind of services they provide even knowing how, they
deal with non-functional considerations.


How many transactions can they provide in a given unit of time and so on.


The third category of questions has to do with data representations. For the past 20 years, relational databases have
dominated the world, but now there's a recognition that one size does not fit all. The different kinds of applications
might require different kinds of organizations for the data. Okay. This movement is sometimes called the NoSQL movement,
and there is various commercial, even solutions out there that you can consider in building your applications.


Another question is, fat versus thin. Particularly fat versus thin clients.


This question has actually been with us for a long time. When we had applets, originally developed by Java, the idea was
that the client, that is the web browser, would, download functionality as needed.


Be able to try to provide as much functionality close to the user as possible.


This is sometimes called a fat client. The other extreme is to say, let's make the client as thin as possible. That is,
all it is is really a user interface.


Now we've gone back and forth between fat and thin clients. AJAX is a way of being able to reduce the overhead of client
to server messaging, in particular client to server when a whole page is being re-written.


AJAX is a way of making local changes to web pages without necessarily having full server interaction. Another class of
questions has to do with the different kinds of devices that are now parts of distributed systems. Sometimes those
devices are relatively constrained by their power consumption and batteries, which might mean that their memories and
their chips are going to be smaller or slower. In which case the overall device is going to be somewhat limited that
might be a reason to have a thinner client on it.


Related to that is the whole question of mobility. If part of the application, if the client side of the application is
moving around, what happens if it all suddenly goes in a tunnel, right, and you can't reach it? Your system man has to
be more robust with dealing with that kind of uncertainty.


39 - Examples
-------------

And now I want to look at a couple of examples of approaches taken to these kind of applications. You can think of these
a computing paradigms or, methods for dealing with particular kinds of situations.


In particular they both relate to services. One of them is web services and the other is service oriented architecture.


For the purposes here we can say that a service is a self contained, self defined unit of computation that's meaningful
to the user. We'll go into that a little bit more when we look as these two particular, types of implications.


40 - Service Oriented Quiz
--------------------------

In terms of the definition I just gave, voting application is not service oriented.


What change would you have to make to it to convert it into a service oriented type of application.


41 - Service Oriented Quiz Solution
-----------------------------------

Well the problem is that as described the application provides two services.


One is the ability to register votes and the other is to give you some kind of statistics.


If we wanted to convert it into a service oriented architectural style then we have to break those into two services.


Note that, that might mean we then require the user two interactions when currently there are only one.


42 - Web Services
-----------------

The first style of application is a web service. You've probably used those.


You may or may not realize you've used web services but they're there.


And all it really means is that you have some kind of software system, designed to support machine to machine
interactions over, over the web. They often involve particular with APIs or standards that are agreed upon up, by the
various parties involved.


43 - Web Services Protocols
---------------------------

1


Typically, web services really mean that you're conforming to


2 a certain alphabet soup of standards that are out there.


3


On the data side, it means you're using XML and possibly some some other


4 related protocols such as SOAP, RDF, OWL, JSON and so on.


5


On the services side, if you're doing full, full-blown web services.


6


You're probably using WSDL which is the Web Services Description Language.


7


Which gives a way of actually defining the service in such a way that


8 then code generation technology can build some of the,


9 the pieces that you need for managing it.


10


The third element of web services is UDDI which stands for


11


Universal Description Discovery and


12


Integration, and what that really means is "Yellow Pages".


13


Using UDDI you describe your service, it gets posted to some kind of server,


14 then that your potential clients can look up when they need a service,


15 and they form, in fact, provide that service.


44 - J2EE System
----------------

Here's a graphic that describes one approach to web services.


This one provided by J2EE, which is Oracle's technology for dealing with new situations. Three remaining components on
the left is your web browser, which is going to be using HTMLs or applets, or possibly even application. On the right,
is some kind of database services, and in between is where the beef is, as far as Oracle is concerned. And that's what
holds the business logic. This is the computational segment, that knows about the particular application computations.
And the way that J2EE has it, there's two parts. One is a web server, and the other is the EJB containers.


EJB is enterprise java beans which is libraries are API within Java.


Standard interactions then apply, and presumably you can build your applications using this technology, in a way that
can deal with some of the non-functional constraints that these applications have to be constructed.


45 - SOA
--------

Second example approach, Service Oriented Architecture, sometimes abbreviated


SOA. Wikipedia calls this a computer system architectural style for creating and using business processes, package to
serves throughout their life cycle.


46 - SOA Services
-----------------

What this means as far as the actual delivery of services is once again you have self contained, self defined modular
applications.


You can think of these as more or less vertical slices through the system.


That each service is capable of self contained that it has all that it needs in order to provide that functionality to
the user.


There's a definition for it, so that the remainder of the system and the architecture can have a configuration that it
understands. And it's modular, okay? It obeys certain rules about interactions. In particular, there's a use protocol
use at the level of the software architecture protocol describing, how the pieces work together.


The overall intent is to try to directly relate, the business needs of the user, to functionality that's being provided.
And typically this means that as a developer, an architect, you're coming up with a suite of sub-services, that together
can be composed into. These user facing services. You publish them, you located them in particular places and you can
dynamically invoke them.


47 - Characteristics of Services
--------------------------------

Some of the characteristics of services are flexibility. That is, you are essentially refactoring, if, if you have an
existing application, you want to make that service oriented you factored into, into pieces that then you could combine
in interesting ways. Meaningful here on the slide means each of the services is something that's meaningful to the end
user. They're stateless, for the reasons described with web services. Stateless means that typically the code is
actually simpler than it would be if you have to remember variables.


And also it's transparent with respect to middleware. Typically, there's a middleware technology solution that takes
your descriptions.


Takes your configuration information and generates the the, the middle work pieces that need to be generated.


48 - SOA Rearchitecting
-----------------------

Service Oriented Architecture is, is often of interest at the enterprise level.


That is, big corporations or organizations who have a suite of applications that they want to adapt to internet type
situations and rather than rewriting the whole suite from scratch, they want to re-architect it into a service oriented
configuration. This can be tricky, as you might imagine.


Any time you're dealing with large amounts of code and rearchitecting them.


You can run into issues of, of reliability. And there's many a story of a lot of wasted money leading to systems that
don't work as expected. So, in, in doing such rearchitecting, ultimately you have to take code that maybe was used to
running on a mainframe in which a code was controlling it's own fate.


It was in charge control-wise for calling the various pieces. Have a service oriented type architecture over the
internet, and it's intended to be providing user functions, then it may have to be switched in to a reactive type
system.


That is, responding to the user interactions. This is a major change to any system to do this. The point I'm making here
is that there's a cost in doing this and there's a high degree of risk because of that cost.


49 - Summary
------------

To kind of tie all this together,


Middleware is ultimately a collection of technologies for addressing non-functional constraints in these heterogeneous
distributed applications.


These technologies include application programmer interfaces, protocols tools, and even design patterns. As the Internet
grows, as our, our networking and our number of users and the various applications, the need for standard Middleware
solutions is going to become all that more important


