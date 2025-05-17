#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int N, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(N, INF);
    dist[src] = 0;
    // Min-heap priority queue {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curDist > dist[node]) continue;

        for (int i = 0; i < (int)adj[node].size(); i++) {
            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

int main() {
    int N, E;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;

    vector<vector<pair<int,int>>> adj(N);

    cout << "Enter edges (u v weight), 0-based indexing:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove this line if the graph is directed
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist = dijkstra(N, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": Not reachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
