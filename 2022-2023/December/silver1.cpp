#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 200000;

vector<int> adj[MAX_N];
ll milkAmount[MAX_N];
ll subtree_sum[MAX_N];
vector<tuple<int, int, ll>> orders;

ll calc_subtree_sum(ll node, ll head) {
    subtree_sum[node] = milkAmount[node];
    for(ll n: adj[node]) {
        if(n != head) {
            subtree_sum[node] += calc_subtree_sum(n, node);
        }
    }
    return subtree_sum[node];
}

ll solve(ll node, ll head) {
    vector<pair<int, ll>> subtree_sums;
    for(int n: adj[node]) {
        if(n != head) {
            subtree_sums.push_back({n, subtree_sum[n]});
        }
    }
    sort(subtree_sums.begin(), subtree_sums.end(), [](pair<int, ll> a, pair<int, ll> b){return a.second > b.second;});
    for(pair<int, ll>& sum: subtree_sums) {
        if(sum.second < 0) {
            orders.push_back({node, sum.first, -sum.second});
            milkAmount[node] += sum.second;
            milkAmount[sum.first] -= sum.second;
        }
        ll give = solve(sum.first, node);
        if(give > 0) {
            orders.push_back({sum.first, node, give});
            milkAmount[node] += give;
            milkAmount[sum.first] -= give;
        }
    }
    return milkAmount[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll totalMilk = 0;
    for(ll i = 0; i < n; i++) {
        cin >> milkAmount[i];
        totalMilk += milkAmount[i];
    }
    totalMilk /= n;
    for(ll i = 0; i < n; i++) {
        milkAmount[i] -= totalMilk;
    }
    for(ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    calc_subtree_sum(0, -1);
    solve(0, -1);
    cout << orders.size() << '\n';
    for(auto& order: orders) {
        cout << get<0>(order) + 1 << ' ' << get<1>(order) + 1 << ' ' << get<2>(order) << '\n';
    }
    return 0;
}