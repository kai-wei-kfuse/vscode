#include <stdio.h>

int main()
{
 int i = 1;
 int N;
 int g = 0;
 int s = 0;
 int sum = 0;
 scanf("%d", &N);
 for(i=1;i<=N;i++)
 {
  g += i;
  for (int s = 1; s <= i-1; s++)
   g *= 10;
  g += i;
  
 }
 sum += i;
 printf("%d", sum);
 }