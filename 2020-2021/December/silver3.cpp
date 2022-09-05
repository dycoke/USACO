#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
vector<int> ans(1000, -1);
void dfs(int cow) {
	ans[cow] = 0;
	for(int& c : adj[cow]) {
		if(ans[c] == -1) {
			dfs(c);
		}
		ans[cow] += (ans[c] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<pair<int, int>> cows(n);
	vector<array<int, 3>> northcows, eastcows;
	for(int i = 0; i < n; i++) {
		char d; cin >> d;
		int x, y; cin >> x >> y;
		cows[i] = {x, y};
		if(d == 'N') {
			northcows.push_back({x, y, i});
		} else {
			eastcows.push_back({x, y, i});
		}
	}
	vector<array<int, 4>> collisions;
	//{time, stopper, victim, direction}
	for(auto& ncow : northcows) {
		for(auto& ecow : eastcows) {
			int dx = ncow[0] - ecow[0], dy = ecow[1] - ncow[1];
			if((dx < 0 || dy < 0) || (dx == dy)) {
				continue;
			} else if(dx > dy) {
				//east cow collides with north cows rut
				collisions.push_back({dx, ncow[2], ecow[2], 1});
			} else if(dy > dx) {
				//north cow collides with east cow's rut
				collisions.push_back({dy, ecow[2], ncow[2], 0});
			}
		}
	}
	
	sort(collisions.begin(), collisions.end(), [](array<int, 4> a, array<int, 4> b) {return a[0] < b[0];});
	vector<int> stopped(n, -1);
	for(auto& collision : collisions) {
		if(stopped[collision[1]] == -1 && stopped[collision[2]] == -1) {
			adj[collision[1]].push_back(collision[2]);
			stopped[collision[2]] = collision[0];
			continue;
		}
		if(stopped[collision[2]] == -1) {
			//basically means stopped[collision[1]] wasnt -1
			if(collision[3]) {
				int start = cows[collision[1]].second;
				int end = start + stopped[collision[1]];
				if(cows[collision[2]].second >= start && cows[collision[2]].second <= end) {
					adj[collision[1]].push_back(collision[2]);
					stopped[collision[2]] = collision[0];
				}
			} else {
				int start = cows[collision[1]].first;
				int end = start + stopped[collision[1]];
				if(cows[collision[2]].first >= start && cows[collision[2]].first <= end) {
					adj[collision[1]].push_back(collision[2]);
					stopped[collision[2]] = collision[0];
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(ans[i] == -1) {
			dfs(i);
		}
		cout << ans[i] << '\n';
	}
}
