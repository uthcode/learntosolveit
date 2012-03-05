import re

class Stack(object):
    def __init__(self):
        self.items = []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def is_empty(self):
        return not self.items

def striptag(t):
    if '/' in t:
        return t[2:-1]
    else:
        return t[1:-1]

def solve(text):
    if (text.count("<") != text.count(">")):
        return "bad character in tag name"
    # greedy regex search
    tags = re.compile(r'<.*?>')
    all_tags = tags.findall(text)
    print all_tags
    for tag in all_tags:
        c = striptag(tag)
        # if more than 10 characters in tag.
        # too many/few characters in tag name
        if len(c) > 10 or len(c) == 0:
            return "too many/few characters in tag"

        # if not find upper case alphabetic character
        # bad character in tag name

        reg = re.compile(r'[A-Z]*')
        match = reg.match(c)
        if not match.group():
            return "bad character in tag name"
        # No ending tag
        # expected </xxxxx>
        # No begin tag
        # no matching begin tag.
    return "OK"


tc = 1
N = int(raw_input())
while N:
    content = []
    for line in range(N):
        content.append(raw_input())
    input_html = "".join(content)
    result = solve(input_html)
    print "Case #%d: %s" % (tc, result)
    tc += 1
    N = int(raw_input())

