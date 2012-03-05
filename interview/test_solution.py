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
    def remove(self, item):
        self.items.remove(item)

def striptag(t):
    if '/' in t: # closing tag
        return t[2:-1]
    else:
        return t[1:-1]

def solve(text):
    # Just check if there is a missing < or >
    if (text.count("<") != text.count(">")):
        return "bad character in tag name"

    # greedy regex search
    tags = re.compile(r'<.*?>')
    all_tags = tags.findall(text)
    s = Stack()

    for tag in all_tags:
        c = striptag(tag)
        if len(c) > 10 or len(c) == 0:
            return "too many/few characters in tag"

        # if not find upper case alphabetic character
        # bad character in tag name
        reg = re.compile(r'[A-Z]*')
        match = reg.match(c)
        if not match.group():
            return "bad character in tag name"

        s.push(tag)

    while not s.is_empty():
        tag = s.pop()
        if not tag.startswith("</"):
            return "expected </" + striptag(tag) + ">"
        start_tag = "<" + striptag(tag) + ">"
        if not start_tag in s.items:
            return "no matching begin tag"
        else:
            s.items.remove(start_tag)

    return "OK"


if __name__ == '__main__':
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

