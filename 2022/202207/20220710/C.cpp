#include<iostream>//C
#include<cstring>
#include<map>
using namespace std;
map<int, int> a, b;
int main()
{
    int n;
    cin >> n;
    int x, y;
    while(n--){
        cin >> x >> y;
        a.clear();
        b.clear();
        int tmp;
        for (int i = 1; i <= x;i++){
            cin >> tmp;
            if(a[tmp]==0){
                a[tmp] = i;
                b[tmp] = i;
            }
            else
                b[tmp] = i;
        }
        int xx , yy;
        while(y--){
            cin >> xx >> yy;
            int f1 = a[xx];
            int f2 = b[yy];
            if(f1!=0&&f2!=0&&f1<f2){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }
}