from collections import deque

def dfs(graph, vertex, visited):
    visited.add(vertex)
    print(vertex, end=' ')
    for next in graph[vertex]:
        if next not in visited:
            dfs(graph, next, visited)

def bfs(graph, start):
    visited = set([start])
    queue = deque([start])
    while queue:
        vertex = queue.popleft()
        print(vertex, end=' ')
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

n, m, v = map(int, input().split())
graph = {}
for i in range(n):
    graph[i+1] = set()
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)
for key in graph:
    graph[key] = sorted(graph[key])
dfs(graph, v, set())
print('')
bfs(graph, v)