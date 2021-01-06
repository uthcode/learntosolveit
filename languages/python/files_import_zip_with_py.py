import os
import sys
import tempfile
import zipfile

def create_importable_zip(filename):
    z = zipfile.ZipFile(filename, 'w')
    z.writestr('hello.py', 'def f(): return "hello world from " + __file__\n')
    z.close()

def import_and_run_module():
    import hello
    print(hello.f())

def main():
    fhandle, filename = tempfile.mkstemp('.zip')

    create_importable_zip(filename)
    sys.path.insert(0, filename)
    import_and_run_module()

    os.close(fhandle)
    os.unlink(filename)


if __name__ == '__main__':
    main()
