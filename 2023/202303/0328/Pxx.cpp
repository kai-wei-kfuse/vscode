#include <bits/stdc++.h>
using namespace std;
// 写一个z函数的模版
const int N = 1e6 + 5;
int z[N];
char s[N];
void get_z(char s[]) {                        // z[i]表示s[i]开始的最长前缀和s[0]开始的最长前缀的长度
    int len = strlen(s);                      // s的长度
    int l = 0, r = 0;                         // l是z[i]的左端点 r是z[i]的右端点 初始值都是0 
    for (int i = 1; i < len; i++) {           // i是z[i]的中心点
        if (i <= r) {                         // 如果i在z[i]的范围内
            z[i] = min(z[i - l], r - i + 1);  // z[i]的值不会超过r-i+1 因为z[i]的右端点是r 而r-i+1是z[i]的长度
        }                                     // 如果i不在z[i]的范围内 那么z[i]的值就是0
        while (i + z[i] < len && s[z[i]] == s[i + z[i]]) {
            // 如果i+z[i]没有超出s的长度 并且s[i+z[i]]和s[z[i]]相等 那么z[i]++
            z[i]++;
        }
        if (i + z[i] - 1 > r) {  // 如果i+z[i]-1超出了z[i]的右端点 那么更新z[i]的左右端点
            l = i;               // z[i]的左端点是i
            r = i + z[i] - 1;    // z[i]的右端点是i+z[i]-1
        }
    }
}
int main() {
    cin >> s;
    get_z(s);
    for (int i = 0; i < strlen(s); i++) {
        cout << z[i] << " ";
    }
    cout << endl;
}