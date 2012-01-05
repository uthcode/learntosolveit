===============
Paxos Algorithm
===============

If you need agreement, you're lost.

Each node in a system should be able to make decisions purely based on local
state. If you need to do something under high load with failures occuring and
you need to reach agreement you are lost. If you are concerned about
scalability, any algorithm that forces you to run agreement will eventually
become your bottlenock. Take that as a given.


http://www.evanjones.ca/model-checking-paxos.html

A better example might be a game with simultaneous moves, such as Jeopardy.
Paxos in this situation would allow all the servers to decide together what
sequence a series of closely timed events (such as buzzer presses) occurred in,
such that all the servers come to the same conclusion.
