#include<bits/stdc++.h>
using namespace std;
vector<int> ve(11);
int main(){
    int sum = 0;
    for (int i = 1; i <= 10;i++){
        ve[i] = i * i;
        sum += ve[i];
    }
    sum-=ve[10];
    for (int i = 10; i >= 1;i--){
        sum -= ve[i];
        cout<<sum-ve[i]+10*i<<endl;
    }
}