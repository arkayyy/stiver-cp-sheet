#include <bits/stdc++.h>
using namespace std;

//DIFFICULTY: EASY (but edge cases important)

int main()
{ 
    int m,n;
    cin>>m>>n;
    
    unordered_set<int> zeroPresentInRow;
    unordered_set<int> zeroPresentInCol;

    vector<vector<int>> mx(m,vector<int>(n,0));

    bool flagNotValid = false;

    int noZerosInitial = 0;

    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mx[i][j];
            if(mx[i][j]==0)
            {
                zeroPresentInRow.insert(i);
                zeroPresentInCol.insert(j);
                noZerosInitial++;
            }
        }
    }

    int noZerosCurr = 0;

    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int bit=mx[i][j];

            if(bit==0) noZerosCurr++;
            if(bit==1 && (zeroPresentInRow.find(i)!=zeroPresentInRow.end() && zeroPresentInCol.find(j)!=zeroPresentInCol.end()))
            {
                flagNotValid = true;
                break;
            }
            if(bit==1 && (zeroPresentInRow.find(i)!=zeroPresentInRow.end() || zeroPresentInCol.find(j)!=zeroPresentInCol.end()) )
            {
                mx[i][j] = 0;
                noZerosCurr++;
            }
            // else 1 --> 1
        }
        if(flagNotValid)
            break;
    }

    if(flagNotValid || (noZerosCurr>noZerosInitial && noZerosCurr==(m*n)))
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i<m;i++)
        {
            for(int j = 0;j <n;j++)
            {
                cout<< mx[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}