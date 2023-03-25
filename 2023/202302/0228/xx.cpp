#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        double a, b;
        cin >> a >> b;
        b /= 2.0;
        double g = (a - 100) * 0.9;
        if (abs(g - b) < g * 0.1) {
            cout << "You are wan mei!" << endl;
        } else {
            if (b > g) 
                    cout << "You are tai pang le!" << endl;
                else {
                    cout << "You are tai shou le!" << endl;
                }
            
        }
    }
}