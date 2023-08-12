#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; ll m; cin >> n >> k >> m;
    ll dances = m/k; int moves = m % k;

	vector<int> cows(n), seen[n];
	vector<pair<int, int>> seen2[n];
	for(int i = 0; i < n; i++) {
		cows[i] = i;
		seen[i].push_back(i);
		seen2[i].push_back({i, 0});
	}

	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		swap(cows[a], cows[b]);
		seen[cows[b]].push_back(b);
		seen[cows[a]].push_back(a);
		seen2[cows[b]].push_back({b, i+1});
		seen2[cows[a]].push_back({a, i+1});
	}
	vector<int> ind(n);
	for(int i = 0; i < n; i++) {
		ind[cows[i]] = i;
	}
	vector<bool> visited(n);
	vector<int> ans(n), cnt(n, 0);
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			int t = ind[i];
			vector<int> cycle;
			while(!visited[t]) {
				cycle.push_back(cows[t]);
				visited[t] = true;
				t = ind[t];
			}
            if(dances >= cycle.size()) {
                unordered_set<int> seen_cycle;
                for(int& cow : cycle) {
                    for(int& seen_cow : seen[cow]) {
                        seen_cycle.insert(seen_cow);
                    }
                }
                for(int& cow : cycle) {
                    ans[cow] = seen_cycle.size();
                }
            } else {
				// sliding window of size moves
				int num_dif = 0;
				for(int i = 0; i < dances; i++) {
					for(int cow: seen[cycle[i]]) {
						if(cnt[cow] == 0) {
							num_dif++;
						}
						cnt[cow]++;
					}
				}
				int l = 0, r = dances;
				for(int cow: cycle) {
					ans[cow] = num_dif;
					for(pair<int, int> seen_cow: seen2[cycle[r]]) {
						if(seen_cow.second > moves) {
							break;
						}
						if(cnt[seen_cow.first] == 0) {
							ans[cow]++;
						}
						cnt[seen_cow.first]++;
					}
					for(pair<int, int> seen_cow: seen2[cycle[r]]) {
						if(seen_cow.second > moves) {
							break;
						}
						cnt[seen_cow.first]--;
					}
					for(int seen_c: seen[cycle[l]]) {
						cnt[seen_c]--;
						if(cnt[seen_c] == 0) {
							num_dif--;
						}
					}
					for(int seen_c: seen[cycle[r]]) {
						if(cnt[seen_c] == 0) {
							num_dif++;
						}
						cnt[seen_c]++;
					}
					l = (l + 1) % cycle.size();
					r = (r + 1) % cycle.size();
				}
				for(int cow: cycle) {
					for(int seen_cow: seen[cow]) {
						cnt[seen_cow] = 0;
					}
				}
            }
		}
	}
	for(int answer : ans) {
		cout << answer << '\n';
	}
	return 0;
}