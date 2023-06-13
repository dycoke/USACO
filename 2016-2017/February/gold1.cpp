#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4;

int grid[MAX_N], dist[MAX_N];
vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];

int dx[] = {-3, -1, 1, 3, 0, 0, 0, 0, 1, 2, -1, -2, 1, 2, -1, -2};
int dy[] = {0, 0, 0, 0, -3, -1, 1, 3, 2, 1, 2, 1, -2, -1, -2, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    int n, t; cin >> n >> t;
    auto ind = [&](int x, int y) { return y*n + x; };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[ind(i, j)];
            dist[ind(i, j)] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a = ind(i, j);
            for(int d = 0; d < 16; d++) {
                int x = i + dx[d], y = j + dy[d];
                if(x >= 0 && y >= 0 && x < n && y < n) {
                    int b = ind(x, y); int w = grid[b] + 3*t;
                    adj[a].push_back({b, w});
                }
            }
        }
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 0}); dist[0] = 0;
    while(!pq.empty()) {
        int top = pq.top().second; pq.pop();
        if(visited[top]) continue;
        visited[top] = 1;
        for(pair<int, int>& v: adj[top]) {
            if(dist[top] + v.second < dist[v.first]) {
                dist[v.first] = dist[top] + v.second;
                pq.push({-dist[v.first], v.first});
            }
        }
    }

    int ans = dist[ind(n-1, n-1)];
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; i+j <= 2; j++) {
            ans = min(ans, dist[ind(n-1-i, n-1-j)] + (i+j)*t);
        }
    }
    cout << ans << '\n';
    return 0;
}