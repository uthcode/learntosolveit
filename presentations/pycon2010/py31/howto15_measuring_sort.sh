/usr/local/bin/python3.1 -mtimeit -s'import random; x=list(range(1000)); random.shuffle(x)' 'y=list(x); y.sort()'
/usr/local/bin/python3.1 -mtimeit -s'import random; x=list(range(1000)); random.shuffle(x)' 'x.sort()'
/usr/local/bin/python3.1 -mtimeit -s'import random; x=list(range(1000)); random.shuffle(x)' 'sorted(x)'
