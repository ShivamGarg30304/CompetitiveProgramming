#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v[i] = x ^ v[i - 1];
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << (v[b] ^ v[a - 1]) << endl;
    }
    return 0;
}