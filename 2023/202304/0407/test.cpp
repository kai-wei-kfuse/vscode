#include<bits/stdc++.h>
using namespace std;

const int N=1e7;
char ma[N<<1];
char s[N];
int p[N<<1];
int maxn=0;

void manacher(char s[],int len){
    int k=0;
    ma[k++]='$';
    ma[k++]='#';
    for(int i=0;i<len;i++){
        ma[k++]=s[i];
        ma[k++]='#';
    }
    ma[k]='&';
    int mr=0,c=0;
    for(int i=0;i<k;i++){
        if(i<mr){
            p[i]=min(p[c*2-i],mr-i);
        }else{
            p[i]=1;
        }
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(p[i]+i>mr){
            mr=p[i]+i;
            c=i;
        }
        maxn=max(maxn,p[i]-1);
    }
}

int main(){
    cin>>s;
    int len=strlen(s);
    manacher(s,len);
    cout<<maxn;
}