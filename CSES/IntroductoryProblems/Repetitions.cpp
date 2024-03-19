#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int ans = 1;
    char prev = s[0];
    for(int i = 1; i < n; i++){
        int curr = 1;
        while(i < n and s[i] == prev){
            curr++;
            i++;
        }
        ans = max(ans, curr);
        if(i < n){
            prev = s[i];
        }
    }
    cout << ans << endl;

    return 0;
}