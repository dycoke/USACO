#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	int table[8] = {1, 2, 4, 7, 8, 11, 13, 14};
	int n; cin >> n;
	n--;
	cout << 15*(n/8) + table[n%8] << '\n';
	return 0;
	
}
