#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string grid[n];
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool works = true;
    int ans[n][n];
    memset(ans, -1, sizeof(ans));

    // B
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'B') {
                ans[i][j] = 1;
                if(i >= b && j >= a) {
                    ans[i - b][j - a] = 1;
                } else {
                    works = false;
                }
            }
        }
    }

    // W
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'W') {
                if(ans[i][j] == 1)
                    works = false;
                ans[i][j] = 0;
            }
        }
    }
    // G
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'G') {
                if(i >= b && j >= a) {
                    if(ans[i - b][j - a] != 1) {
                        ans[i][j] = 1;
                    }
                } else {
                    if(ans[i][j] == 0)
                        works = false;
                    ans[i][j] = 1;
                }
            }
        }
    }
    if(works) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // cout << ans[i][j] << ' ';
                cnt += (ans[i][j] == 1);
            }
            // cout << '\n';
        }
        cout << cnt << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    std::cin >> t;
    while(t--) solve();
    return 0;
}