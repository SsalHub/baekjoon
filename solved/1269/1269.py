import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split())
A = set(map(int, input().strip().split()))
B = set(map(int, input().strip().split()))
print(len(A.difference(B) | B.difference(A)))