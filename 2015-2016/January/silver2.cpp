#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    long n;
    cin >> n;
    vector<long> dp(n+1, 0);
    map<long, set<long> > m;
    for(int i=1; i<=n; i++){
        long x;
        cin >> x;
        dp[i] = dp[i-1] + x;
        m[dp[i]%7].insert(i - 1);
    }
    long ans = 0;
    for(int i=0; i<=n; i++){
        if(m.count(dp[i]%7)) {
            if(m[dp[i]%7].size() > 1) {
                ans = max(ans, i - *m[dp[i]%7].begin() - 1);
            }
        }
    }
    cout << ans << endl;
}
