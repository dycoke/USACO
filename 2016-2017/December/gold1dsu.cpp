#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

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
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> cows(n);
    for(pair<int, int>& cow : cows) {
        cin >> cow.first >> cow.second;
	}
    vector<array<int, 3>> edges;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			int dx = abs(cows[i].first - cows[j].first), dy = abs(cows[i].second - cows[j].second);
			edges.push_back({i, j, dx*dx + dy*dy});
		}
	}
	sort(edges.begin(), edges.end(), [](array<int, 3> a, array<int, 3> b) {return a[2] < b[2];});
	DSU dsu(n);
	for(array<int, 3> edge : edges) {
		dsu.unite(edge[0], edge[1]);
		if(dsu.size(0) == n) {
			cout << edge[2] << '\n';
			break;
		}
	}
	return 0;
}