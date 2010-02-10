Processing XML
==============

Parsing XML using xml.etree module
----------------------------------

First of all understand that Element Tree is a tree datastructure. It
represents the XML document as a Tree. The XML Nodes are Elements. (Thus Element Tree)
Now, if I were to structure an html document as a element tree.



:: 
                <html>
                  |
                <head> -------
                /   \        |
             <title> <meta> <body>
                           /   |  \
                        <h1>  <h2> <para>
                                   /   \
                                  <li> <li>


The Element type is a flexible container object, designed to store hierarchical
data structures in memory. The type can be described as a cross between a list
and a dictionary.  The C implementation of xml.etree.ElementTree is available
as xml.etree.cElementTree


Dealing with Database stuff
---------------------------
