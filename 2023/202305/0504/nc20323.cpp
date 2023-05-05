#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long mod = 1e9+7;

int kmp(vector<int >a,int n){
    int i,j;
    vector<int >next_(n+1);
    for(i=2,j=0;i<=n;i++){
        while(j&&a[i]!=a[j+1])j=next_[j];
        if(a[i]==a[j+1])j++;
        next_[i]=j;
    }
    return n-next_[n];
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string > ve(n+1);
    for (int i = 0; i < n; i++){
        cin >> ve[i];
    }
    vector<vector<int>> num(n+2, vector<int>(m+2));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> num[i][j];
        }
    }
    vector<int> tmp1(n + 1), tmp2(m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp1[i+1] = (ve[i][j]+tmp1[i+1]*13331)%mod;
            tmp2[j+1] = (ve[i][j]+tmp2[j+1]*13331)%mod;
        }
    }
    int p_, q;
    p_ = kmp(tmp1, n);
    q = kmp(tmp2, m);
    //cout<<p_<<" "<<q<<endl;
    vector<vector<int>> ans(n+2, vector<int>(m+2));
    deque<int> q1;
    for (int i = 0; i < n; i++)
    {
        q1.clear();
        for (int j = 0; j < m; j++)
        {
            while (!q1.empty() && num[i][q1.back()] <= num[i][j])
                q1.pop_back();
            q1.push_back(j);
            while (!q1.empty() && j- q + 1 > q1.front())
                q1.pop_front();
                ans[i][j] = num[i][q1.front()];
        }
    }
    long long ans_ = 0x7f7f7f7f;
    for (int i = q - 1; i < m; i++)
    {
        q1.clear();
        for (int j = 0; j < n; j++)
        {
            while (!q1.empty() && ans[q1.back()][i] <= ans[j][i])
                q1.pop_back();
            q1.push_back(j);
            while (!q1.empty() &&j - p_ + 1 > q1.front())
                q1.pop_front();
            if (j >= p_ - 1)
                ans_ = min(ans_, ans[q1.front()][i]);
        }
    }
    // priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         while (!q1.empty() && q1.top().second < j - q + 1)
    //             q1.pop();
    //         q1.push({num[i][j], j});
    //         ans[i][j] = q1.top().first;
    //         // cout<<q1.top().first<<"|"<<q1.top().second<<" ";
    //     }
    //     while (!q1.empty())
    //         q1.pop();
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         while (!q1.empty() && q1.top().second < j - p_ + 1)
    //                 q1.pop();
    //         q1.push({ans[j][i], j});
    //         ans[j][i] = max(ans[j][i], q1.top().first);
    //         // cout<<q1.top().first<<"|"<<q1.top().second<<" ";
    //     }
    //     // cout<<endl;
    //     while (!q1.empty())
    //         q1.pop();
    // }

    //cout << ans_ << endl;
    cout << ans_ * (p_ + 1) * (q + 1) << endl;
}