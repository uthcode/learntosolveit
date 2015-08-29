#!/usr/bin/python

"""
BUGS:
    1. make cprogramming and cprogs dir into a single dir name.

"""

import os
import sys
import time

LANGUAGE_PATH = '../../languages/'
NOW_FORMAT = '%d-%m-%Y %H:%M'
PROGRAM_NAME_TEMPLATE = 'PROGRAMNAME'
SOURCE_PATH = '../../source/'
INVALID_EXIT = -1

USAGE = """
add_program.py program_name

program_name should follow pattern generic_specific.extension
"""

def _now():
    return time.strftime(NOW_FORMAT, time.localtime(time.time()))

def _comment_type(ext):
    return {
        'c': '//',
        'py': '#',
        'rb': '#',
        'java': '//',
        'scala': '//'}.get(ext, '#')

def _source_folder_name(language):
    return {
        'c': 'cprogramming',
        'py': 'python',
        'rb': 'ruby',
        'scala': 'scala',
        'java': 'java'}.get(language, '')

def _program_folder_name(language):
    return {
        'c': 'cprogs',
        'py': 'python',
        'rb': 'ruby',
        'scala': 'scala',
        'java': 'java'}.get(language, '')

def get_language_dir(language):
    return os.path.abspath(
        os.path.join(LANGUAGE_PATH, _program_folder_name(language)))

def get_source_dir(language):
    return os.path.abspath(
        os.path.join(SOURCE_PATH, _source_folder_name(language)))

def get_template_file(language):
    template_path = '../{0}_template.rst'.format(_source_folder_name(language))
    return os.path.abspath(template_path)

def create_program(filename):
    ext = filename.split('.')[1]
    with open(filename, 'w') as fh:
        fh.write('{0} {1} - {2}'.format(
            _comment_type(ext),
            os.path.basename(filename),
            _now()))

def create_source(template, filename, program):
    with open(template) as template_file:
        with open(filename, 'w') as source_file:
            for line in template_file:
                source_file.write(
                    line.replace(PROGRAM_NAME_TEMPLATE, program))

def update_index_file(filename, program):
    with open(filename, 'a') as f:
        f.write('   %s' % program)

def get_index_file(language):
    return os.path.abspath(os.path.join(get_source_dir(language), 'index.rst'))

def exit_if_not_exists(path):
    if not os.path.exists(path):
        print "{0} does not exists".format(path)
        sys.exit(-1)

def main(args):
    try:
        program, = args
    except ValueError:
        print(USAGE)
        sys.exit(-1)

    program_name, language = program.split('.')

    path = get_language_dir(language)
    exit_if_not_exists(path)
    program_file = os.path.abspath(os.path.join(path, program))
    create_program(program_file)
    print 'Created {0}'.format(program_file)

    path = get_source_dir(language)
    exit_if_not_exists(path)
    source_file = os.path.abspath(os.path.join(path, program))
    create_source(get_template_file(language), source_file, program)
    print 'Created {0}'.format(source_file)

    filename = get_index_file(language)
    exit_if_not_exists(filename)
    update_index_file(filename, program)
    print 'Updated {0}'.format(filename)

if __name__ == '__main__':
    main(sys.argv[1:])
