#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b < 129) {
                cout << "duo chi yu!";
            } else if (b == 129) {
                cout << "wan mei!";
            } else {
                cout << "ni li hai!";
            }
            cout << ' ';
            if (c < 25) {
                cout << "duo chi rou!";
            } else if (c > 25) {
                cout << "shao chi rou!";
            } else {
                cout << "wan mei!";
            }
        }
        if (a == 1) {
            if (b < 130) {
                cout << "duo chi yu!";
            } else if (b == 130) {
                cout << "wan mei!";
            } else {
                cout << "ni li hai!";
            }
            cout << ' ';
            if (c < 27) {
                cout << "duo chi rou!";
            } else if (c > 27) {
                cout << "shao chi rou!";
            } else {
                cout << "wan mei!";
            }
        }
        cout << endl;
    }
}