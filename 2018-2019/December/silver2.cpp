#include <bits/stdc++.h>
using namespace std;

bool arrive_comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.second.first < b.second.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, pair<int, int>>> arrivals(n);
	for(int i = 0; i < n; i++) {
		cin >> arrivals[i].second.first >> arrivals[i].second.second;
		arrivals[i].first = i;
	}
	sort(arrivals.begin(), arrivals.end(), arrive_comp);
	set<pair<int, pair<int, int>>> line;
	int time = 0, ans = 0, i = 0;
	while(!line.empty() || i < n) {
		if(line.empty()) {
			line.insert(arrivals[i]);
			i++;
		}
		pair<int, pair<int, int>> next = *line.begin();
		line.erase(line.begin());
		ans = max(ans, max(time - next.second.first, 0));
		time = max(time, next.second.first);
		time += next.second.second;
		while(i < n && arrivals[i].second.first <= time) {
			line.insert(arrivals[i]);
			i++;
		}
	}
	cout << ans << '\n';
	return 0;
}
