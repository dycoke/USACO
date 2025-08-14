#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;

const string moo = "MOO";

struct state {
    array<array<vector<ll>, 3>, 3> dp;

    state(int n) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = vector<ll>(n);
            }
        }
    }
    state() {}
};

vector<ll> merge(const vector<ll> &a, const vector<ll> &b) {
    vector<ll> ans;
    for(int i = 0, j = 0;;) {
        if(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        } else if(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        } else if(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        } else {
            break;
        }
    }
    return ans;
}

void ckmin(vector<ll> &a, vector<ll> &b) {
    for(int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }
    for(int i = 1; i < b.size(); i++) {
        b[i] += b[i - 1];
    }
    if(a.size() < b.size()) {
        swap(a, b);
    }
    for(int i = 0; i < b.size(); i++) {
        a[i] = min(a[i], b[i]);
    }
    for(int i = a.size() - 1; i >= 1; i--) {
        a[i] -= a[i - 1];
    }
}

state dnq(const int L, vector<ll> &a, int l, int r) {
    // cout << "dnq: " << l << ' ' << r << '\n';
    if(r - l + 1 < 2 * L) {
        state ret;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                for(int k = l + i; k <= r - j - L + 1; k++) {
                    if(ret.dp[i][j].empty()) {
                        ret.dp[i][j].push_back(INF);
                    }
                    ret.dp[i][j].back() = min(ret.dp[i][j].back(), a[k]);
                }
            }
        }
        return ret;
    }
    int m = (l + r) >> 1;
    state x = dnq(L, a, l, m);
    state y = dnq(L, a, m + 1, r);
    // combine shit now
    state res;
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            res.dp[i][j] = merge(x.dp[i][0], y.dp[0][j]);
            for(int k = 1; k < L; k++) {
                vector<ll> temp = merge(x.dp[i][k], y.dp[L - k][j]);
                temp = merge(temp, {a[m - k + 1]});
                ckmin(res.dp[i][j], temp);
            }
        }
    }
    return res;
}

void solve() {
    int l, n;
    cin >> l >> n;
    string s; cin >> s;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> a(n - l + 1);
    for(int i = 0; i <= n - l; i++) {
        for(int j = 0; j < l; j++) {
            if(moo[j] != s[i + j]) {
                a[i] += c[i + j];
            }
        }
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    state ans = dnq(l, a, 0, n - 1);
    ll cur = 0;
    assert(ans.dp[0][0].size() == n / l);
    for(ll x : ans.dp[0][0]) {
        cur += x;
        cout << cur << '\n';
    }
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