#include <iostream>
#include <queue>
#define _VERTEX_MAX_    1001

using namespace std;

void dfs(int vlen, bool graph[][_VERTEX_MAX_], bool visited[], int vertex);
void bfs(int vlen, bool graph[][_VERTEX_MAX_], int start);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool graph[_VERTEX_MAX_][_VERTEX_MAX_] = { false };
    bool visited[_VERTEX_MAX_] = { false };
    int n, m, v;
    cin >> n >> m >> v;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    dfs(n, graph, visited, v);
    cout << "\n";
    bfs(n, graph, v);
    return 0;
}


void dfs(int vlen, bool graph[][_VERTEX_MAX_], bool visited[], int vertex)
{
    visited[vertex] = true;
    cout << vertex << ' ';
    for (int i = 1; i <= vlen; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {    
            dfs(vlen, graph, visited, i);
        }
    }
}

void bfs(int vlen, bool graph[][_VERTEX_MAX_], int start)
{
    bool visited[_VERTEX_MAX_] = { false };
    queue<int> q;
    int vertex;
    visited[start] = true;
    q.push(start);
    while (q.size())
    {
        vertex = q.front();
        q.pop();
        cout << vertex << ' ';
        for (int i = 1; i <= vlen; i++)
        {
            if (graph[vertex][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}