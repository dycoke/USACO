#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    bitset<750> routes[n];
    for(int i = 0; i < n - 1; i++) {
        string line; cin >> line;
        for(int j = i + 1; j < n; j++) {
            char r = line[j - i - 1];
            if(r == '1') routes[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        bitset<750> route = routes[i];
        for(int j = i + 1; j < n; j++) {
            if(route[j]) {
                route ^= routes[j];
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
/*
pretty sure it amortizes to O(N^2) but not sure
bitset is pretty fast asw
*/