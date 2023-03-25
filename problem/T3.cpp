#include<iostream>
#include<cstdio>
using namespace std;//t3
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		if(m==0){
		cout<<"empty";
		continue;
		}
		int a[m];
		for(int j=0;j<m;j++)
		cin>>a[j];
		for(int k=m-1;k>=0;k--)
		{
		if(k==0)cout<<a[k];	
		if(k>0)cout<<a[k]<<",";
		}
}
	return 0;
}
 
 
