import re
import sys

re_word = re.compile(r"[\w'-]+")
for line in open(sys.argv[1]):
    for word in re_word.finditer(line):
        print word.group(0)
