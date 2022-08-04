#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    string fence; cin >> fence;
    vector<int> prefix(n+1), suffix(n+1);

    stack<char> colors1, colors2;
    for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i];
        while(!colors1.empty() && colors1.top() > fence[i]) {
            colors1.pop();
        }
        if(colors1.empty() || colors1.top() < fence[i]) {
            colors1.push(fence[i]);
            prefix[i+1]++;
        }
    }
    reverse(fence.begin(), fence.end());
    for(int i = 0; i < n; i++) {
        suffix[i+1] = suffix[i];
        while(!colors2.empty() && colors2.top() > fence[i]) {
            colors2.pop();
        }
        if(colors2.empty() || colors2.top() < fence[i]) {
            colors2.push(fence[i]);
            suffix[i+1]++;
        }
    }
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << prefix[l-1] + suffix[n-r] << '\n';
    }
    return 0;
}