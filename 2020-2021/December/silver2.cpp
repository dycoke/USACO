#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ycmp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<vector<int>> prefix(n + 1, vector<int>(n + 1));
	vector<pair<int, int>> points(n);
	for(int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	sort(points.begin(), points.end());
	for(int i = 0; i < n; i++) {
		points[i].first = i + 1;
	}
	sort(points.begin(), points.end(), ycmp);
	for(int i = 0; i < n; i++) {
		points[i].second = i + 1;
	}
	for(int i = 0; i < n; i++) {
		prefix[points[i].first][points[i].second] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			prefix[i][j] += prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int a = min(points[i].first, points[j].first) - 1;
			int b = max(points[i].first, points[j].first) - 1;
			ans += (ll) (prefix[a + 1][j + 1] - prefix[a + 1][i])*(prefix[n][j+1] - prefix[n][i] - prefix[b][j+1] + prefix[b][i]);
		}
	}
	cout << ans + 1 << '\n';
	return 0;
}