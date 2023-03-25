#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int tmp;
    string a;
    while (n--) {
        cin >> tmp;
        cin >> a;
        int sumr = 0, sumb = 0;
        int flag = 1;
        for (int i = 0; i < tmp; i++) {
            if (a[i] == 'B') {
                sumb++;
            } else if (a[i] == 'R') {
                sumr++;
            } else {
                if (sumb + sumr == 1 || (sumb == 0 && sumr > 0) ||
                    (sumr == 0 && sumb > 0)) {
                    cout << "NO" << endl;
                    flag = 0;
                    break;
                }
                sumr = 0;
                sumb = 0;
            }
        }
        if (a[tmp - 1] != 'W')
            if ((sumb + sumr == 1 || (sumb == 0 && sumr > 0) ||
                 (sumr == 0 && sumb > 0)) &&
                flag != 0) {
                cout << "NO" << endl;
                flag = 0;
            }
        if (flag)
            cout << "YES" << endl;
    }
}