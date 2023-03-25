#include<iostream>
#include<queue>
using namespace std;
priority_queue <int ,vector<int > ,greater<int > >q;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    int sum=0;
    int x=0,y=0;
    while(q.size()>1){
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        q.push(x+y);
        sum+=x+y;
        //cout<<sum<<' ';
    }
    cout<<sum;
}