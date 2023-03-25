#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char a[20];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;;j++)
			if(!a[j]){
				cout<<j<<endl;
				break;
			}
	}
	return 0; 
}
