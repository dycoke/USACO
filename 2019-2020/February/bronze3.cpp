#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> cows(n);
	iota(cows.begin(), cows.end(), 0);
	for(int i = 0; i < 2; i++) {
		int l, r; cin >> l >> r;
		reverse(cows.begin() + l - 1, cows.begin() + r);
	}
	vector<int> ans(n, -1);
	for(int i = 0; i < n; i++) {
		if(ans[i] != -1)
			continue;
		vector<int> cycle;
		int j = cows[i];
		cycle.push_back(j);
		while(j != i) {
			j = cows[j];
			cycle.push_back(j);
		}
		for(int j = 0; j < cycle.size(); j++) {
			ans[cycle[j]] = cycle[(j + k) % cycle.size()];
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] + 1 << '\n';
	}
	return 0;
}