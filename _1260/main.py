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
for i in range(1, n+1):
    graph[i] = set()
for i in range(m):
    a, b = map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)
dfs(graph, v, set())
print('')
bfs(graph, v)