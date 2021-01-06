"""
This  program checks if a string is a text or binary.
This snippet is from Python Cookbook.
"""
 # ensure / does not truncate
import string
text_characters = "".join(map(chr, list(range(32, 127)))) + "\n\r\t\b"
_null_trans = string.maketrans("","")

def istext(s, text_characters=text_characters, threshold=0.30):
    # if s contains any null, then it is not text:
    if '\0' in s:
        return False
    # An empty string is still a text
    if not s:
        return True
    # Get the substring of s made of non-text characters
    t = s.translate(_null_trans, text_characters)
    # s is 'text' if less than 30% of its characters are non-text ones:
    return len(t)/len(s) <=threshold

print("Hello, World ", istext("Hello, World"))
print("\xc3\xa4", istext("\xc3\xa4"))
