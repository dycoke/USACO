/*
Complete search with recursion problem

we can check all 2^N combonations of air conditioners being on and off as m is at max 10
*/
#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<array<int, 4>> subset;
int cur_price = 0;
int ans = INT_MAX;

bool works(vector<array<int, 3>>& cows) {
    vector<int> conditioning(1e6 + 1, 0);
    for(auto& conditioner: subset) {
        for(int i = conditioner[0]; i <= conditioner[1]; i++) {
            conditioning[i] += conditioner[2];
        }
    }
    for(auto& cow: cows) {
        for(int i = cow[0]; i <= cow[1]; i++) {
            if(conditioning[i] < cow[2]) {
                return 0;
            }
        }
    }
    return 1;
}

void subsets(int k, vector<array<int, 4>>& conditioners, vector<array<int, 3>>& cows) {
    if(k == m) {
        if(subset.size() != 0 && works(cows)) {
            ans = min(ans, cur_price);
        }
    } else {
        subsets(k+1, conditioners, cows);
        cur_price += conditioners[k][3];
        subset.push_back(conditioners[k]);
        subsets(k+1, conditioners, cows);
        cur_price -= subset.back()[3];
        subset.pop_back();

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<array<int, 3>> cows(n);
    for(auto& cow: cows) {
        cin >> cow[0] >> cow[1] >> cow[2];
    }

    vector<array<int, 4>> conditioners(m);
    for(auto& conditioner: conditioners) {
        cin >> conditioner[0] >> conditioner[1] >> conditioner[2] >> conditioner[3];
    }

    subsets(0, conditioners, cows);
    cout << ans << '\n';
    return 0;
}