#include <bits/stdc++.h>
using namespace std;

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
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	int n; cin >> n;

	int cows[n];
	for(int i = 0; i < n; i++) {
		cin >> cows[i];
		cows[i]--;
	}

	int ans = n-1;
	BIT<int> bit(n); bit.change(cows[ans], 1);
	for(; ans > 0; ans--) {
		if(cows[ans-1] > cows[ans]) {
			break;
		} else {
			bit.change(cows[ans-1], 1);
		}
	}

	cout << ans << '\n';
	for(int i = 1; i <= ans; i++) {
		cout << ans - i + bit.query(cows[i-1]);
		if(i == ans) cout << '\n';
		else cout << ' ';
		bit.change(cows[i-1], 1);
	}
    return 0;
}