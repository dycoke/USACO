#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> cows(n), seen[n];
	for(int i = 0; i < n; i++) {
		cows[i] = i;
		seen[i].push_back(i);
	}

	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		swap(cows[a], cows[b]);
		seen[cows[b]].push_back(b);
		seen[cows[a]].push_back(a);
	}

	vector<bool> visited(n);
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			int t = i;
			vector<int> cycle;
			while(!visited[t]) {
				cycle.push_back(t);
				visited[t] = true;
				t = cows[t];
			}
			unordered_set<int> seen_cycle;
			for(int& cow : cycle) {
				for(int& seen_cow : seen[cow]) {
					seen_cycle.insert(seen_cow);
				}
			}
			for(int& cow : cycle) {
				ans[cow] = seen_cycle.size();
			}
		}
	}
	for(int& answer : ans) {
		cout << answer << '\n';
	}
	return 0;
}