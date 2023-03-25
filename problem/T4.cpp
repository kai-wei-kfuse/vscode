#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,max;
	cin>>n;
	int a[100];
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=0;j<m;j++)
		{
			cin>>a[j];
		}
		max=a[0];
		for(int k=1;k<m;k++)
		{
			if(max<a[k])max=a[k];
		}
		cout<<max;
	}
	return 0;
}
