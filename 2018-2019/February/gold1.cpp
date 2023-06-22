#include <bits/stdc++.h>
using namespace std;
template <class T> class BIT {
  private:
	int size;
	vector<T> bit;

  public:
	BIT(int size) : size(size), bit(size + 2) {}

    void change(int ind, int val) {
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] ^= val; }
	}

	T query(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total ^= bit[ind]; }
		return total;
	}
};

const int MAX_N = 1e5;
const int LOG = 17;
vector<int> adj[MAX_N];
int up[MAX_N][LOG], depth[MAX_N];
int timer = 0, start[MAX_N], stop[MAX_N];


void dfs(int u, int p) {
    start[u] = timer++;
    for(int& v: adj[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for(int i = 1; i < LOG; i++) {
                up[v][i] = up[up[v][i-1]][i-1];
            }
            dfs(v, u);
        }
    }
    stop[u] = timer;
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--) {
        if(k & (1 << i)) {
            a = up[a][i];
        }
    }
    if(a == b) return a;

    for(int i = LOG-1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);

    int n, q; cin >> n >> q;
    int e[n];
    for(int i = 0; i < n; i++) {
        cin >> e[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    BIT<int> bit(n);
    for(int i = 0; i < n; i++) {
        bit.change(start[i], e[i]);
        bit.change(stop[i], e[i]);
    }

    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        if(c == 1) {
            int a, k; cin >> a >> k;
            --a;
            bit.change(start[a], e[a]^k);
            bit.change(stop[a], e[a]^k);
            e[a] = k;
        } else {
            int a, b; cin >> a >> b;
            int lca = get_lca(--a, --b);
            cout << (bit.query(start[a]) ^ bit.query(start[b]) ^ e[lca]) << '\n';
        }
    }
}