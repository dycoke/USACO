#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int grid[MAX_N][MAX_N];
int N, area, perimeter;
bool visited[MAX_N][MAX_N];

void floodfill(int r, int c, int color){
	if((r < 0 || r >= N || c < 0 || c >= N) || grid[r][c] != color) {
        perimeter++;
        return;
    } else if (visited[r][c])
		return;
	visited[r][c] = true;
	area++;
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x ++) {
        string t; cin >> t;
        for(int y = 0; y < N; y++) {
            if(t.at(y) == '#')
                grid[x][y] = 1;
            else
				grid[x][y] = 0;
        }
    }
	int max_a = 0, min_p = 4000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(!visited[i][j] && grid[i][j] == 1) {
				area = 0;
				perimeter = 0;
				floodfill(i, j, 1);
				if(area > max_a) {
					max_a = area;
					min_p = perimeter;
				} else if (area == max_a && perimeter < min_p)
					min_p = perimeter;
			}
		}
	}
	cout << max_a << " " << min_p;
    return 0;
}
