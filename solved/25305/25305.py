import sys
input = sys.stdin.readline

N, K = map(int, input().strip().split())
score = list(map(int, input().strip().split()))
score.sort()
print(score[-K])