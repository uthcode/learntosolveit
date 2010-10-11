import re
str1 = """
(0.5 cool
  ( 1.000)
    (0.5 ))
    """

pat = re.compile("(\(\d\.\d \w* \)*)")

print pat.search(str1)
