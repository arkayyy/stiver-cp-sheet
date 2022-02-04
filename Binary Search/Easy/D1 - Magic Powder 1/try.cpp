#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(int x, vector<int>& a, vector<int>& b, int k, int n)
{
    int ans = 0;
    for(int i = 0; i<n; i++)
        if(a[i]*x - b[i] > k) return false;
    for(int i = 0; i<n;i++)
        ans+=max(a[i]*x - b[i], 0LL);
    if(ans<=k) return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);

    int maxi = INT_MIN;

    for(int i = 0; i<n; i++)
        cin>>a[i];
    for(int i = 0; i<n; i++)
    {
        cin>>b[i]; 
        maxi = max(maxi,b[i]);
    }

    // unordered_map<int,vector<int>> diff;

    // int mini = INT_MAX;
    // int mink = INT_MAX;
    
    // for(int i = 0;i<n;i++)
    // {
    //     diff[(b[i]/a[i])].push_back(i);
    //     mini = min(mini, (b[i]/a[i]));
    //     mink = min(mink,a[i]);
    // }

    // while(k>=mink)
    // {
    //     int n = diff[mini].size();
    //     int cnt = 0;
    //     for(auto i: diff[mini])
    //     {
    //         if(k>=a[i])
    //         {
    //             k-=a[i];//need
    //             cnt++;
    //         }
    //     }
    //     if(cnt==n)
    //     {
    //         for(auto i: diff[mini])
    //             diff[mini+1].push_back(i);
    //         mini++;
    //     }
    // }

    // cout<<mini<<endl;


    int l = 0, r = 1e5+7;
    int ans = -1;
    
    while(l<=r)
    {
        int mid = l+((r-l)>>1);
        if(check(mid,a,b,k,n))
           { l = mid+1; ans = mid;}
        else
            r = mid-1;
    }

    cout<<ans<<endl;

    return 0;
}