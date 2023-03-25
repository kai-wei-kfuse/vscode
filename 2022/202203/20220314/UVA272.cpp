#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int q=1;
    while((a=getchar())!=EOF){
        if(a=='"'){
            cout<<(q?"``":"''");
            q=!q;
    }
        else cout<<(char)a;
    }
    return 0;
}