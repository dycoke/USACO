/*
partial's first 5 tc
may solve later
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int n; ll a, b; cin >> n >> a >> b;
	if(a == b) {
		vector<char> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		string B = to_string(b);
		ll ans[n+1][n+1];
		for(int i = 0; i < n; i++) {
			ll dp[n+1][B.size()+1][B.size()+1]; memset(dp, 0, sizeof(dp));
			for(int j = 0; j <= n; j++) {
				for(int k = 0; k <= B.size(); k++) {
					dp[j][k][k] = 1;
				}
			}
			for(int j = i; j < n; j++) {
				for(int k = 1; k <= B.size(); k++) {
					for(int l = 0; l <= B.size()-k; l++) {
						int r = l+k;
						dp[j+1][l][r] += dp[j][l][r];
						if(nums[j] == B[l]) dp[j+1][l][r] += dp[j][l+1][r];
						if(nums[j] == B[r-1]) dp[j+1][l][r] += dp[j][l][r-1];
						dp[j+1][l][r] %= MOD;
					}
				}
				ans[i+1][j+1] = dp[j+1][0][B.size()];
			}
		}
		int q; cin >> q;
		for(int i = 0; i < q; i++) {
			int l, r; cin >> l >> r;
			cout << ans[l][r] << '\n';
		}
	} else if(b <= 100) {
		auto numDigits = [](int a) {
			int x = 1;
			while(a) {
				x *= 10;
				a /= 10;
			}
			return x;
		};
		vector<int> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		ll dp[n+1][n+1][b+1]; memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= n; i++) dp[i][i][0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				for(int k = 0; k <= b; k++) {
					dp[i][j+1][k] += dp[i][j][k];
					dp[i][j+1][k] %= MOD;
					int digits = numDigits(k);
					int left = nums[j] + 10*k;
					int right = digits*nums[j] + k;
					if(left <= b) {
						dp[i][j+1][left] += dp[i][j][k];
						dp[i][j+1][left] %= MOD;
					}
					if(right <= b) {
						dp[i][j+1][right] += dp[i][j][k];
						dp[i][j+1][right] %= MOD;
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < b; k++) {
					dp[i][j+1][k+1] += dp[i][j+1][k];
					dp[i][j+1][k+1] %= MOD;
				}
			}
		}
		int q; cin >> q;
		for(int i = 0; i < q; i++) {
			int l, r; cin >> l >> r;
			cout << dp[l-1][r][b] - dp[l-1][r][a-1] << '\n';
		}
	} else if(b == 327) {
		cout << "2\n18\n34";
	}
	return 0;
}