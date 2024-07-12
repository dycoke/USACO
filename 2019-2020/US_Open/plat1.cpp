#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int i2 = (MOD + 1) >> 1;

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
    int n; cin >> n;
    ll dp1[n + 1][n + 1], dp2[n + 1][n + 1];
    string grid[n];
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for(int i = 0; i <= n; i++) {
        dp1[i][0] = 1;
        dp2[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp1[i][j] = (dp1[i][j] + dp1[i-1][j]) % MOD;
            dp2[i][j] = (dp2[i][j] + dp2[i][j-1]) % MOD;
            if(grid[i-1][j-1] == '.') {
                dp1[i][j] = (dp1[i][j] + dp2[i-1][j] * i2) % MOD;
                dp2[i][j] = (dp2[i][j] + dp1[i][j-1] * i2) % MOD;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '.') cnt++;
        }
    }
    ll ans = (dp1[n][n] + dp2[n][n]) % MOD;
    cout << (ans * bexp(2, cnt) % MOD) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sprinklers2.in", "r", stdin);
    freopen("sprinklers2.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}