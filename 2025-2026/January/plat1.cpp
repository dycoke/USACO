#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll c;
    cin >> n >> c;
    vector<int> a(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i] + c;
    }

    vector<ll> ans(n / 2 + 1);
    for(int l = 0; l < n; l++) {
        for(int k = l + 1; k < n; k++) {
            ll d = a[k] - a[l];
            d = min(d, c - d);
            int tot = 0;
            for(int i = l, j = k; j < l + n && i < k;) {
                if(a[j] - a[i] < d) {
                    j++;
                } else if(a[j] - a[i] > c - d) {
                    i++;
                } else {
                    tot++;
                    i++;
                    j++;
                }
            }
            assert(tot <= n / 2);
            ans[tot] = max(ans[tot], d);
        }
    }

    for(int i = n / 2; i > 0; i--) {
        ans[i - 1] = max(ans[i - 1], ans[i]);
    }

    for(int i = 1; i <= n / 2; i++) {
        cout << ans[i] << " \n"[i == n / 2];
    }
    return 0;
}