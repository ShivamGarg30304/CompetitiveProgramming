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

int maxSubArraySum(vector<int> &a, int size) {
    int ans = INT_MIN, temp = 0;
 
    for (int i = 0; i < size; i++) {
        temp = temp + a[i];
        if (ans < temp)
            ans = temp;
 
        if (temp < 0)
            temp = 0;
    }
    return ans;
}

int smallestSumSubarr(vector<int> &arr, int n) {
    int temp = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (temp > 0)
            temp = arr[i];   
        else
            temp += arr[i];
        ans = min(ans, temp);            
    }
    return ans;
}


void solve() {
    int n, c; cin >> n >> c;
    vector<int> arr(n); cin >> arr;
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        brr[i] = -arr[i];
    }
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    if (c > 0) {
        int maxisum = maxSubArraySum(arr, n);
        if (maxisum < 0) {
            cout << total_sum << endl;
            return;
        }
        int remain = total_sum - maxisum;
        cout << maxisum * c + remain << endl;
    } else {
        int maxisum = smallestSumSubarr(arr, n);
        if (maxisum > 0) {
            cout << total_sum << endl;
            return;
        }
        int remain = total_sum - maxisum;
        cout << maxisum * c + remain << endl;
    }
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