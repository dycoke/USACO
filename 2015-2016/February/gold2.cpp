/*
it is always optimal for one gate's cows to take up the whole room
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = (LLONG_MAX >> 1) - (1 << 20); //gives like 1m in leeway

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = LLONG_MAX;
    for(int t = 0; t < n; t++) {
        ll dp[n+1][k+1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0LL;
        ll prefix1[n+1], prefix2[n+1];
        prefix1[0] = 0LL; prefix2[0] = 0LL;
        for(int i = 0; i < n; i++) {
            prefix1[i+1] = prefix1[i] + a[i];
            prefix2[i+1] = prefix2[i] + i*a[i];
        }
        for(int i = 0; i < k; i++) {
            for(int j = n-1; j >= 0; j--) {
                for(int l = j+1; l <= n; l++) {
                    dp[l][i+1] = min(dp[l][i+1], dp[j][i] + (prefix2[l] - prefix2[j] - j*(prefix1[l] - prefix1[j])));
                }
            }
        }
        ans = min(ans, dp[n][k]);
        rotate(a, a+1, a+n);
    }
    cout << ans << '\n';
    return 0;
}