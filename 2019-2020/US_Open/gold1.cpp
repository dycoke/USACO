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
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);

    int n; cin >> n;
	ll ans[n+1]; memset(ans, 0, sizeof(ans));
	BIT<ll> bit(n+1);
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		bit.change(a, 1);
		ans[a] += bit.query(n) - bit.query(a);
	}
	ll res = 0;
	for(int i = 0; i < n; i++) {
		cout << res << '\n';
		res += ans[i];
	}
    return 0;
}