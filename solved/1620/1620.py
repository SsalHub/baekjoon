import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split())
pokemon = {}
for i in range(1, N+1):
    p = input().strip()
    pokemon[str(i)] = p
    pokemon[p] = str(i)
for _ in range(M):
    q = input().strip()
    print(pokemon[q])