#!/usr/bin/python

import sys

# Check for too few arguments
if len(sys.argv) < 2:
    sys.exit("File name required")

# Check for too many arguments
elif len(sys.argv) > 2:
    sys.exit("Too many arguments")

# Get filepath from arguments
else:
    filePath = sys.argv[1]

# Read file contents into string
with open(filePath, 'r') as file:
    numString = file.read()

# Remove newlines from string
numString = numString.translate(None, "\n")
