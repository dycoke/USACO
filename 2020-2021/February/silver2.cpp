#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> ancestors(n);
	for(int& ancestor : ancestors) {
		cin >> ancestor;
	}
	ancestors.push_back(0);
	sort(ancestors.begin(), ancestors.end(), greater<int>());
	vector<int> gaps;
	int time = (ancestors[0]/12)*12;
	for(int i = 0; i <= n; i++) {
		while(i <= n && ancestors[i] >= time) {
			i++;
		}
		int gap = abs(((ancestors[i] + 11)/12)*12 - time);
		gaps.push_back(gap);
		time = (ancestors[i]/12)*12;
	}
	sort(gaps.begin(), gaps.end(), greater<int>());
	int ans = ((ancestors[0] + 11)/12)*12;
	for(int i = 0; i < k - 1; i++) {
		ans -= gaps[i];
	}
	cout << ans << '\n';
	return 0;
}