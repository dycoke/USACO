//problem is OLD SILVER (means very hard accept me mit pls)
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	int n, k;
  	cin >> n >> k;
	vector<vector<int>> prefix(2*n, vector<int>(2*n));
	for(int i = 1; i <= n; i++) {
		int x = i;
		for(int j = n-i+1; j < (n-i+1)+n; j++) {
			cin >> prefix[x][j];
			x++;
		}
	}
	for(int i = 1; i < 2*n; i++) {
		for(int j = 1; j < 2*n; j++) {
			prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
		}
	}
	int ans = 0;
	if(k >= n-1) {
		cout << (prefix[2*n - 1][2*n - 1]) << '\n';
		return 0;
		//not a hard code idk what ur on about
	}
	for(int i = k + 1; i < 2*n - k; i++) {
		for(int j = k + 1; j < 2*n - k; j++) {
			int x1 = i-k, y1 = j-k, x2 = i+k, y2 = j+k;
			ans = max(ans, (prefix[x2][y2] + prefix[x1-1][y1-1] - prefix[x2][y1-1] - prefix[x1-1][y2]));
		}
	}
	cout << ans << '\n';
	return 0;
}
