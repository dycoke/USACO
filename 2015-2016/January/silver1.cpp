#include <bits/stdc++.h>
using namespace std;

int n, k;
bool works(vector<int>& haybales, int radius) {
	int cows_shot = 0;
	for(int i = 0; i < n; i++) {
		cows_shot++;
		int left_most = i;
		while(i < n && haybales[i] <= haybales[left_most] + 2*radius) {
			i++;
		}
		i--;
	}
	return cows_shot <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n >> k;
	vector<int> haybales(n);
	for(auto& haybale : haybales) {
		cin >> haybale;
	}
	sort(haybales.begin(), haybales.end());
	int left = 1, right = haybales[n-1], ans = 0;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(works(haybales, mid)) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}