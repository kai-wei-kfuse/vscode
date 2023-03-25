#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<vector<char> > ve(10, vector<char>(10));
    while(t--){
        for (int i = 1; i <= 9;i++){
            for (int j = 1; j <= 9;j++){
                cin >> ve[i][j];
            }
        }
        for (int i = 1,j = 1; i <= 3,j <= 9;i++,j+=3){
                ve[i][j] = ve[i][j + 1];
        }
        for (int i = 4,j = 2; j <= 9, i <= 6;i++,j+=3){
                ve[i][j] = ve[i][j + 1];
        }
        for (int i = 7, j = 3; j <= 9,i <= 9; i++,j += 3) {
                ve[i][j] = ve[i][j - 1];
        }
        for (int i = 1; i <= 9;i++){
            for (int j = 1; j <= 9;j++){
                cout<< ve[i][j];
            }
            cout << endl;
        }
    }
}