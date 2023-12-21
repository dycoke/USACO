#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
    int n, k; cin >> n >> k;
    int a[k], b[k];
    int ind[n], u = 0; //number of unique
    memset(ind, -1, sizeof(ind));
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        ind[--a[i]] = i;
        u++;
    }
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < k; i++) {
        cin >> b[i];
        if(ind[--b[i]] == -1) u++;
        else cnt[(ind[b[i]] - i + k) % k]++;
    }
    int ans = *max_element(cnt, cnt + k);
    memset(cnt, 0, sizeof(cnt));
    //in case the cycle is backwards
    reverse(b, b + k);
    for(int i = 0; i < k; i++) {
        cnt[(ind[b[i]] - i + k) % k] += (ind[b[i]] != -1);
    }
    ans = max(ans, *max_element(cnt, cnt + k));
    cout << ans + n - u << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}