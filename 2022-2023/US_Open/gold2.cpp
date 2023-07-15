#include <bits/stdc++.h>
using namespace std;
#define ll long long

const string target = "bessie";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    int cost[n], total = 0;
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        total += cost[i];
    }

    pair<int, int> dp[n+1][6]; memset(dp, -1, sizeof(dp));
    dp[0][0] = {0, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < target.size(); j++) {
            if(s[i] == target[j] && dp[i][j].second != -1) {
                int nj = (j+1)%6;
                if(dp[i][j].first + (nj == 0) > dp[i+1][nj].first) dp[i+1][nj] = {dp[i][j].first + (nj == 0), dp[i][j].second};
                else if(dp[i][j].first + (nj == 0) == dp[i+1][nj].first) dp[i+1][nj].second = min(dp[i+1][nj].second, dp[i][j].second);
            } 
            if(j == 0) {
                if(dp[i][j].first > dp[i+1][j].first) {
                    dp[i+1][j] = dp[i][j];
                } else if(dp[i+1][j].first == dp[i][j].first) {
                    dp[i+1][j].second = min(dp[i+1][j].second, dp[i][j].second);
                }
            } else {
                if(dp[i][j].first > dp[i+1][j].first) {
                    dp[i+1][j] = {dp[i][j].first, dp[i][j].second + cost[i]};
                } else if(dp[i+1][j].first == dp[i][j].first) {
                    dp[i+1][j].second = min(dp[i+1][j].second, dp[i][j].second + cost[i]);
                }
            }
        }
    }

    cout << dp[n][0].first << '\n' << dp[n][0].second << '\n';
    return 0;
}