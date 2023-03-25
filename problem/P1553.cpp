#include<bits/stdc++.h>
using namespace std;
string strfz(string num,int len)
{
    if(len==1)return num;
    reverse(num.begin(),num.end());
    int i=0,k;
    while(num[i]=='0')
		i++;   
    if(i==len)return "0";
	for(k=i;k<=len;k++)
        num[k-i]=num[k];
    num.erase(len-i); 
    return num;
}
string rightfz(string a,int len)
{
    reverse(a.begin(),a.end());
    int i=len-1;
    while(a[i]=='0'&& i>0){
        a[i]='\0';
        i--;
    }
    return a;
}
string Xiaoshu(string a,int len,int pos)
{
    string left,right;
    left=a.substr(0,pos);
    right=a.substr(pos+1);
    if(right.length()==1)return strfz(left,left.length())+'.'+'0';
    return strfz(left,left.length())+'.'+rightfz(right,right.length());
}
string Fengshu(string a,int len,int pos)
{
    string left,right;
    left=a.substr(0,pos);
    right=a.substr(pos+1);
    //if(left=="0")return "0"+'/'+strfz(right,right.length());
    return strfz(left,left.length())+'/'+strfz(right,right.length());
}
int main()
{
    string num,m;
    getline(cin,num);
    int len=num.length();
    if(len==1){
        cout<<num;
        return 0;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(num[i]=='%')
        {
            num[i]='0';
            string result=strfz(num,len);
            for(int x=0;result[x];x++)
                  cout<<result[x];
                  cout<<'%';
            return 0;
            }
        if(num[i]=='/')
        {
            cout<<Fengshu(num,len,i);
            return 0;
        }
        if(num[i]=='.')
        {
            cout<<Xiaoshu(num,len,i);
            return 0;
        }
    }
    string result=strfz(num,len);
     for(int x=0;result[x];x++)
    cout<<result[x];
    return 0;
}