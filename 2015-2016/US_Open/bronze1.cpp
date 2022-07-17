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
	int l = 0, r = 0, ans = 0;
	while(r < n) {
		if(diamonds[l] + k >= diamonds[r]) {
			ans = max(ans, r - l + 1);
			r++;
		} else {
			l++;
		}
	}
	cout << ans << '\n';
	return 0;
}
