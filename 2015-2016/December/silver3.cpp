#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n, q; cin >> n >> q;
	int prefix[3][n+1];
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		for(int j = 0; j < 3; j++)
			prefix[j][i] = prefix[j][i-1];
		prefix[x-1][i]++;
	}
	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << (prefix[0][b] - prefix[0][a-1]) << " " << (prefix[1][b] - prefix[1][a-1]) << " " << (prefix[2][b] - prefix[2][a-1]) << '\n';
	}
}
