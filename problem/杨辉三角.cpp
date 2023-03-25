#include<iostream>
#include<cstdio>
using namespace std;
long long a[100],b[100];
int main()
{
	int n;
	cin>>n;
	a[0]=1;
	a[1]=1;
	b[0]=1;
	cout<<"1"<<endl;
	if(n>1) 
	cout<<"1"<<" "<<"1"<<endl;
	for(int i=3;i<=n;i++)
	{
		cout<<"1"<<" ";
		for(int j=0;j<=i-2;j++)
		{
			cout<<a[j]+a[j+1]<<" ";
			b[j+1]=a[j]+a[j+1];
		}
		cout<<endl;
		for(int k=0;k<=i;k++)
		{
			a[k]=b[k];
		}
	}
	return 0;
}
