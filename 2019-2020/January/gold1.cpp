#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    int moonies[n];
    vector<int> adj[n];
    int dp[n][1001];

    for(int i = 0; i < n; i++) {
        cin >> moonies[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
    }

    for(int i = 0; i < n; i++) {
        for(int t = 0; t <= 1000; t++) {
            dp[i][t] = -1;
        }
    }
    dp[0][0] = 0;
    for(int t = 0; t < 1000; t++) {
        for(int i = 0; i < n; i++) {
            if(dp[i][t] == -1) continue;
            for(int& node: adj[i]) {
                dp[node][t+1] = max(dp[node][t+1], dp[i][t] + moonies[node] - c*(2*t + 1));
            }
        }
    }

    int ans = 0;
    for(int t = 0; t <= 1000; t++) {
        ans = max(ans, dp[0][t]);
    }
    cout << ans << '\n';
}
