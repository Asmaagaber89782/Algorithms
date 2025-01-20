#include <iostream>
#include <vector>
#include <limits>
#include <utility>
using namespace std;

void bellman_ford(const vector<vector<pair<int, int>>>& graph, int source) {
    const int n = graph.size();
    const int INF = numeric_limits<int>::max();
    vector<int> D(n, INF);
    D[source] = 0;

    // Relax edges n-1 times
    for (int k = 0; i < n - 1; ++k) {
        for (int u = 0; u < n; ++u) {
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (D[u] != INF && D[u] + weight < D[v]) {
                    D[v] = D[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < n; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (D[u] != INF && D[u] + weight < D[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print the distances
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << (D[i] == INF ? "INF" : to_string(D[i])) << endl;
    }
}

int main() {
    // Define the graph
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 3}},    // Node 0
        {{2, -1}, {3, 1}},   // Node 1
        {{3, 2}},            // Node 2
        {}                   // Node 3
    };
    int source_node = 0;
    bellman_ford(graph, source_node);
    return 0;
}
