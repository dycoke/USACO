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
    int k, n;
    ll l;
    cin >> k >> n >> l;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<ll> fct(n + 1), inv(n + 1);
    fct[0] = 1;
    for(int i = 1; i <= n; i++) {
        fct[i] = fct[i - 1] * i % MOD;
    }
    inv[n] = bexp(fct[n], MOD - 2);
    for(int i = n; i > 0; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }
    auto choose = [&](int a, int b) -> ll {
        assert(a >= b);
        return fct[a] * inv[b] % MOD * inv[a - b] % MOD;
    };
    ll ans = 1;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'O') {
            cnt++;
        } else {
            ans = (ans * choose(cnt, k)) % MOD;
            cnt -= k;
        }
    }
    cout << bexp(ans, l) << '\n';
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