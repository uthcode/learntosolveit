

import zipfile

def read_zip(filename):
    with zipfile.ZipFile(filename, 'r') as z:
        for zip_filename in z.namelist():
            print("File: {0}".format(zip_filename))
            _bytes = z.read(zip_filename)
            print("has {0} bytes".format(len(_bytes)))

def main():
    filename = 'sample.zip'
    read_zip(filename)

if __name__ == '__main__':
    main()
