#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int n; cin >> n;
	vector<int> shuffle(n), parent(n);
	for(int i = 0; i < n; i++) {
		int a; cin >> a; a--;
		shuffle[i] = a;
		parent[a]++;
	}
	queue<int> orphans; //very fitting name
	int ans = n;
	for(int i = 0; i < n; i++) {
		if(parent[i] == 0) {
			orphans.push(i);
			ans--;
		}
	}
	while(!orphans.empty()) {
		int i = orphans.front();
		orphans.pop();
		if(!--parent[shuffle[i]]) {
			ans--;
			orphans.push(shuffle[i]);
		}
	}
	cout << ans << '\n';
	return 0;
}