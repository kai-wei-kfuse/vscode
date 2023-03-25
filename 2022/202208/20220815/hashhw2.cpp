#include <bits/stdc++.h>  //字符串哈希-回文子串
#define LL unsigned long long
using namespace std;

LL p[1009], h1[1009], h2[1009], ans;
int n;
char s[1009];
const int h = 31;
map<int, int> mp1, mp2;
int tmp;

LL gethas1(int x, int y) {
    return h1[y] - h1[x - 1] * p[y - x + 1];
}
LL gethas2(int x, int y) {
    return h2[x] - h2[y + 1] * p[y - x + 1];
}
void query1(int x) {  //疑惑
    int l = 1, r = min(x, n - x);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (gethas1(x - mid, x + mid) == gethas2(x - mid, x + mid)) {
            l = mid + 1;
            mp1[gethas2(x - mid + 1, x + mid) + gethas1(x - mid + 1, x + mid)] =
                1;
        } else
            r = mid - 1;
    }
}

void query2(int x) {
    int l = 1, r = min(x, n - x);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (gethas2(x - mid + 1, x + mid) == gethas1(x - mid + 1, x + mid)) {
            l = mid + 1;
            mp1[gethas2(x - mid + 1, x + mid) + gethas1(x - mid + 1, x + mid)] =
                1;
        } else
            r = mid - 1;
    }
}

int main() {
    cin >> tmp;
    int tmp2 = tmp;
    while (tmp--) {
        ans = 0;
        scanf("%s", s + 1);
        n = strlen(s + 1), p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h1[i] = h1[i - 1] * h + (s[i] - 'a');
            p[i] = p[i - 1] * h;
        }
        for (int i = n; i >= 1; i--)
            h2[i] = h2[i + 1] * h + (s[i] - 'a');
        for (int i = 1; i <= n; i++) {
            query1(i);
            query2(i);
            for (auto j : mp1) {
                if (j.second == 1) {
                    mp2[j.first]++;
                }
            }
            mp1.clear();
        }
    }
    for (auto i : mp2)
        if (i.second == tmp2)
            ans++;
    cout << ans;
    return 0;
}
