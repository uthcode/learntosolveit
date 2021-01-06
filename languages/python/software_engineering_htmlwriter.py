"""
This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or (at your
option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.
"""

class TreeNode(list):
    def __init__(self, tag, wrapper_node=None, **kwds):
        super(TreeNode, self).__init__()
        self._wrap = wrapper_node
        self._tag = tag
        self._attrs = kwds

    def _render_attrs(self):
        if self._attrs:
            return ' ' + ' '.join('%s="%s"' % attr for attr in self._attrs.items())
        else:
            return ''

    def _render(self, depth=0):
        depthStr = " " * (depth * 4)
        result = [depthStr + '<%s%s>' % (self._tag, self._render_attrs())]
        for content in self:
            try:
                content = content._render(depth=depth+1)
            except AttributeError:
                content = str(content)
            if self._wrap:
                result.append(self._wrap(content)._render(depth=depth+1))
            else:
                result.append(content)
        result.append(depthStr + '</%s>' % self._tag)
        return '\n'.join(result)

    def __str__(self):
        return self._render()

class Document(TreeNode):
    def __init__(self, title):
        super(Document, self).__init__('body')
        self._title = title

    def _render(self, depth=0):
        html = TreeNode('html', lang='en')
        head = TreeNode('head')
        titleNode = TreeNode('title')
        titleNode.append(self._title)
        head.append(titleNode)
        html.append(head)
        body = super(Document, self)._render(depth+1)
        html.append(body)
        return html._render(depth=depth)

def _create_tag(tag, wrapper_node=None, use_list=False):
    def _tag(content=None, *args, **kwds):
        t = TreeNode(tag=tag, wrapper_node=wrapper_node, *args, **kwds)
        if content:
            if use_list:
                t.extend(content)
            else:
                t.append(content)
        return t
    return _tag

Paragraph = _create_tag('p')
Heading = _create_tag('h1')
Subheading = _create_tag('h2')
Row = _create_tag('tr', wrapper_node=_create_tag('td'), use_list=True)
HeadingRow = _create_tag('tr', wrapper_node=_create_tag('th'), use_list=True)
Table = _create_tag('table')



if __name__ == '__main__':
    # A simple example that creates a basic HTML document 
    # and outputs it to file.html

    doc = Document("Hello World")
    doc.append(Heading("This is a heading"))
    doc.append(Subheading("This is a subheading"))
    doc.append(Paragraph("This is a paragraph"))
    t = Table(cellpadding="10", border="1")
    t.append(HeadingRow(["Col1", "Col2", "Col3"]))
    t.append(Row(["Column1", "Column2", "Column3"]))
    doc.append(t)
    print(doc)
##    f=open('file.html', 'w')
##    f.write(doc)
##    f.close()
    

