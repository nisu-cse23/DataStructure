#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];
bool cycleFound = false;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor);
        } else if (neighbor != parent[node]) {
            cycleFound = true;
        }
    }
}

int main() {
    int N, E;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(visited, visited + N, false);
    fill(parent, parent + N, -1);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    if (cycleFound) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle Detected\n";
    }

    return 0;
}
