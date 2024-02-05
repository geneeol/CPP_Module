#!/usr/bin/env python

import random
import sys

def generate_unique_numbers(n, start, end):
    if n > (end - start + 1):
        raise ValueError("Range too small for the number of unique numbers requested")
    numbers = random.sample(range(start, end + 1), n)
    return numbers

if __name__ == "__main__":
    n = int(sys.argv[1])
    start = int(sys.argv[2])
    end = int(sys.argv[3])
    unique_numbers = generate_unique_numbers(n, start, end)
    print(' '.join(map(str, unique_numbers)))