# Reading a Specific Line from a file
import linecache
theline = linecache.getline('12.py',10)
print theline,

def getline(thefilepath, desired_line_number):
    if desired_line_number < 1: return
    for current_line, line in enumerate(open(thefilepath,'rU')):
        if current_line == desired_line_number - 1:
            return line
    return ''

