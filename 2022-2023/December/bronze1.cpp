#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> budgets(n);
    for(int& budget : budgets) {
        cin >> budget;
    }
    sort(budgets.begin(), budgets.end());
    ll ans = 0;
    int budget = 0;
    for(int i = 0; i < n; i++) {
        int num = n - i;
        ll money = (ll) num*budgets[i];
        if(ans < money) {
            ans = money;
            budget = budgets[i];
        }
    }
    cout << ans << ' ' << budget << '\n';
    return 0;
}