import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split())
S = set(input().strip() for _ in range(N))
strings = [input().strip() for _ in range(M)]
answer = 0
for s in strings:
    if s in S:
        answer += 1
print(answer)
