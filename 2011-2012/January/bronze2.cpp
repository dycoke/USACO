#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//commented out the files cuz online judge used stdin/out
	// freopen("stacking.in", "r", stdin);
	// freopen("stacking.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> prefix(n+1);
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		prefix[a]++;
		prefix[b+1]--;
	}
	for(int i = 1; i <= n; i++) {
		prefix[i] += prefix[i-1];
	}
	sort(prefix.begin(), prefix.end());
	cout << prefix[((n+1)/2)] << '\n';
}
