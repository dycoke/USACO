#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);

    int n, MOD; cin >> n >> MOD;
    bool sieve[n+1]; memset(sieve, 0, sizeof(sieve));
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(!sieve[i]) {
            primes.push_back(i);
        }
        for(int j = i*i; j <= n; j += i) {
            sieve[j] = 1;
        }
    }

    ll dp[n+1]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int p: primes) {
        for(int i = n; i >= 0; i--) {
            int cur = p;
            while(i - cur >= 0) {
                dp[i] += dp[i-cur] * cur;
                dp[i] %= MOD;
                cur *= p;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}