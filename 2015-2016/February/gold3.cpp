#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int a, b, n, m;
    cin >> a >> b >> n >> m;

    int fx[n+1], fy[m+1];
    for(int i = 0; i < n; i++) {
        cin >> fx[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> fy[i];
    }
    sort(fx, fx+n);
    sort(fy, fy+m);
    fx[n] = a;
    fy[m] = b;

    int prevx = 0, prevy = 0;
    vector<array<int, 3>> edges;
    for(int i = 0; i <= n; i++) {
        int q = fx[i] - prevx;
        prevx = fx[i];
        for(int j = 1; j <= m; j++) {
            edges.push_back({i + (j-1)*(n+1), i + j*(n+1), q});
        }
    }
    for(int i = 0; i <= m; i++) {
        int q = fy[i] - prevy;
        prevy = fy[i];
        for(int j = 1; j <= n; j++) {
            edges.push_back({j + i*(n+1), j + i*(n+1) - 1, q});
        }
    }

    sort(edges.begin(), edges.end(), [](array<int, 3> a, array<int, 3> b) { return a[2] < b[2]; });
    ll ans = 0;
    int num_components = (n+1)*(m+1);
    DSU dsu((n+1)*(m+1));
    for(auto& edge: edges) {
        if(num_components == 1) break;
        if(dsu.unite(edge[0], edge[1])) {
            num_components--;
            ans += (ll) edge[2];
        }
    }
    cout << ans << '\n';
    return 0;
}