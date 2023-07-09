#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);

	int n; cin >> n;
	int dishes[n];
	for(int i = 0; i < n; i++) cin >> dishes[i];
	deque<int> top, bottom;
	int ans = 0, mx = 0;
	set<int> done; done.insert(0);
	for(; ans < n; ans++) {
		int d = dishes[ans];
		auto it = lower_bound(bottom.begin(), bottom.end(), d);
		if(it == bottom.end()) {
			bottom.push_back(d);
			top.push_back(d);
		} else {
			if(mx > d) {
				break;
			}
			int ind = it - bottom.begin();
			if(d < top[ind]) top[ind] = d;
			else {
				while(ind--) {
					top.pop_front();
					bottom.pop_front();
				}
				auto mit = done.lower_bound(d); mit--;
				mx = max(mx, *mit);
				top[0] = d;
			}
		}
		done.insert(d);
	}
	cout << ans << '\n';
    return 0;
}