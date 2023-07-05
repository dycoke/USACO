#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, int val) { change(ind, val - arr[ind]); }

	void change(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T query(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>> cows(n, {-1, -1});
	for(int i = 0; i < 2*n; i++) {
		int c; cin >> c;
		if(cows[--c].first == -1) {
			cows[c].first = i;
		} else {
			cows[c].second = i;
		}
	}
	sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
	
	BIT<int> bit(2*n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (ll) bit.query(cows[i].second) - bit.query(cows[i].first-1);
		bit.change(cows[i].first, 1);
		bit.change(cows[i].second, -1);
	}
	cout << ans << '\n';
    return 0;
}