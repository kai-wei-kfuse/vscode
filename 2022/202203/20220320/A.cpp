#include<iostream>
#include<queue>
using namespace std;
queue<int >a;
queue<int >b;
int main()
{
    int n,m;
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        a.push(tmp);
    }
    for(int i=1;i<=m;i++){
        cin>>tmp;
        b.push(tmp);
    }
    int sum=0;
    while(!a.empty()){
        if(a.front()<=b.front()){
            b.front()-=a.front();
            //cout<<b.front()<<endl;
            a.pop();
            if(b.front()==0)b.pop();
        }
        else {
            //cout<<'d'<<endl;
            sum+=b.front();
            b.pop();
        }
    }
    while(!b.empty()){
        //cout<<sum<<endl;
        sum+=b.front();
        b.pop();
    }
    cout<<sum;
}