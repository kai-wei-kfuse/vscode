#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a;
    cin >> b;
    int fa = 0, fb = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < '0' || a[i] > '9') {
            fa = 1;
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            fb = 1;
        }
    }
    int aa = 0, bb = 0;
    if (fa) {
        cout << "? ";
    } else {
        for (int i = 0; i < a.size(); i++) {
            aa *= 10;
            aa += a[i] - '0';
        }
        if (aa>=0&&aa <= 1000)
            cout << aa << ' ';
        else {
            cout << "? ";
            fa = 1;
        }
    }
    cout << "+ ";
    if (fb) {
        cout << "? ";
    } else {
        for (int i = 0; i < b.size(); i++) {
            bb *= 10;
            bb += b[i] - '0';
        }
        if (bb>=0 && bb <= 1000)
            cout << bb << ' ';
        else {
            cout << "? ";
            fb = 1;
        }
    }
    cout << "= ";
    if (fa == 0 && fb == 0) {
        cout << aa + bb;
    } else {
        cout << "?";
    }
}