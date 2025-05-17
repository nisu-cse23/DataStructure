#include <bits/stdc++.h>
using namespace std;

void allTopologicalSorts(
    unordered_map<char, vector<char>>& Adj,
    unordered_map<char, int>& indegree,
    unordered_map<char, bool>& visited,
    vector<char>& current,
    const vector<char>& nodes)
{
    bool flag = false;

    for (char node : nodes) {
        if (!visited[node] && indegree[node] == 0) {
            visited[node] = true;
            current.push_back(node);

            for (char nbr : Adj[node]) {
                indegree[nbr]--;
            }

            allTopologicalSorts(Adj, indegree, visited, current, nodes);            visited[node] = false;
            current.pop_back();
            for (char nbr : Adj[node]) {
                indegree[nbr]++;
            }

            flag = true;
        }
    }

    if (!flag && current.size() == nodes.size()) {
        for (char c : current) {
            cout << c << " ";
        }
        cout << "\n";
    }
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    unordered_map<char, vector<char>> Adj;
    unordered_map<char, int> indegree;
    unordered_map<char, bool> visited;

    set<char> nodeSet;

    cout << "Enter edges (U V) directed from U to V, nodes are characters:\n";
    for (int i = 0; i < E; i++) {
        char U, V;
        cin >> U >> V;
        Adj[U].push_back(V);
        indegree[V]++;
        nodeSet.insert(U);
        nodeSet.insert(V);
    }

    // Initialize indegree and visited for nodes that may have zero indegree or no outgoing edges
    for (char c : nodeSet) {
        if (indegree.find(c) == indegree.end()) indegree[c] = 0;
        visited[c] = false;
    }

    vector<char> nodes(nodeSet.begin(), nodeSet.end());
    vector<char> current;

    cout << "All possible topological sorts:\n";
    allTopologicalSorts(Adj, indegree, visited, current, nodes);

    return 0;
}
