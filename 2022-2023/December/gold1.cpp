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
    sort(friends, friends+n, [](array<int, 3> a, array<int, 3> b) { if(a[2] == b[2]) return a[0] > b[0]; return a[2] < b[2];});
    int dp[n+1][a+b+1]; memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= a+b; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j > a) {
                int nb = j-a;
                if(nb/friends[i][2] > friends[i][1]) {
                    int &old = dp[i+1][a+nb-(friends[i][1]*friends[i][2])];
                    old = max(old, dp[i][j]+friends[i][0]);
                } else {
                    int nj = a-friends[i][1]+(nb/friends[i][2]);
                    if(nj >= 0) {
                        int &old = dp[i+1][nj];
                        old = max(old, dp[i][j]+friends[i][0]);
                    }
                }
            } else {
                int nj = j - friends[i][1];
                if(nj >= 0) {
                    int &old = dp[i+1][nj];
                    old = max(old, dp[i][j]+friends[i][0]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= a+b; j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';
    return 0;
}