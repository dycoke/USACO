#include <bits/stdc++.h>
using namespace std;
#define ll long long

class HashedString {
  public:
	static const ll M = (1LL << 61) - 1;
	static const ll B;
	static __int128 mul(ll a, ll b) { return (__int128)a * b; }
	static ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

  private:
	static vector<ll> pow;

	vector<ll> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll getHash(int start, int end) {
		ll raw_val =
		    p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<HashedString> spotty, normal;
    for(int i = 0; i < n; i++) {
        string cow; cin >> cow;
        spotty.push_back(HashedString(cow));
    }
    for(int i = 0; i < n; i++) {
        string cow; cin >> cow;
        normal.push_back(HashedString(cow));
    }

    int l = 1, r = m;
    while(l < r) {
        int mid = l + (r-l)/2;
        set<ll> hashes;
        bool works = 0;
        for(int i = 0; i < m-mid; i++) {
            works = 1;
            hashes.clear();
            for(int c = 0; c < n; c++) hashes.insert(spotty[c].getHash(i, i+mid-1));
            for(int c = 0; c < n; c++) {
                if(hashes.count(normal[c].getHash(i, i+mid-1))) {
                    works = 0;
                    break;
                }
            }
            if(works) break;
        }
        if(works) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
	return 0;
}