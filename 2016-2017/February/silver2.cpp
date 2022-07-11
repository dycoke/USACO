//when their solution is worse than yours lmao
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n, k, b;
	cin >> n >> k >> b;
	vector<int> prefix(n+1);
	for(int i = 0; i < b; i++) {
		int a; cin >> a;
		prefix[a]++;
	}
	for(int i = 1; i <= n; i++) {
		prefix[i] = prefix[i] + prefix[i-1];
	}
	int ans = n;
	for(int i = k; i <= n; i++) {
		ans = min(ans, (prefix[i] - prefix[i-k]));
	}
	cout << ans << '\n';
	return 0;
}
