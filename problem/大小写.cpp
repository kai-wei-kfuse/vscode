#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	getline(cin,a);
    int l=a.length();
    for(int i=0;i<=l;i++)
    {
        if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
    }
    cout<<a;
}
