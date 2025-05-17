
#include <bits/stdc++.h>
using namespace std;

void allTopologicalSorts(vector<vector<int>>& Adj, vector<int>& indegree, vector<bool>& visited,
                         vector<int>& current, int V)
{
    bool flag = false;
    for (int i = 1; i <= V; i++) {
        if (!visited[i] && indegree[i] == 0) {
            visited[i] = true;
            current.push_back(i);
            // Reduce indegree of neighbors using indexed loop
            for (int j = 0; j < Adj[i].size(); j++) {
                int nbr = Adj[i][j];
                indegree[nbr]--;
            }
        
            allTopologicalSorts(Adj, indegree, visited, current, V);
            visited[i] = false;
            current.pop_back();
            for (int j = 0; j < Adj[i].size(); j++) {
                int nbr = Adj[i][j];
                indegree[nbr]++;
            }

            flag = true;
        }
    }
    // If no node was picked, and current size equals number of vertices,
    // then current is a valid topological ordering
    if (!flag && (int)current.size() == V) {
        for (size_t i = 0; i < current.size(); i++) {
            cout << current[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    vector<vector<int>> Adj(N + 1);
    vector<int> indegree(N + 1, 0);

    cout << "Enter edges (U V) directed from U to V:\n";
    for (int i = 0; i < E; i++) {
        int U, V;
        cin >> U >> V;
        Adj[U].push_back(V);
        indegree[V]++;
    }

    vector<bool> visited(N + 1, false);
    vector<int> current;

    cout << "All possible topological sorts:\n";
    allTopologicalSorts(Adj, indegree, visited, current, N);

    return 0;
}
