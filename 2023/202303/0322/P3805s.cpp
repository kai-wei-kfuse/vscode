#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e7 + 5;
int p[N << 1];
char a[N], ma[N << 1];

void manacher(char s[], int len) {
    int k = 0;
    ma[k++] = '$';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {
        ma[k++] = s[i];
        ma[k++] = '#';
    }
    ma[k] = '&';
    int mr = 0, c = 0;  // mr表示回文串的最右边界，c就是这个回文串的中心
    for (int i = 0; i < k; i++) {
        if (i < mr) {
            p[i] = min(p[2 * c - i], c + p[c] - i);
        } else {
            p[i] = 1;
        }
        while (ma[p[i] + i] == ma[i - p[i]])
            p[i]++;
        if (p[i] + i > mr) {
            mr = p[i] + i;
            c = i;
        }
    }
}

int main() {
    cin >> a;
    int len = strlen(a);
    manacher(a, len);
    int ans = 0;
    for (int i = 0; i <= 2 * len + 1; i++) {
        ans = max(ans, p[i] - 1);
    }
    cout << ans << endl;
}