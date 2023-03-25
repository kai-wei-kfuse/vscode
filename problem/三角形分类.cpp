#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c && c+b>a &&a+c>b)
	{
		if(a*a+c*c==b*b||a*a+b*b==c*c||c*c+b*b==a*a)
		cout<<"Right triangle"<<endl;
		if(a*a+c*c>b*b && a*a+b*b>c*c && c*c+b*b>a*a)
		cout<<"Acute triangle"<<endl;
		if(a*a+c*c<b*b || a*a+b*b<c*c || c*c+b*b<a*a)
		cout<<"Obtuse triangle"<<endl;
		if(a==b||b==c||a==c)
		cout<<"Isosceles triangle"<<endl;
		if(a==b&&a==c&&b==c)
		cout<<"Equilateral triangle";
	}
	else
	cout<<"Not triangle";
	return 0;
}
