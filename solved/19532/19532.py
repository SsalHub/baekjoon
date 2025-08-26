import sys
input = sys.stdin.readline

A, B, C, D, E, F = map(int, input().strip().split())
for i in range(-999, 1000):
    for j in range(-999, 1000):
        if A * i + B * j == C and D * i + E * j == F:
            print(i, j)