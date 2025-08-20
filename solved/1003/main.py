from collections import deque
import sys

input = sys.stdin.readline
T = int(input())
cases = []
for _ in range(T):
    cases.append(int(input()))

for n in cases:
    dp = []
    dp.append((1, 0))
    dp.append((0, 1))
    for i in range(2, n + 1):
        dp.append((dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]))
    print(dp[n][0], dp[n][1])