#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int start, const vector<vector<int>>& graph, vector<int>& level, vector<int>& parent) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    level[start] = 0;
    parent[start] = -1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                level[neighbor] = level[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

vector<int> reconstructPath(int source, int dest, const vector<int>& parent) {
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    if (path.front() == source)
        return path;
    else
        return {};  // No path found
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> level(n, -1);
    vector<int> parent(n, -1);

    BFS(source, graph, level, parent);

    int destination;
    cout << "Enter destination node: ";
    cin >> destination;

    vector<int> path = reconstructPath(source, destination, parent);

    if (!path.empty()) {
        cout << "Shortest path from " << source << " to " << destination << ":\n";
        for (int node : path) {
            cout << node << " ";
        }
    } else {
        cout << "No path found from " << source << " to " << destination << ".";
    }

    return 0;
}
