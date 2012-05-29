Network Programming
-------------------

In Computing, Network Programming is essentially identified as socket
programming or client-server programming, involves writing computer programs
that communicate with other programs across the Computer Network.  The program
initiating the communication is called the client and the program waiting for
the communication to get initiated is called the server.  The client and the
server process together form the distributed system. The connection between the
client and the server process may be connection oriented (TCP/IP or session) or
connectionless (UDP)

The program that can act both as server and client is based on peer-to-peer
communication. Sockets are usually implemented by an API library such a
Berkeley sockets, first introduced in 1983. The example functions provided by
the API library include:

* socket() - creates a new socket of certain type, identified by the integer
  number and allocates system resources to it.
* bind() is used at the server side; associates a socket with a socket adddress
  structure, typically a IP Address and a Port number.
* listen() is used again on the server side, causes a bound TCP socket to
  listen to enter a listening state.
* connect() is used on the client side; used to assign a free local port number
  to the socket. It causes an attempt to establish a new TCP Connection.
* accept() is used on the server side; It accepts a received incoming connect()
  request and creates a new socket associated with the socket address pair for
  this connection.
* send(), recv(), write(), read() or recvfrom() and sendto() are used for
  sending and receiving data.
* close() is used to terminate the connection and release the resources
  allocated to the socket. 


Twisted Framework
-----------------

Twisted framework provides the facility to build an asynchronous, event-driven
applications for Distributed Network Environment. You will understand all these
terminologies if you just find reason to go ahead and build one.  Twisted is a
platform for developing Internet applications. In the Twisted, internet term
actually denotes internetworking.

At the core of Twisted Framework is its network layer, which can be used to
integrate any existing  protocol as well as model new ones.  Twisted is a pure
python framework. 

Twisted supports Asynchronous programming and deferred abstraction, which
symbolizes a promised result and which can pass eventual result to  handler
functions.  

A fundamental feature of Network Programming is waiting for data. The Normal
Model when using twisted framework is by using Non-Blocking Calls.  When
dealing with many connections in one thread, the scheduling is the
responsiblity of the application, not the operating system, and is usually
implemented by calling a registered function when each function is ready to go
for reading or writing - commonly known as asynchronous, event based, callback
based programming.  

In synchronous programming, a function requests data, waits for the data, and
then processes it. In asynchronous programming, a function requests the data,
and lets the library call the callback function when the data is ready.

It is the class of concurrency problems, non-computationally intensive tasks
that involve an appreciable delay that deferreds are designed to help solve.
They do this by giving a simple management interface for callbacks and
applications.  blocking - means, if one tasks is waiting for data, the other
task cannot get CPU but also waits until the first tasks finishes.  The typical
asynchronous model to notify an application that some data is ready is called
as callback.

Twisted uses Deferred objects to managed callback sequence.  Libraries know
that they make their results available by using Deferred.callback and errors by
Deferred.errback.  

How does the parent function or its controlling program know that connection
does not exist and when it will know, when the connection becomes alive?

Twisted has an object that signals this situation, it is called
twisted.internet.defer.Deferred. Deferred has two purposes; first is saying
that I am a signal, of whatever you wanted me to do is still pending; second
you can ask differed to run things when the data arrives.  The way to tell the
deffered what to do when the data arrives is by defining a callback - asking
the deferred to call a function once the data arrives.  

Deferreds are an object which represent a promise of something; 
Like getPage() returned a Deferred object, which means that when the getPage is
called ( It may not be called sequentially, because it is  asynchronous); a
callback may be attached to the defered object which will ask it do whatever
with the data, in our case, the callback was to print the data.

If nothing else is understood, please understand that you create a differed
object, add a callback function to that object and add an errorback function to
that object. Differed will get called after a particular period of time or some
data is avaiable.Differeds are the signals for asynchronous functions to use to
pass results onto the callbacks, but using them does not guarantee that you
have asynchronous functions.What Differeds dont do: Make your code
asynchronous!.

twisted.internet.defer.Deferred is a promise that the function at some point in
time will have a result.

The Deferred mechanism, standardizes the application programmers inferface with
all sort of blocking and delayed operations.

It is possible to adapt, synchronous functions to return Deferred. Sometimes
you want to be notified after several different events have all happened,
rather than waiting for each one individually.

You may want to wait for all connections in a list to close.

Generating Deferreds is a Document introducing writing of Asynchronous
functions generating deferreds.

deferreds are not a non-blocking talisman; they are a signal for asynchronous
functions to use to pass results to callback once the results are available.

Returning Deferreds from synchronous functions; reasons :- API compatiblity
with another function which returns deferred or making the function
asynchronous in the future.

Requesting method requests a data; and gets a Deferred object.
Requesting method attaches callbacks to the Deferred object, 

Twisted also provides facility to run the blocking function in a separate
thread instead of blocking them.

A Twisted Protocol handles code in an asynchronous manner. What this means is
that the Protocol does not wait for an event, but rather handles the event as
they arrive from network.In the Twisted client, an instance of the Protocol
class will be instantiated when you connect to the Server and will go away when
the connection is finished.

Interface classes are a way of specifying what methods and attributes a
Protocol provides.

* event: Event Driven programming or Event Based Programming is where program
  flow happens based on events like mouse movement or key press or signal from
  another thread.

* Event Driven Programming is paradigm, in which there is a main-loop, which
  does event-detection and event-handling.

* Reactor:  The reactor design pattern is a concurrent programming pattern, for
  handling service requests delivered concurrently to a service handler by one
  or more inputs.

* The service handler then demultiplexes the incoming requests and dispatches
  them synchronously to associated request handlers.

The event loop almost always operates asynchronously with the message
originator.  The event loop forms the central constuct flow of the program, is
the highest level of control within the program. It is often termed as the
main-loop or the main-event loop.

The event loop is the specific implementation techniques of system which does
message passing.

Under Unix, everything is a file-paradigm naturally leads to a file based
event-loop. select and poll system calls monitor a set of file-descriptors for
events.

One of few things in Unix that do not confirm to file descriptors are
asynchronous events (signals); signals are received in signal handlers, small,
limited piece of code that run while rest of the task is suspended. 

Twisted project supports TCP, UDP, SSL/TLS and IP Multicast, Unix Domain
Sockets, a large number of protocols such  as HTTP, XMPP, NNTP, IMAP, SSH, IRC,
FTP.
