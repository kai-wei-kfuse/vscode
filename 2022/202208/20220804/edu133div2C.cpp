#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> qu[3][200005];

int main() {
    int t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ve(3, vector<int>(n + 1));

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> ve[i][j];
                ve[i][j]++;
            }
        }
    }
}