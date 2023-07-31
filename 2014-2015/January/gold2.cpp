#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);

    int n, l; cin >> n >> l;
    vector<int> showtimes[n];
    int duration[n];
    for(int i = 0; i < n; i++) {
        cin >> duration[i];
        int c; cin >> c;
        for(int j = 0; j < c; j++) {
            int s; cin >> s;
            showtimes[i].push_back(s);
        }
    }

    int dp[1 << n]; memset(dp, 0, sizeof(dp));
    int ans = -1;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                int ind = upper_bound(showtimes[j].begin(), showtimes[j].end(), dp[i ^ (1 << j)]) - showtimes[j].begin();
                if(ind == 0) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
                else dp[i] = max(dp[i], max(dp[i ^ (1 << j)], showtimes[j][ind-1] + duration[j]));
            }
        }
        if(dp[i] >= l && (ans == -1 || __builtin_popcount(i) < ans)) {
            ans = __builtin_popcount(i);
        }
    }
    cout << ans << '\n';
    return 0;
}