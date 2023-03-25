#include <iostream>
using namespace std;

char a[100005], b[1000005];
int next_[100005];

int main() {
    int x, y;
    cin >> x >> b + 1 >> y >> a + 1;
    for (int i = 2, j = 0; i <= x; i++) {
        while (j && b[i] != b[j + 1])
            j = next_[j];
        if (b[i] == b[j + 1])
            j++;
        next_[i] = j;
    }
    for (int i = 1, j = 0; i <= y; i++) {
        while (j && a[i] != b[j + 1])
            j = next_[j];
        if (a[i] == b[j + 1])
            j++;
        if (j == x) {
            cout << i - x << ' ';
            j = next_[j];
        }
    }
}