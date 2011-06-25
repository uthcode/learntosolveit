#!/usr/bin/env python
#
# Copyright 2007 Doug Hellmann.
#
#
#                         All Rights Reserved
#
# Permission to use, copy, modify, and distribute this software and
# its documentation for any purpose and without fee is hereby
# granted, provided that the above copyright notice appear in all
# copies and that both that copyright notice and this permission
# notice appear in supporting documentation, and that the name of Doug
# Hellmann not be used in advertising or publicity pertaining to
# distribution of the software without specific, written prior
# permission.
#
# DOUG HELLMANN DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
# INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN
# NO EVENT SHALL DOUG HELLMANN BE LIABLE FOR ANY SPECIAL, INDIRECT OR
# CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
# OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
# NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
# CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

"""Create test data for the glob examples.

"""

__module_id__ = "$Id: glob_maketestdata.py 1995 2009-03-01 21:09:26Z dhellmann $"
#end_pymotw_header

import os

def mkfile(filename):
    print filename
    f = open(filename, 'wt')
    try:
        f.write('\n')
    finally:
        f.close()

print 'dir'
os.mkdir('dir')

mkfile('dir/file.txt')
mkfile('dir/file1.txt')
mkfile('dir/file2.txt')
mkfile('dir/filea.txt')
mkfile('dir/fileb.txt')

print 'dir/subdir'
os.mkdir('dir/subdir')

mkfile('dir/subdir/subfile.txt')
