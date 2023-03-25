#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%18==0){
        cout << n / 18 * 16;
    }else{
        cout << n / 18 * 16 + n % 18;
    }
}