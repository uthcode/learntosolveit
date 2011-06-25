==========
subprocess
==========

The `subprocess` module allows you to spawn new processes, connect to their
input/output/error pipes, and obtain their return codes.

``subprocess.call(*popenargs, **kwargs)``
-----------------------------------------
This is convenience function provided by subprocess module which executes the command given by the argument, when shell=True is the shell variables are expanded in the command line.

.. literalinclude::        subprocess_1.py

Popen method
------------
`subprocess` module defines a class called `Popen`.

::
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

.. literalinclude::        subprocess_2.py
