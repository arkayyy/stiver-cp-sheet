#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


//VERY IMP FUNCTION!!!!!!!!!!!!!!!
void findAllCommonDivisorsArr(vector<int>& nums)
{
    //STEP 1: Find GCD of all nos. in array
    int g = nums[0];
    for(auto i = 1; i<nums.size(); i++)
        g = __gcd(nums[i],g);

    
    set<int> divisors;
    //STEP 2: Find all factors of the above calc GCD, that'll be our set of all common divisors for the given array!!!
    for(int i = 1; i*i<=g; i++)
    {
        if(g%i==0)
        {
            divisors.insert(i);
            if(g/i != i)
                divisors.insert(g/i);
        }
    }

    for(auto d: divisors)
        cout<<d<<" ";
    cout<<endl;
}


//INTUITION: In order to make the whole array sum = 0, we need to nullify all bits of all nos. in the array...
//so for every bit index (from  0 to 31), we check how many numbers in the array have set bit at this bitIndex..
//We know we have to nullify this count of set bits (for every single bitIndex), so whatever k we choose, this count of set bits(for every bitindex) should be divisible by k
//thats why we store such counts and then find common divisors of all counts...
void solve()
{   
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
        cin>>nums[i];
    
    unordered_set<int> bitIsSetCount; //for every bitindex, all the elements are being evaluated for the bitIndex being set. The count of all such elements are being stored in s

    for(int bitIndex = 0; bitIndex<32; bitIndex++)
    {
        int cntSetBits = 0;
        for(int i = 0; i<n; i++)
        {
            if((1<<bitIndex)&nums[i])
                cntSetBits++;
        }
        if(cntSetBits)
        bitIsSetCount.insert(cntSetBits);
    }

    if(bitIsSetCount.size()==0) {
        for(int i = 1; i<=n; i++)
            cout<<i<<" ";
        cout<<endl;
        return;
    }

    vector<int> gg(bitIsSetCount.begin(),bitIsSetCount.end());

    findAllCommonDivisorsArr(gg);
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}