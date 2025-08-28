import sys
input = sys.stdin.readline

MAX = 123456
prime = [ False, False ] + [True for _ in range(MAX * 2)]
i = 2
while i <= MAX * 2:
    if prime[i]:
        j = i * i
        while j <= MAX * 2:
            prime[j] = False
            j += i
    i += 1
while (1):
    N = int(input().strip())
    if (N == 0):
        break
    cnt = 0
    for i in range(N + 1, 2 * N + 1):
        if prime[i]:
            cnt += 1
    print(cnt)
    