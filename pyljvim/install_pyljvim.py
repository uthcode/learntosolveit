'''
Name: install_pyljvim.py
Purpose: Installs the VIM Plugin for Livejournal implemented using Python.
License: GNU GPL v2.

Author: O.R.Senthil Kumaran <orsenthil@gmail.com>
LiveJournal: http://phoe6.livejournal.com
'''
import os
import sys
import fileinput
import shutil
import time
from ConfigParser import ConfigParser

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
    shutil.copyfile('src'+os.sep+'pyljpost.py','src'+os.sep+'pyljpost-orig.py')
    for k,v in settings.items():
      for line in fileinput.input('src' + os.sep+'pyljpost.py',inplace=1):
        print line.replace(k.strip(),v.strip()),
    return

def copyVimfiles(settings):
    '''Copy vim files to the vim location.'''
    vim_location = settings['VIM']
    if not os.path.exists(vim_location):
        raise OSError("%s does not exists" % vim_location)
    else:
        vim_syntax = os.path.join(vim_location, 'syntax')
        vim_macros = os.path.join(vim_location, 'macros')
        vim_templates = os.path.join(vim_location, 'templates')
    shutil.copy('syntax' + os.sep + 'lj.vim', settings['VIM']+ os.sep + 'syntax')
    shutil.copy('macros' + os.sep + 'pyljpost.vim',settings['VIM'] + os.sep + 'macros')
    if not os.path.exists(settings['VIM'] + os.sep + 'templates'):
        os.mkdir(settings['VIM'] + os.sep + 'templates')
    shutil.copy('templates' + os.sep + 'standard',settings['VIM'] + os.sep + 'templates')
    shutil.copy('templates' + os.sep + 'extended',settings['VIM'] + os.sep + 'templates')

def copyLJpythonfile(settings):
    """Copy the LiveJournal Poster to Python"""
    if sys.platform == 'win32':
        shutil.move('src' + os.sep + 'pyljpost.py',settings['PYTHON'] + os.sep + 'Tools' + os.sep + 'Scripts')
    elif sys.platform == 'linux2':
        shutil.move('src' + os.sep + 'pyljpost.py',settings['PYTHON'])
    os.rename('src'+os.sep+'pyljpost-orig.py','src'+os.sep+'pyljpost.py')

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
      pyljpost_path = convertToVimPath(settings['PYTHON'] + os.sep + 'Tools' + os.sep + 'Scripts')
      pyljpost_templates_path = convertToVimPath(settings['VIM'] + os.sep + 'templates')
      appendToFile(vimrc,'let g:pyljpost_path = '+ '"'+ pyljpost_path + 'pyljpost.py'+ '"' )
      appendToFile(vimrc,'let g:pyljpost_templates_path = ' + '"'+ pyljpost_templates_path + '"')
      appendToFile(vimrc,'let g:pyljpost_encoding = "latin1"')
      appendToFile(vimrc,'let g:pyljpost_username = ' + '"'+ settings['LJ_USER'] +'"')
      appendToFile(vimrc,'let g:pyljpost_password = ' + '"' + settings['LJ_PASSWORD'] + '"')
    elif sys.platform == 'linux2':
      vimrc = '/etc/vim/vimrc'
      appendToFile(vimrc,'source ' + settings['VIM']+ os.sep +'macros' + os.sep + 'pyljpost.vim')
      pyljpost_path = settings['PYTHON'] 
      pyljpost_templates_path = settings['VIM'] + os.sep + 'templates'
      appendToFile(vimrc,'let g:pyljpost_path = '+ '"'+ pyljpost_path + 'pyljpost.py'+ '"' )
      appendToFile(vimrc,'let g:pyljpost_templates_path = ' + '"'+ pyljpost_templates_path + '"')
      appendToFile(vimrc,'let g:pyljpost_encoding = "latin1"')
      appendToFile(vimrc,'let g:pyljpost_username = ' + '"'+ settings['LJ_USER'] +'"')
      appendToFile(vimrc,'let g:pyljpost_password = ' + '"' + settings['LJ_PASSWORD'] + '"')

def main():
    """Setting up the environment and paramters"""
    settings = configParsed()
    replaceProxy(settings)
    copyVimfiles(settings)
    copyLJpythonfile(settings)
    editVimrc(settings)
    print '------------------------------'
    print 'pyljvim: The LiveJournal Plugin for VIM is installed.'
    print 'Enjoy!'
    print '------------------------------'

if __name__ == '__main__':
  main()
