from math import gcd
import sys
input = sys.stdin.readline

N = int(input().strip())
tree = [int(input().strip()) for _ in range(N)]
distance = [tree[i] - tree[i-1] for i in range(1, N)]
min_gap = gcd(distance[1], distance[0])
for i in range(2, len(distance)):
    min_gap = gcd(min_gap, distance[i])
add_tree = sum((d // min_gap) - 1 for d in distance)
print(add_tree)