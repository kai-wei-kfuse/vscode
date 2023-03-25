#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int len=a.length();
    stack<int>s;
    int x=0;
    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            //s.push(a[i]-'0');
            x=x*10+a[i]-'0';//不一定只有个位数
        }
        else{
            if(x){
            s.push(x);//cout<<x<<endl;
            x=0;
        }
        if(a[i]=='.')continue;
        else {
            if(a[i]!='@'){
            int x=s.top();s.pop();
            int y=s.top();s.pop();
            if(a[i]=='+')s.push(x+y);
            if(a[i]=='-')s.push(y-x);
            if(a[i]=='*')s.push(x*y);
            if(a[i]=='/')s.push(y/x);
            }
            else cout<<s.top();
            }
        }
    }
}
