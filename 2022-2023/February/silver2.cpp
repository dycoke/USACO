//AYOOOOOO CHEGG???
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lb(int target, vector<array<int, 3>>& grazings) {
    int l = 0, r = grazings.size();
    while(l < r) {
        int mid = l + (r-l)/2;
        if(grazings[mid][0] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int g, n; cin >> g >> n;
    vector<array<int, 3>> grazings(g);
    for(auto& grazing: grazings) {
        cin >> grazing[1] >> grazing[2] >> grazing[0];
    }
    sort(grazings.begin(), grazings.end(), [](array<int, 3> a, array<int, 3> b) { return a[0] < b[0]; });

    int ans = 0;
    for(int i = 0; i < n; i++) {
        array<int, 3> alibi;
        cin >> alibi[1] >> alibi[2] >> alibi[0];
        int lower = lb(alibi[0], grazings);
        bool works = 1;
        if(lower > 0) {
            ll dx = abs(grazings[lower-1][1] - alibi[1]), dy = abs(grazings[lower-1][2] - alibi[2]), dt = abs(alibi[0] - grazings[lower-1][0]);
            if(dx*dx + dy*dy > dt*dt) {
                works = 0;
            }
        }
        if(lower < g) {
            ll dx = abs(grazings[lower][1] - alibi[1]), dy = abs(grazings[lower][2] - alibi[2]), dt = abs(alibi[0] - grazings[lower][0]);
            if(dx*dx + dy*dy > dt*dt) {
                works = 0;
            }
        }
        if(!works) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}

