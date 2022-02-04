#include<bits/stdc++.h>
using namespace std;

#define int long long

//SEGMENTED SIEVE PROBLEM (STEPWISE SOLVED BELOW)

void buildSieve(vector<bool>&isPrime)
{
    int n = isPrime.size()-1;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i*i<=n; i++)
    {
        if(!isPrime[i]) continue;
        for(int j = i*i; j<=n; j+=i)
            isPrime[j] = false;
    }
}

vector<int> generatePrimesUpto(int n, vector<bool>& isPrime)
{
    vector<int> ans;
    for(int i = 2; i<=n; i++)
        if(isPrime[i])
            ans.push_back(i);
    return ans;
}

void solve()
{
    int a, b;
    cin>>a>>b;
    vector<bool> isPrime(1e5+1,true);
    //STEP 1:  firstly we build primes upto 10^5 (since our r can go upto 10^9 so its sqrt must go somewhere upto 10^5 and initilly we need to find primes till that only)
    buildSieve(isPrime);

    //STEP 2: generating all primes upto sqrt(upper range) whose multiples are present b/w a and b
    vector<int> primes = generatePrimesUpto(sqrt(b), isPrime);

    //STEP 3: creating a dummy vector to store prime or not for numbers b/w a and b
    vector<bool> isPrimeAns(b-a+1,true);

    //STEP 4: One by one going through each prime, and marking all their multiples between a and b as NOT PRIME
    for(auto p: primes)
    {
        int firstMultiple = a;
        while(firstMultiple%p!=0) firstMultiple++;
        for(int j = max(p*p,firstMultiple); j<=b; j+=p) // j = max(p*p,firstMultiple) because for every prime we start checking from its p*p, but if p*p falls way below the range, then the first multiple of p in the range would be considered 
            isPrimeAns[j-a] = false;
    }

    //STEP 5: Displaying all primes b/w a and b
    for(int i = a; i<= b; i++)
        if(i!=1 && isPrimeAns[i-a])
            cout<<(i)<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}