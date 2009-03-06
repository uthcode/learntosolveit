# Get the number of unique constituent words of the composite word from the list.
# composite words and consituent word must be present in the list.

wordlist = ['mad','hatter','madhatter','hattermad','madman','man','manhatter',
            'madhatterman','madhatman','madmadmanhatter']

def combination(compword, wordlist):
    for word in wordlist:
        # If it is not a compound word
        # and word is a part of the test compound word
        if not word == compword and compword.startswith(word):
            # test remaining


print combination('madmadmanhatter',wordlist)


