#include <bits/stdc++.h>

using namespace std;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define int long long
const int INF = LLONG_MAX >> 1;
const int mod = 1e9 + 7;

// we will find the (total ways) - (ways on which they attack each other)
void solve(int n) {
    int totalWays = (n * n) * (n * n - 1) / 2;
	int attack = 4 * (n - 1) * (n - 2);
	cout << totalWays - attack << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}