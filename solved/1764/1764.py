import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split())
never_heard = set(input().strip() for _ in range(N))
never_seen = set(input().strip() for _ in range(M))
answer = sorted([p for p in never_heard if p in never_seen])
print(len(answer))
for p in answer:
    print(p)