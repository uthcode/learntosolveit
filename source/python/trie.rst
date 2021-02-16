====
Trie
====

Question
--------

This is simple implementation of Trie data structure.


Solution
--------

.. literalinclude:: ../../languages/python/trie.py
   :language: python
   :tab-width: 4


Explanation
===========

Trie is implemented as a nested dictionary. The printed output shows that fact.
Every insert a new temp dictionary is created for nesting. 

The output of this program will be.

::

   {
   "h": {
      "e": {
         "l": {
         "l": {
            "o": {
               "*": "*"
            }
         },
         "p": {
            "*": "*"
         }
         }
      },
      "i": {
         "*": "*"
      }
   }
   }
   True
   False
   True


Here is a visualization code for `make_trie` to see how the trie builds up over time.

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="http://pythontutor.com/iframe-embed.html#code=_end_marker%20%3D%20%22*%22%0A%0Adef%20add_word%28trie,%20word%29%3A%0A%20%20%20%20word_trie%20%3D%20trie%0A%20%20%20%20%0A%20%20%20%20for%20ch%20in%20word%3A%0A%20%20%20%20%20%20%20%20if%20ch%20in%20word_trie%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20word_trie%20%3D%20word_trie%5Bch%5D%0A%20%20%20%20%20%20%20%20else%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20word_trie%5Bch%5D%20%3D%20%7B%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20word_trie%20%3D%20word_trie%5Bch%5D%0A%20%20%20%20%0A%20%20%20%20word_trie%5B_end_marker%5D%20%3D%20_end_marker%0A%0A%20%20%20%20return%20word_trie%0A%0Adef%20make_trie%28*words%29%3A%0A%20%20%20%20trie%20%3D%20dict%28%29%0A%0A%20%20%20%20for%20word%20in%20words%3A%0A%20%20%20%20%20%20%20%20add_word%28trie,%20word%29%0A%20%20%20%20%0A%20%20%20%20return%20trie%0A%0Atrie%20%3D%20make_trie%28%22hi%22,%20%22hello%22,%20%22help%22%29&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=73&heapPrimitives=nevernest&origin=opt-frontend.js&py=3&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>



.. git_changelog::


.. seealso::

   * :python-suggest-improve:`trie.py`
   * :python-better-explain:`trie.rst`

