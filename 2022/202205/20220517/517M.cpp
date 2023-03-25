#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string> mp;
int main() {
    // freopen("in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    // freopen("out.txt", "w", stdout);
    //  //输出重定向，输出数据将保存out.txt文件中
    string a;
    mp["q"] = mp["iu"] = "q";
    mp["w"] = mp["ei"] = "w";
    mp["e"] = "e";
    mp["r"] = mp["uan"] = "r";
    mp["t"] = mp["ue"] = "t";
    mp["y"] = mp["un"] = "y";
    mp["u"] = mp["sh"] = "u";
    mp["i"] = mp["ch"] = "i";
    mp["o"] = mp["uo"] = "o";
    mp["p"] = mp["ie"] = "p";
    mp["a"] = "a";
    mp["s"] = mp["ong"] = mp["iong"] = "s";
    mp["d"] = mp["ai"] = "d";

    mp["f"] = mp["en"] = "f";
    mp["g"] = mp["eng"] = "g";
    mp["h"] = mp["ang"] = "h";
    mp["j"] = mp["an"] = "j";
    mp["k"] = mp["uai"] = mp["ing"] = "k";
    mp["l"] = mp["uang"] = mp["iang"] = "l";
    mp["c"] = mp["ao"] = "c";
    mp["v"] = mp["zh"] = mp["ui"] = "v";
    mp["b"] = mp["in"] = "b";
    mp["n"] = mp["iao"] = "n";
    mp["m"] = mp["ian"] = "m";
    mp["z"] = mp["ou"] = "z";
    mp["x"] = mp["ia"] = mp["ua"] = "x";

    while (cin >> a) {
        string ans = "";
        int len = a.length();
        int i = 1;
        if (len > 2) {
            if ("a" <= mp[a] && "z" >= mp[a]) {
                ans += a[0];
                ans += mp[a];
            } else {
                if (a.substr(0, 2) == "sh" || a.substr(0, 2) == "ch" ||
                    a.substr(0, 2) == "zh") {
                    ans += mp[a.substr(0, 2)];
                    i++;
                } else {
                    string xx = "";
                    xx += a[0];
                    ans += mp[xx];
                }
                ans += mp[a.substr(i)];
            }
        } else if (len == 2) {
            ans = a;
        } else if (len == 1) {
            ans += a;
            ans += a;
        }
        cout << ans << ' ';
        char tmp;
        tmp = getchar();
        if (tmp == '\n')
            cout << endl;
    }
}
