/*
1. write stupid solution
2. know why solution is stupid and know to write correct solution
3. spent 30 minutes fixing stupid solution instead of rewriting
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char MX = char('z' + 1), MN = char('a' - 1);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; char x;
        cin >> u >> v >> x;
        adj[--u].push_back({--v, x});
        adj[v].push_back({u, x});
    }

    vector<int> ans(n, -1);
    queue<int> q;
    q.push(0);
    vector<char> c(n, MX), o({MX});
    vector<int> kill(n, 0);
    c[0] = MX;
    ans[0] = 0;
    int prv = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(kill[u]) {
            kill[u]--;
            continue;
        }
        if(c[u] > o[ans[u]]) {
            ans[u] = -1;
            c[u] = MX;
            continue;
        }

        for(auto [v, x] : adj[u]) {
            if(ans[v] == -1) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
            if(o.size() <= ans[u] + 1)
                o.push_back(MX);
            o[ans[u] + 1] = min(o[ans[u] + 1], x);
            if(c[v] > o[ans[v]]) {
                ans[v] = ans[u] + 1;
                kill[v]++;
                q.push(v);
            }
            if(ans[u] + 1 == ans[v]) {
                c[v] = min(c[v], x);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}