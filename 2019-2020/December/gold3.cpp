#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
	
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int cost[m][m];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    
    for(int k = 0; k < m; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    ll prefix[n+1][m]; memset(prefix, 0, sizeof(prefix));
    for(int c = 0; c < m; c++) {
        for(int i = 0; i < n; i++) {
            prefix[i+1][c] = prefix[i][c] + cost[s[i] - 'a'][c];
        }
    }

    ll dp[n+1][m]; memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < m; i++) dp[0][i] = 0;
    for(int i = k; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[s[i-1] - 'a'][j]);
            for(int f = 0; f < m; f++) {
                dp[i][j] = min(dp[i][j], dp[i-k][f] + prefix[i][j] - prefix[i-k][j]);
            }
        }
    }
    ll ans = INT_MAX;
    for(int i = 0; i < m; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
    return 0;
}