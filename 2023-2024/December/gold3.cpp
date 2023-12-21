#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin >> n;
    //duplicate elements in x exist
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	vector<array<int, 2>> x;
	for(auto c: cnt) {
		x.push_back({c.first, c.second});
	}
	n = x.size();
	//sum of distances from left & right side
	ll prefixl[n], prefixr[n];
	prefixl[0] = 0; prefixr[n-1] = 0;
	int num = x[0][1];
	for(int i = 1; i < n; i++) {
		prefixl[i] = prefixl[i-1] + (x[i][0] - x[i-1][0])*num;
		num += x[i][1];
	}
	num = x[n-1][1];
	for(int i = n-2; i >= 0; i--) {
		prefixr[i] = prefixr[i+1] + (x[i+1][0] - x[i][0])*num;
		num += x[i][1];
	}
    int q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        int l = 1, r = n-1;
        while(l < r) {
            int mid = l + (r - l + 1)/2;
			//basically see if it is still decreasing
            if(prefixl[mid]*a + prefixr[mid]*b < prefixl[mid-1]*a + prefixr[mid-1]*b) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ll ans = prefixl[l]*a + prefixr[l]*b;
        //bruh bsearch didnt cover index 0
        ans = min(ans, prefixl[0]*a + prefixr[0]*b);

        cout << ans << '\n';
    }

    return 0;
}
/*
idea:
the optimal always occurs on a location in x
(consider moving left or right, always increases)
claim:
	values can never repeat
proof:
	let c be the value that repeats
	then a*x + b*y = c for some value x and y determined by prefixl and prefixr
	linear equation, meaning it is bijective
binary search should work
*/