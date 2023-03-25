#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, p;
    cin >> a >> b >> p;
    if (a > b) {
        if (b >= a * p / 100)
            cout << "Ambidextrous";
        else
            cout << "Left-handed";
    } else if (a < b) {
        if (a >= b * p / 100)
            cout << "Ambidextrous";
        else
            cout << "Right-handed";
    } else if (a == b) {
        cout << "Ambidextrous";
    }
}