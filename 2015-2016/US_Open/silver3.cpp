#include <bits/stdc++.h>
using namespace std;

long n, m, visits;
vector<bool> v, v_copy;
vector<set<long> > adj;
void dfs(long node) {
    v[node] = 1;
    visits++;
    for(auto& n : adj[node]) {
        if(!v[n])
            dfs(n);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    adj = vector<set<long> >(n);
    v = vector<bool>(n, 0);
    v_copy = vector<bool>(n, 0);
    set<long> open;
    for(int i = 0; i < n; i++)
        open.insert(i);
    for(long i = 0; i < m; i++) {
        long a, b; cin >> a >> b;
        adj[a-1].insert(b-1);
        adj[b-1].insert(a-1);
    }
    visits = 0;
    dfs(*open.begin());
    if(visits == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    for(long i = 1; i < n; i++) {
        long c; cin >> c;
        v_copy[c-1] = 1;
        open.erase(c-1);
        v = vector<bool>(v_copy);
        visits = 0;
        dfs(*open.begin());
        if(visits == n-i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    long c; cin >> c;
    return 0;
}
