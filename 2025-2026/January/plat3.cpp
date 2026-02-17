#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

const int N = 2e5;
const int LOG = 18;

vector<int> adj[N];
int pp[N][LOG];
ll bb[N][LOG];
ll up[N], d[N], p[N];
ll down[N], prd[N], pprd[N], ppprd[N];
ll inv[N + 2];

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

pair<int, ll> lca(int a, int b) {
    // cout << "bye: " << a << ' ' << b << '\n';
    if(d[a] < d[b]) swap(a, b);
    int k = d[a] - d[b];
    ll sum = 0;
    for(int i = LOG - 1; i >= 0; i--) {
        if(k & (1 << i)) {
            sum = (sum + bb[a][i]) % MOD;
            a = pp[a][i];
            // cout << "hi: " << i << ' ' << a << ' ' << bb[a][i] << '\n';
        }
    }
    if(a == b) return {a, sum};
    for(int i = LOG-1; i >= 0; i--) {
        if(pp[a][i] != pp[b][i]) {
            a = pp[a][i];
            b = pp[b][i];
        }
    }
    return {pp[a][0], -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n + 1; i++) {
        inv[i] = bexp(i, MOD - 2);
    }

    d[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        adj[--p[i]].push_back(i);
        d[i] = d[p[i]] + 1;
    }

    for(int x = n - 1; x >= 0; x--) {
        if(adj[x].size() == 0) {
            up[x] = 1;
        } else {
            ll sum = 0;
            for(int v : adj[x]) {
                sum = (sum + up[v]) % MOD;
            }
            sum = (sum * inv[adj[x].size()] + 1) % MOD;
            up[x] = (d[x] + 1) * inv[d[x]] % MOD * sum % MOD;
        }
    }

    down[0] = 0;
    prd[0] = 0;
    pprd[0] = 0;

    for(int x = 0; x < n; x++) {
        ll c = adj[x].size();
        ll sum = 0;
        for(int v : adj[x]) {
            sum = (sum + up[v]) % MOD;
        }
        for(int v : adj[x]) {
            down[v] = (c + (sum - up[v] + MOD) + (c - 1) * (inv[d[v]] * pprd[x] % MOD)) % MOD;
            prd[v] = (down[v] + prd[x]) % MOD;
            pprd[v] = (d[v] * down[v] + pprd[x]) % MOD;
            ppprd[v] = (prd[v] + ppprd[x]) % MOD;
        }
    }
    pp[0][0] = 0;
    bb[0][0] = 0;
    for(int u = 1; u < n; u++) {
        pp[u][0] = p[u];
        bb[u][0] = (inv[d[u] + 1] * up[u]) % MOD;
        for(int i = 1; i < LOG; i++) {
            pp[u][i] = pp[pp[u][i - 1]][i - 1];
            bb[u][i] = (bb[u][i - 1] + bb[pp[u][i - 1]][i - 1]) % MOD;
        }
    }

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        auto [a, tem] = lca(x, y);
        if(a == x) {
            cout << (prd[y] - prd[x] + MOD) % MOD << '\n';
            continue;
        }
        
        ll part1 = (prd[y] - inv[d[a] + 1] * ppprd[a] % MOD + MOD) % MOD;
        auto [b, te] = lca(p[x], a);

        ll part2 = (te + up[x]) % MOD;
        ll ans = (part1 + part2) % MOD;
        cout << ans << '\n';
    }
    return 0;
}