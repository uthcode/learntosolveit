import os
for root, dirs, files, rootfd in os.fwalk('/home/senthil/hg/cpython/Lib/email'):
    print(root, "consumes ", end="")
    print(sum([os.fstatat(rootfd, name).st_size for name in files]),
          end="")
    print("bytes in", len(files), "non-directory files")
    if 'CVS' in dirs:
        dirs.remove('CVS')  # don't visit CVS directories
