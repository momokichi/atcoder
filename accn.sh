#!/bin/bash

if [ $# -ne 1 ]; then
    echo "error: missing required argument" 1>&2
    exit 1
fi
acc new $1
cd $1/a
code main.cpp