#include <bits/stdc++.h>
using namespace std;
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

vector<bool> isPrime(1e8, true);
vector<int> ans;

void buildSieve()
{
    int n = isPrime.size()-1;
    for(int i = 2; i*i<=n; i++)
    {
        if(!isPrime[i]) continue;
        for(int j = i*i; j<=n; j+=i)
            isPrime[j] = false;
    }
}

void solve()
{
    int k;
    cin>>k;
    cout<<ans[k-1]<<endl;
}

int32_t main()
{
    int t;
    cin>>t;

    isPrime[0] = false;
    isPrime[1] = false;
    buildSieve();

    for(int i = 0; i<1e8; i++)
        if(isPrime[i])
            ans.push_back(i);

    //cout<<ans.size()<<endl;
    while(t--)
      solve();

    return 0;
}