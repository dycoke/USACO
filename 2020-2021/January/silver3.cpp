#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	bool odd1 = 0;
	vector<array<int, 2>> columns(n), rows(n);
	for(int i = 0; i < n; i++) {
		bool odd2 = 0;
		for(int j = 0; j < n; j++) {
			int a; cin >> a;
			columns[j][odd1] += a;
			rows[i][odd2] += a;
			odd2 ^= 1;
		}
		odd1 ^= 1;
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < n; i++) {
		ans1 += max(columns[i][0], columns[i][1]);
	}
	for(int i = 0; i < n; i++) {
		ans2 += max(rows[i][0], rows[i][1]);
	}
	cout << max(ans1, ans2) << '\n';
	return 0;
}