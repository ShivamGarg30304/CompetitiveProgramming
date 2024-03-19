#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i].second = a;
        v[i].first = b;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= prev)
        {
            cnt++;
            prev = v[i].first;
        }
    }
    cout << cnt;

    return 0;
}