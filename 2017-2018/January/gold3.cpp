#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    ll dp[n+1]; memset(dp, 0, sizeof(dp));
    ll ans = 1, cur = 0;
    for(int i = 1; i <= n; i++) {
        ans *= m;
        ans %= MOD;
        cur += (m-1)*dp[i-1];
        if(i == 1) cur += m;
        cur %= MOD;
        if(i >= k) {
            cur -= (m-1)*dp[i-k];
            if(i == k) cur -= m;
            cur = (cur + MOD) % MOD;
        }

        dp[i] += cur;
        dp[i] %= MOD;
    }
    cout << (ans - dp[n] + MOD) % MOD << '\n';
    return 0;
}
/*
O(NK) too slow

s[i] = (m-1)*(sum of dp[i-c] from c = 1 to c = k-1)
s[i+1] = s[i] - dp[i-k+1] + dp[i]

sliding window?
*/