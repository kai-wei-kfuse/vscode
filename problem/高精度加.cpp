#include <iostream>
using namespace std;

string add(string str1,string str2)//é«˜ç²¾åŠ 
{
    string str;//ç»“æžœå­˜å‚¨å­—ç¬¦ä¸²
    int cd1 = str1.size();
    int cd2 = str2.size();
    if(cd1>cd2)//---------------é•¿åº¦è¡¥é½-----------
    {
        for (int i = 1; i <= cd1 - cd2;++i)
        {
            str2 = '0' + str2;
        }
    }
    else
    {
        for (int i = 1; i <= cd2 - cd1;++i)
        {
            str1 = '0' + str1;
        }
    }//----------------------------------------
    cd1 = str1.size();//å¯¹é½åŽé•¿åº¦
    int jinwei = 0,linshi=0,benwei=0;
    for (int i = str1.size() - 1; i >=0 ;--i)
    {//æ•°å­—å­—ç¬¦çš„ascllç å‡åŽ»å­—ç¬¦0çš„ascllç å¾—åˆ°çš„ascllç å€¼æ°å¥½ä¸ºè¯¥æ•°å­—ï¼ï¼
        linshi = str1[i] - '0' + str2[i] - '0' + jinwei;
        benwei = linshi % 10;//å–å‡ºä¸ªä½
        jinwei = (linshi - benwei) / 10;//å–å‡ºè¿›ä½
        str = char(benwei + '0') + str;//åŠ å›ž0æ”¹å›žå­—ç¬¦æ•°å­—ä¿å­˜æœ¬ä½
    }
    if(jinwei!=0)//æ³¨æ„è¿›ä½æ®‹ç•™
        str = char(jinwei + '0') + str;
    return str;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << add(str1, str2)<<endl;
    return 0;
}