#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    vector<int>bg(N+7);
    int l=-1,r=1;
    while(l<=n)
    {
        for(;l<=n;l++)
        {
            if(a[l]==1)
            {
                break;
            }
        }
        if(l==n+1)
        {
            break;
        }

        for(r=l;r<=n;r++)
        {
            if(a[r]==1)
            {
                bg[a[r]]++;
            }else
            {
                if(bg[a[r]]<bg[a[r]-1])
                {
                    bg[a[r]]++;
                }else
                {
                    break;
                }
            }
        }
        //int first_r=r;
        r--;
        res+=r-l+1;
        //r是当前l最大满足的位置
        l=l+1;
        bg[1]--;
        for(;l<=r;l++)
        {
            if(a[l]==1)
            {
                int p=0;
                if(bg[a[l-1]]<bg[a[l-1]+1])
                {
                    p=(a[l-1]+1);
                }
                if(p>0)
                {
                    while(l<r)
                    {
                        bg[a[r]]--;
                        if(a[r]==p)
                        {
                            r--;
                            break;
                        }
                        r--;
                    }
                }
                res+=r-l+1;
            }
            bg[a[l]]--;
        }
       // l=first_r;
    }
    cout<<res<<endl;


}