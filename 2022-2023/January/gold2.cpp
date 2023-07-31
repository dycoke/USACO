#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n; cin >> t >> n;
    int effect[3*n + 1][n];
    memset(effect, 0, sizeof(effect));
    for(int i = 0; i < 3*n; i++) {
        for(int j = 0; j < n; j++) {
            effect[i+1][j] = effect[i][j] << 1;
            if(effect[i+1][j] >= (1 << n)) {
                effect[i+1][j] ^= (1 << n);
                effect[i+1][j] ^= 1;
            }
            effect[i+1][j] ^= (1 << j);
        }
    }
    
    bool possible[3*n + 1][1 << n];
    memset(possible, 0, sizeof(possible));
    possible[0][0] = 1;
    for(int j = 0; j < 3*n; j++) {
        for(int i = 0; i < (1 << n); i++) {
            if(!possible[j][i]) continue;
            for(int k = 0; k < n; k++) {
                possible[j+1][i ^ (effect[j+1][k])] |= possible[j][i];
            }
        }
    }

    auto binary = [](string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                res ^= (1 << (i));
            }
        }
        return res;
    };

    while(t--) {
        string l, s; cin >> l >> s;
        int lights = binary(l), switches = binary(s);
        int mask = 0;
        for(int i = 0; i <= 3*n; i++) {
            int after = mask ^ lights;
            if(possible[i][after]) {
                cout << i << '\n';
                break;
            }
            mask <<= 1;
            mask ^= switches;
            if(mask >= (1 << n)) {
                mask ^= (1 << n);
                mask ^= 1;
            }
        }
    }
    return 0;
}