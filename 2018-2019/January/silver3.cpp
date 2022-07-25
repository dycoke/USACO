/*
peak1: (x1, y1)
peak2: (x2, y2)
if (x1 - y1 <= x2 - y2 && x1 + y1 >= x2 + y2):
	mountain 1's base covers mountain 2's base
	thus, mountain 1 covers mountain 2
this gives us a rough comprarator to sort by let (x - y)
two mountains dont cover each other if either:
	left is fewer than current
	right is greater than current
since we have sorted by left,
we only need to consider everytime right becomes greater 
this gives us an algorithm thats runs in O(N log N) because of sorting
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> mountains(n);
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		mountains[i].first = x - y;
		mountains[i].second = x + y;
	}
	sort(mountains.begin(), mountains.end(), cmp);
	int mx_right = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		if(mountains[i].second > mx_right) { //found new rightmost
			ans++;
			mx_right = mountains[i].second;
		}
	}
	cout << ans << '\n';
}
