
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define int long long

string tostring(int a) {
	string s = to_string(a);
	while (s.size() < 3) s = "0" + s;
	return s;
}

int Pow(int a, int b) {
    int r = 1;
    while (b) {
		if (b & 1) r = r * a;
		a = 1LL * a * a;
		b >>= 1;
	}
    return max(1LL, r);
}

void solve() {
    int n; cin >> n;
    cout << 1LL * (n - 3) * 4 * 3 * 3 * Pow(4, max(0LL, n - 4)) + 1LL * 2 * 4 * 3 * Pow(4, n - 3) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	int t = 1;
    // cin>>t;
    while (t--) {
		solve();
	}
}