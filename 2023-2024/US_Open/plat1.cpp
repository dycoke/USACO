#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

struct Node {
    bool e;
    int dis;
    Node *l, *r;
    Node() : l(nullptr), r(nullptr), e(false) {
        dis = 1;
    }

    Node(bool en) : l(nullptr), r(nullptr), e(en) {
        dis = 2;
    }

    Node(Node *tl, Node *tr, bool en) : l(tl), r(tr), e(en) {
        if(!l || !r) dis = 1;
        else dis = min(tl->dis, tr->dis) + 1;
    }

    void upd() {
        if(!l && !r) dis = 2;
        else if(!l || !r) dis = 1;
        else dis = min(l->dis, r->dis) + 1;
    }

    bool dir() {
        if(!l) return false;
        else if(!r) return true;
        else return (r->dis) == (dis - 1);
    }

    bool is_leaf() {
        return !l && !r;
    }
};

int ans = 0;

void pushdown(Node *node) {
    ans += 2;
    node->l = new Node(true);
    node->r = new Node(true);
    node->e = false;
}

void trav(Node *node) {
    if(node->is_leaf()) {
        if(node->e) {
            pushdown(node);
            // cout << "pushed\n";
        } else {
            node->e = true;
            node->dis = 2;
            // cout << "end\n";
        }
    } else {
        // cout << node->dir() << '\n';
        // cout << node->dis << '\n';
        ans++;
        if(node->dir()) {
            if(!node->r) {
                node->r = new Node();
            }
            trav(node->r);
        } else {
            if(!node->l) {
                node->l = new Node();
            }
            trav(node->l);
        }
    }
    node->upd();
}

void ins(Node *node, const string& str, int i = 0) {
    // if(i == 0)
    //     cout << "hi: " << str << '\n';
    if(i == str.size()) {
        trav(node);
    } else {
        if(str[i] == '0') {
            if(!node->l) {
                node->l = new Node();
            }
            ins(node->l, str, i + 1);
        } else {
            if(!node->r) {
                node->r = new Node();
            }
            ins(node->r, str, i + 1);
        }
    }
    node->upd();
}

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [](string& a, string& b) {
        return a.size() > b.size();
    });

    Node *root = new Node();
    for(string &ss : s) {
        ins(root, ss);
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.in", "r", stdin);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}