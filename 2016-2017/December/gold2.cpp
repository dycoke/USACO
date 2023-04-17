#include <bits/stdc++.h>
using namespace std;

const int INF = 15e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int H, G; cin >> H >> G;
    vector<pair<int, int>> h(H), g(G);
    int dp[2][H+1][G+1]; //0 for H, 1 for G
    for(int i = 0; i < H; i++) {
        cin >> h[i].first >> h[i].second;
    }
    for(int i = 0; i < G; i++) {
        cin >> g[i].first >> g[i].second;
    }

    for(int i = 0; i <= H; i++) {
        for(int j = 0; j <= G; j++) {
            dp[0][i][j] = INF;
            dp[1][i][j] = INF;
        }
    }

    auto dist = [&] (pair<int, int>& i, pair<int, int>& j) {
        int dx = i.first - j.first;
        int dy = i.second - j.second;
        return dx*dx + dy*dy;
    };
    
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    dp[1][1][1] = dist(h[0], g[0]);

    for(int i = 2; i <= G; i++) {
        dp[1][1][i] = dp[1][1][i-1] + dist(g[i-1], g[i-2]);
    }
    for(int i = 2; i <= H; i++) {
        dp[0][i][0] = dp[0][i-1][0] + dist(h[i-1], h[i-2]);
    }

    for(int i = 2; i <= H; i++) {
        for(int j = 1; j <= G; j++) {
            dp[0][i][j] = min(dp[0][i-1][j] + dist(h[i-1], h[i-2]), dp[1][i-1][j] + dist(h[i-1], g[j-1]));
            dp[1][i][j] = dp[0][i][j-1] + dist(g[j-1], h[i-1]);
            if(j > 1) dp[1][i][j] = min(dp[1][i][j], dp[1][i][j-1] + dist(g[j-2], g[j-1]));
        }
    }

    int ans = min(dp[0][H-1][G] + dist(h[H-1], h[H-2]), dp[1][H-1][G] + dist(h[H-1], g[G-1]));
    cout << ans << '\n';

    return 0;
}