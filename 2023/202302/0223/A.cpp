#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    double len=s.size();
    double num2 = 0;
    for (int i = 0; i < len;i++){
        if(s[i]=='2'){
            num2++;
        }
    }
    double ans;
    if(s[0]=='-'){
    ans=num2 / (len-1);
    }else{
    ans = num2 / len;
    }
    //cout << ans << endl;
    if(s[0]=='-'){
        ans*= 1.5;
    }
   // cout << ans << endl;
    if((s[len-1]-'0')%2==0){
        ans *= 2.0;
    }
    //cout << ans << endl;
    printf("%.2f%", ans * 100);
}