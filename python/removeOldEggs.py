#!/usr/bin/python2.5

import sys
import os
import glob
import shutil
from optparse import OptionParser

__version__ = 0.1
__author__ = 'Jose Galvez'

site_package = '/usr/lib/python2.5/site-packages'
easy_install_pth = 'easy-install.pth'


def my_help(*args):
	print '''
removeOldEggs is inteneded to help you remove old python eggs from
your site-packages folder.  
To use the program:
	1) edit this file and make sure that "site_package" and 
	   "easy_install_pth" are correct
	2) make the program executable (chmod 777 removeOldEggs)
	3) execute > removeOldEggs
	4) alternativly site_pakage may be overrun at run time with the 
option site=<path to folder to scan for eggs and easy_install.pth file>

The program scans your site-packages folder (or site folder)for eggs and 
compairs it with the easy-install.pth file to see which eggs may need 
removal. You will then be given the oportunity to remove the eggs you want to 
remove
'''
	sys.exit(0)


def parseOptions():
	parser = OptionParser()
	parser.add_option('-s', '--site',
			dest='site',
			help='Over ride default site_package with SITE')
	parser.add_option('-a', '--about',
			action='callback', callback=my_help,
			help='about this program')
	(options, args) = parser.parse_args()
	if options.site:
		if os.path.exists(options.site):
			site_package = options.site
		else:
			print '\n===============\nsite must exsit\n===============\n'
			my_help()
		if not os.path.exists(os.path.join(site_package, easy_install_pth)):
			print '\n===============\n%s must be in the %s folder\n===============\n' \
			% (easy_install_pth, site_package)
			my_help()



def main():
	os.chdir(site_package)
	eggs = glob.glob('*.egg')
	eggList = [x.strip().strip('./') for x in 
			file(easy_install_pth, 'r').readlines()
			if x.startswith('./')]
	oldEggs = []
	for egg in eggs:
		if egg not in eggList:
			oldEggs.append(egg)
	if not oldEggs:
		print 'No eggs need removal'
	for oldEgg in oldEggs:
		remove = raw_input('%s not in %s, Remove (Y/n)' % (oldEgg, easy_install_pth))
		if remove.lower() in ['y', '']:
			wholeEgg = os.path.join(site_package, oldEgg)
			print 'Tring to remove %s' % oldEgg
			if os.path.isfile(wholeEgg):
				os.remove(wholeEgg)
			if os.path.isdir(wholeEgg):
				shutil.rmtree(wholeEgg)
		else:
			print 'Leaving %s inplace' % oldEgg

if __name__ == '__main__':
	parseOptions()
	main()
