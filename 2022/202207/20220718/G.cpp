#include <cstring>
#include <iostream>
using namespace std;
int main() {
    string n;
    cin >> n;
    int flag = 0;
    int len = n.length();
    if (len > 1) {
        if (n[0] != '9') {
            for (int i = 1; i < len; i++) {
                cout << '9';
            }
        } else if (n[0] == '9') {
            if (n[len - 2] == '9')
                cout << n;
            else {
                for (int i = 1; i < len; i++) {
                    cout << '9';
                }
            }
        }
    } else if (len == 1) {
        cout << n;
    }
}