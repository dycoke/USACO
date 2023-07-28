#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n; cin >> n;
    int rlog[n];
    for(int i = 0; i < n; i++) {
        cin >> rlog[i];
    }

    int dp[n+1][n+1]; memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        //number of riots
        for(int j = 0; j < n; j++) {
            //first j days
            int good = 0;
            for(int k = 1; k <= n; k++) {
                if(j + k <= n) {
                    good += (rlog[j+k-1] == k-1);
                    dp[i+1][j+k] = min(dp[i+1][j+k], dp[i][j] + (k-good));
                }
            }
        }
        cout << dp[i+1][n] << '\n';
    }
    return 0;
}