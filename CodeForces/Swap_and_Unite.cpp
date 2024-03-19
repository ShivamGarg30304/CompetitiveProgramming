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
    string s; cin >> s;
    vector<vector<int>> v(26);
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        v[ch - 'a'].push_back(i);
    }
    int mini = INT_MAX;
    // for (int i = 0; i < 26; i++) {
    //     if (v[i].size() == 0) continue;
    //     char ch = 'a' + i;
    //     cout << ch << " -> ";
    //     for (auto x : v[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    for (auto vec : v) {
        if (vec.size() == 0) continue;
        if (vec.size() == 1) {
            cout << 0 << endl;
            return;
        }
        int cnt = 0;
        for (int i = 1; i < vec.size(); i++) {
            cnt += (vec[i] - vec[i - 1] - 1);
        }
        mini = min(mini, cnt);
    }
    
    vector<int>cnt(26,0);
    vector<int>b(26,1);

    for(auto x:s)
    {
        cnt[x-'a']++;
    }
    for(int i=0;i<s.length()-1;i++)
    {
        int c = 1 ;
        char ch = s[i];
        while(s[i]==s[i+1] and i<s.length())
        {
            c++;
            i++;
        }
        b[ch-'a']=max(c,b[ch-'a']);
    }
   
    for(int i=0;i<26;i++)
    {
        if(cnt[i]>0)
        mini = min(mini,cnt[i]-b[i]);
    }
    cout << mini << endl;
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