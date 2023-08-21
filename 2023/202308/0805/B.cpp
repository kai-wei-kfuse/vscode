#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        vector<int> ve(n + 1);
        int num1 = 0, numx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> ve[i];
            if (ve[i] == 1)
            {
                num1++;
            }
            else
            {
                numx += ve[i] - 1;
            }
        }
        if(n==1){
            cout<<"No"<<endl;
            continue;
        }
        // sort(ve.begin()+1,ve.end());
        //cout<<numx<< ' '<<num1<<endl;
        if (numx >= num1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}