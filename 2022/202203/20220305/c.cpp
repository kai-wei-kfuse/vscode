#include<iostream>
#include<cstring>
using namespace std;
int time_sum=0;
int borrow_sum=0;
struct xx{
    int ins;
    int t;
}book[1002];
int turn(string a){
    int x=0;
    for(int i=0;i<=1;i++){
        x=x*10+(a[i]-'0');
    }
    x*=60;
    int y=0;
    for(int i=3;i<=4;i++){
        y=y*10+(a[i]-'0');
    }
    return x+y;
}
int main()
{
    int day;
    cin>>day;
    int num;
    string b,c;
    while(cin>>num>>b>>c){
        if(!num){//判断下一天
            if(borrow_sum){
            double cmp=(double)time_sum/(double)borrow_sum+0.5;
            cout<<borrow_sum<<' '<<(int)cmp<<endl;}
            else 
            cout<<borrow_sum<<' '<<'0'<<endl;
            borrow_sum=0;
            time_sum=0;
            memset(book,0,sizeof(book));
            if(!(day--))break;
            continue;
        }
        if(b=="S"){
            //if(!book[num].ins){
                book[num].t=turn(c);//借出时间
                book[num].ins=1;//借出则为1
            //}
        }
        else if(b=="E"){
            if(book[num].ins){//有借才有还
                time_sum+=turn(c)-book[num].t;
                borrow_sum++;
                //cout<<time_sum<<' '<<borrow_sum<<endl;
                book[num].ins=0;
                book[num].t=0;
            }
        }
    }
}