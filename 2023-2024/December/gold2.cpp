#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 2e5;
vector<array<int, 2>> adj[MAX_N];
vector<int> adjR[MAX_N];
bool visited[MAX_N];
vector<int> top_sort;


void dfs(int u) {
    visited[u] = 1;
    for(int v: adjR[u]) {
		if(!visited[v]) {
			dfs(v);
		}
	}
	top_sort.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, l; cin >> u >> v >> l;
        adj[--u].push_back({--v, l});
        adjR[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i);
    }

    reverse(top_sort.begin(), top_sort.end());
    array<ll, 2> dp[n]; memset(dp, 0, sizeof(dp));
    vector<int> nodes[n];
    for(int i = 0; i < n; i++) {
        int u = top_sort[i];
        for(auto v: adj[u]) {
            dp[u][0] = max(dp[u][0], dp[v[0]][0] + 1);
        }
        nodes[dp[u][0]].push_back(u);
    }
    int order[n], to[n], min_edge[n];
    for(int dist = 0; dist < n; dist++) {
        if(!dist) {
            for(int u: nodes[dist]) {
                order[u] = 0;
            }
            continue;
        }
        vector<array<int, 3>> cur;
        for(int u: nodes[dist]) {
            min_edge[u] = INT_MAX;
            int min_ind;
            for(auto v: adj[u]) {
                if(dp[v[0]][0] == dist-1) {
                    if(min_edge[u] > v[1]) {
                        min_edge[u] = v[1];
                        to[u] = v[0];
                        min_ind = order[to[u]];
                    } else if(min_edge[u] == v[1]) {
                        if(order[v[0]] < min_ind) {
                            to[u] = v[0];
                            min_ind = order[to[u]];
                        }
                    }
                }
            }
            cur.push_back({u, min_edge[u], min_ind});
        }
        sort(cur.begin(), cur.end(), [](array<int, 3> a, array<int, 3> b) { 
            if(a[1] == b[1]) {
                return a[2] < b[2];
            }
            return a[1] < b[1];
        });
        for(int i = 0; i < cur.size(); i++) {
            order[cur[i][0]] = i;
        }
    }
    for(int i = 0; i < n; i++) {
        int u = top_sort[i];
        if(dp[u][0] != 0) {
            dp[u][1] = dp[to[u]][1] + min_edge[u];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    return 0;
}
/*
idea: for each distance's nodes, store the relative order they are to each otehr lexicographically
so we can just base it off the min index of its neighbors

10 12
1 5 5
1 4 5
1 3 5
1 2 5
5 9 3
4 8 4
3 7 4
2 6 4
9 10 10000
8 10 1
7 10 0
6 10 0
*/