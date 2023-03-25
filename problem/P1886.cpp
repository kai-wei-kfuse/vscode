#include <iostream>//单调队列 滑动窗口
using namespace std;
int a[1000002];
int q[1000002];
int x[1000002];
int q1[1000002];
int x1[1000002];
int head=1,tail=0;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        while(head<=tail && x[head]+k<=i)head++;
        while(head<=tail && q[tail]>a[i])tail--;
        q[++tail]=a[i];
        x[tail]=i;
        if(i>=k)printf("%d ",q[head]);
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        while(head<=tail && x1[head]+k<=i)head++;
        while(head<=tail && q1[tail]<a[i])tail--;
        q1[++tail]=a[i];
        x1[tail]=i;
        if(i>=k)printf("%d ",q1[head]);
    }
}