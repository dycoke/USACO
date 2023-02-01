/*

*/
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
int signs[1501][1501];
int num_children[1501][1501];

bool find_children(int x, int y, bool dir) {
    if(x < 0 || y < 0 || (x != n && y != n && signs[x][y] != dir)) {
        return 0;
    }
    num_children[x][y] = 1;

    if(y != n && find_children(x-1, y, 0)) {
        num_children[x][y] += num_children[x-1][y];
    }
    if(x != n && find_children(x, y-1, 1)) {
        num_children[x][y] += num_children[x][y-1];
    }
    return 1;
}

int get(int x, int y, int subtract) {
    if(x == n || y == n) {
        return signs[x][y];
    }

    num_children[x][y] -= subtract;
    if(signs[x][y]) {
        return get(x, y+1, subtract);
    } else {
        return get(x+1, y, subtract);
    }

}

void solve() {
    int x, y;
    cin >> x >> y;
    int curr_children = num_children[--x][--y];
    int curr_price = get(x, y, curr_children);
    num_children[x][y] = curr_children;

    ans -= curr_price*curr_children;

    signs[x][y] ^= 1;

    curr_price = get(x, y, -curr_children);
    num_children[x][y] = curr_children;

    ans += curr_price*curr_children;
    cout << ans << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    //1 for R
    //0 for D
    for(int i = 0; i <= n; i++) {
        if(i == n) {
            for(int j = 0; j < n; j++) {
                cin >> signs[i][j];
            }
            break;
        }
        string row; cin >> row;
        for(int j = 0; j < n; j++) {
            signs[i][j] = (row[j] == 'R');
        }
        cin >> signs[i][n];
    }

    for(int i = 0; i < n; i++) {
        find_children(i, n, 0);
        ans += (--num_children[i][n])*signs[i][n];
        find_children(n, i, 0);
        ans += (--num_children[n][i])*signs[n][i];
    }
    
    cout << ans << '\n';
    int q; cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}