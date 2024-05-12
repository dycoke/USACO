#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct cmp {
    bool operator()(const array<ll, 3> &a, const array<ll, 3> &b) const {
        return a[0] > b[0];
    }
};

void solve() {
    int n; cin >> n;
    ll p[n], s[n];
    set<int> exists;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        exists.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll ans[n];
    memset(ans, -1, sizeof(ans));
    vector<int> st;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, cmp> pq;

    auto findTimeToCollision = [&](int l, int r) {
        ll speed = s[l] + s[r], distance = p[r] - p[l];

        ll time = (distance + speed - 1) / speed;

        return 2 * time - 1 + l % 2;
    };
    for(int i = 1; i < n; i++) {
        pq.push({findTimeToCollision(i - 1, i), i - 1, i});
    }
    while(!pq.empty()) {
        auto [time, i, j] = pq.top();
        pq.pop();
        if(ans[i] != -1 || ans[j] != -1) continue;
        ans[i] = ans[j] = time;
        auto iti = exists.find(i), itj = exists.find(j);
        if(iti == exists.begin() || itj == prev(exists.end())) {
            exists.erase(iti);
            exists.erase(itj);
            continue;
        }
        auto niti = prev(iti), nitj = next(itj);
        pq.push({findTimeToCollision(*niti, *nitj), *niti, *nitj});
        exists.erase(iti);
        exists.erase(itj);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}