=========
threading
=========

Threads allow applications to perform multiple tasks at once. Multi-threading
is important in many applications, from primitive servers to today's complex
and hardware-demanding games.

`Credits`: Peyton McCullough 
`Article`: Basic Threading in Python

Simplest Thread
---------------

The threading module provides an easy way to work with threads. Its Thread
class may be subclassed to create a thread or threads. The run method should
contain the code you wish to be executed when the thread is executed. This
sound simple, right? Well, it is:

Executing the thread is also simple. All we have to do is create an instance of
our thread class and then call its start method:

.. literalinclude::        threadin_2.py

Group of Threads
----------------

.. literalinclude::        threading_3.py

Server which services clients in threads
----------------------------------------

Let us build a server, which services clients in threads. When client opens a
connection with the server, the server will create a new thread to handle the
client.

.. literalinclude::        threading_4.py

Client process for this server
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude::        threading_4_client.py

multi-threaded client
^^^^^^^^^^^^^^^^^^^^^

.. literalinclude::        threading_client_5.py

Threaded Pool Server
--------------------

It's important to remember that threads don't start up instantly. Creating too
many of them can slow down your application. It takes time to spawn and later
kill threads. Threads can also eat up valuable system resources in large
applications. This problem is easily solved by creating a set number of threads
(a thread pool) and assigning them new tasks, basically recycling them.
Connections would be accepted and then pushed to a thread as soon as it
finished with the previous client.

Obviously, we'll need something that can transfer client data to our threads
without running into problems (it will need to be “thread safe”). Python's
Queue module does this for us. Client information is stored in a Queue object,
where threads can pull them out when needed.

.. literalinclude::        threading_server_6.py

Naming the Threads
------------------

.. literalinclude::        threading_names_7.py

Check status of Threads
-----------------------

.. literalinclude::        threading_alive_8.py

join and setdaemon methods
--------------------------
If we want a particular thread to wait for another thread to terminate itself,
then we can use the join method.

.. literalinclude::        threading_join_9.py

We can use the setDaemon method, too. If a True value is passed with this
method and all other threads have finished executing, the Python program will
exit, leaving the thread by itself:

.. literalinclude::        threading_setdaemon_10.py


Banking Scenario with threading
-------------------------------
``Credits:`` Jesse Nooler

.. literalinclude::        threading_bankexample_15.py


.. .. literalinclude::        threadin_1.py
.. .. literalinclude::        threadin_2_14.py
.. .. literalinclude::        threading_1_12.py
.. .. literalinclude::        threading_function_as_thread_11.py
.. .. literalinclude::        threading_simplest_thread_13.py
