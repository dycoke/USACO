#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int fx[n+1], fy[m+1];
    fx[n] = a; fy[m] = b;
    for(int i = 0; i < n; i++) cin >> fx[i];
    for(int i = 0; i < m; i++) cin >> fy[i];
    sort(fx, fx+n); sort(fy, fy+m);
    int prevx = 0, prevy = 0;
    vector<pair<int, bool>> fences;

    int minx = -1, miny = -1;
    for(int i = 0; i <= n; i++) {
        int amt = fx[i]-prevx;
        if(minx == -1 || amt < minx) {
            if(minx != -1) {
                fences.push_back({minx, 1});
            }
            minx = amt;
        } else fences.push_back({amt, 1});
        prevx = fx[i];
    }
    for(int i = 0; i <= m; i++) {
        int amt = fy[i]-prevy;
        if(miny == -1 || amt < miny) {
            if(miny != -1) {
                fences.push_back({miny, 0});
            }
            miny = amt;
        } else fences.push_back({amt, 0});
        prevy = fy[i];
    }
    sort(fences.begin(), fences.end());
    int num_x = 0, num_y = 0;
    ll ans = (ll) 1LL*minx*m + 1LL*miny*n, num = (ll) (n+1)*(m+1)-n-m+1;
    for(auto& fence: fences) {
        if(num <= 0) break;
        int num_cells;
        if(fence.second) {
            num_cells = m - num_y;
            num_x++;
        } else {
            num_cells = n - num_x;
            num_y++;
        }

        ans += (ll) fence.first*num_cells;
        num -= (ll) num_cells;
    }

    cout << ans << '\n';
    return 0;
}