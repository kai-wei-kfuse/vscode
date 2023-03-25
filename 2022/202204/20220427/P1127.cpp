#include <iostream>
using namespace std;
int n;
int mp[1005][1005];
struct xx {
    int x;
    string a;
} a[1005];
int main() {
    cin >> n;
    string x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a;
        a[i].x = i;
    }
    
}