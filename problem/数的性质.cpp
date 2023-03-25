#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int number;
	cin>>number;
	if(number%2==0 && (number>4 && number<=12))
		cout<<1<<' ';
	else 
		cout<<0<<' ';
	if(number%2==0 || (number>4 && number<=12))
		cout<<1<<' ';
	else
		cout<<0<<' ';
	if((number%2==0 && !(number>4 && number<=12))||(!(number%2==0) && number>4 && number<=12)) 
		cout<<1<<' ';
	else
		cout<<0<<' ';
	if(!(number%2==0)&& !(number>4 && number<=12)) 
		cout<<1<<' ';
	else
		cout<<0<<' ';
	return 0;
 } 
