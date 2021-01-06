#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
The copyfiles function from source to destination, if the source and
destination was unicode filenames. Remember to declaring the encoding used by
the program if using Python2.
"""


import os
import shutil

def copyfiles(from_dir, to_dir):
    files_in_dir = str(from_dir)
    files_to_dir = str(to_dir)
    for root, dirs, files in files_in_dir:
        for curr_file in files:
            path_of_curr_file = os.path.join(root, curr_file)
            shutil.copy(path_of_curr_file, files_to_dir)

