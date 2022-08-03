#include <bits/stdc++.h>
using namespace std;

int n, t;

bool works(vector<int>& cows, int k) {
	int i = 0, time = 0;
	priority_queue<int, vector<int>, greater<int>> stage;
	while(i < n) {
		if(stage.size() == k) {
			time = stage.top();
			stage.pop();
		}
		if(time + cows[i] > t) {
			return 0;
		}
		stage.push(time + cows[i++]);
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin >> n >> t;
	vector<int> cows(n);
	for(int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	int l = 0, r = n;
	while(l < r) {
		int mid = l + (r - l)/2;
		if(works(cows, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}