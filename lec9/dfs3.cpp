#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs_iterative(char start, const unordered_map<char, vector<char>>& adj) {
    unordered_set<char> visited;
    stack<char> s;
    s.push(start);

    while (!s.empty()) {
        char node = s.top();
        s.pop();

        if (visited.count(node)) continue;

        visited.insert(node);
        cout << node << " ";

        // Push neighbors directly (order may differ from recursive DFS)
        for (char neighbor : adj.at(node)) {
            if (!visited.count(neighbor)) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    unordered_map<char, vector<char>> adj;
    cout << "Enter edges (u v) with characters:\n";
    for (int i = 0; i < e; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }

    char start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS traversal starting from node " << start << ":\n";
    dfs_iterative(start, adj);

    return 0;
}
