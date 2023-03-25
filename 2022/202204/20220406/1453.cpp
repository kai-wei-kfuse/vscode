#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll a[20191000];

int main() {
    a[1] = a[2] = a[3] = 1;
    for (int i = 4; i <= 20190324; i++) {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10000;

        // cout << a[i] << endl;
    }
    cout << a[20190324];
    // cout << "0115";
}