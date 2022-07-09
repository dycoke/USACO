#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> h(n+1, 0);
    vector<int> p(n+1, 0);
    vector<int> s(n+1, 0);
    for(int i = 1; i <= n; i++) {
        h[i] = h[i-1];
        p[i] = p[i-1];
        s[i] = s[i-1];
        string t;
        cin >> t;
        if(t == "H")
            h[i]++;
        else if(t == "P")
            p[i]++;
        else
            s[i]++;
    }
    int ans = max(h[n], max(p[n], s[n]));
    for(int i = 1; i <= n; i++) {
        int t1 = max(h[i] + p[n] - p[i-1], h[i] + s[n] - s[i-1]);
        int t2 = max(p[i] + h[n] - h[i-1], p[i] + s[n] - s[i-1]);
        int t3 = max(s[i] + h[n] - h[i-1], s[i] + p[n] - p[i-1]);
        ans = max(ans, max(t3, max(t1,t2)));
    }
    cout << ans << endl;
}
