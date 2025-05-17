#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(const vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int i = 0; i < graph[u].size(); ++i) {
                    int v = graph[u][i];
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);
    graph[0]={1,3};
    graph[1]={0,2};
    graph[2]={1,3};
    graph[3]={0,2,4};
    graph[4]={3};

    if (isBipartite(graph, n)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is NOT bipartite." << endl;
    }

    return 0;
}
