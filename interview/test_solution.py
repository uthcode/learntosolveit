import re

def solve(text):
    # greedy regex search
    tags = re.compile(r'<.*?>')
    for tag in tags.finditer(text):
        # if not find upper case alphabetic character
        # bad character in tag name
        # if more than 10 characters in tag.
        # too many/few characters in tag name
        # No ending tag
        # expected </xxxxx>
        # No begin tag
        # no matching begin tag.
        if "/" in tag:
            if (len(tag[2:-1]) > 10):
                return "too many/few characters in tag name"
        else:
            if len(tag[1:-1] > 10):
                return "too many/few characters in tag name"
    return "0"


tc = 1
N = int(raw_input())
while N:
    content = []
    for line in range(N):
        content.append(raw_input())
    input_html = "".join(content)
    result = solve(input_html)
    print "Case #%d: %s" % (tc, input_html)
    tc += 1
    N = int(raw_input())

