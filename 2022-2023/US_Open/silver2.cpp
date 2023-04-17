#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, n; cin >> c >> n;
    vector<int> teams(n);
    for(int i = 0; i < n; i++) {
        string team; cin >> team;
        for(int j = 0; j < c; j++) {
            if(team[c-j-1] == 'H') {
                teams[i] |= (1 << j);
            }
        }
    }

    queue<pair<int, int>> bfs;
    vector<int> ans(1 << c, -1);
    for(int& team: teams) {
        bfs.push({team, 0});
        ans[team] = 0;
    }

    while(!bfs.empty()) {
        pair<int, int> front = bfs.front();
        bfs.pop();
        for(int i = 0; i < c; i++) {
            int team = front.first ^ (1 << i);
            if(ans[team] == -1) {
                bfs.push({team, front.second+1});
                ans[team] = front.second+1;
            }
        }
    }

    for(int& team: teams) {
        cout << c - ans[team ^ ((1 << c) - 1)] << '\n';
    }
    return 0;
}