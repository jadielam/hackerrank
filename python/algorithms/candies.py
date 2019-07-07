#!/bin/python3

import math
import os
import random
import re
import sys

def candies_computation(ratings, candies):
    changes = False

    for i in range(0, len(candies)):
        if i != 0:
            if ratings[i] > ratings[i - 1]:
                if candies[i] <= candies[i - 1]:
                    candies[i] = candies[i - 1] + 1
                    changes = True
        if i != len(ratings) - 1:
            if ratings[i] > ratings[i + 1]:
                if candies[i] <= candies[i + 1]:
                    candies[i] = candies[i + 1] + 1
                    changes = True
    
    return changes

# Complete the candies function below.
def candies(n, ratings):
    candies = [1] * len(ratings)
    changes = True
    
    while changes:
        candies_computation(ratings, candies)
        changes = candies_computation(ratings[::-1], candies[::-1])
    return sum(candies)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
