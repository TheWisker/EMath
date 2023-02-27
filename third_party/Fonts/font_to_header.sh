#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: no filename specified"
    exit 1
fi

filename=$(basename "$1")
xxd -i "$1" > "font-${filename}.h"