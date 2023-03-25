#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 1; i <= 100000000;i++){
        for (int j = 1; j <= 10000;j++){
            if(i%(j*j)!=0){
                //cout << i << endl;
                break;
            }
        }
    }
    cout << "gg";
}