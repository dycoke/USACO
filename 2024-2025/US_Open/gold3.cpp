#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {
    int n; ll d;
    cin >> n >> d;
    int a, b;
    cin >> a >> b;
    vector<ll> m(n);
    for(ll &x : m) {
        cin >> x;
    }
    sort(m.begin(), m.end(), greater<ll>());
    ll max_moves = (a - b) * d;
    auto num_moves = [&](ll x, bool change = false) -> ll {
        ll sum = 0;
        for(int i = 0; i < a; i++) {
            ll num = min(max(0LL, x - m[i]), d);
            sum += num;
            if(change) {
                m[i] += num;
            }
        }
        return sum;
    };

    ll l = 0, r = 1e10;
    while(l < r) {
        ll x = l + (r - l + 1) / 2;
        if(num_moves(x) <= max_moves) {
            l = x;
        } else {
            r = x - 1;
        }
    }

    ll unused = max_moves - num_moves(l, true);
    assert(unused < a);
    for(int i = 0, cnt = 0; i < a && cnt < unused; i++) {
        if(m[i] == l) {
            m[i]++;
            cnt++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        m[i] %= MOD;
        ans = (ans + m[i] * m[i]) % MOD;
    }
    cout << ans << '\n';
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