9 Lives
=======

Entry in PyWeek #12  <http://www.pyweek.org/12/>
URL: http://pyweek.org/e/Grizzly
Team: Grizzly Games
Members: Levayaj, phoe6, rakeshs
License: see LICENSE.txt


Running the Game
----------------

On Windows or Mac OS X, locate the "run_game.pyw" file and double-click it.

Othewise open a terminal / console and "cd" to the game directory and run:

  python run_game.py

Dependencies
------------

Install pyglet library in your Operating System.


How to Play the Game
--------------------

Use the Allow Keys to catch the interests of the cat within 1 minute.
Do not hit the barb-wire that is surrounding the fence.

Development notes 
-----------------

Creating a source distribution with::

   python setup.py sdist

You may also generate Windows executables and OS X applications::

   python setup.py py2exe
   python setup.py py2app

Upload files to PyWeek with::

   python pyweek_upload.py

Upload to the Python Package Index with::

   python setup.py register
   python setup.py sdist upload

