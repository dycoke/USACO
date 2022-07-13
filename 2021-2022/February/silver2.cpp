//THE PROBLEM FUCKIGN SUCKS
//BRIAN DEAN GO DIE IN A FUCKING HOLE
//WHY THE FUCK DO I PASS ALL BUT 2 TC THEN I PASS LIKE HALF THE TESTCASES RIGHT AFTEURTDGHFJDGHKJFH
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, targx, targy;
vector<pair<int,int>> subset;
pair<int, int> moves[40];
map<pair<int,int>, vector<int>> subs;
int ans[40];
void gen1(int k) {
	if (k == n/2) {
		int x = 0, y = 0;
		for(pair<int, int> move : subset) {
			x += move.first;
			y += move.second;
		}
		subs[{x, y}].push_back(subset.size());
	} else {
		gen1(k+1);
		subset.push_back(moves[k]);
		gen1(k+1);
		subset.pop_back();
	}
}
void gen2(int k) {
	if(k == n) {
		int x = targx, y = targy;
		for(pair<int, int> move : subset) {
			x -= move.first;
			y -= move.second;
		}
		if(subs.count({x, y})) {
			for(int length : subs[{x,y}])
				ans[length + subset.size() - 1]++;
		}
	} else {
		gen2(k+1);
		subset.push_back(moves[k]);
		gen2(k+1);
		subset.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> targx >> targy;
	for(int i = 0; i < n; i++) {
		cin >> moves[i].first >> moves[i].second;
	}
	gen1(0);
	subset = vector<pair<int,int>>(0);
	gen2(n/2);
	for(int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
}
