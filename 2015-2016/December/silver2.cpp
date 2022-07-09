#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n; cin >> n;
    set<int> elsie, bessie;
    for(int i = 1; i <= 2*n; i++) {
        bessie.insert(i);
    }
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        elsie.insert(t);
        bessie.erase(t);
    }
    int ans = 0;
    for(auto& i : elsie) {
        auto temp = bessie.upper_bound(i);
        if(temp == bessie.end())
            break;
        bessie.erase(temp);
        ans++;
    }
    cout << ans;
}
