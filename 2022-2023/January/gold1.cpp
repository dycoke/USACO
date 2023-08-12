#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

struct node {
	node *l, *r;
	ll size;
	char c;
	void print_sub(ll left, ll right) {
		if(left > 0 && right > 0) {
			if(c != '.') {
				cout << c;
			} else {
				if(left <= l->size) {
					l->print_sub(left, min(right, l->size));
				}
				if(right > l->size) {
					r->print_sub(max(1LL, left-(l->size)), right-(l->size));
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll l, r; int n;
	cin >> l >> r >> n;
	char c[n]; string s[n];
	for(int i = 0; i < n; i++) {
		cin >> c[i] >> s[i];
	}
	node* nodes[26];
	for(int i = 0; i < 26; i++) {
		nodes[i] = new node{nullptr, nullptr, 1, char('a'+i)};
	}
	for(int i = n-1; i >= 0; i--) {
		node* merge = nullptr;
		for(int j = s[i].size() - 1; j >= 0; j--) {
			char q = s[i][j];
			if(merge == nullptr) {
				merge = nodes[q-'a'];
			} else {
				merge = new node{nodes[q-'a'], merge, min(merge->size + nodes[q-'a']->size, INF), '.'};
			}
		}
		nodes[c[i]-'a'] = merge;
	}
	nodes[0]->print_sub(l, r);
	cout << '\n';
	return 0;
}