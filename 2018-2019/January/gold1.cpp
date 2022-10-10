#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<array<int, 3>> relevance(n-1);
    for(int i = 0; i < n - 1; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        relevance[i] = {--a, --b, r};
    }
    vector<array<int, 3>> queries(q);
    for(int i = 0; i < q; i++) {
        int k, v; cin >> k >> v;
        queries[i] = {k, --v, i};
    }
    sort(relevance.begin(), relevance.end(), [](array<int, 3> a, array<int, 3> b) {return a[2] > b[2];});
    sort(queries.begin(), queries.end(), [](array<int, 3> a, array<int, 3> b) {return a[0] > b[0];});
    vector<int> ans(q);
    int index = 0;
    DSU dsu(n);
    for(int i = 0; i < q; i++) {
        while(index < n-1 && queries[i][0] <= relevance[index][2]) {
            dsu.unite(relevance[index][0], relevance[index][1]);
            index++;
        }
        ans[queries[i][2]] = dsu.size(queries[i][1]) - 1;
    }
    for(int& a : ans) {
        cout << a << '\n';
    }
    return 0;
}