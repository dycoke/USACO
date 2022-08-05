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
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> cows(n);
	for(int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}

	vector<pair<int, int>> points;
	sort(cows.begin(), cows.end());
	for(int i = 0; i < 4; i++) {
		points.push_back(cows[i]);
	}
	for(int i = n - 1; i >= n - 5; i--) {
		points.push_back(cows[i]);
	}
	sort(cows.begin(), cows.end(), cmp);
	for(int i = 0; i < 4; i++) {
		points.push_back(cows[i]);
	}
	for(int i = n - 1; i >= n - 5; i--) {
		points.push_back(cows[i]);
	}
	int ans = INT_MAX;
	for(int i = 0; i < 14; i++) {
		for(int j = i + 1; j < 15; j++) {
			for(int k = j + 1; k < 16; k++) {
				int mxx = 0, mxy = 0, mnx = 40001, mny = 40001;
				for(int l = 0; l < n; l++) {
					if(cows[l] != points[i] && cows[l] != points[j] && cows[l] != points[k]) {
						mxx = max(mxx, cows[l].first);
						mxy = max(mxy, cows[l].second);
						mnx = min(mnx, cows[l].first);
						mny = min(mny, cows[l].second);
					}
				}
				ans = min(ans, (mxx - mnx) * (mxy - mny));
			}
		}
	}

	cout << ans << '\n';
	return 0;
}