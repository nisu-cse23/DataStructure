#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

unordered_map<char, int> dijkstra(
    unordered_map<char, vector<pair<char,int>>>& adj,
    char src)
{
    unordered_map<char, int> dist;
    // Initialize distances
    for (auto it = adj.begin(); it != adj.end(); ++it) {
        dist[it->first] = INF;
    }
    dist[src] = 0;

    // Min-heap {distance, node}
    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int curDist = pq.top().first;
        char node = pq.top().second;
        pq.pop();

        if (curDist > dist[node]) continue;

        for (size_t i = 0; i < adj[node].size(); ++i) {
            char neighbor = adj[node][i].first;
            int weight = adj[node][i].second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    return dist;
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    unordered_map<char, vector<pair<char,int>>> adj;

    cout << "Enter edges (U V weight), nodes are characters:\n";
    for (int i = 0; i < E; ++i) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // comment out if directed graph
    }

    char src;
    cout << "Enter source node: ";
    cin >> src;

    unordered_map<char, int> dist = dijkstra(adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (auto it = dist.begin(); it != dist.end(); ++it) {
        if (it->second == INF)
            cout << "Node " << it->first << ": Not reachable\n";
        else
            cout << "Node " << it->first << ": " << it->second << "\n";
    }

    return 0;
}
