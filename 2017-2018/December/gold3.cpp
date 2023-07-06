#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);

	int n; ll m; 
	cin >> n >> m;
	ll haybales[n], spice[n];
	for(int i = 0; i < n; i++) cin >> haybales[i] >> spice[i];

	multiset<ll> s;
	ll sum = 0, ans = LLONG_MAX;
	int r = -1;
	for(int l = 0; l < n; l++) {
		while(r < n-1 && sum < m) {
			sum += haybales[++r];
			s.insert(spice[r]);
		}
		if(sum >= m) {
			ans = min(ans, *s.rbegin());
		}
		s.erase(s.find(spice[l]));
		sum -= haybales[l];
	}

	cout << ans << '\n';
    return 0;
}