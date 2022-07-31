#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
pair<int, int> intervals[100000];

bool works(ll d) {
	ll pos = 0;
	int cows = 0;
	for(int i = 0; i < m && cows < n; i++) {
		pos = max(pos, (ll) intervals[i].first);
		while(pos >= intervals[i].first && pos <= intervals[i].second) {
			cows++;
			pos += d;
		}
	}
	return cows >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals, intervals + m);
	ll left = 1, right = intervals[m-1].second - intervals[0].first, ans;
	// ll left = 2, right = 2;
	while(left <= right) {
		ll mid = left + (right - left)/2;
		if(works(mid)) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}