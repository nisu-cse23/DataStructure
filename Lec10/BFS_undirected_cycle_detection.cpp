#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
bool hasCycle = false;

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] && parent[u] != v) {
                hasCycle = true;
            }
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    graph.resize(n);
    visited.assign(n, false);
    parent.assign(n, -1);

    cout << "Enter edges (undirected, 0-based indexing):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    if (hasCycle) {
        cout << "Cycle Detected\n";
    } else {
        cout << "Cycle Not Detected\n";
    }

    return 0;
}
