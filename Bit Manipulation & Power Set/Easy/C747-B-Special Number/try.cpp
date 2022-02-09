#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long MOD = 1e9+7;

void solve()
{
    int n, k;
    cin>>n>>k;
    int ans = 0;
    int j = 1;

    while(k>0)
    {
        if(k%2==1)
            ans = (ans+j)%MOD;
        k/=2, j = (j*n)%MOD;
    }
    cout<<(ans%MOD)<<endl;
}

int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}