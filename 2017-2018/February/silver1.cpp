/*
problem and idea were super simple
took me 20 minutes to figure out what was wrong
and notice that the answers were HUGE
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	int l, n, fjohn, bessie;
	cin >> l >> n >> fjohn >> bessie;
	vector<pair<int,int>> stops(n);
	for(int i = 0; i < n; i++) {
		cin >> stops[i].second >> stops[i].first;
	}
	int mx = 0;
	vector<int> maxed(n);
	for(int i = n-1; i >= 0; i--) {
		if(stops[i].first > mx) {
			maxed[i] = 1;
			mx = stops[i].first;
		}
	}
	ll ans = 0;
	int index = 0;
	for(int i = 0; i < n; i++) {
		if(maxed[i]) {
			ans += (ll) stops[i].first*(fjohn - bessie)*(stops[i].second - index);
			index = stops[i].second;
		}
	}
	cout << ans << '\n';
}
