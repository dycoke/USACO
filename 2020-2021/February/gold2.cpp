#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n; cin >> n;
	int painting[n];
	for(int i = 0; i < n; i++) {
		cin >> painting[i];
	}
	int dp[n][n]; memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for(int l = 0; l < n; l++) {
		for(int i = 0; i < n - l; i++) {
			for(int j = i + 1; j <= i+l; j++) {
				dp[i][i+l] = min(dp[i][i+l], dp[i][j-1] + dp[j][i+l] - (painting[i] == painting[i+l]));
			}
		}
	}
	cout << dp[0][n-1] << '\n';
    return 0;
}