#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int bprefix[n][n + 1], eprefix[n][n + 1];
    for(int i = 0; i < n; i++) {
        bprefix[i][0] = 0;
        eprefix[i][0] = 0;
        for(int j = 1; j <= n; j++) {
            int g; cin >> g;
            bprefix[i][j] = g;
            eprefix[i][j] = g;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            bprefix[i][j] = (bprefix[i][j] < 100) + bprefix[i][j - 1];
            eprefix[i][j] = (eprefix[i][j] <= 100) + eprefix[i][j - 1];
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int k1 = 0, k2 = 0;
            for(int k = 0; k < n; k++) {
                while(k1 < n && (k1 < k || eprefix[k1][j] == eprefix[k1][i])) {
                    k1++;
                }
                while(k2 < n && (k2 < k || bprefix[k2][j] == bprefix[k2][i])) {
                    k2++;
                }
                ans += k2 - k1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}