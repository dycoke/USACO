#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fortmoo.in", "r", stdin);
    freopen("fortmoo.out", "w", stdout);

    int n, m; cin >> n >> m;
    int grid[n][m];
    for(int i = 0; i < n; i++) {
        string line; cin >> line;
        for(int j = 0; j < m; j++) {
            grid[i][j] = (line[j] == 'X');
        }
    }

    int prefix[n+1][m]; memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            prefix[i][j] = prefix[i-1][j] + grid[i-1][j];
        }
    }
    int ans = 0;
    for(int x1 = 0; x1 < n; x1++) {
        for(int x2 = x1; x2 < n; x2++) {
            for(int y1 = 0; y1 < m;) {
                if(prefix[x2+1][y1] - prefix[x1][y1] == 0) {
                    int l = y1;
                    int res = 0;
                    while(l < m && grid[x1][l] != 1 && grid[x2][l] != 1) {
                        if(prefix[x2+1][l] - prefix[x1][l] == 0) {
                            res = max(res, l - y1 + 1);
                        }
                        l++;
                    }
                    ans = max(ans, res*(x2-x1+1));
                    y1 = l;
                }
                while(y1 < m && prefix[x2+1][y1] - prefix[x1][y1] != 0) {
                    y1++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}