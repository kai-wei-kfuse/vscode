#include<iostream>
using namespace std;
int t[105];
int main()
{
    int n;
    cin>>n;
    while(n--){
        int s;
        cin>>s;
        int st=0,ls=0;
        int cos=0;
        for(int i=1;i<=s;i++){
            cin>>t[i];
            }
        for(int i=1;i<=s;i++){ 
            if(t[i]==0){st=i-1;
            break;
            }
        }
        for(int i=s;i>=1;i--){
            if(t[i]==0){ls=i+1;
            break;
            }
        }
        cout<<ls-st<<endl;
    }
}