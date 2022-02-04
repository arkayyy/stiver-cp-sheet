#include<bits/stdc++.h>
using namespace std;

void util(unsigned int a,unsigned int b,unsigned int c, int x, int idx)
{
    if(idx==32)
        return;
    if(x&1)
    {
        util((a<<1)|1,(b<<1)|1, (c<<1)|1);
        
    }
    else
    {

    }
}

void solve()
{
    int n;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}