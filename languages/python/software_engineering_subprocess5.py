import subprocess
f = file('data.out','w')
ef = file('error.out','w')
cmd = '/home/senthil/uthcode/python/somebigout'
p = subprocess.Popen(cmd, shell=True, stdout=f, stderr=ef)
errcode = p.wait()
f.close()
ef.close()
if errcode:
    with open('error.out') as ef:
        pass
    #errmess = p.stderr.read()
with open('data.out') as f:
    pass
