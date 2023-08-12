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
    
    int n; cin >> n;
    vector<array<int, 3>> edges;
    for(int i = 0; i < n; i++) {
        int cost; cin >> cost;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edges.push_back({--a, --b, 0});
        edges.push_back({--c, --d, 0});
        edges.push_back({a, c, cost});
    }
    sort(edges.begin(), edges.end(), [](array<int, 3> a, array<int, 3> b) {return a[2] < b[2]; });
    DSU dsu(n << 1);
    ll ans = 0; int components = n << 1;
    for(array<int, 3> edge: edges) {
        if(dsu.unite(edge[0], edge[1])) {
            ans += edge[2];
            components--;
        }
        if(!components) break;
    }
    cout << ans << '\n';
    return 0;
}