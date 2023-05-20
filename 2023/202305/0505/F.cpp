#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e12 + 39;

int next_[1000005];
int kmp(vector<int >a,int n){
    int i, j;
    for (i = 2, j = 0; i <= n;i++){
        while(j&&a[i]!=a[j+1])
            j = next_[j];
        if(a[i]!=a[j+1])
            j++;
        next_[i] = j;
    }
    return n - next_[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > ve(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ve[i][j];
        }
    }
    vector<long long> row(m + 1), col(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row[i] = (row[i] * 13331 + ve[i][j]) % mod;
            col[j] = (col[j] * 13331 + ve[i][j]) % mod;
        }
    }
    int p=kmp(row) 
}