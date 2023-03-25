#include<iostream>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
string a;
//map<char, int >mp;
int mp[31];
deque<string>ch;
int main()
{
    cin>>a;
    //getchar();
    int len=a.length();
    int num,num2,charnum;
    for(int i=0;i<len;i++){
        if(a[i]>='a' && a[i]<='z'){charnum++;
                 mp[a[i]-'a'+1]++;
                 //cout<<(a[i]-'a'+1)<<endl;
        }
        if(a[i]=='<')mp[27]++;
        if(a[i]=='>')mp[28]++;
        if(a[i]=='/')mp[29]++;
        //mp[a[i]]++;
        
    }
    //cout<<charnum<<endl;
    /*for(map<char,int > ::iterator i=mp.begin();i!=mp.end();i++){
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
    }*/
    for(int i=1;i<=28;i++){
        if(mp[1]%2!=0){cout<<"Impossible";return 0;}
    }
    //cout<<mp[27]/2<<' '<<mp[29]<<endl;
    if(mp[27]!=mp[29]*2||charnum==0){cout<<"Impossible";return 0;}
    //cout<<charnum/(num2*2)<<endl;
    //if(num/2 !=num2){cout<<"Impossible";return 0;}
   // cout<<num<<' '<<num2<<' ';
    //map<char,int > ::iterator i=mp.find('>');
    //i++;
    num2=mp[27]/2;
    int l=1;
    for(int j=1;j<=num2;j++){//括号对数
    ch.push_front(">");
    ch.push_back("<");
    ch.push_back("/");
    string aa="",bb="";
        for(int k=1;k<=charnum/(num2*2);k++)//输入字母数量
        {
            //while((*i).second){
            //cout<<(*i).first<<' ';
                //a+=(*i).first;
                //b+=(*i).first;
                //(*i).second-=2;
                //if((*i).second==0)i++;
            //}
           // cout<<mp[l]<<' '<<endl;
            while(mp[l]==0&&l<27)l++;
            //cout<<mp[l]<<' ';
            //cout<<(char)(l+'a'+1);
            mp[l]-=2;
            aa+=(char)(l+'a'-1);
            bb+=(char)(l+'a'-1);
            //if(mp[l]==0)l++;
            /*while((*i).second){
            ch.push_back((*i).first);
            ch.push_front((*i).first);
            }*/
        }
        //cout<<aa<<' '<<bb<<endl;
        ch.push_back(aa);
        ch.push_front(bb);
        aa.clear();bb.clear();
        ch.push_back(">");
        ch.push_front("<");
    }
    for(deque<string>::iterator i=ch.begin();i!=ch.end();i++){
        cout<<(*i);
    }
}
//<>test<>//<>test<><>test<>//<>test<>
