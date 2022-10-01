#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> intervals(n);
	for(int i = 0; i < n; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	vector<ll> start(2*m+1), stop(2*m+1);
	vector<ll> a(m+1);
	vector<ll> b(m+1);
	for(int i = 0; i < n; i++) {
		a[intervals[i].first]++;
		b[intervals[i].second]++;
	}
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= m; j++) {
			start[i+j] += a[i] * a[j];
			stop[i+j] += b[i] * b[j];
		}
	}
	ll ans = 0;
	for(int i = 0; i <= 2*m; i++) {
		ans += start[i];
		cout << ans << '\n';
		ans -= stop[i];
	}
}
