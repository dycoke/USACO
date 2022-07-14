#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MOD = 1000000007;

bool ycomp(pair<int,int> a, pair<int, int> b) {
	if(a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int n; cin >> n;

	vector<pair<int,int> > posts(n);
	map<pair<int, int>, int> pasture;

	for(int i = 0; i < n; i++) {
		cin >> posts[i].first >> posts[i].second;
		pasture[posts[i]] = i;
	}
	
	sort(posts.begin(), posts.end());
	
	vector<ll> vertical(n);
	for(int i = 0; i < n - 1; i++) {
		int j = i + 1, same = 1;
		while(j < n && posts[i].first == posts[j].first) {
			vertical[pasture[posts[i]]] += (posts[j].second - posts[i].second);
			j++; same++;
		}
		j = i + 1;
		while(j < n && posts[i].first == posts[j].first) {
			vertical[pasture[posts[j]]] = vertical[pasture[posts[j-1]]] + (posts[j].second - posts[j-1].second) * (2*j - 2*i - same);
			j++;
		}
		i = j - 1;
	}

	sort(posts.begin(), posts.end(), ycomp);

	vector<ll> horizontal(n);
	for(int i = 0; i < n - 1; i++) {
		int j = i + 1, same = 1;
		while(j < n && posts[i].second == posts[j].second) {
			horizontal[pasture[posts[i]]] += (posts[j].first - posts[i].first);
			j++; same++;
		}
		j = i + 1;
		while(j < n && posts[i].second == posts[j].second) {
			horizontal[pasture[posts[j]]] = horizontal[pasture[posts[j-1]]] + (posts[j].first - posts[j-1].first) * (2*j - 2*i - same);
			j++;
		}
		i = j - 1;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += vertical[pasture[posts[i]]] * horizontal[pasture[posts[i]]];
	}

	cout << ans % MOD << "\n";
	return 0;
}
