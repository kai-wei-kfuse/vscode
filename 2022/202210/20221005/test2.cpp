#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int main(int argc,char* argv[]) {
     registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int x = rnd.next(n, m);
    cout << x << endl;
}