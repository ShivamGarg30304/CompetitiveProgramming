#include <bits/stdc++.h>

using namespace std;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define int long long
const int INF = LLONG_MAX >> 1;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= 2;
        ans = ans % mod;
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}