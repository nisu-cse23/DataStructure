#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int src, const vector<vector<pair<int,int>>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int,int> current = pq.top();
        pq.pop();
        int currentDist = current.first;
        int u = current.second;

        if (currentDist > dist[u]) continue;

        // Relax all adjacent edges
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pair<int,int>>> graph(n);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w)); // For undirected graph
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist;
    dijkstra(src, graph, dist);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }

    return 0;
}
