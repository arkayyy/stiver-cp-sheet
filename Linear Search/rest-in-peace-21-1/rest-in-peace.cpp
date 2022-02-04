/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = false;

        if (n % 21 == 0)
        {
            cout << "The streak is broken!" << endl;
            continue;
        }
        while (n)
        {
            int digit = n % 10;
            n /= 10;
            if (n % 10 == 2 && digit == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "The streak is broken!" << endl;
        else
            cout << "The streak lives still in our heart!" << endl;
    }
    return 0;
}
