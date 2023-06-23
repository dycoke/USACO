#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int MAX_N = 1e5;
vector<int> adj[MAX_N];
ll dp[3][MAX_N];

void dfs(int u, int p) {
    for(int& v: adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[0][u] = (dp[0][u]*(dp[1][v]+dp[2][v])) % MOD;
        dp[1][u] = (dp[1][u]*(dp[0][v]+dp[2][v])) % MOD;
        dp[2][u] = (dp[2][u]*(dp[0][v]+dp[1][v])) % MOD;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int n, k; cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        dp[0][i] = 1;
        dp[1][i] = 1;
        dp[2][i] = 1;
    }
    for(int i = 0; i < k; i++) {
        int a, c; cin >> a >> c;
        --a; --c;
        for(int j = 0; j < 3; j++) {
            dp[j][a] = (j == c);
        }
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[1][0] + dp[2][0]) % MOD << '\n';
    return 0;
}