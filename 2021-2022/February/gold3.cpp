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
	// freopen("milkorder.in", "r", stdin);
	// freopen("milkorder.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> coords[11];
    pair<int, int> cows[n];
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coords[y].push_back({x, i});
        cows[i] = {x, y};
    }
    for(int i = 0; i <= 10; i++) {
        sort(coords[i].begin(), coords[i].end());
    }
    vector<int> coord[11], index[11];
    for(int i = 0; i <= 10; i++) {
        for(auto c: coords[i]) {
            coord[i].push_back(c.first);
            index[i].push_back(c.second);
        }
    }
    vector<array<ll, 3>> edges;
    for(int i = 0; i < n; i++) {
        for(int y = 0; y <= 10; y++) {
            auto it = lower_bound(coord[y].begin(), coord[y].end(), cows[i].first);
            ll dy = 1LL*(y - cows[i].second);
            if(cows[i].second == y) {
                int ind = it - coord[y].begin();
                if(it != coord[y].begin()) {
                    ll dx = coord[y][ind-1] - cows[i].first;
                    edges.push_back({1LL*i, 1LL*index[y][ind-1], dx*dx + dy*dy});
                }
                it++;
                if(it != coord[y].end()) {
                    ll dx = coord[y][ind+1] - cows[i].first;
                    edges.push_back({1LL*i, 1LL*index[y][ind+1], dx*dx + dy*dy});
                }
            } else {
                int ind = it - coord[y].begin();
                if(it != coord[y].begin()) {
                    ll dx = coord[y][ind-1] - cows[i].first;
                    edges.push_back({1LL*i, 1LL*index[y][ind-1], dx*dx + dy*dy});
                }
                if(it != coord[y].end()) {
                    ll dx = coord[y][ind] - cows[i].first;
                    edges.push_back({1LL*i, 1LL*index[y][ind], dx*dx + dy*dy});
                }
            }
        }
    }
    sort(edges.begin(), edges.end(), [](array<ll, 3> a, array<ll, 3> b) {return a[2] < b[2];});

    DSU dsu(n);
    ll ans = 0; int components = n;
    for(auto& e: edges) {
        if(!dsu.same_set(e[0], e[1])) {
            dsu.unite(e[0], e[1]);
            ans += e[2];
            if(--components == 0) break;
        }
    }
    cout << ans << '\n';
    return 0;
}