#include <iostream>

using namespace std;

struct Edge {
    int u, v, weight;
};

class DisjointSet {
public:
    int *parent, *rank;
    
    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
        
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void kruskal(int n, int m, Edge edges[]) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    DisjointSet ds(n);

    cout << "Minimum Spanning Tree edges:\n";
    int mstWeight = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (ds.find(u) != ds.find(v)) {
            cout << u << " - " << v << " (Weight: " << weight << ")\n";
            mstWeight += weight;
            ds.unionSets(u, v);
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Edge edges[m];

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(n, m, edges);

    return 0;
}