#include <cstring>
#include <iostream>
using namespace std;

int next_[1000005];

int main() {
    char s1[100005], s2[100005];
    while (scanf("%s%s", s1, s2) != EOF) {
        //string a = "?" + s1 + s2;
        int j = 0;
        int n = a.size() - 1;
        for (int i = 2; i <= n; i++) {
            while (j && a[i] != a[j + 1])
                j = next_[j];
            if (a[i] == a[j + 1])
                j++;
            next_[i] = j;
        }
        if (next_[n]) {
            for (int i = 1; i <= next_[n]; i++) {
                cout << a[i];
            }
            cout << " " << next_[n];
        } else {
            cout << 0;
        }
        cout << endl;
    }
}