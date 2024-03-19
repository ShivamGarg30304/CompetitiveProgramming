#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        lli row, col;
        cin >> row >> col;
        lli mx = max(row, col);
        lli a = mx * mx;
        lli b = (mx - 1) * (mx - 1);
        if (mx % 2)
        {
            if (row > col)
            {
                cout << b + col << "\n";
            }
            else
            {
                cout << a - row + 1 << "\n";
            }
        }
        else
        {
            if (row > col)
            {
                cout << a - col + 1 << "\n";
            }
            else
            {
                cout << b + row << "\n";
            }
        }
    }
    return 0;
}