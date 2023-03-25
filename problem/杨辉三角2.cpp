#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[50][50]; 
	a[0][0]=1;
	a[1][0]=1;
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i][0]=1;
		for(int j=1;j<n;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][n]=1;
	 } 
	 for(int k=0;k<n;k++)
	 {
	 	for(int i=0;i<=k;i++)
	 	cout<<a[k][i]<<" ";
	 	cout<<endl; 
	 }
	 return 0;
 } 
