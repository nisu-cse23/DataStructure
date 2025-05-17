
#include <iostream>
#include <vector>

using namespace std;

int colorGraph(const vector<vector<int>>& graph, int totalVertices) {
    vector<int> color(totalVertices, -1); // -1 means no color assigned
    vector<bool> usedColors(totalVertices, false);// To track used colors
    color[0] = 0; // First vertex gets color 0

    // Loop for all other vertices
    for (int current = 1; current < totalVertices; current++) {
        // Mark colors of adjacent vertices as used
        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (color[neighbor] != -1) {
                usedColors[color[neighbor]] = true;
            }
        }

        // Find the first available color
        int newColor = 0;
        for (int i = 0; i < totalVertices; i++) {
            if (!usedColors[i]) {
                newColor = i;
                break;
            }
        }

        color[current] = newColor; // Assign the selected color

        // Reset usedColors for the next vertex
        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (color[neighbor] != -1) {
                usedColors[color[neighbor]] = false;
            }
        }
    }

    // Find the highest color number used (without using max_element)
    int highestColor = color[0];
    for (int i = 1; i < totalVertices; i++) {
        if (color[i] > highestColor) {
            highestColor = color[i];
        }
    }

    // Print the color of each vertex
    cout << "\nColor of each vertex:\n";
    for (int i = 0; i < totalVertices; i++) {
        cout << "Vertex " << i << " --> Color " << color[i] << endl;
    }

    return highestColor + 1; // Chromatic number = max color + 1
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v) using 0-based indexing:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    int chromaticNumber = colorGraph(graph, n);

    cout << "\nChromatic number: " << chromaticNumber << endl;

    return 0;
}
