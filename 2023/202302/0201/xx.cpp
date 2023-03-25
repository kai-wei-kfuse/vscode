#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 200000;

int next_[MAXN];
int extend[MAXN];

void EKMP(char s[], char t[])  // s[]为主串，t[]为模式串
{
    int i, j, p, l;
    int len = strlen(t);
    int len1 = strlen(s);
    memset(next_, 0, sizeof(next_));
    memset(extend, 0, sizeof(extend));

    next_[0] = len;
    j = 0;
    while (j + 1 < len && t[j] == t[1 + j])
        j++;
    next_[1] = j;

    int a = 1;
    for (int i = 2; i < len; i++) {
        p = next_[a] + a - 1;
        l = next_[i - a];
        if (i + l < p + 1)
            next_[i] = l;
        else {
            j = max(0, p - i + 1);
            while (i + j < len && t[i + j] == t[0 + j])
                j++;
            next_[i] = j;
            a = i;
        }
    }

    j = 0;
    while (j < len1 && j < len && s[j] == t[j])
        j++;

    extend[0] = j;
    a = 0;
    for (i = 1; i < len1; i++) {
        p = extend[a] + a - 1;
        l = next_[i - a];
        if (l + i < p + 1)
            next_[i] = l;
        else {
            j = max(0, p - i + 1);
            while (i + j < len1 && j < len && s[i + j] == t[j])
                j++;
            extend[i] = j;
            a = i;
        }
    }
}

char s[MAXN], tab[MAXN], c[MAXN];
map<char, char> map1;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", &tab, &s);
        int len = strlen(tab);
        int len1 = strlen(s);
        for (int i = 0; i < len; i++)
            map1[tab[i]] = 'a' + i;
        for (int i = 0; i < len1; i++)
            c[i] = map1[s[i]];
        c[len1] = 0;
        EKMP(s, c);

        int k;
        for (int i = 1; i <= len1; i++) {
            cout << extend[i] << ' ';
        }
        for (k = 0; k < len1; k++) {
            if (k + extend[k] >= len1 && k >= extend[k])
                break;
        }
        // cout << " " << k << ' ' << len1 << endl;
        for (int i = 0; i < k; i++)
            printf("%c", s[i]);
        for (int i = 0; i < k; i++)
            printf("%c", map1[s[i]]);

        printf("\n");
    }
    return 0;
}
