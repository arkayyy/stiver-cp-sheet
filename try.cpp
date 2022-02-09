#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n;
    cin>>n;
    vector<int> a(2*n);

    for(int i = 0;i<2*n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    
    int curr = 0;
    int i  = 0;
    while(i<2*n)
    {
        if(a[i]!=curr)
        { break;}
        while(a[i]==curr)
            i++;
        curr++;
    }
    cout<<curr<<endl;
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