#include <bits/stdc++.h>
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
    int n, q;
    cin >> n >> q;
    vector<ll> inv(n + 1);
    for(int i = 1; i <= n; i++) {
        inv[i] = bexp(i, MOD - 2);
    }
    vector<int> c(q), v(q);
    int mx = 0;
    for(int i = 0; i < q; i++) {
        cin >> c[i] >> v[i];
        mx = max(mx, v[i]);
        if(mx > v[i] + 1) {
            cout << 0 << '\n';
            return;
        }
    }
    vector<array<ll, 2>> dp(q);
    dp[0][0] = 1;
    dp[0][1] = 0;

    auto calc = [&inv](int n, int l) -> ll {
        ll a = 1, b = 1, res = 1;
        for(int k = 1; k <= n; k++) {
            // update a and b
            a = a * (n - k + 1) % MOD * inv[k] % MOD;
            b = b * (k + l) % MOD * inv[k] % MOD;
            res = (res + a * b) % MOD;
            // cout << "calc: " << a << ' ' << b << '\n';
        }
        // cout << '\n';
        return res;
    };
    for(int i = 1; i < q; i++) {
        int l = v[i] - v[i - 1];
        int nn = c[i] - c[i - 1] - 1;
        if(v[i] > v[i - 1]) {
            // do 1 -> 0
            dp[i][0] = (dp[i][0] + dp[i - 1][1] * calc(nn, l - 1)) % MOD;
        }
        if(v[i] >= v[i - 1]) {
            // do 1 -> 1
            dp[i][1] = (dp[i][1] + dp[i - 1][1] * calc(nn, l)) % MOD;
            // do 0 -> 0
            dp[i][0] = (dp[i][0] + dp[i - 1][0] * calc(nn, l)) % MOD;
        }
        // do 0 -> 1
        dp[i][1] = (dp[i][1] + dp[i - 1][0] * calc(nn, l + 1)) % MOD;
        dp[i][1] = (dp[i][1] - dp[i][0] + MOD) % MOD;
    }
    cout << (dp[q - 1][0] + dp[q - 1][1]) % MOD << '\n';
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