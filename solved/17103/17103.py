import sys
input = sys.stdin.readline

_MAX_ = 1000001
isprime = [True for _ in range(_MAX_)]
prime = []
isprime[0], isprime[1] = False, False
for i in range(2, int(_MAX_ ** 0.5) + 1):
    if isprime[i]:
        for j in range(i * i, _MAX_, i):
            isprime[j] = False
for i in range(2, _MAX_):
    if isprime[i]:
        prime.append(i)
T = int(input().strip())
for i in range(T):
    N = int(input().strip())
    cnt = 0
    for p in prime:
        if p > N // 2:
            break
        if isprime[N - p]:
           cnt += 1
    print(cnt) 