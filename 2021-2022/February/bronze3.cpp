#include <bits/stdc++.h>
using namespace std;

void solve(array<string, 4>& blocks) {
	string word; cin >> word;
	for(int b1 = 0; b1 < 6; b1++) {
		for(int b2 = 0; b2 < 6; b2++) {
			for(int b3 = 0; b3 < 6; b3++) {
				for(int b4 = 0; b4 < 6; b4++) {
					unordered_multiset<char> tower;
					tower.insert(blocks[0][b1]);
					tower.insert(blocks[1][b2]);
					tower.insert(blocks[2][b3]);
					tower.insert(blocks[3][b4]);
					for(int i = 0; i < word.size(); i++) {
						if(tower.count(word[i]) == 0) {
							goto NEXT;
						} else {
							tower.erase(tower.find(word[i]));
						}
					}
					cout << "YES\n";
					return;
					NEXT:;
				}
			}
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	array<string, 4> blocks;
	for(int i = 0; i < 4; i++) {
		cin >> blocks[i];
	}

	while(n--) {
		solve(blocks);
	}
	return 0;
}