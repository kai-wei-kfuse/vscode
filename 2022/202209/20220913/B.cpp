#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < n;++i)
        {
            int u, v;
            cin >> u >> v;
        }
        if(n%2==0)
        {
            cout << "Bob" << endl;
        }
        else 
        {
            cout << "Alice" << endl;
        }
    }
}