#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void BFS(char start, const unordered_map<char, vector<char>>& graph,
         unordered_map<char, int>& level, unordered_map<char, char>& parent) {
    unordered_set<char> visited;
    queue<char> q;

    visited.insert(start);
    level[start] = 0;
    parent[start] = '\0';
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                level[neighbor] = level[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

vector<char> reconstructPath(char start, char dest, const unordered_map<char, char>& parent) {
    vector<char> path;
    char cur = dest;
    while (cur != '\0') {
        path.push_back(cur);
        cur = parent.at(cur);
    }
    reverse(path.begin(), path.end());
    if (path.front() == start)
        return path;
    return {}; // No path found
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
        graph[v].push_back(u);  // Undirected graph
    }

    char start, dest;
    cout << "Enter source node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> dest;

    unordered_map<char, int> level;
    unordered_map<char, char> parent;

    BFS(start, graph, level, parent);

    vector<char> path = reconstructPath(start, dest, parent);

    if (!path.empty()) {
        cout << "Shortest path from " << start << " to " << dest << ":\n";
        for (char c : path) cout << c << " ";
    } else {
        cout << "No path found from " << start << " to " << dest << ".";
    }

    return 0;
}
