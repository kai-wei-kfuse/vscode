#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
int main()
{
    while(true)
    {
        if(kbhit())
        {
            char c=getch();
            if(GetAsyncKeyState(VK_UP))
                printf("up,");
            if(GetAsyncKeyState(VK_DOWN))
                printf("Down,");
            if(GetAsyncKeyState(VK_LEFT)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x70);
                printf("\nHighlight,");
        }
            if(GetAsyncKeyState(VK_RIGHT)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
                printf("\nNormal,");
        }
        Sleep(100);
        }
    }
    return 0;
}