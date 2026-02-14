#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6, MOD = 1e9 + 7;

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

int n;

struct Node {
	ll val, lz;
	Node() {};
} tree[N << 2];

void pushup(int p) {
	tree[p].val = (tree[(p << 1)].val + tree[(p << 1) + 1].val) % MOD;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	if(tree[p].lz != 1) {
		tree[(p << 1)].lz = (tree[(p << 1)].lz * tree[p].lz) % MOD;
		tree[(p << 1) + 1].lz = (tree[(p << 1) + 1].lz * tree[p].lz) % MOD;
		tree[(p << 1)].val = (tree[(p << 1)].val * tree[p].lz) % MOD;
		tree[(p << 1) + 1].val = (tree[(p << 1) + 1].val * tree[p].lz) % MOD;
		tree[p].lz = 1;
	}
	return;
}

void build(int p, int l = 1, int r = n) {
	tree[p].lz = 1;
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

void mul(int p, int a, int b, ll val, int l = 1, int r = n) {
    // cout << "bruh1: " << p << ' ' << l << ' ' << r << '\n';
	if(a > r || b < l) return;
	if(a <= l && r <= b) {
		tree[p].val = (tree[p].val * val) % MOD;
		tree[p].lz = (tree[p].lz * val) % MOD;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	mul((p << 1), a, b, val, l, mid);
	mul((p << 1) + 1, a, b, val, mid + 1, r);
	pushup(p);
	return;
}

void idx_add(int p, int i, ll val, int l = 1, int r = n) {
    // cout << "bruh2: " << p << ' ' << l << ' ' << r << '\n';
    if(l == r) {
        tree[p].val = (tree[p].val + val) % MOD;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(p, l, mid, r);
    if(i <= mid) {
        idx_add(p << 1, i, val, l, mid);
    } else {
        idx_add((p << 1) + 1, i, val, mid + 1, r);
    }
    pushup(p);
    return;
}

ll query(int p, int a, int b, int l = 1, int r = n) {
	if(a > r || b < l) return 0;
	if(a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return (query((p << 1), a, b, l, mid) + query((p << 1) + 1, a, b, mid + 1, r)) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll d;
    cin >> n >> d;

    build(1);

    vector<ll> coach(n + 1);
    int num = 0, cur = 1;
    for(int i = 0; i < n; i++) {
        ll p; int o;
        cin >> p >> o;
        if(o == 0) {
            while(cur <= num && coach[cur] < p - d) {
                cur++;
                // cout << "stop?? " << i << '\n';
            }
            if(cur <= num) {
                mul(1, cur, num, 2);
            }
        } else {
            coach[++num] = p;
            ll val = (query(1, 1, n) + 1) % MOD;
            idx_add(1, num, val);
        }
    }

    // cout << "loop yo\n";

    ll ans = query(1, 1, n) % MOD;

    if(d == 0) {
        assert(ans == bexp(2, num) - 1);
    }
    
    cout << ans << '\n';
    return 0;
}