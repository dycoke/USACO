#include <bits/stdc++.h>
using namespace std;

bool ycmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

pair<int, int> A[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A, A + n);
	for(int i = 0; i < n; i++) {
		A[i].first = i;
	}
	sort(A, A + n, ycmp);
	int ans = 0;
	for(pair<int, int>& a : A) {
		ans = max(ans, a.second - a.first);
	}
	cout << ans + 1 << '\n';
	return 0;
}