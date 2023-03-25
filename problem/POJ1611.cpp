#include<iostream>
using namespace std;
int a[502][502];
int parent[30502];
int cmp;
int find(int a)
{
    while(parent[a]!=a){
        a=parent[a]=parent[parent[a]];
    }
    return a;
}
void root(int a,int b)
{
    int a_root=find(a);
    int b_root=find(b);
    if(a_root!=b_root)parent[a_root]=b_root;
}
int main()
{
    int stu,n,m;
    cin>>stu>>n;
    while(stu!=0 ||n!=0){
        int ans=0;
        for(int i=0;i<stu+n;i++)
            parent[i]=i;
        for(int i=1;i<=n;i++){
            cin>>m;
            for(int j=1;j<=m;j++){
                cin>>cmp;
                root(cmp,stu+i-1);
            }
        }
        int root_=find(0);
        for(int i=0;i<stu;i++){
            //cout<<parent[i]<<' ';
            if(find(i)==root_)ans++;
        }
        cout<<ans<<endl;
        cin>>stu>>n;
    }
}