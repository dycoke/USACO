#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n; cin >> n;
    vector<bool> thing(2*n, 0);
    vector<int> bessie, elsie1(n/2), elsie2(n/2);
    for(int i = 0; i < n/2; i++) {
        cin >> elsie1[i];
        thing[elsie1[i]-1] = 1;
    }
    for(int i = 0; i < n/2; i++) {
        cin >> elsie2[i];
        thing[elsie2[i]-1] = 1;
    }
    for(int i = 0; i < 2*n; i++) {
        if(!thing[i])
            bessie.push_back(i+1);
    }
    sort(elsie1.begin(), elsie1.end(), greater<int>());
    sort(elsie2.begin(), elsie2.end());
    int ans = 0, j = n-1;
    for(int i = 0; i < n/2; i++) {
        if(bessie[j] > elsie1[i]) {
            ans++;
            j--;
        }
    }
    j = 0;
    for(int i = 0; i < n/2; i++) {
        if(bessie[j] < elsie2[i]) {
            j++;
            ans++;
        }
    }
    cout << ans;
}
