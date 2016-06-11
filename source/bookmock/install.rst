Installation
============

* Installing Python from Source at a custom environment.
* Using that Python to Create Virtual Environment.
* Install gnupg python at this environment.

::

    ./configure --prefix=/Users/senthilkumaran/mypythonjune10/prefix --exec-prefix=/Users/senthilkumaran/mypythonjune10/eprefix

Creating your gpg environment is required.


The interesting binaries that are installed include.

::

    $ tree -L 3
    .
    ├── eprefix
    │   ├── bin
    │   │   ├── 2to3 -> 2to3-3.6
    │   │   ├── 2to3-3.6
    │   │   ├── idle3 -> idle3.6
    │   │   ├── idle3.6
    │   │   ├── pydoc3 -> pydoc3.6
    │   │   ├── pydoc3.6
    │   │   ├── python3 -> python3.6
    │   │   ├── python3-config -> python3.6-config
    │   │   ├── python3.6
    │   │   ├── python3.6-config -> python3.6m-config
    │   │   ├── python3.6m
    │   │   ├── python3.6m-config
    │   │   ├── pyvenv -> pyvenv-3.6
    │   │   └── pyvenv-3.6
    │   ├── include
    │   │   └── python3.6m
    │   └── lib
    │       ├── libpython3.6m.a
    │       ├── pkgconfig
    │       └── python3.6
    └── prefix
        ├── bin
        │   ├── easy_install-3.6
        │   ├── pip3
        │   └── pip3.6
        ├── include
        │   └── python3.6m
        ├── lib
        │   └── python3.6
        └── share
            └── man



** Let's look at pyvenv

::

     ./eprefix/bin/pyvenv

    WARNING: the pyenv script is deprecated in favour of `python3.6 -m venv`

    usage: venv [-h] [--system-site-packages] [--symlinks | --copies] [--clear]
                [--upgrade] [--without-pip]
                ENV_DIR [ENV_DIR ...]

    venv: error: the following arguments are required: ENV_DIR


We'll install using venv module.

::

   ./eprefix/bin/python3 -m venv bookmock


We'll activate this.

::

    $ source bin/activate
    (bookmock) K2047:bookmock senthilkumaran$ pwd
    /Users/senthilkumaran/mypythonjune10/bookmock

We'll see the list of packages which are installed.

::

    $ pip list
    pip (8.1.1)
    setuptools (20.10.1)
    You are using pip version 8.1.1, however version 8.1.2 is available.
    You should consider upgrading via the 'pip install --upgrade pip' command.
    (bookmock) K2047:bookmock senthilkumaran$ pip install --upgrade pip
    Collecting pip
      Downloading pip-8.1.2-py2.py3-none-any.whl (1.2MB)
        100% |████████████████████████████████| 1.2MB 1.0MB/s
    Installing collected packages: pip
      Found existing installation: pip 8.1.1
        Uninstalling pip-8.1.1:
          Successfully uninstalled pip-8.1.1
    Successfully installed pip-8.1.2

Installing the Python Gnu PG Interface.

::

    $ pip install python-gnupg
    Collecting python-gnupg
      Downloading python-gnupg-0.3.8.tar.gz
    Installing collected packages: python-gnupg
      Running setup.py install for python-gnupg ... done
    Successfully installed python-gnupg-0.3.8

We will use a GnuPG directory.

::

    >>> gpg = gnupg.GPG(gnupghome='/Users/senthilkumaran/.gnupg')
    >>> pprint.pprint(gpg.list_keys(secret=True))
    [{'algo': '1',
      'date': '1363810076',
      'dummy': '',
      'expires': '1490040476',
      'fingerprint': 'D9E9D421EDF0D7EAF74210C95EA272FAACCC125F',
      'keyid': 'E47C4E185EAC5C19',
      'length': '2048',
      'ownertrust': '',
      'subkeys': [],
      'trust': '',
      'type': 'sec',
      'uids': ['Senthil Kumaran (Python Core Developer) <senthil@uthcode.com>']}]

Here is using GPG.

Using GPG.


::

    >>> gpg = GPG(use_agent=True)
    >>> encrypted = gpg.encrypt("mypassword", recipients='senthil@uthcode.com')
    >>> encrypted.data
    b'-----BEGIN PGP MESSAGE-----\nComment: GPGTools - https://gpgtools.org\n\nhQEMA16icvqszBJfAQgAh596HpOK07d3yiWS+MGlfTRQaDSRrTUwJEWLaIYDnD1G\nw1pkA+a0Fmwl1QyBeZLtrdzmJtolZm4YOAqDoHwVJvTnDZcbdqifcZW6/inopSk4\nckHDq8hEv4SeIkdiASUixkwOm3tW0Va0Eb++9Vu+MdykTcAX1jTHbA4Z6fwY0I2V\nTEuQKuEgUjpN+niR0AT67OCAO+qcHC0/4EwikLlAdaMxDgIyPhCLV9wGjpUEazbS\nw2R4O97BkK5uX7TtNWvvqIs0LYqnKXYdegjiKbKat8jDCEP8iFn5Z7vSgnKNA2C+\npvPy6zHKkMoExaL79AJ37VxBuir8RxKf/IdhIRJ6s9JFASk+taFqsTCVJjOOvykT\nqYevDj0CyKPHjDWa2JB4+6mlsolqzBy8nXOEM2pFQiwf2TPVB3GFKrLYSzORIyKW\nafrjD/Xq\n=lTeu\n-----END PGP MESSAGE-----\n'
    >>> decrypted = gpg.decrypt(str(encrypted))
    >>> decrypted.data
    b'mypassword'
