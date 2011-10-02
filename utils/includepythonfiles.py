import glob
import os
import time
import string
import tempfile

import re
import string

page_header_value = """\
===============
Python Snippets
===============

The following project page contains Python snippets useful for various tasks.

"""

footer_value = """

**Last Updated:** |today|
"""

template_value = """
**{0}**

{1}

.. literalinclude:: ../{2}
   :tab-width: 4

----
"""

re_title = re.compile(r'\$Id:\s+([\w\.]*).*\n')
re_rest = re.compile('"""(.*?)"""(.*)',re.DOTALL)

uthcodepath = '/home/senthil/uthcode/'

date_file_list = []

cfiles = glob.glob(uthcodepath + 'languages/python/*.py')

for each in cfiles:
    stats = os.stat(each)
    last_modified_date = time.localtime(stats[8])
    date_file_tuple = last_modified_date, each
    date_file_list.append(date_file_tuple)

date_file_list.sort()
date_file_list.reverse()


content = []

for item in date_file_list:
    fileloc = item[1]
    with open(fileloc) as filehandle:
        snippet = filehandle.read()

    title = re_title.search(snippet)
    rest = re_rest.search(snippet)

    if not title:
        title = item[1].split('/')[-1]
    else:
        title = title.group(1)

    if not rest:
        header = 'Purpose: - An Example Snippet'
        filename = os.path.join(os.getcwd(),item[1])
    else:
        header = rest.group(1)
        code = rest.group(2)
        filename = tempfile.mkstemp('.py','python-',dir='temp',text=True)[1]
        with open(filename,'w') as f:
            f.write(code)

    filename = filename.replace(uthcodepath,'')
    out = template_value.format(title,header, filename)
    content.append(out)

content = ''.join(content)

with open(uthcodepath + 'source/pythonsnippets.rst','w') as fobject:
    fobject.write(page_header_value)
    fobject.write(content)
    fobject.write(footer_value)
