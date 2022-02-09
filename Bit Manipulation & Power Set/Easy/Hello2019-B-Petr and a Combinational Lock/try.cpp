#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n;
    cin>>n;
    vector<int> degrees(n);
    for(int i=0;i<n;i++)
        cin>>degrees[i];
    
    int k = pow(2,n);
    while(k)
    {
        int ck = k;
        int res = 0; 
        //int i = 0;
        for(int i = 0; i<n; i++)
        {
            if((1<<i)&k)
                res+=degrees[i];
            else
                res-=degrees[i];
        }
        if(res==0 || res%360==0)
            {cout<<"YES"<<endl; return;}
        k--;
    }
    cout<<"NO"<<endl;
}

int32_t main()
{
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}