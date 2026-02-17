#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> g, h;
    int n; cin >> n;
    string s; cin >> s;

    g.push_back(-1), h.push_back(-1);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'G') {
            g.push_back(i);
        } else {
            h.push_back(i);
        }
    }
    g.push_back(n), h.push_back(n);
    ll ans = 0;
    for(int i = 0, j = 0; i + j < n;) {
        int prv, nxt;
        if(s[i + j] == 'G') {
            prv = g[i], nxt = g[i + 2];
            i++;
        } else {
            prv = h[j], nxt = h[j + 2];
            j++;
        }
        int l = i + j - prv - 1, r = nxt - (i + j - 1);
        // cout << l << ' ' << r << '\n';
        ans += 1LL * l * r;
        ans--;
        if(l > 1) ans--;
        if(r > 1) ans--;
    }
    cout << ans << '\n';
    return 0;
}