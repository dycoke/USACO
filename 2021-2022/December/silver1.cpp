#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, m, n; cin >> k >> m >> n;
    vector<pair<int, int>> patches(k);
    for(pair<int, int>& patch : patches) {
        cin >> patch.first >> patch.second;
    }
    sort(patches.begin(), patches.end());
    vector<int> njoh(m);
    for(int& cow : njoh) {
        cin >> cow;
    }
    sort(njoh.begin(), njoh.end());
    njoh.push_back(1e9 + 1);
    vector<vector<pair<int, int>>> sections(m+1);
    vector<ll> section_tastiness(m+1, 0);
    int r, pp = 0;
    for(int i = 0; i <= m; i++) {
        r = njoh[i];
        while(pp < k && patches[pp].first < r) {
            section_tastiness[i] += patches[pp].second;
            sections[i].push_back(patches[pp]);
            pp++;
        }
    }
    vector<ll> gains;
    gains.push_back(section_tastiness[0]);
    gains.push_back(section_tastiness[m]);
    for(int i = 1; i < m; i++) {
        if(section_tastiness[i] == 0) {
            continue;
        }
        ll max_sum = 0, cur_sum = 0;
        int p1 = 0, p2 = 0;
        while(p1 < sections[i].size() && p2 < sections[i].size()) {
            while(p2 < sections[i].size()) {
                cur_sum += sections[i][p2].second;
                if(2*(sections[i][p2].first - sections[i][p1].first) >= (njoh[i] - njoh[i-1])) {
                    cur_sum -= sections[i][p2].second;
                    break;
                } else {
                    p2++;
                }
            }

            max_sum = max(max_sum, cur_sum);
            cur_sum -= sections[i][p1++].second;
        }
        gains.push_back(max_sum);
        if(max_sum)
        gains.push_back(section_tastiness[i] - max_sum);
    }
    ll ans = 0;
    sort(gains.begin(), gains.end(), greater<ll>());
    
    for(int i = 0; i < n; i++) {
        if(i >= gains.size() || gains[i] == 0) {
            break;
        }
        ans += gains[i];
    }
    cout << ans << '\n';
    return 0;
}