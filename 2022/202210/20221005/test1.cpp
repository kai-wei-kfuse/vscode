#include <bits\stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int n_ = rnd.next(2, n);  // n
    int t1 = rnd.next(0, 1000 * 1000);
    int i_ = rnd.wnext(1, 1000, -10);
    int num1 = rnd.wnext(2, n_, 5);
    int num2 = n_ - num1;
    println(n_);
    int minn = 0;
    vector<int> q1(num1);  // t1
    vector<int> q2(num2);  // t2
    int bias_ = rnd.next(-1000 * 10, -1000);
    for (int i = 0; i < num1; i++) {
        q1[i] = rnd.wnext(minn, t1, bias_);
    }
    for (int i = 0; i < num2; i++) {
        q2[i] = rnd.wnext(minn, t1, bias_);
    }
    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());
    int bias_2 = rnd.next(-10, 2);
    int bias_3 = rnd.wnext(-1000 * 1000, -1000 * 100, -1000);
    for (int i = 0; i < num1; i++) {
        cout << 1 << " ";
        cout << q1[i] << " ";
        cout << rnd.wnext(minn, i_, bias_2) << endl;
    }
    for (int i = 0; i < num2; i++) {
        cout << 2 << " ";
        cout << q2[i] << endl;
    }
}