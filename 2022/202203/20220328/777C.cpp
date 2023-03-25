#include<iostream>
#include<cstring>
#include<vector>
#include<array>
using namespace std;
int a[101][101];
vector<array<int ,4> >ans;
int main()
{
    int n;
    cin>>n;
    int x,y;
    while(n--){
        cin>>x>>y;
        char c;
        for(int i=1;i<=x;i++){
            for(int j = 1; j<= y; j++){
               cin>>c;
               a[i][j]=c-'0'; 
            }
        }
        ans.clear();
        if(a[1][1]==1){cout<<-1<<endl;
        continue;}
        for(int i=x; i >=1; i--){
            for(int j=y; j>=1 ;j--){
                if(a[i][j]==1){
                    if(j>1){
                        ans.push_back({i,j-1,i,j});
                        //cout<<i<<' '<<j-1<<' '<<i<<' '<<j<<endl;
                    }
                    else {
                        ans.push_back({i-1,j,i,j});
                        //cout<<i-1<<' '<<j<<' '<<i<<' '<<j<<endl;
                    }
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto i: ans){
            cout<< i[0]<<' '<< i[1] << ' '<< i[2]<< ' '<< i[3]<< endl;
        }
    }
}