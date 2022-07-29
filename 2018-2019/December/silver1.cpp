#include <bits/stdc++.h>
using namespace std;

int n, m, c;
bool works(vector<int>& arrivals, int time) {
	int buses = 0;
	for(int i = 0; i < n; i++) {
		buses++;
		int t = i;
		while(i < n && arrivals[i] - arrivals[t] <= time && i - t + 1 <= c) {
			i++;
		}
		i--;
	}
	return buses <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	cin >> n >> m >> c;
	vector<int> arrivals(n);
	for(auto& arrival : arrivals) {
		cin >> arrival;
	}
	sort(arrivals.begin(), arrivals.end());
	int left = 0, right = arrivals[n-1] - arrivals[0], ans = 0; //spent 10 minutes figuring out why this was wrong
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(works(arrivals, mid)) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}