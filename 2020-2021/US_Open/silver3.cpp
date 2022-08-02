#include <bits/stdc++.h>
using namespace std;
#define ll long long

int papers[100000], n, k, l;

bool works(int h) {
	ll citings = (ll) k*l;
	for(int i = 0; i < h; i++) {
		int needed = max(0, h - papers[i]);
		citings -= needed;
		if(citings < 0 || needed > k) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> l;
	for(int i = 0; i < n; i++) {
		cin >> papers[i];
	}
	sort(papers, papers + n, greater<int>());
	int left = 1, right = n, ans;
	while(left <= right) {
		int mid = left + (right - left)/2;
		if(works(mid)) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}