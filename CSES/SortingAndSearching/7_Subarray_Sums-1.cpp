#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int sum = 0;
    int i = -1;
    int j = 0;
    long long int ans = 0;
    while (j < n && sum + arr[j] <= k)
    {
        sum += arr[j];
        j++;
    }
    if (sum == k)
    {
        ans++;
    }
    while (j < n && i < n)
    {
        sum += arr[j];
        while (sum > k)
        {
            i++;
            sum -= arr[i];
            if (i == j)
            {
                sum = 0;
                break;
            }
        }
        if (sum == k)
        {
            ans++;
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}