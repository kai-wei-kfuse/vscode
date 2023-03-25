#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        double x;
        if(s=="bit")
            x = 2;
        if(s=="nat")
            x = exp(1);
        if(s=="dit")
            x = 10;
        double ans = 0;
        double p;
        for (int i = 1; i <= n;i++){
            cin >> p;
            if(p==0)
            {
                ans += 0;
            }else
            ans += (p/100 )* log2(p/100) / log2(x);
        }
        printf("%.10f\n", -ans);
    }   
}