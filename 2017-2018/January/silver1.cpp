#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> lifeguards(n);
	for(int i = 0; i < n; i++) {
		cin >> lifeguards[i].first >> lifeguards[i].second;
	}
	sort(lifeguards.begin(), lifeguards.end());
	
	int left = 0, right = 0, total = 0;
	for(int i = 0; i < n; i++) {
		if(lifeguards[i].second > right) {
			left = max(right, lifeguards[i].first);
			total += lifeguards[i].second - left;
			right = lifeguards[i].second;
		}
	}
	int alone = total; right = 0;
	lifeguards.push_back({lifeguards[n - 1].second, lifeguards[n - 1].second});
	for(int i = 0; i < n; i++) {
		int t = min(lifeguards[i].second, lifeguards[i + 1].first) - max(right, lifeguards[i].first);
		alone = min(alone, t);
		right = max(right, lifeguards[i].second);
	}
	alone = max(alone, 0);
	
	cout << total - alone << '\n';
	return 0;
}