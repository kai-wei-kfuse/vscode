#include<iostream>
#include<cstring>
using namespace std;
int map[9][9];
const string word[]={"LU","U","RU","R","RD","D","LD","L"};
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int main()
{
    string a,b;
    cin>>a>>b;
    int y1=(a[1]-'0'),y2=(b[1]-'0');
    int x1=(int)a[0]-96,x2=(int)b[0]-96;
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    int xroad=abs(x1-x2),yroad=abs(y1-y2);
    int ans=max(xroad,yroad);
    cout<<ans<<endl;
        if(y2-y1>=0&&x2-x1<0)//说明在左上角
        {
            while(1)
            {
                if(x1==x2||y1==y2)break;
                cout<<"LU"<<endl;
                x1--;
                y1++;
            }
            if(x1==x2&&y1==y2)return 0;
            if(x1>x2)while(x1!=x2){cout<<"L"<<endl;x1--;}
            if(y1<y2)while(y1!=y2){cout<<"U"<<endl;y1++;}
        }
        if(y2-y1>0&&x2-x1>=0)//右上角
        {
            while(1)
            {
                if(x1==x2||y1==y2)break;
                cout<<"RU"<<endl;
                x1++;
                y1++;  
            }
            if(x1==x2&&y1==y2)return 0;
            if(x1<x2)while(x1!=x2){cout<<"R"<<endl;x1++;}
            if(y1<y2)while(y1!=y2){cout<<"U"<<endl;y1++;}
        }
        if(y2-y1<=0&&x2-x1>0)//右下角
        {
            while(1)
            {
                if(x1==x2||y1==y2)break;
                cout<<"RD"<<endl;
                x1++;
                y1--;
            }
            if(x1==x2&&y1==y2)return 0;
            if(x1<x2)while(x1!=x2){cout<<"R"<<endl;x1++;}
            if(y1>y2)while(y1!=y2){cout<<"D"<<endl;y1--;}
        }
        if(y2-y1<0&&x2-x1<=0)//左下角
        {
            while(1)
            {
                if(x1==x2||y1==y2)break;
                cout<<"LD"<<endl;
                x1--;
                y1--;
            }
            if(x1==x2&&y1==y2)return 0;
            if(x1>x2)while(x1!=x2){cout<<"L"<<endl;x1--;}
            if(y1>y2)while(y1!=y2){cout<<"D"<<endl;y1--;}
        }
    }

