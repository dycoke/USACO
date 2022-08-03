#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
	int n; cin >> n;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	set<int> possible;
	for(int i = 0; i < n; i++) {
		possible.insert(numbers[i]);
		for(int j = 0; j < n; j++) {
			if(numbers[i] < numbers[j]) {
				possible.insert(numbers[j] - numbers[i]);
			}
		}
	}

	int ans = 0;
	for(int a : possible) {
		for(int b : possible) {
			for(int c : possible) {
				if(a <= b && b <= c) {
					vector<int> checks = {a, b, c, a + b, b + c, c + a, a + b + c};
					bool works = 0;
					for(int j = 0; j < n; j++) {
						works = 0;
						for(int i = 0; i < 7; i++) {
							if(numbers[j] == checks[i]) {
								works = 1;
								break;
							}
						}
						if(!works) {
							break;
						}
					}
					ans += works;
				}
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		solve_tc();
	}
	return 0;
}