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
        if (n & 1&&n!=1)
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> ve(n + 1);
            ve[1]=n;
            int tmp=n-1;
            for (int i = 2; i <= n; i+=2){
                ve[i]=tmp;
                tmp-=2;
            }
            tmp=2;
            for(int i=3;i<=n;i+=2){
                ve[i]=tmp;
                tmp+=2;
            }
            for(int i=1;i<=n;i++){
                cout<<ve[i]<<" ";
            }
            cout<<endl;
        }
    }
}