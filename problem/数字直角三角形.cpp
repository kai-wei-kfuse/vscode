#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a=1;
	cin>>n;
	for(int j=n;j>=1;j--)
	{
	for(int i=1;i<=j;i++)
	{
		if(a<=9)cout<<"0"<<a;
		if(a>9)cout<<a;
		a++;
		}
		cout<<endl;
	}
	return 0;
 } 
