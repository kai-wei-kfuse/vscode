#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct xx{
    int a;
    string s;
}a[200005];
bool cmp(xx a, xx b){
    return a.a<b.a;
}
int main()
{
    getline (cin,a[1].s);
    a[1].a=0;
    int i=2;
    while(getline (cin,a[i].s),a[i].s!="};"){
        if(a[i].s[0]=='i')a[i].a=4;
        else if(a[i].s[0]=='b')a[i].a=2;
        else if(a[i].s[0]=='c')a[i].a=1;
        else if(a[i].s[0]=='s')a[i].a=3;
        else if(a[i].s[0]=='f')a[i].a=4;
        else if(a[i].s[0]=='d')a[i].a=8;
        else if(a[i].s.find("long long ")!=-1||a[i].s.find("long double ")!=-1)a[i].a=8;
        else a[i].a=4;
        i++;
    }
    //cout<<i<<endl;
    sort(a+1,a+i,cmp);
    for(int j=1;j<i;j++){
        cout<<a[j].s<<endl;
    }
    cout<<"};";
}