#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ve(505, vector<int>(505));

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 1) {
        cout << "0" << endl;
    } else if (a == 1||b==1) {
        if(a==1)
        for (int i = 1; i <= b; i++) {
            cout << i + 1 << ' ';
        }else{
            for (int i = 1; i <= a; i++) {
            cout << i + 1 << endl;
        }
        }
    } else {
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                ve[i][j] = (i + b) * (j);
                cout << ve[i][j] << ' ';
            }
            cout << endl;
        }
    }
}