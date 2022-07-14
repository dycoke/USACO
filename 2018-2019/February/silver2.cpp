//lmao brian dean l bozo
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	int n, k;
  	cin >> n >> k;
	vector<vector<int>> prefix(1002, vector<int>(1002));
  	for(int i = 0; i < n; i++) {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
		a++; b++; c++; d++;
    	prefix[a][b]++;
    	prefix[a][d]--;	
    	prefix[c][b]--;
    	prefix[c][d]++;
	}
	int ans = 0;
	for(int i = 1; i <= 1000; i++) {
		for(int j = 1; j <= 1000; j++) {
			prefix[i][j] += (prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]);
			if(prefix[i][j] == k) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
