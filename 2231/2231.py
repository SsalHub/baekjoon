import sys
input = sys.stdin.readline

def getDisassembleSum(N):
    v = n = N
    while 0 < n:
        v += n % 10
        n = n // 10
    return v

N = int(input().strip())
digits = 1
n = N
while 0 < n:
    n = n // 10
    digits += 1
n_begin = N - (digits * 9) if digits * 9 < N else 0
answer = -1
for i in range(n_begin, N - 1):
    n = i
    if getDisassembleSum(i) == N:
        answer = i
        break
if answer < 0:
    print(0)
else:
    print(answer)