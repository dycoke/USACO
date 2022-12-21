#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
    if(a <= 1) {
        return 1;
    }
    for(int i = 2; i*i <= a; i++) {
        if(a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int n; cin >> n;
    vector<pair<bool, int>> winners(n);
    bool prime = 0;
    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        if(prime || isPrime(c)) {
            prime = 1;
        } else if(c % 4 == 0) {
            winners[i] = {0, c >> 1};
        } else if(c % 4 == 2) {
            winners[i] = {1, c >> 1};
        } else {
            for(int j = 4; j <= c; j+=4) {
                if(isPrime(c - j)) {
                    winners[i] = {1, (j >> 1) + 1};
                    break;
                }
            }
        }
    }
    if(prime) {
        cout << "Farmer John\n";
        return;
    }
    pair<bool, int> winner = {0, 5000001};
    for(int i = 0; i < n; i++) {
        if((winners[i].second >> 1) < (winner.second >> 1)) {
            winner = winners[i];
        }
    }
    cout << (winner.first ? "Farmer John" : "Farmer Nhoj") << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}