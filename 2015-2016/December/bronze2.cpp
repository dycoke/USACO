#include <bits/stdc++.h>
using namespace std;

int main() {
  	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	int N, M;
	cin >> N >> M;
	int ans = 0;
	int limits[100];
	int journey[100];
	int index = 0;
	for(int i = 0; i < N; i++) {
		int length, limit;
		cin >> length >> limit;
		int temp = index + length;
		for(; index < temp; index++) {
			limits[index] = limit;
		}
	}
	index = 0;
	for(int i = 0; i < M; i++) {
		int length, speed;
		cin >> length >> speed;
		int temp = index + length;
		for(; index < temp; index++) {
			journey[index] = speed;
		}
	}
	for(int i = 0; i < 100; i++) {
		ans = max(ans, max((journey[i] - limits[i]), 0));
	}
	cout << ans << endl;
}
