#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    auto ckmax = [](ll& a, ll b) -> void {
        a = max(a, b);
    };
    int n, m; cin >> n >> m;
    ll w[m]; int l[m], r[m];
    ll mx[n+1][n+1][n];
    memset(mx, 0, sizeof(mx));
    for(int i = 0; i < m; i++) {
        cin >> w[i] >> l[i] >> r[i];
        --l[i];
        for(int j = l[i]; j < r[i]; j++) {
            ckmax(mx[l[i]][r[i]][j], w[i]);
        }
    }
    for(int len = 1; len <= n; len++) {
        for(int i = 0, j = len; j <= n; i++, j++) {
            for(int k = i; k < j; k++) {
                ckmax(mx[i][j][k], mx[i+1][j][k]);
                ckmax(mx[i][j][k], mx[i][j-1][k]);
            }
        }
    }
    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int len = 1; len <= n; len++) {
        for(int i = 0, j = len; j <= n; i++, j++) {
            //iterate on seperator
            for(int k = i; k < j; k++) {
                ckmax(dp[i][j], dp[i][k] + dp[k][j]);
            }
            //iterate on the missing element
            for(int k = i; k < j; k++) {
                ckmax(dp[i][j], dp[i][k] + dp[k+1][j] + mx[i][j][k]);
            }
        }
    }
    cout << dp[0][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
/*
dp[l][r] = maximum weight of a group that only earts here
need a ds that allows us to query the max segment with one end in [a, b] and another in [c, d]
nvm 300^3 is not 270m LOL
*/