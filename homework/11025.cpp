#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1,j=1;i<=n;i++,j+=2){
        for(int k=n-i;k>0;k--)
        printf(" ");
        for(int k=1;k<=j;k++)
        printf("*");
    printf("\n");}
    j-=4;
    for(i=1;i<n;i++,j-=2)
    {
        for(int k=1;k<=i;k++)
        printf(" ");
       for(int k=1;k<=j;k++)
        printf("*");
    printf("\n");
    }
}