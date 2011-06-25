Unit test - Super Cool stuff
============================

How to write Unit tests
-----------------------

The :mod:`unittest` module provides a rich set of tools for constructing and
running tests.  This section demonstrates that a small subset of the tools
suffice to meet the needs of most users.

Here is a short script to test three functions from the :mod:`random` module::

   import random
   import unittest

   class TestSequenceFunctions(unittest.TestCase):

       def setUp(self):
           self.seq = list(range(10))

       def test_shuffle(self):
           # make sure the shuffled sequence does not lose any elements
           random.shuffle(self.seq)
           self.seq.sort()
           self.assertEqual(self.seq, list(range(10)))

       def test_choice(self):
           element = random.choice(self.seq)
           self.assert_(element in self.seq)

       def test_sample(self):
           self.assertRaises(ValueError, random.sample, self.seq, 20)
           for element in random.sample(self.seq, 5):
               self.assert_(element in self.seq)

   if __name__ == '__main__':
       unittest.main()


The unittest module can be used from the command line to run tests from
modules, classes or even individual test methods::

   python -m unittest test_module1 test_module2
   python -m unittest test_module.TestClass
   python -m unittest test_module.TestClass.test_method

You can pass in a list with any combination of module names, and fully
qualified class or method names.

You can run tests with more detail (higher verbosity) by passing in the -v flag::

   python-m unittest -v test_module

For a list of all the command line options::

   python -m unittest -h

..  versionchanged:: 2.7
   In earlier versions it was only possible to run individual test methods and
   not modules or classes.

The command line can also be used for test discovery, for running all of the
tests in a project or just a subset.


.. _unittest-test-discovery:

Test Discovery
--------------

.. versionadded:: 2.7

unittest supports simple test discovery. For a project's tests to be
compatible with test discovery they must all be importable from the top level
directory of the project; i.e. they must all be in Python packages.

Test discovery is implemented in :meth:`TestLoader.discover`, but can also be
used from the command line. The basic command line usage is::

   cd project_directory
   python -m unittest discover

The ``discover`` sub-command has the following options:

   -v, --verbose    Verbose output
   -s directory     Directory to start discovery ('.' default)
   -p pattern       Pattern to match test files ('test*.py' default)
   -t directory     Top level directory of project (default to
                    start directory)

The -s, -p, & -t options can be passsed in as positional arguments. The
following two command lines are equivalent::

   python -m unittest -s project_directory -p '*_test.py'
   python -m unittest project_directory '*_test.py'

