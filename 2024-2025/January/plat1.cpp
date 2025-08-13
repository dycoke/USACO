#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    ll cost[n][n], pref[n][n], ans = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
            if(cost[i][j] < 0) {
                ans -= cost[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        pref[i][i] = 0;
        for(int j = i + 1; j < n; j++) {
            pref[i][j] = pref[i][j - 1] + cost[j][i] * (cost[j][i] < 0);
        }
    }
    ll dp[n][n];
    memset(dp, 0x3f, sizeof(dp));
    for(int l = 0; l < n; l++) {
        for(int i = 0; i + l < n; i++) {
            if(l == 0) {
                dp[i][i] = 0;
                continue;
            }
            for(int j = i; j < i + l; j++) {
                ll sum = pref[i][i + l] - pref[i][j + 1];
                dp[i][i + l] = min(dp[i][i + l], dp[i][j] + dp[j + 1][i + l] + cost[i][j + 1] + sum);
            }
        }
    }
    cout << ans + dp[0][n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}