#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
char s[N], ma[N << 1];
int p[N << 1];
int ans = 0;

void manacher(char s[], int len) {
    int k = 0;
    ma[k++] = '$';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {
        ma[k++] = s[i];
        ma[k++] = '#';
    }
    ma[k] = '&';
   // cout << ma << endl;
    int mr = 0, c = 0;
    for (int i = 0; i < k; i++) {
        if (i < mr) {
            p[i] = min(p[2 * c - i], mr - i);
        } else {
            p[i] = 1;
        }
        while (ma[i + p[i]] == ma[i - p[i]]) {
            p[i]++;
        }
        if (p[i] + i > mr) {
            if (i & 1)
                for (int j = max(mr, i + 4); j < p[i] + i; j++) {
                   // cout << j << ' ' << i << ' ' << p[i - (j - i) / 2] << endl;
                    if (!(j - i & 3) && p[i - (j - i) / 2] > (j - i) / 2) {
                        ans = max(ans, j - i);
                    }
                }
            mr = p[i] + i;
            c = i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin >> s;
    manacher(s, n);
    cout << ans << endl;
}