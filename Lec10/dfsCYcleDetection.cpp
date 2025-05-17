#include <iostream>
#include <vector>
using namespace std;

int N, E;
vector<vector<int>> Adj;
vector<bool> Visited, RecStack;
bool CycleFound = false;

void DFS(int node) {
    Visited[node] = true;
    RecStack[node] = true;

    for (int nbr : Adj[node]) {
        if (RecStack[nbr]) {
            CycleFound = true;  // Cycle detected
            return;
        }
        if (!Visited[nbr]) {
            DFS(nbr);
            if (CycleFound) return;  // Early stop if cycle found
        }
    }

    RecStack[node] = false;
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;

    Adj.assign(N, vector<int>());
    Visited.assign(N, false);
    RecStack.assign(N, false);

    cout << "Enter edges (from to):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        if (!Visited[i]) {
            DFS(i);
            if (CycleFound) break;
        }
    }

    if (CycleFound) cout << "Cycle Detected\n";
    else cout << "No Cycle Detected\n";

    return 0;
}
