#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c >= a && d >= a) {
        cout << c << "-Y" << ' ' << d << "-Y" << endl;
        cout << "huan ying ru guan" << endl;
    } else if (c < a) {  // 1:x
        if (d >= b) {    // 2:o
            cout << c << "-Y" << ' ' << d << "-Y" << endl;
            cout << "qing 2 zhao gu hao 1";
        } else {          //
            if (d < a) {  // 2:x
                cout << c << "-N" << ' ' << d << "-N" << endl;
                cout << "zhang da zai lai ba";
            } else {  // 2:o
                cout << c << "-N" << ' ' << d << "-Y" << endl;
                cout << "2: huan ying ru guan";
            }
        }
    } else if (d < a) {
        if (c >= b) {  // 2:o
            cout << c << "-Y" << ' ' << d << "-Y" << endl;
            cout << "qing 1 zhao gu hao 2";
        } else {          //
            if (c < a) {  // 2:x
                cout << c << "-N" << ' ' << d << "-N" << endl;
                cout << "zhang da zai lai ba";
            } else {  // 2:o
                cout << c << "-Y" << ' ' << d << "-N" << endl;
                cout << "1: huan ying ru guan";
            }
        }
    }
}