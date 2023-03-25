#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m;
	double h;
	cin>>m>>h;
	double s=h*h;
	if(m/s < 18.5)
	cout<<"Underweight";
	if(m/s>=18.5 && m/s<=24)
	cout<<"Normal";
	if(m/s>=24)
	{
	cout<<m/s<<endl;
	cout<<"Overweight";
	}
	return 0;
}
 
