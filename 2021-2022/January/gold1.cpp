#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int bounds[n+1]; bounds[0] = 0;
    ll dp[n+1][1001], ans = 0;
    int mn = INT_MAX;
    for(int i = 1; i <= n; i++) {
        cin >> bounds[i];
        mn = min(mn, bounds[i]);
    }
    if(n&1) {
        for(int b = 0; b <= mn; b++) {
            bounds[0] = b;
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for(int i = 1; i <= n; i++) {
                ll sum = 0;
                for(int j = 0; j < bounds[i-1] - bounds[i]; j++) {
                    sum += dp[i-1][j];
                    sum %= MOD;
                }
                for(int j = bounds[i] - b; j >= 0; j--) {
                    if(bounds[i-1] - b - j >= 0) {
                        sum += dp[i-1][bounds[i-1] - b - j];
                        sum %= MOD;
                    }
                    dp[i][j] += sum;
                    dp[i][j] %= MOD;
                }
            }
            for(int i = 0; i <= 1000; i++) {
                ans += dp[n][i];
                ans %= MOD;
            }
        }
    } else {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            ll sum = 0;
            for(int j = 0; j < bounds[i-1] - bounds[i]; j++) {
                sum += dp[i-1][j];
                sum %= MOD;
            }
            for(int j = bounds[i]; j >= 0; j--) {
                if(bounds[i-1] - j >= 0) {
                    sum += dp[i-1][bounds[i-1] - j];
                    sum %= MOD;
                }
                dp[i][j] += sum;
                dp[i][j] %= MOD;
            }
        }
        for(int i = 0; i <= 1000; i++) {
            ans += dp[n][i];
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}