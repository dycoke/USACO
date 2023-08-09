#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n, m; cin >> n >> m;
	int occur[n+1][2];
	bool exists[n+1][m];
	memset(occur, -1, sizeof(occur));
	memset(exists, 0, sizeof(exists));
	int occur2[m][n+1][2];
	memset(occur2, -1, sizeof(occur2));
	for(int i = 0; i < m; i++) {
		int k; cin >> k;

		for(int j = 0; j < k; j++) {
			int c; cin >> c;
			if(occur[c][0] == -1) {
				occur[c][0] = i;
			}
			if(occur2[i][c][0] == -1) {
				occur2[i][c][0] = j;
			}
			occur[c][1] = i;
			occur2[i][c][1] = j;
			exists[c][i] = 1;
		}
	}
	for(int c = 1; c <= n; c++) {
		//check if for each color they exists from start to finish
		for(int i = occur[c][0]; i <= occur[c][1]; i++) {
			if(i == -1) break;
			if(!exists[c][i]) {
				cout << "NO\n";
				return;
			}
		}
	}
	int relation[n+1][n+1]; memset(relation, 0, sizeof(relation));
	for(int c1 = 1; c1 <= n; c1++) {
		for(int c2 = 1; c2 <= n; c2++) {
			if(c1 == c2) continue;
			for(int i = 0; i < m; i++) {
				if(exists[c1][i] && exists[c2][i]) {
					int type = 0;
					int l1 = occur2[i][c1][0], l2 = occur2[i][c2][0];
					int r1 = occur2[i][c1][1], r2 = occur2[i][c2][1];
					if(l1 <= l2 && r1 >= r2) {
						type = 4;
						if(occur[c1][0] > occur[c2][0] || occur[c1][1] < occur[c2][1]) {
							cout << "NO\n";
							return;
						}
					}
					else if(l1 >= l2 && r1 <= r2) {
						type = 3;
						if(occur[c1][0] < occur[c2][0] || occur[c1][1] > occur[c2][1]) {
							cout << "NO\n";
							return;
						}
					}
					else if(r2 <= l1) type = 2;
					else if(l2 >= r1) type = 1;
					else {
						cout << "NO\n";
						return;
					}
					if(relation[c1][c2] != 0 && relation[c1][c2] != type) {
						cout << "NO\n";
						return;
					}
					relation[c1][c2] = type;
				}
			}
		}
	}
	cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
	
    return 0;
}