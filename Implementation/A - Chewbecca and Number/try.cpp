#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long res = 0;
    long long tens = 1;
    int nines = 0;

    while (n>=10)
    {
        long long r = n % 10;
        // if (r != 9)
        //     nines = 0;
        // else
        //     nines++;

        if (r >= 5)
            res = (9 - r) * tens + res;
        else
            res = r * tens + res;
        n /= 10;
        tens *= 10;
    }
    if(n==9)
        cout<<9*tens+res<<endl;
    else cout << (n>=5?(9-n):n)*tens+res << endl;

}

int main()
{
    long long t = 1;
    while (t--)
        solve();
    return 0;
}