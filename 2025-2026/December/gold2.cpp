#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int long long

class BIT {
  private:
	int n;
	vector<int> bit;
	vector<int> arr;

  public:
	BIT(int n) : n(n), bit(n + 1), arr(n) {}

	void change(int i, int v) {
		arr[i] += v;
		i++;
		for (; i <= n; i += i & -i) {
            bit[i] += v;
        }
	}

	int query(int i) {
		i++;
		int res = 0;
		for (; i > 0; i -= i & -i) {
            res += bit[i];
        }
		return res;
	}
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    priority_queue<array<int, 2>> pq;
    BIT bit(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push({a[i], i});
        bit.change(i, 1);
    }

    int ans = 0;

    while(!pq.empty()) {
        vector<int> b;
        auto [x, i] = pq.top();
        int cur = 0;
        // move all of b to the right for now
        while(!pq.empty() && pq.top()[0] == x) {
            int j = pq.top()[1];
            b.push_back(j);
            bit.change(j, -1);
            cur += bit.query(n - 1) - bit.query(j);
            pq.pop();
        }
        reverse(b.begin(), b.end());
        int res = cur;
        for(int j : b) {
            // move j to the left instead
            cur -= bit.query(n - 1) - bit.query(j);
            cur += bit.query(j);
            res = min(res, cur);
        }

        ans += res;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("out.txt", "w", stdout);

    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
