#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int inf = 2000000000;
const long long infLL = 900000000000000000;
const int mx = 1e5+123;

ll dist[mx];
vector<pair<long long,long long>>adj[mx];
void dijkstra(long long source,long long node)
{
    for(int i=0;i<=node;i++) dist[i] = inf;///Initialization
    dist[source] = 0;///initializing source distance

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0,source});///pushing source in queue


    while(!pq.empty())
    {
        int u = pq.top().second;
        long long curDis = pq.top().first;

        pq.pop();

        if(dist[u]<curDis) continue;

        for(auto it : adj[u])
        {
            int v =it.first;
            long long w = it.second;
            if(curDis+w<dist[v])
            {
                dist[v] = curDis+w;
                pq.push({dist[v],v});
            }
        }

    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node,edge;
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    dijkstra(0,node);

    for(int i=0;i<node;i++) cout<<dist[i]<<" ";

    cout<<endl;

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
