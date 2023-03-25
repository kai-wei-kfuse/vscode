#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1000010
/*
KMP算法步骤：
1、输入A,B串，求A串中B串的数量
2、求出B串的next数组（kmp数组）
3、同样的方法开始匹配AB串
*/
int kmp[maxn],lena,lenb;
char a[maxn],b[maxn];
int main()
{
    cin>>b+1;
    cin>>a+1;
    lena=strlen(a+1);
    lenb=strlen(b+1);
    kmp[1]=0;//一个字符没有最长公共前后缀
    for(int i = 2,len = 0;i <= lena; i ++){
        while(len>0 && a[i] != a[len + 1])len = kmp[len];
        if(a[i] == a[len + 1])len++;
        kmp[i] = len;
    }
    for(int i = 1,len = 0;i <= lenb;i ++){    
        while(len > 0 && (len == lena || b[i] != a[len+1]))len = kmp[len];
        if(b[i] == a[len + 1])len ++;
        if(len == lena){
            cout<<i-lena+1<<endl;
            //len = kmp[len];
        }
    }
    //i是在串尾的指针，求哪个子串的最长公共前后缀就在哪个子串的末尾
    //len（或者写成j）可以理解为目前最长公共前后缀的长度
    for(int i=1;i<=lena;i++){
        cout<<kmp[i]<<' ';
    }
}