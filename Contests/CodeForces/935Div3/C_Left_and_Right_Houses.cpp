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


void solve() {
    int n; cin >> n; 
    string s; cin >> s;
    s = "x" + s;
    vector<int> one(n + 1, 0);
    vector<int> zero(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            one[i] += one[i - 1] + 1;
            zero[i] += zero[i - 1];
        } else {
            one[i] += one[i - 1];
            zero[i] += zero[i - 1] + 1;
        }
    }
    int ans = INT_MAX;
    double mid = n / 2.0;
    for (int i = 0; i <= n; i++) {
        int left = i;
        int right = n - i;
        int zero_on_left = zero[i];
        int index = left;
        int one_on_right = one[n] - one[index];
        // cout << zero_on_left << " " << one_on_right << endl;
        if (zero_on_left >= (left + 1) / 2 and one_on_right >= (right + 1) / 2) {
            // cout << left << " " << right << " " << zero_on_left << " " << one_on_right << endl;
            double prev = abs(mid - ans);
            double next = abs(mid - i);
            if (prev > next) {
                ans = i;
            }
        }
    }
    cout << ans << endl;
    // cout << one << endl;
    // cout << zero << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}