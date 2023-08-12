#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5;
vector<int> adj[MAX_N];

int dfs(int u, int p, int l) {
    map<int, int> lengths;
    for(int& v: adj[u]) {
        if(v != p) {
            int res = dfs(v, u, l);
            lengths[res]++;
            if(res == -1) return -1;
        }
    }
    int ret = -1;
    for(auto length: lengths) {
        if(length.first == 0) continue;
        if(length.second > lengths[l - length.first] || (l - length.first == length.first && (length.second % 2 == 1))) {
            if(ret != -1 || length.second - lengths[l - length.first] > 1) {
                return -1;
            }
            ret = length.first;
        }
    }
    if(ret == -1) return 1;
    return (ret + 1) % l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);

    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    cout << 1;
    bool bad[n]; memset(bad, 0, sizeof(bad));
    for(int i = 2; i < n; i++) {
        if((n-1) % i || bad[i]) {
            cout << 0;
            continue;
        }
        bool res = dfs(0, -1, i) == 1;
        if(res) cout << 1;
        else {
            cout << 0;
            for(int j = i; j < n; j += i) {
                bad[j] = 1;
            }
        }
    }
    cout << '\n';
    return 0;
}