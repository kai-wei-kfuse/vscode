#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1), dis(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            dis[i] = b[i] - a[i];
        }
        sort(dis.begin() + 1, dis.end(), greater<int>());
        int j = n, ans = 0;
        for (int i = 1; i <= n; i++) {
            //双指针，i从最有钱的开始（剩余最多），j从最没钱的开始（剩余最少<负数>）
            while (i < j && dis[i] + dis[j] < 0)
                j--;
                //如果两个人可以去餐厅那么就不用再加人了，加了也没用
            if (i >= j)
                break;
            ans++;
            j--;
        }
        cout << ans << endl;
    }
}