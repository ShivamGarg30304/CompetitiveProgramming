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
    vector<int> v(n);
    cin >> v;
    vector<int> hsh(n);
    for (auto x : v) {
        hsh[x]++;
    }
    int emp = -1;
    for (int i = 0; i < n; i++) {
        if (hsh[i] == 0) {
            emp = i;
            break;
        }
    }
    if (emp == -1) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    for (auto x : v) {
        if (x < emp) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n << endl;
        return;
    }
    for(int i = 0; i < emp; i++) {
        if (hsh[i] < 2) {
            cout << -1 << endl;
            return;
        }
    }
    // cout << emp << endl;
    set<int> st;
    int begin = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < emp) {
            st.insert(v[i]);
            if (st.size() == emp) { 
                // cout << "h" << v[i] << endl;
                set<int> st2;
                for (int j = i + 1; j < n; j++) {
                    // cout << v[j] << " ";
                    if (v[j] < emp) {
                        st2.insert(v[j]);
                    }
                }
                // cout << "he" << endl;
                if (st2.size() >= emp) {
                    cout << 2 << endl;
                    cout << 1 << " " << i + 1 << endl;
                    cout << i + 2 << " " << n << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
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