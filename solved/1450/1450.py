from itertools import combinations
import bisect
import sys

input = sys.stdin.readline
N, C = map(int, input().strip().split())
item = list(map(int, input().strip().split()))

left_item, right_item = item[:N//2], item[N//2:]
left_sum, right_sum = [], []
for i in range(len(left_item) + 1):
    for c in combinations(left_item, i):
        left_sum.append(sum(c))
for i in range(len(right_item) + 1):
    for c in combinations(right_item, i):
        right_sum.append(sum(c))
right_sum.sort()
count = 0
for ls in left_sum:
    if C < ls:
        continue
    max_w = C - ls
    idx = bisect.bisect_right(right_sum, max_w)
    count += idx
print(count)