#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool works(ll n, ll k, ll m, ll x) {
	//since n k and m all change, we cant just modify the original variables without making a copy
	ll gallons = 0;
	while(k > 0 && gallons < n) {
		ll y = (n - gallons)/x; //gallons giving to bessie
		if(y < m) {
			/* if the number of gallons left to give rounded to the nearest multiple of m
			is less than the days left to give */
			return (n - gallons + m - 1)/m <= k;
		}
		//max number of y gallons given to bessie while y doesn't change
		ll right = n - x*y;
		//get the number of days with g gallons given to bessie each day
		ll days = (right - gallons) / y + 1;
		if(days > k) {
			days = k;
		}
		k -= days;
		gallons += days * y;
	}
	return gallons >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
	ll n, k, m;
	cin >> n >> k >> m;
	ll l = 1, r = 1000000000000LL;
	//binary search for the answer
	while(l < r) {
		ll mid = l + (r - l + 1)/2;
		if(works(n, k, m, mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	//l and r are the same, output either one
	cout << l << '\n';
	return 0;
}