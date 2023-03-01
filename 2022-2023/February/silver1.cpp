#include <bits/stdc++.h>
using namespace std;

int n, c, m;
array<int, 3> orders[100];

bool works(int z) {
    int x = c, y = m;
    for(int i = 0; i < n; i++) {
        array<int, 3>& order = orders[i];
        if(order[0] > order[1]) {
            int remains = order[2] - order[1]*z;
            if(remains/(order[0] - order[1]) <= 0) {
                return 0;
            }
            x = min(x, remains/(order[0] - order[1]));
        } else if(order[0] < order[1]) {
            int remains = order[2] - order[0]*z;
            if(remains/(order[1] - order[0]) <= 0) {
                return 0;
            }
            y = min(y, remains/(order[1] - order[0]));
        } else {
            if(order[2] < order[1]*z) {
                return 0;
            }
        }
    }
    if(x + y >= z) {
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    cin >> n >> c >> m;
    for(int i = 0; i < n; i++) {
        cin >> orders[i][0] >> orders[i][1] >> orders[i][2];
    }

    int l = 2, r = c + m;
    while(l < r) {
        int mid = l + (r-l+1)/2;
        
        if(works(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << c + m - l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}