#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int p[N << 1];
char ma[N << 1], a[N];

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
    char x;
    while (cin >> x >> a) {
        int len = strlen(a);
        manacher(a, len);
        int ans = 0;
        string anss = "";
        for (int i = 0; i <= len * 2 + 1; i++) {
            if (p[i] - 1 >= 2) {
                string tmp = "";
                for (int j = i - p[i] + 2; j <= i + p[i] - 2; j++) {
                    if (ma[j] != '#') {
                        tmp += ma[j];
                    }
                }
                if (ans == 0) {
                    anss = tmp;
                    ans = p[i] - 1;
                } else if (ans == p[i] - 1 &&tmp[0]<anss[0]){
                    
                }
            }
        }
    }
}