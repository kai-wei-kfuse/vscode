#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int a[2000][2000];
int main()
{
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    //scanf("%d",&n);
    int i=1;
    int x=0,y=0;
    a[x][y]=1;
    while(i<n*n)
    {
        while(y<n-1 && !a[x][y+1])//
        {
            a[x][++y]=i;
            ++i;
        }
        while(x<n-1 && !a[x+1][y])//
        {
            a[++x][y]=i;
            ++i;
        }
         while(y>0 && !a[x][y-1])//
        {
            a[x][--y]=i;
           ++i;
        }
        while(x>0 && !a[x-1][y])//
        {
            a[--x][y]=i;
            ++i;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //printf("%d",a[i][j]);
            cout<<a[i][j];
        }
        cout<<endl;
		//printf("\n");
    }
    return 0;
}

