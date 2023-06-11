#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e4;

vector<pair<int, int>> adj[MAX_N];
vector<int> adj_tree[MAX_N];
int numc[MAX_N], numpass[MAX_N], dist[MAX_N], par[MAX_N];
bool visited[MAX_N];

void dfs(int node, int p=-1) {
    numpass[node] = numc[node];
    for(int& neighbor: adj_tree[node]) {
        if(neighbor == p) continue;
        dfs(neighbor, node);
        numpass[node] += numpass[neighbor];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        cin >> numc[i];
        visited[i] = 0;
        dist[i] = INT_MAX;
        par[i] = -1;
    }
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b, w});
        adj[b].push_back({a, w});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0}); dist[0] = 0;
    while(!pq.empty()) {
        int top = pq.top().second; pq.pop();
        if(visited[top]) continue;
        visited[top] = 1;
        for(auto& v: adj[top]) {
            if(dist[top] + v.second < dist[v.first]) {
                dist[v.first] = dist[top] + v.second;
                par[v.first] = top;
                pq.push({-dist[v.first], v.first});
            } else if(dist[top] + v.second == dist[v.first] && par[v.first] > top) {
                par[v.first] = top;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        adj_tree[i].push_back(par[i]);
        adj_tree[par[i]].push_back(i);
    }
    dfs(0);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, 1LL*numpass[i]*(dist[i]-t));
    }
    cout << ans << '\n';
    return 0;
}