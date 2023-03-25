#include<iostream>
#include<algorithm>
using namespace std;
struct xx{
    int x,y;
    int num;
}a[450];
int b[450];
bool cmp(xx a,xx b){
    return a.num>b.num;
}
int main()
{
    int l,k,t;
    int cnt=0;
    int sum=0;
    cin>>l>>k>>t;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=k;j++){
            cin>>a[++cnt].num;
            a[cnt].x=i;
            a[cnt].y=j;
            /*if(a[i][j].num){
                b[++cnt]=a[i][j].num;
            }*/
        }
    }
    sort(a+1,a+l*k+1,cmp);
    //sort(b+1,b+cnt+1,greater<int>());//cnt有花生的格子的数量
    int nowx,nowy;
    nowx=0;nowy=a[1].y;
    for(int i=1;a[i].num;i++){
        int tt=abs(a[i].x-nowx)+abs(a[i].y-nowy)+1+a[i].x;
        //cout<<a[i].x<<' '<<a[i].y<<' '<<t<<' '<<tt<<endl;
        //cout<<nowx<<' '<<nowy<<' '<<t<<' '<<tt<<endl;
        if(tt<t){ 
            sum+=a[i].num;
            nowx=a[i].x;
            nowy=a[i].y;
            t=t-tt+a[i].x;
            //cout<<nowx<<' '<<nowy<<' '<<t<<' '<<tt<<' '<<a[i].y<<endl;
        }
        else if(tt==t){
            //cout<<nowx<<' '<<nowy<<' '<<t<<' '<<tt<<' '<<a[i].y<<endl;
            sum+=a[i].num;
            break;
        }
        else break;
    }
    cout<<sum;
}