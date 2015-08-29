#!/usr/bin/python

import sys
import os
import datetime

invocation_format = """
add_program.py language_name program_name

language_name should be one off c, java, python, ruby, scala.
program_name should be in ascii following the pattern generictype_specifictype.extension
"""

language_path = '../../languages/'
source_path = '../../source/'

def write_program_file(language, program):
  if language == 'c':
    language == 'cprogs'

  path = os.path.join(language_path, language)

  if os.path.exists(path):
    filename = os.path.join(path, program)
    with open(filename, 'w') as fhandle:
      fhandle.write('// %s - %s' % (program, str(datetime.datetime.now())))

def write_doc_file():
  pass

def update_index_file():
  pass

def main(args):
  try:
    language, program = args
  except ValueError:
    print(invocation_format)
    sys.exit(-1)

  write_program_file(language.lower(), program)

  print language, program

if __name__ == '__main__':
  main(sys.argv[1:])

