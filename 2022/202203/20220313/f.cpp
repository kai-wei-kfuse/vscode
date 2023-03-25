#include<iostream>
using namespace std;
int turn(string a){
    int x=0;
    for(int i=0;i<=1;i++){
        x=x*10+(a[i]-'0');
    }
    x*=60;
    int y=0;
    for(int i=3;i<=4;i++){
        y=y*10+(a[i]-'0');
    }
    return x+y;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int day,hour;
        cin>>day>>hour;
        string a,b;
        int sum=0;
        for(int i=1;i<=day;i++){
            cin>>a>>b;
            //cout<<turn(b)<<' '<<turn(a)<<endl;
            sum+=turn(b)-turn(a);
        } 
        if(hour*60<=sum)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}