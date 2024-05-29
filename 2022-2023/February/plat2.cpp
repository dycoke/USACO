#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

ll exp(ll x, ll n) {
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
    int n, m; cin >> n >> m;
    vector<ll> fct(n + 1), inv(n + 1);
    fct[0] = 1; inv[0] = 1;
    for(int i = 1; i <= n; i++) {
        fct[i] = (fct[i - 1] * i) % MOD;
        inv[i] = exp(fct[i], MOD - 2);
    }
    vector<int> cnt(1 << m);
    vector<string> opinions(m);
    for(int i = 0; i < m; i++) {
        cin >> opinions[i]; 
    }
    for(int i = 0; i < n; i++) {
        int res = 0;
        for(int j = 0; j < m; j++) {
            if(opinions[j][i] == 'H') res ^= (1 << j);
        }
        cnt[res]++;
    }
    vector<ll> ways(1 << m, 1);
    vector<vector<ll>> dp(1 << m, vector<ll>(m + 1));
    for(int i = 0; i < (1 << m); i++) {
        if(cnt[i]) {
            ll tot = 0;
            for(int j = 1; j <= cnt[i]; j++) {
                tot = (tot + fct[cnt[i]] * inv[cnt[i] - j]) % MOD;
            }
            ways[i] = tot;
            dp[i][0] = 0;
        }
    }

    ll ans = 0;
    for(int mask = 0; mask < (1 << m); mask++) {
        for(int i = 0, j = 1; j <= m; i++, j++) {
            if(mask & (1 << i)) {
                dp[mask][j] = (dp[mask][i] + dp[mask ^ (1 << i)][i]) % MOD;
            } else {
                dp[mask][j] = dp[mask][i];
            }
        }
        if(cnt[mask]) {
            ll tot = (ways[mask] * dp[mask][m] + ways[mask]) % MOD;
            ans = (ans + tot) % MOD;
            for(int i = 0; i <= m; i++) {
                dp[mask][i] = (dp[mask][i] + tot) % MOD;
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}