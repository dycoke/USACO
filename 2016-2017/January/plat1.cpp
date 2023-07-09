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

const int MAX_N = 1e5;
vector<int> adj[MAX_N];
int start[MAX_N], finish[MAX_N], timer = 0;;

void dfs(int u) {
	start[u] = timer++;
	for(int& v: adj[u]) {
		dfs(v);
	}
	finish[u] = timer - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);

	int n; cin >> n;
	int ratings[n], order[n];
	for(int i = 0; i < n; i++) {
		cin >> ratings[i];
		order[i] = i;
	}
	for(int i = 1; i < n; i++) {
		int p; cin >> p;
		adj[--p].push_back(i);
	}
	dfs(0);
	BIT<int> bit(n);
	sort(order, order + n, [&](int a, int b) { return ratings[a] > ratings[b]; });
	int ans[n];
	for(int i = 0; i < n;) {
		int p = i;
		while(p < n && ratings[order[p]] == ratings[order[i]]) {
			ans[order[p]] = bit.query(finish[order[p]]) - bit.query(start[order[p]]);
			p++;
		}
		for(int j = i; j < p; j++) {
			bit.change(start[order[j]], 1);
		}
		i = p;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
    return 0;
}