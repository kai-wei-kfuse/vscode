#include<iostream>
#include<cstring>
using namespace std;
string a;
char x;
int xnum=0;
int rights=0;
int turn(int i,int j){
    if(a[i]<'0'||a[i]>'9')return 0;
    int ans=0;
    while(i<=j){
    ans=ans*10+a[i]-'0';
    i++;
    }
    return ans;
}
int main()
{
    int ii=1;
    cin>>a;
    int len=a.length();
    int i;
    for(i=0;a[i]!='=';i++){
        if(a[i]>='0'&&a[i]<='9'||a[i]=='-'){
            if(a[i]=='-')i++;
            int j=i;
            while(a[j+1]>='0'&&a[j+1]<='9')j++;
            if(a[j+1]!='-'&&a[j+1]!='+'&&a[j+1]!='='){
                x=a[j+1];
                //xnum+=turn(i,j);
                //cout<<turn(i,j)<<endl;
                if(i>0&&a[i-1]=='-')xnum-=turn(i,j);
                else xnum+=turn(i,j);
                if(turn(i,j)==0){
                    if(a[i-1]='-')xnum--;
                    else xnum++;
                    }
                //cout<<xnum<<'.';
                i=j;
            }
            else{
                //cout<<turn(i,j)<<endl;
            if(i>0&&a[i-1]=='-')rights+=turn(i,j);
            else rights-=turn(i,j);
            //cout<<rights<<'|';
            i=j;
            }
        }
        else{
            x=a[i-1];
            if(i>0&&a[i-2]=='-')xnum-=1;
            else xnum+=1;
        }
    }
   for(;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'||a[i]=='-'){
            if(a[i]=='-')i++;
            int j=i;
            while(a[j+1]>='0'&&a[j+1]<='9')j++;
            if(j<len-1&&(a[j+1]!='-'&&a[j+1]!='+'&&a[j+1]!='=')){
                //x=a[j+1];
                //xnum+=turn(i,j);
                //cout<<turn(i,j)<<endl;
                if(a[i-1]=='-')xnum+=turn(i,j);
                //else if(a[i]=='-')xnum+=1;
                else xnum-=turn(i,j);
                if(turn(i,j)==0){
                    if(a[i-1]='-')xnum++;
                    else xnum--;
                    }
                //cout<<xnum<<'.';
                i=j;
            }
            else{
                //cout<<turn(i,j)<<endl;
            if(a[i-1]=='-')rights-=turn(i,j);
            else rights+=turn(i,j);
            //cout<<rights<<'|';
            i=j;
            }
        }
        else{
            x=a[i-1];
            if(i>0&&a[i-2]=='-')xnum+=1;
            else xnum-=1;
        }
    }
    //cout<<rights<<' '<<xnum;
    double ans=(double)rights/(double)xnum;
    cout<<x;
    printf("=%.3f",ans);
}