#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	int c, n; cin >> c >> n;
	multiset<int> chickens;
	vector<pair<int, int>> cows(n);
	for(int i = 0; i < c; i++) {
		int chicken; cin >> chicken;
		chickens.insert(chicken);
	}
	for(pair<int, int>& cow : cows) {
		cin >> cow.first >> cow.second;
	}
	sort(cows.begin(), cows.end(), cmp);
	int ans = 0;
	for(int i = 0; i < n && !chickens.empty(); i++) {
		auto pt = chickens.lower_bound(cows[i].first);
		if(pt == chickens.end()) {
			continue;
		}
		if(*pt <= cows[i].second) {
			ans++;
			chickens.erase(pt);
		}
	}
	cout << ans << '\n';
	return 0;
}
