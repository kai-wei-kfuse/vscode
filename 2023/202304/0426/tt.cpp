#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	int fg=0;
	for(int i=2;i<=n;i++)
	{
        if(__gcd(a[1],a[i])==a[1])
        {
            continue;
        }
		if(a[1]*2+1>a[i])
		{
			fg=1;
			break;
		}
	}
	if(!fg)
	{
		cout<<a[1]<<endl;
	}else
	{
        if(a[1]%2==0)
        {
            int p=a[1]/2;
            for(int i=1;i<=n;i++)
            {
                if(__gcd(p,a[i])==p)
                {
                    continue;
                }
                if(p*2+1>a[i])
                {
                    fg=1;
                    break;
                }
            }
            if(fg)
            {
                cout<<max(1LL,(a[1]-1)/2)<<endl;
            }else
            {
                cout<<max(p,1LL)<<endl;
            }

        }else
        {
            cout<<max((a[1]-1)/2,1LL)<<endl;
        }
        
	}
}
