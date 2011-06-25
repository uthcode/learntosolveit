#!/usr/bin/env python2.6

# Finding Files Given a Search Path and a Pattern

import glob
import os

def all_files(pattern, search_path, pathsep = os.pathsep):
    for path in search_path.split(pathsep):
        for match in glob.glob(os.path.join(path, pattern)):
            yield match

for match in all_files('*.py', os.getcwd()):
    print(match)
