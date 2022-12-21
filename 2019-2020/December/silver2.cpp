/*
realise that cows basically pass through each other if you dont consider the weights
the number of cows on each side is determined by the direction
there is a dividing line between cows ending up on left and right
ex. < < > < | > > > < >
left sides end up on left, right side ends up on right
the closest cows to the barns end up on the barns first
you can effectively tell when a certain cow ends up on a barn
loop through until you get half of the weights of cows on barns
the number of meetings is just the number of opposite facing cows in 2*time distance in a direction
i used binary search for this, im sure theres better ways but it doesnt really affect the time complexity because sorting
since 2 cows meeting counts as one meeting,only check for one direction to avoid overcomputation
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	int n, l; cin >> n >> l;
	//{weight, pos}, stop_time
	vector<pair<pair<int, int>, int>> cows(n);
	vector<int> left, right;
	//stop_time, direction(1 for right, 0 for left)
	vector<pair<int, bool>> distances(n);
	int sumweights = 0;
	for(int i = 0; i < n; i++) {
		int w, x, d; cin >> w >> x >> d;
		cows[i].first = {w, x};
		sumweights += w;
		if(d == 1) {
			right.push_back(x);
			distances[i] = {l-x, 1};
		} else {
			left.push_back(x);
			distances[i] = {x, 0};
		}
	}
	//sort by position
	sort(cows.begin(), cows.end(), 
	[](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.first.second < b.first.second;
	});
	sort(distances.begin(), distances.end(),
	[](pair<int, bool> a, pair<int, bool> b) {
		return a.first < b.first;
	});
	//find the time cow reaches barn
	int leftp = 0, rightp = n-1;
	for(int i = 0; i < n; i++) {
		if(distances[i].second) {
			cows[rightp].second = distances[i].first;
			rightp--;
		} else {
			cows[leftp].second = distances[i].first;
			leftp++;
		}
	}
	//sort by time cow reaches barn
	sort(cows.begin(), cows.end(), 
	[](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if(a.second == b.second)
			return a.first.first > b.first.first;
		return a.second < b.second;
	});
	//find stopping time
	int sum = 0, etime = -1;
	while((sum << 1) < sumweights) { //bit shifting to save time because its multiplying by 2
		sum += cows[++etime].first.first;
	}
	etime = cows[etime].second;
	int ans = 0;
    //cows only collide at opposite directions
	sort(right.begin(), right.end());
	for(int i = 0; i < left.size(); i++) {
		ans += lower_bound(right.begin(), right.end(), left[i]) - lower_bound(right.begin(), right.end(), max(left[i] - (2*etime), 0));
	}
	cout << ans << '\n';
}