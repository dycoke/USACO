#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int n; cin >> n;
	vector<int> cows(n);
	for(int& cow : cows) {
		cin >> cow;
	}
	sort(cows.begin(), cows.end(), greater<int>());
	int ans = 0;
	while(cows[ans] >= ans) {
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
