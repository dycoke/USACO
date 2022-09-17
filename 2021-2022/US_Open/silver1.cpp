#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

int succ[MAX_N], moos[MAX_N];
long long ans = 0;
bool visited[MAX_N];
vector<int> adj[MAX_N];

void mark_done(int node) {
    visited[node] = 1;
    for(int& n : adj[node]) {
        if(!visited[n])
            mark_done(n);
    }
}

void floyd(int x) {
    int a = x, b = x;
    do {
        a = succ[a];
        b = succ[succ[b]];
    } while(a != b);
    int min_moos = INT_MAX;
    do {
        min_moos = min(min_moos, moos[a]);
        a = succ[a];
    } while(a != b);
    ans -= min_moos;
    mark_done(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> succ[i] >> moos[i];
        succ[i]--;
        adj[succ[i]].push_back(i);
        ans += moos[i];
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            floyd(i);
        }
    }
    cout << ans << '\n';
    return 0;
}