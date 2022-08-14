#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<pair<int, int>> heights(n);
	for(int i = 0; i < n; i++) {
		cin >> heights[i].second;
		heights[i].first = i;
	}
	sort(heights.begin(), heights.end(), cmp);

	set<int> cows;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		cows.insert(heights[i].first);
		auto ub = cows.upper_bound(heights[i].first);
		if(ub != cows.end()) {
			ans += *ub - heights[i].first + 1;
		}
		auto lb = cows.lower_bound(heights[i].first);
		if(lb != cows.begin()) {
			ans += heights[i].first - *(--lb) + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}