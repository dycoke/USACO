#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);

	int n; cin >> n;
	int fields[2][n];
	for(int i = 0; i < n; i++) {
		cin >> fields[0][i];
	}
	for(int i = 0; i < n; i++) {
		cin >> fields[1][i];
	}
	int dp[n+1][n+1]; memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(i < n && j < n) {
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
				if(abs(fields[0][i] - fields[1][j]) <= 4) {
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
				}
			}
			if(i < n) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j < n) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
		}
	}
	cout << dp[n][n];
    return 0;
}