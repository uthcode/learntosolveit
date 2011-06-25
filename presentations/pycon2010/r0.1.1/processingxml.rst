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


    <html>
        <head>
            <title>Example page</title>
        </head>
        <body>
            <p>Moved to <a href="http://example.org/">example.org</a>
            or <a href="http://example.com/">example.com</a>.</p>
        </body>
    </html>

Example of changing the attribute "target" of every link in first paragraph::

    >>> from xml.etree.ElementTree import ElementTree
    >>> tree = ElementTree()
    >>> tree.parse("index.xhtml")
    <Element html at b7d3f1ec>
    >>> p = tree.find("body/p")     # Finds first occurrence of tag p in body
    >>> p
    <Element p at 8416e0c>
    >>> links = p.getiterator("a")  # Returns list of all links
    >>> links
    [<Element a at b7d4f9ec>, <Element a at b7d4fb0c>]
    >>> for i in links:             # Iterates through all found links
    ...     i.attrib["target"] = "blank"
    >>> tree.write("output.xhtml")


Dealing with Database stuff
---------------------------
