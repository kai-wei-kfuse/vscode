#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct st{
    string name;
    int num1,num2;
    char a,b;
    int num3;
    int money;
    int num;
}node[105];
bool cmp(st a,st b){
    if(a.money!=b.money)
    return a.money>b.money;
    else return a.num<b.num;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i].name>>node[i].num1>>node[i].num2>>node[i].a>>node[i].b>>node[i].num3;
        node[i].num=i;
        if(node[i].num1>80&&node[i].num3>0)node[i].money+=8000;
        if(node[i].num1>85&&node[i].num2>80)node[i].money+=4000;
        if(node[i].num1>90)node[i].money+=2000;
        if(node[i].num1>85&&node[i].b=='Y')node[i].money+=1000;
        if(node[i].num2>80&&node[i].a=='Y')node[i].money+=850;
    }
    sort(node+1,node+1+n,cmp);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=node[i].money;
    }
    cout<<node[1].name<<endl;
    cout<<node[1].money<<endl;
    cout<<sum<<endl;
}