#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4005;

bool grid[MAX_N][MAX_N];
int mnx = 2002, mny = 2002, mxx = 2002, mxy = 2002;

void floodfill(int r, int c){
	if ((r < mnx || r >= mxx || c < mny || c >= mxy) || grid[r][c])
        return;
	
	grid[r][c] = 1;
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	int n; string directions; 
	cin >> n >> directions;
	int dirx, diry, x = 2002, y = 2002;
	grid[x][y] = 1;
	for(int i = 0; i < n; i++) {
		if(directions[i] == 'N')
			dirx = 0, diry = 1;
		else if(directions[i] == 'S')
			dirx = 0, diry = -1;
		else if(directions[i] == 'E')
			dirx = 1, diry = 0;
		else
			dirx = -1, diry = 0;
		for(int j = 0; j < 2; j++) {
			x += dirx;
			y += diry;
			grid[x][y] = 1;
			
		}
		mxx = max(mxx, x); mnx = min(mnx, x);
		mxy = max(mxy, y); mny = min(mny, y);
	}
	mxx+=2, mxy+=2;
	mnx--, mny--;
	int ans = 0;
	for(int i = mnx; i < mxx; i++) {
		for(int j = mny; j < mxy; j++) {
			if(!grid[i][j]) {
				floodfill(i, j);
				ans++;
			}
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}