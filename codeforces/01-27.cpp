#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct aa{
    int c,i;
}a[100002],b[100002];
bool cmp(aa x,aa y){
    return x.c>y.c;
}
int main()
{
    cin>>n;
    while(n--){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i].c);
            a[i].i=i; 
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i].c);
            b[i].i=i;
        }
        sort(a+1,a+m+1,cmp);
        sort(b+1,b+m+1,cmp);
        /*for(int i=1;i<=m;i++){
            cout<<a[i].c<<' ';
        }
        cout<<endl;
        for(int i=1;i<=m;i++){
            cout<<b[i].c<<' ';
        }*/
        //swap(a[1].c,b[a[1].i].c);
        int tmp=b[a[1].i].c;
        cout<<tmp<<endl;
        if(a[1].c>b[1].c){
            for(int i=2;i<=m;i++){
                if(a[i].c>b[a[i].i].c && tmp<b[a[i].i].c){
                    swap(a[i].c,b[a[i].i].c);
                    cout<<'d'<<endl;
                }
                cout<<a[i].c<<' '<<b[a[i].i].c<<' '<<i<<endl;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<a[i].c<<' ';
        }
        cout<<endl;
        for(int i=1;i<=m;i++){
            cout<<b[i].c<<' ';
        }
    }
}