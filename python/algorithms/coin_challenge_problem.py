
import math
import os
import random
import re
import sys

# Complete the getWays function below.    
def get_ways(n, c):
    '''
    - Arguments:
        -n (int): number
        -c (list(int)): denominations
    '''
    # matrix of shape (n + 1, len(c))
    counts = [[-1 for x in range(len(c))] for y in range(n + 1)]
    for j in range(len(c)):
        counts[0][j] = 1
    for i in range(c[0], n + 1):
        for j in range(len(c)):
            if counts[i][j] == -1:
                lower_n_count = 0
                lower_c_count = 0
                if i >= c[j]:
                    lower_n_count = max(counts[i - c[j]][j], 0)
                if j >= 1:
                    lower_c_count = max(counts[i][j - 1], 0)
                counts[i][j] = lower_n_count + lower_c_count
    return counts[n][len(c) - 1]

if __name__ == '__main__':
    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    c = list(map(int, input().rstrip().split()))

    # Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    ways = get_ways(n, c)

    print(ways)