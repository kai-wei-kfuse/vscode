#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                cout << i << j << k << endl;
                int a[7] = {1, 2, 3, 4, 5, 6, 7, 8};
                do {
                    // for (int i = 0; i < 8;i++){
                    //     cout << a[i] << ' ';
                    // }
                    // cout << endl;
                    vector<int> ve, ve1;
                    map<int, int> mp;
                    for (int l = 2; l <= 8; l += 2) {
                        if (i == 1)
                            ve.push_back(max(a[l], a[l - 1]));
                        else
                            ve.push_back(min(a[l], a[l - 1]));
                    }
                    for (int l = 1; l < 4; l++) {
                        if (j == 1)
                            ve1.push_back(max(a[l], a[l - 1]));
                        else
                            ve1.push_back(min(a[l], a[l - 1]));
                    }
                    for (int l = 1; l < 4; l++) {
                        if (k == 1)
                            mp[max(a[l], a[l - 1])]++;
                        else
                            mp[min(a[l], a[l - 1])]++;
                    }
                    for(auto i:mp){
                        cout << i.second << endl;
                    }
                } while (next_permutation(a, a + 7));
                cout << i << j << k << endl;
            }
        }
    }
}