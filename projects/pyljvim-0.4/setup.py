import os
import sys
import fileinput
import shutil
import time
from ConfigParser import ConfigParser
from distutils.core import setup

def appendToFile(file,content):
    """Append an Entry to file"""
    fhandle = open(file,'r+')
    filecontents = fhandle.read()
    if filecontents.find(content) > 0:
      pass
    else:
      fhandle.close()
      fhandle = open(file,'a')
      fhandle.write(content+"\n")
    fhandle.close()

def convertToVimPath(path):
    """Converts a path to vim characterized path, replaces \ with \\ """
    dircomponents = path.split(os.sep)
    dirpath = ""
    for eachvalue in dircomponents:
      dirpath = dirpath + eachvalue + os.sep + os.sep
    return dirpath

def editVimrc(settings):
    """Edit the _vimrc file to add the support for LJPost"""
    if sys.platform == 'win32':
      dircom = settings['VIM'].split(os.sep)
      vim = settings["VIM"].strip(dircom[len(dircom)-1]).strip(os.sep)
      vimrc = vim + os.sep + '_vimrc'
      appendToFile(vimrc,'source ' + settings['VIM']+ os.sep +'macros' + os.sep + 'pyljpost.vim')
      install_location = settings['PYTHON']
      if not install_location.endswith(os.sep):
          install_location = install_location + os.sep
      pyljpost_path = convertToVimPath(install_location)
      pyljpost_templates_path = convertToVimPath(settings['VIM'] + os.sep + 'templates')
      appendToFile(vimrc,'let g:pyljpost_path = '+ '"'+ pyljpost_path + 'pyljpost.py'+ '"' )
      appendToFile(vimrc,'let g:pyljpost_templates_path = ' + '"'+ pyljpost_templates_path + '"')
      appendToFile(vimrc,'let g:pyljpost_encoding = "latin1"')
      appendToFile(vimrc,'let g:pyljpost_username = ' + '"'+ settings['LJ_USER'] +'"')
      appendToFile(vimrc,'let g:pyljpost_password = ' + '"' + settings['LJ_PASSWORD'] + '"')
    elif sys.platform == 'linux2':
      vimrc = os.path.join(os.path.expanduser('~'),'.vimrc')
      appendToFile(vimrc,'source ' + settings['VIM']+ os.sep +'macros' + os.sep + 'pyljpost.vim')
      install_location = settings['PYTHON']
      if not install_location.endswith(os.sep):
          install_location = install_location + os.sep
      pyljpost_path = convertToVimPath(install_location)
      pyljpost_templates_path = settings['VIM'] + os.sep + 'templates'
      appendToFile(vimrc,'let g:pyljpost_path = '+ '"'+ pyljpost_path + 'pyljpost.py'+ '"' )
      appendToFile(vimrc,'let g:pyljpost_templates_path = ' + '"'+ pyljpost_templates_path + '"')
      appendToFile(vimrc,'let g:pyljpost_encoding = "latin1"')
      appendToFile(vimrc,'let g:pyljpost_username = ' + '"'+ settings['LJ_USER'] +'"')
      appendToFile(vimrc,'let g:pyljpost_password = ' + '"' + settings['LJ_PASSWORD'] + '"')


def configParsed():
    """Parse the Configfile.txt"""
    configparser = ConfigParser()
    configparser.read('ConfigFile.txt')
    settings = {}
    settings['USE_PROXY'] = configparser.get('PROXY','USE_PROXY')
    settings['PROXY_IP'] = configparser.get('PROXY','PROXY_IP')
    settings['PROXY_PORT'] = configparser.get('PROXY','PROXY_PORT')
    settings['PROXY_USER'] = configparser.get('PROXY','PROXY_USER')
    settings['PROXY_PASSWORD'] = configparser.get('PROXY','PROXY_PASSWORD')
    settings['VIM'] = configparser.get('LOCATION','VIM')
    settings['PYTHON'] = configparser.get('LOCATION','PYTHON')
    settings['LJ_USER'] = configparser.get('LIVEJOURNAL','LJ_USER')
    settings['LJ_PASSWORD'] = configparser.get('LIVEJOURNAL','LJ_PASSWORD')
    return settings

def replaceProxy(settings):
    '''Replace the Proxy Credential values'''
    shutil.copyfile('pyljpost.py','pyljpost-orig.py')
    for k,v in settings.items():
      for line in fileinput.input('pyljpost.py',inplace=1):
        print line.replace(k.strip(),v.strip()),
    return

if __name__ == '__main__':
    if sys.platform == 'linux2' and not os.geteuid() == 0:
        sys.exit("Please run this script as root or via sudo")
    settings = configParsed()
    replaceProxy(settings)
    vim_location = settings['VIM']
    script_install_location = settings['PYTHON']

    if not os.path.exists(script_install_location):
        raise OSError("%s does not exist." % script_install_location)

    if not os.path.exists(vim_location):
        raise OSError("%s does not exist." % vim_location)
    else:
        vim_syntax = os.path.join(vim_location, 'syntax')
        vim_macros = os.path.join(vim_location, 'macros')
        vim_templates = os.path.join(vim_location, 'templates')

    editVimrc(settings)

    setup(name='pyljvim',
          version='0.4',
          data_files = [
                        (script_install_location, ['pyljpost.py']),
                        (vim_syntax,['syntax/lj.vim']),
                        (vim_macros,['macros/pyljpost.vim']),
                        (vim_templates,['templates/standard','templates/extended'])]
          )
    shutil.move('pyljpost-orig.py','pyljpost.py')
