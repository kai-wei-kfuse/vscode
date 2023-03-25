#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
string a;
map<char, int >mp;
deque<string>ch;
int main()
{
    cin>>a;
    //getchar();
    int len=a.length();
    int num,num2,charnum;
    for(int i=0;i<len;i++){
        if(a[i]>='a' && a[i]<='z')charnum++;
        mp[a[i]]++;
    }
    for(map<char,int > ::iterator i=mp.begin();i!=mp.end();i++){
        //cout<<(*i).first<<' ';
        if((*i).first!='/' && (*i).second%2!=0){
            cout<<"Impossible";
            return 0;
        }
        if((*i).first=='<'){
            num = (*i).second;
        }
        if((*i).first=='/'){
            num2 = (*i).second;
        }
    }
    //cout<<charnum<<endl;
    //cout<<charnum/(num2*2)<<endl;
    if(num/2 !=num2){cout<<"Impossible";return 0;}
   // int sum=num/2;
   // cout<<num<<' '<<num2<<' ';
    map<char,int > ::iterator i=mp.find('>');
    i++;
    //ch.push_back(0);
    for(int j=1;j<=num2;j++){//括号对数
    ch.push_front(">");
    ch.push_back("<");
    ch.push_back("/");
    string a,b;
        for(int k=1;k<=charnum/(num2*2);k++)//输入字母数量
        {
            //while((*i).second){
            //cout<<(*i).first<<' ';
                a+=(*i).first;
                b+=(*i).first;
                (*i).second-=2;
                if((*i).second==0&&i!=mp.end())i++;
            //}
            
            /*while((*i).second){
            ch.push_back((*i).first);
            ch.push_front((*i).first);
            }*/
        }
        //cout<<a<<' '<<b<<endl;
        ch.push_back(a);
        ch.push_front(b);
        a.clear();b.clear();
        ch.push_back(">");
        ch.push_front("<");
    }
    for(deque<string>::iterator i=ch.begin();i!=ch.end();i++){
        cout<<(*i);
    }

}
//<>test<>//<>test<><>test<>//<>test<>
