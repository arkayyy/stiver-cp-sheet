#include <bits/stdc++.h>
using namespace std;

#define int long long

bool findNos(int n, int &a, int &b, int &c)
{
    int cn = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a = i;
            break;
        }
    }
    if (a == cn + 1)
        return false; // to handle the cases where either a or b don't obtain a suitable value for doing a*b*c = n
    n /= a;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != a)
            {
                b = min(b, i);
            }
            if ((n / i) != i && (n / i) != a)
            {
                b = min(b, (n / i));
            }
        }
    }
    if (b == cn + 1)
        return false; // to handle the cases where either a or b don't obtain a suitable value for doing a*b*c = n
    c = (n / b);

    if (a != b && b != c && a != c && c != 1)
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int a = n + 1, b = n + 1, c = n + 1; // a,b and c can be initialised with any value greater than n..but we have to put 2 if statements in
    // the findNo function to handle the cases where either a or b don't obtain a suitable value for doing a*b*c = n
    // NOTE: But if we initialise a,b, and c with n, we don't need extra if statements because if no suitable value for either
    // a or b is not found, c = n/n = 1 which always returns false in findNo function above...!
    if (findNos(n, a, b, c))
    {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }
    else
        cout << "NO" << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}