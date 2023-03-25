#include <iostream>
#include <vector>
using namespace std;

int ask(vector<int>& k) {
    cout << "?" << k[0] << ' ' << k[2] << '\n';
    int x;
    cin >> x;
    if (x == 1) {
        cout << "?" << k[0] << ' ' << k[3] << '\n';
        cin >> x;
        if (x == 1)
            return k[0];
        else
            return k[3];
    } else if (x == 2) {
        cout << "? " << k[1] << ' ' << k[2] << endl;
        cin >> x;
        if (x == 1)
            return k[1];
        return k[2];
    } else {
        cout << "? " << k[1] << ' ' << k[3] << endl;
        cin >> x;
        if (x == 1)
            return k[1];
        return k[3];
    }
}


int main() {
    int t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve, ve1;
        int m = (1 << n);
        for (int i = 1; i <= m; i++) {
            ve.push_back(i);
        }
        while (ve.size() > 2) {
            while (!ve.empty()) {
                vector<int> k(4);
                k[0] = ve.back();
                ve.pop_back();
                k[1] = ve.back();
                ve.pop_back();
                k[2] = ve.back();
                ve.pop_back();
                k[3] = ve.back();
                ve.pop_back();
                int win = ask(k);
                ve1.push_back(win);
            }
            ve = ve1;
            ve1.clear();
        }
        if (ve.size() == 2) {
            cout << "? " << ve[0] << ' ' << ve[1] << endl;
            int x;
            cin >> x;
            if (x == 2)
                ve[0] = ve[1];
        }
        cout << "! " << ve[0] << endl;
    }
}