#!/bin/sh
find . -type f -name *.c | xargs shuf -n1 -e
