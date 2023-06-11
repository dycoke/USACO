#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n; cin >> n;
    int pow[n+1], prefix[2*n];
    pow[0] = 1;
    for(int i = 0; i < n; i++) {
        prefix[i] = 0; prefix[i+n] = 0;
        pow[i+1] = (pow[i]*2 % MOD);
    }
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        prefix[--l]++;
        prefix[--r]--;
    }
    int ans = 0, curr = 0;
    for(int i = 0; i < 2*n; i++) {
        curr += prefix[i];
        if(prefix[i] == 1) ans = (ans + pow[n-curr]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}