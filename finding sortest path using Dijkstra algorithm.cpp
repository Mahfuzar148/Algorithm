#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, int dest) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);  // To store the parent of each vertex
        dist[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (!pq.empty()) {
            int u = pq.top().second;
            int curDis = pq.top().first;
            pq.pop();

            if (curDis > dist[u]) continue;

            for (auto &edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];

                if (dist[u] != INT_MAX && curDis + weight < dist[v]) {
                    dist[v] = curDis + weight;
                    parent[v] = u;  // Update the parent of vertex v
                    pq.push({dist[v], v});
                }
            }
        }

        // Trace the path from destination to source
        vector<int> path;
        int current = dest;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());  // Reverse to get the path from source to destination

        return path;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Assuming the graph is undirected
        }

        int source, destination;
        cin >> source >> destination;

        Solution obj;
        vector<int> path = obj.dijkstra(V, adj, source, destination);

        // Output the shortest path
        cout << "Shortest path from " << source << " to " << destination << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
