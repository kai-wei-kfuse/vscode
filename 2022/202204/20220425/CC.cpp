#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map<char, int> mp1;
map<char, int> mp2;
int vis1[27], vis2[27];
int main() {
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    int lenx = max(lena, lenb);
    for (int i = 0; i < lena; i++) {
        mp1[a[i]]++;
        // if (i == lena) {
        //     while (i < lenb) {
        //         mp2[b[i]]++;
        //         i++;
        //     }
        //     break;
        // } else if (i == lenb) {
        //     while (i < lena) {
        //         mp1[a[i]]++;
        //         i++;
        //     }
        //     break;
        // }
        // mp1[a[i]]++;
        // mp2[b[i]]++;
    }
    for (int i = 0; i < lenb; i++) {
        mp2[b[i]]++;
    }
    ll ans = lena * lenb;
    int j = 1;
    for (map<char, int>::iterator i = mp1.begin(); j <= 26, i != mp2.end();
         i++, j++) {
        vis1[j] += mp1[char('a' + j - 1)];
    }
}