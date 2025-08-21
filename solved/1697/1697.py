import sys
from collections import deque

input = sys.stdin.readline
N, K = map(int, input().split())
MAX = 100001
# bfs
next = [-1, 1, 2]
visited = [-1] * MAX
if N == K:
    print(0)
else:
	queue = deque([N])
	visited[N] = 0
	while queue:
		point = queue.popleft()
		if point == K:
			break
		for dp in next:
			np = point + dp if dp != 2 else point * dp
			if 0 <= np < MAX and visited[np] == -1:
				queue.append(np)
				visited[np] = visited[point] + 1
	print(visited[K])