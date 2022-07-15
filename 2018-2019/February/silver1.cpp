#include <bits/stdc++.h>
using namespace std;
bool ycomp (pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	int n; cin >> n;
	vector<int> cows(n);
	for(int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	sort(cows.begin(), cows.end());
	int mn, mx;
	if((cows[n-2] - cows[0] == n-2 && cows[n-1] - cows[n-2] > 2) || (cows[n-1] - cows[1] == n-2 && cows[1] - cows[0] > 2)) {
		mn = 2;
	} else {
		int l = 0, r = 0, mx1 = 0;
		while(r < n) {
			if(cows[r] - cows[l] < n) {
				mx1 = max(mx1, r - l + 1);
				r++;
			} else {
				l++;
			}
		}
		mn = n - mx1;
	}
	mx = (cows[n-1] - cows[0] + 1) - n - min(cows[n-1] - cows[n-2] - 1, cows[1] - cows[0] - 1);
	cout << mn << '\n' << mx << '\n';
}
