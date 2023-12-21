#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
    int n, c; cin >> n >> c;
    bool tar_p[2*c+5];
    memset(tar_p, 0, sizeof(tar_p));
    //cool trick to allow negative indices
    bool* tar = &tar_p[c+2]; //there exists a target at i
    int t[n];
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        tar[t[i]] = 1;
    }
    string s; cin >> s;
    int cur = 0; //position we are currently at
    int cnt_p[2*c+5];
    memset(cnt_p, 0, sizeof(cnt_p));
    int* cnt = &cnt_p[c+2];
    for(int i = 0; i < c; i++) {
        if(s[i] == 'R') cur++;
        else if(s[i] == 'L') cur--;
        else cnt[cur]++;
    }
    int l1 = 0, r1 = 0;
    int l2 = 0, r2 = 0;
    for(int i = 0; i < n; i++) {
        if(cnt[t[i]+1]) l1++;
        if(cnt[t[i]+2]) l2++;
        if(cnt[t[i]-1]) r1++;
        if(cnt[t[i]-2]) r2++;
    }
    bool used_p[2*c+5];
    memset(used_p, 0, sizeof(used_p));
    bool* used = &used_p[c+2];
    cur = 0;
    int ans = 0, hit = 0;
    for(int i = 0; i < c; i++) {
        if(s[i] == 'R') {
            //change to L
            ans = max(ans, l2 + hit);
            //change to F
            bool add = (!used[cur] && !cnt[cur+1] && tar[cur]);
            ans = max(ans, l1 + hit + add);
            cur++;
        } else if(s[i] == 'L') {
            //change to R
            ans = max(ans, r2 + hit);
            //change to F
            bool add = (!used[cur] && !cnt[cur-1] && tar[cur]);
            ans = max(ans, r1 + hit + add);
            cur--;
        } else {
            if(--cnt[cur] == 0) {
                if(!used[cur-1] && tar[cur-1]) l1--;
                if(!used[cur-2] && tar[cur-2]) l2--;
                if(!used[cur+1] && tar[cur+1]) r1--;
                if(!used[cur+2] && tar[cur+2]) r2--;
            }
            ans = max(ans, hit + r1);
            ans = max(ans, hit + l1);
            if(tar[cur] && !used[cur]) {
                used[cur] = 1;
                if(cnt[cur+1]) l1--;
                if(cnt[cur+2]) l2--;
                if(cnt[cur-1]) r1--;
                if(cnt[cur-2]) r2--;
                hit++;
            }
        }
    }
    ans = max(ans, hit);
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}