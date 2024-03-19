#include <bits/stdc++.h>

using namespace std;

void TowerOfHanoi(int n, int A, int B, int C) {
    if (n == 1) {
        cout << A << " " << B << endl;
        return;
    }
    TowerOfHanoi(n - 1, A, C, B);
    cout << A << " " << B << endl;
    TowerOfHanoi(n - 1, C, B, A);
}

int main (){
    int n;
    cin >> n;
    cout << int(pow(2, n)) - 1 << endl;
    TowerOfHanoi(n, 1, 3, 2);
    return 0;
}