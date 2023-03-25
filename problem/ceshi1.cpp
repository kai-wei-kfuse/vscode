#include<bits/stdc++.h>
using namespace std;
int b[10];
void Merge(int a[],int l,int mid,int R,int tmp[])
{
    int p1=l,p2=mid+1,s=0;//左右边分别设置指针指向左右边的开头
    while(p1<=mid&&p2<=R)//如果两边都没归并完就继续，只要有一边完成了就跳出
    {
        if(a[p1]>a[p2])
            tmp[s++]=a[p2++];//把指向的内容复制到中转数组中
        else 
            tmp[s++]=a[p1++];
    }
    while(p1<=mid)
        tmp[s++]=a[p1++];//如果一边完成了，就把另一边剩下的按顺序复制到中转数组中
    while(p2<=R)
        tmp[s++]=a[p2++];
    for(int k=0;k<R-l+1;k++)
        a[l+k]=tmp[k];//拷贝回原来数组
}
void mergesort(int a[],int left,int right,int tmp[])
//归并排序：把左右边分别归并排序，然后在左右边归并
{
    if(left<right)//只有左右元素都大于1才排，只剩一个数就不用排了（就什么都不做）
    {
        int mid=left+(right-left)/2;//求中间
        mergesort(a,left,mid,tmp);//左边归并排序
        mergesort(a,mid+1,right,tmp);//右边归并排序
        Merge(a,left,mid,right,tmp);//最后再归并
    }
}
int main()
{
    int n;
    //cin>>n;
    int s[10]={0,21,3,9,7,12,34,3,7,8};
    int len=sizeof(s)/sizeof(int);//求数组长度
    mergesort(s,0,len-1,b);//归并排序，len-1指下标减1,b:为中转数组
    for(int i=0;i<10;i++)cout<<s[i]<<",";
}