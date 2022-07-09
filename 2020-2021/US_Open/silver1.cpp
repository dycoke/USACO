#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;

string grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][19683];
set<int> ans;

bool check_ttt(int board) {
	vector<vector<int>> ttt(3, vector<int>(3));
	int power = 6561;
	for(int i = 2; i >= 0; i--) {
		for(int j = 2; j >= 0; j--) {
			ttt[i][j] = board / power;
			board %= power; power /= 3;
		}
	}
	for(int i = 0; i < 3; i++) {
		if((ttt[i][0] == 2 && ttt[i][1] == 1 && ttt[i][2] == 1) || (ttt[i][0] == 1 && ttt[i][1] == 1 && ttt[i][2] == 2)) {
			return 1;
		}
	}
	for(int i = 0; i < 3; i++) {
		if((ttt[0][i] == 2 && ttt[1][i] == 1 && ttt[2][i] == 1) || (ttt[0][i] == 1 && ttt[1][i] == 1 && ttt[2][i] == 2)) {
			return 1;
		}
	}
	if((ttt[0][0] == 2 && ttt[1][1] == 1 && ttt[2][2] == 1) || (ttt[0][0] == 1 && ttt[1][1] == 1 && ttt[2][2] == 2) || (ttt[0][2] == 2 && ttt[1][1] == 1 && ttt[2][0] == 1) || (ttt[0][2] == 1 && ttt[1][1] == 1 && ttt[2][0] == 2))
		return 1;
	
	return 0;
}

void floodfill(int r, int c, int moves, int b) {if (grid[r][c][0] == '#' || visited[r][c][b]) {
		return;
	}
	if(grid[r][c][0] == 'M') {
		int x = grid[r][c][1] - '0', y = grid[r][c][2] - '0', pos = 3*(x-1) + y;
		int power = pow(3, pos);
		if((3*(b % power))/power == 0)
			b += ((2*power/3) - (3*(b % power)/power));
		moves++;
	} else if(grid[r][c][0] == 'O') {
		int x = grid[r][c][1] - '0', y = grid[r][c][2] - '0', pos = 3*(x-1) + y;
		int power = pow(3, pos);
		if((3*(b % power))/power == 0)
			b += ((power/3) - (3*(b % power)/power));
		moves++;
	}


	if(moves >= 3 && check_ttt(b)) {
		ans.insert(b);
		return;
	}
	visited[r][c][b] = 1;
	moves++;
	floodfill(r, c + 1, moves, b);
	floodfill(r, c - 1, moves, b);
	floodfill(r - 1, c, moves, b);
	floodfill(r + 1, c, moves, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	pair<int, int> bessie;
	for(int i = 0; i < n; i++) {
		string row; cin >> row;
		for(int j = 0; j < n; j++) {
			string t = row.substr(j*3, 3);
			grid[i][j] = t;
			if(grid[i][j][0] == 'B') {
				bessie.first = i; bessie.second = j;
			}
		}
	}
	floodfill(bessie.first, bessie.second, 0, 0);
	cout << ans.size() << '\n';
}
