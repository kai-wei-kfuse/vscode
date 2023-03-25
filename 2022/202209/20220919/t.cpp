#include<iostream>
using namespace std;
int main(){
    int tmp = 1;
    for (int i = 1; i <= 12;i++){
        tmp *= i;
    }
    cout << tmp;
}