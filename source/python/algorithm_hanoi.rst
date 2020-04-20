===============
Towers of Hanoi
===============

Question
--------

Implement the Towers of Hanoi program.


Solution
--------

.. literalinclude:: ../../languages/python/algorithm_hanoi.py
   :language: python
   :tab-width: 4


Visualize
---------


.. raw:: html

    <iframe width="100%" height="500px" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23!/usr/bin/python%0A%23%20Towers%20of%20Hanoi%20program.%0A%0Adisks%20%3D%203%0Afrom_tower%20%3D%20'A'%0Ato_tower%20%3D%20'C'%0Ausing_tower%20%3D%20'B'%0A%0Adef%20hanoi%28n,%20from_tower,%20to_tower,%20using_tower%29%3A%0A%20%20%20%20if%20n%20%3E%200%3A%0A%20%20%20%20%20%20%20%20hanoi%28n-1,%20from_tower,%20using_tower,%20to_tower%29%0A%20%20%20%20%20%20%20%20print%20'move%20disk%20from%20',%20from_tower,%20'%20to%20',%20to_tower%0A%20%20%20%20%20%20%20%20hanoi%28n-1,%20using_tower,%20to_tower,%20from_tower%29%0A%0Ahanoi%28disks,%20from_tower,%20to_tower,%20using_tower%29&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=2&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>

Execute
-------

.. raw:: html

    <iframe frameborder="0" width="100%" height="500px" src="https://repl.it/@orsenthil/uthcodepythonhanoi?lite=true&outputonly=1"></iframe>




.. seealso::

   * :python-suggest-improve:`algorithm_hanoi.py`
   * :python-better-explain:`algorithm_hanoi.rst`
