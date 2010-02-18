Processing XML
==============

* XML is the open standards way of exchanging information.
* Dealing with XML is not very seamless, there is always a requirement to write
  code that reads (i.e, deserializes or parses) and writes (i.e, serializes)
  XML.
* It is important to note that modules in the xml package require that there be
at least one SAX-compliant XML parser available. Starting with Python 2.3, the
Expat parser is included with Python, so the xml.parsers.expat module will
always be available. 
* xml.dom and xml.sax packages are the definition of the Python bindings for the DOM and SAX interfaces.

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


Processing XML using the ElementTree module
-------------------------------------------
.. literalinclude:: py31/howto12_processing_xml.py
