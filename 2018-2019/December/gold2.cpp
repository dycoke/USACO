#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    int n; cin >> n;
    vector<array<int, 5>> choices(n);
    map<int, ll> sub1;
    map<array<int, 2>, ll> sub2;
    map<array<int, 3>, ll> sub3;
    map<array<int, 4>, ll> sub4;
    map<array<int, 5>, ll> sub5;
    for(auto& c: choices) {
        cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4];
        sort(c.begin(), c.end());
        for(int i = 0; i < 5; i++) {
            sub1[c[i]]++;;
        }
        for(int i = 0; i < 4; i++) {
            for(int j = i+1; j < 5; j++) {
                sub2[{c[i], c[j]}]++;
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = i+1; j < 4; j++) {
                for(int k = j+1; k < 5; k++) {
                    sub3[{c[i], c[j], c[k]}]++;
                }
            }
        }
        for(int i = 0; i < 2; i++) {
            for(int j = i+1; j < 3; j++) {
                for(int k = j+1; k < 4; k++) {
                    for(int l = k+1; l < 5; l++) {
                        sub4[{c[i], c[j], c[k], c[l]}]++;
                    }
                }
            }
        }
        sub5[c]++;
    }
    ll ans = 0;
    for(auto s: sub1) {
        ans += (s.second*(s.second-1))/2;
    }

    for(auto s: sub2) {
        ans -= (s.second*(s.second-1))/2;
    }

    for(auto s: sub3) {
        ans += (s.second*(s.second-1))/2;
    }

    for(auto s: sub4) {
        ans -= (s.second*(s.second-1))/2;
    }

    for(auto s: sub5) {
        ans += (s.second*(s.second-1))/2;
    }

    ll t = (ll) n*(n-1)/2;
    cout << t - ans << '\n';
    return 0;
}