#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 2e5;
vector<int> adj[MAX_N];
int rate[MAX_N], height[MAX_N];
ll dp1[MAX_N], dp2[MAX_N];
ll subsize[MAX_N], subsum[MAX_N];
int max_depth = 0;

void dfs(int u, int p) {
    subsize[u] = 1;
    subsum[u] = rate[u];
    dp1[u] = 0;
    dp2[u] = 0;
    height[u] = 0;
    vector<int> children;
    
    for(int& v: adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        height[u] = max(height[u], height[v]+1);
        subsize[u] += subsize[v];
        subsum[u] += subsum[v];
        children.push_back(v);
    }
    auto cmp = [&](int a, int b) {
        return subsum[b]*subsize[a] <= subsum[a]*subsize[b];
    };
    sort(children.begin(), children.end(), cmp);

    ll total_time = 1;
    for(int& v: children) {
        dp1[u] += (total_time)*subsum[v] + dp1[v];
        total_time += 2*subsize[v];
    }

    if(children.size()) {
        dp2[u] = LLONG_MAX;
        int mn = -1;
        ll time1 = 1, time2 = 1, sum = 0;
        for(int& v: children) {
            sum += subsum[v];
            if(height[v] == height[u] - 1) {
                dp2[u] = min(dp2[u], dp1[u] - (time1*subsum[v] + dp1[v]) - (2*subsize[v])*(subsum[u] - rate[u] - sum) + (total_time - 2*subsize[v])*subsum[v] + dp2[v]);
            }
            time1 += 2*subsize[v];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, t; cin >> n >> t;
    for(int i = 1; i < n; i++) {
        int p, a; cin >> p >> rate[i];
        adj[i].push_back(--p);
        adj[p].push_back(i);
    }
    rate[0] = 0;
    dfs(0, -1);
    if(t == 0) {
        //easier case
        cout << 2*(n-1) << ' ' << dp1[0] << '\n';
    } else {
        cout << 2*(n-1) - height[0] << ' ' << dp2[0] << '\n';
    }
    return 0;
}