#include <bits/stdc++.h>
using namespace std;
bool ycomp (pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> cows(n);
	for(int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end(), ycomp);

	int l = 0, r = n - 1, ans = 0;
	while(l <= r) {
		if(!cows[l].first)
			l++;
		if(!cows[r].first)
			r--;
		cows[l].first--;
		cows[r].first--;
		ans = max(ans, cows[l].second + cows[r].second);
	}
	cout << ans << '\n';
}
