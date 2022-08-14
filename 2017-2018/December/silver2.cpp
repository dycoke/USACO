#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n, g; cin >> n >> g;
	vector<pair<int, pair<int, int>>> logs(n);
	unordered_map<int, int> cows;
	multiset<int> lb;
	for(int i = 0; i < n; i++) {
		cin >> logs[i].first >> logs[i].second.first >> logs[i].second.second;
		cows[logs[i].second.first] = g;
		lb.insert(g);
	}
	sort(logs.begin(), logs.end());
	int ans = 0;
	for(pair<int, pair<int, int>> lo : logs) {
		pair<int, int> l = lo.second;
		cows[l.first] += l.second;
		if(cows[l.first] > *lb.rbegin()) { //obtaining first place
			ans++;
			if(lb.count(cows[l.first] - l.second) == 1 && cows[l.first] - l.second == *lb.rbegin()) //aready first place
				ans--;
			lb.erase(lb.find(cows[l.first] - l.second));
			lb.insert(cows[l.first]);
		} else if(cows[l.first] == *lb.rbegin()) { //sharing first place
			ans++;
			lb.erase(lb.find(cows[l.first] - l.second));
			lb.insert(cows[l.first]);
		} else {
			int t = *lb.rbegin();
			lb.erase(lb.find(cows[l.first] - l.second));
			lb.insert(cows[l.first]);
			if(cows[l.first] == *lb.rbegin()) { //in first place
				ans++;
				if(lb.count(cows[l.first]) == 1 && t == cows[l.first] - l.second) //only one first place and was first place last time
					ans--;
			} else if(t == cows[l.first] - l.second && cows[l.first] != *lb.rbegin()) { //in first place last time but lost
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
