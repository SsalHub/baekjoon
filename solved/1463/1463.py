import sys
from collections import deque

input = sys.stdin.readline
N = int(input()[:-1])
queue = deque([N])
depth = {N: 0}
while queue:
	x = queue.popleft()
	if x == 1:
		break
	if x % 3 == 0 and x // 3 not in depth:
		queue.append(x // 3)
		depth[x // 3] = depth[x] + 1
	if x % 2 == 0 and x // 2 not in depth:
		queue.append(x // 2)
		depth[x // 2] = depth[x] + 1
	if x - 1 not in depth:
		queue.append(x - 1)
		depth[x - 1] = depth[x] + 1
print(depth[1])