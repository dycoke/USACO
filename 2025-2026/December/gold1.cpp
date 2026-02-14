#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU {
    private:
        vector<int> e;
        vector<int> v;

    public:
        DSU(int n) {
            e = vector<int>(n, -1);
            v = vector<int>(n);
        }
        
        int get(int x) {
            return e[x] < 0 ? x : e[x] = get(e[x]);
        }

        bool same_set(int a, int b) {
            return get(a) == get(b);
        }

        int val(int x) {
            return v[get(x)];
        }

        void set(int x, int val) {
            v[get(x)] = val;
        }

        int size(int x) {
            return -e[get(x)];
        }

        bool unite(int x, int y, int val) {
            x = get(x), y = get(y);
            if (x == y) {
                v[x] = val;
                return false;
            }
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y]; e[y] = x;
            v[x] = val;
            return true;
        }
};

const int N = 2e5 + 5, LOG = 18;

bool vis[N], cycle[N];
int a[N];
vector<int> adj[N];
DSU dsu(0);

void dfs(int u, int p, int pp) {
    if(vis[u]) {
        pp = u;
    }
    dsu.unite(u, pp, pp);
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, pp);
        }
    }
}

void rev(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            rev(v);
        }
    }
}

void floyd(int x) {
    int f = x, s = x;
    do {
        f = a[a[f]];
        s = a[s];
    } while(f != s);

    do {
        cycle[f] = true;
        f = a[f];
    } while(f != s);

    rev(f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("out.txt", "w", stdout);

    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        adj[a[i]].push_back(i);
        vis[i] = false;
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            floyd(i);
        }
    }

    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    vector<int> roots;

    vector<array<int, 2>> parties;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t;
        int x; char c;
        cin >> x >> c;
        x--;
        if(c == 'C') {
            t = 0;
        } else if(c == 'O') {
            t = 1;
        } else {
            t = 2;
        }

        if(cycle[x] && !vis[x]) {
            // set x as the root
            auto it = find(adj[a[x]].begin(), adj[a[x]].end(), x);
            adj[a[x]].erase(it);
            a[x] = -1;
            rev(x);
            roots.push_back(x);
        }

        parties.push_back({x, t});
    }

    for(int i = 0; i < n; i++) {
        if(cycle[i] && !vis[i]) {
            auto it = find(adj[a[i]].begin(), adj[a[i]].end(), i);
            adj[a[i]].erase(it);
            rev(i);
            a[i] = -1;
            roots.push_back(i);
        }
    }

    // cout << "roots: " << '\n';
    // for(int u : roots) {
    //     cout << u << ' ';
    // }
    // cout << '\n';

    // cout << "adj: " << '\n';
    // for(int u = 0; u < n; u++) {
    //     cout << u << ": ";
    //     for(int v : adj[u]) {
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    vector<int> cur(n, -1), prv(q);
    for(int i = 0; i < q; i++) {
        auto [x, t] = parties[i];
        vis[x] = true;
        prv[i] = cur[x];
        cur[x] = t;
    }

    dsu = DSU(n);

    for(int u : roots) {
        dfs(u, -1, u);
    }

    array<int, 3> ans = {0, 0, 0};

    for(int i = 0; i < n; i++) {
        if(vis[i]) {
            ans[cur[i]] += dsu.size(i);
        }
        // cout << a[i] << ' ';
    }
    // cout << '\n';

    // cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

    vector<array<int, 3>> res;
    res.push_back(ans);
    for(int i = q - 1; i >= 0; i--) {
        auto [x, t] = parties[i];
        if(cur[x] != -1) {
            ans[cur[x]] -= dsu.size(x);
        }
        cur[x] = prv[i];
        if(cur[x] != -1) {
            ans[cur[x]] += dsu.size(x);
        }
        if(prv[i] == -1) {
            // merge with parent
            if(a[x] != -1) {
                int siz = dsu.size(x);
                dsu.unite(x, a[x], dsu.val(a[x]));
                if(dsu.val(x) != -1) {
                    int temp = cur[dsu.val(x)];
                    if(temp != -1) {
                        ans[temp] += siz;
                    }
                }
            }
        }
        res.push_back(ans);
    }
    reverse(res.begin(), res.end());
    // assert(res.size() == q + 1);
    for(int i = 1; i < res.size(); i++) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << '\n';
    }
    return 0;
}
