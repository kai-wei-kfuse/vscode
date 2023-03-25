#include <cstring>
#include <iostream>
using namespace std;

// #define IOS ios::sync_with_stdio, cin.tie(0), cout.tie(0)
const int N = 1e5 + 5;
int next_[N];
char s[N];
int main() {
    // IOS;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);

        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
        }
        if (n % (n - next_[n]) == 0 && n / (n - next_[n]) >= 2) {
            printf("0\n");
        } else {
            printf("%d\n", n - next_[n] - next_[n] % (n - next_[n]));
        }
    }
}