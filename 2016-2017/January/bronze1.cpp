#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

void make_cows(vector<pair<string, int>>& cows) {
	cows[0] = {"Annabelle", 0};
	cows[1] = {"Bessie", 0};
	cows[2] = {"Daisy", 0};
	cows[3] = {"Elsie", 0};
	cows[4] = {"Gertie", 0};
	cows[5] = {"Henrietta", 0};
	cows[6] = {"Maggie", 0};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int n; cin >> n;
	vector<pair<string, int>> cows(7);
	make_cows(cows);
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
	if(i == 7 || cows[i].second == cows[i+1].second) {
		cout << "Tie\n";
	} else {
		cout << cows[i].first << '\n';
	}
	return 0;
}