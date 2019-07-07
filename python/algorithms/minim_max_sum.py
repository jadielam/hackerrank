#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    min_v = min(arr)
    max_v = max(arr)
    index_min = arr.index(min_v)
    index_max = arr.index(max_v)

    min_sum = 0
    max_sum = 0
    for i in range(len(arr)):
        if i != index_max:
            min_sum += arr[i]
        if i != index_min:
            max_sum += arr[i]

    print("{} {}".format(min_sum, max_sum))

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
