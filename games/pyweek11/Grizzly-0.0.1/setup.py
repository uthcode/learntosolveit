import os

# usage: python setup.py command
#
# sdist - build a source dist
# py2exe - build an exe
# py2app - build an app
# cx_freeze - build a linux binary (not implemented)
#
# the goods are placed in the dist dir for you to .zip up or whatever...


APP_NAME = 'Grizzly'
DESCRIPTION = open('README.txt').read()
CHANGES = open('CHANGES.txt').read()
TODO = open('TODO.txt').read()



METADATA = {
    'name':APP_NAME,
    'version':          '0.0.1',
    'license':          'short_licence',
    'description':      '',
    'author':           '',
    #'author_email':     '',
    'url':              'http://pyweek.org/e/Grizzly',
    'classifiers':      [
            'Development Status :: 4 - Beta',
            'Intended Audience :: End Users/Desktop',
            'Intended Audience :: Information Technology',
            'License :: OSI Approved :: BSD License',
            'Operating System :: OS Independent',
            'Programming Language :: Python :: 2',
            'Programming Language :: Python :: 2.5',
            'Programming Language :: Python :: 2.6',
            'Programming Language :: Python :: 2.7',
            'Programming Language :: Python :: 3',
            'Programming Language :: Python :: 3.0',
            'Programming Language :: Python :: 3.1',
            'Programming Language :: Python :: 3.2',
            'Topic :: Software Development :: Libraries :: pygame',
            'Topic :: Games/Entertainment :: Real Time Strategy',
    ],


    'py2exe.target':'',
    #'py2exe.icon':'icon.ico', #64x64
    'py2exe.binary':APP_NAME, #leave off the .exe, it will be added
    
    'py2app.target':APP_NAME,
    'py2app.icon':'icon.icns', #128x128
    
    #'cx_freeze.cmd':'~/src/cx_Freeze-3.0.3/FreezePython',
    'cx_freeze.cmd':'cxfreeze',
    'cx_freeze.target':'%s_linux' % APP_NAME,
    'cx_freeze.binary':APP_NAME,
    }
    
files_to_remove = ['tk84.dll',
                    '_ssl.pyd',
                    'tcl84.dll',
                    os.path.join('numpy','core', '_dotblas.pyd'),
                    os.path.join('numpy', 'linalg', 'lapack_lite.pyd'),
]


directories_to_remove = [os.path.join('numpy', 'distutils'),
                         'distutils',
                         'tcl',
]


cmdclass = {}
PACKAGEDATA = {
    'cmdclass':    cmdclass,

    'package_dir': {'Grizzly': 'Grizzly',
                   },
    'packages': ['Grizzly',
                ],
    'scripts': ['scripts/Grizzly'],
}

PACKAGEDATA.update(METADATA)


from distutils.core import setup, Extension
try:
    import py2exe
except:
    pass

import sys
import glob
import os
import shutil

try:
    cmd = sys.argv[1]
except IndexError:
    print 'Usage: setup.py install|py2exe|py2app|cx_freeze'
    raise SystemExit

# utility for adding subdirectories
def add_files(dest,generator):
    for dirpath, dirnames, filenames in generator:
        for name in 'CVS', '.svn':
            if name in dirnames:
                dirnames.remove(name)

        for name in filenames:
            if '~' in name: continue
            suffix = os.path.splitext(name)[1]
            if suffix in ('.pyc', '.pyo'): continue
            if name[0] == '.': continue
            filename = os.path.join(dirpath, name)
            dest.append(filename)

# define what is our data
_DATA_DIR = os.path.join('Grizzly', 'data')
data = []
add_files(data,os.walk(_DATA_DIR))




#data_dirs = [os.path.join(f2.replace(_DATA_DIR, 'data'), '*') for f2 in data]
data_dirs = [os.path.join(f2.replace(_DATA_DIR, 'data')) for f2 in data]
PACKAGEDATA['package_data'] = {'Grizzly': data_dirs}





data.extend(glob.glob('*.txt'))
#data.append('MANIFEST.in')
# define what is our source
src = []
add_files(src,os.walk('Grizzly'))
src.extend(glob.glob('*.py'))




# build the sdist target
if cmd not in "py2exe py2app cx_freeze".split():
    f = open("MANIFEST.in","w")
    for l in data: f.write("include "+l+"\n")
    for l in src: f.write("include "+l+"\n")
    f.close()
    
    setup(**PACKAGEDATA)

# build the py2exe target
if cmd in ('py2exe',):
    dist_dir = os.path.join('dist',METADATA['py2exe.target'])
    data_dir = dist_dir
    
    src = 'run_game.py'
    dest = METADATA['py2exe.binary']+'.py'
    shutil.copy(src,dest)
    
    setup(
        options={'py2exe':{
            'dist_dir':dist_dir,
            'dll_excludes':['_dotblas.pyd','_numpy.pyd', 'numpy.linalg.lapack_lite.pyd', 'numpy.core._dotblas.pyd'] + files_to_remove,
            'excludes':['matplotlib', 'tcl', 'OpenGL'],
            'ignores':['matplotlib', 'tcl', 'OpenGL'],
            'bundle_files':1,
            }},
#        windows=[{
       console=[{
            'script':dest,
            #'icon_resources':[(1,METADATA['py2exe.icon'])],
            }],
        )

# build the py2app target
if cmd == 'py2app':
    dist_dir = os.path.join('dist',METADATA['py2app.target']+'.app')
    data_dir = os.path.join(dist_dir,'Contents','Resources')
    from setuptools import setup

    src = 'run_game.py'
    dest = METADATA['py2app.target']+'.py'
    shutil.copy(src,dest)

    APP = [dest]
    DATA_FILES = []
    OPTIONS = {'argv_emulation': True, 
               #'iconfile':METADATA['py2app.icon']
              }

    setup(
        app=APP,
        data_files=DATA_FILES,
        options={'py2app': OPTIONS},
        setup_requires=['py2app'],
    )

# make the cx_freeze target
if cmd == 'cx_freeze':
    app_dist_dir = METADATA['cx_freeze.target'] + "_" + METADATA['version']
    dist_dir = os.path.join('dist', app_dist_dir)
    data_dir = dist_dir

    modules_exclude = "tcl,tk"
    cmd_args = (METADATA['cx_freeze.cmd'], dist_dir, METADATA['cx_freeze.binary'], modules_exclude)
    sys_cmd = '%s --install-dir=%s --target-name=%s --exclude-modules=%s run_game.py' % cmd_args
    print sys_cmd
    os.system(sys_cmd)

    import shutil
    if os.path.exists(os.path.join(data_dir, "tcl")): 
        shutil.rmtree( os.path.join(data_dir, "tcl") )
    if os.path.exists(os.path.join(data_dir, "tk")): 
        shutil.rmtree( os.path.join(data_dir, "tk") )



# recursively make a bunch of folders
def make_dirs(dname_):
    parts = list(os.path.split(dname_))
    dname = None
    while len(parts):
        if dname == None:
            dname = parts.pop(0)
        else:
            dname = os.path.join(dname,parts.pop(0))
        if not os.path.isdir(dname):
            os.mkdir(dname)

# copy data into the binaries 
if cmd in ('py2exe','cx_freeze','py2app'):
    dest = data_dir
    for fname in data:
        dname = os.path.join(dest,os.path.dirname(fname))
        make_dirs(dname)
        if not os.path.isdir(fname):
            #print (fname,dname)
            shutil.copy(fname,dname)

# make a tgz files.
if cmd == 'cx_freeze':
    sys_cmd = "cd dist; tar -vczf %s.tgz %s/" % (app_dist_dir,app_dist_dir)  
    os.system(sys_cmd)


# remove files from the zip.
if 0 and cmd in ('py2exe'):
    import shutil

    #shutil.rmtree( os.path.join('dist') )
    #shutil.rmtree( os.path.join('build') )


    os.system("unzip dist/library.zip -d dist\library")

    for fn in files_to_remove:
        os.remove( os.path.join('dist', 'library', fn) )


    for d in directories_to_remove:
        if os.path.exists( os.path.join('dist', 'library', d) ):
            shutil.rmtree( os.path.join('dist', 'library', d) )

    os.remove( os.path.join('dist', 'library.zip') )


    os.chdir("dist")
    os.chdir("library")

    os.system("zip -r -9 ..\library.zip .")

    os.chdir("..")
    os.chdir("..")
