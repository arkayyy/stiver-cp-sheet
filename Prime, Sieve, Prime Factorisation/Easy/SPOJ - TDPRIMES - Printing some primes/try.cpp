#include <bits/stdc++.h>
using namespace std;
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

void buildSieve(vector<bool> &isPrime)
{
    int n = isPrime.size() - 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
}

void solve()
{
    int n = 1e8;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    buildSieve(isPrime);
    vector<int> ans;
    for (int i = 0; i <= n; i++)
        if (isPrime[i])
            ans.push_back(i);
    for (int i = 0; i < ans.size(); i += 100)
        cout << (ans[i]) << endl;
}

int32_t main()
{
    ios;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}