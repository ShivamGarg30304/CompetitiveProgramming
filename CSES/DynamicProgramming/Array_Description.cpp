#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define srt(v)  sort(v.begin(), v.end())         // sort 
#define mxe(v)  *max_element(v.begin(), v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(), v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x, y)  bitset<y> (x) 
using namespace std;
int MOD = 1e9 + 7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a = ((a % MOD) + (b % MOD)) % MOD;}
void modsub(int &a , int b) {a = ((a % MOD) - (b % MOD) + MOD) % MOD;}
void modmul(int &a , int b) {a = ((a % MOD) * (b % MOD)) % MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC, typename typD> istream &operator >> (istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator >> (istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream &operator << (ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template<typename typC, typename typD> ostream &operator << (ostream &cout, const vector<pair<typC, typD>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator << (ostream &cout, const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
// ===================================END Of the input module ==========================================

bool valid(int x, int m) {
    return x >= 1 and x <= m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    for (int i = 1; i <= m; i++) {
        if (a[0] == i or a[0] == 0) {
            dp[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (a[i - 1] != 0 and a[i - 1] != k) {
                dp[i][k] = 0;
                continue;
            }

            for (int prev = k - 1; prev <= k + 1; prev++) {
                if (!valid(prev, m)) continue;
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}