#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(const vector<vector<int>>& Adj, int V) {
    vector<int> indegree(V, 0);

    // Calculate indegree of each node
    for (int u = 0; u < V; u++) {
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j];
            indegree[v]++;
        }
    }

    queue<int> q;
    // Enqueue all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Decrement indegree of neighbors
        for (int j = 0; j < Adj[node].size(); j++) {
            int nbr = Adj[node][j];
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    if ((int)topoOrder.size() != V) {
        cout << "Graph contains a cycle!\n";
        return {};
    }

    return topoOrder;
}

int main() {
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    vector<vector<int>> Adj(N);
    cout << "Enter edges (U V) directed from U to V, 0-based indexing:\n";
    for (int i = 0; i < E; i++) {
        int U, V;
        cin >> U >> V;
        Adj[U].push_back(V);
    }

    vector<int> result = topologicalSort(Adj, N);

    if (!result.empty()) {
        cout << "Topological sorting of the graph: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
