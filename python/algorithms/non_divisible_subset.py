#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the nonDivisibleSubset function below.
def nonDivisibleSubset(k, S):
    if k == 1:
        return 1
    
    rs = [a % k for a in S]
    r_d = {}
    for i in range(k):
        r_d[i] = 0
    for r in rs:
        r_d[r] += 1
    
    set_count = 0
    for r in range(int(k / 2) + 1):
        if r == 0:
            set_count += min(r_d[r], 1)
        elif (r + r) == k:
            set_count += min(r_d[r], 1)
        else:
            set_count += max(r_d[r], r_d[k - r])
    return set_count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    S = list(map(int, input().rstrip().split()))

    result = nonDivisibleSubset(k, S)

    fptr.write(str(result) + '\n')

    fptr.close()
