#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5;
const int MOD = 1e9 + 7;

int n;

struct Node {
	ll val;
    ll lzadd, lzmul;
	Node() {};
} tree[N << 2];

void pushup(int p) {
	tree[p].val = tree[(p << 1)].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
    if(tree[p].lzmul != 1) {
        tree[(p << 1)].lzmul = tree[(p << 1)].lzmul * tree[p].lzmul % MOD;
        tree[(p << 1)].lzadd = tree[(p << 1)].lzadd * tree[p].lzmul % MOD;
        tree[(p << 1)].val = tree[(p << 1)].val * tree[p].lzmul % MOD;
        tree[(p << 1) + 1].lzmul = tree[(p << 1) + 1].lzmul * tree[p].lzmul % MOD;
        tree[(p << 1) + 1].lzadd = tree[(p << 1) + 1].lzadd * tree[p].lzmul % MOD;
        tree[(p << 1) + 1].val = tree[(p << 1) + 1].val * tree[p].lzmul % MOD;
        tree[p].lzmul = 1;
    }
    if(tree[p].lzadd != 0) {
        tree[(p << 1)].lzadd = (tree[(p << 1)].lzadd + tree[p].lzadd) % MOD;
        tree[(p << 1)].val = (tree[(p << 1)].val + tree[p].lzadd) % MOD;
        tree[(p << 1) + 1].lzadd = (tree[(p << 1) + 1].lzadd + tree[p].lzadd) % MOD;
        tree[(p << 1) + 1].val = (tree[(p << 1) + 1].val + tree[p].lzadd) % MOD;
        tree[p].lzadd = 0;
    }
	return;
}

void build(int p, int l = 1, int r = n) {
	tree[p].lzadd = 0;
    tree[p].lzmul = 1;
	if(l == r) {
		tree[p].val = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build((p << 1), l, mid);
	build((p << 1) + 1, mid + 1, r);
	pushup(p);
	return;
}

void add(int p, int a, int b, ll val, int l = 1, int r = n) {
	if(a > r || b < l) return;
	if(a <= l && r <= b) {
        tree[p].val = (tree[p].val + val) % MOD;
		tree[p].lzadd = (tree[p].lzadd + val) % MOD;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add((p << 1), a, b, val, l, mid);
	add((p << 1) + 1, a, b, val, mid + 1, r);
	pushup(p);
	return;
}

void mul(int p, int a, int b, ll val, int l = 1, int r = n) {
	if(a > r || b < l) return;
	if(a <= l && r <= b) {
        tree[p].val = (tree[p].val * val) % MOD;
		tree[p].lzmul = (tree[p].lzmul * val) % MOD;
        tree[p].lzadd = (tree[p].lzadd * val) % MOD;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	mul((p << 1), a, b, val, l, mid);
	mul((p << 1) + 1, a, b, val, mid + 1, r);
	pushup(p);
	return;
}

ll query(int p, int a, int l = 1, int r = n) {
    if(l == r) {
        return tree[p].val;
    }
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
    if(a <= mid) {
        return query((p << 1), a, l, mid);
    } else {
        return query((p << 1) + 1, a, mid + 1, r);
    }
}

struct DSU {
	std::vector<int> e;
	DSU(int N) { e = std::vector<int>(N, -1); }
	
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
    int m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u - 1, v - 1, i + 1});
    }
    DSU dsu(n);
    vector<int> b(n), e(n), nxt(n, -1), in(n);
    vector<ll> p10(n + 1);
    p10[0] = 1;
    for(int i = 0; i < n; i++) {
        b[i] = i;
        e[i] = i;
        p10[i + 1] = p10[i] * 10 % MOD;
    }
    vector<array<int, 3>> order;
    for(auto [u, v, w] : edges) {
        if(!dsu.same_set(u, v)) {
            order.push_back({u, v, w});
            u = dsu.get(u);
            v = dsu.get(v);
            nxt[e[u]] = b[v];
            dsu.unite(u, v);
            int x = dsu.get(u);
            b[x] = b[u];
            e[x] = e[v];
        }
    }
    for(int i = 0; i < n; i++) {
        b[i] = i;
        e[i] = i;
        if(nxt[i] != -1)
            in[nxt[i]]++;
    }
    vector<int> ind(n);
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) {
            for(int j = 1; i >= 0; i = nxt[i], j++) {
                ind[i] = j;
            }
            break;
        }
    }
    build(1);

    dsu = DSU(n);
    assert(order.size() == n - 1);
    for(auto [u, v, w] : order) {
        int szu = dsu.size(u), szv = dsu.size(v);
        ll x = query(1, ind[u]), y = query(1, ind[v]);
        u = dsu.get(u);
        v = dsu.get(v);
        assert(ind[e[u]] - ind[b[u]] == szu - 1);
        mul(1, ind[b[u]], ind[e[u]], 10);
        mul(1, ind[b[v]], ind[e[v]], 10);
        add(1, ind[b[u]], ind[e[u]], w);
        add(1, ind[b[v]], ind[e[v]], w);
        mul(1, ind[b[u]], ind[e[u]], p10[szv - 1]);
        mul(1, ind[b[v]], ind[e[v]], p10[szu - 1]);
        add(1, ind[b[u]], ind[e[u]], y);
        add(1, ind[b[v]], ind[e[v]], x);
        dsu.unite(u, v);
        int xx = dsu.get(u);
        b[xx] = b[u];
        e[xx] = e[v];
    }
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = query(1, ind[i]);
        cout << ans[i] << '\n';
    }
    // cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}