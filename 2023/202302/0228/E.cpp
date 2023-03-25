#include<bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    n -= 100;
    n *= 0.9;
    n *= 2.0;
    printf("%.1f", n);
}