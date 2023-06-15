#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    array<int, 3> friends[n];
    for(auto& f: friends) {
        cin >> f[0] >> f[1] >> f[2];
    }
    sort(friends, friends+n, [](array<int, 3> a, array<int, 3> b) { return a[2] < b[2];});
    int dp[n+1][a+1][b+1]; memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= a; j++) {
            for(int k = 0; k <= b; k++) {
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if(j >= friends[i][1]) {
                    int nj = j - friends[i][1];
                    int &old = dp[i+1][nj+min(friends[i][1], k/friends[i][2])][k-friends[i][2]*min(friends[i][1], k/friends[i][2])];
                    old = max(old, dp[i][j][k]+friends[i][0]);
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= a; j++) {
        for(int k = 0; k <= b; k++) {
            ans = max(ans, dp[n][j][k]);
        }
    }
    cout << ans << '\n';
    return 0;
}