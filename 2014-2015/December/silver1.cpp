#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 40000;

vector<ll> adj[MAX_N];
void bfs(ll node, vector<ll>& visited) {
    queue<ll> q;
    q.push(node);
    visited[node] = 0;
    while(!q.empty()) {
        node = q.front(); q.pop();
        for(ll& n : adj[node]) {
            if(visited[n] == -1) {
                q.push(n);
                visited[n] = visited[node] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    ll b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    vector<ll> bessie(n, -1), elsie(n, -1), barn(n, -1);
    bfs(0, bessie);
    bfs(1, elsie);
    bfs(n-1, barn);
    ll ans = INT_MAX;
    for(ll i = 0; i < n; i++) {
        ans = min(ans, bessie[i]*b + elsie[i]*e + barn[i]*p);
    }
    cout << ans << '\n';
    return 0;
}