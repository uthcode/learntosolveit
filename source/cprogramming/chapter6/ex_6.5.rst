================================================
6.5 undef: remove name and definition from table
================================================

Question
========

Write a function undef that will remove a name and definition from the table
maintained by lookup and install.

.. coderun:: cprogs/ex_6.5.c
   :language: c
   :tab-width: 4

Explanation
===========

This program demonstrates implementing a hash table for inserting key -> value.
When there is a collision to inserting values against a key, it will create a linked list of values.

So, it implements

* install - installs the word in the hash table. Creates a linked list for the new value.
* lookup - looks up the word in the hash table.
* undef - removes the word in the hash table.

For each of these operations, it takes word, calculates the hash value.
If there is a collision, it will add the word to the linked list in the hashtable key.

Sample run of this program.

::

	key1->value1
	key2->value2
	key3->value3
	key not found
	key1->value1
	key2->value2
	key not found


	


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20hash%20table%20%E2%80%94%20install%20name%2Fdefinition%20pairs%20and%20look%20them%20up%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0A%23define%20HASHSIZE%207%0Astruct%20nlist%20%7B%20struct%20nlist%20%2Anext%3B%20char%20%2Aname%3B%20char%20%2Adefn%3B%20%7D%3B%0Astatic%20struct%20nlist%20%2Ahashtab%5BHASHSIZE%5D%3B%0Aunsigned%20hash%28char%20%2As%29%20%7B%0A%20%20%20%20unsigned%20hv%3B%0A%20%20%20%20for%20%28hv%20%3D%200%3B%20%2As%3B%20s%2B%2B%29%20hv%20%3D%20%2As%20%2B%2031%20%2A%20hv%3B%0A%20%20%20%20return%20hv%20%25%20HASHSIZE%3B%0A%7D%0Astruct%20nlist%20%2Alookup%28char%20%2As%29%20%7B%0A%20%20%20%20struct%20nlist%20%2Anp%3B%0A%20%20%20%20for%20%28np%20%3D%20hashtab%5Bhash%28s%29%5D%3B%20np%3B%20np%20%3D%20np-%3Enext%29%0A%20%20%20%20%20%20%20%20if%20%28strcmp%28s%2C%20np-%3Ename%29%20%3D%3D%200%29%20return%20np%3B%0A%20%20%20%20return%20NULL%3B%0A%7D%0Astruct%20nlist%20%2Ainstall%28char%20%2Aname%2C%20char%20%2Adefn%29%20%7B%0A%20%20%20%20struct%20nlist%20%2Anp%3B%0A%20%20%20%20if%20%28%28np%20%3D%20lookup%28name%29%29%20%3D%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20np%20%3D%20malloc%28sizeof%28%2Anp%29%29%3B%0A%20%20%20%20%20%20%20%20np-%3Ename%20%3D%20strdup%28name%29%3B%20np-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20hashtab%5Bhash%28name%29%5D%20%3D%20np%3B%0A%20%20%20%20%7D%20else%20free%28np-%3Edefn%29%3B%0A%20%20%20%20np-%3Edefn%20%3D%20strdup%28defn%29%3B%0A%20%20%20%20return%20np%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20install%28%22PI%22%2C%20%223.14159%22%29%3B%0A%20%20%20%20install%28%22E%22%2C%20%20%222.71828%22%29%3B%0A%20%20%20%20struct%20nlist%20%2Ap%3B%0A%20%20%20%20p%20%3D%20lookup%28%22PI%22%29%3B%20if%20%28p%29%20printf%28%22%25s%20%3D%20%25s%5Cn%22%2C%20p-%3Ename%2C%20p-%3Edefn%29%3B%0A%20%20%20%20p%20%3D%20lookup%28%22E%22%29%3B%20%20if%20%28p%29%20printf%28%22%25s%20%3D%20%25s%5Cn%22%2C%20p-%3Ename%2C%20p-%3Edefn%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
