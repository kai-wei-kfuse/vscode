#include <bits/stdc++.h>
using namespace std;
int chack(int x);

int main() {
    int l, r;
    while (l < r) {
        int mid = l + r >> 1;
        if (chack(mid))
            l = mid;
        else
            r = mid - 1;
    }
    while (l < r) {
        int mid = l + r >> 1;
        if (chack(mid))
            l = mid + 1;
        else
            r = mid;
    }
}