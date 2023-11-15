#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int inf = 2e9;
const ll infLL = 9e18;

const int mx = 1e5 + 123;
ll dist[mx];
vector<pair<int, int>> adj[mx];
int par[mx];

void dijkstra(int s, int n)
{
     for ( int i = 1; i <= n; i++ ) dist[i] = infLL;

    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        ll curDis = pq.top().first; // Corrected data type here
        pq.pop();

        if (dist[u] < curDis) // Corrected comparison here
            continue;

        for (auto v : adj[u])
        {
            if (curDis + v.second < dist[v.first])
            {
                dist[v.first] = curDis + v.second;
                par[v.first] = u;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n);

    if (dist[n] == infLL)
    {
        cout << "-1" << endl;
    }
    else
    {
        int u = n;
        vector<int> ans={n};
        while (par[u]!= 0)
        {
            ans.push_back(par[u]);
            u = par[u];
        }
        reverse(ans.begin(), ans.end());

        for (auto u : ans)
        {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
