#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a;
    int x,y;
    while(n--){
        cin>>a>>x>>y;
        if(x<15||x>20||y<50||y>70)cout<<a<<endl;
    }
}