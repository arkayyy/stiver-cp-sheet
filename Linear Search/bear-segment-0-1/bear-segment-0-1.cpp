#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        bool foundOne = false;
        int flag = false;
        int i = 0;

        while (i < s.length())
        {

            if (s[i] == '1')
            {

                if (foundOne)
                {
                    flag = true;
                    break;
                } // if a group of 1s has already occured before

                while (s[i] == '1')
                    i++;         // forwarding for the whole present group of 1s
                foundOne = true; // marking that at least one 1 has been found in the string
            }

            i++;
        }
        if (flag)
            cout << "NO" << endl;
        else if (foundOne)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
