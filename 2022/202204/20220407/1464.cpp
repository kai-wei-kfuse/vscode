#include <iostream>
using namespace std;
int chack(int x) {
    if (x <= 0)
        return 0;
    while (x) {
        int tmp = x % 10;
        x /= 10;
        if (tmp == 4 || tmp == 2)
            return 0;
    }
    return 1;
}
int main() {
    int sum = 0;
    for (int i = 1; i <= 2019; i++) {
        for (int j = i + 1; j <= 2019; j++) {
            int k = 2019 - i - j;
            if (k <= j)
                continue;
            if (chack(k) && chack(i) && chack(j)) {
                // cout << i << ' ' << j << ' ' << k << endl;
                sum++;
            }
        }
    }
    cout << sum;
}