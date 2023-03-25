#include <algorithm>
#include <iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ull;  //通过ull自然溢出来实现%2^64

const int N = 1000005;
int next_[N];

void kmp(string b) {
    b = ' ' + b;
    int len = b.length()-1;
    // cout << b << endl;
    // cout << len << endl;
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && b[i] != b[j + 1])
            j = next_[j];
        if (b[i] == b[j + 1])
            j++;
        next_[i] = j;
    }
}

int main() {
    int n, m;
    cin >> n;
    string a, ans;
    cin >> ans;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        int len = min(a.size(), ans.size());
        string tmp = a + "##" + ans.substr(ans.size() - len);
        // cout << ans<<'|' << endl;
        // cout << ans.size() << endl;
        //cout<<len<<'|'<<ans<<'|'<<ans.size()<<'|' << ans.size() - len << endl;
        //cout << tmp <<'|'<< endl;
        kmp(tmp);
        // for (int i = 1; i <= tmp.size();i++){
        //     cout << next_[i] << " ";
        // }
         //cout << endl;
        for (int j = next_[tmp.size()]; j < a.size(); j++) {
           // cout << j << ' ';
            ans += a[j];
           // cout << ans << endl;
            }
        
    }

    cout << ans;
}