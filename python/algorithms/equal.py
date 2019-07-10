#!/bin/python3

import math
import os
import random
import re
import sys

def equal(conf):
    '''
    Greedy algorith that does not find optimal, but that works well in practice
    4 / 16 failed
    '''
    
    #1, 2, 5
    if conf[1:] == conf[:-1]:
        return 0
    
    conf.sort()
    
    answers = []
    for i in range(5):
        arr = conf[:]
        answer = 0
        for sidx in range(1, len(arr)):
            arr[sidx] += i
        if i == 3 or i == 4:
            answer += 2
        elif i == 1 or i == 2:
            answer += 1
        
        previous_item = arr[0]
        idx = 1
        sum_diff = 0
        
        while idx < len(arr):
            current_item = arr[idx]
            current_item += sum_diff
            if current_item != previous_item:
                diff = current_item - previous_item
                sum_diff += diff
                for a in [5, 2, 1]:
                    r = diff // a
                    answer += r
                    diff -= (a * r)
            previous_item = current_item
            idx += 1
        

        answers.append(answer)

    return min(answers)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = equal(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
