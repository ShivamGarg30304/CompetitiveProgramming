#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
 
        if (a > b)
            cout << "Alice\n";
        else if (a < b)
        {
            if (n <= a) 
                cout << "Alice\n";
            else 
                cout << "Bob\n";
        } 
        else 
        {
            if (n % (a + 1) == 0) 
                cout << "Bob\n";
            else 
                cout << "Alice\n";
        }
    }
}