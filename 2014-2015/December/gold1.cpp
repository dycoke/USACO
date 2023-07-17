#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    int n; ll h; cin >> n >> h;
    array<int, 3> cows[n];
    int dp[1 << n][n]; memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
        dp[1 << i][i] = cows[i][2];
    }
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                for(int k = 0; k < n; k++) {
                    if(j != k && (i & (1 << k))) {
                        dp[i][j] = max(dp[i][j], min(dp[i ^ (1 << j)][k] - cows[j][1], cows[j][2]));
                    }
                }
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < (1 << n); i++) {
        ll sum = 0; int res = -1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum += cows[j][0];
                res = max(res, dp[i][j]);
            }
        }
        if(sum >= h) ans = max(ans, res);
    }
    if(ans < 0) {
        cout << "Mark is too tall\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}