#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    int ans = 1;
    while(ans<n)
        ans = ans*2+1;
    
    cout<< ans<<endl;
    return 0;
}