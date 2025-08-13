#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int N = 2e5;

struct Node {
	ll val, cnt;
	Node *l, *r;

	Node(ll x) : val(x), cnt(0), l(nullptr), r(nullptr) {}
    Node(ll x, int c) : val(x), cnt(c), l(nullptr), r(nullptr) {}
	Node(Node *l1, Node *r1) {
		l = l1, r = r1;
		val = 0;
        cnt = 0;
		if (l) {
            val += l->val;
            cnt += l->cnt;
        }
		if (r) {
            val += r->val;
            cnt += r->cnt;
        }
	}
	Node(Node *cp) : val(cp->val), l(cp->l), r(cp->r) {}
};

int n;
Node *roots[N + 1];

Node *build(int l = 1, int r = n) {
	if (l == r) return new Node(0LL);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, ll val, int pos, int l = 1, int r = n) {
	if (l == r) return new Node(val, 1);
	int mid = (l + r) / 2;
	if (pos > mid)
		return new Node(node->l, update(node->r, val, pos, mid + 1, r));
	else return new Node(update(node->l, val, pos, l, mid), node->r);
}

ll query(Node *node, int k, int l = 1, int r = n) {
    // cout << l << ' ' << r << ' ' << k << '\n';
    if(k == 0) return 0;
    if(l == r || k == node->cnt) {
        return node->val;
    }
    int mid = (l + r) / 2;
    if(node->l->cnt < k) {
        return node->l->val + query(node->r, k - node->l->cnt, mid + 1, r);
    } else {
        return query(node->l, k, l, mid);
    }
}



void solve() {
    int q;
    cin >> n >> q;
    vector<array<ll, 3>> dat(n + 1);


    vector<ll> ans(n + 1, LLONG_MIN);
    ans[0] = ans[n] = 0;
    vector<ll> pref(n + 1, 0);
    vector<int> opt(n + 1, -1);
    opt[0] = n, opt[n] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> dat[i][0] >> dat[i][1];
        ans[0] += dat[i][0];
        ans[n] -= dat[i][1];
    }

    sort(dat.begin() + 1, dat.end(), [](array<ll, 3> a, array<ll, 3> b) {
        return a[1] < b[1];
    });

    for(int i = 1; i <= n; i++) {
        dat[i][2] = i;
    }

    sort(dat.begin() + 1, dat.end(), [](array<ll, 3> a, array<ll, 3> b) {
        if(a[0] + a[1] == b[0] + b[1]) {
            return a[0] < b[0];
        }
        return (a[0] + a[1]) < (b[0] + b[1]);
    });

    roots[n] = build();
    for(int i = n; i >= 1; i--) {
        roots[i - 1] = update(roots[i], dat[i][1], dat[i][2]);
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + dat[i][0];
    }

    auto gen = [&](auto self, int l, int r) -> void {
        if(r <= l) {
            return;
        }
        int mid = l + (r - l) / 2;
        // cout << l << ' ' << r << ' ' << mid << '\n';
        if(opt[mid] != -1) return;
        // solve for mid
        int ub = opt[l], lb = opt[r];
        for(int i = lb; i <= ub && i <= n - mid; i++) {
            ll temp = pref[i] - query(roots[i], mid);
            if(ans[mid] < temp) {
                ans[mid] = temp;
                opt[mid] = i;
            }
        }
        self(self, l, mid);
        self(self, mid, r);
    };

    gen(gen, 0, n);


    int prv = 1;
    for(int qq = 0; qq < q; qq++) {
        int k; cin >> k;
        // ll ans = -INF, cur = 0, sum = 0;

        // ans = -query(roots[0], k);
        // bool prv = false;
        // // cout << ans << ' ';
        // int opt = 0;
        // for(int i = prv; i <= n - k; i++) {
        //     cur += dat[i][0];
        //     sum = query(roots[i], k);
        //     if(ans <= cur - sum) {
        //         opt = i;
        //     }
        //     // cout << ans << ' ';
        //     ans = max(ans, cur - sum);
        // }

        // prv = opt;
        cout << ans[k] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}