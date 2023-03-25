#include<iostream>
using namespace std;
char a[22][22];
int main()
{
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        int x,y;
        int flag=0;
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>a[i][j];
            }
        }
        int ii,jj;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(a[i][j]=='*'){
                    ii=i;jj=j;
                    break;
                }
            }
        }
       // cout<<ii<<' '<<jj<<endl;
        while(a[ii][jj]=='*')
        {
            
            if(a[ii+1][jj]=='*'&&a[ii-1][jj]=='*'&&a[ii][jj+1]=='*')
            {
                printf("Case %d: Eight\n",k);
                flag=1;
                break;
            }
        ii--;
        //cout<<a[ii][jj]<<"|";
        }
        if(!flag)printf("Case %d: Zero\n",k);         
    }
}