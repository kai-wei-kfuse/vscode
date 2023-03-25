#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
int num[102],num2[102];
int n,len;
int A[150],B[150],C[150];
int hh(int a){
    for(int i=1;i<=len;i++){
        if(A)
    }
}
string pluss(int a,int b){  
    for(int i=len-1,j=1;i>=0;i--,j++){
        B[j]=A[i];
    } 
    for(int i=1;i<=len;i++){
        C[i]+=A[i]+B[i];
        C[i+1]+=C[i]/n;
        C[i]=C[i]%n;
    }
    if(C[len+1]){
        len++;
    }
}
int main()
{
    cin>>n;
    string a;
    cin>>a;
    len=a.length();
     for(int i=a.length(),j=1;i>=0;i--,j++){
        A[j]=a[i]-'0';
    }

}