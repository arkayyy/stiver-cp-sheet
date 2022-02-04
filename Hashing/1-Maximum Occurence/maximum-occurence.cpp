/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    vector<int> freq(256,0);

    int maxFreq = -1;

    for(auto ch: s)
    {
        freq[(int)ch]++;
        maxFreq = max(maxFreq,freq[(int)ch]);
    }

    for(int i = 0; i<256;i++)
    {
        if(freq[i]==maxFreq)
        {
            cout<< (char)i << " " << maxFreq<<endl;
            break;
        }
    }

    return 0;

}