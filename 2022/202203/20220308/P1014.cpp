#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j=0,l;
    int sum=1;
    int cnt=1;
    for(i=0;i<n;i+=j){
            j++;
    }
    if(j%2==0){
        cout<<j+n-i<<'/'<<i-n+1;
    }
    if(j%2!=0){
        cout<<i-n+1<<'/'<<j+n-i;
        }
    
}