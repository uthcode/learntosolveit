#!/bin/bash

# author: Duane Johnson
# email: duane.johnson@gmail.com
# date: 2008 Jun 12
# license: MIT
#
# Based on discussion at http://kerneltrap.org/mailarchive/git/2007/11/12/406496

pushd . >/dev/null

# Find base of git directory
while [ ! -d .git ] && [ ! `pwd` = "/" ]; do cd ..; done

# Show various information about this git directory
if [ -d .git ]; then
  echo "== Remote URL: `git remote -v`"

  echo "== Remote Branches: "
  git branch -r
  echo

  echo "== Local Branches:"
  git branch
  echo

  echo "== Configuration (.git/config)"
  cat .git/config
  echo

  echo "== Most Recent Commit"
  git --no-pager log --max-count=1
  echo

  echo "Type 'git log' for more commits, or 'git show' for full commit details."
else
  echo "Not a git repository."
fi

popd >/dev/null
