#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> crosses(n);
    for(int& cross: crosses) {
        cin >> cross;
    }
    int index = 0;
    while(crosses[0] > 0) {
        do {
            --crosses[index++];
            cout << 'R';
        } while(index < n && crosses[index] != 0);
        index--;
        int prev = 0;
        do {
            prev = --crosses[index--];
            cout << 'L';
        } while(index >= 0 && (prev == 0 || crosses[index] > 1));
        index++;
    }
    cout << '\n';
    return 0;
}