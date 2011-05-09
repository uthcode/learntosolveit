#fake Makefile for Grizzly, to support the common
# ./configure;make;make install

PYTHON = python

#build: Setup setup.py
build: setup.py
	$(PYTHON) setup.py build

#install: Setup setup.py
install: setup.py
	$(PYTHON) setup.py install

#Setup:
#	$(PYTHON) configure.py

test check tests:
	$(PYTHON) run_tests.py

testall:
	python2.5 setup.py test
	python2.6 setup.py test
	python3.1 setup.py test
	make checkdocs

#docs:	install
#	cd docs/utils
#	$(PYTHON) makedocs.py

clean:
	rm -rf build dist MANIFEST .coverage
	rm -f Grizzly/*~
	rm -rf bin develop-eggs eggs parts .installed.cfg Grizzly.egg-info
	find . -name *.pyc -exec rm {} \;
	find . -name *.swp -exec rm {} \;
	$(PYTHON) setup.py clean

# push changes
push:
	#bzr push lp:Grizzly
	svn commit

# commit changes
commit:
	#bzr commit
	svn commit

#upload to pypi
upload:
	make clean
	#if you have your gpg key set up... sign your release.
	#$(PYTHON) setup.py sdist upload --sign --identity="Your Name <youremail@example.com>" 
	$(PYTHON) setup.py sdist upload

sdist:
	make clean
	make testall
	$(PYTHON) setup.py sdist

checkdocs:
	$(PYTHON) setup.py checkdocs -setuptools

showdocs:
	$(PYTHON) setup.py showdocs -setuptools

coverage:
	coverage run run_tests.py
	coverage report -m


