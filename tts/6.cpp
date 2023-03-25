#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    string a, b;
    string as = "", bs = "";
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    for (int i = 1; i < lena; i++) {
        if ((a[i] - '0') % 2 == (a[i - 1] - '0') % 2) {
            as += max(a[i], a[i - 1]);
        }
    }
    for (int i = 1; i < lenb; i++) {
        if ((b[i] - '0') % 2 == (b[i - 1] - '0') % 2) {
            bs += max(b[i], b[i - 1]);
        }
    }
    if (as == bs) {
        cout << as;
    } else {
        cout << as << endl << bs;
    }
}