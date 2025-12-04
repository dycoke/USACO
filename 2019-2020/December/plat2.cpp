#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, int val) { change(ind, val - arr[ind]); }

	void change(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T query(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

const int N = 1e5;
vector<int> adj[N];
set<int> col[N];
int in[N], out[N], sz[N], out2[N], cur;

void dfs(int u, int p) {
    out2[cur] = u;
    in[u] = cur++;
    sz[u] = 1;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    out[u] = cur;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    cur = 0;
    dfs(0, -1);
    BIT<ll> a(n + 1), b(n + 1);
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int x, c;
            cin >> x >> c;
            x--, c--;
            auto it2 = col[c].lower_bound(in[x]);
            if(it2 != col[c].begin() && in[x] < out[out2[*prev(it2)]]) {
                continue;
            }
            for(auto it = col[c].lower_bound(in[x]);
                it != col[c].end() && *it < out[x];
                it = col[c].lower_bound(in[x])) {
                
                a.change(*it, -sz[out2[*it]]);
                b.change(*it, -1);
                b.change(out[out2[*it]], 1);
                col[c].erase(it);
            }
            col[c].insert(in[x]);
            a.change(in[x], sz[x]);
            b.change(in[x], 1);
            b.change(out[x], -1);
        } else {
            int x; cin >> x;
            x--;
            ll res = (a.query(out[x] - 1) - a.query(in[x])) + 1LL * sz[x] * b.query(in[x]);
            assert(res >= 0);
            cout << res << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}