#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool gcomp(pair<int,int> a, pair<int,int> b) {
	return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	ll farms[r+1], cows[n+1];
	int cow[n];
	pair<int,int> stores[m];
	for(int i = 0; i < n; i++) {
		cin >> cow[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> stores[i].first >> stores[i].second;
	}
	for(int i = 1; i <= r; i++) {
		cin >> farms[i];
	}
	sort(stores, stores + m, gcomp);
	sort(cow, cow + n, greater<int>());
	sort(farms + 1, farms + r + 1, greater<ll>());
	farms[0] = 0;
	cows[0] = 0;
	int store = 0; //i dont want to admit that i put that into the loop
	//but i did... and made the code dogshit
	//LUCKILY I CAUGHT IT AND IT WORKS NOW
	for(int i = 1; i <= n; i++) {
		cows[i] = cows[i-1];
		while(cow[i-1] && store < m) {
			int use = min(cow[i-1], stores[store].first);
			cow[i-1] -= use;
			stores[store].first -= use;
			cows[i] += (ll) (use*stores[store].second);
			if(stores[store].first == 0) {
				store++;
			}
		}
	}
	for(int i = 1; i <= r; i++) {
		farms[i] += farms[i-1];
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = max(ans, cows[n-i] + (ll) (farms[min(i, r)]));
	}
	cout << ans << '\n';
}
