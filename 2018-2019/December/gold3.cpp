#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k; cin >> n >> k;
    int skill[n];
    for(int i = 0; i < n; i++) {
        cin >> skill[i];
    }
    int dp[n+1]; //max sum of team that ends on i
    for(int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        int cur_max = 0;
        for(int j = 1; j <= k; j++) {
            if(i + j <= n) {
                cur_max = max(cur_max, skill[i+j-1]);
                dp[i+j] = max(dp[i+j], dp[i] + (j)*cur_max);
            }
        }
    }
    cout << dp[n] << '\n';
}
