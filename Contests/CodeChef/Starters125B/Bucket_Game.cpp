#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int v[n];
        int c = 0;
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2)
                d++;
            if (v[i] == 1)
                c++;
        }
        int a = (c + 1) / 2;
        int b = (c) / 2;
        if (d % 2)
            a += (n - c);
        else
            b += (n - c);
        if (a == b)
            cout << "DRAW" << endl;
        if (a > b)
            cout << "ALICE" << endl;
        if (b > a)
            cout << "BOB" << endl;
    }
}