#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int n; cin >> n;
	vector<int> shuffle(n), cows(n);
	for(int i = 0; i < n; i++) {
		cin >> shuffle[i];
		shuffle[i]--;
	}
	for(int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	for(int i = 0; i < n; i++) {
		int location = shuffle[shuffle[shuffle[i]]];
		cout << cows[location] << '\n';
	}
	return 0;
}