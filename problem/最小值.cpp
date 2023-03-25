#include<iostream>
#include<cstdio>
using namespace std;
int a[100];
int main()
{
	int n,min;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	min=a[0];
	for(int i=1;i<n;i++)
	{
		if(min>a[i])min=a[i];
	}
	cout<<min;
	return 0;
}
