#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tmp = n;
    int flag = 0;
    int num = to_string(n).size();
    while (tmp) {
        int x = tmp % 10;
        tmp /= 10;
        if (x == 0)
            flag++;
        else if (n % x != 0) {
            flag++;
        }
    }
    //cout << flag << ' ' << num << endl;
    if (flag == 0) {
        cout << "happier";
    } else if (flag < num) {
        cout << "happy";
    } else {
        cout << "upset";
    }
}