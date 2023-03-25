#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        cin >> tmp;
        if (tmp >= 1900) {
            cout << "Division 1" << '\n';
        } else if (tmp >= 1600 && tmp <= 1899) {
            cout << "Division 2" << '\n';
        } else if (tmp >= 1400 && tmp <= 1599) {
            cout << "Division 3" << '\n';
        } else {
            cout << "Division 4" << '\n';
        }
    }
}