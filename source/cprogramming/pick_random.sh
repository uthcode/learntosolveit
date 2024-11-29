#!/bin/sh
find . -type f -print0 -name "*.c" | xargs --null shuf -n1 -e
