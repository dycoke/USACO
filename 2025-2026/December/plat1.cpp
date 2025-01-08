#include <iostream>
#include <vector>
#include <array>
#include <cassert>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll bexp(ll x, ll n) {
    assert(n >= 0);
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = (res * x) % MOD; }
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);

    vector<vector<array<int, 2>>> dp(k + 1, vector<array<int, 2>>(1 << k));

    for(int i = 0; i < n; i++) {
        cin >> x[i];
        dp[0][x[i]][0]++;
    }

    for(int b = 0; b < k; b++) {
        for(int j = b + 1; j >= 0; j--) {
            for(int i = 0; i < (1 << k); i++) {
                if(i & (1 << b)) {
                    if(j > 0) {
                        dp[j][i][0] = dp[j - 1][i][0];
                        dp[j][i][1] = dp[j - 1][i][1] + dp[j - 1][i][0];
                        dp[j][i][0] += dp[j - 1][i ^ (1 << b)][0];
                        dp[j][i][1] += dp[j - 1][i ^ (1 << b)][1];
                    } else {
                        dp[j][i] = {0, 0};
                    }
                } else {
                    if(j > 0) {
                        dp[j][i][0] += dp[j - 1][i ^ (1 << b)][0];
                        dp[j][i][1] += dp[j - 1][i ^ (1 << b)][1];
                    }
                }
            }
        }
    }

    vector<ll> inv(k + 1);
    for(int i = 1; i <= k; i++) {
        inv[i] = bexp(i, MOD - 2);
    }

    for(int i = 0; i < n; i++) {
        ll ans = 0;
        for(int j = 0; j <= k; j++) {
            ans = (ans + dp[j][x[i]][1] * inv[j] % MOD) % MOD;
        }
        cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while(t--) solve();
    return 0;
}