#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5;
vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];
vector<int> top_sort;

void dfs(int node) {
    visited[node] = 1;
    for (auto& i : adj[node]) {
        int q = i.first;
		if(!visited[q]) {
			dfs(q);
		}
	}
	top_sort.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    ll ans[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        cin >> ans[i];
    }

    for(int i = 0; i < c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[--a].push_back({--b, x});
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    reverse(top_sort.begin(), top_sort.end());

    for(int i = 0; i < n; i++) {
        for(auto& q: adj[top_sort[i]]) {
            ans[q.first] = max(ans[q.first], (ll) ans[top_sort[i]] + q.second);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}