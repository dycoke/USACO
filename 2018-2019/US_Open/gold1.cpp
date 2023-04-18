#include <bits/stdc++.h>
using namespace std;
const int INF = 15e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k; cin >> n >> k;
    int snakes[n];
    for(int i = 0; i < n; i++) {
        cin >> snakes[i];
    }

    int dp[n+1][k+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i <= k; i++) {
        dp[0][i] = 0;
    }

    int cur_max = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        cur_max = max(cur_max, snakes[i-1]);
        sum += snakes[i-1];
        dp[i][k] = min(dp[i][k], cur_max*i - sum);
    }
    for(int i = 1; i <= n; i++) { 
        cur_max = 0, sum = 0;
        for(int l = i - 1; l < n; l++) {
            cur_max = max(cur_max, snakes[l]);
            sum += snakes[l];
            for(int j = k - 1; j >= 0; j--) {
                dp[l+1][j] = min(dp[l+1][j], dp[i-1][j+1] + cur_max*(l-i+2) - sum);
            }
        }
    }
    cout << dp[n][0] << '\n';
    return 0;
}