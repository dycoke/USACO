#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;

    bool dp[2][t+1];
    for(int i = 0; i <= t; i++) {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    dp[1][0] = 1;
    for(int i = 1; i <= t; i++) {
        if(i - a >= 0) {
            dp[1][i] |= dp[1][i-a];
            dp[0][i/2] |= dp[1][i-a];
        }
        if(i - b >= 0) {
            dp[1][i] |= dp[1][i-b];
            dp[0][i/2] |= dp[1][i-b];
        }
    }
    for(int i = 1; i <= t; i++) {
        if(i - a >= 0) {
            dp[0][i] |= dp[0][i-a];
        }
        if(i - b >= 0) {
            dp[0][i] |= dp[0][i-b];
        }
    }
    for(int i = t; i >= 1; i--) {
        if(dp[1][i] || dp[0][i]) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
