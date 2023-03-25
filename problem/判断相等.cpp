#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
    for(int i=0;i<=a.length();i++)
    {
        if(a[i]!=b[i]){
        	cout<<"0";
        	return 0;
		}
    }
    cout<<"1";
    return 0;

}
