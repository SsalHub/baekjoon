import sys

input = sys.stdin.readline
N = int(input()[:-1])
combi = [0] * 1001
combi[1] = 1
combi[2] = 2
for i in range(3, N + 1):
    combi[i] = combi[i-1] + combi[i-2]
print(combi[N] % 10007)