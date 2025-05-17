#include <iostream>
#include <vector>
using namespace std;

void inputEdges(int n, int e, vector<vector<int>>& mat) {
    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
}

void printMatrix(int n, const vector<vector<int>>& mat) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, e;
    cout << "Number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    inputEdges(n, e, mat);
    printMatrix(n, mat);

    return 0;
}
