import re

WORD_REGEX = re.compile(r"[\w'-]+")

def do_something_with_word(word):
    print(word)

def words_in_file(file_name):
    with open(file_name) as fh:
        for line in fh:
            for word in WORD_REGEX.finditer(line):
                do_something_with_word(word.group(0))

def main():
    words_in_file('./files_processing_every_word.py')

if __name__ == '__main__':
    main()