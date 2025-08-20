import sys

def bfs(graph, visited, start):
    queue = [start]
    visited[start] = 1
    while queue:
        v = queue.pop(0)
        for next in graph[v]:
            if visited[next] < 0:
                queue.append(next)
                visited[next] = visited[v] + 1

def getConnets(graph):
    visited = [-1 for _ in range(len(graph))]
    connects = 0
    for v in range(1, len(graph)):
        if visited[v] < 0:
            connects += 1
            bfs(graph, visited, v)
    return connects

input = sys.stdin.readline
N, M = map(int, input().split())
graph = [set() for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].add(v)
    graph[v].add(u)
print(getConnets(graph))