#include <bits/stdc++.h>
using namespace std;

int succ[52], component_size;
vector<int> reversed[52];
bool visited[52];

int getIndex(char c) {
    return c >= 'a' ? (c - 'a' + 26) : c - 'A';
}

void mark_visited(int node) {
    visited[node] = 1;
    component_size++;
    for(int& n: reversed[node]) {
        if(!visited[n]) {
            mark_visited(n);
        }
    }
}

int get_cycle_length(int x) {
    int a = x, b = x;
    do {
        if(succ[b] == -1) {
            mark_visited(b);
            return 0;
        } else if (succ[succ[b]] == -1) {
            mark_visited(succ[b]);
            return 0;
        }
        a = succ[a];
        b = succ[succ[b]];
    } while(a != b);
    b = a;
    int length = 0;
    do {
        b = succ[b];
        length++;
    } while(a != b);
    mark_visited(a);
    return length;
}

void solve() {
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < 52; i++) {
        succ[i] = -1;
        reversed[i].clear();
        visited[i] = 0;
    }
    int num_diff = 0;
    for(int i = 0; i < a.size(); i++) {
        int indexA = getIndex(a[i]), indexB = getIndex(b[i]);
        if(succ[indexA] != -1 && succ[indexA] != indexB) {
            cout << "-1\n";
            return;
        } else if(succ[indexA] != -1 && succ[indexA] == indexB) {
            continue;
        }
        num_diff++;
        succ[indexA] = indexB;
        reversed[indexB].push_back(indexA);
    }
    int ans = 0;
    bool all_cycles = 1;
    for(int i = 0; i < 52; i++) {
        if(succ[i] != -1 && !visited[i]) {
            component_size = 0;
            int cycle_length = get_cycle_length(i);
            if(cycle_length == 0) { //broken cycle
                all_cycles = 0;
                ans += component_size - 1;
            } else if(cycle_length == 1) { //single length cycle
                if(component_size != cycle_length) { //collapseable
                    all_cycles = 0;
                }
                ans += component_size - 1;
            } else { //multi length cycle
                if(component_size == cycle_length) { //non-collapseable
                    ans += component_size + 1;
                } else { //collapseable
                    all_cycles = 0;
                    ans += component_size;
                }
            }
        }
    }
    if(num_diff == 52 && all_cycles && ans != 0) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    return;
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