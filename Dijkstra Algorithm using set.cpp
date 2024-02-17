#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int inf = 2000000000;
const long long infLL = 900000000000000000;
const int mx = 1e5 + 123;

ll dist[mx];
vector<pair<long long, long long>> adj[mx];

void dijkstra(long long source, long long node) {
    for (int i = 0; i <= node; i++) dist[i] = inf; /// Initialization
    dist[source] = 0; /// initializing source distance

    set<pair<ll, ll>> st;

    st.insert({0, source});

    while (!st.empty()) {
        auto it = st.begin();
        ll curDis = it->first;
        ll u = it->second;

        st.erase(it);

        if (dist[u] < curDis) continue;

        for (auto it : adj[u]) {
            ll v = it.first;
            ll w = it.second;
            if (curDis + w < dist[v]) {
                dist[v] = curDis + w;
                st.insert({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node, edge;
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(0, node);

    for (int i = 0; i < node; i++) cout << dist[i] << " ";

    cout << endl;
    cout << dist[4] << endl;
}

/*
5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5
*/
