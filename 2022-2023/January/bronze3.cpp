/*
Lets start by checking 3 letter strings to see what happens
We find out that if a 3 letter string has 'O' as its second letter, we are always able to turn it into "MOO"

If we can reduce a bigger string into a 3 letter string with 'O' as its second letter, it is possible to turn it into "MOO"
Therefore, we just need to find the 3 character substring in teh string that leads to "MOO" in the least amount of moves

Since the only way to reduce the string's length is subtract one at a time, we add the length of the string minus 3
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    if(s.size() < 3) {
        cout << "-1\n";
        return;
    }
    vector<pair<string, int>> subst({{"MOO", 0}, {"MOM", 1}, {"OOM", 2}, {"OOO", 1}});
    int ans = 3;
    for(int i = 0; i < s.size() - 2; i++) {
        if(s.at(i+1) != 'M') {
            string substring = s.substr(i, 3);
            for(int i = 0; i < 4; i++) {
                if(subst[i].first == substring) {
                    ans = min(ans, subst[i].second);
                    break;
                }
            }
        }
    }
    if(ans == 3) {
        cout << "-1\n";
    } else {
        cout << ans + s.size() - 3 << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}