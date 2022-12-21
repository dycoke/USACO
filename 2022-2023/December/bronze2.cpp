#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string cows; cin >> cows;
    if(k == 0) {
        cout << n << '\n';
        cout << cows << '\n';
        return;
    }
    vector<int> guernsey, holstein;
    for(int i = 0; i < n; i++) {
        if(cows[i] == 'G') {
            guernsey.push_back(i);
        } else {
            holstein.push_back(i);
        }
    }
    string ans = "";
    int num_placed = 0;
    for(int i = 0; i < n; i++) {
        ans += '.';
    }
    int next = -1;
    for(int i = 0; i < guernsey.size();) {
        next = guernsey[i] + 2*k;
        if(guernsey[i] + k >= n) {
            ans[n-1] = 'G';
        } else {
            ans[guernsey[i] + k] = 'G';
        }
        num_placed++;
        while(i < guernsey.size() && guernsey[i] <= next) {
            i++;
        }
    }
    next = -1;
    for(int i = 0; i < holstein.size();) {
        next = holstein[i] + 2*k;
        if(holstein[i] + k >= n || (holstein[i] + k == n-1 && ans[n-1] == 'G')) {
            int j = n-1;
            while(j >= holstein[i] && ans[j] != '.') {
                j--;
            }
            ans[j] = 'H';
        } else {
            ans[holstein[i] + k] = 'H';
        }
        num_placed++;
        while(i < holstein.size() && holstein[i] <= next) {
            i++;
        }
    }
    cout << num_placed << '\n' << ans << '\n';
    
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