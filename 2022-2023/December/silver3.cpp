#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> ranges;
    for(int i = 0; i < n - 1; i++) {
        vector<int> range(n-i-1);
        int waste; cin >> waste;
        for(int j = n-i-2; j >= 0; j--) {
            cin >> range[j];
        }
        ranges.push_back(range);
    }
    int waste; cin >> waste;
    vector<int> order({0, ranges[n-2][0]});
    int min_milk = 0;
    for(int i = n-3; i >= 0; i--) {
        int a = order[order.size()-1] - ranges[i][ranges[i].size()-1], b = INT_MIN;
        bool works = 1;
        for(int j = order.size() - 1; j >= 0; j--) {
            b = max(b, order[j]);
            a = min(a, order[j]);
            if(b - a != ranges[i][j]) {
                works = 0;
                break;
            }
        }
        if(works) {
            min_milk = min(min_milk, order[order.size()-1] - ranges[i][ranges[i].size()-1]);
            order.push_back(order[order.size()-1] - ranges[i][ranges[i].size()-1]);
        } else {
            min_milk = min(min_milk, order[order.size()-1] + ranges[i][ranges[i].size()-1]);
            order.push_back(order[order.size()-1] + ranges[i][ranges[i].size()-1]);
        }
    }
    for(int i = n - 1; i > 0; i--) {
        cout << order[i] - min_milk << ' ';
    }
    cout << order[0] - min_milk << '\n';
    return 0;
}