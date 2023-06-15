#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    vector<tuple<ll, int, int>> sums;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sums.push_back({prefix[j+1] - prefix[i], i, j});
        }
    }

    sort(sums.begin(), sums.end(), [](tuple<ll, int, int> a, tuple<ll, int, int> b) { return (get<0>(a)) < (get<0>(b)); });

    auto containsi = [&sums](int j, int i) {
        return get<1>(sums[j]) <= i && get<2>(sums[j]) >= i;
    };
    for(int i = 0; i < n; i++) {
        int prev_ncontainsi = -1, prev_containsi = -1;
        ll min_dif = LLONG_MAX;
        for(int j = 0; j < sums.size() - 1; j++) {
            if(containsi(j, i) && containsi(j+1, i)) {
                if(get<0>(sums[j]) == get<0>(sums[j+1])) {
                    min_dif = 0;
                    break;
                }
            } else if(containsi(j, i) || containsi(j+1, i)) {
                min_dif = min(min_dif, abs(get<0>(sums[j]) - get<0>(sums[j+1])));
            }

            if(containsi(j, i)) {
                prev_containsi = j;
                if(prev_ncontainsi != -1) {
                    min_dif = min(min_dif, abs(get<0>(sums[j]) - get<0>(sums[prev_ncontainsi])));
                }
            } else {
                prev_ncontainsi = j;
                if(prev_containsi != -1) {
                    min_dif = min(min_dif, abs(get<0>(sums[j]) - get<0>(sums[prev_containsi])));
                }
            }
        }

        cout << min_dif << '\n';
    }
    return 0;
}