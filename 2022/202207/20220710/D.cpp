#include<iostream>
#include<algorithm>
using namespace std;
struct xx{
    char c;
    int i;
}b[200005];
bool cmp2(xx a, xx b){
    return a.c > a.c;
}
bool cmp(xx a, xx b){
    return a.i < b.i;
}
int main()
{
    int n;
    cin >> n;
    string a;
    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> a;
        int len = a.length();
        for (int i = 0; i < len;i++){
            b[i+1].c = a[i];
            b[i+1].i = i;
            sum += a[i] - 'a';
        }
        int ans;
        cin >> ans;
        sort(b+1, b + len+1, cmp2);
        for (int i = 1; i < len;i++){
            cout << b[i].c;
        }
        int ii = 0;
        while(sum>ans){
            sum -= (b[ii++].c - 'a');
        }
        sort(b + ii, b + len+1, cmp);
        for (int i = ii; i < len;i++){
            cout << b[i].c;
        }
        cout << '\n';
    }
}