#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 4;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << ' ' << b;
}