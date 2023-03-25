#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int mp[7][7];
int per[] = {1, 2, 3, 4, 5, 6};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string c;
        // int flags;
        for (int i = 1; i <= 6; i++) {
            // flags = 1;  //
            cin >> c;
            int len = c.length();
            int tmp = 0;
            for (int j = 0; j < len; j++) {
                if (c[j] == 'h')
                    mp[i][1] = 1;
                if (c[j] == 'a')
                    mp[i][2] = 1;
                if (c[j] == 'r')
                    mp[i][3] = 1;
                if (c[j] == 'b')
                    mp[i][4] = 1;
                if (c[j] == 'i')
                    mp[i][5] = 1;
                if (c[j] == 'n')
                    mp[i][6] = 1;
            }

            // for (int j = 1; j <= 6; j++) {
            //     tmp += mp[i][j];
            // }
            // if (tmp == 0) {
            //     flags = 0;
            // }
        }
        int flag = 1;
        // if (flags) {
        do {
            int sum = 0;
            // for (int i = 0; i < 6; i++) {
            //     cout << per[i] << ' ';
            // }
            // cout << endl;
            for (int i = 1; i <= 6; i++) {
                // cout << mp[i][per[i - 1]] << ' ';
                sum += mp[per[i - 1]][i];
            }
            // cout << endl;
            if (sum == 6) {
                printf("Yes\n");
                flag = 0;
                break;
            }
        } while (next_permutation(per, per + 6));
        if (flag)
            printf("No\n");
    }
}