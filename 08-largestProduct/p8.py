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

# Verify file formatting
if not numString.isdigit():
    sys.exit("Invalid file formatting")

# Loop over the valid consecutive 13 digit substring of numString
i = 0; maxProduct = 0
while i+13 <= len(numString):

    # Create a string that is a subset of the main numString
    shortStr = numString[i:i+13]

    # The shortStr must be 13 digits long
    assert len(shortStr) == 13

    # Multiply the digits in shortStr
    product = 1
    for idx, char in enumerate(shortStr):
        product *= char.int()

    # Find the largest product
    if product > maxProduct:
        maxProduct = product 
