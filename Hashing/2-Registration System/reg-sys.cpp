#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> freq;
    while (n--)
    {
        string name;
        cin >> name;
        if (freq.find(name) != freq.end())
        { // if the name already exists in the database, we are simply adding the frequency of the already present name with the name in order to make it a new unique name
            cout << (name + to_string(freq[name])) << endl;
            freq[name + to_string(freq[name])]++;
        }
        else
            cout << "OK" << endl;
        freq[name]++;
    }
    return 0;
}