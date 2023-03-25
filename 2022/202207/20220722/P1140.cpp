#include <iostream>
#include <map>
using namespace std;

char a[105], b[105];
int dp[105][105];

int main() {
    int x, y;
    cin >> x >> a + 1 >> y >> b + 1;
    map<pair<char, char>, int> mp;
    mp[{'A', '-'}] = -3;
    mp[{'A', 'T'}] = -1;
    mp[{'A', 'G'}] = -2;
    mp[{'A', 'C'}] = -1;
    mp[{'A', 'A'}] = 5;

    mp[{'T', '-'}] = -1;
    mp[{'T', 'T'}] = 5;
    mp[{'T', 'G'}] = -2;
    mp[{'T', 'C'}] = -2;
    mp[{'T', 'A'}] = -1;

    mp[{'G', '-'}] = -2;
    mp[{'G', 'T'}] = -2;
    mp[{'G', 'G'}] = 5;
    mp[{'G', 'C'}] = -3;
    mp[{'G', 'A'}] = -2;

    mp[{'C', '-'}] = -4;
    mp[{'C', 'T'}] = -2;
    mp[{'C', 'G'}] = -3;
    mp[{'C', 'C'}] = 5;
    mp[{'C', 'A'}] = -1;
    for (int i = 1; i <= x; i++) {
        dp[i][0] = dp[i - 1][0] + mp[{a[i], '-'}];
        // cout << dp[i][0] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= y; i++) {
        dp[0][i] = dp[0][i - 1] + mp[{b[i], '-'}];
        // cout << dp[0][i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + mp[{a[i], b[j]}],
                           max(dp[i - 1][j] + mp[{a[i], '-'}],
                               dp[i][j - 1] + mp[{b[j], '-'}]));
            // cout << a[i] << ',' << b[j] << ':' << mp[{a[i], b[j]}] << ' ';
        }
        // cout << endl;
    }
    cout << dp[x][y];
}