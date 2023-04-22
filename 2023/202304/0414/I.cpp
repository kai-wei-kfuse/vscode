#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int w1, l1, w2, l2;
    int ans = 0;
    cin >> w1 >> l1 >> w2 >> l2;
    int first = w1 / w2 * l1 / l2;
    int ll = l1 % l2;
    int ww = w1 % w2;
    ans += first;
    int numl;
    if (ll != 0)
    {
        numl = l2 / ll;
        int numll = (w1 / w2 + numl - 1) / numl;
        ans += numll;
    }
    int numw;
    if (ww != 0)
    {
        numw = w2 / ww;
        int numww = (l1 / l2 + numw - 1) / numw;
        ans += numww;
    }
    if (ll != 0 && ww != 0)
    {
        if ((w1 / w2) % numl && (l1 / l2) % numw)
        {
            ans++;
        }
    }
    cout << ans << endl;
}