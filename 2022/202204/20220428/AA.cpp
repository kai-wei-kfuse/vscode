#include <iostream>
using namespace std;
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int n;
    cin >> n;
    int ye1, ye2, m1, m2, d1, d2;
    while (n--) {
        int sum = 0;
        cin >> ye1 >> m1 >> d1;
        cin >> ye2 >> m2 >> d2;
        sum += (ye2 - ye1) * 2;
        int tmp1=m1*100+d1;
        if(tmp1)
    }
}