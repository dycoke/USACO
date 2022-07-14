#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k; cin >> n >> k;
	vector<int> diamonds(n);
	for(int i = 0; i < n; i++) {
		cin >> diamonds[i];
	}
	sort(diamonds.begin(), diamonds.end());

	vector<int> greater(n), fewer(n);
	int l = 0, r = 0;
	while(r < n) {
		if(diamonds[l] + k >= diamonds[r]) {
			greater[l] = fewer[r] = r - l + 1;
			r++;
		} else {
			l++;
		}
	}

	int ans = 0, mx = 0;
	for(int i = 0; i < n; i++) {
		mx = max(mx, fewer[i-1]);
		ans = max(ans, mx + greater[i]);
	}
	cout << ans << '\n';
	return 0;
}
