import sys

input = sys.stdin.readline
N = int(input())
stairs = [0] * (N + 1)
for i in range(N):
    n = int(input())
    stairs[i] = n
