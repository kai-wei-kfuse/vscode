#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        for (int n = 1; n <= 10; n++)
        {
            for (int k = 1; k <= n; k++)
            {
                vector<int> a;
                for (int i = 1; i <= n; i++)
                {
                    a.push_back(i);
                }
                int cnt = 0;
                do
                {
                    vector<int> p = a;
                    sort(p.begin(), p.begin() + k);
                    vector<int> dp(n + 1, 1);
                    int maxn = 0;
                    for (int i = 0; i < p.size(); i++)
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (p[i] > p[j])
                                dp[i] = max(dp[j] + 1, dp[i]);
                            maxn = max(maxn, dp[i]);
                        }
                    }
                    if (maxn >= n - 1)
                    {

                        cnt++;
                    }
                } while (next_permutation(a.begin(), a.end()));
                cout << cnt << " ";
            }
            cout<<endl;
        }
    }
}
