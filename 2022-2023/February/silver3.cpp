//monkey brown monkey
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;

int n, m;
int layovers[MAX_N];

vector<array<int, 3>> adj[MAX_N];
int ans[MAX_N];

void dfs(int node, int time, bool first = 0) {
    if(ans[node] != -1 && ans[node] <= time) {
        return;
    }

    ans[node] = time;

    for(auto& neighbor: adj[node]) {
        if(neighbor[0] >= time + layovers[node] || first) {
            dfs(neighbor[1], neighbor[2]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        adj[--c].push_back({r, --d, s});
    }

    for(int i = 0; i < n; i++) {
        cin >> layovers[i];
    }
    for(int i = 0; i < n; i++) {
        ans[i] = -1;
    }
    dfs(0, 0, 1);
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}