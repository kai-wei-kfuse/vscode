#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string a;
int chcak(string s) {
    reverse(s.begin(), s.end());
    if (s[0] - '0' > 1)
        return 0;
    if (s[0] - '0' == 1) {
        if (s[1] - '0' > 2)
            return 0;
    }
    if (s[2] - '0' > 3) {
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> a;
        // int front = 0, back = 0;
        string front, back;
        // for (int i = 3; i >= 0; i--) {
        //     front *= 10;
        //     front += a[i] - '0';
        // }
        // for (int i = 4; i <= 7; i++) {
        //     back *= 10;
        //     back += a[i] - '0';
        // }
        // cout << front << ' ' << back;
        for (int i = 0; i <= 3; i++) {
            front += a[i];
        }
        for (int i = 4; i <= 7; i++) {
            back += a[i];
        }
        cout << front << ' ' << back << endl;
        string frontb = front;
        reverse(frontb.begin(), frontb.end());
        if (back >= frontb) {  //不在一年内
            int jw = 3;
            while (1) {
                if (front[jw] == '9')
                    jw--;
                front[jw] = char(front[jw] + 1);
                if (chack(front))
                    break;
            }
            cout << front;
            cout << frontb << endl;
        } else {  //如果一年内
            cout << front;
            cout << frontb << endl;
        }
    }
}