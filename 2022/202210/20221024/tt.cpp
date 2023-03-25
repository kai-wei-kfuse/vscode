#include<bits/stdc++.h>
using namespace std;
int main(){
    for (int i = -50000; i <= 0;i++){
        for (int j = i + 1; j <= 0;j++){
            if(abs(j+2022)==abs(i-3)){
                cout << i << ' ' << j << endl;
            }
        }
    }
}