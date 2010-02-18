Process Handling
================

subprocess module
-----------------

The `subprocess` module allows you to spawn new processes, connect to their
input/output/error pipes, and obtain their return codes.

Basic Examples of using subprocess
----------------------------------
``subprocess.call(*popenargs, **kwargs)``

This is convenience function provided by subprocess module which executes the
command given by the argument, when shell=True is the shell variables are
expanded in the command line.

`subprocess` module defines a class called `Popen`::

        class subprocess.Popen(args, bufsize=0, executable=None, stdin=None,
        stdout=None, stderr=None, preexec_fn=None, close_fds=False,
        shell=False, cwd=None, env=None, universal_newlines=False,
        startupinfo=None, creationflags=0)

* ``subprocess.PIPE``: Special value that can be used as the stdin, stdout or
  stderr argument to Popen and indicates that a pipe to the standard stream
  should be opened.

* ``subprocess.STDOUT``: Special value that can be used as the stderr argument
  to Popen and indicates that standard error should go into the same handle as
  standard output.


.. literalinclude:: py31/howto16_subprocess_examples.py

Writing a Task Scheduler
------------------------

.. literalinclude:: py31/howto17_scheduling.py

Monitoring a directory for changes
----------------------------------

.. literalinclude:: py31/howto18_monitordir.py

Monitoring a directory asynchronously using twisted
---------------------------------------------------
.. literalinclude:: py31/howto18_monitordir_twisted-py26.py
