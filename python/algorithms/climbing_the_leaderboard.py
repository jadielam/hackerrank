#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    rankings = []
    
    scores_rankings = [1]
    for i in range(1, len(scores)):
        score = scores[i]
        if score == scores[i - 1]:
            scores_rankings.append(scores_rankings[i - 1])
        else:
            scores_rankings.append(scores_rankings[i - 1] + 1)

    s_idx = len(scores) - 1
    for a_score in alice:
        while a_score >= scores[s_idx] and s_idx >= 1:
            s_idx -= 1
        if a_score >= scores[s_idx]:
            rankings.append(scores_rankings[s_idx])
        else:
            rankings.append(scores_rankings[s_idx] + 1)
        
    return rankings


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()