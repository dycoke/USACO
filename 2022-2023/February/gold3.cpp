#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

char papers[301];
ll dp[301][20][20][3];

void solve(const string& lim, int s, int n) {
    int sz = lim.size();
    memset(dp, 0, sizeof(dp));
    for(int i = s; i < n; i++) for(int j = 0; j < sz; j++)
        for(int k = 0; k < sz - j; k++) {
            if(j == 0) {
                dp[i+1][k][k][0] += dp[i][k][k][0];
                dp[i+1][k][k][1] += dp[i][k][k][1];
                dp[i+1][k][k][2] += dp[i][k][k][2];
                if(papers[i] < lim[k]) {
                    dp[i+1][k][k][0] += 2;
                } else if(papers[i] == lim[k]) {
                    dp[i+1][k][k][1] += 2;
                } else {
                    dp[i+1][k][k][2] += 2;
                }
                dp[i+1][k][k][0] %= MOD;
                dp[i+1][k][k][1] %= MOD;
                dp[i+1][k][k][2] %= MOD;
                continue;
            }
            for(int f = 0; f < 3; f++) {
                //skip this one
                ll res = dp[i][k][k+j][f];
                //j is the size of the
                if(f == 0) {
                    //add to the front
                    if(papers[i] < lim[k]) {
                        res = (res + dp[i][k+1][k+j][0]) % MOD;
                        res = (res + dp[i][k+1][k+j][1]) % MOD;
                        res = (res + dp[i][k+1][k+j][2]) % MOD;
                    }
                    if(papers[i] == lim[k]) {
                        res = (res + dp[i][k+1][k+j][0]) % MOD;
                    }
                    //add to the back
                    res = (res + dp[i][k][k+j-1][0]) % MOD;
                    if(papers[i] < lim[k+j]) {
                        res = (res + dp[i][k][k+j-1][1]) % MOD;
                    }
                } else if(f == 1) {
                    if(papers[i] == lim[k]) {
                        res = (res + dp[i][k+1][k+j][1]) % MOD;
                    }
                    if(papers[i] == lim[k+j]) {
                        res = (res + dp[i][k][k+j-1][1]) % MOD;
                    }
                } else {
                    if(papers[i] > lim[k]) {
                        res = (res + dp[i][k+1][k+j][0]) % MOD;
                        res = (res + dp[i][k+1][k+j][1]) % MOD;
                        res = (res + dp[i][k+1][k+j][2]) % MOD;
                    }
                    if(papers[i] == lim[k]) {
                        res = (res + dp[i][k+1][k+j][2]) % MOD;
                    }
                    res = (res + dp[i][k][k+j-1][2]) % MOD;
                    if(papers[i] > lim[k+j]) {
                        res = (res + dp[i][k][k+j-1][1]) % MOD;
                    }
                }
                dp[i+1][k][k+j][f] += res;
                dp[i+1][k][k+j][f] %= MOD;
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int n; cin >> n;
    ll a, b; cin >> a >> b;
    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        papers[i] = char('0' + p);
    }
    string ta = to_string(a-1);
    ll ansa[n][n];
    memset(ansa, 0, sizeof(ansa));
    for(int i = 0; i < n; i++) {
        solve(ta, i, n);
        for(int j = i; j < n; j++) {
            for(int x = 0; x < ta.size(); x++) {
                ansa[i][j] += dp[j+1][x][ta.size()-1][0];
                ansa[i][j] += dp[j+1][x][ta.size()-1][1];
                if(x != 0) {
                    ansa[i][j] += dp[j+1][x][ta.size()-1][2];
                }
                ansa[i][j] %= MOD;
            }
        }
    }

    string tb = to_string(b);
    ll ansb[n][n];
    memset(ansb, 0, sizeof(ansb));
    for(int i = 0; i < n; i++) {
        solve(tb, i, n);
        for(int j = i; j < n; j++) {
            for(int x = 0; x < tb.size(); x++) {
                ansb[i][j] += dp[j+1][x][tb.size()-1][0];
                ansb[i][j] += dp[j+1][x][tb.size()-1][1];
                if(x != 0) {
                    ansb[i][j] += dp[j+1][x][tb.size()-1][2];
                }
                ansb[i][j] %= MOD;
            }
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        cout << (ansb[l][r] - ansa[l][r] + MOD) % MOD << '\n';
    }
    return 0;
}