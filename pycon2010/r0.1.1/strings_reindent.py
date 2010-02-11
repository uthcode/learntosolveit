
def reindent(s, numSpaces=1):
    leading_space = numSpaces * ' '
    lines = [ leading_space + line.strip()
             for line in s.splitlines() ]
    return '\n'.join(lines)


sentence = """

        This is a sentence which is not formatted. 
   You this right? 
                    How would it be good be really well formattted?

        Let us try it?
"""
print sentence
print '-'*80
print reindent(sentence)
