#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
1. 输入
2.01背包直接输入
3.多重背包拆开
4.完全背包直接输入
5.dp：完全背包需要从头到尾
6.01and多重需要从尾到头更新
*/
int dp[2005];
struct xx {
    int kind, v, val;
};
vector<xx> ve;
int main() {
    int N, V;
    cin >> N >> V;
    int v, val, s;
    for (int i = 1; i <= N; i++) {
        cin >> v >> val >> s;
        if (s == -1) {
            ve.push_back({1, v, val});
        } else if (s == 0) {
            ve.push_back({0, v, val});
        } else {
            for (int i = 1; i <= s; i *= 2) {
                s -= i;
                ve.push_back({1, i * v, i * val});
            }
            if (s > 0)
                ve.push_back({1, s * v, s * val});
        }
    }
    for (auto i : ve) {
        if (i.kind) {
            for (int j = V; j >= i.v; j--) {
                dp[j] = max(dp[j], dp[j - i.v] + i.val);
            }
        } else {
            for (int j = i.v; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - i.v] + i.val);
            }
        }
    }
    cout << dp[V];
}