#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
using namespace std;

const int maxx = 1000099;  // 描述一个学生2个点，最多1e6个点
int a[maxx], f[maxx], num[maxx];
vector<P> v1;
vector<int> v2;
map<int, int> mp;

int main() {
    int n, k, x, y, z, pos = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        v1.push_back(make_pair(x, y + 1));
        v2.push_back(z);
        a[pos++] = x;
        a[pos++] = y + 1;
    }
    sort(a, a + pos);
    int pos2 = 1;
    for (int i = 0; i < pos; i++) {
        if (mp[a[i]] == 0)
            mp[a[i]] = pos2++;
    }
    for (int i = 0; i < (int)v1.size(); i++) {
        f[mp[v1[i].first]] ^= v2[i];
        f[mp[v1[i].second]] ^= v2[i];
        num[mp[v1[i].first]]++;
        num[mp[v1[i].second]]--;
    }
    int ans = -1;
    for (int i = 1; i < pos2;
         i++)  // 这里要到pos2-1,不是n.描述一个学生两个点，所以最多n*2个点.
    {
        f[i] ^= f[i - 1];
        num[i] += num[i - 1];
        if (num[i] >= k)
            ans = max(ans, f[i]);
    }
    printf("%d\n", ans);

    return 0;
}
