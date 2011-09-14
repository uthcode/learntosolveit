Paxos Algorithm

If you need agreement, you're lost.

Each node in a system should be able to make decisions purely based on local
state. If you need to do something under high load with failurs occuring and
you need to reach agreementm you are lost. If you are concerned about
scalability, any algorithm that forces you to run agreement will eventually
become your bottlenock. Take that as a given.


http://www.evanjones.ca/model-checking-paxos.html
