import os
import stat

filename = 'os_stat_chmod_example.txt'

if os.path.exists(filename):
    existing_permissions = stat.S_IMODE(os.stat(filename).st_mode)
    if os.access(filename, os.X_OK):
        print 'File Exists and has execute permissions.'
        print 'Removing Execute permissions'
        new_permissions = existing_permissions ^ stat.S_IXUSR
    else:
        print 'File Exists and lacks execute permission.'
        print 'Adding Execute permissions'
        new_permissions = existing_permissions | stat.S_IXUSR
else:
    print 'Creating a file and Read, Write and Execute mode'
    f = open(filename,'wt')
    f.write('contents')
    f.close()
    new_permissions = stat.S_IWRITE| stat.S_IREAD | stat.S_IXUSR

os.chmod(filename, new_permissions)
