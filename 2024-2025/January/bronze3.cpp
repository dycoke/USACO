#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    int a[n], b[n];
    int cnt[n][n];
    int x[n + 1], y[n + 1];
    x[0] = 0;
    y[n] = 0;
    for(int i = 0; i < n; i++) {

        cin >> a[i];
    }

    int ans[n + 1];
    memset(ans, 0, sizeof(ans));

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[i][i] = a[i] == b[i];
        x[i + 1] = cnt[i][i] + x[i];
        y[i] = cnt[i][i];
    }
    for(int i = n - 1; i >= 0; i--) {
        y[i] += y[i + 1];
        ans[cnt[i][i] + x[i] + y[i + 1]]++;
    }
    for(int i = 0; i < n - 1; i++) {
        cnt[i][i + 1] = (int) (a[i] == b[i + 1]) + (int) (a[i + 1] == b[i]);
        ans[cnt[i][i + 1] + x[i] + y[i + 2]]++;
    }

    for(int l = 2; l < n; l++) {
        for(int i = 0, j = l; j < n; i++, j++) {
            cnt[i][j] = cnt[i + 1][j - 1] + (int) (a[i] == b[j]) + (int) (a[j] == b[i]);
            ans[cnt[i][j] + x[i] + y[j + 1]]++;
        }
    }
    
    for(int i = 0; i <= n; i++) {
        cout << ans[i] << '\n';
    }
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