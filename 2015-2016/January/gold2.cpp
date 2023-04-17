#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m; cin >> n >> m;
    pair<int, int> fj[n+1], bessie[m+1];

    cin >> fj[0].first >> fj[0].second;
    cin >> bessie[0].first >> bessie[0].second;
    string directions;

    cin >> directions;
    for(int i = 1; i <= n; i++) {
        char d = directions[i-1];
        if(d == 'N') {
            fj[i].first = fj[i-1].first;
            fj[i].second = fj[i-1].second+1;
        } else if(d == 'E') {
            fj[i].first = fj[i-1].first+1;
            fj[i].second = fj[i-1].second;
        } else if(d == 'W') {
            fj[i].first = fj[i-1].first-1;
            fj[i].second = fj[i-1].second;
        } else {
            fj[i].first = fj[i-1].first;
            fj[i].second = fj[i-1].second-1;
        }
    }

    cin >> directions;
    for(int i = 1; i <= m; i++) {
        char d = directions[i-1];
        if(d == 'N') {
            bessie[i].first = bessie[i-1].first;
            bessie[i].second = bessie[i-1].second+1;
        } else if(d == 'E') {
            bessie[i].first = bessie[i-1].first+1;
            bessie[i].second = bessie[i-1].second;
        } else if(d == 'W') {
            bessie[i].first = bessie[i-1].first-1;
            bessie[i].second = bessie[i-1].second;
        } else {
            bessie[i].first = bessie[i-1].first;
            bessie[i].second = bessie[i-1].second-1;
        }
    }

    auto dist = [&] (pair<int, int>& i, pair<int, int>& j) {
        int dx = i.first - j.first;
        int dy = i.second - j.second;
        return dx*dx + dy*dy;
    };

    ll dp[n+1][m+1];
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dist(fj[i], bessie[0]);
    }
    for(int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i-1] + dist(bessie[i], fj[0]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = (ll) dist(fj[i], bessie[j]) + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
