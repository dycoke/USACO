#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<int> berries(n);
	int maxb = 0;
	for(int i = 0; i < n; i++) {
		cin >> berries[i];
		maxb = max(maxb, berries[i]);
	}
	int ans = 0;
	for(int q = 1; q <= maxb; q++) {
		vector<int> chunks(q + 1);
		for(int i = 0; i < n; i++) {
			chunks[berries[i] % q]++;
			chunks[q] += berries[i] / q;
		}
		int num_baskets = 0, bessie = 0;
		for(int i = q; i >= 0; i--) {
			while(num_baskets < k && chunks[i]--) {
				num_baskets++;
				if(num_baskets > k/2) {
					bessie += i;
				}
			}
		}
		if(num_baskets == k) {
			ans = max(ans, bessie);
		}
	}
	cout << ans << '\n';
	return 0;
}