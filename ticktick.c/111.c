#include <time.h>
#include <stdio.h>
#include <conio.h>                //kbhit()/_kbhit()
#include <Windows.h>              //Sleep(ms)
 
int main(void)
{
    time_t tt_;
    struct tm *tm_ ;
    while(!kbhit())               //���¼���������˳�ѭ���������������
    {
        time(&tt_);               //��ȡ����
        tm_ = localtime(&tt_);    //������ת��Ϊ����ʱ�䣨����ʱ�䣩
        printf("��ǰʱ�䣺%d��%d��%d�� %02d:%02d:%02d\r", 1900 + tm_->tm_year,\
               tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
        Sleep(500);               
    }
 
    return 0;
}