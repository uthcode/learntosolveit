#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import shutil

def copyfiles(from_dir, to_dir):
    files_in_dir = unicode(from_dir)
    files_to_dir = unicode(to_dir)
    for root, dirs, files in files_in_dir:
        for curr_file in files:
            path_of_curr_file = os.path.join(root, curr_file)
            shutil.copy(path_of_curr_file, files_to_dir)

