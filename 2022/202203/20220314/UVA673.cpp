#include<iostream>
#include<stack>
using namespace std;
char trans(char a){
    if(a==')')return '(';
    if(a==']')return '[';
    if(a=='}')return '{';
    return '\0';
}
int main() 
{
    int n;
    cin>>n;
    getchar();
    string a;
    while(n--){
        getline(cin,a);
        stack<char> s;
        int len=a.length();
        for(int i=0;i<len;i++){
            if(s.empty())
            s.push(a[i]);
            else {
                if(trans(a[i])==s.top())s.pop();
                else s.push(a[i]);
            }
        }   
        if(s.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}