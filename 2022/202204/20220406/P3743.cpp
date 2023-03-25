#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
struct xx {
    int ms, yuan;
} a[100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].ms >> a[i].yuan;
    }
}