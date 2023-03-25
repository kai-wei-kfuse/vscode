#include <time.h>
#include <stdio.h>
#include <conio.h>                //kbhit()/_kbhit()
#include <Windows.h>              //Sleep(ms)
 
int main(void)
{
    time_t tt_;
    struct tm *tm_ ;
    while(!kbhit())               //按下键盘任意键退出循环（包括鼠标点击）
    {
        time(&tt_);               //获取秒数
        tm_ = localtime(&tt_);    //将秒数转换为本地时间（北京时间）
        printf("当前时间：%d年%d月%d日 %02d:%02d:%02d\r", 1900 + tm_->tm_year,\
               tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
        Sleep(500);               
    }
 
    return 0;
}