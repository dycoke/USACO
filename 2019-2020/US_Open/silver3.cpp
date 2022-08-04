#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> particles(n);
	for(int i = 0; i < n; i++) {
		cin >> particles[i].first >> particles[i].second;
	}
	sort(particles.begin(), particles.end(), cmp);

	vector<int> mn(n), mx(n);
	mn[0] = particles[0].second;
	for(int i = 1; i < n; i++) {
		mn[i] = min(mn[i-1], particles[i].second);
	}
	mx[n-1] = particles[n-1].second;
	for(int i = n-2; i >= 0; i--) {
		mx[i] = max(mx[i+1], particles[i].second);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += mn[i] > mx[i + 1];
	}

	cout << ans + 1 << '\n';
	return 0;
}