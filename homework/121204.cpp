#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  // printf("%d",argc);
   //char a[]=argv[0];
    int len=strlen(argv[1]);
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if((int)argv[1][j]>(int)argv[1][j+1])
            {
                char tmp=argv[1][j+1];
                argv[1][j+1]=argv[1][j];
                argv[1][j]=tmp;
            }
        }
    }
    printf("%s",argv[1]);
}
