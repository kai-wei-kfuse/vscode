#include <iostream>
using namespace std;
int num[100005];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int nump = 0, numf = 0;
        int tmp;
        cin >> tmp;
        for (int i = 1; i <= tmp; i++) {
            cin >> num[i];
            if (num[i] < 0) {
                numf++;
                num[i] = -num[i];
            } else
                nump++;
        }
        int flag = 0;
        for (int i = 2; i <= numf; i++) {
            if (num[i] > num[i - 1]) {
                flag = 1;
            }
        }
        for (int i = numf + 2; i <= tmp; i++) {
            if (num[i] < num[i - 1]) {
                flag = 1;
            }
        }
        if (flag)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}
