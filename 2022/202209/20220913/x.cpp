#include <bits/stdc++.h>
using namespace std;
vector<int> ve;
vector<int> ans(70);
int main()
{
    int K;
    cin >> K;
    if (K == 1)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2;
        return 0;
    }
    else if (K == 2)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 1;
        return 0;
    }
    //-----对k质因数分解
    int k = K;
    for (int i = 2; i <= k / i; i++)
    {
        while (k % i == 0)
        {
            ve.push_back(i);
            k /= i;
        }
    }
    if (k > 1)
    {
        ve.push_back(k);
    }
    for (auto it : ve)
    {
        cout << it << " ";
    }
    cout << endl;

    //-------
    long long num = 0;
    int temp = 0;
    int j1 = 1;       // j1记录由2开始的总数，j2记录每一个质因数是否走完
    for (auto i : ve) //遍历所有质因数
    {
        num += i;

        for (int j = 1; j <= i; ++j)
        {

            if (j == 1)
            {
                ans[j1] = 1;
            }
            else
            {
                ans[j1] = j1;
            }
            j1++;
        }
    }
    cout << num + 1 << endl;
    for (int i = 1; i <= num; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << 10000000000 << " ";
    for (int i = 1; i <= num; ++i)
    {
        cout << 1 << " ";
    }
}