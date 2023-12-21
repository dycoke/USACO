#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
    int n; ll m, k;
    cin >> n >> m >> k;
    array<ll, 2> c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i][0] >> c[i][1];
    }
    sort(c, c+n, [](array<ll, 2> a, array<ll, 2> b) { return a[0] > b[0]; });
    //pretend the stacks will be sorted by largest element
    //each element is only inserted once, so should be O(N log N)
    priority_queue<array<ll, 2>> pq;
    //just to fill the whole thing with huge stuff
    pq.push({(ll) 2e9, m});
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll cur = 0;
        while(!pq.empty() && pq.top()[0] >= c[i][0] + k) {
            array<ll, 2> top = pq.top();
            pq.pop();
            if(top[1] >= c[i][1]) {
                cur += c[i][1];
                pq.push({c[i][0], cur});
                if(top[1] - c[i][1])
                    pq.push({top[0], top[1] - c[i][1]});
                ans += cur;
                cur = -1;
                break;
            } else {
                cur += top[1];
                c[i][1] -= top[1];
            }
        }
        if(cur != -1) {
            pq.push({c[i][0], cur});
            ans += cur;
        }
    }
    cout << ans << '\n';
    
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