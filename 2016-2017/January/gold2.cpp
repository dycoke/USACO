#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, k;
    int dp[3][n][k+1];
    int fj[n];

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        char move; cin >> move;
        if(move == 'H') {
            fj[i] = 0;
        } else if(move == 'P') {
            fj[i] = 1;
        } else {
            fj[i] = 2;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            for(int K = 0; K <= k; K++) {
                dp[i][j][K] = 0;
            }
        }
    }

    dp[(fj[0] + 1) % 3][0][k] = 1;
    for(int i = 1; i < n; i++) {
        int winner = (fj[i] + 1) % 3;
        for(int j = 0; j <= k; j++) {
            for(int m = 0; m < 3; m++) {
                dp[m][i][j] = dp[m][i-1][j]; //no change
            }
            if(j != k) {
                for(int m = 0; m < 3; m++) {
                    if(m != winner) {
                        dp[winner][i][j] = max(dp[winner][i][j], dp[m][i-1][j+1]);
                    }
                }
            }
            dp[winner][i][j]++;
        }
    }

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max({ans, dp[0][n-1][i], dp[1][n-1][i], dp[2][n-1][i]});
    }
    cout << ans << '\n';
}
