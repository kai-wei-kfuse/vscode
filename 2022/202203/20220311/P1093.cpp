#include<iostream>
#include<set>
using namespace std;
struct xx{
    int a,b,c,sum,i;
};
struct cmp {
    bool operator() (const xx& a,const xx& b)const{
        if(a.sum!=b.sum)
        return a.sum>b.sum;
        else return a.a==b.a?a.i<b.i:a.a>b.a;
    }
};
set<xx,cmp>se;
int main()
{
    int n;
    cin>>n;
    xx tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp.a>>tmp.b>>tmp.c;
        tmp.sum=tmp.a+tmp.b+tmp.c;
        tmp.i=i;
        se.insert(tmp);
    }
    int j=1;
    for(set<xx,cmp>::iterator i=se.begin();j<=5;j++,i++){
        cout<<(*i).i<<' '<<(*i).sum<<endl;
    }
}