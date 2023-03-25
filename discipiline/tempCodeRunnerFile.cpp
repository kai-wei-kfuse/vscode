#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector < vector <int> > a;
vector < int > x;
int main()
{
    int n,m;
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=m;i++){
        x.push_back(0);
    }
    a.push_back(x);
    for(int i=1;i<=n;i++){
        x.clear();
        x.push_back(0);
        for(int j=1;j<=m;j++){
            scanf("%d",&tmp);
            x.push_back(tmp);
        }
        a.push_back(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    int t;
    cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]);
    }
}