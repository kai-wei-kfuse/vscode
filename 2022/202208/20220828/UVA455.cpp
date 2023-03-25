// #include <cstring>
// #include <iostream>
// using namespace std;

// int next_[850];
// char a[850];

// int main() {
//     int n;
//     cin >> n;
//     while (n--) {
//         cin >> a + 1;
//         int len = strlen(a + 1);
//         for (int i = 2, j = 0; i <= len; i++) {
//             while (j && a[i] != a[j + 1])
//                 j = next_[j];
//             if (a[i] == a[j + 1])
//                 j++;
//             next_[i] = j;
//         }
//         if (!len % (len - next_[len]))
//             cout << len - next_[len] << '\n';
//         else
//             cout << len << '\n';
//         if (n)
//             cout << '\n';
//     }
//     return 0;
// }
#include <iostream>
#include <cstring>
#define eps 1e-7
#define re register
#define N 100101
#define MAX 2001
#define PI 3.1415927
#define inf 1e18
using namespace std;
typedef long long ll;
typedef double db;
inline void read(re ll& ret) {
    ret = 0;
    re ll pd = 0;
    re char c = getchar();
    while (!isdigit(c)) {
        pd |= c == '-';
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 1) + (ret << 3) + (c & 15);
        c = getchar();
    }
    ret = pd ? -ret : ret;
    return;
}
ll n, kmp[N], len;
char s[N];
int main() {
    read(n);
    while (n--) {
        scanf("%s", s + 1);
        len = strlen(s + 1);
        for (re int i = 2, j = 0; i <= len; i++) {
            while (j && s[i] != s[j + 1])
                j = kmp[j];
            if (s[i] == s[j + 1])
                j++;
            kmp[i] = j;
        }
        if (!(len % (len - kmp[len])))
            printf("%lld\n", len - kmp[len]);
        else
            printf("%lld\n", len);
        if (n)
            putchar('\n');
    }
    exit(0);
}