#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	
	int n; cin >> n;
	int colors[n];
	int start[n], finish[n];
	memset(start, -1, sizeof(start));
	for(int i = 0; i < n; i++) {
		cin >> colors[i];
		--colors[i];
		if(start[colors[i]] == -1) start[colors[i]] = i;
		finish[colors[i]] = i;
	}
	bool events[2][n]; memset(events, 0, sizeof(events));
	for(int i = 0; i < n; i++) {
		if(start[i] != -1) {
			events[0][start[i]] = 1;
			events[1][finish[i]] = 1;
		}
	}
	stack<int> curr;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(events[0][i]) curr.push(colors[i]);
		if(events[1][i]) {
			ans = max(ans, (int) curr.size());
			if(curr.top() != colors[i]) {
				ans = -1;
				break;
			}
			curr.pop();
		}
	}
	cout << ans << '\n';
    return 0;
}