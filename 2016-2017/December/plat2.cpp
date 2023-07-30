#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    int n, m, t; cin >> n >> m >> t;
    int fj[n], fp[m];
    for(int i = 0; i < n; i++) {
        cin >> fj[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> fp[i];
    }
    sort(fj, fj + n); sort(fp, fp + m);
    ll dp[t+1][n+1][m+1]; memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[0][i][j] = 1;
        }
    }
    for(int k = 1; k <= t; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[k][i+1][j+1] += dp[k][i+1][j]; //skip cur cow of fj
                dp[k][i+1][j+1] += dp[k][i][j+1]; //skip cur cow of fp
                dp[k][i+1][j+1] -= dp[k][i][j]; //dont overcount
                dp[k][i+1][j+1] = (dp[k][i+1][j+1] + MOD) % MOD;
                if(fj[i] > fp[j]) {
                    dp[k][i+1][j+1] += dp[k-1][i][j]; //bring them onto the next level
                    dp[k][i+1][j+1] %= MOD;
                }
            }
        }
    }
    cout << dp[t][n][m] << '\n';
    return 0;
}