#include<iostream>
#include<string.h>
char a[500],b[200],c[200],tmp[500];
int main()
{
    scanf("%s %s %s",a,b,c);
    int len1=strlen(a),len2=strlen(b),len3=strlen(c);
    for(int i=0;i<len1-len2;i++)
    {
        int j;
        for(j=0;j<len2;j++)
        {
            if(a[i+j]!=b[j])break;
        }
        if(j==len2)
        {
            for(int k=j+i,l=0;k<len1;k++,l++)//把后面拷走
                tmp[l]=a[k];
            for(int k=i;k<len3+i;k++)//塞入b
                a[k]=c[k-i];
            for(int k=i+len3,l=0;k<len1;k++,l++)//把后面接上去
                a[k]=tmp[l];
        }
        }
    printf("%s",a);
}