#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int x, k;
    cin >> x >> k;
    vector<int> divisor;
    while (x % 2 == 0) {
        divisor.push_back(2);
        x /= 2;
    }
    for (int i = 3; i * i <= x; i++) {
        while (x % i == 0) {
            divisor.push_back(i);
            x /= i;
        }
    }
    if (x > 1) divisor.push_back(x);
    if (divisor.size() < k) {
        cout << -1 << endl;
        return;
    }
    int count = 0;
    for (int i = 0; i < k - 1; i++) {
        cout << divisor[i] << " ";
    }
    int num = 1;
    for (int i = k - 1; i < divisor.size(); i++) {
        num *= divisor[i];
    }
    cout << num << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}