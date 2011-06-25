/usr/local/bin/python2.6 -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'y=list(x); y.sort()'
/usr/local/bin/python2.6 -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'x.sort()'
/usr/local/bin/python2.6 -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'sorted(x)'
