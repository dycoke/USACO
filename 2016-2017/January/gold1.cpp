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
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);

    int n; cin >> n;
	pair<int, int> compress[n];
	for(int i = 0; i < n; i++) {
		cin >> compress[i].first;
		compress[i].second = i;
	}
	sort(compress, compress + n);
	int cows[n];
	for(int i = 0; i < n; i++) {
		cows[compress[i].second] = i;
	}

	BIT<ll> start(n), end(n);
	int left[n], right[n];
	for(int i = 0; i < n; i++) {
		start.change(cows[i], 1);
		left[i] = start.query(n-1) - start.query(cows[i]);
	}
	for(int i = n-1; i >= 0; i--) {
		end.change(cows[i], 1);
		right[i] = end.query(n-1) - end.query(cows[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(right[i]*2 < left[i] || left[i]*2 < right[i]) {
			ans++;
		}
	}
	cout << ans << '\n';
    return 0;
}