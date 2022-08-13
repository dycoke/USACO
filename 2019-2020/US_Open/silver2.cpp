#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> preferences(n);
	for(pair<int, int>& preference : preferences) {
		cin >> preference.first >> preference.second;
		preference.first--; preference.second--;
	}

	vector<int> taken(m);
	vector<int> answer(n + 1);
	for(int i = n - 1; i >= 0; i--) {
		answer[i] = answer[i + 1];
		int curr = preferences[i].first, curr_index = i;
		while(true) {
			if(!taken[curr]) {
				answer[i]++;
				taken[curr] = curr_index;
				break;
			} else if(taken[curr] < curr_index) {
				break;
			} else {
				int occ = taken[curr];
				taken[curr] = curr_index;
				if(preferences[occ].second == curr) {
					break;
				}
				curr_index = occ;
				curr = preferences[occ].second;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}