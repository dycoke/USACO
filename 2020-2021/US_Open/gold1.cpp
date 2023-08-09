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

    int n; cin >> n;
    int prev[n]; memset(prev, 0, sizeof(prev));
    BIT<int> bit(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int b; cin >> b; --b;
        ans += bit.query(i) - bit.query(prev[b]);
        bit.set(prev[b], 0);
        bit.set(i, 1);
        prev[b] = i;
    }
    cout << ans << '\n';
    return 0;
}