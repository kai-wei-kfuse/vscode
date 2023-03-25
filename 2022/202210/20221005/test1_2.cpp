#include <bits\stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int n_ = rnd.next(2, n);  // n
    int t1 = rnd.next(0, 1000 * 1000 * 1000);
    int i_ = rnd.wnext(1, 1000 * 1000, -10);
    println(n_);
    int minn_1 = 0;
    int minn_2 = 0;
    // vector<int> q1(n_);  // t1
    int bias_ = rnd.next(-1000 * 10, -1000);
    // for (int i = 0; i < n_; i++) {
    //     q1[i] = rnd.wnext(minn_1, t1, bias_);
    // }
    // sort(q1.begin(), q1.end());
    int bias_2 = rnd.next(-10, 2);
    int bias_3 = rnd.wnext(-1000 * 1000, -1000 * 100, -1000);
    int q_;
    for (int i = 0; i < n_; i++) { 
        q_ = rnd.next(1, 2);
        if (q_ == 1) {
            cout << q_ << " ";
            minn_1 = rnd.wnext(minn_1, t1, bias_);
            cout << minn_1 << " ";
            cout << rnd.wnext(minn_2, i_, bias_2) << endl;
        } else if (q_ == 2) {
            cout << q_ << " ";
            int tmp = rnd.wnext(minn_1, t1, bias_3);
            cout << tmp - rnd.wnext(minn_1, tmp, bias_3) << endl;  // t2
        }
    }
}