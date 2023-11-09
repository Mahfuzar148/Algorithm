#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p, ans;

    for (int i = 0; i < n; i++) {
        int start, ends;
        cin >> start >> ends;
        p.push_back({ends, start});
    }

    sort(p.begin(), p.end());
    ans.push_back({p[0].first, p[0].second});

     for(int i=1;i<n;i++)
     {
          if (p[i-1].first <= p[i].second) {
            ans.push_back({p[i].first, p[i].second});

        }

     }
    if (ans[ans.size()-1].first<=p[n-1].second) {
        ans.push_back({p[n-1].first, p[n-1].second});
    }

    for (auto it : ans) {
        cout << it.second << " " << it.first << endl;
    }

    return 0;
}
