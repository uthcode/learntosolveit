#!/bin/bash
svn st | sed 's/^\? \s*//' > /tmp/files
