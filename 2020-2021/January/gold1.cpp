#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    map<char, int> indices;
    int numchar = 0;
    for(int i = 0; i < n; i++) {
        if(!indices.count(s[i])) {
            indices[s[i]] = numchar;
            numchar++;
        }
    }
    int adj[numchar][numchar]; memset(adj, 0, sizeof(adj));
    for(int i = 1; i < n; i++) {
        adj[indices[s[i-1]]][indices[s[i]]]++;
    }
    int dp[1 << numchar]; memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < (1 << numchar); i++) {
        for(int c = 0; c < numchar; c++) {
            if(i & (1 << c)) {
                int times = 0;
                for(int j = 0; j < numchar; j++) {
                    if(j == c || !(i & (1 << j))) {
                        times += adj[j][c];
                    }
                }
                dp[i] = min(dp[i], dp[i ^ (1 << c)] + times);
            }
        }
    }
    cout << dp[(1 << numchar) - 1] << '\n';
    return 0;
}