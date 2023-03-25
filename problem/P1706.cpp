#include<bits/stdc++.h>//全排列
using namespace std;
void swap(int n[],int i,int j)
{
    int x=n[j];
    for(int k=j;k>i;k--)
        n[k]=n[k-1];
    n[i]=x;
}
void swapback(int n[],int i,int j)
{
    int x=n[i];
    for(int k=i;k<=j;k++)
        n[k]=n[k+1];
    n[j]=x;
}
void allsort(int n[],int first,int last)
{
    if(first==last){
        for(int i=0;i<=last;i++)
            printf("%5d",n[i]);
        cout<<endl;
    }
    else 
    for(int i=first;i<=last;i++)
        {
        swap(n,first,i);
        allsort(n,first+1,last);
        swapback(n,first,i);
        }
}
int main()
{
    int n[9]={1,2,3,4,5,6,7,8,9},num=0;
    cin>>num;
    allsort(n,0,num-1);
    return 0;
}