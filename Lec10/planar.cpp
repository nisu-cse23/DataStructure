#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstring>
using namespace std;

const int MAX = 100005;
vector<int> graph[MAX];
bool visited[MAX];
int color[MAX];

// BFS to check bipartite and get all nodes in one component
pair<bool, vector<int>> bfs(int start) {
    vector<int> component;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    color[start] = 0;
    component.push_back(start);
    bool isBipartite = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                color[v] = 1 - color[u];  // alternate colors: 0,1
                component.push_back(v);
                q.push(v);
            }
            else if (color[v] == color[u]) {
                isBipartite = false;  // same color on adjacent nodes
            }
        }
    }
    return {isBipartite, component};
}

// Count edges in a component
int countEdges(const vector<int> &component) {
    unordered_set<int> nodes(component.begin(), component.end());
    int edges = 0;

    for (int u : component) {
        for (int v : graph[u]) {
            if (nodes.count(v)) edges++;
        }
    }

    return edges / 2;  // every edge counted twice
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter each edge as two node numbers :" << endl;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    bool planar = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            pair<bool, vector<int>> result = bfs(i);
            bool bipartite = result.first;
            vector<int> comp = result.second;

            int V = (int)comp.size();
            int E = countEdges(comp);

            if (V >= 3) {
                if (E > 3 * V - 6) {
                    planar = false;
                    break;
                }
                if (bipartite && E > 2 * V - 4) {
                    planar = false;
                    break;
                }
            }
        }
    }
if (planar) {
    cout << "The graph is planar." << endl;
} else {
    cout << "The graph is not planar." << endl;
}


    return 0;
}
