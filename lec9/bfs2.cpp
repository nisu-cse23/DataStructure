#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void BFS(char start, const unordered_map<char, vector<char>>& graph) {
    unordered_set<char> visited;
    queue<char> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " ";

        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    unordered_map<char, vector<char>> graph;
    cout << "Enter edges (u v) with characters:\n";
    for (int i = 0; i < e; i++) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // For undirected graph
    }

    char start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "BFS traversal starting from node " << start << ":\n";
    BFS(start, graph);

    return 0;
}
