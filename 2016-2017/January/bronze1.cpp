#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int n; cin >> n;
	vector<pair<string, int>> cows ({
		{"Annabelle", 0}, 
		{"Bessie", 0}, 
		{"Daisy", 0}, 
		{"Elsie", 0}, 
		{"Gertie", 0}, 
		{"Henrietta", 0}, 
		{"Maggie", 0}
	});
	
	for(int i = 0; i < n; i++) {
		string c; int produced;
		cin >> c >> produced;
		char cow = c[0];
		if(cow == 'A') {
			cows[0].second += produced;
		} else if(cow == 'B') {
			cows[1].second += produced;
		} else if(cow == 'D') {
			cows[2].second += produced;
		} else if(cow == 'E') {
			cows[3].second += produced;
		} else if(cow == 'G') {
			cows[4].second += produced;
		} else if(cow == 'H') {
			cows[5].second += produced;
		} else {
			cows[6].second += produced;
		}
	}

	sort(cows.begin(), cows.end(), cmp);
	int i = 0;
	while(i < 7 && cows[0].second == cows[i].second) {
		i++;
	}
	if(i == 7 || (i < 7 && cows[i].second == cows[i+1].second)) {
		cout << "Tie\n";
	} else {
		cout << cows[i].first << '\n';
	}
	return 0;
}