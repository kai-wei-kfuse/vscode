#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string, int> mp;
signed main(){
    int t;
    cin >> t;
    mp["bool"] = 1;
    mp["char"] = 1;
    mp["int"] = 4;
    mp["__int128"] = 16;
    mp["float"] = 4;
    mp["double"] = 8;
    mp["long long"] = 8;
    mp["long double"] = 16;
    int cs = 1;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n;i++){
            string s1,s2;
            cin >> s1>>s2;
            string tmp = s1 + " "+s2;
            
            if(tmp=="long long"||tmp=="long double"){
                string s3;
                cin >> s3;
                if(s3[s3.size()-2]==']'){
                    int k=0,res=0;
                    while(s3[k]!='['){
                        k++;
                    }
                    k++;
                    for (; s3[k] != ']';k++){
                        res = res * 10 + s3[k] - '0';
                    }
                    ans += mp[tmp] * res;
                }else{
                    ans += mp[tmp];
                }
            }else{
                //cout << "hh"<< endl;
                if(s2[s2.size()-2]==']'){
                    int k=0,res=0;
                    while(s2[k]!='['){
                        k++;
                    }
                    k++;
                    //cout << s2<< endl;
                    for (; s2[k] != ']';k++){
                        //cout << s2[k]<<" "<<s2[k]-'0' << endl;
                        res = res * 10 + s2[k] - '0';
                     
                    }
                    
                    ans += mp[s1] * res;
                }else{
                    ans += mp[s1];
                }
            }
        }
       //cout << ans << endl;
        cout << "Case #" << cs++ << ":" << ' ';
        if(ans%1024==0){
            cout << ans / 1024 << endl;
        }else{
            cout << ans / 1024 + 1<<endl;
        }
    }
}
/* 
2
1
int a[1000];
8
bool a;
char b;
int c;
long long d;
__int128 e;
float f;
double g;
long double h;

 */