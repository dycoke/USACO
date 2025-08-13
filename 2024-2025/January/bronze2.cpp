#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    int a[n], f[n + 1];
    memset(f, -1, sizeof(f));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(f[a[i]] == -1) f[a[i]] = i;
    }
    int vis[n + 1];
    memset(vis, 0, sizeof(vis));
    ll ans = 0;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(vis[a[i]] == 1) {
            cnt++;
        }
        vis[a[i]]++;
        if(f[a[i]] == i)
            ans += (cnt - (vis[a[i]] > 1));
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while(t--) solve();
    return 0;
}