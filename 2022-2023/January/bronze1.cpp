/*
let's call a leader natural if their list contains all cows in its breed

the most important thing to notice is that a cow's list can only contain cows that appear after it

this leads to 3 observations:
    - a set of leaders must have at least one natural leader
    - a natural leader must be the first appearing cow of its breed
    - only one natural leader of each breed can exist

Thus, you only need to check:
    1. if a natural leader exists
    2. if the cows appearing before the natural leader have a list containing the natural leader

Code runs in O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string breeds; cin >> breeds;
    vector<int> lists(n);
    for(int i = 0; i < n; i++) {
        cin >> lists[i];
        lists[i]--;
    }
    int firstH, firstG, lastH, lastG;
    bool foundH = 0, foundG = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(breeds[i] == 'H') {
            if(!foundH) {
                lastH = i;
                foundH = 1;
            }
            firstH = i;
        } else {
            if(!foundG) {
                lastG = i;
                foundG = 1;
            }
            firstG = i;
        }
    }

    int ans = 0;
    if(lists[firstH] >= lastH) {
        //firstH will be a natural leader
        
        //check the cows before firstH to see if they contain firstH
        for(int i = 0; i < firstH; i++) {
            if(breeds[i] == 'G' && lists[i] >= firstH) {
                ans++;
            }
        }
    }
    if(lists[firstG] >= lastG) {
        //firstG will be a natural leader

        if(lists[firstH] >= lastH) {
            //2 natural leaders
            ans++;
        }

        //check the cows before firstG to see if they contain firstG
        for(int i = 0; i < firstG; i++) {
            if(breeds[i] == 'H' && lists[i] >= firstG) {
                ans++;
            }
        }
    }


    cout << ans << '\n';
    return 0;
}