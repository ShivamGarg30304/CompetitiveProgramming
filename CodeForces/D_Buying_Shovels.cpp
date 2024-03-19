#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define papus ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod = 1e9 + 7;
signed main()
{
    papus
    ll t; 
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        set<ll>st;
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                st.insert(i);
                st.insert(n / i);
            }
        }
        int asn;
        for (auto i : st) {
            if(i <= k) {
                asn = i;
            } else {
                break;
            }
        }
        cout << n / asn << '\n';
    }
}