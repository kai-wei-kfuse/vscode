#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    long long sum = 1;
    for (int i = 1; i <= a + b; i++) {
        sum *= i;
    }
    cout << sum;
}