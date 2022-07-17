#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	int n; cin >> n;
	vector<int> questions(n);
	for(int i = 0; i < n; i++) {
		cin >> questions[i];
	}
	int mn = min(questions[n-1], questions[n-2]), total = questions[n-1] + questions[n-2];
	float mx = (float) (total-mn);
	vector<int> ans;
	ans.push_back(n-2);
	for(int i = n-3; i >= 1; i--) {
		total += questions[i];
		mn = min(mn, questions[i]);
		float t = (float) (total-mn)/(n - i - 1);
		if(t > mx) {
			mx = t;
			ans.clear();
			ans.push_back(i);
		} else if(t == mx) {
			ans.push_back(i);
		}
	}
	for(int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}
	return 0;
}
