#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    // Such a permutation exists for all positive integers except 2 and 3
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        // Simply print all the even numbers upto n followed by all the odd numbers upto n
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
