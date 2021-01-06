"""
Finding 'class' in every file python file in the directory.
'out' and 'err' are string objects containing the standard output and,
eventually, the error output.

find -iname *.py|xargs grep class

"""
from subprocess import Popen, PIPE
find_process = Popen(['find', '-iname', '*.py'], stdout=PIPE)
grep_process = Popen(['xargs', 'grep', 'class'], stdin=find_process.stdout, stdout=PIPE)
out, err = grep_process.communicate()
print(out)
