#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
    result.push_back(node);  // Add node after visiting all neighbors (postorder)
}

vector<int> topologicalSort(int N, const vector<vector<int>>& adj) {
    vector<bool> visited(N, false);
    vector<int> result;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, result);
        }
    }
    reverse(result.begin(), result.end());  // Reverse to get correct topological order
    return result;
}

int main() {
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    vector<vector<int>> adj(N);

    cout << "Enter edges (U V) directed from U to V (0-based indexing):\n";
    for (int i = 0; i < E; i++) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
    }

    vector<int> topoOrder = topologicalSort(N, adj);

    cout << "Topological sorting of the graph:\n";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
