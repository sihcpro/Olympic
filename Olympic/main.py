#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the stringSimilarity function below.
def stringSimilarity(s):

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = stringSimilarity(s)

        fptr.write(str(result) + '\n')

    fptr.close()
