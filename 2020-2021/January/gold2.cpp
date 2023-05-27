#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> breeds[k];
    int breed[n], dist[n];
    bool visited[n];
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        breed[i] = --b;
        breeds[b].push_back(i);
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    vector<int> comm[k];
    bool idfk[k];
    for(int i = 0; i < k; i++) {
        string c; cin >> c;
        for(int j = 0; j < k; j++) {
            if(i != j && c[j] == '1') comm[i].push_back(j);
            if(i == j) {
                comm[i].push_back(j);
                idfk[i] = c[j] == '1';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int& b: comm[breed[i]]) {
            if(i == 0 && b == breed[i] && !idfk[b]) continue;
            int upper = upper_bound(breeds[b].begin(), breeds[b].end(), i) - breeds[b].begin();
            if(upper != 0) {
                if(breeds[b][upper-1] == i && upper >= 2) adj[i].push_back({breeds[b][upper-2], abs(i-breeds[b][upper-2])});
                else adj[i].push_back({breeds[b][upper-1], abs(i-breeds[b][upper-1])});
            }
            if(upper != breeds[b].size()) {
                adj[i].push_back({breeds[b][upper], abs(abs(i-breeds[b][upper]))});
            }
        }
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 0}); dist[0] = 0;
    while(!pq.empty()) {
        int top = pq.top().second; pq.pop();
        if(visited[top]) continue;
        visited[top] = 1;
        for(auto& i: adj[top]) {
            if(dist[top] + i.second < dist[i.first]) {
                dist[i.first] = dist[top] + i.second;
                pq.push({-dist[i.first], i.first});
            }
        }
    }
    if(!visited[n-1]) cout << "-1\n";
    else cout << dist[n-1] << '\n';
    return 0;
}