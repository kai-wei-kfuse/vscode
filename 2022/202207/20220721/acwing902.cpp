#include <algorithm>
#include <iostream>
using namespace std;

char a[1005], b[1005];
int dp[1005][1005];

int main() {
    int lena, lenb;
    cin >> lena >> a + 1 >> lenb >> b + 1;
    for (int i = 1; i <= lena; i++)
        dp[i][0] = i;
    for (int i = 1; i <= lenb; i++)
        dp[0][i] = i;
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[lena][lenb];
}
