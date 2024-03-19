#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int total_sum = (n * (n + 1)) /2;
    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        total_sum = total_sum - x;
    }
    cout << total_sum << endl;

    return 0;
}