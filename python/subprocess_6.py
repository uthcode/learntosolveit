import subprocess
f = file('data.out','w')
ef = file('error.out','w')
cmd = '/home/senthil/uthcode/python/somebigout'
p = subprocess.Popen([cmd],stdout=f, stderr=ef,close_fds=True)
stdout,stderr = p.communicate()
f.close()
ef.close()
"""
if errcode:
    with open('error.out') as ef:
        pass
    #errmess = p.stderr.read()
with open('data.out') as f:
    pass
"""
