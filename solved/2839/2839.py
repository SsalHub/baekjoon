import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
# bfs
next = [3, 5]
bag = [-1] * (N + 1)
queue = deque([0])
bag[0] = 0
while queue:
    p = queue.popleft()
    for n in next:
        np = p + n
        if np <= N and bag[np] == -1:
            queue.append(np)
            bag[np] = bag[p] + 1
print(bag[N])