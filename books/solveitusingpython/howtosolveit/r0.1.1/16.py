import re
import sys

def words_of_file(thefilepath, line_to_words=str.split):
    the_file = open(thefilepath)
    for line in the_file:
        for word in line_to_words(line):
            if type(word) is str:
                yield word
            else:
                yield word.group(0)
    the_file.close()

for word in words_of_file(sys.argv[1]):
    print word

def words_by_re(thefilepath, repattern=r"[\w'-]+"):
    wre = re.compile(repattern)
    def line_to_words(line):
        return wre.finditer(line)
    return words_of_file(thefilepath, line_to_words)

for word in words_by_re(sys.argv[1]):
    print word
