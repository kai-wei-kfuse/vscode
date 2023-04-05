#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    int x_ = x, y_ = y;
    for (int i = 1;i<=n;i++){
        char s;
        cin>>s;
        if(s=='Y'){
            x_--;
            y_++;
            cout << 'Y' << ' ';
        }
        else{
            if(y_==0){
                cout << 'Y' << ' ';
                y_++;
                x_--;
            }else{
                cout << 'N' << ' ';
            }
        }
        cin >> s;
        if(s=='Y'){
            y_--;
            x_++;
            cout << 'Y' << endl;
        }
        else{
            if(x_==0){
                cout << 'Y' << endl;
                x_++;
                y_--;
            }else{
                cout << 'N' << endl;
            }
        }
    }
}