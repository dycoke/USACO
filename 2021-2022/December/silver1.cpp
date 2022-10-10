#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, m, n; cin >> k >> m >> n;
    vector<pair<int, int>> patches(k);
    for(int i = 0; i < k; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    vector<int> nhoj(m);
    for(int i = 0; i < m; i++) {
        cin >> nhoj[i];
    }
    sort(patches.begin(), patches.end());
    sort(nhoj.begin(), nhoj.end());
    nhoj.push_back(1e9 + 1);
    //divide patches into m + 1 sections
    vector<vector<pair<int, int>>> sections(m+1);
    vector<ll> section_sums(m+1);
    int r, pi = 0;
    for(int i = 0; i <= m; i++) {
        r = nhoj[i];
        int sum = 0;
        while(pi < k && patches[pi].first < r) {
            sections[i].push_back(patches[pi]);
            sum += patches[pi].second;
            pi++;
        }
        section_sums[i] = sum;
    }
    //for each section, use 2p to find the max amount of tastiness half-lengthed
    vector<ll> gains({section_sums[0], section_sums[m]});
    for(int i = 1; i < m; i++) {
        if(section_sums[i] == 0) {
            gains.push_back(0);
        }
        int l = 0, r = 0;
		ll cur_sum = 0, max_sum = 0;
        while(l < sections[i].size() && r < sections[i].size()) {
            while(r < sections[i].size()) {
                cur_sum += sections[i][r].second;
                if(2*(sections[i][r].first - sections[i][l].first) >= nhoj[i] - nhoj[i-1]) {
					cur_sum -= sections[i][r].second;
                    break;
                } else {
                    r++;
                }
            }
			max_sum = max(cur_sum, max_sum);
            cur_sum -= sections[i][l++].second;
        }
        gains.push_back(max_sum);
        gains.push_back(section_sums[i] - max_sum);
    }
    sort(gains.begin(), gains.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += gains[i];
    }
	cout << ans << '\n';
    return 0;
}