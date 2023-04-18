#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    pair<int, int> words[n];
    int lengths[k+1], pattern[26];
    memset(pattern, 0, sizeof(pattern));
    memset(lengths, 0, sizeof(lengths));
    for(int i = 0; i < n; i++) {
        int l, c; cin >> l >> c;
        words[i] = {l, c};
        lengths[l]++;
    }

    for(int i = 0; i < m; i++) {
        char c; cin >> c;
        pattern[c - 'A']++;
    }

    ll dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= i; j++) {
            if(i - j >= 0) {
                dp[i] += dp[i-j]*lengths[j];
                dp[i] %= MOD;
            }
        }
    }

    sort(words, words + n, [](pair<int, int> a, pair<int, int> b) {return a.second < b.second;});
    vector<int> rhymes;
    for(int i = 0; i < n;) {
        int curr = 0;
        int p = i;
        while(p < n && words[p].second == words[i].second) {
            curr += dp[k - words[p].first];
            curr %= MOD;
            p++;
        }
        rhymes.push_back(curr);
        i = p;
    }

    // cout << rhymes.size() << '\n';
    ll ans = 1;
    for(int i = 0; i < 26; i++) {
        // cout << pattern[i] << ' ';
        if(pattern[i] == 0) continue;
        ll curr = 0;
        for(int& r: rhymes) {
            curr += exp(r, pattern[i]);
            curr %= MOD;
        }
        ans *= curr;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}

/*
O(n^2)
*/