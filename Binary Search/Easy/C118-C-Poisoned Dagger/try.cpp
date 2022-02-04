#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(int x, vector<int>& times, int h)
{
    int currRange = -1;
    int damage = 0;
    for(auto t: times)
    {
        if(t <= currRange)
            damage+=(x-(currRange-t+1));
        else
            damage+=x; 1
        
        currRange = t+x-1;
        
        if(damage >= h) return true;
    }

    return damage>=h;
}

void solve()
{
    int n,h;
    cin>>n>>h;
    vector<int> times(n);
    for(int i=0;i<n;i++)
        cin>>times[i];
    
    int lo = 1, hi = h;
    int ans;
    while(lo<=hi)
    {
        int mid = lo+((hi-lo)>>1);
        if(check(mid,times,h))
            {hi = mid-1; ans = mid;}
        else
            lo = mid+1;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}