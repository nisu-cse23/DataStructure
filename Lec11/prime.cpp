#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> &adj, vector<pair<int, int>> &mstEdges)
{
    vector<bool> visited(V, false);
    int mstWeight = 0;
    visited[0] = true;

    for (int count = 0; count < V - 1; count++)
    {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++)
        {
            if (visited[i]) 
            {
                for (auto &neighbor : adj[i])
                {
                    int adjNode = neighbor.first;
                    int weight = neighbor.second;
                    if (!visited[adjNode] && weight < minWeight)
                    {
                        minWeight = weight;
                        u = i;
                        v = adjNode;
                    }
                }
            }
        }

        // If we found a valid edge, add it to the MST
        if (u != -1 && v != -1)
        {
            mstWeight += minWeight;
            visited[v] = true;
            mstEdges.push_back({u, v}); // Record the edge in the MST
        }
    }
    return mstWeight;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    vector<pair<int, int>> mstEdges;
    int mstWeight = primMST(V, adj, mstEdges);

    cout << "\nSum of MST weights: " << mstWeight << endl;
    cout << "Edges in MST:\n";
    for (auto &edge : mstEdges)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}