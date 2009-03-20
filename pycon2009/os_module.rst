=========
os module
=========

This module provides a unified interface to a number of operating system
functions.

Most of the functions in this module are implemented by platform specific
modules, such as posix and nt. The os module automatically loads the right
implementation module when it is first imported.

Differences from earlier python releases
----------------------------------------

* popen2,popen3,popen4 modules are Deprecated in Python 2.6
* popen2,popen3,popen4 modules are removed in Python 3.0.
* Most of the these functionalities are best adviced to be carried out through subprocess module.
* os.popen() method exists though to create child processes.


Working with directories and files
----------------------------------
There are several functions for working with directories on filesystem,
including creating, listing contents and removing them. Let us look into
``os.getcwd()``, ``os.makedirs(path[,mode=777])``, ``os.path.join(a,*p)``,
``os.listdir(path)``, ``os.unlink(path)`` and ``os.rmdir(path)`` with this
example.

``os.curdir`` and ``os.pardir`` attributes refer the current directory and
parent directory respectively in a portable manner.

.. literalinclude::        os_directories_12.py

Note
^^^^
* There is difference between ``os.mkdir(path,[,mode=777])`` and
  ``os.makedirs(path[,mode=777])``, the latter is recursive and it best to use
  makedirs.


Checking file permissions.
--------------------------
We can test the permissions set on file, by using ``os.access(path,mode)`` module.

.. literalinclude::        os_permissions_9.py

* __file__ is a special attribute that points to the current file in python interpretor.

Change file permissions using chmod
-----------------------------------
Subsequent to the ``os.access(path,mode)``, os.chmod can be used to set the file
permissions.  Here we also see the `stat` module to retrieve the permission
values to be set using ``os.chmod(path,mode)``

.. literalinclude::        os_chmod_11.py

file and file system status through stat system call
----------------------------------------------------
``os.stat(path)`` returns stat information about *path* in the same formata on
both Unix and Windows Operating Systems. The stat values are interpreted using
the stat helper attributes.

.. literalinclude::        os_stat_10.py

Creating a symbolic link to a file.
-----------------------------------

``os.symlink(src,dst)`` method provides the facility to create a symbolic link at `dst` for the `src`. We also see ``os.readlink(path)`` and ``os.unlink(path)`` in this example.

* `tempfile` module is used to create a temporary file.

.. literalinclude::        os_symlink_13.py

Getting the user information.
-----------------------------
User information details such as effective user id, actual user id, group id and login id can be got from os module. In this example, let us look at ``os.geteuid()``, ``os.getegid()``, ``os.getuid()``, ``os.getgid()``, ``os.getlogin()``, ``os.getgroups()`` and ``os.setegid(gid)``.

.. literalinclude::        os_module_1.py

* Exception ``OSError`` is raised on failure to perform any operation from os module.


Environment values and execution
--------------------------------

Methods available ``os.environ`` provide facilities to get and set the
enviroment variable.  Please note that the enviroment variables are set for the
Python process and cannot be reflected in the system environment variables
outside in the parent process. That is, child process cannot change values of
the parent process.

``os.system(command)`` provides a facility to execute the command as executed
by the operating system shell.

.. literalinclude::        os_module_2.py

popen - Open a pipe
-------------------

``popen(command [, mode='r' [, bufsize]]) -> pipe`` 

Open a pipe to/from a command returning a file object.

.. literalinclude::        os_module_4.py
