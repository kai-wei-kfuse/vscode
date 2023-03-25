#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void alarm()
{
    int i=5;
    while(i--)
    {
        Beep(2000,500);  
        Beep(1900,400);
        Beep(1800,400);
        Beep(1700,400);
        Beep(1600,300);
    }
}
int main()
{
    while(0)
    {
        time_t t;
        struct tm *lt;
        time(&t);           //获取时间戳。
        lt = localtime(&t); //转为时间结构。
        printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour,
           lt->tm_min, lt->tm_sec);
        sleep(1);
        
        system("cls");
    }
    alarm();
    return 0;
}