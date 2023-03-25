#include<bits/stdc++.h>
using namespace std;
struct Student{
	int num;
	double score;
};
int main()
{
	int n;
	cin>>n;
	Student a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].num>>a[i].score;
	}
	sort(a.score,a.score+n);
	for(int j=0;j<n;j++)
	{
		cout<<a[j].num<<' ';
		scanf("%.1f",a[j].score);
		cout<<endl;
	}
	return 0;
}
