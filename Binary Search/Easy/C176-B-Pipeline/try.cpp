#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int n, int s, int target)
{
    int maxs = (n - 1) * (s - 1) + s;
    return maxs >= target;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    if (n == k)
    {
        cout << 1 << endl;
        return 0;
    }

    int l = 0, r = n;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (check(mid, k, n))
            r = mid - 1;
        else
            l = mid + 1;
    }
    if ((l - 1) * (k - 1) + k >= n)
        cout << l << endl;
    else
        cout << -1 << endl;

    return 0;
}