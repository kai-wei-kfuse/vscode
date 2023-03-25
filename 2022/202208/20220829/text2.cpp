#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char a[1000005], b[1000005];
int next_[1000005], z[1000005], p[1000005];

int main() {
    cin >> a + 1;
    int len = strlen(a + 1);
    int ans = 0;
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && a[i] != a[j + 1])
            j = next_[j];
        if (a[i] == a[j + 1])
            j++;
        next_[i] = j;
    }

    int flag = 0;
    if (next_[len]) {
        for (int i = 2, j = 0; i < len; i++) {
            while (j && a[i] != a[j + 1])
                j = next_[j];
            if (a[i] == a[j + 1])
                j++;
            if (j == next_[len]) {
                flag = 1;
                break;
            }
        }
        if (flag)
            for (int i = 1; i <= next_[len]; i++)
                cout << a[i];
        else {
            if (next_[next_[len]]) {
                for (int i = 1; i <= next_[next_[len]]; i++)
                    cout << a[i];
            }
            else{
                cout << "Just a legend";
            }
        }
    } else {
        cout << "Just a legend";
    }
}