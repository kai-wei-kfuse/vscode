#include<iostream>
#include<algorithm>
using namespace std;
int ti[100005];
int main()
{
    int n;
    cin>>n;
    while(n--){
        int p;
        cin>>p;
        for(int i=1;i<=p;i++){
            cin>>ti[i];
        }
        sort(ti+1,ti+p+1);
        for(int i=2;i<=p;i++){
            if(ti[i]!=1&&ti[i]!=ti[i-1])
            ti[i]=ti[i-1]%ti[i];
            else{
                
            }
        }
    }
}