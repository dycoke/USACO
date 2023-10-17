#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n; cin >> n;
    int ind[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int g; cin >> g;
            ind[i][g-1] = j;
        }
    }
    ll dp[1 << n][n+1];
    memset(dp, 0, sizeof(dp)); dp[0][n] = 1;
    for(int i = 0; i < (1 << n); i++) {
        //j is the node to add
        int h = -1;
        for(int j = n-1; j >= 0; j--) {
            if(i & (1 << j)) {
                h = j;
                break;
            }
        }
        for(int g = 0; g < n; g++) {
            if(!(i & (1 << g))) continue;
            for(int j = 0; j <= h; j++) {
                if(i & (1 << j)) continue;
                //find if you can give g's gift to j
                //find if you can complete the cycle
                if(ind[j][g] < ind[j][j]) {
                    assert(h >= 0 && h < n);
                    if(ind[h][j] < ind[h][h]) {
                        dp[i ^ (1 << j)][n] += dp[i][g];
                    }
                    dp[i ^ (1 << j)][j] += dp[i][g];
                }
            }
        }
        for(int j = max(h, 0); j < n; j++) {
            if(i & (1 << j)) continue;
            //start a new cycle
            dp[i ^ (1 << j)][j] += dp[i][n];
            //start and complete a new cycle
            dp[i ^ (1 << j)][n] += dp[i][n];
        }
    }
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        int g = 0, h = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'G') g ^= (1 << i);
            else h ^= (1 << i);
        }
        cout << dp[g][n] * dp[h][n] << '\n';
    }
    return 0;
}

/*
dp[mask][r][g] = number of ways s.t. there are the subset mask of nodes and r can receive and g can give
dp[mask][n][n] = loop is complete
time complexity too slow and also overcounts
instead reorder by highest bit?
*/