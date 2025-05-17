#include <iostream>
#include <vector>
using namespace std;

// Function to build adjacency list
void buildAdjList(int n, int e, vector<vector<int>>& adj) {
    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }
}

// Function to print adjacency list
void printAdjList(int n, const vector<vector<int>>& adj) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < (int)adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, e;
    cout << "Number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);

    buildAdjList(n, e, adj);
    printAdjList(n, adj);

    return 0;
}
