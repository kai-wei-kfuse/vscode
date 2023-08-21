#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]-'0'>=5){
                if(i==0){
                    s='1'+s;
                    len++;
                    i++;
                }else{
                    for(int j=i-1;j>=0;j--){
                        s[j]++;
                        if(j==0&&s[j]-1-'0'==9){
                            s='1'+s;
                            len++;
                            break;
                        }
                        if(s[j]-'0'<5){
                            break;
                        }else{
                            s[j]='0';
                        }
                        
                    }
                }
                for(int j=i;j<len;j++){
                    s[j]='0';
                }
            }
        }
        cout<<s<<endl;
    }
}