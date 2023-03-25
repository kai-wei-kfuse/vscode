#include<iostream>//全排列stl
#include<algorithm>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int main()
{
    int n=8;
    int sum=0;
    //cin>>n;
    do{
        sum++;
        for(int i=1;i<=n;i++)printf("%d ",a[i-1]);
        cout<<endl;
    }
    while(next_permutation(a,a+n));
    //printf("%d",sum);
    return 0;
}