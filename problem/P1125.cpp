#include<bits/stdc++.h>//字符串
using namespace std;//笨小猴
int num[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
    char word[101];
    int a[27];
    memset(a,0,sizeof(a));
    gets(word);
    int l=strlen(word);
    for(int i=0;i<l;i++)
    {
    switch (word[i])
    {
    case 'a':a[1]++;
    break;
    case 'b':a[2]++;
    break;
    case 'c':a[3]++;
    break;
    case 'd':a[4]++;
    break;
    case 'e':a[5]++;
    break;
    case 'f':a[6]++;
    break;
    case 'g':a[7]++;
    break;
    case 'h':a[8]++;
    break;
    case 'i':a[9]++;
    break;
    case 'j':a[10]++;
    break;
    case 'k':a[11]++;
    break;
    case 'l':a[12]++;
    break;
    case 'm':a[13]++;
    break;
    case 'n':a[14]++;
    break;
    case 'o':a[15]++;
    break;
    case 'p':a[16]++;
    break;
    case 'q':a[17]++;
    break;
    case 'r':a[18]++;
    break;
    case 's':a[19]++;
    break;
    case 't':a[20]++;
    break;
    case 'u':a[21]++;  
    break;
    case 'v':a[22]++;
    break;
    case 'w':a[23]++;
    break;
    case 'x':a[24]++;
    break;
    case 'y':a[25]++;
    break;
    case 'z':a[26]++;
    break;
    }
    }
    int max,min;
    for(int i=1;i<=26;i++)
    if(a[i])
     max=a[i],min=a[i];
    for(int i=2;i<=26;i++)
    {
        if(a[i]&&max<a[i])max=a[i];
        if(a[i]&&min>a[i])min=a[i];
    }
    for(int i=0;i<25;i++)
    {
        if(max-min==num[i])
        {
            cout<<"Lucky Word"<<endl;
            cout<<max-min;
            return 0;
        }
    }
    cout<<"No Answer"<<endl;
    cout<<0;
}