#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;
    vector<int> a(18), b(18);
    for(char& c : s) {
        a[c - 'a']++;
    }
    for(char& c : t) {
        b[c - 'a']++;
    }
    vector<vector<bool>> equals(18, vector<bool>(18));
    for(int i = 0; i <= 17; i++) {
        for(int j = i; j <= 17; j++) {
            if(a[i] + a[j] != b[i] + b[j]) { //base case, amount of letters not the same
                equals[i][j] = 0;
                equals[j][i] = 0;
                continue;
            }
            string a1, b1;
            for(char& c: s) {
                if(c - 'a' == i || c - 'a' == j) {
                    a1 += (char) c;
                }
            }
            for(char& c: t) {
                if(c - 'a' == i || c - 'a' == j) {
                    b1 += (char) c;
                }
            }
            equals[i][j] = (a1 == b1);
            equals[j][i] = equals[i][j];
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        string query; cin >> query;
        bool works = 1;
        for(int i = 0; i < query.size(); i++) {
            for(int j = i; j < query.size(); j++) {
                int c1 = query[i] - 'a', c2 = query[j] - 'a';
                if(!equals[c1][c2]) {
                    works = 0;
                    goto PRNT;
                }
            }
        }
        PRNT: cout << (works ? 'Y' : 'N');
    }
    cout << '\n';
    return 0;
}