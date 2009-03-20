=============
shutil module
=============

This utility module contains some functions for copying files and directories.
This module provide high level operations that get performed on a bunch of
files or a collection.

Note that copy methods cannot reliably copy all the metadata. On POSIX
platforms, this means that file owner and group are lost as well as ACLs. On
Mac OS, the resource fork and other metadata are not used. This means that
resources will be lost and file type and creator codes will not be correct. On
Windows, file owners, ACLs and alternate data streams are not copied.


What's new shutil module in Py2.6 and Py3k.
-------------------------------------------
* copytree function has an additional parameter called ignore, which takes
  callable as an argument. shutil also exposes a ignore_patterns function which
  can be used with ignore parameter.


Simplest shutil.copy example
----------------------------
The following snippet demonstrates, ``copy(src, dst)`` function. It copies the
data as well as the mode bits and as the following shows, it can copy a file
into a directory.  The copy function copies a file in pretty much the same way
as the Unix cp command.

.. literalinclude::        shutil_copy.py

shutil.copy2 example
--------------------
Copy data and all stat info ("cp -p src dst").

.. literalinclude::        shutil_copy2.py

move, copytree, rmtree
----------------------
The following snippet demonstrates, ``move(src, dst)``, which recursively move
a file or directory to another location. This is similar to the unix `mv` command.

``copytree(src, dst, symlinks=False, ignore=None)``, recursively copies a
directory tree using copy2() function and ``rmtree(path, ignore_errors=False,
onerror=None)`` recursively deletes a directory tree.

.. literalinclude::        shutil_move_copy_rmtree.py

* commands.getoutput, returns the output(stdout,stderr) as if executed from a shell.

copyfileobj function
--------------------

``copyfileobj(fsrc, fdst[, length=16384])``,copy data from file-like object
fsrc to file-like object fdst. length is optional. fsrc, and fdst should be
open file handles.

.. literalinclude::        shutil_copyfileobj.py

copyfile and copymode
---------------------
``copyfile(src, dst)``, copies the src to dst. The permissions are set
according to the umask of the current user.  In order to copy the file mode
bits from one file to another, we use ``copymode(src, dst)``. copymode, does
not create a destination file, it assumes dst already exists.

.. literalinclude::        shutil_copymode.py

copystat
--------

``shutil.copystat(src, dst)``, copie all stat info (mode bits, atime, mtime,
flags) from src to dst. It is best verified from the following example.

.. literalinclude::        shutil_copystat.py


Assignment
----------
* Write a script that can export a svn or cvs directory.
