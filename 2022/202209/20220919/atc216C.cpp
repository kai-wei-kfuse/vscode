#include <iostream>
using namespace std;

void dfs(long long n, long long l) {
    if (n == 1) {
        cout << "A";
        return;
    }
    dfs(n / 2, (n / 2) % 2);
    if (l == 1) {
        cout << "BA";
    } else if (l == 0) {
        cout << "B";
    }
}

int main() {
    long long n;
    cin >> n;
    dfs(n, n % 2);
}