#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int ii,jj;
int a[100002],b[100002];
int main()
{
    cin>>n;
    while(n--){
        int maxa=0,maxb=0,max=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            if(maxa<a[i]){maxa=a[i];
            ii=i;}
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            if(maxb<b[i]){maxb=b[i];
            jj=i;}
        }
        //cout<<maxa<<' '<<maxb<<' '<<b[ii]<<endl;
        if(maxa>=maxb){
            max=b[ii];
            //cout<<max;
            for(int i=1;i<=m;i++){
                if(a[i]<b[i] && b[i]>b[ii]){
                    swap(a[i],b[i]);
                    }
                    if(b[i]>max)max=b[i];
            }
            printf("%d\n",max*maxa);
        }
        else if(maxa<maxb){
            max=a[ii];
            for(int i=1;i<=m;i++){
                if(a[i]>b[i] && a[i]>a[jj])
                {
                    swap(a[i],b[i]);
                    }
                    if(a[i]>max)max=a[i];
            }
            printf("%d\n",max*maxb);
        }
        /*if(maxa==maxb){
            if(ii==jj)printf("%d\n",maxa*maxb);
            else{
            for(int i=1;i<=m;i++){
                if(a[i]>b[i] && a[i]>a[jj])
                {
                    swap(a[i],b[i]); 
                    } 
                    if(a[i]>max)max=a[i];             
            }
            printf("%d\n",max*maxb);}
        }*/
    }
}