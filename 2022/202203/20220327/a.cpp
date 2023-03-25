#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int tmp;
    string a;
    while(n--){
        cin>>tmp;
        cin>>a;
        int len=a.length();
        int sum=0;
        for(int i=0;i<len;i++){
            if(a[i]=='0'){
                if(a[i+1]=='0'){
                    sum+=2;
                }
                if(a[i+1]=='1'&&a[i+2]=='0'){
                    sum+=1;
                }
            }
        }
        cout<<sum<<endl;
    }
}