# Erdos-Woods-number-generator
Finds Erdos Wood's numbers.

Inspired by a Numberphile video:
https://www.youtube.com/watch?app=desktop&v=uJtxlErlx0U

## Running:
Run with 'make all'. The search and length limits can be changed in the main file.

## Overview
The algorithm searches for ranges of numbers that share prime factors with the start or end numbers of the range. Erdos Wood's numbers are then the length of these ranges. e.g. the first number is 16, which starts at 2184 and goes to 2200.
