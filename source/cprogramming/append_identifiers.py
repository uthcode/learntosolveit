import glob
list_of_files = glob.glob("*.rst")
for file_name in list_of_files:
    if file_name.startswith('Ex') or file_name.startswith('sec') or file_name == 'append_identifiers.py':
        continue
    progname = file_name.split('.')[0]
    with open(file_name, 'a') as fhandle:
        fhandle.write("\n\n\n")
        fhandle.write(".. seealso::\n\n")
        fhandle.write("\t* :c-suggest-improve:`%s.c`\n" % progname)
        fhandle.write("\t* :c-better-explain:`%s.rst`\n" % progname)
