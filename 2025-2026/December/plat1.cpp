#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {
    int n; cin >> n;
    vector<array<ll, 2>> a(n);
    for(int i = 0; i < n; i++) {
        ll h, p, s;
        cin >> h >> p >> s;
        ll g = max(gcd(h - s, p - s), 1LL);
        a[i] = {(h - s) / g, (p - s) / g};
    }

    auto cross = [&](array<ll, 2> x, array<ll, 2> y) -> ll {
        return x[0] * y[1] - y[0] * x[1];
    };

    auto dot = [&](array<ll, 2> x, array<ll, 2> y) -> ll {
        return x[0] * x[0] + y[0] * y[0];
    };

    auto half = [&](array<ll, 2> x) -> bool {
        return (x[1] == 0 && x[0] >= 0) || x[1] > 0;
    };

    sort(a.begin(), a.end(), [&](array<ll, 2> x, array<ll, 2> y) {
        bool hx = half(x), hy = half(y);
        if(hx != hy) {
            return hx > hy;
        }
        ll cr = cross(x, y);
        if(cr != 0) return cr > 0;
        ll dx = x[0] * x[0] + x[1] * x[1];
        ll dy = y[0] * y[0] + y[1] * y[1];
        return dx < dy;
    });

    vector<array<ll, 2>> p;
    vector<int> cnt;
    int zero = 0;
    for(int i = 0; i < n; i++) {
        if(a[i][0] == 0 && a[i][1] == 0) {
            zero++;
        } else if(p.empty() || p.back()[0] != a[i][0] || p.back()[1] != a[i][1]) {
            p.push_back(a[i]);
            cnt.push_back(1);
        } else {
            cnt.back()++;
        }
    }
    int m = p.size();
    p.resize(2 * m);
    cnt.resize(2 * m);
    for(int i = m; i < 2 * m; i++) {
        p[i] = p[i - m];
        cnt[i] = cnt[i - m];
    }

    ll res = 0;



    for(int i = 0, j = 0, tot = 0; i < m;) {
        while(j < i + m && cross(p[i], p[j]) >= 0) {
            tot += cnt[j++];
        }

        res += 1LL * cnt[i] * (tot - cnt[i]) * (tot - cnt[i] - 1) / 2;
        res += 1LL * (tot - cnt[i]) * cnt[i] * (cnt[i] - 1) / 2;
        res += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;

        if(cross(p[i], p[j - 1]) == 0 && j > m) {
            int s = cnt[j - 1];
            res -= 1LL * cnt[i] * s * (s - 1) / 2;
            res -= 1LL * cnt[i] * (cnt[i] - 1) * s / 2;
        }
        tot -= cnt[i++];
    }


    res += 1LL * zero * (zero - 1) * (zero - 2) / 6;
    res += 1LL * zero * (zero - 1) / 2 * (n - zero);
    res += 1LL * zero * (n - zero) * (n - zero - 1) / 2;

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6 - res;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("out.txt", "w", stdout);

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}